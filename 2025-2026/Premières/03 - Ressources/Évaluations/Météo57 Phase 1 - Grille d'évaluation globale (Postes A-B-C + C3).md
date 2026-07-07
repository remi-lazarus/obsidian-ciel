---
type: évaluation
titre: "Grille d'évaluation globale — Météo57 Phase 1 (Postes A/B/C + C3)"
code: 1ere-METEO57-P1-EVA
classe: Première CIEL
compétences:
  - C07
  - C09
  - C10
  - C03
activités_pro:
  - D1
  - E1
  - E3
  - E4
  - R2
  - R3
statut: brouillon
---

# Grille d'évaluation globale — Météo57 Phase 1

> **Contexte d'évaluation :** Mise en situation professionnelle — Météo57
> Vous travaillez pour la société Météo57 en tant que technicien junior. Un nouveau projet de développement d'une station de mesure de température a été confié à votre équipe : implémenter la station de mesure, le système de collecte des données, et préparer la carte électronique qui les supportera.

> [!info] Organisation de la séance — 3 postes en parallèle
> Équipes de 3 élèves, chacun en charge d'un poste différent, travail simultané pendant la séance :
> - **Poste A** — Prototypage sur breadboard de la chaîne de relevé de température (ESP32 + DS18B20)
> - **Poste B** — Installation et configuration du serveur de collecte des données (Raspberry Pi)
> - **Poste C** — Prototypage de la carte électronique en CFAO (Fusion 360 Electronics)
>
> **Mode d'emploi de la grille :** cette grille sert à l'évaluation individuelle de chaque élève. Chaque élève est évalué sur **la section correspondant à son poste** (A, B ou C) **+ la section C3**, commune aux trois postes, qui porte sur le comportement en gestion de projet.

---

| | |
|---|---|
| **Nom / Prénom** | |
| **Classe** | Première CIEL |
| **Poste réalisé** | ☐ A &emsp; ☐ B &emsp; ☐ C |
| **Date** | |
| **Enseignant** | |

---

> [!tip] Aménagements — élèves à besoins particuliers
> - **Tiers-temps** : la grille est identique — l'enseignant note l'avancement au moment de l'évaluation sans pénaliser le temps supplémentaire
> - **Reformulation** : les indicateurs peuvent être lus à voix haute ou reformulés
> - **Aide technique** : un guidage verbal sur une étape (câblage, commande Linux, manipulation Fusion 360) est possible sans invalider l'évaluation des autres critères
> - **Support visuel** : les schémas et fiches cours peuvent rester accessibles pendant l'évaluation
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

## Poste A — Prototypage breadboard · Relevé de température

*À évaluer uniquement pour l'élève ayant occupé le Poste A. Première version du nœud de mesure (ESP32 + DS18B20 sur breadboard), avant la fabrication du PCB.*

### C07 — Réaliser des maquettes et prototypes

#### Montage du nœud de mesure

| #   | Indicateur observable (contextualisé)                                                                                                                          | Critère référentiel                                                                                                                           | NA  | PA  | A   | D   |
| --- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------- | --- | --- | --- | --- |
| A1  | Le câblage du capteur DS18B20 sur breadboard est conforme au schéma fourni (VCC → 3,3V, GND → GND, Data → GPIO4, résistance pull-up 4,7 kΩ entre Data et 3,3V) | *La nomenclature des composants est respectée*                                                                                                | ☐   | ☐   | ☐   | ☐   |
| A2  | Avant la mise sous tension, l'élève vérifie visuellement l'absence de court-circuit et le bon sens de câblage                                                  | *Le contrôle visuel de la carte assemblée est conforme au dossier de fabrication*                                                             | ☐   | ☐   | ☐   | ☐   |
| A3  | L'élève identifie les risques liés à la manipulation (décharge électrostatique, inversion de polarité) et prend les précautions appropriées                    | *Les risques d'une situation de travail sont repérés et les mesures appropriées pour sa santé, sa sécurité et celle des autres sont adoptées* | ☐   | ☐   | ☐   | ☐   |
| A4  | L'élève fournit l'effort nécessaire pour terminer le montage dans le temps imparti, sans se décourager en cas de difficulté                                    | *L'effort nécessaire est fourni afin de terminer et de réussir le travail demandé*                                                            | ☐   | ☐   | ☐   | ☐   |

