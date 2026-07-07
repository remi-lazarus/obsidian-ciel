---
type: séance
titre: Simulation sur TinkerCAD
code: 2de-SEQ02-SÉA02
séquence: "[[2de-SEQ02 - Évaluation Arduino Feux de circulation]]"
classe: Seconde TNE
date: 
durée_minutes: 120
compétences:
  - C08
savoirs:
  - Principes fondamentaux de programmation (alternatives, boucles)
  - Lecture d'une entrée numérique (bouton poussoir)
  - Gestion du temps avec delay()
type_séance: Évaluation (simulation)
statut: fait
---

# Simulation sur TinkerCAD

## 🎯 Objectif de la séance

À la fin de cette séance, l'élève aura câblé le circuit complet (5 LEDs + bouton) dans TinkerCAD et programmé le comportement du système selon le chronogramme, avec validation du programme en simulation.

## 🔗 Contexte dans la séquence

Séance appartenant à → [[2de-SEQ02 - Évaluation Arduino Feux de circulation]]

Séance d'évaluation — l'élève travaille en autonomie. Le programme validé ici sera téléversé sur matériel physique en SÉA03.

## ⏱️ Déroulé pédagogique

| Phase | Activité | Durée | Mode |
|-------|----------|-------|------|
| Rappel | Vérification de la compréhension du cahier des charges | 5 min | Collectif |
| Câblage | Réalisation du circuit dans TinkerCAD | 30 min | Binôme |
| Programmation | Écriture et test du code | 70 min | Binôme |
| Dépôt | Export et dépôt du programme sur Moodle | 10 min | Binôme |
| Validation | Appel professeur pour vérification | 5 min | Binôme |

## 📋 Contenu

### Mise en situation

Le circuit est à réaliser en simulation complète avant toute manipulation physique. Le programme sera ensuite exporté depuis TinkerCAD et déposé sur Moodle (activité "Programme de l'exercice").

### Activité élève

Réaliser le circuit et le programme conformément à l'énoncé [[2de-SEQ02 - Énoncé évaluation]].

Schéma de câblage de référence : [[_assets/SEQ03-cablage-breadboard.png]]

### Éléments de correction / Points de vigilance

- `digitalRead(PIN_BOUTON) == LOW` quand le bouton est appuyé (résistance pull-up interne) → voir [[Résistances de pull-up et pull-down]]
- Le clignotement piéton = boucle `for` avec `digitalWrite` + `delay(500)` répété 5×
- Bien éteindre toutes les LEDs non concernées à chaque changement d'état
- Exporter le code depuis TinkerCAD : bouton "Télécharger le code"

## 📦 Ressources

- [ ] Énoncé : [[2de-SEQ02 - Énoncé évaluation]]
- [ ] Schéma câblage : [[_assets/SEQ03-cablage-breadboard.png]]
- [ ] TinkerCAD : https://www.tinkercad.com/

## ✅ Critères de réussite

- [ ] Les 5 LEDs et le bouton sont câblés correctement
- [ ] En l'absence d'appui : feu voiture vert allumé en continu
- [ ] À l'appui du bouton : séquence orange (5s) → transition (1s) → piéton vert (15s) → clignotement (5s) → retour
- [ ] Le code est commenté
- [ ] Le programme est déposé sur Moodle

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
