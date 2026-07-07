---
type: tp-élève
titre: "Poste C — Fabrication PCB sur Technodrill 3"
séance: "[[1ere-SEQ01 - SÉA03 - Poste C — Fabrication PCB sur Technodrill 3]]"
séquence: "[[1ere-SEQ01 - Météo57 Phase 2]]"
classe: Première CIEL
compétences:
  - C07
durée_minutes: 240
---

# TP — Poste C · Fabrication PCB sur Technodrill 3

---

> **Ta mission :** Tu es technicien fabrication. Les fichiers Gerber du circuit imprimé Météo57 ont été validés par le bureau d'études. Ta mission : transformer ces fichiers numériques en un PCB physique prêt à être câblé. La qualité de ton travail conditionne l'ensemble du prototype.

---

> [!danger] EPI obligatoires pour toute la séance
> ☐ Lunettes de protection portées pendant l'usinage
> Ne jamais laisser la machine sans surveillance pendant le fraisage.

---

## ✅ Suivi d'avancement

- [ ] Étape 1 — Import des fichiers Gerber dans GALAAD 3
- [ ] Étape 2 — Paramétrage de l'usinage
- [ ] Étape 3 — Mise à zéro et bridage (avec l'enseignant)
- [ ] Étape 4 — Fraisage (gravure + perçage)
- [ ] Étape 5 — Contrôle qualité
- [ ] Questions complétées

---

## Étape 1 — Import des fichiers Gerber dans GALAAD 3

### 1.1 Récupérer les fichiers

Cloner le dépôt Git et localiser les fichiers Gerber :

```bash
git clone git@github.com:remi-lazarus/projet-station-mesure.git
```

Chemin des fichiers Gerber dans le dépôt : _________________________________

Fichiers à utiliser :

| Fichier | Extension | Contenu |
|---------|-----------|---------|
| `meteo57.___` | `.gtl` | Cuivre — pistes et pastilles |
| `meteo57.___` | `.drl` | Perçages |

### 1.2 Import dans GALAAD 3

Suivre la procédure :
1. `Fichier > Importer > Gerber RS-274X` → sélectionner `meteo57.gtl`
2. `Fichier > Importer > Perçage Excellon` → sélectionner `meteo57.drl`

Dans l'aperçu GALAAD, je vois (décris ce que tu observes) :

&nbsp;

&nbsp;

Le PCB est-il dans le bon sens (cuivre visible, pas en miroir) ? ☐ Oui  ☐ Non

> [!warning] STOP — Validation enseignant
> ☐ Aperçu GALAAD validé par l'enseignant avant de continuer

---

## ❓ Question 1

**Qu'est-ce qu'un fichier Gerber ? Quel logiciel a généré ce fichier dans notre projet ? Quel est le rôle du fichier `.drl` ?**

*(3 à 5 lignes)*

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

---

## Étape 2 — Paramétrage de l'usinage

### 2.1 Paramètres de gravure (isolation des pistes)

Renseigne les paramètres dans GALAAD 3 :

| Paramètre | Valeur à saisir | Saisi ✓ |
|-----------|----------------|---------|
| Outil | V-bit 30° Ø 0,1 mm | ☐ |
| Vitesse broche | 20 000 tr/min | ☐ |
| Vitesse d'avance | 300 mm/min | ☐ |
| Profondeur de passe | −0,1 mm | ☐ |

### 2.2 Paramètres de perçage

| Paramètre | Valeur à saisir | Saisi ✓ |
|-----------|----------------|---------|
| Outil | Foret Ø 0,8 mm (ou 1,0 mm) | ☐ |
| Vitesse broche | 15 000 tr/min | ☐ |
| Vitesse d'avance | 200 mm/min | ☐ |
| Profondeur | Traversant | ☐ |

---

## ❓ Question 2

**Quelle est la différence entre la vitesse d'avance et la vitesse de rotation de la broche ? Quelles sont les conséquences si la vitesse d'avance est trop élevée ?**

&nbsp;

&nbsp;

&nbsp;

&nbsp;

---

## Étape 3 — Mise à zéro Z et bridage

> [!danger] Cette étape se fait obligatoirement avec l'enseignant.

### 3.1 Mise à zéro Z

Méthode utilisée : feuille de papier entre l'outil et le PCB.

Étapes réalisées (cocher au fur et à mesure) :
- [ ] Placer la feuille de papier sous la pointe de l'outil
- [ ] Descendre l'outil pas à pas (0,1 mm) jusqu'à résistance légère
- [ ] Valider le zéro Z dans GALAAD
- [ ] Retirer la feuille

### 3.2 Bridage du PCB

- [ ] PCB positionné sur le plateau
- [ ] Brides latérales serrées (minimum 2 brides)
- [ ] Vérification planéité : pas de jeu sous le PCB
- [ ] Test de traction manuel : le PCB ne bouge pas

> [!warning] STOP — Validation enseignant avant lancement
> ☐ Mise à zéro Z validée
> ☐ Bridage validé

---

## Étape 4 — Fraisage

### 4.1 Gravure des pistes

- [ ] Simulation du parcours outil vérifiée dans GALAAD
- [ ] Zone de travail dégagée — personne dans la zone
- [ ] Lunettes de protection portées
- [ ] Gravure lancée

**Pendant le temps de fraisage automatique → rejoindre le Poste A** pour aider à l'assemblage du prototype (binôme C+A).

Durée du fraisage : _______ min

Ce que j'ai fait pendant ce temps (binôme Poste A) :

&nbsp;

&nbsp;

### 4.2 Perçage

Après retour de la gravure :
- [ ] Changer l'outil (foret Ø 0,8 mm)
- [ ] Refaire la mise à zéro Z avec le nouveau foret (enseignant)
- [ ] Lancer le perçage

---

## Étape 5 — Contrôle qualité

### 5.1 Contrôle visuel

Nettoyer le PCB à l'air comprimé, puis inspecter à l'œil nu (loupe si disponible).

| Critère | OK ✓ | Problème observé |
|---------|------|-----------------|
| Pas de pont de cuivre entre pistes adjacentes | ☐ | |
| Pistes continues, sans interruption | ☐ | |
| Pastilles centrées sur les trous | ☐ | |
| Bords nets, pas d'éclats importants | ☐ | |

### 5.2 Contrôle au multimètre

Régler le multimètre en mode **continuité** (symbole ))) ou bip).