**Sous-total C07 (Poste A) : ___ / 12**

### C09 — Installer les éléments d'un système électronique ou informatique

#### Mise en service et transmission des données

| #   | Indicateur observable (contextualisé)                                                                                                                               | Critère référentiel                                                                                                              | NA  | PA  | A   | D   |
| --- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------- | --- | --- | --- | --- |
| A5  | Le matériel nécessaire (ESP32, capteur, résistance, câbles, accès au code) est vérifié avant de commencer                                                           | *L'ensemble des éléments pour l'installation du système est complet et vérifié par rapport au cahier des charges*                | ☐   | ☐   | ☐   | ☐   |
| A6  | Le code est récupéré depuis le dépôt Git, les paramètres réseau (SSID, mot de passe) sont renseignés, et le programme est téléversé sur l'ESP32                     | *La configuration est réalisée*                                                                                                  | ☐   | ☐   | ☐   | ☐   |
| A7  | Le moniteur série confirme la connexion au réseau WiFi et affiche une valeur de température cohérente (entre 15 et 35 °C)                                           | *La mise en service est réalisée*                                                                                                | ☐   | ☐   | ☐   | ☐   |
| A8  | Les résultats observés (messages du moniteur série, valeur de température) sont renseignés dans la fiche TP                                                         | *L'état de l'installation est renseigné de manière écrite ou orale*                                                              | ☐   | ☐   | ☐   | ☐   |
| A9  | En cas de problème (température −127 °C, échec de connexion WiFi…), l'élève diagnostique et tente une correction par ses propres moyens avant de demander de l'aide | *La résolution d'un problème nouveau imprévu est réussie en utilisant ses propres moyens conformément aux règles de la fonction* | ☐   | ☐   | ☐   | ☐   |

**Sous-total C09 (Poste A) : ___ / 15**

---

## Poste B — Installation et configuration du serveur de collecte (Raspberry Pi)

*À évaluer uniquement pour l'élève ayant occupé le Poste B.*

### C09 — Installer les éléments d'un système électronique ou informatique

#### Préparation et mise en service du serveur

| #   | Indicateur observable (contextualisé)                                                                                                                                     | Critère référentiel                                                                                                              | NA  | PA  | A   | D   |
| --- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------- | --- | --- | --- | --- |
| B1  | Le matériel nécessaire (Raspberry Pi, alimentation, accès au réseau, accès au dépôt Git) est vérifié avant de commencer                                                   | *L'ensemble des éléments pour l'installation du système est complet et vérifié par rapport au cahier des charges*                | ☐   | ☐   | ☐   | ☐   |
| B2  | L'adresse IP fixe du Raspberry Pi (192.168.57.10) est configurée et vérifiée (`hostname -I` ou `ip addr`)                                                                 | *La configuration est réalisée*                                                                                                  | ☐   | ☐   | ☐   | ☐   |
| B3  | Le serveur Flask est cloné depuis le dépôt Git, lancé, et écoute sur `0.0.0.0:5000` (message de démarrage visible)                                                        | *La mise en service est réalisée*                                                                                                | ☐   | ☐   | ☐   | ☐   |
| B4  | La réception des données envoyées par l'ESP32 du Poste A est vérifiée (`curl http://192.168.57.10:5000/data` ou navigateur)                                               | *La mise en service est réalisée*                                                                                                | ☐   | ☐   | ☐   | ☐   |
| B5  | Les résultats des commandes exécutées (`ip addr`, `curl`, logs serveur) sont renseignés dans la fiche TP                                                                  | *L'état de l'installation est renseigné de manière écrite ou orale*                                                              | ☐   | ☐   | ☐   | ☐   |
| B6  | En cas de problème (serveur inaccessible, port déjà utilisé, dépendances manquantes…), l'élève diagnostique et corrige par ses propres moyens avant de demander de l'aide | *La résolution d'un problème nouveau imprévu est réussie en utilisant ses propres moyens conformément aux règles de la fonction* | ☐   | ☐   | ☐   | ☐   |

