---
type: tp-élève
titre: TP SÉA02 — Lecture de schéma électronique
code: 2de-SEQ03-TP-SÉA02
séquence: "[[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]"
classe: Seconde TNE
à_imprimer: true
---

# TP SÉA02 — Lecture de schéma électronique

**Nom / Prénom :** ________________________________  **Date :** __________

> **Document de référence à avoir devant toi pendant toute la séance :** [[2de-SEQ03 - Schéma électronique]]

---

## Activité 1 — Découverte du perfboard

Observe le perfboard distribué en classe. Réponds sans chercher dans tes notes.

**1.** Les trous du perfboard sont-ils tous reliés entre eux ? Coche ta réponse.

- [ ] Oui, tous les trous sont reliés
- [ ] Non, aucun trou n'est relié
- [ ] Seulement certains trous sont reliés — lesquels ? ___________________________

**2.** Après le test au multimètre en classe, complète :

> Sur ce perfboard, chaque pastille est __________________ des autres.
> Pour créer une connexion, il faudra __________________ les deux pastilles.

**3.** Quelle est la différence principale entre un perfboard et une breadboard ?

> _________________________________________________________________________
> _________________________________________________________________________

---

## Activité 2 — Identifier les composants du schéma

Pour chaque référence du schéma, complète le tableau. Utilise le schéma [[2de-SEQ03 - Schéma électronique]].

| Référence schéma | Symbole normalisé (dessin ou description) | Nom du composant | Valeur / Caractéristique |
|-----------------|------------------------------------------|-----------------|--------------------------|
| R1, R2, R3 | | | |
| R4, R5 | | | |
| R6, R7 | | | |
| D1 | | | |
| D2 | | | |
| D3 | | | |
| D4 | | | |
| D5 | | | |
| SW1, SW2 | | | |
| U1 | | | |

---

## Activité 3 — Retrouver les broches Arduino

En suivant chaque fil sur le schéma depuis la broche Arduino jusqu'au composant, complète le tableau.

| Référence schéma | Composant réel | Broche Arduino (n° logique) |
|-----------------|----------------|----------------------------|
| D1 + R1 | LED __________ voiture | D___ |
| D2 + R2 | LED __________ voiture | D___ |
| D3 + R3 | LED __________ voiture | D___ |
| D4 + R4 | LED __________ piéton | D___ |
| D5 + R5 | LED __________ piéton | D___ |
| SW1 + R6 | Bouton poussoir 1 | D___ |
| SW2 + R7 | Bouton poussoir 2 | D___ |
| — | GND commun | GND |

**Question :** sur la carte Arduino Uno, la broche « D2 » correspond-elle à la 2e patte physique du connecteur ?

- [ ] Oui
- [ ] Non — explication : ___________________________________________________

---

## Activité 4 — Lire les connexions

Réponds aux questions suivantes en observant le schéma.

**1.** Sur un schéma, comment sait-on que deux fils **sont connectés** à leur croisement ?

> _________________________________________________________________________

**2.** Comment sait-on qu'ils **ne sont pas connectés** ?

> _________________________________________________________________________

**3.** Sur le symbole de la LED, de quel côté se trouve la **cathode (−)** ?

> _________________________________________________________________________

**4.** Quel est le rôle des résistances R6 et R7 (10 kΩ) ? (différent des résistances R1 à R5)

> _________________________________________________________________________
> _________________________________________________________________________

---

## Activité 5 — Gabarit d'implantation perfboard

> **Support séparé :** [[2de-SEQ03 - Gabarit perfboard vierge]] (feuille quadrillée A4)

Sur le gabarit, reporte la position de chaque composant en respectant les contraintes suivantes :

- [ ] Résistances et LEDs voiture regroupées ensemble
- [ ] Résistances et LEDs piéton regroupées ensemble
- [ ] Polarité de chaque LED marquée : **A** (anode) et **K** (cathode)
- [ ] Espacement suffisant entre composants pour braser (minimum 1 case entre deux composants)
- [ ] Position de l'Arduino (ou du connecteur de câblage) indiquée sur le gabarit

**Validation enseignant :** ⬜  *Le gabarit est vérifié avant le début du brasage (SÉA03)*

---

## Bilan

**Ce que je retiens sur la lecture d'un schéma :**

> _________________________________________________________________________
> _________________________________________________________________________

**Le point qui m'a posé le plus de difficulté :**

> _________________________________________________________________________

---

*Référence : [[2de-SEQ03 - Schéma électronique]] · [[2de-SEQ03 - Cours — Le perfboard]]*
