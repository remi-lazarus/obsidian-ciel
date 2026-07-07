---
type: tp
titre: TP2 — Feu de circulation sur matériel physique
code: 2de-SEQ01-SÉA05
séquence: "[[2de-SEQ01 - Découverte Arduino ESP32]]"
séance: "[[2de-SEQ01 - SÉA05 - TP2 matériel physique]]"
classe: Seconde TNE
outil: Arduino IDE + breadboard
durée: 2h
prérequis: "[[2de-SEQ01 - SÉA04 - TD1 feu de circulation]]"
---

# TP2 — Feu de circulation sur matériel physique

**Noms / Prénoms (binôme) :** _____________________________ / _____________________________  
**Classe :** ___________  **Date :** ___________

> ⚠️ **Prérequis :** La simulation TinkerCAD (TD1) doit être validée avant de commencer ce TP.

---

## Contexte

La simulation est validée. Chez **TechSignal**, l'étape suivante est la **réalisation physique** du prototype. Tu vas maintenant reproduire le montage sur breadboard et téléverser le programme sur une vraie carte Arduino.

---

## Matériel fourni

| Quantité | Composant |
|----------|-----------|
| 1 | Carte Arduino Uno |
| 1 | Breadboard (plaque d'essai) |
| 1 | LED rouge |
| 1 | LED orange (ou jaune) |
| 1 | LED verte |
| 3 | Résistances 220 Ω |
| 1 | Câble USB (Arduino → ordinateur) |
| Plusieurs | Câbles de connexion (fils) |

---

## Partie 1 — Câblage sur breadboard

### Comment fonctionne une breadboard ?

```
  +  − a b c d e   f g h i j  + −
  │  │ ╔═══════╗   ╔═══════╗  │ │
1 │  │ ║       ║   ║       ║  │ │   ← Rangées horizontales reliées
2 │  │ ║       ║   ║       ║  │ │      5 trous par rangée, par côté
  ...
  Rails +/− : colonnes reliées sur toute la longueur
```

- Les **rangées** (horizontales) sont reliées entre elles (5 trous côté gauche, 5 côté droit)
- Les **rails** + et − (colonnes verticales) sont reliés sur toute la longueur

### Question 1

Avant de câbler, identifie sur ta breadboard :

☐ Les rails d'alimentation (+) et de masse (−)  
☐ La séparation centrale (les deux moitiés ne sont PAS reliées)  

---

### Question 2 — Réalisation du montage

Réalise le câblage sur breadboard en suivant le schéma ci-dessous :

```
Arduino          Breadboard
─────────────────────────────────────────────
D11 ──────────── [220Ω] ──── Anode LED verte
D12 ──────────── [220Ω] ──── Anode LED orange
D13 ──────────── [220Ω] ──── Anode LED rouge
GND ──────────── Rail GND (−)
                 Cathodes des 3 LEDs ──── Rail GND (−)
5V  ──────────── Rail 5V (+)  [si besoin d'alimentation externe]
```

> 💡 **Rappel polarité LED :** patte longue = Anode (+) · patte courte = Cathode (−)

☐ Câblage réalisé  
☐ Polarités des LEDs vérifiées  
☐ Toutes les cathodes reliées au GND  

---

## Partie 2 — Programmation avec Arduino IDE

### Ouvrir Arduino IDE

1. Lancer **Arduino IDE** sur le poste de travail
2. Créer un nouveau fichier (`Fichier > Nouveau`)

### Question 3 — Saisir le programme

Recopier ou adapter le code validé dans TinkerCAD. S'assurer que le programme est **commenté** :

```cpp
// Feu de circulation — TechSignal
// Auteurs : ___________________________
// Date : ___________________________

// Définition des broches
const int PIN_VERT   = 11;
const int PIN_ORANGE = 12;
const int PIN_ROUGE  = 13;

void setup() {
  // Configuration des broches en sortie
  pinMode(PIN_VERT,   OUTPUT);
  pinMode(PIN_ORANGE, OUTPUT);
  pinMode(PIN_ROUGE,  OUTPUT);
}

void loop() {
  // --- Feu VERT (10 secondes) ---
  digitalWrite(PIN_VERT,   HIGH);
  digitalWrite(PIN_ORANGE, LOW);
  digitalWrite(PIN_ROUGE,  LOW);
  delay(10000);

  // --- Feu ORANGE (3 secondes) ---
  digitalWrite(PIN_VERT,   LOW);
  digitalWrite(PIN_ORANGE, HIGH);
  digitalWrite(PIN_ROUGE,  LOW);
  delay(3000);

  // --- Feu ROUGE (10 secondes) ---
  digitalWrite(PIN_VERT,   LOW);
  digitalWrite(PIN_ORANGE, LOW);
  digitalWrite(PIN_ROUGE,  HIGH);
  delay(10000);
}
```

---

### Question 4 — Configurer Arduino IDE

1. Brancher la carte Arduino en USB
2. Dans le menu **Outils** :
   - Vérifier **Type de carte** → `Arduino Uno`
   - Vérifier **Port** → sélectionner le port COM avec `Arduino Uno`

Quel port COM est affiché sur ton poste ?  Port : ___________

---

### Question 5 — Compiler et téléverser

1. Cliquer sur le bouton ✓ (**Vérifier / Compiler**)
2. Le message en bas doit indiquer : `Compilation terminée.`
3. Cliquer sur → (**Téléverser**)
4. Attendre le message : `Téléversement terminé.`

| Étape | Résultat | Problème rencontré |
|-------|----------|-------------------|
| Compilation | ☐ OK ☐ Erreur | |
| Téléversement | ☐ OK ☐ Erreur | |

> Si une erreur apparaît : noter le message d'erreur et appeler le professeur.

---

## Partie 3 — Tests et validation

### Question 6 — Vérification du fonctionnement

Observer le feu pendant au moins un cycle complet et noter les résultats :

| Test | Résultat | Conforme ? |
|------|----------|------------|
| LED verte s'allume en premier | | ☐ Oui ☐ Non |
| Durée du feu vert ≈ 10 s | | ☐ Oui ☐ Non |
| Durée du feu orange ≈ 3 s | | ☐ Oui ☐ Non |
| Durée du feu rouge ≈ 10 s | | ☐ Oui ☐ Non |
| Une seule LED allumée à la fois | | ☐ Oui ☐ Non |
| Cycle se répète indéfiniment | | ☐ Oui ☐ Non |

---

### Question 7 — Bilan

**Quelle différence as-tu observée entre la simulation TinkerCAD et le matériel physique ?**

> _____________________________________________________________________
> _____________________________________________________________________
> _____________________________________________________________________

**Quelle difficulté as-tu rencontrée lors du câblage sur breadboard ?**

> _____________________________________________________________________
> _____________________________________________________________________

---

## ✅ Validation professeur

Appelle le professeur pour la démonstration finale.

| Critère d'évaluation | Validé |
|---------------------|--------|
| TinkerCAD et Arduino IDE utilisés pour programmer la carte | ☐ |
| Pas d'erreur de compilation dans le terminal | ☐ |
| Le feu respecte la séquence (vert → orange → rouge) | ☐ |
| L'élève peut expliquer comment il a validé le fonctionnement | ☐ |
| La boucle `setup()` et `loop()` sont identifiées dans le code | ☐ |
| Le montage est câblé, testé et validé dans les 4h du TP | ☐ |
| Le travail en binôme est solidaire | ☐ |

**Signature professeur :** ___________________________