**Sous-total C09 (Poste B) : ___ / 18**

### C10 — Exploiter un réseau informatique

#### Exploitation du réseau et travail en équipe

| #   | Indicateur observable (contextualisé)                                                                                   | Critère référentiel                                                                                     | NA  | PA  | A   | D   |
| --- | ----------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------- | --- | --- | --- | --- |
| B7  | L'élève identifie les éléments du réseau (adresses IP, rôles des équipements) à partir du schéma fourni                 | *Les différents éléments d'un réseau ou d'un système à partir d'un schéma fourni sont identifiés*       | ☐   | ☐   | ☐   | ☐   |
| B8  | Des commandes Linux appropriées sont utilisées pour vérifier et diagnostiquer le réseau (`ip addr`, `ping`, `curl`)     | *Les lignes de commandes d'équipements sont mises en œuvre sur systèmes d'exploitation UNIX et Windows* | ☐   | ☐   | ☐   | ☐   |
| B9  | Les paramètres réseau nécessaires (SSID, mot de passe, adresse IP du serveur) sont communiqués proactivement au Poste A | *Le travail en équipe est conduit de manière solidaire en contribuant par des idées et des efforts*     | ☐   | ☐   | ☐   | ☐   |

**Sous-total C10 (Poste B) : ___ / 9**

---

## Poste C — Prototypage de la carte électronique en CFAO (Fusion 360 Electronics)

*À évaluer uniquement pour l'élève ayant occupé le Poste C. Conception électronique préparatoire à la fabrication du PCB (Phase 2).*

### C07 — Réaliser des maquettes et prototypes

#### Conception électronique et préparation à la fabrication

| #   | Indicateur observable (contextualisé)                                                                                                                    | Critère référentiel                                                                                   | NA  | PA  | A   | D   |
| --- | -------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------- | --- | --- | --- | --- |
| C1  | Le schéma électronique est saisi dans Fusion 360 Electronics conformément au schéma de référence (composants, références, connexions correctes)          | *Le placement et routage sont conformes au cahier des charges*                                        | ☐   | ☐   | ☐   | ☐   |
| C2  | Les empreintes des composants sont placées sur le PCB de façon cohérente, en respectant les dimensions de la carte définies dans le cahier des charges   | *Le placement et routage sont conformes au cahier des charges*                                        | ☐   | ☐   | ☐   | ☐   |
| C3  | Le routage des pistes est réalisé sans erreur de Design Rule Check (DRC) — aucune connexion manquante ni court-circuit                                   | *Le placement et routage sont conformes au cahier des charges*                                        | ☐   | ☐   | ☐   | ☐   |
| C4  | Les fichiers de fabrication (Gerber, fichier de perçage) sont générés et exportés conformément aux attentes, prêts pour la fabrication en phase suivante | *La génération des fichiers de fabrication du PCB est conforme aux attentes*                          | ☐   | ☐   | ☐   | ☐   |
| C5  | L'élève organise son travail (sauvegardes régulières, nommage clair des fichiers/projets) de façon à satisfaire les exigences de qualité et d'échéancier | *Le travail est préparé de façon à satisfaire les exigences de qualité, d'efficacité et d'échéancier* | ☐   | ☐   | ☐   | ☐   |
| C6  | L'élève fournit l'effort nécessaire pour aboutir, en fin de séance, à un fichier de conception exploitable                                               | *L'effort nécessaire est fourni afin de terminer et de réussir le travail demandé*                    | ☐   | ☐   | ☐   | ☐   |

**Sous-total C07 (Poste C) : ___ / 18**

---

## C3 — Participer à un projet *(commun aux 3 postes)*

*Cette section est évaluée pour **tous les élèves**, quel que soit leur poste. Elle porte sur le comportement en gestion de projet observé pendant la séance.*

