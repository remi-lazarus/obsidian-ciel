---
type: projet-technique
titre: Robot Sumo compétition — Performance v0.2
code: SUMO-01
version: 0.2
date: 2026-06-11
auteur: ingenieur-ciel
statut: étude
précédente: "[[Fiche projet — v0.1]]"
---

# Robot Sumo — Fiche projet technique (v0.2 — Performance)

> **Objectif de cette version :** concevoir le meilleur robot possible pour **gagner** la compétition, budget illimité. Mêmes règles que v0.1 (16×16 cm, 750 g, autonome, départ 5 s, dohyo noir à bord blanc).
> La v0.2 part de la stratégie et en déduit l'électronique — pas l'inverse.
> [[Fiche projet — v0.1]] reste la version pédagogique/budget. [[Fiche projet — v0.3]] (vision, télécommande) reste une exploration séparée.

---

## 1. Ce qui fait gagner un match de sumo

Dans les compétitions de robot sumo de haut niveau (classe autonome japonaise), un match se joue en **moins de 2 secondes**. L'analyse des robots gagnants donne trois piliers, par ordre d'importance :

| Pilier | Principe physique | Conséquence de conception |
|---|---|---|
| **1. Traction** | `F_poussée_max = μ × F_normale` — un robot ne peut pas pousser plus fort que ses roues n'accrochent | Maximiser μ (roues silicone coulées) **et** F_normale (aimants néodyme si dohyo acier) |
| **2. Réaction** | Le premier qui voit l'autre et frappe son flanc gagne | Capteurs < 1 ms, boucle de contrôle 1 kHz, manœuvres de départ pré-programmées |
| **3. Géométrie** | La lame la plus basse passe sous l'adversaire et lui vole sa traction | Lame acier ressort affûtée, < 0,5 mm du sol, toute la largeur avant |

**Insight contre-intuitif :** la puissance moteur n'est PAS un pilier. Le robot est limité par la traction bien avant d'être limité par le couple (calcul §5.1). Un budget illimité s'investit dans l'adhérence, les capteurs et la mécanique de précision — pas dans des moteurs surdimensionnés.

---

## 2. ⚠️ Points de règlement à vérifier AVANT de figer la conception

Ces quatre réponses de l'organisateur changent radicalement le design :

| Question | Si OUI | Si NON |
|---|---|---|
| Le dohyo est-il en **acier** (standard compétition) ? | Aimants néodyme = arme principale (×4–6 sur la traction) | Plan B : downforce par ventilateur EDF (si autorisé) ou pur lest + CG bas |
| Les **aimants** sont-ils autorisés ? | idem ci-dessus | idem plan B |
| Une **lame affûtée** est-elle autorisée ? | Lame acier ressort 0,5 mm sharpened | Lame épaisse à angle faible |
| Test d'adhérence pneus (la roue ne doit pas soulever une feuille A4) ? | Silicone Shore 20–30 A (limite légale) | Silicone collant type "sticky tire" |

> La suite de la fiche suppose **dohyo acier + aimants autorisés** (configuration standard des compétitions sumo). Le plan B est décrit en §5.2.

---

## 3. Doctrine stratégique

### 3.1 Manœuvres de départ (les 2 premières secondes décident du match)

Bibliothèque de manœuvres pré-programmées, sélectionnée avant chaque match par 3 micro-switchs (8 combinaisons) selon l'adversaire observé aux matchs précédents :

| ID | Manœuvre | Contre quel adversaire |
|---|---|---|
| 0 | **Assaut direct** | Robot lent ou lourd — le toucher avant qu'il bouge |
| 1 | **Feinte arc gauche** | Robot qui fonce droit — l'esquiver et frapper son flanc |
| 2 | **Feinte arc droite** | Variante miroir (ne pas être prévisible) |
| 3 | **Contournement large** | Robot défensif posté au centre — attaquer par l'arrière |
| 4 | **Demi-tour + assaut** | Si placement dos à dos imposé |
| 5 | **Matador** | Robot très rapide — pivot d'esquive au dernier moment, il sort avec son propre élan |
| 6 | **Attente courte (500 ms) + assaut** | Robot à feinte — le laisser s'engager d'abord |
| 7 | **Recherche standard** | Adversaire inconnu (1er match) |

