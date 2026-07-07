---
type: cours
titre: Résistances de pull-up et pull-down
code: COURS-PULLUP
séquences:
  - "[[2de-SEQ02 - Évaluation Arduino Feux de circulation]]"
classe: Seconde TNE
compétences:
  - C04
  - C09
savoirs:
  - Structures programmables
  - Technologies de raccordement
  - Appareils de mesure (multimètre)
---

# Résistances de pull-up et pull-down

## 1. Le problème : une entrée qui « flotte »

Lors de la séquence SEQ03, vous avez connecté un bouton poussoir sur la broche D2 de l'Arduino pour déclencher la séquence piéton. Certains d'entre vous ont observé un comportement **imprévisible** : la séquence se déclenchait toute seule, sans appuyer sur le bouton.

**Pourquoi ?**

Regardons ce qui se passe avec un bouton branché « directement » sans résistance :

```
         Bouton ouvert
         ┌──────/──────┐
5V ──────┤             ├────── Broche D2 de l'Arduino
         └─────────────┘

         Bouton fermé
         ┌─────────────┐
5V ──────┤             ├────── Broche D2 de l'Arduino
         └─────────────┘
```

- **Bouton fermé** : la broche est connectée au 5V → l'Arduino lit **HIGH**. ✅ Clair.
- **Bouton ouvert** : la broche n'est connectée **à rien** du tout.

Quand une broche n'est connectée à rien, elle est dite **flottante** (*floating*). Sa tension est indéterminée : elle capte les perturbations électromagnétiques de la pièce (lumières, téléphones, câbles...). L'Arduino peut lire tantôt HIGH, tantôt LOW, de façon **aléatoire**.

> ⚠️ Une entrée flottante est une source de bugs impossible à corriger sans comprendre ce phénomène. C'est pour ça que votre bouton semblait "se déclencher tout seul".

**La solution** : forcer la broche à une tension connue quand le bouton est ouvert, grâce à une résistance. Il existe deux configurations : le **pull-down** et le **pull-up**.

---

## 2. La résistance de pull-down

### Principe

On place une résistance entre la broche et le **GND (0V)**. Elle « tire vers le bas » (*pull down*) la tension de la broche quand le bouton est ouvert.

```
                   Broche D2
                       │
         Bouton         │
5V ────── /  ──────────┤
                       │
                    [10 kΩ]     ← résistance de pull-down
                       │
                      GND (0V)
```

### Analyse des deux états

**Bouton ouvert :**

```
5V ────── /  (circuit ouvert)

                  Broche D2
                      │
               [10 kΩ] ← très peu de courant, mais la broche
                      │    est reliée au GND
                     GND
```

La broche est reliée au GND via la résistance → tension = **0V → Arduino lit LOW (0)**

**Bouton fermé :**

```
         ┌──────────────────── Broche D2
5V ──────┤
         │            [10 kΩ]
         └──────────────────── GND
```

La broche est directement reliée au 5V ET au GND via la résistance.  
Comme la résistance est grande (10 kΩ), presque tout le courant passe vers la broche → tension ≈ **5V → Arduino lit HIGH (1)**

> La résistance est grande exprès : elle limite le courant qui « fuit » vers le GND (quelques centaines de µA). Si elle était trop petite, elle consommerait inutilement beaucoup d'énergie.

### Résumé pull-down

| État du bouton | Tension sur la broche | Arduino lit |
|---------------|----------------------|-------------|
| Ouvert (relâché) | 0V (tiré vers GND) | **LOW (0)** |
| Fermé (appuyé) | 5V | **HIGH (1)** |

**Code Arduino avec pull-down :**
```cpp
pinMode(2, INPUT);                    // Entrée simple (pas de pull-up interne)

if (digitalRead(2) == HIGH) {         // HIGH = bouton appuyé
  // déclencher l'action
}
```

---

## 3. La résistance de pull-up

### Principe

Cette fois, on place la résistance entre la broche et le **5V**. Elle « tire vers le haut » (*pull up*) la tension de la broche quand le bouton est ouvert. Le bouton relie la broche au **GND**.

```
                  5V
                   │
               [10 kΩ]     ← résistance de pull-up
                   │
                   ├────── Broche D2
                   │
         Bouton
GND ──── /  ──────
```

### Analyse des deux états

**Bouton ouvert :**

```
5V ─── [10 kΩ] ─── Broche D2

GND ─── /  (circuit ouvert, ne tire pas vers le bas)
```

La broche est reliée au 5V via la résistance → tension = **5V → Arduino lit HIGH (1)**

**Bouton fermé :**

```
5V ─── [10 kΩ] ─── Broche D2 ─── (bouton fermé) ─── GND
```

Le bouton relie directement la broche au GND. Comme le GND impose 0V, la broche est tirée à **0V → Arduino lit LOW (0)**

> La logique est **inversée** par rapport au pull-down : bouton appuyé = LOW, bouton relâché = HIGH. C'est contre-intuitif au départ, mais c'est la configuration la plus courante !

### Résumé pull-up

