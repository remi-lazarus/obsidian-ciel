---
type: support-élève
titre: TD1 — Réaliser un feu de circulation
code: 2de-SEQ01-SÉA04
séquence: "[[2de-SEQ01 - Découverte Arduino ESP32]]"
séance: "[[2de-SEQ01 - SÉA04 - TD1 feu de circulation]]"
classe: Seconde TNE
outil: TinkerCAD (simulation)
durée: 2h
---

# TD1 — Réaliser un feu de circulation

**Nom / Prénom :** _____________________________ **Classe :** ___________  **Date :** ___________

---

## Contexte

Tu es stagiaire chez **TechSignal**, une entreprise spécialisée dans les systèmes de contrôle de la circulation.

Ton responsable te demande de concevoir et programmer un **feu de signalisation** en utilisant une carte Arduino, des LEDs et des résistances. La première étape est une **validation en simulation** sur TinkerCAD avant toute réalisation physique.

---

## Cahier des charges

Le feu doit respecter le cycle suivant :

| Couleur | Durée | Signification |
|---------|-------|---------------|
| 🟢 Vert | **10 secondes** | Les véhicules peuvent avancer |
| 🟠 Orange | **3 secondes** | Les véhicules doivent s'arrêter |
| 🔴 Rouge | **10 secondes** | Les véhicules doivent s'immobiliser |

Le cycle se **répète indéfiniment**.

---

## Matériel (dans TinkerCAD)

- 1 carte Arduino Uno
- 3 LEDs : 1 rouge, 1 orange (jaune), 1 verte
- 3 résistances de 220 Ω
- Fils de connexion

---

## Partie 1 — Câblage du circuit

### Question 1

En t'appuyant sur le cours (SÉA02), calcule la résistance minimale à utiliser pour une LED rouge alimentée en 5V (tension de seuil : 2V, courant : 20 mA).

$$R = \frac{V_{cc} - V_f}{I_f} = \frac{\quad - \quad}{\quad} = \quad \Omega$$

---

### Question 2

Complète le tableau de câblage ci-dessous avant de réaliser le circuit dans TinkerCAD :

| LED | Couleur du fil | Broche Arduino | Via résistance | Vers |
|-----|---------------|----------------|----------------|------|
| LED verte | | D11 | 220 Ω | Anode LED |
| LED orange | | D12 | 220 Ω | Anode LED |
| LED rouge | | D13 | 220 Ω | Anode LED |
| Cathode toutes LEDs | Noir | — | — | GND |

---

### Question 3

Réalise le câblage dans TinkerCAD en respectant le tableau ci-dessus.

☐ Circuit câblé dans TinkerCAD  
☐ Valeur des résistances configurée à 220 Ω  

---

## Partie 2 — Programmation

### Question 4

Complète le programme ci-dessous en mode **Blocs** ou **Texte** dans TinkerCAD.

```cpp
void setup() {
  pinMode(11, OUTPUT);  // LED verte
  pinMode(___, OUTPUT);  // LED orange   ← à compléter
  pinMode(___, OUTPUT);  // LED rouge    ← à compléter
}

void loop() {
  // --- Feu VERT ---
  digitalWrite(11, HIGH);   // Allumer vert
  digitalWrite(12, LOW);    // Éteindre orange
  digitalWrite(13, LOW);    // Éteindre rouge
  delay(___);               // ← Durée en ms ?

  // --- Feu ORANGE ---
  digitalWrite(11, LOW);
  digitalWrite(12, ___);    // ← HIGH ou LOW ?
  digitalWrite(13, LOW);
  delay(___);               // ← Durée en ms ?

  // --- Feu ROUGE ---
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(___, HIGH);  // ← Quelle broche ?
  delay(___);               // ← Durée en ms ?
}
```

---

### Question 5

Lance la simulation. Observe et note tes réponses :

| Observation | Résultat obtenu | Attendu | Conforme ? |
|-------------|----------------|---------|------------|
| Première LED allumée au démarrage | | Verte | ☐ Oui ☐ Non |
| Durée du feu vert | | 10 s | ☐ Oui ☐ Non |
| Durée du feu orange | | 3 s | ☐ Oui ☐ Non |
| Durée du feu rouge | | 10 s | ☐ Oui ☐ Non |
| Cycle recommence | | Oui | ☐ Oui ☐ Non |

---

## Partie 3 — Vérification et validation

### Question 6

Que se passerait-il si on oubliait la ligne `digitalWrite(11, LOW)` avant d'allumer la LED orange ?

> _____________________________________________________________________
> _____________________________________________________________________

---

### Question 7

Le code est-il commenté ? Identifie dans ton code :
- La **boucle de configuration** : fonction `_______________()`
- La **boucle principale** : fonction `_______________()`

---

## ✅ Validation professeur

Appelle le professeur pour valider la simulation.

| Critère | Validé |
|---------|--------|
| Les 3 LEDs sont câblées avec résistances | ☐ |
| La séquence vert → orange → rouge est correcte | ☐ |
| Les durées sont respectées (10s / 3s / 10s) | ☐ |
| Le code est commenté | ☐ |

**Signature professeur :** ___________________________
