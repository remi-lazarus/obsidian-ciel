---
type: séance
titre: Tests et validation du prototype
code: 2de-SEQ03-SÉA05
séquence: "[[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]"
classe: Seconde TNE
date: 
durée_minutes: 120
compétences:
  - CC4
type_séance: TP — Validation
statut: brouillon
---

# Tests et validation du prototype

## 🎯 Objectif de la séance

À la fin de cette séance, l'élève a testé le prototype brasé selon un protocole structuré, déclaré sa conformité ou non-conformité par rapport au cahier des charges SmartUrb, et produit un rapport de validation livrable.

## 🔗 Contexte dans la séquence

Séance appartenant à → [[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]

Cinquième et dernière séance — le prototype est assemblé et les connexions sont vérifiées (SÉA03). On passe maintenant à la **validation fonctionnelle** : est-ce que le carrefour se comporte exactement comme le spécifie le cahier des charges SmartUrb ? La réponse doit être documentée dans un rapport de conformité.

> **Enjeu SmartUrb :** ce rapport de validation sera le premier document officiel remis à la Métropole de Metz. Un prototype déclaré "conforme" sans l'avoir vérifié engage la responsabilité de SmartUrb. Un prototype "non conforme" mais avec défauts bien documentés permet une correction avant livraison.

## ⏱️ Déroulé pédagogique

| Phase | Activité | Durée | Mode |
|-------|----------|-------|------|
| Mise sous tension initiale | Connecter l'Arduino + vérifier qu'aucun composant ne chauffe anormalement — si c'est le cas, débrancher immédiatement | 5 min | Individuel, enseignant présent |
| Tests fonctionnels | Exécuter le protocole de test complet (tableau de conformité) — noter chaque résultat | 50 min | Individuel |
| Analyse et corrections | Si non-conformité détectée : identifier la cause (brasure, polarité, code) et corriger si possible dans le temps imparti | 30 min | Individuel + aide enseignant |
| Rédaction du rapport | Compléter le rapport de conformité : statut conforme / non conforme, défauts constatés, actions menées | 25 min | Individuel |
| Bilan collectif | Mise en commun : problèmes rencontrés, solutions trouvées, points de vigilance pour la prochaine fois | 10 min | Collectif |

## 📋 Contenu

### Mise en situation

Le prototype est assemblé. SmartUrb remet chaque livraison à la Métropole de Metz accompagnée d'un **rapport de validation**. Ce document certifie que le système a été testé et atteste de sa conformité au cahier des charges. C'est ton rapport que tu vas rédiger aujourd'hui.

### Procédure de mise sous tension — première fois

Avant de brancher l'USB :

- [ ] Vérifier visuellement qu'aucun fil nu ne touche un fil voisin
- [ ] Vérifier que la table de continuité SÉA04 est complète (toutes les connexions validées)
- [ ] Tenir le prototype à plat, éloigné des matières inflammables
- [ ] Brancher l'USB sur l'Arduino — observer pendant **10 secondes** sans toucher

**Si une LED s'allume en permanence sans clignoter, ou si un composant chauffe :**
→ Débrancher immédiatement → chercher le court-circuit ou l'inversion de polarité

**Si rien ne se passe (aucune LED) :**
→ Vérifier que le programme est chargé (Arduino IDE → téléverser si nécessaire)

### Protocole de test — tableau de conformité

> Référence : [[Projets/SmartUrb/Contexte projet — SmartUrb]] — Cahier des charges fonctionnalité 1

#### Test 1 — Cycle voiture (sans appui bouton)

| Critère CDC | Comportement observé | Conforme ? |
|-------------|---------------------|------------|
| LED verte voiture allumée au démarrage | | ⬜ |
| Durée verte voiture : 5 s (±0,5 s) | | ⬜ |
| LED orange voiture s'allume après le vert | | ⬜ |
| Durée orange voiture : 2 s (±0,5 s) | | ⬜ |
| LED rouge voiture s'allume après l'orange | | ⬜ |
| Rouge voiture reste allumé (permanent) | | ⬜ |
| Une seule LED voiture allumée à la fois | | ⬜ |

#### Test 2 — Feu piéton au repos

| Critère CDC | Comportement observé | Conforme ? |
|-------------|---------------------|------------|
| LED rouge piéton allumée au repos | | ⬜ |
| LED verte piéton éteinte au repos | | ⬜ |

#### Test 3 — Activation par le bouton piéton

| Critère CDC | Comportement observé | Conforme ? |
|-------------|---------------------|------------|
| Appui bouton → orange voiture 2 s | | ⬜ |
| Orange voiture → rouge voiture + vert piéton | | ⬜ |
| Durée vert piéton : 5 s (±0,5 s) | | ⬜ |
| Vert piéton → piéton rouge clignotant | | ⬜ |
| Durée clignotant piéton : 2 s (±0,5 s) | | ⬜ |
| Retour au cycle voiture après clignotant | | ⬜ |

#### Test 4 — Robustesse

| Critère | Comportement observé | Conforme ? |
|---------|---------------------|------------|
| Le cycle reprend normalement après un appui bouton complet | | ⬜ |
| Appui bouton en phase orange ou rouge voiture : pas de blocage | | ⬜ |

### Rapport de conformité (à rendre)

**Prototype N° :** _________  **Élève :** _______________________  **Date :** ___________

**Résultat global :**
- [ ] ✅ **CONFORME** — Tous les critères du CDC sont satisfaits
- [ ] ⚠️ **NON CONFORME** — Un ou plusieurs critères ne sont pas satisfaits (voir tableau)

**Défauts constatés :**

| N° | Description du défaut | Cause identifiée | Corrigé ? |
|----|----------------------|-----------------|-----------|
| 1 | | | ⬜ |
| 2 | | | ⬜ |
| 3 | | | ⬜ |

**Actions correctives menées :**

_____________________________________________________
_____________________________________________________

**Observations générales :**

_____________________________________________________

**Signature élève :** _______________________   **Validé par l'enseignant :** ⬜

### Éléments de correction / Causes fréquentes de non-conformité

| Symptôme | Cause probable | Solution |
|----------|---------------|----------|
| Une LED ne s'allume pas | Brasure froide ou polarité inversée | Rebraser ou débraser + réorienter |
| Timing incorrect | Code non téléversé ou modifié | Retéléverser le programme SEQ02 |
| Tout fonctionne sauf le bouton | Pull-down non brasé, ou D2 mal connecté | Vérifier connexion R6 + fil D2 |
| Court-circuit au démarrage | Pont de brasure entre pistes | Inspecter sous lumière rasante, nettoyer avec tresse |
| LED piéton rouge toujours allumée | Normal au repos — vérifier test 3 | — |

## 📦 Ressources

- [[Projets/SmartUrb/Contexte projet — SmartUrb]] — cahier des charges (référence pour les critères)
- [[2de-SEQ03 - Schéma électronique]] — pour diagnostic en cas de non-conformité
- Matériel :
  - Câble USB Arduino
  - Arduino IDE (si retéléversement nécessaire)
  - Multimètre (mode continuité + mode tension)
  - Tresse à débraser + fer à braser (corrections éventuelles)

## ✅ Critères de réussite

- [ ] **(CC4)** La mise sous tension est réalisée en respectant la procédure (vérifications préalables)
- [ ] **(CC4)** Le protocole de test est exécuté de façon méthodique (tableau complété case par case)
- [ ] **(CC4)** Les défauts éventuels sont identifiés avec leur cause probable
- [ ] **(CC4)** Le rapport de conformité est complété, signé et remis — conforme ou non conforme avec justification

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
