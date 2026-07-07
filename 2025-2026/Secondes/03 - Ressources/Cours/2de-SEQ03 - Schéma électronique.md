---
type: cours
titre: Schéma électronique — Fonctionnalité 1 (carrefour complet)
code: 2de-SEQ03-schema-elec
séquence: "[[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]"
classe: Seconde TNE
version: 1.0
---

# Schéma électronique

> **Document de référence pour SEQ03.** À consulter pendant SÉA02 (lecture de schéma), SÉA03 et SÉA04 (réalisation), et SÉA05 (diagnostic).
>
> ⚠️ Le schéma graphique officiel (format PDF/PNG) est fourni séparément par l'enseignant — ce document est la **description textuelle et le tableau de connexion** qui l'accompagnent.

---

## Description du système

Le carrefour SmartUrb comporte :
- **3 LEDs voiture** (rouge, orange, verte) — feu tricolore
- **2 LEDs piéton** (rouge, verte) — feu bicolore
- **1 bouton poussoir** — appel piéton
- **1 carte Arduino Uno** — cerveau du système

Toutes les LEDs sont pilotées en **sortie numérique** avec résistance de limitation de courant série. Le bouton est lu en **entrée numérique** avec résistance de tirage vers la masse (pull-down).

---

## Tableau de connexion complet

| Référence | Composant          | Broche Arduino | Résistance associée | Valeur R |
| --------- | ------------------ | -------------- | ------------------- | -------- |
| D1        | LED rouge voiture  |                | R1 (série)          | 220 Ω    |
| D2        | LED orange voiture |                | R2 (série)          | 220 Ω    |
| D3        | LED verte voiture  |                | R3 (série)          | 220 Ω    |
| D4        | LED rouge piéton   |                | R4 (série)          | 220 Ω    |
| D5        | LED verte piéton   |                | R5 (série)          | 220 Ω    |
| SW1       | Bouton poussoir    |                | R6 (pull-down)      | 10 kΩ    |
| —         | Masse commune      |                | —                   | —        |
| —         | Alimentation       |                | —                   | —        |

---

## Schéma électronique

![[Pasted image 20260409234854.png]]

**Note sur R6 (pull-down) :**
- Bouton relâché → D2 lié à GND via R6 → lit **0 (FAUX)**
- Bouton appuyé → D2 lié à 5V via le bouton → lit **1 (VRAI)**
- Sans R6, D2 serait "en l'air" (flottant) et lirait des valeurs aléatoires.

---

## Calcul des résistances série LEDs

| Grandeur | Valeur |
|----------|--------|
| Tension alimentation Arduino | 5 V |
| Tension seuil LED standard (rouge/orange/vert) | 2,0 V |
| Courant LED recommandé | 10 mA |
| **Formule** | R = (Vcc − Vled) / Iled |
| **Calcul** | R = (5 − 2,0) / 0,010 = **300 Ω** |
| **Valeur choisie** | **220 Ω** (valeur normalisée E24 inférieure) |

> Le choix de 220 Ω plutôt que 300 Ω donne un courant légèrement supérieur (~13,6 mA) mais reste dans la plage nominale de la LED. Les LEDs sont légèrement plus lumineuses, ce qui est souhaitable pour un feu de circulation.

---

## Implantation sur perfboard — contraintes à respecter

1. **Regrouper les LEDs voiture** ensemble (D1, D2, D3) — colonne ou rangée adjacente
2. **Regrouper les LEDs piéton** ensemble (D4, D5) — zone séparée
3. **Résistances** : placer en série juste avant l'anode de chaque LED
4. **Bouton** : en bas du perfboard, accessible facilement
5. **Nœud GND commun** : prévoir une ligne de masse horizontale sur le perfboard (barre de bus)

