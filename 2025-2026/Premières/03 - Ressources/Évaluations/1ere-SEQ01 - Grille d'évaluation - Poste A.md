---
type: évaluation
titre: "Grille d'évaluation — Poste A · Prototype et intégration capteur"
code: 1ere-SEQ01-EVA-A
séquence: "[[1ere-SEQ01 - Météo57 Phase 2]]"
séance: "[[1ere-SEQ01 - SÉA01 - Poste A — Prototype et intégration capteur]]"
classe: Première CIEL
compétences:
  - C07
  - C09
activités_pro:
  - E3
  - E4
statut: brouillon
---

# Grille d'évaluation — Poste A · Prototype et intégration capteur

> **Contexte d'évaluation :** Mise en situation professionnelle — Météo57
> L'élève assemble le nœud de mesure de la station météo : câblage du capteur DS18B20, fabrication d'un câble JST par sertissage, intégration de la chaîne d'alimentation solaire, configuration et téléversement du code, validation de la transmission de données.
>
> **Activités professionnelles :** E3 — Production et assemblage · E4 — Intégration matérielle et logicielle

---

| | |
|---|---|
| **Nom / Prénom** | |
| **Classe** | Première CIEL |
| **Date** | |
| **Enseignant** | |

---

> [!tip] Aménagements — élèves à besoins particuliers
> - **Tiers-temps** : la grille est identique — l'enseignant note l'avancement au moment de l'évaluation sans pénaliser le temps supplémentaire
> - **Reformulation** : les indicateurs peuvent être lus à voix haute ou reformulés
> - **Aide technique** : l'élève peut être guidé verbalement sur une étape sans que cela invalide l'évaluation des autres critères
> - **Rapport écrit** : si l'oral est difficile, l'élève peut répondre par écrit sur la fiche TP

---

## Légende

| Niveau | Code | Signification |
|--------|------|--------------|
| Non atteint | **NA** | Critère non observable ou objectif non réalisé |
| Partiellement atteint | **PA** | Réalisé avec aide significative ou résultat partiel |
| Atteint | **A** | Réalisé de façon autonome, résultat conforme |
| Dépassé | **D** | Réalisé avec maîtrise, capable d'expliquer et d'aider |

---

## C07 — Réaliser des maquettes et prototypes

*Critères du référentiel BO 2023 appliqués au contexte Météo57*

### Partie câblage et montage

| # | Indicateur observable (contextualisé) | Critère référentiel | NA | PA | A | D |
|---|---------------------------------------|--------------------|----|----|----|---|
| 1 | Le câblage DS18B20 est conforme au schéma de la fiche projet (VCC, GND, Data sur GPIO 4, pull-up 4,7 kΩ) | *La nomenclature des composants est respectée* | ☐ | ☐ | ☐ | ☐ |
| 2 | Aucun court-circuit ni erreur de polarité avant mise sous tension (vérification visuelle) | *Le contrôle visuel de la carte assemblée est conforme au dossier de fabrication* | ☐ | ☐ | ☐ | ☐ |
| 3 | La chaîne d'alimentation (panneau → TP4056 → batterie → ESP32) est correctement montée avec les bonnes polarités | *La nomenclature des composants est respectée* | ☐ | ☐ | ☐ | ☐ |

### Partie câble JST

| # | Indicateur observable (contextualisé) | Critère référentiel | NA | PA | A | D |
|---|---------------------------------------|--------------------|----|----|----|---|
| 4 | Le câble JST est fabriqué : contacts sertis, logés dans le boîtier (clic audible), résistance à la traction OK | *Le PCB est réalisé, contrôlé et conforme — finition de surface, propreté* | ☐ | ☐ | ☐ | ☐ |
| 5 | La procédure de sertissage est respectée (dénudage, sertissage isolation + conducteur, séquence correcte) | *Le travail est préparé de façon à satisfaire les exigences de qualité* | ☐ | ☐ | ☐ | ☐ |

### Qualité du travail et comportement professionnel

| # | Indicateur observable (contextualisé) | Critère référentiel | NA | PA | A | D |
|---|---------------------------------------|--------------------|----|----|----|---|
| 6 | L'élève identifie les risques (LiPo, polarité) et prend les précautions appropriées avant manipulation | *Les risques d'une situation de travail sont repérés et les mesures appropriées sont adoptées* | ☐ | ☐ | ☐ | ☐ |
| 7 | L'élève fournit l'effort nécessaire pour terminer la tâche dans le temps imparti, sans se décourager en cas de difficulté | *L'effort nécessaire est fourni afin de terminer et de réussir le travail demandé* | ☐ | ☐ | ☐ | ☐ |

