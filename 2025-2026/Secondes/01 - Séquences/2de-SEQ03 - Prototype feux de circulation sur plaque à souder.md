---
type: séquence
titre: Prototype feux de circulation sur plaque à souder
code: 2de-SEQ03
classe: Seconde TNE
trimestre: T2
période:
durée_heures: 8
activite_pro: CC4
compétences:
  - CC4
  - CC2
statut: en cours
fil_rouge: SmartUrb
---

# Prototype feux de circulation sur plaque à souder

## 🏭 Activité professionnelle de référence

> **Point d'entrée du référentiel :** [[00 - Référentiel/Compétences TNE — Seconde#CC4 — Réaliser une installation ou une intervention|CC4 — Réaliser une installation ou une intervention]]
>
> **Tâche mobilisée :** Réaliser le prototype physique du nœud de carrefour SmartUrb sur perfboard — brasage des composants traversants, brasure des fils de connexion, implantation conforme au schéma fourni.
>
> **Résultat attendu :** Un prototype physique fonctionnel, brasé, contrôlé et conforme au schéma, prêt pour la phase de déploiement terrain.

## 🎯 Objectifs de la séquence

À l'issue de cette séquence, l'élève sera capable de réaliser un prototype physique du feu de circulation sur perfboard — en appliquant les gestes de brasage conformes aux normes IPC, à partir d'un schéma électronique fourni — et de valider son fonctionnement avec la carte Arduino programmée en SEQ02.

## 📚 Prérequis

- Séquence(s) précédente(s) : [[2de-SEQ01 - Découverte Arduino ESP32]] · [[2de-SEQ02 - Évaluation Arduino Feux de circulation]]
- Notions techniques attendues :
  - Composants de base : LED, résistance, bouton poussoir (identification, polarité)
  - Câblage sur breadboard (réalisé en SEQ01/SEQ02)
  - Programme Arduino fonctionnalité 1 (feux voiture + piéton + bouton) — déjà validé en SEQ02
- Compétences déjà travaillées :
  - CC1 (S'informer — lecture du cahier des charges SmartUrb)
  - CC6 (Mettre en service — validation du carrefour complet sur breadboard)

## 🏢 Mise en situation professionnelle

Le service technique de **SmartUrb** a validé ton carrefour complet en simulation et sur breadboard (SEQ01 et SEQ02). La Métropole de Metz souhaite maintenant disposer d'un **prototype physique robuste** pour présentation lors de la réunion de validation du projet République–Saulcy.

La breadboard ne suffit plus : trop fragile pour le transport, trop peu représentative du futur équipement terrain. Tu es chargé(e) de passer à l'étape suivante : assembler le nœud de carrefour sur une **plaque à braser (perfboard)**, en respectant le schéma de câblage fourni par le bureau d'études.

> **Enjeu TNE :** le prototype brasé sera le premier élément physique livrable du projet SmartUrb. Il servira de référence pour la fabrication en série du boîtier de carrefour connecté — chaque défaut de brasure ou d'implantation devra être signalé dans le rapport de validation.

## 📋 Compétences ciblées

> Référentiel TNE — Seconde · Voir [[00 - Référentiel/Compétences TNE — Seconde]]

> ⚠️ **2 compétences ciblées.** CC4 est la compétence centrale de toute la séquence (réalisation du prototype). CC2 est travaillée en SÉA01/SÉA02 (organisation du poste, planification du montage). Les autres compétences mobilisées sont des supports, pas des cibles d'évaluation.

| Code | Intitulé | Rôle | Correspondance CIEL |
|------|----------|------|---------------------|
| **CC4** | Réaliser une installation ou une intervention | Principale | C07 (Réaliser) · C09 (Installer) |
| CC2 | Organiser son intervention | Secondaire | C03 (Participer) |

## 🗓️ Découpage en séances

| N° | Titre | Durée | CC | Statut |
|----|-------|-------|----|--------|
| [[2de-SEQ03 - SÉA00 - Lancement et réactivation SEQ02\|SÉA00]] | Lancement — réactivation SEQ02 et mise en situation | 15 min | CC2 | ⬜ |
| [[2de-SEQ03 - SÉA01 - Soudage — notions et sécurité\|SÉA01]] | Brasage — notions et sécurité | 1h | CC2 · CC4 | ⬜ |
| [[2de-SEQ03 - SÉA02 - Lecture de schéma électronique\|SÉA02]] | Lecture de schéma électronique | 1h | CC4 | ⬜ |
| [[2de-SEQ03 - SÉA03 - Implantation et première brasure des composants\|SÉA03]] | Brasage par chaîne — feu tricolore voiture *(demi-groupe, parallèle SÉA02)* | 1h | CC4 | ⬜ |
| [[2de-SEQ03 - SÉA05 - Tests et validation du prototype\|SÉA05]] | Tests et validation du prototype | 2h | CC4 | ⬜ |

> **SÉA00** (15 min) : lancement collectif — réactivation SEQ02, besoin breadboard → perfboard.
> **SÉA01** (1h) : apport notionnel — gestes de brasage, sécurité, EPI.
> **SÉA02 / SÉA03** (1h, demi-groupes en parallèle) : lecture du schéma + gabarit d'un côté, brasage par chaîne du feu voiture de l'autre — les groupes permutent.
> **SÉA05** (2h) : tests fonctionnels complets avec l'Arduino, validation du prototype livrable.

## 📦 Ressources nécessaires

- **Matériel élève :**
  - 1 plaque à braser perfboard (format adapté au montage)
  - Arduino Uno (issu de SEQ02, programme déjà chargé)
  - 5 LEDs : 3 voiture (rouge, orange, vert) + 2 piéton (rouge, vert)
  - 5 résistances 220 Ω · 1 résistance pull-down 10 kΩ · 1 bouton poussoir
  - Fils de connexion (stranded ou tinned)
  - Fer à braser + support, étain sans plomb, éponge humide
  - Lunettes de protection, pince brucelles, pince coupante, pince à dénuder
- **Documents fournis :**
  - Schéma électronique fonctionnalité 1 (A4, versionné)
  - Fiche sécurité brasage (EPI, conduite à tenir en cas d'accident)
- **Logiciels :**
  - Arduino IDE (retéléversement du code si nécessaire en SÉA05)

## ✅ Critères de réussite de la séquence

- [ ] **(CC2)** Le poste de travail est organisé avant démarrage (EPI, outillage, schéma consulté)
- [ ] **(CC4)** Les composants sont positionnés et brasés conformément au schéma (pas d'erreur d'implantation)
- [ ] **(CC4)** Toutes les brasures sont nettes, brillantes et mécaniquement solides — pas de brasure froide
- [ ] **(CC4)** Les fils de connexion sont brasés sans court-circuit entre pistes voisines
- [ ] **(CC4)** Le prototype exécute la séquence complète du carrefour SmartUrb : vert voiture → bouton → orange 2 s → rouge voiture / vert piéton 5 s → piéton rouge clignotant 2 s → retour vert voiture

## 📝 Notes / Ajustements

> Séquence recadrée rétrospectivement dans le contexte SmartUrb (anciennement "TechSignal"). Le contenu technique reste inchangé.
>
> Première expérience de brasage des élèves — prévoir une démonstration live du geste par l'enseignant en début de SÉA03 avant toute mise en autonomie.
>
> Le programme Arduino utilisé est celui validé en SEQ02 (fonctionnalité 1 uniquement).
>
> En cas de défaut de brasure détecté en SÉA05, prévoir un temps de reprise ou gérer en heure de remédiation.
>
> Vérifier la ventilation de la salle avant les séances de brasage (SÉA03 et SÉA04).
