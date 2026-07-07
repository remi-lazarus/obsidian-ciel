---
type: consignes-élève
titre: Consignes élève — SÉA02 et SÉA03
code: 2de-SEQ03-consignes
séquence: "[[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]"
classe: Seconde TNE
à_imprimer: true
---

# Consignes élève — SEQ03

**Nom / Prénom :** ________________________________  **Groupe :** ⬜ SÉA02  ⬜ SÉA03

---

## Groupe SÉA02 — Lecture de schéma électronique

> **Document à avoir devant toi :** [[2de-SEQ03 - Schéma électronique]] imprimé · [[2de-SEQ03 - Gabarit perfboard vierge]] · ton TP SÉA02

---

**Consigne 1**
Observe le perfboard distribué. Teste deux pastilles voisines au multimètre (mode continuité). Note ce que tu observes dans la case prévue du TP.

> *But : comprendre que chaque pastille est indépendante — il faudra braser pour créer une connexion.*

---

**Consigne 2**
Pour chaque référence du schéma (R1 à R6, D1 à D5, SW1, U1), complète le tableau d'identification : nom du composant, valeur et symbole normalisé.

> *But : identifier tous les composants du schéma et les associer à leur symbole — critère CC4 évalué.*

---

**Consigne 3**
En suivant chaque fil sur le schéma, retrouve la broche Arduino qui commande chaque LED et le bouton. Complète le tableau de correspondance.

> *But : lire les connexions d'un schéma — critère CC4 évalué.*

---

**Consigne 4**
Réponds aux questions sur la polarité de la LED (anode / cathode), les nœuds électriques et la différence entre broche logique et pin physique.

> *But : vérifier la compréhension des points clés avant de braser — une erreur ici entraîne une LED inversée en SÉA03.*

---

**Consigne 5**
Sur le gabarit perfboard, reporte la position de chaque composant : résistances, LEDs (avec A et K marqués), fils vers l'Arduino. Respecte les contraintes d'espacement.

**→ Appelle l'enseignant pour valider ton gabarit avant de le rendre.**

> *But : planifier l'implantation avant de toucher le fer — critère CC4 évalué. Le gabarit validé est ton guide personnel en SÉA03.*

---

## Groupe SÉA03 — Brasage par chaîne, feu voiture

> **Documents à avoir devant toi :** [[2de-SEQ03 - Schéma électronique]] · ton gabarit validé (SÉA02) · [[2de-SEQ03 - Fiche mémo brasage]] · ton TP SÉA03

---

> [!warning] Règle absolue
> L'Arduino ne se branche **jamais** pendant le brasage — uniquement pour les tests, après accord de l'enseignant.

---

**Consigne 1**
Avant de brancher le fer : dispose le gabarit et le schéma devant toi, enfile les EPI (lunettes + blouse), allume la ventilation, règle le fer à 350 °C. Coche la liste de vérification du TP.

**→ Appelle l'enseignant pour valider la mise en place.**

> *But : organiser son poste avant toute manipulation — critère CC2 évalué.*

---

**Consigne 2**
Prépare le fil GND noir (mesure, coupe, dénude 5 mm, étame). Brase une extrémité sur la borne GND du perfboard, l'autre sur le GND de l'Arduino. Vérifie la continuité au multimètre (mode bip).

> *But : sans GND validé, aucun test n'est possible — c'est la fondation de toutes les chaînes.*

---

**Consigne 3**
Implante et brase R1 (220 Ω) à la position de ton gabarit. Vérifie l'aspect de la brasure : brillante et conique.

> *But : maîtriser le geste de brasage sur un composant sans polarité (plus simple) avant de passer aux LEDs — critère CC4 évalué.*

---

**Consigne 4**
Vérifie la polarité de D1 rouge (patte longue = anode, côté indiqué sur ton gabarit).
**→ Appelle l'enseignant avant d'implanter la LED.**
Implante D1 et brase.

> *But : une LED brasée à l'envers ne s'allume pas et est difficile à débraser — la vérification avant brasure est un critère CC4 évalué.*

---

**Consigne 5**
Prépare le fil rouge (mesure, coupe, dénude 5 mm, étame). Brase côté perfboard sur l'anode de R1, côté Arduino sur la broche D12.
**→ Appelle l'enseignant pour le test. Branche l'Arduino uniquement sur son accord.**

> *But : vérifier la chaîne complète (composant + fil) avant d'en commencer une autre — si ça ne fonctionne pas maintenant, c'est plus facile à corriger qu'après 3 chaînes brasées.*

---

**Consigne 6**
Répète les consignes 3, 4 et 5 pour la chaîne LED orange : R2 → D2 orange → fil D11 → test.

> *But : reproduire la méthode de façon autonome — critère CC4 évalué.*

---

**Consigne 7**
Répète pour la chaîne LED verte : R3 → D3 verte → fil D10 → test.
**→ À la fin, appelle l'enseignant pour le contrôle visuel final des trois chaînes.**

> *But : les trois LEDs voiture doivent s'allumer lors du test final — résultat fonctionnel CC4 évalué.*

---

**Consigne 8**
Range le poste : fer éteint sur son support, éponge retirée, chutes de pattes dans la poubelle, plan de travail nettoyé.

> *But : attitude écoresponsable — critère CC4 évalué.*
