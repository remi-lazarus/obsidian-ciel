---
type: séance
titre: Réalisation sur matériel réel
code: 2de-SEQ02-SÉA03
séquence: "[[2de-SEQ02 - Évaluation Arduino Feux de circulation]]"
classe: Seconde TNE
date: 
durée_minutes: 120
compétences:
  - C07
  - C08
savoirs:
  - Technologies de raccordement (breadboard, câbles, composants)
  - Polarité des composants (LED anode/cathode)
  - Téléversement Arduino IDE
type_séance: Évaluation (TP)
statut: fait
---

# Réalisation sur matériel réel

## 🎯 Objectif de la séance

À la fin de cette séance, l'élève aura câblé le système complet sur breadboard physique, téléversé le programme validé en simulation et démontré le fonctionnement du feu de circulation avec bouton d'appel au professeur.

## 🔗 Contexte dans la séquence

Séance appartenant à → [[2de-SEQ02 - Évaluation Arduino Feux de circulation]]

Séance finale d'évaluation — la simulation TinkerCAD (SÉA02) doit être validée avant de commencer.

## ⏱️ Déroulé pédagogique

| Phase | Activité | Durée | Mode |
|-------|----------|-------|------|
| Distribution | Récupération du matériel, vérification de la liste | 10 min | Binôme |
| Câblage | Montage sur breadboard | 50 min | Binôme |
| Téléversement | Connexion USB, compilation, téléversement Arduino IDE | 20 min | Binôme |
| Tests | Vérification du fonctionnement complet | 25 min | Binôme |
| Validation | Appel professeur pour démonstration et évaluation | 15 min | Binôme |

## 📋 Contenu

### Mise en situation

La simulation est validée. Il est temps de réaliser le vrai prototype que TechSignal pourra présenter à son client.

### Activité élève

Récupérer le matériel auprès du professeur, réaliser le câblage sur breadboard en s'appuyant sur le schéma [[_assets/SEQ03-cablage-breadboard.png]], téléverser le programme et démontrer le fonctionnement.

### Éléments de correction / Points de vigilance

- Vérifier la polarité de chaque LED avant d'insérer dans la breadboard
- Le bouton poussoir : s'assurer qu'il chevauche bien le canal central de la breadboard
- En cas de LED qui ne s'allume pas : tester en mode multimètre (continuité)
- En cas d'erreur de téléversement : vérifier le port COM sélectionné

## 📦 Ressources

- [ ] Énoncé + grille : [[2de-SEQ02 - Énoncé évaluation]]
- [ ] Schéma câblage : [[_assets/SEQ03-cablage-breadboard.png]]
- [ ] Grille d'évaluation : [[2de-SEQ02 - Grille d'évaluation]]
- [ ] Matériel : Arduino Uno, 3 LEDs voiture (R/O/V), 2 LEDs piéton (R/V), 5 résistances 220 Ω, 1 bouton poussoir, breadboard, câbles, USB

## ✅ Critères de réussite

- [ ] Schéma de câblage respecté pour le prototype
- [ ] Composants identiques au schéma (nomenclature)
- [ ] LEDs positionnées en identifiant correctement l'anode et la cathode
- [ ] Les deux feux câblés dans le temps imparti
- [ ] Démonstration validée par le professeur

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