| #   | Indicateur observable (contextualisé)                                                                                                                  | Critère référentiel                                                                                                                                               | NA  | PA  | A   | D   |
| --- | ------------------------------------------------------------------------------------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------- | --- | --- | --- | --- |
| P1  | L'élève identifie son poste (A, B ou C) ainsi que le rôle des deux autres postes de son équipe dans la réalisation du projet Météo57                   | *Les rôles et tâches de chacun sont identifiés*                                                                                                                   | ☐   | ☐   | ☐   | ☐   |
| P2  | Le planning prévisionnel de la séance (durée, étapes, moments de coordination avec les autres postes) est compris                                      | *Le planning prévisionnel est compris*                                                                                                                            | ☐   | ☐   | ☐   | ☐   |
| P3  | Le déroulement de la fiche TP est suivi dans l'ordre prévu, sans sauter d'étape                                                                        | *Le suivi du projet est respecté*                                                                                                                                 | ☐   | ☐   | ☐   | ☐   |
| P4  | Le dépôt Git du projet (espace collaboratif) est correctement utilisé : clonage, navigation dans les fichiers, récupération de la bonne version        | *L'espace collaboratif est correctement utilisé*                                                                                                                  | ☐   | ☐   | ☐   | ☐   |
| P5  | Face à une difficulté imprévue, l'élève décide d'actions appropriées (recherche documentaire, test, demande d'aide ciblée) plutôt que de rester bloqué | *Face à un ensemble de faits, des actions appropriées à poser sont décidées*                                                                                      | ☐   | ☐   | ☐   | ☐   |
| P6  | Face aux difficultés rencontrées, l'élève reste calme et persévère jusqu'à obtenir un résultat, sans se décourager                                     | *Le calme est conservé de façon constante dans des situations particulières, tout en persévérant dans la tâche jusqu'à l'atteinte du résultat sans se décourager* | ☐   | ☐   | ☐   | ☐   |
| P7  | L'élève observe avec attention l'avancement de son propre travail et de celui de son équipe, pour s'assurer que le résultat attendu est atteint        | *Le déroulement des tâches de travail est observé avec attention et de façon soutenue de façon à en contrôler le résultat attendu*                                | ☐   | ☐   | ☐   | ☐   |

**Sous-total C03 : ___ / 21**

---

## Récapitulatif et positionnement global

> Ne remplir que la ou les lignes correspondant au poste réalisé par l'élève, ainsi que la ligne C03 (toujours évaluée).

| Poste | Compétence | Points obtenus | Points max | Taux |
|-------|------------|----------------|------------|------|
| A | C07 | | 12 | % |
| A | C09 | | 15 | % |
| B | C09 | | 18 | % |
| B | C10 | | 9 | % |
| C | C07 | | 18 | % |
| Tous | **C03** | | **21** | % |

### Positionnement par compétence

| Compétence (poste, /max) | Non atteint | Partiellement atteint | Atteint | Dépassé |
|---------------------------|-------------|------------------------|---------|---------|
| C07 — Poste A (/12) | < 4 pts | 4–6 pts | 7–10 pts | 11–12 pts |
| C09 — Poste A (/15) | < 5 pts | 5–7 pts | 8–12 pts | 13–15 pts |
| C09 — Poste B (/18) | < 6 pts | 6–9 pts | 10–15 pts | 16–18 pts |
| C10 — Poste B (/9) | < 3 pts | 3–4 pts | 5–7 pts | 8–9 pts |
| C07 — Poste C (/18) | < 6 pts | 6–9 pts | 10–15 pts | 16–18 pts |
| C03 (/21) | < 7 pts | 7–10 pts | 11–17 pts | 18–21 pts |

---

## Observations de l'enseignant

*(Comportement, points forts, points à travailler, incidents éventuels, qualité de la coordination avec les autres postes de l'équipe)*

&nbsp;

&nbsp;

&nbsp;

&nbsp;

---

**Signature enseignant :** _________________________ &emsp; **Date :** _____________
