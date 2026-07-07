---
type: séance
titre: "Poste C — Fabrication PCB sur Technodrill 3"
code: 1ere-SEQ01-SÉA03
séquence: "[[1ere-SEQ01 - Météo57 Phase 2]]"
classe: Première CIEL
date: 
durée_minutes: 240
compétences:
  - C07
type_séance: TP
statut: brouillon
poste: C
parallèle_avec:
  - "[[1ere-SEQ01 - SÉA01 - Poste A — Prototype et intégration capteur]]"
  - "[[1ere-SEQ01 - SÉA02 - Poste B — Réseau et serveur]]"
---

# Poste C — Fabrication PCB sur Technodrill 3

> [!info] Organisation de la séance
> Cette séance se déroule **en parallèle** avec les postes A et B au sein de chaque équipe. L'élève du poste C est **en binôme avec l'élève du Poste A** pendant les temps de fonctionnement automatique de la CNC (~30 min). Il y a **une seule CNC** dans l'atelier — les 5 équipes se coordonnent avec l'enseignant pour l'accès machine. La séance dure **4 heures**.

## 🎯 Objectif de la séance

À l'issue de cette séance, l'élève sera capable d'importer des fichiers Gerber dans GALAAD 3, de paramétrer et lancer une opération de fraisage sur la Technodrill 3, et de contrôler la qualité du PCB fabriqué par mesure de continuité et d'isolation.

## 🔗 Contexte dans la séquence

Séance appartenant à → [[1ere-SEQ01 - Météo57 Phase 2]]

> **Mise en situation professionnelle — TechMétéo57**
> Tu es technicien en fabrication. Les fichiers Gerber du PCB Météo57 ont été validés par l'équipe conception. Ta mission : transformer ces fichiers numériques en un circuit imprimé physique prêt à être câblé. C'est la même chaîne numérique (Fusion 360 → Gerber → CNC) que celle utilisée dans les bureaux d'études industriels.

## ⏱️ Déroulé pédagogique

| Phase | Activité | Durée | Mode |
|-------|----------|-------|------|
| Lancement | Présentation des 3 postes, distribution des rôles, EPI | 15 min | Collectif |
| Import Gerber | Import des fichiers dans GALAAD 3, vérification de l'aperçu | 30 min | Individuel |
| Paramétrage usinage | Réglage des vitesses, profondeurs, zéro pièce | 25 min | Individuel + Prof |
| Bridage & lancement | Bridage du PCB, lancement de la gravure | 15 min | Individuel + Prof |
| Binôme CNC (temps machine) | Aide au Poste A pendant le fraisage automatique | 30 min | Binôme C+A |
| Perçage | Changement d'outil, lancement des perçages | 20 min | Individuel + Prof |
| Contrôle qualité | Nettoyage, contrôle visuel, mesure continuité/isolation | 30 min | Individuel |
| Analyse et bilan | Comparaison PCB fabriqué / fichier numérique, questions de synthèse | 20 min | Individuel |
| Bilan | Remplissage de la fiche de résultats | 15 min | Individuel |

> [!warning] Accès CNC
> La Technodrill 3 est partagée entre les 5 équipes. Un planning d'accès est géré par l'enseignant. Se préparer en avance (import + paramétrage) pour optimiser son créneau machine.

## 📋 Contenu

### Mise en situation

Le bureau d'études a livré les fichiers Gerber. À toi de les convertir en un PCB réel. La qualité de ton travail conditionne le montage des composants par l'équipe — un pont entre deux pistes ou une piste interrompue, et c'est tout le prototype qui ne fonctionnera pas.

### Activité élève

#### Étape 1 — Import des fichiers Gerber dans GALAAD 3

Les fichiers Gerber sont disponibles dans le dépôt Git du projet :
```
git@github.com:remi-lazarus/projet-station-mesure.git
```

Fichiers à récupérer dans le dossier `gerber/` :
- `meteo57.gtl` — cuivre top (pistes)
- `meteo57.drl` — fichier de perçage (Excellon)

**Procédure d'import dans GALAAD 3 :**
1. Lancer GALAAD 3
2. `Fichier > Importer > Gerber RS-274X`
3. Sélectionner `meteo57.gtl`
4. Vérifier l'aperçu : les pistes et pastilles doivent être visibles et correctement orientées
5. `Fichier > Importer > Perçage Excellon`
6. Sélectionner `meteo57.drl`

**Question 1 :** Qu'est-ce qu'un fichier Gerber ? Quel logiciel l'a généré dans notre cas ?

*(Espace réponse)*

> [!warning] Orientation du PCB
> Vérifier que le PCB est dans le bon sens (cuivre visible, pas en miroir). En cas de doute, comparer avec la capture d'écran de référence fournie par l'enseignant.

---

#### Étape 2 — Paramétrage de l'usinage

Renseigner les paramètres suivants dans GALAAD 3 avant de lancer l'usinage :

**Gravure des pistes (isolation) :**

| Paramètre | Valeur |
|-----------|--------|
| Outil | V-bit 30° Ø 0,1 mm |
| Vitesse broche | 20 000 tr/min |
| Vitesse d'avance | 300 mm/min |
| Profondeur de passe | −0,1 mm |

**Perçage des composants :**

| Paramètre | Valeur |
|-----------|--------|
| Outil | Foret Ø 0,8 mm (ou 1,0 mm selon composants) |
| Vitesse broche | 15 000 tr/min |
| Vitesse d'avance | 200 mm/min |
| Profondeur | Traversant |

