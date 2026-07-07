---
type: cours
titre: La carte de développement Arduino Uno
code: 2de-SEQ01-SÉA02
séquence: "[[2de-SEQ01 - Découverte Arduino ESP32]]"
séance: "[[2de-SEQ01 - SÉA02 - Découvrir la carte Arduino]]"
classe: Seconde TNE
compétences:
  - C04
  - C09
---

# La carte de développement Arduino Uno

## 1. Qu'est-ce qu'un microcontrôleur ?

Un **microcontrôleur** est un circuit intégré qui regroupe sur une seule puce :
- un **processeur** (exécute les instructions du programme)
- de la **mémoire** (stocke le programme et les données)
- des **entrées/sorties** (communique avec le monde extérieur)

La carte **Arduino Uno** est une carte de développement basée sur le microcontrôleur **ATmega328P**. Elle est conçue pour être facile à utiliser en prototypage et en enseignement.

---

## 2. Présentation de la carte Arduino Uno

![[SEQ02-arduino-uno-schema.png]]

### Les éléments principaux

| Élément | Rôle |
|---------|------|
| Microcontrôleur ATmega328P | Cerveau de la carte — exécute le programme |
| Connecteur USB type B | Alimentation et téléversement du programme |
| Régulateur de tension | Convertit le 5V USB en tension stable pour la carte |
| Bouton Reset | Redémarre le programme depuis le début |
| LED intégrée (L) | LED connectée à la broche D13 — utile pour tester |
| Connecteurs de broches | Permettent de connecter des composants extérieurs |

---

## 3. Les broches (pins)

### Broches numériques (D0 à D13)

- Peuvent être configurées en **entrée** (`INPUT`) ou en **sortie** (`OUTPUT`)
- Valeurs possibles : **0V (LOW)** ou **5V (HIGH)** uniquement
- Courant maximum par broche : **40 mA** (typiquement 20 mA recommandé)
- Les broches **D0 et D1** sont réservées à la communication série (UART) — à éviter

### Broches analogiques (A0 à A5)

- Peuvent **lire** une tension entre 0 et 5V (résolution 10 bits = 1024 valeurs)
- Peuvent aussi être utilisées comme broches numériques

### Broches d'alimentation

| Broche | Tension | Usage |
|--------|---------|-------|
| 5V | 5V | Alimentation des composants |
| 3,3V | 3,3V | Composants basse tension |
| GND | 0V | Référence commune (masse) |
| Vin | 7–12V | Alimentation externe |

> ⚠️ Le **GND** est la référence commune de toute l'électronique. Tout composant doit être connecté à GND pour former un circuit.

---

## 4. Pourquoi une résistance avec une LED ?

Une LED (Diode Électroluminescente) laisse passer le courant dans un seul sens. Sans résistance de limitation, elle laisserait passer un courant trop fort et **se détruirait immédiatement**.

**Calcul de la résistance de protection :**

$$R = \frac{V_{cc} - V_f}{I_f}$$

Avec :
- $V_{cc}$ = tension d'alimentation = **5V**
- $V_f$ = tension de seuil de la LED ≈ **2V** (rouge/verte) ou **3V** (bleue/blanche)
- $I_f$ = courant nominal de la LED = **20 mA = 0,02 A**

**Exemple pour une LED rouge :**

$$R = \frac{5 - 2}{0{,}02} = \frac{3}{0{,}02} = 150\ \Omega$$

En pratique, on utilisera une résistance de **220 Ω** (valeur normalisée disponible, un peu plus sécurisante).

---

## 5. Identifier une LED

Une LED a deux pattes de longueurs différentes :

```
      Anode (+)     Cathode (−)
         |               |
     (patte longue)  (patte courte)
         |               |
         └───── LED ─────┘
                  ↑
           côté plat = cathode
```

- **Anode (+)** → côté + de l'alimentation (ou broche Arduino)
- **Cathode (−)** → côté GND

---

## 6. Schéma de principe : LED sur broche D13

```
Arduino D13 ──── [220Ω] ──── Anode LED ──── Cathode LED ──── GND
```

Ce schéma est le point de départ de la séquence. Il sera réalisé dans TinkerCAD (SÉA03) puis sur breadboard (SÉA05).

---

## À retenir

> - L'Arduino Uno possède 14 broches numériques (D0–D13) et 6 broches analogiques (A0–A5)
> - Toujours mettre une résistance de protection avec une LED (220 Ω avec une alimentation 5V)
> - L'anode est la patte longue de la LED (+), la cathode est la patte courte (−)
> - Le GND est la référence commune de tous les composants
