---
type: séance
titre: Lancement — réactivation SEQ02 et mise en situation
code: 2de-SEQ03-SÉA00
séquence: "[[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]"
classe: Seconde TNE
date: 
durée_minutes: 15
compétences:
  - CC2
type_séance: Lancement / Réactivation
statut: brouillon
---

# Lancement — réactivation SEQ02 et mise en situation

## 🎯 Objectif de la séance

En 15 minutes, remettre les élèves dans le contexte SmartUrb, vérifier que les acquis de SEQ02 sont actifs, et créer le besoin qui justifie le passage breadboard → perfboard.

## 🔗 Contexte dans la séquence

Séance appartenant à → [[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]

Séance zéro — à faire en collectif avant de séparer les groupes pour [[2de-SEQ03 - SÉA01 - Soudage — notions et sécurité]] et [[2de-SEQ03 - SÉA02 - Lecture de schéma électronique]].

## ⏱️ Déroulé pédagogique

| Phase | Activité | Durée | Mode |
|-------|----------|-------|------|
| Réactivation SEQ02 | Quiz oral rapide : 5 questions sur le carrefour breadboard — voir ci-dessous | 7 min | Collectif |
| Rupture / Besoin | L'enseignant provoque délibérément une fausse connexion sur un montage breadboard (fil mal inséré) qui fait tomber en panne le carrefour. Question : « Est-ce qu'on peut livrer ça à la Métropole de Metz ? » → formuler ensemble le problème et la solution | 5 min | Collectif |
| Présentation de la séquence | Annoncer la mission (prototype brasé sur perfboard), montrer l'objet fini (ou une photo), présenter les 5 séances à venir en 3 phrases | 3 min | Collectif |

### Quiz oral — 5 questions de réactivation SEQ02

Les questions sont posées à la volée, sans support écrit. L'enseignant note les réponses au tableau pour garder une trace.

| # | Question | Réponse attendue |
|---|----------|-----------------|
| 1 | Quelle est la valeur des résistances utilisées devant chaque LED ? | 220 Ω |
| 2 | Comment reconnaître l'anode d'une LED ? | Patte longue / absence de méplat |
| 3 | Pourquoi y a-t-il une résistance de 10 kΩ reliée au GND sur le bouton ? | Pull-down — pour éviter que l'entrée Arduino soit flottante quand le bouton est relâché |
| 4 | Quelle broche Arduino allume la LED verte voiture ? | D4 (selon le schéma SEQ02 — accepter toute valeur cohérente avec leur montage) |
| 5 | Qu'est-ce qui se passe si une LED est branchée à l'envers sur la breadboard ? | Elle ne s'allume pas |

> Adapter la question 4 au brochage réel utilisé en SEQ02.

### La rupture — pourquoi pas la breadboard ?

L'enseignant débranche discrètement un fil du montage breadboard sous les yeux des élèves.

> « Le carrefour vient de tomber en panne. Qu'est-ce qui s'est passé ? »

Après explication : « SmartUrb doit livrer ce prototype à la réunion de la Métropole vendredi. On lui livre la breadboard ? »

Réponse attendue : non — une connexion mal enfichée suffit à tout bloquer. Il faut un montage **physiquement solidaire**, résistant aux vibrations et au transport. C'est le rôle du brasage.

## 📦 Ressources

- Montage breadboard SEQ02 opérationnel (emprunté à un élève ou préparé par l'enseignant)
- Optionnel : photo ou objet d'un perfboard brasé terminé à montrer comme objectif

## ✅ Critères de réussite

- [ ] **(CC2)** L'élève restitue les composants utilisés en SEQ02 et leur rôle (LED, résistance, pull-down, bouton)
- [ ] **(CC2)** L'élève formule le problème de la breadboard (fragilité, connexions non solidaires)
- [ ] **(CC2)** L'élève identifie l'objectif de la séquence : réaliser un prototype brasé, livrable

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
