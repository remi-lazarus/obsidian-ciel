---
type: séance
titre: Brasage par chaîne — feu tricolore voiture
code: 2de-SEQ03-SÉA03
séquence: "[[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]"
classe: Seconde TNE
date: 
durée_minutes: 60
compétences:
  - CC4
type_séance: TP — Réalisation (demi-groupe)
statut: brouillon
---

# Brasage par chaîne — feu tricolore voiture

## 🎯 Objectif de la séance

À la fin de cette séance, l'élève a brasé les trois chaînes du feu tricolore voiture (LED + résistance + fil de connexion) sur le perfboard, et a testé chaque chaîne individuellement avant de passer à la suivante.

## 🔗 Contexte dans la séquence

Séance appartenant à → [[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]

**Organisation demi-groupe** — cette séance se déroule en parallèle avec [[2de-SEQ03 - SÉA02 - Lecture de schéma électronique]] :
- Groupe A → SÉA02 (lecture de schéma + gabarit)
- Groupe B → SÉA03 (brasage voiture)

Les deux groupes permutent à mi-séquence selon l'organisation définie dans la séquence.

> **Prérequis individuel :** le gabarit d'implantation complété en SÉA02 est obligatoire pour commencer le brasage — chaque élève travaille depuis son propre gabarit.

**Périmètre de cette séance :** feu tricolore voiture uniquement — LED rouge (D1), orange (D2), verte (D3) avec leurs résistances et leurs fils de connexion. Le feu piéton et les boutons sont traités ultérieurement.

## ⏱️ Déroulé pédagogique

| Phase | Activité | Durée | Mode |
|-------|----------|-------|------|
| Mise en place | Gabarit + schéma posés devant soi. EPI enfilés. Fer branché et réglé à 350 °C. Rappel règle absolue : **l'Arduino ne se branche jamais pendant le brasage** — seulement pour les tests, et toujours après accord enseignant. | 5 min | Individuel |
| Fil GND commun | Préparer le fil noir GND (mesurer, couper, dénuder 5 mm, étamer). Braser sur la borne GND du perfboard et sur le GND de l'Arduino. Vérifier la continuité au multimètre avant d'aller plus loin — sans GND, aucun test ne peut se faire. | 10 min | Individuel |
| Chaîne 1 — LED rouge | R1 (220 Ω) : implanter, vérifier position, braser. D1 rouge : vérifier la polarité (anode côté indiqué sur le gabarit), braser. Fil signal : préparer le fil rouge, braser côté perfboard sur l'anode de R1, braser côté Arduino sur D2. → **Test chaîne 1** | 15 min | Individuel + validation |
| Chaîne 2 — LED orange | Même procédure : R2 + D2 orange + fil D3→Arduino. → **Test chaîne 2** | 12 min | Individuel + validation |
| Chaîne 3 — LED verte | Même procédure : R3 + D3 verte + fil D4→Arduino. → **Test chaîne 3** | 12 min | Individuel + validation |
| Bilan et passation | Contrôle visuel enseignant sur les trois chaînes. Rangement du poste. Préparation de la passation au groupe suivant. | 6 min | Collectif |

### Procédure de test après chaque chaîne

1. Informer l'enseignant avant de brancher l'Arduino
2. Brancher l'USB — observer 5 secondes : aucun composant ne doit chauffer
3. Téléverser le sketch de test (disponible sur le poste enseignant) — le sketch allume chaque LED en séquence (D2 → D3 → D4, 1 s chacune)
4. Vérifier que la LED de la chaîne testée s'allume bien au bon moment
5. Débrancher l'Arduino avant de reprendre le brasage

> Si la LED ne s'allume pas : vérifier la polarité, inspecter les brasures (continuité au multimètre), puis appeler l'enseignant.

## 📋 Contenu

### Ordre d'implantation par chaîne

Pour chaque chaîne, l'ordre est toujours le même :

```
① Résistance (pas de polarité — plus simple à braser en premier)
② LED (polarité à vérifier AVANT d'implanter)
③ Fil de connexion vers Arduino (mesurer, couper, dénuder, étamer, braser)
④ Test immédiat
```

| Chaîne | Résistance | LED | Broche Arduino | Couleur fil |
|--------|-----------|-----|----------------|-------------|
| 1 — rouge voiture | R1 — 220 Ω | D1 rouge | D12 | Rouge |
| 2 — orange voiture | R2 — 220 Ω | D2 orange | D11 | Orange |
| 3 — verte voiture | R3 — 220 Ω | D3 verte | D10 | Vert |
| GND commun | — | — | GND Arduino | Noir |

### Rappel — geste de brasage

1. Poser la panne sur le **joint** (pastille + patte simultanément)
2. Chauffer **2 à 3 secondes**
3. Amener l'étain sur le joint chaud (pas sur la panne) — petite quantité
4. Retirer l'étain, puis retirer le fer
5. **Ne pas bouger** pendant 3 à 5 s

> Référence : [[2de-SEQ03 - Fiche mémo brasage]]

### Points de vigilance

- **Polarité LED** : faire vérifier par l'enseignant avant de braser — une LED inversée est difficile à débraser sans abîmer le perfboard
- **Fil GND non vérifié** : si le test échoue sur toutes les LEDs, la première cause est presque toujours le fil GND — vérifier la continuité en premier
- **Etain sur la panne** : une panne qui noircit ne transfère plus la chaleur — nettoyer sur l'éponge humide, ré-étamer, puis continuer
- **Fils trop longs** : mesurer avant de couper — un fil trop long augmente le risque de court-circuit avec un voisin

## 📦 Ressources

- [[2de-SEQ03 - Fiche mémo brasage]] — gestes de référence
- [[2de-SEQ03 - Schéma électronique]] — document de référence pendant toute la séance
- [[2de-SEQ03 - Gabarit perfboard vierge]] — gabarit complété en SÉA02 (document personnel de l'élève)
- Sketch de test pré-chargé sur le poste enseignant (allumage séquentiel D2 → D3 → D4)
- Matériel :
  - Fer à braser réglable 350 °C + support + éponge humide ou bloc de laiton
  - Fil d'étain sans plomb Sn96.5/Ag3/Cu0.5
  - Fil de connexion multibrins : rouge × 2, orange × 1, vert × 1, noir × 1
  - Pince à dénuder, pince coupante, pince brucelles
  - Multimètre (mode continuité)
  - Lunettes de protection, blouse

## ✅ Critères de réussite

- [ ] **(CC4)** Le fil GND est brasé et la continuité est vérifiée au multimètre avant tout test
- [ ] **(CC4)** Chaque chaîne est brasée dans l'ordre : résistance → LED (polarité vérifiée) → fil
- [ ] **(CC4)** Chaque chaîne est testée individuellement avant de passer à la suivante
- [ ] **(CC4)** Les trois LEDs voiture s'allument lors du test final
- [ ] **(CC4)** Toutes les brasures sont brillantes et coniques — pas de brasure froide ni de pont

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
