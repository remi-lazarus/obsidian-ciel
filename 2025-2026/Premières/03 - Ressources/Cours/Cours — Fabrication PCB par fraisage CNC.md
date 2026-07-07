---
type: cours
titre: "Fabrication PCB par fraisage CNC"
séquence: "[[1ere-SEQ01 - Météo57 Phase 2]]"
classe: Première CIEL
compétences:
  - C07
lié_au_poste: C
---

# Fiche cours — Fabrication PCB par fraisage CNC

## 1. Du fichier numérique au circuit imprimé — la chaîne complète

```
Conception sous Fusion 360
         │
         ▼
  Export fichiers Gerber
  (.gtl — pistes cuivre)
  (.drl — perçages)
         │
         ▼
  Import dans GALAAD 3
  (calcul parcours outil)
         │
         ▼
  Fraisage CNC — Technodrill 3
  (gravure + perçage)
         │
         ▼
  Contrôle qualité
  (visuel + multimètre)
         │
         ▼
  PCB prêt pour câblage
```

---

## 2. Les fichiers Gerber

Le format **Gerber** (RS-274X) est le standard industriel pour l'échange de données de fabrication de circuits imprimés. Tous les logiciels de CAO électronique (Fusion 360, KiCad, Altium…) peuvent exporter dans ce format.

### Principaux fichiers Gerber

| Extension | Contenu |
|-----------|---------|
| `.gtl` | Cuivre top (pistes et pastilles face composants) |
| `.gbl` | Cuivre bottom (face brasure, double face) |
| `.drl` | Fichier de perçage (format Excellon) |
| `.gko` | Contour du PCB |

> Dans notre projet, le PCB est **simple face** : seulement `.gtl` et `.drl`.

---

## 3. La Technodrill 3 — machine de fraisage CNC

La **Technodrill 3** est une fraiseuse CNC (Commande Numérique par Calculateur) dédiée à la fabrication de circuits imprimés au lycée.

### Principe de fonctionnement

Un outil rotatif (fraise ou foret) se déplace selon des axes X, Y, Z contrôlés par ordinateur. Pour fabriquer un PCB :
1. **Gravure** : la fraise enlève le cuivre entre les pistes pour les isoler
2. **Perçage** : le foret perce les trous pour les composants traversants
3. **Détourage** : découpe du contour du PCB (optionnel)

### Les outils

| Outil | Forme | Utilisation |
|-------|-------|-------------|
| V-bit 30° Ø 0,1 mm | Pointe conique | Gravure des pistes — trace un sillon fin entre les pistes |
| Foret Ø 0,8 mm | Cylindrique | Perçage des pastilles pour composants standard |
| Foret Ø 1,0 mm | Cylindrique | Perçage pour connecteurs ou composants plus larges |

---

## 4. Paramètres d'usinage — comprendre les valeurs

### Vitesse de rotation de la broche (tr/min)

C'est la vitesse à laquelle l'outil tourne sur lui-même. Plus elle est élevée, plus la coupe est nette sur les matériaux durs comme le cuivre et la fibre de verre (FR4).

### Vitesse d'avance (mm/min)

C'est la vitesse à laquelle la machine déplace l'outil dans le plan XY. C'est un paramètre critique :

| Vitesse d'avance | Conséquence |
|-----------------|-------------|
| Trop rapide | Bris de mèche, pistes mal gravées |
| Trop lente | Brûlure du FR4, usure excessive de l'outil |
| Correcte | Coupe nette, outil préservé |

### Profondeur de passe (mm)

Pour la gravure : on enlève juste assez de cuivre pour isoler les pistes (−0,1 mm). Trop profond = fragilise le substrat FR4.

### Tableau récapitulatif des paramètres Météo57

| Opération | Outil | Broche (tr/min) | Avance (mm/min) | Profondeur |
|-----------|-------|-----------------|-----------------|------------|
| Gravure isolation | V-bit 30° Ø 0,1 | 20 000 | 300 | −0,1 mm |
| Perçage composants | Foret Ø 0,8 | 15 000 | 200 | Traversant |

---

## 5. Mise à zéro Z — étape critique

La mise à zéro Z définit la position de référence de l'outil par rapport à la surface du PCB. C'est l'étape la plus délicate de la fabrication.

**Méthode de la feuille de papier :**
- Placer une feuille entre l'outil et le cuivre
- Descendre l'outil jusqu'à ce que la feuille résiste légèrement (frôlement)
- Valider ce point comme zéro Z

**Conséquences d'une mauvaise mise à zéro :**

| Erreur | Conséquence |
|--------|-------------|
| Zéro trop bas | Gravure trop profonde → pistes effacées ou FR4 percé |
| Zéro trop haut | Pas assez de cuivre enlevé → court-circuits entre pistes |

---

## 6. Contrôle qualité du PCB

### Contrôle visuel (à l'œil ou à la loupe)

- **Ponts** : dépôt de cuivre résiduel reliant deux pistes qui ne devraient pas l'être → court-circuit
- **Interruptions** : piste gravée trop profond → circuit ouvert
- **Trous** : bien circulaires et centrés sur les pastilles

### Contrôle au multimètre

**Mode continuité (bip) :**
- Mesurer d'un bout à l'autre d'une piste → doit biper (résistance ≈ 0 Ω)
- Mesurer entre deux pastilles GND → doit biper

**Mode résistance (Ω) :**
- Mesurer entre deux pistes qui ne sont pas reliées → doit indiquer > 1 MΩ (infini)
- Si la résistance est faible (quelques Ω ou kΩ) : pont de cuivre → utiliser une lame ou un grattoir pour éliminer le pont

---

## 7. EPI et sécurité

| Risque | EPI / Précaution |
|--------|-----------------|
| Éclats de fibre de verre (FR4) | Lunettes de protection obligatoires |
| Bris de mèche sous pression | Vérifier le bridage, ne pas forcer |
| Vibrations et bruit | Ne pas laisser la machine sans surveillance |
| Poussières de FR4 (irritantes) | Aspiration si disponible, ne pas souffler avec la bouche |

> Le FR4 contient des fibres de verre en suspension dans une résine époxy. Les poussières sont irritantes pour les voies respiratoires et les yeux.
