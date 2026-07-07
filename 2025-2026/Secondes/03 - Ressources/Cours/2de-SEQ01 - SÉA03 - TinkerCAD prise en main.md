---
type: cours
titre: TinkerCAD — Prise en main du simulateur
code: 2de-SEQ01-SÉA03
séquence: "[[2de-SEQ01 - Découverte Arduino ESP32]]"
séance: "[[2de-SEQ01 - SÉA03 - Découvrir TinkerCAD]]"
classe: Seconde TNE
compétences:
  - C04
  - C08
---

# TinkerCAD — Prise en main du simulateur

## 1. Qu'est-ce que TinkerCAD ?

**TinkerCAD** (https://www.tinkercad.com) est un outil en ligne gratuit d'Autodesk qui permet de :
- **Simuler** des circuits électroniques avec Arduino **sans matériel physique**
- **Programmer** l'Arduino en blocs (Scratch) ou en code C
- **Tester** et déboguer son programme avant de le réaliser sur du vrai matériel

> C'est l'outil utilisé chez TechSignal pour valider un prototype avant toute commande de composants.

---

## 2. Interface TinkerCAD Circuits

![[_assets/SEQ02-tinkercad-circuit-led.png]]

### Les zones principales

| Zone | Rôle |
|------|------|
| Zone de travail (centre) | Espace où on place et câble les composants |
| Bibliothèque (droite) | Catalogue de composants à glisser-déposer |
| Bouton "Démarrer la simulation" | Lance la simulation du circuit |
| Éditeur de code (bas/droite) | Fenêtre de programmation (blocs ou texte) |

---

## 3. Câbler un circuit dans TinkerCAD

### Étape 1 — Placer les composants

1. Dans la bibliothèque (colonne de droite), rechercher "Arduino Uno" → glisser dans la zone de travail
2. Rechercher "LED" → placer à droite de l'Arduino
3. Rechercher "Résistance" → placer entre l'Arduino et la LED

### Étape 2 — Câbler

- Cliquer sur une **broche** de l'Arduino → un fil apparaît
- Cliquer sur la **patte correspondante** du composant pour relier
- Les fils se colorent automatiquement selon la convention (rouge = +, noir = GND)

**Connexions à réaliser :**

```
Broche D13 ──► Résistance (patte 1)
Résistance (patte 2) ──► Anode LED (+, patte longue)
Cathode LED (−, patte courte) ──► GND Arduino
```

### Étape 3 — Configurer la résistance

- Double-cliquer sur la résistance
- Saisir la valeur : **220 Ω**

---

## 4. Programmer avec les blocs (interface Scratch)

Cliquer sur **"Code"** en haut de l'interface, puis choisir **"Blocs"**.

### Structure d'un programme Arduino

Tout programme Arduino est composé de deux fonctions :

| Fonction | Exécution | Rôle |
|----------|-----------|------|
| `setup()` | Une seule fois au démarrage | Initialisation (configurer les broches) |
| `loop()` | En boucle infinie | Comportement répété (faire clignoter, lire un capteur…) |

### Programme "LED clignotante" en blocs

```
[ setup ]
  └─ Définir broche 13 en SORTIE

[ répéter indéfiniment ]  ← loop()
  └─ Mettre broche 13 à HAUT  (LED allumée)
  └─ Attendre 1 seconde
  └─ Mettre broche 13 à BAS   (LED éteinte)
  └─ Attendre 1 seconde
```

### Équivalent en code C (Arduino)

```cpp
void setup() {
  pinMode(13, OUTPUT);   // Configure la broche 13 en sortie
}

void loop() {
  digitalWrite(13, HIGH);  // Allume la LED
  delay(1000);             // Attend 1 seconde (1000 ms)
  digitalWrite(13, LOW);   // Éteint la LED
  delay(1000);             // Attend 1 seconde
}
```

> `delay(n)` attend **n millisecondes** → `delay(1000)` = 1 seconde, `delay(3000)` = 3 secondes

---

## 5. Lancer la simulation

1. Cliquer sur le bouton vert **"Démarrer la simulation"**
2. Observer le circuit : la LED doit clignoter
3. Pour arrêter : cliquer sur **"Arrêter la simulation"**

> En simulation, les composants se comportent exactement comme en réalité. Si la LED ne clignote pas, vérifier le câblage et le programme.

---

## 6. Passer du mode blocs au mode texte

TinkerCAD génère automatiquement le code C à partir des blocs. On peut basculer en mode **"Texte"** pour voir le code correspondant.

C'est ce code C qui sera utilisé dans **Arduino IDE** pour le matériel physique (SÉA05).

---

## À retenir

> - TinkerCAD permet de simuler un circuit Arduino sans matériel
> - Un programme Arduino = `setup()` (une fois) + `loop()` (en boucle)
> - `pinMode(broche, OUTPUT)` configure une broche en sortie
> - `digitalWrite(broche, HIGH/LOW)` allume ou éteint la broche
> - `delay(ms)` fait attendre le programme (en millisecondes)
