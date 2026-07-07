---
type: support-élève
titre: Gabarit perfboard vierge — SEQ03
code: 2de-SEQ03-gabarit-perfboard
séquence: "[[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]"
séance: "[[2de-SEQ03 - SÉA02 - Lecture de schéma électronique]]"
classe: Seconde TNE
à_imprimer: true
---

# Gabarit perfboard vierge — SEQ03

**Nom / Prénom :** ___________________________  **Classe :** _________  **Date :** ___________

> **Consigne :** À partir du [[2de-SEQ03 - Schéma électronique]], reporter la position de chaque composant sur ce gabarit. Ce document sera ton guide personnel pendant la réalisation (SÉA03 et SÉA04). Sois précis — une erreur sur le gabarit entraîne une erreur sur le prototype.

---

## Le perfboard — rappel

> Voir la fiche de cours complète : [[2de-SEQ03 - Cours — Le perfboard]]

Un perfboard (plaque à braser) est une plaque percée de trous régulièrement espacés (pas de **2,54 mm = 0,1 pouce**). Chaque trou est entouré d'une **pastille de cuivre** sur laquelle on braser le composant. Les trous ne sont **pas reliés entre eux** — c'est toi qui crée les connexions avec l'étain et les fils.

---

## Grille d'implantation (30 × 20 trous)

> Reporter chaque composant dans la case correspondant à sa position prévue. Utiliser les abréviations : **R1–R6** (résistances), **D1–D5** (LEDs), **SW1** (bouton), **GND** (masse), **+5V** (alimentation).
> Marquer **(A)** pour l'anode et **(K)** pour la cathode des LEDs.

```
     1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
A  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
B  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
C  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
D  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
E  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
F  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
G  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
H  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
I  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
J  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
K  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
L  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
M  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
N  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
O  |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
```

*Grille indicative — adapter si le perfboard physique a des dimensions différentes.*

---

## Tableau de positionnement (à compléter)

| Référence | Composant | Valeur | Position sur la grille | Orientation / Polarité |
|-----------|-----------|--------|------------------------|------------------------|
| R1 | Résistance | 220 Ω | | — |
| R2 | Résistance | 220 Ω | | — |
| R3 | Résistance | 220 Ω | | — |
| R4 | Résistance | 220 Ω | | — |
| R5 | Résistance | 220 Ω | | — |
| R6 | Résistance pull-down | 10 kΩ | | — |
| D1 | LED rouge voiture | — | | A = ___  K = ___ |
| D2 | LED orange voiture | — | | A = ___  K = ___ |
| D3 | LED verte voiture | — | | A = ___  K = ___ |
| D4 | LED rouge piéton | — | | A = ___  K = ___ |
| D5 | LED verte piéton | — | | A = ___  K = ___ |
| SW1 | Bouton poussoir | — | | |

---

## Questions de vérification (à compléter avant de commencer SÉA03)

**1.** Tous les composants de la nomenclature sont-ils reportés sur le gabarit ?
→ _______________________________________________

**2.** Les polarités (A/K) de toutes les LEDs sont-elles indiquées ?
→ _______________________________________________

**3.** Y a-t-il suffisamment d'espace entre les composants pour braser sans risquer un pont ?
→ _______________________________________________

**4.** L'emplacement des sorties vers l'Arduino (côté connecteur) est-il prévu ?
→ _______________________________________________

> ✅ **Ce gabarit doit être validé par l'enseignant avant le début de SÉA03.**

**Validé par l'enseignant :** ⬜  **Observations :** _______________________________

Groupe A
![[Pasted image 20260409224603.png]]
Final
![[Pasted image 20260409230027.png]]
Groupe B
![[Pasted image 20260409230418.png]]
