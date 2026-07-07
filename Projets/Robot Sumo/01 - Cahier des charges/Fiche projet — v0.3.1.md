---
version: v0.3.1
date: 2026-06-21
parent: "[[Fiche projet — v0.3]]"
statut: concept
type: projet-technique
titre: Robot Sumo apprenant — Deep RL embarqué + sim2real
---

# Fiche projet — v0.3.1 : Robot Sumo apprenant

> Extension de la v0.3 (caméra + ESP-NOW). Le robot collecte la télémétrie de ses matchs, identifie le comportement de chaque adversaire et adapte sa stratégie via un **modèle de Deep Reinforcement Learning** entraîné en simulation puis affiné sur les matchs réels (pipeline sim2real).

## 1. Vision d'ensemble

Cycle complet ML embarqué :

```
[Match réel] ─► télémétrie SD ─► dump WiFi/PC
                                       │
                                       ▼
                            [Simulateur 2D Python]
                            + matchs simulés (100k+)
                                       │
                                       ▼
                            [Entraînement PPO/DQN]
                            curriculum + domain rand.
                                       │
                                       ▼
                       [Export TFLite Micro 50–200 ko]
                                       │
                                       ▼ OTA WiFi
                       [Inférence ESP32-S3 — 2–5 ms]
                                       │
                                       ▼
                              [Match réel suivant]
```

Le but n'est **pas** d'apprendre pendant un match (trop court, 3 min) mais d'**améliorer la politique entre les matchs** via une boucle complète sim → réel → ré-entraînement.

---

## 2. Architecture en 4 couches

### Couche 1 — Télémétrie embarquée

Boucle à 50 Hz pendant tout le match. Écriture binaire compacte sur carte SD.

**Format d'un échantillon (32 octets) :**

| Champ | Type | Bits | Notes |
|---|---|---|---|
| timestamp | uint32 | 32 | ms depuis début match |
| pos_x, pos_y | int16×2 | 32 | mm, estimé via ADNS-3080 |
| heading | int16 | 16 | degrés, MPU-6050 gyro |
| dist_adv_360 | uint16×N | variable | distances tourelle LIDAR |
| adv_angle | int16 | 16 | angle adversaire estimé |
| adv_dist | uint16 | 16 | distance adversaire mm |
| imu_ax, ay, az | int16×3 | 48 | accélérations |
| imu_gx, gy, gz | int16×3 | 48 | rotations |
| state_robot | uint8 | 8 | enum machine d'états |
| action | uint8 | 8 | enum {av, ar, rg, rd, push, idle} |
| reward | int8 | 8 | -1 / 0 / +1 |

→ ~5 Mo par match (50 Hz × 180 s × 32 B + tourelle), tient sur SD 1 Go pour des centaines de matchs.

**Tag de fin de match** : bouton dédié pour marquer V/D + opponent ID.

### Couche 2 — Simulateur Python

**Stack :**
- `Pymunk` — moteur physique 2D (collisions, friction, masses)
- `Gymnasium` — interface RL standard
- `Pygame` — visualisation pour debug

**Modélisation :**
- Dohyo circulaire Ø 92 cm, surface noire + ligne blanche
- Robot = corps rigide avec moteurs différentiels (force vs friction silicone/bois)
- Capteurs simulés : VL53L0X (rayons + bruit gaussien), TCRT5000 (lookup couleur), IMU, ADNS-3080

**Adversaires synthétiques :**

| Classe | Comportement |
|---|---|
| `fonceur` | va toujours vers le robot, attaque frontale |
| `fuyard` | s'éloigne dès détection, joue les bords |
| `circulaire` | tourne autour du robot, attend ouverture |
| `passif` | reste centré, réagit en miroir |
| `random` | actions aléatoires |
| `clone` | copie de la policy actuelle (self-play) |

**Domain randomization** (à chaque épisode) :
- friction roues : 0.6 – 1.2× nominale
- latence capteurs : 0 – 30 ms
- bruit IMU : σ ∈ [0.5, 3]°/s
- offset orientation LIDAR : ±3°
- masse robot : 700 – 800 g

→ La politique apprise reste robuste au passage en réel.

### Couche 3 — Entraînement offline

**Algorithme** : **PPO** (Proximal Policy Optimization) — plus stable que DQN pour actions continues/hybrides, convergence fiable.

**Lib** : `Stable-Baselines3` (PyTorch).

**Architecture du réseau :**

