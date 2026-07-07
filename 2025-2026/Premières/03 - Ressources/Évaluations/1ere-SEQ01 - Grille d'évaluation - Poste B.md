---
type: évaluation
titre: "Grille d'évaluation — Poste B · Réseau et serveur"
code: 1ere-SEQ01-EVA-B
séquence: "[[1ere-SEQ01 - Météo57 Phase 2]]"
séance: "[[1ere-SEQ01 - SÉA02 - Poste B — Réseau et serveur]]"
classe: Première CIEL
compétences:
  - C09
  - C10
activités_pro:
  - R2
  - R3
statut: brouillon
---

# Grille d'évaluation — Poste B · Réseau et serveur

> **Contexte d'évaluation :** Mise en situation professionnelle — Météo57
> L'élève configure un réseau WiFi local isolé (VLAN dédié, sans accès internet), déploie un serveur Flask sur Raspberry Pi, vérifie la réception des données de température depuis l'ESP32, et rend compte de l'état de l'infrastructure.
>
> **Activités professionnelles :** R2 — Installation et qualification · R3 — Exploitation et maintien en condition opérationnelle

---

| | |
|---|---|
| **Nom / Prénom** | |
| **Classe** | Première CIEL |
| **Date** | |
| **Enseignant** | |

---

> [!tip] Aménagements — élèves à besoins particuliers
> - **Tiers-temps** : la grille est identique — évaluation de l'état au moment de l'observation, sans pénalité liée au temps
> - **Reformulation** : les indicateurs peuvent être lus ou reformulés oralement
> - **Aide technique** : un guidage verbal sur la syntaxe d'une commande Linux est possible sans invalider l'évaluation de la compréhension globale
> - **Support visuel** : le schéma réseau de la fiche cours peut rester accessible pendant l'évaluation

---

## Légende

| Niveau | Code | Signification |
|--------|------|--------------|
| Non atteint | **NA** | Critère non observable ou objectif non réalisé |
| Partiellement atteint | **PA** | Réalisé avec aide significative ou résultat partiel |
| Atteint | **A** | Réalisé de façon autonome, résultat conforme |
| Dépassé | **D** | Réalisé avec maîtrise, capable d'expliquer et d'aider |

---

## C09 — Installer les éléments d'un système électronique ou informatique

*Critères du référentiel BO 2023 appliqués au contexte Météo57*

### Préparation et installation

| # | Indicateur observable (contextualisé) | Critère référentiel | NA | PA | A | D |
|---|---------------------------------------|--------------------|----|----|----|---|
| 1 | L'élève identifie et vérifie le matériel nécessaire avant de commencer (RPi, routeur, câbles, accès Git) | *L'ensemble des éléments pour l'installation du système est complet et vérifié par rapport au cahier des charges* | ☐ | ☐ | ☐ | ☐ |
| 2 | Le routeur est configuré selon la procédure : SSID `meteo57`, 2,4 GHz, DHCP 192.168.57.x, WAN désactivé | *Les éléments du système sont installés et raccordés selon une procédure* | ☐ | ☐ | ☐ | ☐ |
| 3 | L'adresse IP fixe `192.168.57.10` est configurée sur le Raspberry Pi et vérifiée (`hostname -I`) | *La configuration est réalisée* | ☐ | ☐ | ☐ | ☐ |
| 4 | Le serveur Flask est démarré et écoute sur `0.0.0.0:5000` (message de démarrage visible) | *La mise en service est réalisée* | ☐ | ☐ | ☐ | ☐ |
| 5 | Les données de température sont reçues depuis l'ESP32 du Poste A et lisibles via `curl` ou navigateur | *La mise en service est réalisée* | ☐ | ☐ | ☐ | ☐ |

### Compte-rendu et communication

| # | Indicateur observable (contextualisé) | Critère référentiel | NA | PA | A | D |
|---|---------------------------------------|--------------------|----|----|----|---|
| 6 | Les résultats des commandes (`ping`, `curl`, `hostname -I`) sont renseignés dans la fiche TP | *L'état de l'installation est renseigné de manière écrite ou orale* | ☐ | ☐ | ☐ | ☐ |
| 7 | L'élève communique proactivement les paramètres réseau au Poste A (SSID, mot de passe, IP) | *Le travail est effectué selon les attentes exprimées de temps, de quantité ou de qualité* | ☐ | ☐ | ☐ | ☐ |