**Sous-total C07 : ___ / 21**

---

## C09 — Installer les éléments d'un système électronique ou informatique

*Critères du référentiel BO 2023 appliqués au contexte Météo57*

### Installation et mise en service

| # | Indicateur observable (contextualisé) | Critère référentiel | NA | PA | A | D |
|---|---------------------------------------|--------------------|----|----|----|---|
| 8 | L'élève vérifie la liste du matériel avant de commencer (composants, câbles, outillage, code) | *L'ensemble des éléments pour l'installation du système est complet et vérifié par rapport au cahier des charges* | ☐ | ☐ | ☐ | ☐ |
| 9 | Les éléments sont assemblés en suivant la procédure de la fiche TP (ordre des étapes respecté) | *Les éléments du système sont installés et raccordés selon une procédure* | ☐ | ☐ | ☐ | ☐ |
| 10 | Le code est cloné, les paramètres réseau (SSID, IP serveur) sont correctement renseignés et téléversés | *La configuration est réalisée* | ☐ | ☐ | ☐ | ☐ |
| 11 | L'ESP32 est connecté au réseau et envoie des données de température cohérentes (valeur entre 15 et 35 °C) | *La mise en service est réalisée* | ☐ | ☐ | ☐ | ☐ |

### Compte-rendu et communication

| # | Indicateur observable (contextualisé) | Critère référentiel | NA | PA | A | D |
|---|---------------------------------------|--------------------|----|----|----|---|
| 12 | Les résultats sont renseignés dans la fiche TP (moniteur série, valeur de température, JSON reçu) | *L'état de l'installation est renseigné de manière écrite ou orale* | ☐ | ☐ | ☐ | ☐ |
| 13 | L'élève confirme avec le Poste B que les données sont bien reçues côté serveur (validation croisée) | *La mise en service est réalisée — résolution d'un problème en autonomie* | ☐ | ☐ | ☐ | ☐ |

### Résolution de problèmes

| # | Indicateur observable (contextualisé) | Critère référentiel | NA | PA | A | D |
|---|---------------------------------------|--------------------|----|----|----|---|
| 14 | En cas de problème (valeur −127°C, connexion WiFi refusée…), l'élève diagnostique et tente une correction par ses propres moyens avant de demander de l'aide | *La résolution d'un problème nouveau imprévu est réussie en utilisant ses propres moyens* | ☐ | ☐ | ☐ | ☐ |

**Sous-total C09 : ___ / 21**

---

## Évaluation des savoirs — Questions de synthèse

*(Issues de la fiche TP — à évaluer sur le document élève)*

| Question | Attendu | NA | PA | A |
|----------|---------|----|----|---|
| Q1 — Rôle de la résistance pull-up | Explique le fonctionnement open-drain du 1-Wire, conséquence si absente | ☐ | ☐ | ☐ |
| Q2 — Attribution d'adresse IP | Nomme le DHCP, identifie le routeur comme serveur DHCP | ☐ | ☐ | ☐ |
| Q3 — HTTP vs Bluetooth | Identifie HTTP comme protocole réseau TCP/IP, Bluetooth comme liaison courte portée sans infrastructure | ☐ | ☐ | ☐ |

**Sous-total Questions : ___ / 9**

---

## Récapitulatif

| Compétence | Points obtenus | Points max | Taux |
|------------|---------------|-----------|------|
| C07 | | 21 | % |
| C09 | | 21 | % |
| Questions de synthèse | | 9 | % |
| **Total** | | **51** | **%** |

### Positionnement global

| Compétence | Non atteint | Partiellement atteint | Atteint | Dépassé |
|------------|-------------|----------------------|---------|---------|
| C07 | < 7 pts | 7–10 pts | 11–17 pts | 18–21 pts |
| C09 | < 7 pts | 7–10 pts | 11–17 pts | 18–21 pts |

---

## Observations de l'enseignant

*(Comportement, points forts, points à travailler, incidents éventuels)*

&nbsp;

&nbsp;

&nbsp;

&nbsp;

---

**Signature enseignant :** _________________________ &emsp; **Date :** _____________
