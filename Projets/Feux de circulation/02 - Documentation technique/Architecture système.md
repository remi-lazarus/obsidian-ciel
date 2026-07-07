---
tags: [projet, feux-circulation, architecture, machine-etats, CIEL, arduino]
date: 2026-04-03
statut: validé
niveau: Bac Pro CIEL — Seconde / Première
---

# Architecture système — Système de feux de circulation

## 1. Vue d'ensemble de l'architecture logicielle

### 1.1 Choix architectural : machine à états finis (FSM)

Le programme est structuré autour d'une **machine à états finis** (Finite State Machine — FSM). C'est le paradigme le plus adapté pour ce type de système car :

- Le comportement dépend d'un **état courant** bien défini à tout instant.
- Les **transitions** entre états sont déclenchées par des événements (appui bouton, temporisation, mesure capteur).
- On évite les `delay()` bloquants qui empêcheraient la détection des boutons ou du capteur pendant une séquence.
- Le code est lisible, testable et extensible.

### 1.2 Principe de non-blocage : `millis()` vs `delay()`

> **Règle fondamentale :** on n'utilise jamais `delay()` dans la boucle principale `loop()`.

La fonction `millis()` retourne le temps écoulé depuis le démarrage en millisecondes. On mémorise l'instant de début d'une étape (`unsigned long tDebut`), et on compare à l'instant courant pour savoir si la durée est écoulée :

```cpp
if (millis() - tDebut >= DUREE_MS) {
    // durée écoulée → changer d'état
}
```

Cette approche permet à `loop()` de s'exécuter en continu (~5 000 à 50 000 itérations/seconde) sans jamais bloquer, ce qui permet de lire les capteurs et boutons à chaque cycle.

---

## 2. États du système

### 2.1 Liste des états

| Identifiant | Nom | Description |
|-------------|-----|-------------|
| `ETAT_JOUR_VERT` | Jour — Vert voiture | Feu voiture vert, feu piéton rouge. Attente appui SW1. |
| `ETAT_JOUR_ORANGE_TRANSITION` | Jour — Orange transition | Feu voiture orange (2 s), préparation passage piéton. |
| `ETAT_JOUR_ROUGE_PIETON` | Jour — Passage piéton | Feu voiture rouge, feu piéton vert (5 s). |
| `ETAT_JOUR_FIN_PASSAGE` | Jour — Fin passage | Feu piéton clignotant rouge (2 s), avertissement fin traversée. |
| `ETAT_NUIT` | Nuit | Tous feux en orange clignotant. Boutons inactifs. |

### 2.2 Variables d'état du servomoteur

La barrière a son propre état booléen, indépendant de la FSM principale :

| Variable | Valeur | Signification |
|----------|--------|---------------|
| `barriereOuverte` | `true` | Servo à 90° — barrière levée |
| `barriereOuverte` | `false` | Servo à 0° — barrière abaissée |

---

## 3. Diagramme d'états (FSM principale)

```
                         ┌──────────────────────────────────┐
                         │           DÉMARRAGE               │
                         │      → ETAT_JOUR_VERT              │
                         └────────────────┬─────────────────┘
                                          │
                                          ▼
          ┌──────────────────────────────────────────────────────┐
          │                    ETAT_JOUR_VERT                    │
          │  Feu voiture : VERT                                  │
          │  Feu piéton  : ROUGE                                 │
          │  Attente : appui SW1 (et délai_min écoulé)           │
          └──────────────────┬───────────────────────┬──────────┘
                             │ SW1 pressé             │ LDR < seuil_nuit
                             ▼                        ▼
   ┌─────────────────────────────┐    ┌──────────────────────────────┐
   │  ETAT_JOUR_ORANGE_TRANSITION│    │         ETAT_NUIT            │
   │  Feu voiture : ORANGE       │    │  Feu voiture : ORANGE clign. │
   │  Feu piéton  : ROUGE        │    │  Feu piéton  : ORANGE clign. │
   │  Durée : 2 s                │    │  Boutons inactifs            │
   └─────────────┬───────────────┘    └──────────────┬───────────────┘
                 │ 2 s écoulées                       │ LDR > seuil_jour
                 ▼                                    │
   ┌─────────────────────────────┐                    │
   │   ETAT_JOUR_ROUGE_PIETON    │                    │
   │  Feu voiture : ROUGE        │                    │
   │  Feu piéton  : VERT         │                    │
   │  Durée : 5 s                │                    │
   └─────────────┬───────────────┘                    │
                 │ 5 s écoulées                        │
                 ▼                                    │
   ┌─────────────────────────────┐                    │
   │     ETAT_JOUR_FIN_PASSAGE   │                    │
   │  Feu voiture : ROUGE        │                    │
   │  Feu piéton  : ROUGE clign. │                    │
   │  Durée : 2 s                │                    │
   └─────────────┬───────────────┘                    │
                 │ 2 s écoulées                        │
                 └──────────────► ETAT_JOUR_VERT ◄────┘
                                  (mémorisation tDernierPassage)
```

