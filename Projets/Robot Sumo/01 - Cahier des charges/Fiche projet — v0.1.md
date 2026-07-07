---
type: projet-technique
titre: Robot Sumo autonome ESP32
code: SUMO-01
version: 0.1
date: 2026-06-10
auteur: ingenieur-ciel
statut: en cours
précédente: "[[Fiche projet — v0]]"
---

# Robot Sumo — Fiche projet technique (v0.1)

> **Changements vs v0 :** capteurs de bord → QTR-1RC · capteurs adversaire → VL53L0X ×3 frontaux (ToF I2C) + stratégie rotation pour la recherche

## 1. Contexte

Projet de démonstration destiné à préparer une participation au concours de robot sumo organisé en fin d'année scolaire. Le robot sert de référence technique pour les élèves qui participeront l'année suivante.

### Règles du concours (catégorie spéciale)

| Paramètre | Valeur |
|---|---|
| Dimensions max | 16 × 16 cm (empreinte au sol) |
| Masse max | 750 g |
| Mode | Autonome (pas de télécommande) |
| Délai de démarrage | 5 secondes après signal (règle standard) |
| Aire de jeu | Dohyo circulaire — bord blanc, surface noire |

> La hauteur n'est pas limitée par les règles connues — à vérifier avec l'organisateur.

---

## 2. Architecture du système

```
┌─────────────────────────────────────────────────────────┐
│  Alimentation : LiPo 2S (7,4V)                         │
│  └─→ Régulateur 5V → ESP32                             │
│  └─→ DRV8833 (tension moteurs directe)                 │
└───────────────────────────┬─────────────────────────────┘
                            │
            ┌───────────────▼───────────────┐
            │             ESP32              │
            │  • Flux optique ADNS-3080 (SPI)│
            │  • IR sécurité TCRT5000 (×4)  │
            │  • Capteurs ToF VL53L0X (×3)  │
            │  • Commande moteurs via PWM    │
            │  • Machine à états (logique)   │
            └──┬───────────┬────────────┬───┘
               │           │            │
   ┌───────────▼──┐  ┌──────▼─────┐  ┌──▼──────────────────┐
   │   DRV8833    │  │  Bus SPI   │  │  Bus I2C partagé     │
   │  (pont en H) │  │  ADNS-3080 │  │  VL53L0X ×3 + OLED  │
   └──────┬───────┘  └────────────┘  └─────────────────────┘
          │
   ┌──────┴──────────┐
   │  Moteur G  Moteur D │
   │ N20 500RPM N20 500RPM│
   └─────────────────┘

   Sous le châssis :
   ADNS-3080 (centre) + TCRT5000 ×4 (coins, interruption hardware)
```

### Placement des 3 capteurs adversaire (VL53L0X)

```
        ┌──────────────────┐
        │  [1]  [2]  [3]   │   Avant
        │  AV-G AV-C AV-D  │
        │                  │
        │                  │
        └──────────────────┘
```

| ID | Position | Angle orienté |
|---|---|---|
| 1 | Avant gauche | ~30° vers la gauche |
| 2 | Avant centre | 0° (droit devant) |
| 3 | Avant droit | ~30° vers la droite |

> Couverture frontale ~90°. La recherche 360° est assurée par **rotation du robot** — les 3 capteurs balayent tout l'anneau dans le temps. En phase d'attaque, les 3 capteurs permettent de corriger la trajectoire vers la cible.

### Logique de décision (machine à états)

```
[ATTENTE 5s] → [RECHERCHE] ←→ [ATTAQUE]
                    ↑               ↓
               [REPLI BORD] ←── (si bord détecté)
```

- **ATTENTE** : immobile 5 secondes après signal
- **RECHERCHE** : rotation sur place — les 3 capteurs frontaux balayent 360° dans le temps
- **ATTAQUE** : fonce vers l'adversaire, correction de trajectoire via les 3 capteurs (centrage sur la cible)
- **REPLI** : deux niveaux de déclenchement :
  - *Niveau 1 — ralentissement* : l'ADNS-3080 calcule la position → vitesse réduite à ~30% quand le robot approche du bord (zone de sécurité ~3 cm)
  - *Niveau 2 — arrêt d'urgence* : un TCRT5000 détecte la ligne blanche via interruption hardware → marche arrière immédiate indépendamment du reste du code