```
input (state, ~40 features)
       │
       ▼
   Dense 128 + ReLU
       │
       ▼
   Dense 128 + ReLU
       │
       ▼
   Dense 64 + ReLU
       │
   ┌───┴───┐
   ▼       ▼
 actor    critic
(6 actions)(value)
```

~50 k paramètres → ~200 ko en float32, ~50 ko en int8 quantifié.

**Curriculum :**
1. Phase 1 : adversaires faciles (passif, random) — 50 k épisodes
2. Phase 2 : ajout fonceur + fuyard — 50 k épisodes
3. Phase 3 : circulaire + self-play — 100 k épisodes
4. Phase 4 : fine-tuning sur replay buffer **réel** — 5–10 k épisodes

**Suivi** : Weights & Biases pour les courbes (reward, win rate par classe, divergence sim/réel).

**Export** : PyTorch → ONNX → TFLite → TFLite Micro (avec quantification int8 pour gagner ×4 en taille).

### Couche 4 — Inférence embarquée

**Runtime** : **TensorFlow Lite Micro** + backend **ESP-NN** (Espressif Neural Network kernels, optimisés SIMD ESP32-S3).

**Boucle de contrôle :**

```cpp
loop() {
  // 1. Lecture capteurs (~1 ms)
  read_lidar_turret(); read_imu(); read_position();

  // 2. Safety layer — JAMAIS bypassé par le ML
  if (tcrt_irq) { emergency_reverse(); return; }
  if (battery < 6.6V) { ouvre_log(); return; }

  // 3. Construction du state vector (~0.5 ms)
  build_state_vector(state);

  // 4. Inférence policy (~2–5 ms sur ESP32-S3)
  action = tflite_invoke(state);

  // 5. ε-greedy : 5% d'exploration pour collecter des trajectoires variées
  if (random() < 0.05) action = random_action();

  // 6. Commande moteurs + log télémétrie
  execute_action(action);
  log_sample();
}
```

**Total** : ~6–8 ms par cycle → boucle 100+ Hz possible, on régule à 50 Hz pour stabilité capteurs.

---

## 3. Mode "Imitation learning" (bonus stratégique)

La télécommande ESP-NOW (déjà prévue v0.3) sert aussi à enregistrer des **démos humaines** :

1. Mode pilotage manuel via télécommande
2. Télémétrie loggée avec `action = action_humaine`
3. **Behavior Cloning** : entraîner un premier policy par apprentissage supervisé sur ces démos
4. Ce policy sert d'**initialisation** au RL → convergence ×3 à ×5 plus rapide

30 minutes de démos humaines bien faites = équivalent de plusieurs jours de RL à froid.

---

## 4. Couche Safety — jamais bypassée

Le ML ne contrôle **que** les actions stratégiques. Les fonctions critiques restent hardcodées :

| Sécurité | Implémentation | Pourquoi |
|---|---|---|
| REPLI BORD | Interruption hardware TCRT5000 | Latence ML trop élevée pour ça |
| ATTENTE 5 s | Timer logiciel rigide | Règle du concours, non négociable |
| Watchdog anti-immobilité | Reset si 5 s sans mouvement | Art. 14 règlement TechnoBot |
| Coupure batterie basse | ADC GPIO 34 + seuil 6,6 V | Préservation LiPo |
| Override télécommande | Bouton STOP ESP-NOW | Récupération en cas de comportement aberrant |

Le RL prend la main **uniquement** dans les phases RECHERCHE et ATTAQUE.

---

## 5. Hardware additionnel vs v0.3

| Composant | Référence | Pourquoi | Prix |
|---|---|---|---|
| Module SD card SPI | Générique 3.3V | Télémétrie binaire ~5 Mo/match | ~3€ |
| ESP32-S3-WROOM-1 N16R8 | 16 Mo flash + 8 Mo PSRAM | Place pour modèle + replay buffer + logs | ~6€ |
| (Option) Antenne WiFi externe IPEX | — | Dump rapide entre matchs | ~3€ |

**Surcoût total : ~10€** au-dessus de la v0.3 (qui était à +25–35€ vs v0.1).
→ Budget v0.3.1 estimé : **~250€** au lieu de ~205€ pour la v0.1.

---

## 6. GPIO supplémentaires

La SD SPI partage le bus SPI déjà utilisé par l'ADNS-3080 :

| Pin | Rôle |
|---|---|
| GPIO 18 | SPI SCK partagé |
| GPIO 19 | SPI MISO partagé |
| GPIO 23 | SPI MOSI partagé |
| GPIO 5 | CS — ADNS-3080 |
| GPIO 17 | CS — Carte SD |