Toutes les manœuvres sont exécutées **en aveugle gyro+encodeurs** (trajectoire pré-calculée, recalée par capteurs dès détection de l'adversaire).

### 3.2 Attaque

1. **Acquisition** : 7 capteurs IR rapides → cap estimé de l'adversaire pondéré par capteur ; rotation gyro-contrôlée vers la cible.
2. **Charge en arc** : viser le **flanc**, jamais lame contre lame. Trajectoire courbe pleine puissance.
3. **Contact** (détecté par pic de courant moteur + accéléromètre) : pousser plein couple. Les aimants rendent le robot quasi impoussable pendant qu'il pousse.
4. **Anti-enlisement** : si poussée sans progression (encodeurs ≈ 0 pendant 400 ms) → micro-dégagement latéral ("juke") et ré-attaque en biais pour casser l'appui adverse.

### 3.3 Défense

- **Jamais montrer les flancs** : vitesse de rotation sur place supérieure à la vitesse de circulation adverse (asservissement gyro).
- **Carte mentale du dohyo** : odométrie encodeurs + gyro, recalée à chaque détection de ligne → le robot sait toujours où est le bord. En zone périphérique, interdiction logicielle de reculer vers l'extérieur : tout repli se fait vers le centre.
- **Si poussé** (encodeurs reculent malgré commande avant) : tenir grâce aux aimants ; si la dérive continue → pivot matador pour transformer l'élan adverse en sortie de piste.
- **Perte de cible** : pas de rotation aveugle — spirale de recherche orientée vers la dernière position connue de l'adversaire.

---

## 4. Cerveau : pourquoi PAS un Raspberry Pi 5

| Critère | Raspberry Pi 5 | Teensy 4.1 (choix retenu) |
|---|---|---|
| Temps de boot | 20–30 s (risqué entre deux matchs) | < 300 ms |
| Temps réel | Linux non déterministe (jitter ms) | Bare-metal, boucle 1 kHz garantie |
| Latence capteur→moteur | 5–20 ms (USB, scheduler) | < 100 µs (GPIO direct, interruptions) |
| Conso / masse | 5–10 W + dissipateur | 0,5 W, 5 g |
| Encodeurs quadrature | Logiciel (charge CPU) | 4 décodeurs **hardware** — exactement nos 4 moteurs |
| Écosystème | Python/Linux | Arduino/PlatformIO — continuité avec l'ESP32 de la v0.1 |

**Teensy 4.1** : Cortex-M7 @ 600 MHz, 55 I/O, 4 décodeurs quadrature hardware, tous les GPIO interruptibles. C'est la carte de référence en robotique de compétition rapide. Le Pi 5 ne redevient pertinent que si la vision embarquée entre en jeu → c'est le sujet de [[Fiche projet — v0.3]], pas de la performance pure.

**Option télémétrie** : un ESP32-C3 sur UART relaie les logs en WiFi entre les matchs (tuning des stratégies sans ouvrir le robot). Hors chemin critique, réutilise les acquis v0.1.

---

## 5. Architecture matérielle (déduite de la stratégie)

### 5.1 Traction — le cœur du robot

**Transmission 4WD** — 4 roues motrices pour que 100 % de la force d'appui (poids + aimants) passe par des roues motrices.

**Aimants néodyme N52** sous le châssis, entrefer 1–1,5 mm du dohyo (ne touchent jamais le sol) :
- Cible : **40–50 N d'appui supplémentaire** (~4–5 kgf), array de 8–12 aimants bar 20×10×3 mm (~120 g)
- Entrefer réglable par cales — à caractériser au banc (la force chute très vite avec la distance)
- Avec μ ≈ 0,8 (silicone) : `F_traction = 0,8 × (7,4 N + 45 N) ≈ 42 N` — soit **5,7× le poids du robot**. Un adversaire sans aimants de 750 g pousse au mieux 3,7 N : rapport de force 11:1.

**Dimensionnement moteurs — preuve que la traction limite, pas le couple :**
```
Force traction totale visée : 42 N, roues Ø30 mm
Couple total aux roues : 42 × 0,015 = 0,63 N·m  → 0,16 N·m par roue
Côté moteur (réducteur 16:1, η=0,75) : ≈ 13 mN·m
Maxon DCX16L (kT ≈ 9,5 mN·m/A) : ≈ 1,4 A par moteur — loin des limites
```
→ Des moteurs coreless 16 mm de qualité suffisent **même avec aimants**. Le surplus de budget va dans la précision (encodeurs, réducteurs céramique), pas dans la taille.

**Moteurs : 4× Maxon DCX16L** (coreless, bobinage 12 V) + réducteur planétaire **GPX16 ~16:1** + encodeur **ENX16 EASY** (1024 imp/tr).
- Vitesse pointe ≈ 1,8–2 m/s — suffisant : au-delà, on ne s'arrête plus avant le bord ; l'accélération et la contrôlabilité priment
- ~55 g l'ensemble moteur+réducteur+encodeur → 220 g pour 4
- Configuration exacte (bobinage/ratio) à finaliser sur le configurateur Maxon
- Alternative équivalente : Faulhaber 1717…SR + IE2-1024

**Roues : 4× jantes alu usinées + bandage silicone coulé** (Shore 20–30 A, moules imprimés 3D). Largeur ~20 mm. Nettoyage alcool + ruban adhésif avant chaque match (rituel standard compétition).

> **Contrepartie du 4WD + aimants** : le skid-steer frotte fort en rotation (scrub). Roues relativement étroites et asservissement de cap gyro compensent.

### 5.2 Plan B si aimants impossibles (dohyo non acier ou interdits)

- **Ventilateur EDF** d'aspiration sous châssis (downforce active ~15–25 N) — si le règlement l'autorise
- Sinon : lest acier au plancher, CG le plus bas et le plus avant possible, et la stratégie bascule de "duel de poussée" vers "esquive matador + attaque de flanc" (la doctrine §3 reste valable, seuls les rapports de force changent)

### 5.3 Perception — voir vite plutôt que voir bien

| Capteur                                      | Qté | Rôle                                                                        | Latence       |
| -------------------------------------------- | --- | --------------------------------------------------------------------------- | ------------- |
| **IR numériques JS40F** (ou équiv. 40–80 cm) | 7   | Adversaire : avant 0°/±30°/±60°, flancs ±90°, arrière                       | < 1 ms        |
| **QRE1113 analogiques**                      | 4   | Ligne blanche, coins du châssis, lecture ADC 10 kHz + seuil en interruption | < 200 µs      |
| **IMU SPI** (ISM330DHCX ou BMI088)           | 1   | Gyro 1 kHz : asservissement de cap, détection choc/bascule                  | < 1 ms        |
| **Encodeurs ENX16**                          | 4   | Odométrie, détection enlisement/poussée subie                               | temps réel HW |
| **Courant moteur (IPROPI)**                  | 4   | Détection de contact adversaire                                             | < 1 ms        |

**Rejets argumentés :**
- **VL53L0X (v0.1)** : 50 Hz = 20 ms de latence — à 2 m/s l'adversaire parcourt 4 cm entre deux mesures. Disqualifiant en compétition.
- **Caméra/vision** : latence 30–100 ms + sensibilité éclairage → voir [[Fiche projet — v0.3]] pour l'exploration, hors sujet performance.
- **Flux optique ADNS-3080 (v0.1)** : remplacé par odométrie encodeurs+gyro, plus précise avec des roues qui ne patinent pas (aimants).

### 5.4 Énergie

| Élément | Choix | Justification |
|---|---|---|
| Batterie | **LiPo 3S 11,1 V 450–650 mAh 75C** (~45 g), ×3 packs en rotation | Bursts > 30 A sans chute de tension ; un match consomme < 50 mAh |
| Puissance moteurs | Directe batterie (pas de régulation) | Latence et pertes nulles |
| Logique | Buck 5 V (Pololu D36V28F5) → Teensy | Propre, marges |
| Coupure | XT60 = coupure principale (décision v0.1 conservée) | Simple, fiable |
| Suivi batterie | INA219 sur I2C | Tension + courant sans pin dédiée |
| Chargeur | iMax B6AC — **déjà acquis en v0.1** | ✅ |

### 5.5 Drivers moteurs

**4× DRV8874** (H-bridge 37 V / 6 A crête, mode PH/EN) :
- Limitation de courant réglée ≈ 4 A : protège les coreless (qui brûlent en stall prolongé) **sans perdre de poussée** — on a montré en §5.1 que 1,4 A suffit à saturer la traction
- Sortie IPROPI → mesure de courant temps réel = capteur de contact gratuit
- Sur **PCB custom 4 couches** (JLCPCB) : drivers + capteurs ligne + INA219 + connecteurs — conçu sous Fusion 360 Electronics (continuité avec le schéma v0.1 en cours)

### 5.6 Châssis et lame

- **Châssis usiné alu 7075** (usinage JLC/PCBWay CNC) — rigidité maximale pour que la lame reste à hauteur constante
- **Lame acier ressort 0,5 mm affûtée**, toute la largeur avant, angle 30–45°, **< 0,5 mm du sol** (les aimants plaquent le châssis, on peut raser)
- Déflecteurs latéraux inclinés (un adversaire qui frappe le flanc glisse vers l'extérieur)
- Trappe batterie à accès rapide (clip, sans vis) — décision v0.1 conservée
- Aimants sur support à cales réglables (entrefer ajustable selon usure roues)

---

## 6. Budget masse (750 g)

| Élément | Masse |
|---|---|
| 4× moteur+réducteur+encodeur Maxon 16 mm | 220 g |
| 4× roues (jante alu + silicone) | 80 g |
| Châssis alu 7075 + visserie | 160 g |
| Lame acier ressort + déflecteurs | 45 g |
| Aimants N52 + supports | 130 g |
| PCB + Teensy + capteurs + câblage | 60 g |
| LiPo 3S 450 mAh | 45 g |
| **Total** | **~740 g** ✓ |

> Marge de réglage ~10 g. Contrairement à la v0.1, pas de lest : la masse "utile" (aimants, moteurs) remplit le quota.

---

## 7. Affectation des broches — Teensy 4.1

> À valider contre le pinout FlexPWM / QuadEncoder officiel avant routage du PCB.

| Broches | Fonction |
|---|---|
| 0/1, 2/3, 4/5, 7/8 | Encodeurs quadrature M1–M4 (décodeurs hardware) |
| 6, 9, 22, 23 | PWM moteurs M1–M4 (DRV8874 EN) |
| 28, 29, 38, 39 | Direction M1–M4 (DRV8874 PH) |
| 24–27 (A10–A13) | Courant moteurs M1–M4 (IPROPI) |
| 14–17 (A0–A3) | Capteurs ligne QRE1113 ×4 |
| 30–36 | IR adversaire ×7 |
| 10, 11, 12, 13 | SPI IMU (CS, MOSI, MISO, SCK) |
| 37 | IMU interruption |
| 18, 19 | I2C : OLED 0,96" (état/stratégie) + INA219 |
| 20, 21, 41 | Micro-switchs sélection stratégie (×3 = 8 manœuvres) |
| 40 | Bouton départ match (compte à rebours 5 s) |
| RX1/TX1 | UART télémétrie → ESP32-C3 (option) |

---

## 8. Architecture logicielle

```
Boucle principale 1 kHz (timer hardware)
├── Perception   : fusion IR (cap adversaire), ligne (ISR prioritaire), IMU, courants
├── Localisation : odométrie encodeurs+gyro, recalage sur détections de ligne
│                  → position estimée sur le dohyo en continu
├── Comportement : machine à états hiérarchique
│                  ATTENTE → MANŒUVRE_DÉPART[0–7] → RECHERCHE ⇄ ATTAQUE
│                  états réflexes prioritaires : BORD, ENLISEMENT, POUSSÉ
└── Pilotage     : PID vitesse par roue (encodeurs) + PID cap (gyro), rampes
```

- **Réflexe bord** : ISR ligne → inversion moteurs en < 1 ms, indépendant de la boucle (principe TCRT v0.1 conservé)
- **Cible temps de réaction bout-en-bout** (détection IR → couple aux roues) : **< 5 ms**
- Paramètres de stratégie en EEPROM, modifiables par télémétrie entre les matchs

---

## 9. BOM estimative

| Poste | Référence | Qté | ~Prix |
|---|---|---|---|
| Moteurs complets | Maxon DCX16L + GPX16 + ENX16 (configurateur Maxon) | 4 | ~1 050 € |
| Roues | Jantes alu usinées + silicone coulé (moules 3D) | 4 | ~80 € |
| Cerveau | Teensy 4.1 | 1 | ~35 € |
| Drivers | DRV8874 (sur PCB custom) | 4 | ~20 € |
| PCB | 4 couches JLCPCB + assemblage partiel | 1 | ~80 € |
| IR adversaire | JS40F (JSumo) ou équivalent | 7 | ~85 € |
| Ligne | QRE1113 | 4 | ~5 € |
| IMU | ISM330DHCX breakout (SPI) | 1 | ~25 € |
| Aimants | N52 bar 20×10×3 + supports réglables | 12 | ~40 € |
| Châssis | Alu 7075 usiné (JLC CNC) | 1 | ~150 € |
| Lame | Acier ressort 0,5 mm + découpe | 1 | ~30 € |
| Batteries | LiPo 3S 450 mAh 75C | 3 | ~60 € |
| Buck 5 V | Pololu D36V28F5 | 1 | ~12 € |
| Suivi batterie | INA219 | 1 | ~5 € |
| OLED + switchs + connecteurs | divers | — | ~30 € |
| Télémétrie (option) | ESP32-C3 Super Mini | 1 | ~5 € |
| **Total** | | | **~1 700 €** |

> Budget illimité ≠ dépenser pour dépenser : 60 % du budget va dans les moteurs/encodeurs Maxon, car la précision d'exécution des manœuvres (§3.1) repose entièrement dessus. Tout le reste est volontairement simple.

---

## 10. Plan de validation

1. **Banc aimants** : mesurer la force d'arrachement vs entrefer (0,5 / 1 / 1,5 / 2 mm) sur tôle acier équivalente au dohyo
2. **Banc traction** : robot complet contre dynamomètre — vérifier les ~40 N
3. **Temps de réaction** : oscilloscope entre stimulus IR et inversion PWM — cible < 5 ms
4. **Distance d'arrêt au bord** à pleine vitesse (avec aimants, le freinage est démultiplié)
5. **Répétabilité des manœuvres de départ** : 10 exécutions, dispersion < 2 cm / < 5°
6. **Sparring contre le robot v0.1** — la v0.1 devient le partenaire d'entraînement et la référence de mesure des progrès

---

## 11. Liens

- [[Fiche projet — v0.1]] — version pédagogique/budget (sparring partner)
- [[Fiche projet — v0.3]] — exploration vision + télécommande ESP-NOW
- [[Robot Sumo — Journal de bord]]
