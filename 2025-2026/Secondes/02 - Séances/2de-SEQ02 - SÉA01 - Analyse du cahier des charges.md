---
type: séance
titre: Analyse du cahier des charges
code: 2de-SEQ02-SÉA01
séquence: "[[2de-SEQ02 - Évaluation Arduino Feux de circulation]]"
classe: Seconde TNE
date: 
durée_minutes: 60
compétences:
  - C07
  - C08
savoirs:
  - Lecture de chronogramme
  - Analyse fonctionnelle simple
  - Entrée numérique (bouton poussoir)
type_séance: Lancement évaluation
statut: fait
---

# Analyse du cahier des charges

## 🎯 Objectif de la séance

À la fin de cette séance, l'élève sera capable d'analyser le chronogramme de fonctionnement du système, d'identifier les composants nécessaires et de déduire le plan de câblage avant de commencer la simulation.

## 🔗 Contexte dans la séquence

Séance appartenant à → [[2de-SEQ02 - Évaluation Arduino Feux de circulation]]

Séance de lancement de l'évaluation — fait suite à [[2de-SEQ01 - Découverte Arduino ESP32]]. Le système est plus complexe : feu voiture + feu piéton + bouton d'appel.

## ⏱️ Déroulé pédagogique

| Phase | Activité | Durée | Mode |
|-------|----------|-------|------|
| Lancement | Distribution de l'énoncé, présentation du système | 10 min | Collectif |
| Analyse | Lecture du chronogramme, questions de compréhension | 25 min | Individuel |
| Mise en commun | Correction collective, clarification du cahier des charges | 15 min | Collectif |
| Préparation | Plan de câblage et répartition des tâches en binôme | 10 min | Binôme |

## 📋 Contenu

### Mise en situation

Présentation du système complet : le feu voiture seul ne suffit plus. TechSignal demande d'ajouter un **feu piéton avec bouton d'appel**. L'élève doit d'abord comprendre le fonctionnement avant de coder.

### Activité élève

Analyser le chronogramme de fonctionnement ([[_assets/SEQ03-timing-feux.png]]) et répondre aux questions de la partie 1 de l'énoncé :
- Identifier les états de chaque feu
- Relever les durées de chaque phase
- Identifier le rôle du bouton poussoir
- Lister tous les composants nécessaires

### Éléments de correction / Points de vigilance

- Bien faire distinguer état **normal** (voiture vert, piéton rouge) et état **demande de passage**
- Insister sur la gestion du bouton : lecture d'une **entrée numérique** (`digitalRead`)
- Expliquer pourquoi une résistance est indispensable → voir [[Résistances de pull-up et pull-down]]
- Rappeler `INPUT_PULLUP` : le bouton lit LOW quand appuyé (logique inversée !)
- Attirer l'attention sur le **clignotement** : nécessite une alternance rapide dans le code

## 📦 Ressources

- [ ] Énoncé : [[2de-SEQ02 - Énoncé évaluation]]
- [ ] Chronogramme : [[_assets/SEQ03-timing-feux.png]]

## ✅ Critères de réussite

- [ ] L'élève identifie les 5 états du système (normal, orange, transition, piéton vert, clignotement)
- [ ] L'élève liste les 5 LEDs et le bouton nécessaires
- [ ] L'élève comprend le rôle de `digitalRead()`

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