**Test de continuité d'une piste :**

| Piste testée (départ → arrivée) | Bip ? | Résultat |
|---------------------------------|-------|---------|
| | ☐ Oui  ☐ Non | ☐ OK  ☐ Interrompue |
| | ☐ Oui  ☐ Non | ☐ OK  ☐ Interrompue |
| | ☐ Oui  ☐ Non | ☐ OK  ☐ Interrompue |

Régler le multimètre en mode **résistance** (Ω).

**Test d'isolation entre 2 pistes adjacentes :**

| Pistes testées | Résistance mesurée | Résultat |
|----------------|-------------------|---------|
| | Ω | ☐ > 1 MΩ ✓  ☐ Pont ✗ |
| | Ω | ☐ > 1 MΩ ✓  ☐ Pont ✗ |

---

## ❓ Question 3

**Tu mesures une résistance de 10 Ω entre deux pistes qui ne devraient pas être reliées. Qu'est-ce que cela indique ? Comment peux-tu y remédier ?**

&nbsp;

&nbsp;

&nbsp;

---

## ❓ Question 4

**Cite deux avantages de la fabrication d'un PCB par fraisage CNC par rapport à une plaque d'essai (breadboard ou perfboard). Cite aussi une limite.**

| | Avantage / Limite |
|---|---|
| Avantage 1 | |
| Avantage 2 | |
| Limite | |

---

## Comparaison numérique / physique

Compare le PCB fabriqué avec l'aperçu GALAAD :

| Élément | Conforme ? | Observation |
|---------|------------|-------------|
| Nombre de pistes | ☐ Oui  ☐ Non | |
| Dimensions générales | ☐ Oui  ☐ Non | |
| Diamètre des trous | ☐ Oui  ☐ Non | |

