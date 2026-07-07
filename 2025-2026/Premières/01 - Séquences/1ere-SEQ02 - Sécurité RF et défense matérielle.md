---
type: séquence
titre: Sécurité RF et défense matérielle — Durcir la station connectée
code: 1ere-SEQ02
classe: Première CIEL
trimestre: T2
période: 
durée_heures: 13
activite_pro: D3 — Gestion d'incidents
compétences:
  - C04
  - C06
savoirs:
  - Cybersécurité et réglementation
  - Électronique matérielle et mesure
statut: brouillon
fil_rouge: Météo57
---

# Sécurité RF et défense matérielle — Durcir la station connectée

> [!warning] Cadre légal et éthique — à poser dès la SÉA01
> **Construire, détenir ou utiliser un brouilleur radio est un délit en France** (Code des postes et des communications électroniques, art. **L.33-3-1**), sanctionné par l'**ANFR**. Un brouilleur réalise un **déni de service sur la couche radio** : il déborde toujours sur le voisinage (secours, réseaux légitimes…).
> **Cette séquence ne fabrique aucun émetteur de brouillage.** On démontre la menace par **réception passive** (analyse de spectre) et par **simulation**, et on travaille la **contre-mesure matérielle** (blindage, cage de Faraday). C'est exactement la posture du technicien en cybersécurité : comprendre l'attaque pour mieux **défendre**.

## 🏭 Activité professionnelle de référence

> **Point d'entrée du référentiel :** [[Activités professionnelles#D3 — Gestion d'incidents|D3 — Gestion d'incidents]]
>
> La station Météo57 cesse de remonter ses données par intermittence. C'est un **incident** (D3) : il faut l'ouvrir et le qualifier (T1), l'analyser, identifier la cause — une **perturbation radioélectrique** de la bande 2,4 GHz, accidentelle ou malveillante — puis **remédier** par une solution de durcissement matériel (T3) et rédiger un **rapport d'incident** avec recommandations de prévention (T4). L'élève est en autonomie complète sur le périmètre de l'incident.

## 🎯 Objectifs de la séquence

> À l'issue de cette séquence, l'élève sera capable d'**analyser une menace de brouillage radio** sur un objet connecté, d'en **mesurer l'effet sur le signal**, et de **concevoir puis valider une contre-mesure matérielle** (blindage) en chiffrant son efficacité en décibels.

## 🏢 Mise en situation professionnelle

> Contexte ancré dans le fil rouge [[1ere-SEQ01 - Météo57 Phase 2|Météo57]].

Les stations **Météo57** sont déployées en extérieur et remontent leurs mesures au serveur via **WiFi 2,4 GHz**. Depuis une semaine, une station du secteur République–Saulcy **décroche par intermittence** : les relevés manquent, puis réapparaissent. Le client soupçonne une panne ; le diagnostic réseau ne montre pourtant aucun défaut logiciel.

En tant que technicien cybersécurité de l'équipe, vous ouvrez un **ticket d'incident** : et si le problème venait de l'**environnement radio** ? Un four à micro-ondes, un autre émetteur, ou pire — un **brouilleur** installé à proximité ? Votre mission : **caractériser la perturbation**, comprendre pourquoi un attaquant ne peut pas être combattu par un autre brouilleur (c'est illégal et inefficace), et proposer un **durcissement matériel** de la station — puis **prouver par la mesure** qu'il protège réellement la liaison.

## 📚 Prérequis

- Séquence(s) précédente(s) : [[1ere-SEQ01 - Météo57 Phase 2]]
- Notions techniques attendues :
  - ESP32 et liaison WiFi (la station émet déjà en 2,4 GHz)
  - Notion de signal, de fréquence, lecture d'une grandeur sur un appareil de mesure
  - Architecture client-serveur Météo57 (capteur → ESP32 → serveur)
- Compétences déjà travaillées :
  - C07 / C09 (réalisation et intégration de la station en Phase 2)

## 📋 Compétences ciblées

> ⚠️ **1 à 2 compétences maximum.**