### Résolution de problèmes

| # | Indicateur observable (contextualisé) | Critère référentiel | NA | PA | A | D |
|---|---------------------------------------|--------------------|----|----|----|---|
| 8 | En cas de problème (serveur inaccessible, IP non attribuée…), l'élève diagnostique et tente une action corrective avant de demander de l'aide | *La résolution d'un problème nouveau imprévu est réussie en utilisant ses propres moyens* | ☐ | ☐ | ☐ | ☐ |

**Sous-total C09 : ___ / 24**

---

## C10 — Exploiter un réseau informatique

*Critères du référentiel BO 2023 appliqués au contexte Météo57*

### Identification et exploitation du réseau

| # | Indicateur observable (contextualisé) | Critère référentiel | NA | PA | A | D |
|---|---------------------------------------|--------------------|----|----|----|---|
| 9 | L'élève identifie correctement les éléments du réseau sur le schéma de la fiche TP (IP, rôles, flux) | *Les différents éléments d'un réseau ou d'un système à partir d'un schéma fourni sont identifiés* | ☐ | ☐ | ☐ | ☐ |
| 10 | L'élève utilise des commandes Linux appropriées pour vérifier et diagnostiquer le réseau (`ip addr`, `ping`, `curl`) | *Les lignes de commandes d'équipements sont mises en œuvre sur systèmes d'exploitation UNIX* | ☐ | ☐ | ☐ | ☐ |
| 11 | Les alertes et incidents (ESP32 non connecté, erreur Flask, IP conflictuelle) sont renseignés dans la fiche TP avec les actions correctives menées | *Les alertes et problèmes rencontrés sont renseignés* | ☐ | ☐ | ☐ | ☐ |

### Travail en équipe et contribution

| # | Indicateur observable (contextualisé) | Critère référentiel | NA | PA | A | D |
|---|---------------------------------------|--------------------|----|----|----|---|
| 12 | L'élève coordonne efficacement avec les Postes A et C (partage des paramètres réseau, confirmation de réception des données) | *Le travail en équipe est conduit de manière solidaire en contribuant par des idées et des efforts* | ☐ | ☐ | ☐ | ☐ |
| 13 | L'élève prépare et organise son travail pour que l'infrastructure soit opérationnelle avant que le Poste A ait fini son câblage | *Le travail est préparé de façon à satisfaire les exigences de qualité, d'efficacité et d'échéancier* | ☐ | ☐ | ☐ | ☐ |

**Sous-total C10 : ___ / 15**

---

## Évaluation des savoirs — Questions de synthèse

*(Issues de la fiche TP — à évaluer sur le document élève)*

| Question | Attendu | NA | PA | A |
|----------|---------|----|----|---|
| Q1 — Définition du VLAN | Réseau logique isolé sur une infrastructure physique partagée — isolation du trafic, exemple industriel | ☐ | ☐ | ☐ |
| Q2 — `0.0.0.0` vs `127.0.0.1` | `0.0.0.0` = toutes interfaces (accessible réseau), `127.0.0.1` = local uniquement | ☐ | ☐ | ☐ |
| Q3 — Fréquence d'envoi ESP32 | Valeur cohérente observée dans les logs (ex. toutes les 10 s), méthode d'observation décrite | ☐ | ☐ | ☐ |
| Q4 — Test de robustesse WiFi | Observation correcte (perte de données pendant la coupure, reconnexion automatique), explication du mécanisme | ☐ | ☐ | ☐ |

**Sous-total Questions : ___ / 12**

---

## Récapitulatif

| Compétence | Points obtenus | Points max | Taux |
|------------|---------------|-----------|------|
| C09 | | 24 | % |
| C10 | | 15 | % |
| Questions de synthèse | | 12 | % |
| **Total** | | **51** | **%** |

### Positionnement global

| Compétence | Non atteint | Partiellement atteint | Atteint | Dépassé |
|------------|-------------|----------------------|---------|---------|
| C09 | < 8 pts | 8–12 pts | 13–20 pts | 21–24 pts |
| C10 | < 5 pts | 5–7 pts | 8–12 pts | 13–15 pts |

---

## Observations de l'enseignant

*(Comportement, points forts, points à travailler, incidents réseau éventuels)*

&nbsp;

&nbsp;

&nbsp;

&nbsp;

---

**Signature enseignant :** _________________________ &emsp; **Date :** _____________
