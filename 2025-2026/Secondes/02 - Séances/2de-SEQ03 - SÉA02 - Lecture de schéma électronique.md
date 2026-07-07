---
type: séance
titre: Lecture de schéma électronique
code: 2de-SEQ03-SÉA02
séquence: "[[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]"
classe: Seconde TNE
date: 
durée_minutes: 60
compétences:
  - C04
savoirs:
  - Lecture d'un schéma électronique
  - Fonctionnement et utilisation d'un perfboard
  - Implantation de composants sur plaque à braser (perfboard)
type_séance: Cours / TD
statut: brouillon
---

# Lecture de schéma électronique

## Objectif de la séance

À la fin de cette séance, l'élève est capable de lire le schéma électronique du feu de circulation SmartUrb, d'identifier chaque composant et sa broche Arduino associée, et de reporter le positionnement des composants sur un gabarit de perfboard — prêt à braser en SÉA03.

## Contexte dans la séquence

Séance appartenant à → [[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]

Deuxième séance du bloc "lancement 2h", après [[2de-SEQ03 - SÉA01 - Soudage — notions et sécurité]].

Les élèves ont déjà câblé ce circuit sur breadboard lors de [[2de-SEQ01 - SÉA05 - TP2 matériel physique]] et [[2de-SEQ02 - SÉA03 - Réalisation sur matériel réel]] : ils connaissent les composants physiques et leur câblage. Ce qu'ils ne maîtrisent pas encore, c'est la **représentation schématique normalisée** — symboles, nœuds, références, sens de lecture. C'est l'objet de cette séance, point de passage obligatoire avant l'implantation sur perfboard.

## Déroulé pédagogique

| Phase                                   | Activité                                                                                                                                                                                                                                                                               | Durée  | Mode                     |
| --------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------ | ------------------------ |
| Lancement — découverte du perfboard     | Distribuer un perfboard vierge à chaque élève. Observer, toucher, comparer avec la breadboard. Questions orales : "Que remarquez-vous ? Les trous sont-ils reliés ?" → test au multimètre en direct. Lecture de [[2de-SEQ03 - Cours — Le perfboard]] section 1 et 2                    | 10 min | Collectif / Manipulation |
| Activité principale — lecture de schéma | Affichage côte à côte de la photo du montage breadboard (SEQ02) et du schéma électronique SmartUrb. Décodage guidé : symboles normalisés, nœuds électriques, références composants. Exercice de correspondance : relier chaque symbole du schéma à son composant réel + broche Arduino | 25 min | Individuel               |
| Mise en commun                          | Correction collective au tableau — polarité LED, confusion broche logique / pin physique, nœuds électriques (point noir = connexion, croix sans point = pas de connexion)                                                                                                              | 10 min | Collectif                |
| Bilan / Production — gabarit            | Complétion du [[2de-SEQ03 - Gabarit perfboard vierge]] : reporter la position de chaque composant sur le quadrillage en respectant les contraintes d'espacement et de polarité — ce gabarit sera le guide personnel en SÉA03. Validation enseignant obligatoire avant de partir.       | 15 min | Individuel               |

## Contenu

### Mise en situation

Le bureau d'études SmartUrb fournit un schéma électronique à chaque fois qu'un prototype doit être assemblé. Ce document est la référence officielle : il fait foi sur la valeur des résistances, le sens des LEDs, les broches Arduino utilisées. Sur un chantier réel, un technicien qui ne sait pas lire un schéma ne peut pas assembler un prototype fiable. Cette séance, c'est exactement ça : comprendre le support (le perfboard), lire le document de référence (le schéma), et planifier l'implantation avant de toucher le fer à braser.

### Activité élève

Les élèves disposent du [[2de-SEQ03 - Schéma électronique]] (format A4) et du [[2de-SEQ03 - Gabarit perfboard vierge]] (quadrillage A4).

**Étape 1 — Identifier chaque symbole du schéma**

Pour chaque composant présent sur le schéma, renseigner le tableau suivant :

| Symbole (référence schéma) | Nom du composant     | Valeur / Caractéristique | Composant réel vu en SEQ02 ? |
| -------------------------- | -------------------- | ------------------------ | ---------------------------- |
| R1, R2, R3, R4, R5         | Résistance           | 220 Ω                    | Oui                          |
| R6                         | Résistance pull-down | 10 kΩ                    | Oui                          |
| D1 (rouge)                 | LED                  | Rouge, 5 mm              | Oui                          |
| D2 (orange)                | LED                  | Orange, 5 mm             | Oui                          |
| D3 (verte)                 | LED                  | Verte, 5 mm              | Oui                          |
| D4 (rouge piéton)          | LED                  | Rouge, 5 mm              | Oui                          |
| D5 (verte piéton)          | LED                  | Verte, 5 mm              | Oui                          |
| SW1                        | Bouton poussoir      | —                        | Oui                          |
| U1                         | Arduino Uno          | —                        | Oui                          |

> Point méthode : sur un schéma, le triangle avec une barre représente la LED — la barre est du côté cathode (−), la pointe du triangle est du côté anode (+). Cette convention est universelle, quelle que soit la couleur de la LED.

**Étape 2 — Retrouver la broche Arduino de chaque composant**

Lire le schéma en suivant chaque fil depuis la broche Arduino jusqu'au composant. Compléter :

| Référence schéma | Composant réel | Broche Arduino (numéro logique) | Pin physique sur le connecteur |
|------------------|----------------|---------------------------------|-------------------------------|
| D1 + R1 | LED rouge voiture | D12 | — |
| D2 + R2 | LED orange voiture | D11 | — |
| D3 + R3 | LED verte voiture | D10 | — |
| D4 + R4 | LED rouge piéton | D9 | — |
| D5 + R5 | LED verte piéton | D8 | — |
| SW1 + R6 | Bouton poussoir | D2 | — |

> Les valeurs de broches ci-dessus sont indicatives et à adapter au schéma fourni. L'important est la méthode de lecture, pas les numéros.

**Étape 3 — Compléter le tableau de correspondance complet**

Consolider les étapes 1 et 2 dans le tableau de correspondance élève (support papier à rendre) : référence schéma → composant réel → broche Arduino.

**Étape 4 — Reporter les positions sur le gabarit perfboard**

Sur le [[2de-SEQ03 - Gabarit perfboard vierge]] (quadrillage), tracer la position de chaque composant en respectant :
- L'ordre logique sur le schéma (regrouper les LEDs voiture ensemble, les LEDs piéton ensemble)
- La polarité des LEDs : marquer clairement l'anode (A) et la cathode (K) sur le gabarit
- L'espacement suffisant entre composants pour permettre la brasure
- L'emplacement de l'Arduino Uno (ou du connecteur de câblage vers l'Arduino)

### Éléments de correction / Points de vigilance

**Polarité des LEDs**
Sur le schéma, la cathode est toujours du côté de la barre verticale du symbole diode. Sur le composant réel, la cathode se repère par la patte la plus courte ET par le méplat sur le boîtier. Une LED brasée à l'envers ne s'allume pas et peut être détruite si elle reste sous tension.

**Résistance pull-down (R6)**
Ces résistances relient l'entrée Arduino à la masse (GND) quand le bouton est relâché. Sans elles, l'entrée est "en l'air" (flottante) et lit des valeurs aléatoires. Ce n'est pas une résistance de limitation de courant : sa valeur de 10 kΩ est choisie pour imposer un niveau logique BAS (0 V) sans consommer trop de courant.

**Sens de lecture d'un schéma**
Par convention, on lit un schéma de la source d'alimentation (haut ou gauche) vers la masse / GND (bas ou droite). Sur ce schéma, la source est le +5 V de l'Arduino et la masse est le GND. Suivre ce sens aide à ne pas confondre sens du courant et sens de câblage.

**Erreur fréquente : numéro logique vs pin physique**
La broche "D2" sur le schéma correspond à la broche numérique numéro 2 du programme Arduino (`pinMode(2, OUTPUT)`). Ce n'est pas forcément la 2e patte physique du connecteur sur la carte. Sur la carte Arduino Uno, les broches numériques sont sérigraphiées : se fier à la sérigraphie, pas à la position.

**Erreur fréquente : les nœuds électriques**
Sur un schéma, deux fils qui se croisent avec un point noir sont connectés. Deux fils qui se croisent sans point noir ne sont pas connectés (ils se croisent juste graphiquement). Vérifier systématiquement la présence ou l'absence de ce point avant de câbler.

## Ressources

- [ ] [[2de-SEQ03 - Schéma électronique]]
- [ ] [[2de-SEQ03 - Gabarit perfboard vierge]]
- [ ] Tableau de correspondance à compléter (support élève papier, inclus dans le gabarit ou en document séparé)
- [ ] Photo du montage breadboard SEQ02 (projection au tableau en début de séance)

## Critères de réussite

- [ ] **(C04)** L'élève identifie tous les composants du schéma et associe chacun à son symbole normalisé
- [ ] **(C04)** Le tableau de correspondance est entièrement complété et correct (référence schéma → composant réel → broche Arduino)
- [ ] **(C04)** Le gabarit de perfboard indique le positionnement correct de tous les composants
- [ ] **(C04)** La polarité des LEDs (anode / cathode) est correctement reportée sur le gabarit
- [ ] **(C04)** L'élève distingue broche logique Arduino et pin physique sur le connecteur

## Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