→ Pas de pin supplémentaire nécessaire (juste un CS additionnel).

---

## 7. Pipeline de développement — calendrier réaliste

### Phase A — Infrastructure télémétrie (2–3 semaines)
- [ ] Câblage carte SD + test écriture
- [ ] Format binaire compact défini et implémenté
- [ ] Logger 50 Hz validé (vérifier overhead, jitter)
- [ ] Outil Python de relecture/visualisation des logs
- [ ] OTA WiFi pour pousser des poids (`ArduinoOTA`)

### Phase B — Simulateur Python (3–4 semaines)
- [ ] Modèle physique Pymunk : robot + dohyo + 1 adversaire fonceur
- [ ] Wrapper Gymnasium (`reset`, `step`, `reward`)
- [ ] Capteurs simulés calibrés sur données réelles télémétrie
- [ ] Visualisation Pygame pour debug
- [ ] Implémentation des 6 classes d'adversaires
- [ ] Domain randomization

### Phase C — Premier entraînement (2–3 semaines)
- [ ] Pipeline Stable-Baselines3 + W&B
- [ ] Curriculum learning implémenté
- [ ] Premier modèle convergent en sim (win rate > 70% vs fonceur)
- [ ] Export ONNX → TFLite → TFLite Micro
- [ ] Validation taille et latence sur ESP32-S3 (banc isolé)

### Phase D — Intégration onboard (2 semaines)
- [ ] Inférence dans la boucle 50 Hz
- [ ] Mesure latence réelle, ajustements
- [ ] Safety layer testée (forçage repli pendant ML actif)
- [ ] Premier match réel avec policy sim-seule

### Phase E — Sim2real fine-tuning (continu)
- [ ] Collecte de ~50–100 matchs réels variés
- [ ] Calibration des adversaires synthétiques sur données réelles
- [ ] Re-training avec replay buffer mixte sim+réel
- [ ] Mesure du gap sim/réel et itération

### Phase F (optionnelle) — Imitation Learning
- [ ] Mode pilotage manuel ESP-NOW
- [ ] Collecte 30 min de démos humaines
- [ ] Behavior Cloning offline
- [ ] Comparaison "BC seul" vs "BC + RL" vs "RL seul"

**Total estimé : 3–4 mois en parallèle des autres axes.**

---

## 8. Métriques de succès

| Métrique | Objectif |
|---|---|
| Latence inférence | < 10 ms par décision |
| Taille modèle déployé | < 200 ko (int8) |
| Win rate sim final | > 80% vs adversaires synthétiques |
| Gap sim/réel | < 20 points de win rate |
| Win rate réel après fine-tuning | > 60% vs adversaires réels variés |
| Fréquence de boucle de contrôle | 50 Hz stable |

---

## 9. Risques et mitigations

| Risque | Mitigation |
|---|---|
| Gap sim/réel trop grand | Domain randomization agressive + fine-tuning sur replay réel |
| Modèle trop gros pour la PSRAM | Quantification int8, pruning, distillation vers MLP plus petit |
| Comportement aberrant en compétition | Safety layer hardware + bouton override ESP-NOW |
| Logs SD trop lents | Buffer en PSRAM + flush par chunks de 4 ko |
| OTA bricke le robot pendant un tournoi | Système A/B : on garde toujours la dernière policy fonctionnelle en backup |
| Pas assez de matchs réels pour fine-tuning | Self-play sim + behavior cloning sur démos humaines |

---

## 10. Pédagogie — ce qui se montre aux élèves

Cette version sert de vitrine technique : on ne demande pas aux élèves de l'implémenter, mais on leur montre **le cycle complet d'un projet ML embarqué** moderne. Démos suggérées :

- **Dashboard temps réel** (Streamlit) : décisions du modèle + confiance + état machine
- **Courbe d'apprentissage** : win rate match après match → on visualise l'amélioration
- **Comparaison "sim seul" vs "sim + fine-tuning"** : effet du sim2real
- **Mode démo humaine** : élève pilote, le robot enregistre, on rejoue
- **Visualisation du replay buffer** : trajectoires réelles vs simulées

---

## 11. Liens

- [[Fiche projet — v0.3]] — Vision (caméra + ESP-NOW)
- [[Fiche projet — v0.1]] — Architecture de base
- [[Tourelle LIDAR/01 - Cahier des charges/Fiche projet|Tourelle LIDAR]] — fournit l'observation 360°
- [[Robot Sumo — Timeline]]
