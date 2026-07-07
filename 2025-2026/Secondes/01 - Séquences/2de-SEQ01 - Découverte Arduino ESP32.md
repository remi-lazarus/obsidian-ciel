---
type: séquence
titre: Découverte du nœud de carrefour — Arduino / ESP32
code: 2de-SEQ01
classe: Seconde TNE
trimestre: T1
période:
durée_heures: 8
activite_pro: CC1
compétences:
  - CC1
  - CC4
statut: fait
fil_rouge: SmartUrb
---

# Découverte du nœud de carrefour — Arduino / ESP32

## 🏭 Activité professionnelle de référence

> **Point d'entrée du référentiel :** [[00 - Référentiel/Compétences TNE — Seconde#CC1 — S'informer sur l'intervention ou la réalisation|CC1 — S'informer sur l'intervention ou la réalisation]]
>
> **Tâche mobilisée :** Collecter et ordonner les données nécessaires à la prise en main du nœud de carrefour SmartUrb — lire le cahier des charges, identifier les composants du système, repérer les contraintes énergétiques (passage aux LEDs).
>
> **Résultat attendu :** L'élève est capable de décrire l'architecture du carrefour, d'identifier ses composants, et de réaliser un premier montage fonctionnel en simulation puis sur matériel réel.

## 🎯 Objectifs de la séquence

À l'issue de cette séquence, l'élève sera capable de lire le cahier des charges du carrefour SmartUrb, d'identifier ses composants électroniques, et de câbler et programmer un premier feu tricolore sur Arduino en simulation puis sur matériel physique.

## 📚 Prérequis

- Séquence(s) précédente(s) : aucune — première séquence de l'année
- Notions techniques attendues :
  - Notions de base en électricité (tension, courant, résistance) — niveau collège
- Compétences déjà travaillées :
  - Aucune — séquence de découverte

## 🏢 Mise en situation professionnelle

Bienvenue chez **SmartUrb** ! La Métropole de Metz vient de confier à l'entreprise le déploiement d'une nouvelle génération de carrefours intelligents sur l'axe République–Saulcy.

En tant que technicien(ne) en contrat de professionnalisation, ta première mission est de **prendre en main le nœud de carrefour** : comprendre son architecture, identifier les composants, et réaliser un premier prototype de feu tricolore. SmartUrb remplace les anciens feux à lampes à incandescence par des LEDs pilotées — un choix qui réduit la consommation de 70 %. C'est cette technologie que tu vas maîtriser cette semaine.

## 📋 Compétences ciblées

> Référentiel TNE — Seconde · Voir [[00 - Référentiel/Compétences TNE — Seconde]]

| Code | Intitulé | Rôle | Correspondance CIEL |
|------|----------|------|---------------------|
| **CC1** | S'informer sur l'intervention ou la réalisation | Principale | C04 (Analyser) |
| CC4 | Réaliser une installation ou une intervention | Secondaire | C07 · C09 |

## 🗓️ Découpage en séances

| N° | Titre | Durée | CC | Statut |
|----|-------|-------|----|--------|
| [[2de-SEQ01 - SÉA01 - Validation des prérequis\|SÉA01]] | Validation des prérequis | 1h | CC1 | ✅ |
| [[2de-SEQ01 - SÉA02 - Découvrir la carte Arduino\|SÉA02]] | Découvrir la carte de développement Arduino | 1h | CC1 · CC4 | ✅ |
| [[2de-SEQ01 - SÉA03 - Découvrir TinkerCAD\|SÉA03]] | Découvrir l'outil de simulation TinkerCAD | 2h | CC1 · CC4 | ✅ |
| [[2de-SEQ01 - SÉA04 - TD1 feu de circulation\|SÉA04]] | TD1 : réaliser un feu de circulation | 2h | CC4 | ✅ |
| [[2de-SEQ01 - SÉA05 - TP2 matériel physique\|SÉA05]] | TP2 : Réalisation sur du matériel physique | 2h | CC4 | ✅ |

## 📦 Ressources nécessaires

- Matériel : carte Arduino Uno, LEDs (rouge, orange, verte), résistances, breadboard, câbles
- Logiciels : TinkerCAD (simulation), Arduino IDE (téléversement)
- Documents : [[Projets/SmartUrb/Contexte projet — SmartUrb]] · fiches séances SÉA01 à SÉA05

## ✅ Critères de réussite de la séquence

- [ ] **(CC1)** L'élève identifie les composants du carrefour et explique le rôle des LEDs vs lampes incandescentes
- [ ] **(CC4)** Le circuit est câblé correctement (LEDs + résistances)
- [ ] **(CC4)** Le code Arduino fait défiler rouge / orange / vert aux bonnes durées
- [ ] **(CC4)** La simulation TinkerCAD est validée avant le montage physique
- [ ] **(CC4)** Le programme est téléversé et fonctionne sur le matériel physique

## 📝 Notes / Ajustements

> Séquence réalisée avant la mise en place du cadre TNE/SmartUrb — recadrée rétrospectivement en 2026-04-07.
> Le contenu technique reste inchangé. La mise en situation a été adaptée au fil rouge SmartUrb.