| Code | Intitulé | Niveau visé |
|------|----------|-------------|
| [[Compétences#C04 — Analyser une structure matérielle et logicielle\|C04]] | Analyser une structure matérielle et logicielle *(principale — Bloc 3 cybersécurité)* | Approfondissement |
| [[Compétences#C06 — Valider la conformité d'une installation\|C06]] | Valider la conformité d'une installation *(secondaire — volet mesure)* | Découverte |

**Savoirs associés mobilisés** ([[Savoirs associés]]) :
- *Domaine 5 — Cybersécurité et réglementation :* acteurs de l'écosystème réglementaire (**ANSSI, ANFR, Cybermalveillance.gouv**), bonnes pratiques de sécurité, disponibilité comme critère de sécurité (le brouillage attaque la **disponibilité**).
- *Domaine 2 — Électronique matérielle et mesure :* structures électroniques matérielles, **caractérisation de signaux non complexes**, **appareils de mesure**, notion de **décibel** et d'atténuation.

## 🗓️ Découpage en séances

| N° | Titre | Durée | Compétences | Statut |
|----|-------|-------|-------------|--------|
| [[1ere-SEQ02 - SÉA01 - La menace RF et le cadre légal\|SÉA01]] | La menace RF : brouillage, disponibilité et cadre légal | 2 h | C04 | ⬜ |
| [[1ere-SEQ02 - SÉA02 - Cartographier le spectre 2.4 GHz\|SÉA02]] | Cartographier le spectre 2,4 GHz (analyse passive) | 3 h | C04 | ⬜ |
| [[1ere-SEQ02 - SÉA03 - Concevoir la défense matérielle\|SÉA03]] | Concevoir la défense : blindage et cage de Faraday | 3 h | C04 | ⬜ |
| [[1ere-SEQ02 - SÉA04 - Valider le blindage par la mesure\|SÉA04]] | Valider le blindage : mesure d'atténuation en dB | 3 h | C06 | ⬜ |
| [[1ere-SEQ02 - SÉA05 - Rapport d'incident et durcissement\|SÉA05]] | Rapport d'incident et recommandations de durcissement | 2 h | C04 · C01 | ⬜ |

## 🔬 Approche technique (100 % légale)

| Besoin | Solution retenue | Pourquoi |
|--------|------------------|----------|
| **Émetteur légitime** (source de signal connue) | ESP32 de la station Météo57 émettant en WiFi 2,4 GHz | On mesure le **RSSI** d'un signal qu'on maîtrise — aucune émission de brouillage |
| **Analyseur de spectre 2,4 GHz** | Module **nRF24L01+** piloté par Arduino/ESP32 (*« Poor Man's 2.4 GHz scanner »*) | ~3 €, **détection d'énergie** sur 126 canaux, balaye WiFi + BT + micro-ondes. Légal (réception/détection seule) |
| **Découverte RF large bande** *(optionnel)* | Dongle **RTL-SDR** (FM, 433 MHz, ADS-B) | Montre le spectre… mais **ne monte pas jusqu'à 2,4 GHz** → point pédagogique sur les **limites du matériel** |
| **Démonstration du brouillage** | **Simulation** (courbe SNR qui s'effondre) ou observation d'une bande **saturée** | On illustre le *concept* sans jamais émettre de brouillage |
| **Contre-mesure matérielle** | Cage de Faraday (boîte métallique, grillage fin, alu multicouche), plan de masse, **ferrites** sur câbles | Cœur « défense matérielle » de la séquence |
| **Mesure d'atténuation** | RSSI (dBm) reçu avec / sans blindage → **atténuation en dB** | Chiffrer l'efficacité, valider contre un cahier des charges |

## 📦 Ressources nécessaires

- **Matériel :** ESP32 (station Météo57), module nRF24L01+ + Arduino/ESP32 récepteur, *(option)* dongle RTL-SDR + antenne, boîtes métalliques / grillage à mailles fines / papier aluminium / sachets anti-statique, ferrites de câble, multimètre.
- **Logiciels :** PlatformIO + Arduino-core ESP32, croquis « Poor Man's 2.4 GHz scanner » (nRF24), *(option)* SDR# ou GQRX et Universal Radio Hacker, tableur pour les courbes d'atténuation.
- **Documents :** fiche réglementaire ANFR/ANSSI, cahier des charges du blindage (seuil d'atténuation à atteindre), fiche de relevé de mesures, trame de rapport d'incident.

## ✅ Critères de réussite de la séquence

- [ ] L'élève distingue **brouillage RF** (couche physique) et **attaque protocolaire** (ex. déauthentification), et sait pourquoi le brouillage attaque la **disponibilité**.
- [ ] L'élève cite le **cadre légal** (illégalité du brouilleur, rôle de l'ANFR/ANSSI) et la posture éthique du technicien.
- [ ] L'élève **caractérise** l'occupation de la bande 2,4 GHz et relève le **RSSI** de la station.
- [ ] L'élève **conçoit** une cage de Faraday et justifie le choix des matériaux/maillage.
- [ ] L'élève **mesure l'atténuation en dB** apportée par le blindage et la **compare au cahier des charges**.
- [ ] L'élève rédige un **rapport d'incident** exploitable avec recommandations de durcissement.

## 🛡️ Prolongements possibles

- Atténuation comparée selon le **maillage** (loi : la maille doit être ≪ λ/10 ≈ 1,2 cm à 2,4 GHz).
- Sensibilisation **GPS / clés de voiture** (autres bandes brouillées dans l'actualité) → débat cybercitoyen.
- Lien avec la **redondance** comme défense logicielle (la station re-tente l'envoi) → complémentarité matériel/logiciel.

## 📝 Notes / Ajustements

- Séquence pensée pour le **T2** (après la fabrication de la station en SEQ01). Ajuster la durée selon le nombre de postes nReF24/RTL-SDR disponibles.
- Si pas de nRF24 : se rabattre sur un **scan WiFi ESP32** (RSSI + occupation des canaux) — moins « spectre », mais suffisant pour la mesure d'atténuation.
</content>
</invoke>
