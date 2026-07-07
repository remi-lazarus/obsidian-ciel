---
type: projet-technique
titre: Robot Sumo autonome ESP32
code: SUMO-01
version: 0.0
date: 2026-06-10
auteur: ingenieur-ciel
statut: archivé
archive: true
---

# Robot Sumo — Fiche projet technique (v0)

> Version initiale — remplacée par [[Fiche projet — v0.1]]

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
            │  • Gestion capteurs bord (x4) │
            │  • Gestion capteurs adversaire │
            │  • Commande moteurs via PWM    │
            │  • Machine à états (logique)   │
            └──────┬─────────────┬──────────┘
                   │             │
       ┌───────────▼──┐   ┌──────▼──────────┐
       │   DRV8833    │   │  Sharp GP2Y0A21  │
       │  (pont en H) │   │  x2 (adversaire) │
       └──────┬───────┘   └─────────────────┘
              │
   ┌──────────┴──────────┐
   │  Moteur G  Moteur D │
   │  N20 30:1  N20 30:1 │
   └─────────────────────┘

   Sous le châssis :
   TCRT5000 x4 (détection bord — un par coin)
```

### Logique de décision (machine à états)

```
[ATTENTE 5s] → [RECHERCHE] ←→ [ATTAQUE]
                    ↑               ↓
               [REPLI BORD] ←── (si bord détecté)
```

- **ATTENTE** : immobile 5 secondes après signal
- **RECHERCHE** : rotation lente sur place, scan des capteurs adversaire
- **ATTAQUE** : fonce vers l'adversaire à pleine vitesse
- **REPLI** : marche arrière + virage si le bord est détecté

---

## 3. Liste des composants

### 3.1 Déjà disponible

| Composant | Note |
|---|---|
| ESP32 DevKit | Cerveau du robot |
| Imprimante 3D | Fabrication du châssis |
| Fusion 360 | Conception châssis + schéma électronique |

### 3.2 À commander

| Composant           | Référence                                | Qté | ~Prix unitaire |
| ------------------- | ---------------------------------------- | --- | -------------- |
| Moteurs             | N20 avec réducteur 30:1 — 6V             | 2   | 4–6 €          |
| Roues               | Compatibles N20, Ø 32–40 mm              | 2   | 2–4 €          |
| Pont en H           | DRV8833 breakout                         | 1   | 2–4 €          |
| Capteurs bord       | TCRT5000 (IR réflectif)                  | 4   | < 1 €          |
| Capteurs adversaire | Sharp GP2Y0A21YK (IR distance, 10–80 cm) | 2   | 3–5 €          |
| Batterie            | LiPo 2S — 750–1000 mAh                   | 1   | 10–14 €        |
| Chargeur            | iMax B3 (ou équivalent 2S)               | 1   | 8–12 €         |
| Régulateur 5V       | AMS1117-5V ou buck LM2596                | 1   | 1–2 €          |
| Interrupteur        | Slide switch — montage châssis           | 1   | < 1 €          |
| Visserie            | Assortiment M2 + M3                      | —   | 5 €            |
| Fils                | Dupont + silicone 22 AWG                 | —   | 5 €            |

**Budget estimé total : 50–70 €**

### 3.3 Répartition du poids estimée

| Élément | Masse estimée |
|---|---|
| Châssis 3D (PLA) | 100–120 g |
| Moteurs x2 + roues | 60–80 g |
| Électronique (ESP32 + driver + capteurs) | 60–80 g |
| Batterie LiPo 2S 750 mAh | 80–100 g |
| Lame avant (acier ou PLA renforcé) | 50–80 g |
| Visserie + câbles | 30–50 g |
| **Total estimé** | **380–510 g** |

---

## 4. Connexions électroniques

### Affectation des broches ESP32

| Broche ESP32 | Fonction |
|---|---|
| GPIO 32 | Moteur G — IN1 (DRV8833) |
| GPIO 33 | Moteur G — IN2 (DRV8833) |
| GPIO 25 | Moteur D — IN1 (DRV8833) |
| GPIO 26 | Moteur D — IN2 (DRV8833) |
| GPIO 34 | TCRT5000 — avant gauche |
| GPIO 35 | TCRT5000 — avant droit |
| GPIO 36 (VP) | TCRT5000 — arrière gauche |
| GPIO 39 (VN) | TCRT5000 — arrière droit |
| GPIO 27 | Sharp GP2Y0A21 — gauche (analogique) |
| GPIO 14 | Sharp GP2Y0A21 — droit (analogique) |
| EN | Bouton démarrage (pull-up) |