| État du bouton | Tension sur la broche | Arduino lit |
|---------------|----------------------|-------------|
| Ouvert (relâché) | 5V (tiré vers 5V) | **HIGH (1)** |
| Fermé (appuyé) | 0V (relié à GND) | **LOW (0)** |

**Code Arduino avec pull-up externe :**
```cpp
pinMode(2, INPUT);                    // Entrée simple

if (digitalRead(2) == LOW) {          // LOW = bouton appuyé (logique inversée !)
  // déclencher l'action
}
```

---

## 4. Le pull-up interne de l'Arduino

### Bonne nouvelle : pas besoin de résistance externe !

L'Arduino Uno intègre une résistance de pull-up **à l'intérieur** de chaque broche numérique. Elle vaut environ **20 à 50 kΩ**. Il suffit de l'activer avec `INPUT_PULLUP` :

```cpp
pinMode(2, INPUT_PULLUP);   // Active la résistance pull-up interne
```

Le circuit est alors équivalent à :

```
          5V (interne)
              │
          [~47 kΩ]   ← résistance interne activée par INPUT_PULLUP
              │
              ├───── Broche D2
              │
    Bouton
GND ── /  ───
```

### Ce que ça change dans le câblage

Avec `INPUT_PULLUP`, **on ne câble plus rien entre la broche et le 5V** — c'est fait en interne. Le bouton relie simplement la broche à GND :

```
Arduino D2 ────────────────────┐
                               │
                           Bouton poussoir
                               │
GND ───────────────────────────┘
```

Le câblage est plus simple ! C'est pour ça que c'est la méthode la plus utilisée avec Arduino.

### La logique reste inversée

Comme avec un pull-up externe, la lecture est inversée :

| État du bouton | Arduino lit |
|---------------|-------------|
| Relâché | **HIGH (1)** |
| Appuyé | **LOW (0)** |

**Code Arduino avec `INPUT_PULLUP` — ce que vous avez utilisé dans SEQ03 :**
```cpp
pinMode(BOUTON, INPUT_PULLUP);

// Attendre l'appui du bouton
while (digitalRead(BOUTON) == HIGH) {
  // On attend... HIGH = bouton relâché
}
// Ici, digitalRead(BOUTON) == LOW → bouton appuyé → on continue
```

---

## 5. Comparaison des trois solutions

| Configuration | Résistance externe | Bouton relâché | Bouton appuyé | Complexité câblage |
|--------------|-------------------|----------------|---------------|-------------------|
| Sans résistance | Non | ⚠️ Flottant | HIGH | Minimal mais **inutilisable** |
| Pull-down externe | 10 kΩ vers GND | LOW | HIGH | Moyenne |
| Pull-up externe | 10 kΩ vers 5V | HIGH | LOW (inversé) | Moyenne |
| Pull-up interne (`INPUT_PULLUP`) | Non (intégrée) | HIGH | LOW (inversé) | **Minimale** ✅ |

---

## 6. Quand utiliser pull-up ou pull-down ?

**Pull-down** → logique « naturelle » (appuyé = 1), à utiliser quand :
- Tu veux que `HIGH` signifie "actif" (plus lisible dans le code)
- La résistance externe ne pose pas de problème

**Pull-up interne Arduino** → le choix le plus simple dans 95% des cas :
- Pas de résistance externe à ajouter
- Câblage minimal (bouton entre broche et GND)
- Disponible sur toutes les broches numériques Arduino

> Dans les systèmes industriels, le pull-up externe (avec une vraie résistance) est souvent préféré car il est plus robuste aux perturbations électromagnétiques que le pull-up interne (~47 kΩ, moins efficace sur de longues liaisons filaires).

---

## 7. Application — Retour sur SEQ03

Dans l'évaluation SEQ03, vous avez utilisé :

```cpp
pinMode(BOUTON, INPUT_PULLUP);       // Pull-up interne activé

while (digitalRead(BOUTON) == HIGH) {  // HIGH = pas appuyé
  // on attend
}
// LOW = appuyé → on lance la séquence
```

Et le câblage était :
```
Arduino D2 ──── [bouton poussoir] ──── GND
```

**Sans `INPUT_PULLUP`**, quand le bouton était relâché, la broche D2 était flottante. L'Arduino lisait une valeur aléatoire → la séquence se déclenchait toute seule. C'est exactement ce que certains ont observé en cours.

**Avec `INPUT_PULLUP`** :
- Bouton relâché → D2 tiré à 5V → `HIGH` → on reste dans la boucle d'attente ✅
- Bouton appuyé → D2 tiré à 0V → `LOW` → on sort de la boucle et la séquence démarre ✅

---

## À retenir

> - Une broche d'entrée non connectée est **flottante** → valeur aléatoire → bugs
> - Une **résistance de pull-down** tire la broche vers GND (0V) quand le bouton est ouvert → relâché = LOW, appuyé = HIGH
> - Une **résistance de pull-up** tire la broche vers 5V quand le bouton est ouvert → relâché = HIGH, appuyé = LOW
> - `pinMode(broche, INPUT_PULLUP)` active la résistance pull-up **intégrée** dans l'Arduino → plus besoin de résistance externe
> - Avec `INPUT_PULLUP`, la logique est **inversée** : bouton appuyé = LOW