**Note sur les transitions vers ETAT_NUIT :**
La vérification de la luminosité est effectuée à chaque itération de `loop()`, mais **uniquement depuis `ETAT_JOUR_VERT`** (pendant les séquences en cours, on termine la séquence avant de passer en mode nuit). Cela évite d'interrompre une séquence piéton en cours.

---

## 4. Chronogrammes des séquences

### 4.1 Séquence passage piéton complète

```
Temps (s) →   0         2         7         9        (t+10 s minimum)
              │         │         │         │         │
SW1 ─────────┐│         │         │         │         │
              ▼│         │         │         │         │
 Feu  VERT  ══╪═══╗     │         │         │         ╔══════════
voiture       │   ║     │         │         │         ║
       ORANGE │   ╚═════╝         │         │         │
              │         │         │         │         │
        ROUGE │         ╚═════════╪═════════╝         │
              │                   │         │
 Feu  ROUGE  ═╪═══════════════════╗         ╔═════════╪══════════
piéton        │                   ║         ║(clign.) │
        VERT  │                   ╚═════════╝         │
              │
              ├── État ──┤ ORANGE  ├── ROUGE PIETON ──┤ FIN  ├── VERT
              │  VERT    │ TRANS.  │                   │PASS. │
              │  (attente│ (2 s)   │      (5 s)        │(2 s) │
```

### 4.2 Clignotement mode nuit (1 Hz)

```
Temps (ms) → 0    500   1000  1500  2000  2500
LED orange  ┌────┐     ┌────┐     ┌────┐
            │ ON │ OFF │ ON │ OFF │ ON │ ...
            └────┘     └────┘     └────┘
```

Implémentation sans `delay()` :
```cpp
if (millis() - tClignotement >= 500) {
    tClignotement = millis();
    etatClignotement = !etatClignotement;
    // Mettre à jour les LEDs orange selon etatClignotement
}
```

### 4.3 Commande barrière (événementielle)

```
Temps →     t0          t1          t2          t3
SW2         ─┐ ┌─       ─┐ ┌─       ─┐ ┌─
              └┘           └┘           └┘
Servo     0° ════╗       ════════╗    ══════════╗
               90°╚══════╝    0°╚════╝       90°╚══
barriereOuverte: F → T          T → F            F → T
```

---

## 5. Structure du code (pseudo-code)

```
INITIALISATION :
  Configurer toutes les broches (pinMode)
  Attacher le servo sur D9
  Fermer la barrière (servo 0°)
  État initial = ETAT_JOUR_VERT
  Activer feu vert voiture + feu rouge piéton

BOUCLE PRINCIPALE (loop) :
  │
  ├── 1. LIRE les capteurs
  │     lireLDR()          → valeur 0–1023
  │     lireBoutonPieton() → true/false (avec anti-rebond)
  │     lireBoutonBarriere() → true/false (avec anti-rebond)
  │
  ├── 2. GÉRER mode nuit
  │     si valeur_LDR < SEUIL_NUIT → passer en ETAT_NUIT
  │     si valeur_LDR > SEUIL_JOUR → passer en ETAT_JOUR_VERT
  │
  ├── 3. EXÉCUTER la machine à états (FSM)
  │     selon etatCourant :
  │       ETAT_JOUR_VERT          → gererEtatVert()
  │       ETAT_JOUR_ORANGE_TRANS  → gererEtatOrangeTransition()
  │       ETAT_JOUR_ROUGE_PIETON  → gererEtatPassagePieton()
  │       ETAT_JOUR_FIN_PASSAGE   → gererEtatFinPassage()
  │       ETAT_NUIT               → gererEtatNuit()
  │
  └── 4. GÉRER la barrière (indépendant de la FSM feux)
        si boutonBarriere pressé ET mode jour → basculerBarriere()
```

