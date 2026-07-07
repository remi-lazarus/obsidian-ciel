---
type: support-élève
titre: Évaluation — Feux de circulation voitures et piétons
code: 2de-SEQ02-EVAL
séquence: "[[2de-SEQ02 - Évaluation Arduino Feux de circulation]]"
classe: Seconde TNE
outil: TinkerCAD puis Arduino IDE + breadboard
durée: 5h (3 séances)
compétences:
  - C07
  - C08
---

# Évaluation — Feux de circulation voitures et piétons

**Nom / Prénom :** _____________________________ **Classe :** ___________  **Date :** ___________

---

## Contexte

Tu es stagiaire chez **TechSignal**. Après avoir réalisé un feu tricolore simple, ton responsable te confie une mission plus complexe : réaliser un système complet avec un **feu voiture**, un **feu piéton** et un **bouton d'appel** permettant aux piétons de demander à traverser.

---

## Fonctionnement du système

### Matériel

- Des LEDs de couleurs : **rouge, orange, verte** (feux voitures) + **rouge, verte** (feux piétons)
- Un microcontrôleur **Arduino Uno**
- Un **bouton poussoir** (bouton d'appel piéton)
- Des résistances de **220 Ω**

### Chronogramme

![[_assets/SEQ03-timing-feux.png]]

### Description détaillée

**État normal (sans appui bouton) :**
- Feu voiture : **VERT** allumé en continu
- Feu piéton : **ROUGE** allumé en continu

**Séquence déclenchée à l'appui du bouton :**

| Étape | Feu voiture | Feu piéton | Durée |
|-------|------------|------------|-------|
| 1 | 🟠 ORANGE | 🔴 Rouge | 5 secondes |
| 2 | 🔴 ROUGE | 🟢 VERT | 15 secondes |
| 3 | 🔴 ROUGE | 🔴 Rouge **clignotant** | 5 secondes |
| 4 | 🟢 VERT | 🔴 Rouge | Retour état normal |

> Le clignotement = alternance rouge allumé / éteint toutes les 500 ms.

---

## Partie 1 — Analyse du système *(SÉA01)*

### Question 1

Complète le tableau des composants nécessaires :

| Composant | Quantité | Broche Arduino | Rôle |
|-----------|----------|----------------|------|
| LED verte voiture | 1 | D10 | Feu vert voiture |
| LED orange voiture | 1 | D9 | |
| LED rouge voiture | 1 | D8 | |
| LED verte piéton | 1 | D12 | |
| LED rouge piéton | 1 | D11 | |
| Bouton poussoir | 1 | D2 | |
| Résistances 220 Ω | ___ | — | Protection LEDs |

### Question 2

Sur le chronogramme, identifie et nomme les 4 étapes de la séquence bouton :

1. _____________________________________ (durée : ___ s)
2. _____________________________________ (durée : ___ s)
3. _____________________________________ (durée : ___ s)
4. _____________________________________

### Question 3

Quelle instruction Arduino permet de lire l'état d'un bouton connecté à la broche D2 ?

```cpp
int etat = _________________(2);
```

Quelle valeur renvoie-t-elle quand le bouton est **appuyé** (avec `INPUT_PULLUP`) ?  
→ ☐ HIGH (1)  ☐ LOW (0)

> 💡 Si tu ne sais pas, consulte le cours [[Résistances de pull-up et pull-down]].

---

## Partie 2 — Simulation TinkerCAD *(SÉA02)*

### Question 4 — Câblage

Réalise le circuit dans TinkerCAD en suivant le schéma de référence :

![[_assets/SEQ03-cablage-breadboard.png]]

☐ 5 LEDs câblées avec résistances  
☐ Bouton poussoir câblé sur D2  
☐ Toutes les cathodes reliées au GND  

### Question 5 — Programme

Complète le programme ci-dessous :

```cpp
// Feux de circulation TechSignal — voitures + piétons
// Auteurs : ___________________________ / ___________________________

// === Définition des broches ===
const int VOITURE_VERT   = 10;
const int VOITURE_ORANGE = 9;
const int VOITURE_ROUGE  = 8;
const int PIETON_VERT    = 12;
const int PIETON_ROUGE   = 11;
const int BOUTON         = 2;

void setup() {
  // Broches LEDs en sortie
  pinMode(VOITURE_VERT,   OUTPUT);
  pinMode(VOITURE_ORANGE, OUTPUT);
  pinMode(VOITURE_ROUGE,  OUTPUT);
  pinMode(PIETON_VERT,    OUTPUT);
  pinMode(PIETON_ROUGE,   OUTPUT);
  // Bouton en entrée avec résistance pull-up interne
  pinMode(BOUTON, ___________);
}

// Fonction : allumer uniquement les LEDs passées en paramètre
void etat(bool vV, bool oV, bool rV, bool vP, bool rP) {
  digitalWrite(VOITURE_VERT,   vV);
  digitalWrite(VOITURE_ORANGE, oV);
  digitalWrite(VOITURE_ROUGE,  rV);
  digitalWrite(PIETON_VERT,    vP);
  digitalWrite(PIETON_ROUGE,   rP);
}

void loop() {
  // --- État normal : voiture vert, piéton rouge ---
  etat(HIGH, LOW, LOW, LOW, HIGH);

  // Attendre l'appui du bouton (LOW = appuyé avec INPUT_PULLUP)
  while (digitalRead(BOUTON) == ___________) {
    // Rien — on attend
  }

  // --- Étape 1 : voiture orange, 5 secondes ---
  etat(LOW, ___, LOW, LOW, HIGH);
  delay(___________);

  // --- Étape 2 : voiture rouge, piéton vert, 15 secondes ---
  etat(LOW, LOW, ___, ___, LOW);
  delay(___________);

  // --- Étape 3 : piéton rouge clignotant, 5 secondes ---
  // Voiture rouge reste allumée
  digitalWrite(VOITURE_ROUGE, HIGH);
  digitalWrite(PIETON_VERT, LOW);
  for (int i = 0; i < 5; i++) {          // 5 cycles = ~5 secondes
    digitalWrite(PIETON_ROUGE, ___);     // Allumer
    delay(500);
    digitalWrite(PIETON_ROUGE, ___);     // Éteindre
    delay(500);
  }

  // Retour à l'état normal (géré par le début du loop)
}
```

### Question 6

Lance la simulation. Teste en appuyant sur le bouton. Complète le tableau :

| Test | Attendu | Obtenu | Conforme ? |
|------|---------|--------|------------|
| Sans appui : LED verte voiture allumée | Oui | | ☐ |
| Appui : LED orange voiture (5s) | Oui | | ☐ |
| Piéton vert pendant 15s | Oui | | ☐ |
| Piéton rouge clignotant (5s) | Oui | | ☐ |
| Retour à l'état initial | Oui | | ☐ |

---

## Partie 3 — Réalisation sur matériel réel *(SÉA03)*

### Question 7 — Câblage sur breadboard

Récupère le matériel auprès du professeur et réalise le câblage en suivant le schéma.

Avant d'insérer les LEDs, identifie la polarité de chaque LED :

| LED | Anode (+) = patte... | Cathode (−) = patte... |
|-----|---------------------|----------------------|
| Toutes | _______________ | _______________ |

☐ Toutes les LEDs insérées dans le bon sens  
☐ Bouton poussoir positionné sur la rainure centrale de la breadboard  
☐ Toutes les cathodes reliées au rail GND  

### Question 8 — Téléversement

1. Ouvrir Arduino IDE
2. Connecter la carte Arduino en USB
3. Menu **Outils** → sélectionner la bonne carte et le bon port
4. Compiler (`Ctrl+R`) — résultat : ☐ OK  ☐ Erreur : _______________
5. Téléverser (`Ctrl+U`) — résultat : ☐ OK  ☐ Erreur : _______________

### Question 9 — Tests finaux

| Test | Résultat |
|------|----------|
| Appui bouton : séquence complète déclenchée | ☐ Oui  ☐ Non |
| Durées respectées | ☐ Oui  ☐ Non |
| Clignotement piéton visible | ☐ Oui  ☐ Non |
| Code commenté (`setup` et `loop` identifiés) | ☐ Oui  ☐ Non |

---

## ✅ Validation professeur

Appelle le professeur pour la démonstration finale.

**Signature :** ___________________________
