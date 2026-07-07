---
type: séquence
titre: Validation du carrefour — feux voiture et piéton
code: 2de-SEQ02
classe: Seconde TNE
trimestre: T1
période:
durée_heures: 5
activite_pro: CC6
compétences:
  - CC6
  - CC5
statut: fait
fil_rouge: SmartUrb
---

# Validation du carrefour — feux voiture et piéton

## 🏭 Activité professionnelle de référence

> **Point d'entrée du référentiel :** [[00 - Référentiel/Compétences TNE — Seconde#CC6 — Mettre en service|CC6 — Mettre en service]]
>
> **Tâche mobilisée :** Valider que le comportement du carrefour SmartUrb est conforme aux spécifications de la Métropole de Metz — simulation puis montage réel, mesures et vérification de la séquence temporelle.
>
> **Résultat attendu :** Un carrefour complet (feu voiture tricolore + feu piéton bicolore + bouton d'appel) fonctionnel, validé contre le cahier des charges avant passage au prototype physique.

## 🎯 Objectifs de la séquence

À l'issue de cette séquence, l'élève sera capable de câbler et programmer le carrefour complet SmartUrb (feu voiture + feu piéton + bouton d'appel), de vérifier sa conformité au cahier des charges et de justifier la validation ou non-conformité du système.

## 📚 Prérequis

- Séquence(s) précédente(s) : [[2de-SEQ01 - Découverte du nœud de carrefour — Arduino / ESP32]]
- Notions techniques attendues :
  - Câblage LED + résistance sur breadboard
  - Structure d'un programme Arduino (`setup()`, `loop()`, `delay()`)
  - Lecture d'un schéma de câblage simple
- Compétences déjà travaillées :
  - CC1 (S'informer — lecture du cahier des charges)
  - CC4 (Réaliser — montage et programmation Arduino)

## 🏢 Mise en situation professionnelle

La direction technique de **SmartUrb** a validé ton premier prototype de feu tricolore. La prochaine étape du déploiement sur l'axe République–Saulcy nécessite un carrefour **complet** : feu voiture + feu piéton avec bouton d'appel.

La Métropole de Metz impose un cahier des charges strict sur les temporisations — un carrefour non conforme crée des risques pour les piétons et peut engager la responsabilité de SmartUrb. Ta mission : développer et **valider** le système complet contre les spécifications avant de soumettre le prototype à la validation client.

> **Enjeu TNE :** chaque carrefour connecté de la Métropole remontera automatiquement un rapport de conformité au serveur de supervision. Ce que tu valides aujourd'hui sera la référence pour les tests automatisés de demain.

## 📋 Compétences ciblées

> Référentiel TNE — Seconde · Voir [[00 - Référentiel/Compétences TNE — Seconde]]

| Code | Intitulé | Rôle | Correspondance CIEL |
|------|----------|------|---------------------|
| **CC6** | Mettre en service | Principale | C06 (Valider) |
| CC5 | Effectuer les opérations préalables | Secondaire | C06 · C10 |

## 🗓️ Découpage en séances

| N° | Titre | Durée | CC | Statut |
|----|-------|-------|----|--------|
| [[2de-SEQ02 - SÉA01 - Analyse du cahier des charges\|SÉA01]] | Analyse du cahier des charges | 1h | CC5 | ✅ |
| [[2de-SEQ02 - SÉA02 - Simulation TinkerCAD\|SÉA02]] | Simulation sur TinkerCAD | 2h | CC5 · CC6 | ✅ |
| [[2de-SEQ02 - SÉA03 - Réalisation sur matériel réel\|SÉA03]] | Réalisation et validation sur matériel réel | 2h | CC6 | ✅ |

## 📦 Ressources nécessaires

- Matériel : carte Arduino Uno, 3 LEDs voiture (R/O/V), 2 LEDs piéton (R/V), 5 résistances 220 Ω, 1 bouton poussoir, breadboard, câbles, USB
- Logiciels : TinkerCAD (simulation), Arduino IDE (téléversement)
- Documents :
  - Énoncé : [[2de-SEQ02 - Énoncé évaluation]]
  - Grille : [[2de-SEQ02 - Grille d'évaluation]]
  - Référence projet : [[Projets/SmartUrb/Contexte projet — SmartUrb]]

## ✅ Critères de réussite de la séquence

- [ ] **(CC5)** Le cahier des charges est analysé et les spécifications temporelles sont identifiées
- [ ] **(CC5)** La simulation TinkerCAD est validée avant le montage physique
- [ ] **(CC6)** Le schéma de câblage est respecté (5 LEDs + bouton + résistances)
- [ ] **(CC6)** La séquence temporelle est conforme au cahier des charges SmartUrb
- [ ] **(CC6)** Le montage est réalisé et la conformité est déclarée (conforme / non conforme + justification)

## 🚀 Pour aller plus loin

- [[2de-SEQ02 - Pour aller plus loin - Servo moteur]]
- [[2de-SEQ02 - Pour aller plus loin - Capteur de lumière]]

## 📝 Notes / Ajustements

> Séquence réalisée avant la mise en place du cadre TNE/SmartUrb — recadrée rétrospectivement en 2026-04-07.
> Le contenu technique reste inchangé. La mise en situation a été adaptée au fil rouge SmartUrb.