---

## 6. Fonctions principales

| Fonction | Rôle |
|----------|------|
| `setup()` | Initialisation des broches, servo, état initial |
| `loop()` | Boucle principale : lecture capteurs + FSM + barrière |
| `gererFeux(rouge, orange, vert, rPieton, vPieton)` | Allume/éteint les 5 LEDs selon paramètres booléens |
| `gererEtatVert()` | Logique de l'état JOUR_VERT : attend appui SW1 |
| `gererEtatOrangeTransition()` | Logique de l'état ORANGE_TRANSITION : temporisation 2 s |
| `gererEtatPassagePieton()` | Logique de l'état ROUGE_PIETON : temporisation 5 s |
| `gererEtatFinPassage()` | Logique de l'état FIN_PASSAGE : clignotement rouge piéton 2 s |
| `gererEtatNuit()` | Logique du mode nuit : clignotement orange tous feux |
| `basculerBarriere()` | Bascule la position du servo et la variable `barriereOuverte` |
| `lireButtonAvecDebounce(broche, &dernierEtat, &dernierTemps)` | Lecture bouton avec anti-rebond (50 ms) |

---

## 7. Points de vigilance techniques

### 7.1 Anti-rebond des boutons (debounce)

Les boutons mécaniques produisent des oscillations parasites (rebonds) lors de l'appui, sur une durée de 5 à 50 ms. Sans anti-rebond, un seul appui peut être détecté plusieurs fois.

**Solution logicielle :** on ne valide un changement d'état du bouton que s'il est stable depuis au moins 50 ms.

```cpp
// Principe anti-rebond
unsigned long tDernierChangement = 0;
bool dernierEtatBrut = LOW;

bool lireBouton(int broche) {
    bool etatBrut = digitalRead(broche);
    if (etatBrut != dernierEtatBrut) {
        tDernierChangement = millis();
        dernierEtatBrut = etatBrut;
    }
    if ((millis() - tDernierChangement) > 50) {
        return etatBrut;
    }
    return !etatBrut; // état instable → on renvoie l'ancien état
}
```

### 7.2 Débordement de `millis()`

`millis()` retourne un `unsigned long` qui déborde après ~49 jours. La soustraction `millis() - tDebut` reste correcte même au débordement grâce à l'arithmétique non signée du C. **Ne jamais comparer directement** `millis() >= tDebut + duree` (risque de débordement).

Forme correcte :
```cpp
if ((millis() - tDebut) >= DUREE) { ... }  // OK
if (millis() >= tDebut + DUREE) { ... }    // INCORRECT si débordement
```

### 7.3 Servo et broches PWM

- La bibliothèque `Servo.h` désactive le PWM sur les broches D9 et D10 dès qu'elle est initialisée. Ne pas utiliser ces broches pour autre chose.
- Utiliser `servo.write(angle)` et non `analogWrite()` pour commander le servo.
- Laisser un délai de stabilisation de 15–20 ms après un `servo.write()` avant de couper l'alimentation (le servo doit avoir atteint sa position).

### 7.4 Calibration du seuil LDR

La valeur de seuil ADC dépend de la LDR utilisée et de l'éclairage de la salle. La constante `SEUIL_NUIT` (valeur par défaut : 300) doit être ajustée lors de la mise en service :
1. Afficher `analogRead(A0)` dans le moniteur série en mode journée.
2. Couvrir la LDR avec la main et noter la valeur.
3. Choisir un seuil entre les deux valeurs, avec 50 points d'hystérésis.

### 7.5 Séquence piéton non interruptible

Une fois la séquence piéton déclenchée, elle va jusqu'à son terme. Un second appui sur SW1 pendant la séquence est ignoré. Le délai minimum entre deux séquences (`DELAI_MIN_ENTRE_PASSAGES` = 10 000 ms) est géré par comparaison avec `tDernierPassage`.
