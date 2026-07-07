---
type: séance
titre: Brasage — notions et sécurité
code: 2de-SEQ03-SÉA01
séquence: "[[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]"
classe: Seconde TNE
date: 
durée_minutes: 60
compétences:
  - C01
  - C04
savoirs:
  - Techniques de brasage à l'étain (brasage tendre)
  - Sécurité liée au brasage (risques thermiques, fumées, EPI)
type_séance: Cours / Découverte
statut: brouillon
---

# Brasage — notions et sécurité

## 🎯 Objectif de la séance

À la fin de cette séance, l'élève sera capable de citer les risques liés au brasage à l'étain, d'identifier les EPI obligatoires et de décrire les gestes de base à respecter avant toute manipulation du fer à braser.

## 🔗 Contexte dans la séquence

Séance appartenant à → [[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]

Première séance du bloc **lancement (2h)**, à enchaîner avec [[2de-SEQ03 - SÉA02 - Lecture de schéma implantation]]. Les élèves viennent de réaliser leur feu de circulation sur breadboard (SEQ02) — SmartUrb demande maintenant un **prototype brasé**, plus robuste. C'est la transition breadboard → plaque à braser qui donne le sens à cette séance.

## ⏱️ Déroulé pédagogique

| Phase                      | Activité                                                                                                                                                            | Durée  | Mode          |
| -------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------ | ------------- |
| Lancement                  | Accroche visuelle : confronter une brasure correcte, une brasure froide et une brasure en pont — poser la question « Qu'est-ce qui différencie ces trois joints ? » | 10 min | Collectif     |
| Apport notionnel           | Présentation du principe du brasage tendre (étain, flux, panne), rôle de la chaleur, différence brasage tendre / brasure forte                                      | 10 min | Collectif     |
| Démonstration enseignant   | Manipuler le fer sous les yeux des élèves : chauffer la panne, étamer, braser un composant sur plaquette d'essai, nettoyer la panne                                 | 10 min | Démonstration |
| Manipulation guidée        | Élèves manipulent l'outillage **fer éteint et débranché** : poser le fer sur le support, position de la main, tenir l'étain, régler le poste (simulation)           | 10 min | Binôme        |
| Quiz oral — risques et EPI | Questions rapides : « Citez un risque thermique », « Quel EPI pour les yeux ? », « Que faire si l'étain éclabousse ? »                                              | 10 min | Collectif     |
| Bilan                      | Distribution et collage de la [[2de-SEQ03 - Fiche mémo brasage]] dans le cahier — lecture commentée                                                                 | 10 min | Individuel    |

## 📋 Contenu

### Mise en situation

SmartUrb valide le prototype breadboard — mais un breadboard reste fragile : une connexion mal enfichée suffit à tout bloquer. La prochaine étape industrielle est de **braser les composants** sur une plaque à pastilles pour livrer un prototype fiable.

Avant de toucher un fer à braser, les élèves doivent connaître les **risques réels** et les **règles non négociables** de l'atelier. Cette séance est le passage obligé.

### Activité élève

**Étape 1 — Observation de l'accroche (fer allumé devant la classe)**

L'enseignant montre trois brasures sur composants :
- Une brasure **correcte** (brillante, conique, propre)
- Une brasure **froide** (terne, granuleuse — risque de coupure de circuit)
- Une brasure **en pont** (court-circuit entre deux pistes)

Questions posées à l'oral : _Laquelle est correcte ? Pourquoi la froide est-elle dangereuse ? Qu'est-ce qui cause le pont ?_

**Étape 2 — Identification des EPI (fiche à compléter)**

Chaque élève complète une fiche simple :
- Entourer les EPI obligatoires parmi une liste illustrée (lunettes de protection, gants thermiques, blouse, masque à cartouche ou ventilation)
- Relier chaque EPI au risque qu'il couvre (projection d'étain fondu, fumées de flux, chaleur)

**Étape 3 — Manipulation à froid**

En binôme, chaque élève prend en main l'outillage **hors tension** :
- Poser et retirer le fer de son support sans le poser sur la table
- Tenir le fil d'étain côté libre (jamais par l'extrémité active)
- Identifier les réglages du poste de brasage (température cible : 350 °C)
- Localiser l'éponge humide et décrire son rôle (nettoyer la panne oxydée)

### Éléments de correction / Points de vigilance

- **Température** : régler à **350 °C** pour l'étain sans plomb (Sn96.5/Ag3/Cu0.5) — en dessous la brasure est froide, au-dessus l'étain brûle et le flux se dégrade
- **Fumées de flux** : l'étain utilisé en atelier est **sans plomb** mais le flux reste **irritant pour les voies respiratoires** — ventilation ou bras extracteur obligatoire, ne pas se pencher au-dessus de la brasure
- **Support fer** : le fer ne se pose **jamais** directement sur la table ni sur le plan de travail — toujours dans le support dédié, même 2 secondes
- **Nettoyage de la panne** : essuyer sur l'éponge **humide** (pas sèche) ou sur le bloc de laiton — une panne oxydée noire ne transfère plus la chaleur
- **Quantité d'étain** : une toute petite quantité suffit — l'erreur classique des débutants est d'en mettre trop, ce qui crée des ponts
- **Couper l'alimentation** : ne jamais braser un composant sur un circuit **sous tension** — risque de court-circuit et de destruction du composant

## 📦 Ressources

- [ ] [[2de-SEQ03 - Fiche mémo brasage]]
- [ ] [[2de-SEQ03 - Fiche sécurité atelier brasage]]
- [ ] Matériel de démonstration :
  - Fer à braser réglable + support
  - Fil d'étain sans plomb (Sn96.5)
  - Éponge humide ou bloc de laiton
  - Lunettes de protection × 1 classe
  - Composants d'exemple montés sur plaquette (LED, résistance)
  - Exemples de brasures correcte / froide / en pont (plaquette préparée à l'avance)

## ✅ Critères de réussite

- [ ] L'élève cite au moins **3 risques** liés au brasage (brûlure, projection, fumées de flux, incendie par contact)
- [ ] L'élève identifie et nomme les **EPI obligatoires** (lunettes, ventilation/extraction, blouse)
- [ ] L'élève décrit les **bons gestes de base** : poser le fer sur son support, nettoyer la panne à l'éponge humide, doser l'étain en petite quantité
- [ ] L'élève sait régler la température cible du poste à **350 °C**

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
