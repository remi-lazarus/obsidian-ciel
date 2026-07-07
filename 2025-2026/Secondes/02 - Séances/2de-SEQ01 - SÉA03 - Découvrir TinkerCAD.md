---
type: séance
titre: Découvrir l'outil de simulation TinkerCAD
code: 2de-SEQ01-SÉA03
séquence: "[[2de-SEQ01 - Découverte Arduino ESP32]]"
classe: Seconde TNE
date: 
durée_minutes: 120
compétences:
  - C04
  - C08
savoirs:
  - Outils de modélisation / simulation
  - Langages de développement (Scratch / blocs)
  - Schéma électronique simple
type_séance: TD
statut: fait
---

# Découvrir l'outil de simulation TinkerCAD

## 🎯 Objectif de la séance

À la fin de cette séance, l'élève sera capable de réaliser un schéma de circuit LED + résistance dans TinkerCAD et de faire clignoter une LED à l'aide de l'interface de programmation par blocs (Scratch).

## 🔗 Contexte dans la séquence

Séance appartenant à → [[2de-SEQ01 - Découverte Arduino ESP32]]

Prise en main du simulateur avant le TD feu de circulation (SÉA04) — permet d'expérimenter sans risquer le matériel.

## ⏱️ Déroulé pédagogique

| Phase | Activité | Durée | Mode |
|-------|----------|-------|------|
| Lancement | Présentation de l'interface TinkerCAD | 15 min | Collectif |
| Découverte guidée | Placer composants, câbler, lancer la simulation | 30 min | Individuel |
| Activité principale | Faire clignoter la LED en Scratch | 55 min | Individuel |
| Validation | Appel professeur pour validation | 10 min | Individuel |
| Bilan | Retour sur les difficultés rencontrées | 10 min | Collectif |

## 📋 Contenu

### Mise en situation

Avant de toucher au matériel physique, TechSignal impose de valider le câblage en simulation. Découverte de TinkerCAD comme outil professionnel de prototypage virtuel.

### Activité élève

1. Créer un compte sur https://www.tinkercad.com/ (ou utiliser le compte établissement)
2. Créer un nouveau circuit avec :
   - Une carte Arduino Uno
   - Une LED
   - Une résistance de protection (220 Ω)
   - Câblage LED entre broche D13 et GND via la résistance
3. Ouvrir l'éditeur de code (mode **Blocs / Scratch**)
4. Programmer le clignotement de la LED (allumer 1 s, éteindre 1 s, répéter)
5. Lancer la simulation et vérifier le fonctionnement
6. **Appeler le professeur pour validation**

### Éléments de correction / Points de vigilance

- Vérifier la polarité de la LED (anode côté +, cathode côté GND)
- Si la LED ne clignote pas : vérifier la connexion GND et la broche dans le code
- Rappeler que `delay(1000)` = 1 seconde dans Arduino

## 📦 Ressources

- [ ] Cours : [[2de-SEQ01 - SÉA03 - TinkerCAD prise en main]]
- [ ] Accès à https://www.tinkercad.com/

## ✅ Critères de réussite

- [ ] Le schéma est câblé correctement dans TinkerCAD
- [ ] La simulation montre la LED qui clignote
- [ ] La validation professeur est obtenue

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
