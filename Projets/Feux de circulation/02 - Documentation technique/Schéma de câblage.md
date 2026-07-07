---
tags: [projet, feux-circulation, schema, cablage, CIEL, arduino]
date: 2026-04-03
statut: validé
niveau: Bac Pro CIEL — Seconde / Première
---

# Schéma de câblage — Système de feux de circulation

## 1. Tableau d'affectation des broches Arduino Uno

| Broche Arduino | Type | Composant | Désignation | Notes |
|---------------|------|-----------|-------------|-------|
| **D2** | Sortie numérique | D1 — LED rouge | Feu voiture — rouge | Via R1 (220 Ω) |
| **D3** | Sortie numérique | D2 — LED orange | Feu voiture — orange | Via R1 (220 Ω) |
| **D4** | Sortie numérique | D3 — LED verte | Feu voiture — vert | Via R1 (220 Ω) |
| **D5** | Sortie numérique | D4 — LED rouge | Feu piéton — rouge | Via R1 (220 Ω) |
| **D6** | Sortie numérique | D5 — LED verte | Feu piéton — vert | Via R1 (220 Ω) |
| **D7** | Entrée numérique | SW1 — Bouton piéton | Demande passage | Pull-down 10 kΩ sur GND |
| **D8** | Entrée numérique | SW2 — Bouton barrière | Commande barrière | Pull-down 10 kΩ sur GND |
| **D9** | Sortie PWM | SRV1 — Servomoteur | Signal PWM servo | Fil orange/jaune du servo |
| **A0** | Entrée analogique | LDR1 — Photorésistance | Mesure luminosité | Point milieu diviseur LDR/R3 |
| **5V** | Alimentation | Breadboard rail + | Alim. composants | LEDs, servo, pont LDR |
| **GND** | Masse | Breadboard rail − | Masse commune | Toutes masses |

---

## 2. Schéma de câblage détaillé par sous-système

### 2.1 Feu voiture tricolore (D1, D2, D3)

```
Arduino D2 ──── R1 (220 Ω) ──── Anode D1 (rouge)  ──── Cathode ──── GND
Arduino D3 ──── R1 (220 Ω) ──── Anode D2 (orange) ──── Cathode ──── GND
Arduino D4 ──── R1 (220 Ω) ──── Anode D3 (verte)  ──── Cathode ──── GND
```

**Points de vigilance :**
- Respecter la polarité des LEDs : anode (+) côté résistance, cathode (−) côté GND.
- Repérage visuel : la cathode est identifiée par la patte la plus courte et le méplat sur le boîtier.
- Ne jamais connecter une LED directement sur une broche Arduino sans résistance.

**Calcul de la résistance de limitation :**
- Tension d'alimentation : 5 V
- Tension de seuil LED rouge/orange/verte : ≈ 2,0 V (rouge, orange) / ≈ 2,1 V (verte)
- Courant nominal visé : 10 mA
- R = (5 V − 2,0 V) / 10 mA = **300 Ω** → valeur normalisée : **220 Ω** (courant réel ≈ 13 mA, acceptable)

---

### 2.2 Feu piéton bicolore (D4, D5)

```
Arduino D5 ──── R1 (220 Ω) ──── Anode D4 (rouge) ──── Cathode ──── GND
Arduino D6 ──── R1 (220 Ω) ──── Anode D5 (verte) ──── Cathode ──── GND
```

Même schéma que le feu voiture. Les 2 LEDs ne sont jamais allumées simultanément (logique logicielle).

---

### 2.3 Bouton poussoir piéton SW1 (D7)

```
5V ──── SW1 ──── D7 (Arduino)
                  │
                R2 (10 kΩ)
                  │
                 GND
```

**Schéma pull-down :**
- Quand SW1 est relâché : D7 est tiré à 0 V par R2 → `digitalRead(D7) = LOW (0)`
- Quand SW1 est pressé : D7 est connecté au 5 V → `digitalRead(D7) = HIGH (1)`
- La résistance R2 (10 kΩ) limite le courant lors de l'appui à 0,5 mA (négligeable).

> **Pourquoi pull-down et non pull-up ?**
> En pull-down, l'appui donne un `1` logique (plus intuitif pour les débutants).
> En pull-up interne Arduino (`INPUT_PULLUP`), la logique est inversée : relâché = 1, appuyé = 0. On préfère ici la résistance externe pull-down pour la clarté pédagogique.

---

### 2.4 Bouton poussoir barrière SW2 (D8)

```
5V ──── SW2 ──── D8 (Arduino)
                  │
                R2 (10 kΩ)
                  │
                 GND
```