---

## 3. Liste des composants

### 3.1 Déjà disponible

| Composant | Note |
|---|---|
| ESP32 DevKit | Cerveau du robot |
| Imprimante 3D | Fabrication du châssis |
| Fusion 360 | Conception châssis + schéma électronique |

### 3.2 À commander

| Composant             | Référence                                                                                                                            | Qté     | ~Prix unitaire |
| --------------------- | ------------------------------------------------------------------------------------------------------------------------------------ | ------- | -------------- |
| Moteurs               | Hailege GA12-N20 — 6V 500 RPM (~20:1) arbre D — [Amazon.fr](https://www.amazon.fr/dp/B0CJY59TPB)                                     | 2       | 4–6 €          |
| Roues                 | JSumo SLT20 — alu + silicone, Ø 33×20mm, 22g/u — [jsumo.com](https://www.jsumo.com/slt20-aluminum-silicone-wheel-set-33mmx20mm-pair) | 1 paire | ~12 €          |
| Pont en H             | DEWOTHV DRV8833 — 2,7–10,8V, 1,5A/canal, pack ×3 — [Amazon.fr](https://www.amazon.fr/dp/B0G34SRZ7H)                                  | 1 pack  | ~8–10 €        |
| Flux optique          | ⏳ Récupération sur vieille souris optique — identifier le chip (ADNS-xxxx ou PMW-xxxx), utiliser le PCB entier avec lentille         | 1       | 0 € (récup)    |
| IR sécurité bord      | TCRT5000 module — 3,3–5V, DO + potentiomètre, pack ×8 — [Amazon.fr](https://www.amazon.fr/dp/B0CSJXRFK7)                             | 1 pack  | ~8 €           |
| Capteurs adversaire   | AYWHP VL53L0X — I2C, XSHUT, 30–2000mm, 50Hz, 10×12mm, pack ×5 — [Amazon.fr](https://www.amazon.fr/dp/B0FPFT2944)                     | 1 pack  | 14,99 €        |
| Batteries             | OVONIC 2S 7,4V 2200mAh 35C XT60, 98g, pack ×2 — swap entre matchs inclus — [Amazon.fr](https://www.amazon.fr/dp/B0CX1KMJ3M)        | 1 pack  | 28 €           |
| Chargeur              | iMax B6AC — 80W 6A AC/DC, balance LiPo 1S–6S, LCD, connecteur XT60 — [Amazon.fr](https://www.amazon.fr/dp/B0DDL4LZ1T)               | 1       | 44 €           |
| Régulateur 5V         | LM2596 buck ajustable — entrée 3.2–40V, sortie 1.25–35V, 3A, pack ×5 — [Amazon.fr](https://www.amazon.fr/dp/B0FLYNNNWL)             | 1 pack  | 10 €           |
| Bouton démarrage      | Bouton poussoir tactile NO — signal démarrage match (5s délai) — tout assortiment tactile switch                                     | 1       | < 1 €          |
| Écran                 | APKLVSR OLED 1.3" I2C SSH1106 128×64px, blanc, pack ×3 — [Amazon.fr](https://www.amazon.fr/dp/B0CWGP53JW)                           | 1 pack  | 15 €           |
| Connecteurs puissance | YIXISI XT60 mâle + femelle, pack ×10 paires (câbles à fabriquer) — [Amazon.fr](https://www.amazon.fr/dp/B0CF89QJGR)                  | 1 pack  | 10 €           |
| Connecteurs balance   | JST-XH 2.54mm 3 broches mâle + femelle — ✅ stock atelier                                                                            | 2       | 0 €            |
| IMU                   | MPU-6050 (GY-521) — accéléromètre + gyroscope, I2C 0x68, bus partagé GPIO 21/22, zéro pin supplémentaire                            | 1       | 3–5 €          |
| Pont diviseur batt.   | 2 résistances : 100kΩ + 56kΩ — lecture tension LiPo sur GPIO 34 (ADC)                                                               | —       | ✅ stock atelier |
| Lest                  | Acier ou plomb (chutes, plombs de pêche…)                                                                                            | —       | < 5 €          |
| Visserie              | Assortiment M2 + M3                                                                                                                  | —       | 5 €            |
| Fils 22AWG            | HuLuWa fil silicone 22AWG — puissance (moteurs, batterie, XT60) — [Amazon.fr](https://www.amazon.fr/dp/B0C84BX56N)                   | 1       | 12 €           |
| Fils 26AWG            | HuLuWa fil silicone 26AWG — signaux (capteurs, balance) — [Amazon.fr](https://www.amazon.fr/dp/B0C84QLV2L)                           | 1       | 15 €           |

**Budget estimé total : ~205 €** *(hors lest et visserie — chargeur B6AC 44€ et fils silicone 27€ représentent l'essentiel du dépassement vs estimation initiale ; MPU-6050 +5€ ; pont diviseur sur stock atelier)*

> Inclut une 2e batterie (rechange entre les matchs) et les connecteurs XT30 pour swap rapide. L'OLED SH1106 partage le bus I2C existant (adresse 0x3C, pas de conflit avec les VL53L0X en 0x30–0x32).

### 3.3 Répartition du poids estimée

| Élément | Masse estimée |
|---|---|
| Châssis 3D (PLA) | 100–120 g |
| Moteurs N20 ×2 + roues | 60–80 g |
| Électronique (ESP32 + DRV8833 + capteurs) | 70–90 g |
| Batterie LiPo 2S 750 mAh | 80–100 g |
| Lame avant (acier ou PLA renforcé) | 50–80 g |
| OLED 1.3" + support | 5–10 g |
| Visserie + câbles | 30–50 g |
| Lest (acier/plomb) | 220–350 g |
| **Total visé** | **~750 g** |

> Le lest est ajouté en fin de build pour atteindre exactement 750 g. Le positionner au plus bas du châssis et à l'avant pour abaisser le centre de gravité et augmenter la force sur la lame.
> La 2e batterie reste hors du robot — elle est en charge pendant les matchs.

---

## 4. Conception châssis (Fusion 360)

### Contraintes de conception

- Empreinte max : 160 × 160 mm
- Hauteur libre (vérifier règles)
- Lame avant la plus basse possible (< 1 mm du sol)
- Logements intégrés :
  - Moteurs N20 (latéraux, au plus bas)
  - QTR-1RC ×4 sous le châssis (coins, garde au sol 3–5 mm)
  - VL53L0X ×3 en façade avant (voir placement §2)
- **Trappe batterie à accès rapide** : glissière ou clip latéral, pas de vis — swap en < 10 secondes
- Connecteur XT30 accessible sans ouvrir le châssis
- Logement OLED 1.3" en façade supérieure (visible pendant le match)
- Accès facile à l'interrupteur et à la prise de charge LiPo
- Fixation ESP32 + DRV8833 accessibles pour le debug

### Points critiques

- Angle de la lame avant : 0° (rase le sol) pour glisser sous l'adversaire
- Garde au sol QTR-1RC : 3–5 mm (trop haut → raté, trop bas → frottement)
- Centre de gravité bas → batterie positionnée au plancher du châssis
- Les VL53L0X ont un FOV de ~25° — orienter précisément selon le tableau de placement

---

## 5. Connexions électroniques

### Affectation des broches ESP32

| Broche ESP32 | Fonction |
|---|---|
| GPIO 32 | Moteur G — IN1 (DRV8833) |
| GPIO 33 | Moteur G — IN2 (DRV8833) |
| GPIO 25 | Moteur D — IN1 (DRV8833) |
| GPIO 26 | Moteur D — IN2 (DRV8833) |
| GPIO 18 | SPI SCK — ADNS-3080 |
| GPIO 19 | SPI MISO — ADNS-3080 |
| GPIO 23 | SPI MOSI — ADNS-3080 |
| GPIO 5  | SPI CS — ADNS-3080 |
| GPIO 15 | TCRT5000 — avant gauche (interruption hardware) |
| GPIO 16 | TCRT5000 — avant droit (interruption hardware) |
| GPIO 17 | TCRT5000 — arrière gauche (interruption hardware) |
| GPIO 4  | TCRT5000 — arrière droit (interruption hardware) |
| GPIO 21 | I2C SDA (VL53L0X ×3 + OLED partagé) |
| GPIO 22 | I2C SCL (VL53L0X ×3 + OLED partagé) |
| GPIO 13 | XSHUT — VL53L0X 1 (AV-G) |
| GPIO 12 | XSHUT — VL53L0X 2 (AV-C) |
| GPIO 14 | XSHUT — VL53L0X 3 (AV-D) |
| GPIO 27 | Bouton démarrage match (pull-up interne, front descendant) |
| GPIO 34 | Pont diviseur batterie — lecture tension LiPo (ADC entrée seule, pas de pull-up interne) |

> **Coupure principale :** pas d'interrupteur sur la ligne LiPo. Le connecteur XT60 fait office de coupure principale — débrancher la batterie = tout s'éteint. Le bouton GPIO 27 sert uniquement au signal de démarrage du match (déclenche le compte à rebours 5s dans le code).

> **Note ADNS-3080 :** monté sous le châssis au centre, à 2–3 mm du sol. Interface SPI (VSPI ESP32). Fournit le déplacement XY du robot en temps réel — utilisé pour calculer la position sur le dohyo et déclencher le ralentissement en zone de sécurité (~3 cm du bord estimé).

> **Note TCRT5000 :** branché sur interruption hardware (`attachInterrupt`). Déclenche le repli d'urgence indépendamment de la boucle principale — latence < 1ms garantie même si l'ESP32 est occupé sur le bus I2C.

> **Note VL53L0X :** au démarrage, tous les XSHUT sont LOW (capteurs éteints). On les active un par un pour assigner des adresses I2C uniques (0x30, 0x31, 0x32), puis on les laisse tous actifs.

> **Note OLED SH1106 :** adresse I2C 0x3C — pas de conflit avec les VL53L0X. Affichage : tension batterie, compte à rebours 5s, état courant, chrono du match.

> **Note MPU-6050 :** adresse I2C 0x68 — pas de conflit. Usages : (1) détection bascule/roue dans le vide (variation de l'axe Z de gravité) → déclenche repli ; (2) gyroscope pour contrôler précisément l'angle de rotation en phase RECHERCHE. La détection "robot poussé en arrière" est déjà couverte par l'ADNS-3080 (déplacement sol réel vs commande moteurs).

> **Note pont diviseur batterie :** R1=100kΩ (côté LiPo+), R2=56kΩ (côté GND) → tension sur GPIO 34 = V_bat × 56/156 ≈ V_bat × 0,36. À 8,4V full : 3,02V. À 6,0V min : 2,16V. Seuil d'alerte OLED : V_bat < 6,6V (3,3V/cellule).

---

## 6. Décisions techniques

### Détection de bord — approche hybride flux optique + IR sécurité

**Contexte :** à 83 cm/s, la ligne blanche du dohyo (~25mm) est traversée en 30ms. Un capteur polé dans la boucle principale (occupée par les lectures I2C VL53L0X ~20ms) peut rater la ligne. Solutions pures insuffisantes.

**Solution retenue : deux niveaux indépendants**
1. **ADNS-3080 (flux optique SPI)** — calcule la position XY du robot en continu à 2300 FPS. Le code réduit la vitesse à ~30% quand le robot approche à ~3 cm du bord estimé. Proactif.
2. **TCRT5000 ×4 (IR, interruption hardware)** — déclenche le repli d'urgence immédiatement dès que la ligne blanche est détectée, indépendamment de la boucle principale. Latence < 1ms garantie.

**Rejet du QTR-1RC Pololu :** introuvable sur Amazon.fr ou Gotronic. Remplacé par TCRT5000 (module intégré, lecture digitale, même principe).

**Rejet du tout-IR pur :** latence insuffisante à haute vitesse si polling dans la boucle principale. Résolu par l'interruption hardware du TCRT5000.

**Approvisionnement flux optique — récupération sur vieille souris :**
Le module ADNS-3080 neuf coûte ~20€. Décision : récupérer le PCB complet d'une vieille souris optique (capteur + lentille + éclairage déjà alignés en usine). Les capteurs courants (ADNS-xxxx, PMW3360, PMW3389) sont tous compatibles SPI avec l'ESP32 et disposent de librairies Arduino. Coût : 0€. Procédure : ouvrir la souris → photographier le marquage du chip → identifier le modèle → souder 4 fils SPI sur le PCB existant. ⏳ En attente de trouver une souris disponible.

---

### Moteurs brushed N20 retenus — rejet du brushless

**Contexte :** option brushless + ESC étudiée pour améliorer le rapport poids/puissance en poussée face à face.

**Analyse :** pour un robot de 750 g, la force de poussée maximale est limitée par la traction, pas par les moteurs :

```
F_traction_max = μ × m × g = 0,5 × 0,75 × 9,81 ≈ 3,7 N
F_moteurs N20 30:1 (×2) ≈ 9,8 N  →  déjà 2,6× au-dessus de la limite
```

Les roues patinent avant que les moteurs soient saturés. Passer au brushless ne change rien à la force transmissible au sol.

**Inconvénients du brushless dans ce contexte :**
- ESC bidirectionnel par moteur : +30 g chacun (poids inutile)
- Complexité câblage et code supérieure
- Coût plus élevé

**Ce qui améliore réellement la poussée :**
- Maximiser le poids du robot (utiliser la marge ~230 g → lest acier bas)
- Roues haute adhérence (silicone ou uréthane)
- N20 50:1 si plus de couple statique souhaité (au détriment de la vitesse)
- Lame avant large et rase pour passer sous l'adversaire

**Décision :** N20 30:1 conservés. Investir le budget et le poids disponible dans le lest, les roues et la conception de la lame.

---

### Chargeur LiPo — critères retenus

**Contexte :** tournoi à rythme variable — 4 à 5 matchs d'affilée puis 30min à 1h de pause, phase finale plus soutenue. 2 batteries en swap.

**Analyse :**
- iMax B3 (~0,8A) → 2h45 par charge complète → **incompatible** avec une pause de 30–45min en phase finale
- Chargeur ≥ 2A → charge complète en ~1h10 à 1C → batterie à 50–70% en 30min → suffisant pour les matchs suivants

**Critères retenus :**
1. Courant de charge ≥ 2A
2. Alimentation secteur intégrée (pas de PSU externe à apporter en concours)
3. Charge par équilibrage (balance via JST-XH 3 broches) — protège la longévité des cellules
4. Compatible 2S LiPo explicitement

**Budget cible : 15–25 €** (ex : HTRC C240, SkyRC E430 ou équivalent)

---

## 7. Prochaines étapes

- [ ] Commander les composants (voir §3.2)
- [ ] Concevoir le châssis sur Fusion 360 (intégrer logements QTR + VL53L0X)
- [ ] Schéma électronique complet sous Fusion 360
- [ ] Écrire le code ESP32 — initialisation I2C multi-adresses VL53L0X
- [ ] Écrire le code ESP32 — machine à états
- [ ] Tester les QTR-1RC (calibrage seuil ligne blanche)
- [ ] Tester les VL53L0X (validation portée et angles)
- [ ] Intégration et premiers essais sur dohyo
- [ ] Calibrage et optimisation de la stratégie
- [ ] Vérifier les règles complètes avec l'organisateur

---

## 8. Liens

- [[Fiche projet — v0]] — version précédente
- [[Robot Sumo — Journal de bord]]
- [[Robot Sumo — Code ESP32]]
