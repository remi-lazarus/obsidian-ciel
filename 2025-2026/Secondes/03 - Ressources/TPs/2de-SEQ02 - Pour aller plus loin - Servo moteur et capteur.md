---
type: tp
titre: Pour aller plus loin — Servo moteur et capteur de lumière
code: 2de-SEQ02-BONUS
séquence: "[[2de-SEQ02 - Évaluation Arduino Feux de circulation]]"
classe: Seconde TNE
type_séance: Approfondissement
statut: fait
---

# Pour aller plus loin — Servo moteur et capteur de lumière

> Ces activités sont destinées aux élèves ayant terminé l'évaluation principale avant la fin du temps imparti.

---

## Activité A — Le servo moteur

Un **servo moteur** est un actionneur qui permet de positionner un axe à un **angle précis** (0° à 180°). Il est utilisé dans les systèmes de contrôle (barrières, bras robotiques, volets, etc.).

### Utilisation avec Arduino

Arduino dispose d'une bibliothèque `Servo.h` qui simplifie la commande :

```cpp
#include <Servo.h>

Servo monServo;

void setup() {
  monServo.attach(9);   // Servo connecté sur broche D9
}

void loop() {
  monServo.write(0);    // Position 0°
  delay(1000);
  monServo.write(90);   // Position 90°
  delay(1000);
  monServo.write(180);  // Position 180°
  delay(1000);
}
```

### Idée d'extension

Ajouter une **barrière automatique** au système TechSignal : quand le feu piéton passe au vert, un servo fait descendre la barrière voiture à 90° ; quand le feu repasse au rouge, la barrière se relève à 0°.

> 📄 Voir le document PDF fourni pour l'activité complète sur les servomoteurs.

---

## Activité B — Le capteur de lumière (LDR)

Une **LDR** (Light Dependent Resistor) est une résistance dont la valeur **diminue quand la lumière augmente**. Connectée sur une entrée analogique Arduino, elle permet de mesurer l'intensité lumineuse.

### Utilisation avec Arduino

```cpp
void setup() {
  Serial.begin(9600);   // Ouvrir le moniteur série
}

void loop() {
  int lumiere = analogRead(A0);   // Valeur entre 0 (obscur) et 1023 (lumineux)
  Serial.println(lumiere);
  delay(200);
}
```

### Câblage (pont diviseur)

```
5V ──── [LDR] ──── A0 ──── [10kΩ] ──── GND
```

### Idée d'extension

Allumage automatique des feux la nuit : si `analogRead(A0) < 300` (obscurité), activer le clignotement orange en continu (mode nuit des feux de carrefour).

> 📄 Voir le document PDF fourni pour l'activité complète sur les entrées analogiques.

---

## Ressources PDF

> Les documents PDF sont disponibles dans les ressources Moodle de la séquence :
> - *Activité 4 — Les librairies — Les servomoteurs*
> - *Activité 3 — Entrée analogique — Sortie série*