> [!info] Pourquoi ces paramètres ?
> La fibre de verre (FR4) est abrasive — trop vite = bris de mèche, trop lent = brûlure. Ces valeurs sont issues des recommandations fabricant pour les outils disponibles.

**Question 2 :** Qu'est-ce que la vitesse d'avance ? En quoi est-elle différente de la vitesse de rotation de la broche ?

*(Espace réponse)*

---

#### Étape 3 — Mise à zéro et bridage du PCB

> [!danger] Étape critique — ne pas faire seul la première fois
> Appeler l'enseignant pour valider la mise à zéro Z et le bridage avant de lancer la machine.

**Procédure de mise à zéro Z :**
1. Placer une feuille de papier entre la pointe de l'outil et la surface du PCB
2. Descendre l'outil manuellement (pas à pas, 0,1 mm) jusqu'à ce que la feuille résiste légèrement au glissement
3. Valider le zéro Z dans GALAAD

**Bridage du PCB :**
- Positionner le PCB vierge sur le plateau
- Fixer avec les brides latérales — **le PCB ne doit pas bouger d'un millimètre**
- Vérifier la planéité (pas de bombe, pas de jeu sous le PCB)

---

#### Étape 4 — Lancement de la gravure

1. Valider l'aperçu du parcours outil dans GALAAD (simulation visuelle)
2. S'assurer que personne ne se trouve dans la zone de travail
3. Mettre les **lunettes de protection**
4. Lancer la gravure
5. **Ne pas quitter la machine des yeux** pendant l'usinage

Pendant le fonctionnement automatique (~30 min) → rejoindre le **Poste A** pour avancer sur l'assemblage du prototype (binôme C+A).

---

#### Étape 5 — Perçage

Après la gravure :
1. Changer l'outil (foret Ø 0,8 mm)
2. Refaire la mise à zéro Z avec le nouveau foret
3. Lancer le perçage

---

#### Étape 6 — Contrôle qualité

**Contrôle visuel (à l'œil nu ou à la loupe) :**
- [ ] Pas de pont de cuivre entre deux pistes adjacentes
- [ ] Pistes continues, sans interruption
- [ ] Pastilles bien centrées sur les trous
- [ ] Bords du PCB nets (pas d'éclats importants)

**Contrôle au multimètre :**

| Test | Mode | Attendu |
|------|------|---------|
| Continuité d'une piste (d'un bout à l'autre) | Continuité (bip) | Bip = OK |
| Isolation entre deux pistes adjacentes | Résistance | > 1 MΩ |
| Continuité GND général | Continuité | Bip sur toutes les pastilles GND |

**Question 3 :** Tu trouves une résistance de 10 Ω entre deux pistes qui ne devraient pas être reliées. Qu'est-ce que cela indique ? Comment y remédier ?

*(Espace réponse)*

---

#### Comparaison numérique / physique

Comparer le PCB fabriqué avec l'aperçu GALAAD :
- Toutes les pistes sont-elles présentes ?
- Les dimensions sont-elles conformes ?
- Les trous correspondent-ils aux empreintes des composants prévus ?

**Question 4 :** Cite deux avantages de la fabrication PCB par fraisage CNC par rapport à une plaque d'essai (breadboard ou perfboard).

*(Espace réponse)*

### Éléments de correction / Points de vigilance

| Étape | Erreur fréquente | Cause | Remédiation |
|-------|-----------------|-------|-------------|
| Import Gerber | PCB en miroir | Fichier top/bottom inversé | Réimporter le bon fichier |
| Zéro Z | Pistes trop profondes ou trop peu gravées | Mauvaise mise à zéro | Recommencer avec une chute de PCB |
| Bridage | PCB bouge pendant l'usinage | Serrage insuffisant | Toujours 2 brides minimum |
| Gravure | Bris de mèche | Avance trop rapide ou zéro Z trop bas | Réduire avance de 20% |
| Perçage | Trous décalés | Changement d'outil sans recalage | Toujours refaire le zéro Z après changement d'outil |

## 📦 Ressources

- [ ] Énoncé TP : [[TP — Poste C — Fabrication PCB sur Technodrill 3]]
- [ ] Support cours : [[Cours — Fabrication PCB par fraisage CNC]]
- [ ] Grille d'évaluation : [[1ere-SEQ01 - Grille d'évaluation - Poste C]]
- [ ] Fiche projet technique : [[Projets/Météo57 Phase 2/01 - Cahier des charges/Fiche projet]]
- [ ] Matériel : PCB vierge FR4 simple face, V-bit 30° Ø 0,1 mm, foret Ø 0,8 mm, brides, Technodrill 3
- [ ] Logiciel : GALAAD 3, accès Git
- [ ] EPI obligatoires : lunettes de protection

## ✅ Critères de réussite

- [ ] Fichiers Gerber importés correctement dans GALAAD (aperçu validé par l'enseignant)
- [ ] Paramètres d'usinage corrects (validés avant lancement)
- [ ] PCB gravé : contrôle visuel OK
- [ ] Continuité des pistes vérifiée au multimètre
- [ ] Isolation entre pistes vérifiée au multimètre (> 1 MΩ)
- [ ] Questions 1, 2, 3 et 4 renseignées

## 🔀 Différenciation

> [!help] Aide — si l'import Gerber pose problème
> Demander à l'enseignant de valider l'aperçu GALAAD avant de lancer. Une capture d'écran de référence est disponible. Ne pas lancer la machine sans validation.

> [!success] Approfondissement — si tu termines en avance
> Mesurer les **largeurs de pistes** fabriquées avec un pied à coulisse et les comparer aux valeurs théoriques du fichier Gerber. Calculer l'écart en pourcentage et rédiger une courte analyse.

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
