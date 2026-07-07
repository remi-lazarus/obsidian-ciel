---
tags: [projet, feux-circulation, cahier-des-charges, CIEL, arduino]
date: 2026-04-03
statut: validé
niveau: Bac Pro CIEL — Seconde / Première
---

# Cahier des charges — Système de feux de circulation complet

## 1. Contexte et objectif général

Ce projet consiste à réaliser une maquette fonctionnelle d'un système de feux de circulation urbain. Il simule une intersection comprenant un feu tricolore pour les voitures, un feu bicolore pour les piétons, une barrière motorisée, et un mode nuit automatique.

Le projet est conçu pour être développé de manière **progressive**, en 3 phases cumulatives. Chaque phase est autonome et testable indépendamment avant d'être intégrée à l'ensemble.

---

## 2. Description fonctionnelle

### Fonctionnalité 1 — Feu voiture + feu piéton avec demande de passage

Le système fonctionne en **mode nominal** : le feu voiture est au vert par défaut. Lorsqu'un piéton appuie sur le bouton de demande de passage, la séquence suivante se déroule :

| Étape | Feu voiture | Feu piéton | Durée |
|-------|-------------|------------|-------|
| 1 (normal) | Vert | Rouge | indéfini |
| 2 (transition) | Orange | Rouge | 2 s |
| 3 (passage piéton) | Rouge | Vert | 5 s |
| 4 (fin passage) | Rouge | Rouge clignotant | 2 s |
| 5 (retour normal) | Vert | Rouge | indéfini |

- Le bouton piéton est ignoré si une séquence est déjà en cours.
- Un délai minimum de 10 s est respecté entre deux déclenchements consécutifs pour éviter les appuis répétés.

### Fonctionnalité 2 — Barrière motorisée

Une barrière (servomoteur) est commandée par un second bouton poussoir.

| Action | Comportement |
|--------|-------------|
| Appui bref bouton barrière | Bascule l'état : ouverte → fermée ou fermée → ouverte |
| Barrière ouverte | Servomoteur à 90° |
| Barrière fermée | Servomoteur à 0° |

- La commande de la barrière est **indépendante** du cycle des feux.
- La position est maintenue sans action répétée (le servomoteur tient la position).

### Fonctionnalité 3 — Mode nuit (détection automatique par LDR)

Un capteur de luminosité (LDR) surveille en permanence l'intensité lumineuse ambiante.

| Condition | Comportement |
|-----------|-------------|
| Luminosité > seuil | Mode jour : fonctionnement normal (feux + barrière actifs) |
| Luminosité ≤ seuil | Mode nuit : feux voiture et piéton passent en orange clignotant |

- En mode nuit, les boutons piéton et barrière sont **désactivés**.
- La LED orange du feu voiture clignote à 1 Hz (500 ms ON / 500 ms OFF).
- La LED orange du feu piéton clignote en phase avec le feu voiture.
- Le passage en mode nuit et le retour en mode jour sont gérés avec une **hystérésis** (± 50 unités ADC) pour éviter les oscillations au seuil.
- Le servomoteur reste dans sa dernière position connue lors du passage en mode nuit.

---

## 3. Contraintes techniques

### Contraintes matérielles
- Microcontrôleur : **Arduino Uno** (ATmega328P, 5 V, 16 MHz)
- Alimentation : USB (5 V) ou alimentation externe 7–12 V via jack
- Tous les composants montés sur **breadboard**
- Pas de PCB custom — câblage par fils dupont

### Contraintes logicielles
- Environnement : **Arduino IDE** ou VS Code + extension PlatformIO
- Langage : **C/C++ Arduino**
- Pas de bibliothèque externe sauf `Servo.h` (incluse dans l'IDE Arduino)
- Code commenté en français
- Pas de `delay()` bloquant dans la boucle principale (gestion du temps par `millis()`)

### Contraintes pédagogiques
- Niveau Bac Pro CIEL — accessible à un élève de Seconde
- Chaque fonctionnalité doit pouvoir être testée séparément
- Le code doit être lisible, structuré en fonctions, avec des noms de variables explicites
- La conception doit être reproductible dans TinkerCAD

---

## 4. BOM — Liste des composants (Bill of Materials)

| Réf. | Désignation | Valeur / Caractéristique | Qté | Rôle |
|------|-------------|--------------------------|-----|------|
| U1 | Arduino Uno | ATmega328P | 1 | Microcontrôleur principal |
| BB1 | Breadboard | 830 points | 1 | Support de câblage |
| D1 | LED rouge | 5 mm, rouge | 1 | Feu voiture — rouge |
| D2 | LED orange | 5 mm, orange/jaune | 1 | Feu voiture — orange |
| D3 | LED verte | 5 mm, verte | 1 | Feu voiture — vert |
| D4 | LED rouge | 5 mm, rouge | 1 | Feu piéton — rouge |
| D5 | LED verte | 5 mm, verte | 1 | Feu piéton — vert |
| R1 | Résistance | 220 Ω, 1/4 W | 5 | Limitation courant LEDs (une par LED) |
| SW1 | Bouton poussoir | NO, 6 mm | 1 | Demande passage piéton |
| SW2 | Bouton poussoir | NO, 6 mm | 1 | Commande barrière |
| R2 | Résistance pull-down | 10 kΩ, 1/4 W | 2 | Pull-down boutons SW1 et SW2 |
| SRV1 | Servomoteur | SG90 (ou équivalent 5 V) | 1 | Barrière motorisée |
| LDR1 | Photorésistance | LDR 5 mm GL5516 (ou équivalent) | 1 | Détection luminosité (mode nuit) |
| R3 | Résistance diviseur | 10 kΩ, 1/4 W | 1 | Diviseur de tension avec LDR |
| — | Fils dupont | M/M et M/F, assortiment | ~30 | Câblage |

**Notes BOM :**
- Les 5 résistances R1 sont identiques (220 Ω). Une résistance par LED, en série entre la broche Arduino et l'anode de la LED.
- Les résistances pull-down R2 (10 kΩ) assurent un niveau logique bas stable quand le bouton est relâché.
- La LDR et R3 forment un pont diviseur de tension : la tension en sortie varie avec la luminosité et est lue par une entrée analogique de l'Arduino.
- Le servomoteur SG90 est directement alimenté par le 5 V de l'Arduino (consommation ~150 mA en charge, acceptable pour une utilisation occasionnelle).

---

## 5. Critères de validation

| Fonctionnalité | Critère de validation |
|----------------|----------------------|
| Feu tricolore nominal | LED verte allumée en permanence au démarrage |
| Séquence piéton | Appui SW1 → séquence complète en ~9 s, retour au vert |
| Anti-rebond | Appui pendant séquence = ignoré |
| Barrière SW2 | Appui → servomoteur bascule entre 0° et 90° |
| Mode nuit LDR | Obscurcir capteur → clignotement orange, déboucher → retour mode jour |
| Mode nuit isolation | Boutons inactifs en mode nuit |

---

## 6. Évolutions possibles (hors périmètre initial)

- Ajout d'un second feu voiture pour la voie opposée (synchronisation en opposition)
- Buzzer d'aide à la traversée pour malvoyants
- Afficheur 7 segments pour compte à rebours piéton
- Communication série pour supervision sur PC
- Remplacement Arduino par ESP32 avec interface web de commande