Schéma identique à SW1. Broche D8 configurée en `INPUT`.

---

### 2.5 Servomoteur SG90 (D9)

Le servomoteur SG90 possède 3 fils :

| Couleur fil | Connexion Arduino |
|-------------|------------------|
| Rouge | 5V |
| Marron / Noir | GND |
| Orange / Jaune | D9 (PWM) |

```
Arduino 5V  ──── Fil rouge  (alimentation)
Arduino GND ──── Fil marron (masse)
Arduino D9  ──── Fil orange (signal PWM)
```

**Point de vigilance :**
- D9 est une broche PWM de l'Arduino Uno (Timer 1). La bibliothèque `Servo.h` génère automatiquement le signal PWM à 50 Hz avec une impulsion entre 1 ms (0°) et 2 ms (180°).
- Le SG90 consomme jusqu'à 150–200 mA en charge lors du déplacement. Pour une utilisation en démo, l'alimentation 5 V de l'USB est suffisante. Pour un usage prolongé, préférer une alimentation externe 5 V distincte pour le servo.
- Ne pas utiliser les broches D10 ou D11 si Servo.h est activé sur D9 (le Timer 1 est partagé).

---

### 2.6 Capteur LDR — diviseur de tension (A0)

```
5V ──── LDR1 ──── A0 (Arduino)
                   │
                 R3 (10 kΩ)
                   │
                  GND
```

**Principe du pont diviseur :**
- La LDR et R3 forment un diviseur de tension.
- En pleine lumière, la LDR a une résistance faible (≈ 1–5 kΩ) → tension sur A0 **élevée** (proche de 5 V).
- Dans l'obscurité, la LDR a une résistance élevée (≈ 100–500 kΩ) → tension sur A0 **basse** (proche de 0 V).
- `analogRead(A0)` retourne une valeur entre 0 et 1023 (résolution 10 bits).
- Seuil de passage en mode nuit : **valeur ADC < 300** (à ajuster selon la LDR et l'environnement).
- Hystérésis : retour en mode jour si **valeur ADC > 350** (évite les oscillations).

**Calcul de la tension à mi-obscurité (exemple) :**
- R_LDR = 50 kΩ (pénombre), R3 = 10 kΩ
- V_A0 = 5 V × 10 kΩ / (50 kΩ + 10 kΩ) = **0,83 V** → ADC ≈ 170 (< 300 → mode nuit activé)

---

## 3. Vue d'ensemble du câblage (schéma ASCII)

```
                        ARDUINO UNO
                   ┌─────────────────┐
              RESET │                 │ D13
               3.3V │                 │ D12
                 5V │●────────────────┼──── Rail + breadboard
                GND │●────────────────┼──── Rail − breadboard
                GND │                 │ D11
                Vin │                 │ D10
                    │                 │ D9 ●──── Signal servo SRV1
                 A0 │●──── LDR/R3     │ D8 ●──── SW2 (barrière)
                 A1 │                 │ D7 ●──── SW1 (piéton)
                 A2 │                 │ D6 ●──── R1 ── LED verte piéton (D5)
                 A3 │                 │ D5 ●──── R1 ── LED rouge piéton (D4)
                 A4 │                 │ D4 ●──── R1 ── LED verte voiture (D3)
                 A5 │                 │ D3 ●──── R1 ── LED orange voiture (D2)
                    │                 │ D2 ●──── R1 ── LED rouge voiture (D1)
                    └─────────────────┘
```

---

## 4. Notes générales de câblage

1. **Masse commune** : toutes les cathodes de LEDs, les résistances pull-down et la masse du servo sont connectées au rail GND de la breadboard, lui-même relié à une broche GND de l'Arduino.

2. **Rail 5 V** : l'alimentation 5 V de l'Arduino alimente le rail + de la breadboard. Ne jamais inverser les rails.

3. **Ordre de montage recommandé** :
   - Câbler d'abord les LEDs et résistances (pas d'alimentation active)
   - Vérifier les polarités des LEDs à l'ohmmètre avant de connecter l'Arduino
   - Ajouter les boutons et pull-down
   - Ajouter le servomoteur en dernier (vérifier la couleur des fils selon la référence)
   - Brancher la LDR et R3

4. **Test avant upload du code** : vérifier l'absence de court-circuit entre les rails avec l'ohmmètre (résistance > 1 kΩ entre 5 V et GND sans Arduino connecté).

5. **Broches non utilisées** : D0 (RX) et D1 (TX) sont réservées à la communication série USB — ne jamais y connecter de composant lors de l'upload.
