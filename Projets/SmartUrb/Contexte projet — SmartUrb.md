---
type: contexte-projet
titre: SmartUrb — Carrefours intelligents de la Métropole de Metz
code: SMARTURB
classe: Seconde TNE
fil_rouge: SmartUrb
référentiel: TNE — CC1–CC9
mise_à_jour: 2026-04-07
---

# SmartUrb — Carrefours intelligents de la Métropole de Metz

## L'entreprise

**SmartUrb** est un bureau d'études spécialisé en **mobilité urbaine connectée et efficacité énergétique**. L'entreprise conçoit, fabrique et déploie des équipements de gestion du trafic pour les collectivités locales.

SmartUrb intervient sur toute la chaîne :
- Conception électronique des équipements de carrefour
- Développement logiciel embarqué
- Infrastructure réseau de supervision
- Maintenance et télémaintenance des installations

**Siège :** Zone d'activités Metz-Technopôle — 57000 Metz

---

## La mission 2025-2026

La **Métropole de Metz** a signé un contrat avec SmartUrb pour déployer une nouvelle génération de carrefours intelligents sur l'**axe République–Saulcy**, dans le cadre de son plan de mobilité durable et de son programme smart city.

Les objectifs du projet :

| Objectif | Enjeu TNE |
|----------|-----------|
| Remplacer les anciens feux à lampes à incandescence par des LEDs pilotées | ⚡ Énergétique — réduction de 70% de la consommation |
| Connecter chaque carrefour au réseau de supervision de la Métropole | 🌐 Numérique — remontée d'état en temps réel |
| Adapter les cycles en fonction du trafic et de l'heure | 🌐+⚡ — optimisation consommation et fluidité |
| Permettre la maintenance à distance et le diagnostic de pannes | 🌐 Numérique — télémaintenance |

---

## Les élèves sont…

**Techniciens en contrat de professionnalisation** chez SmartUrb. Ils intègrent l'équipe technique pour la durée du projet et prennent en charge des phases successives de la fabrication et du déploiement.

> À chaque séquence, la mise en situation s'inscrit dans une **phase identifiée du projet SmartUrb** et fait explicitement référence à un ou plusieurs enjeux TNE.

---

## Architecture du carrefour connecté SmartUrb

```
                    ┌──────────────────────────────┐
                    │   Serveur de supervision       │
                    │   Métropole de Metz            │
                    │   (dashboard temps réel)       │
                    └──────────────┬───────────────┘
                                   │ WiFi / 4G
                    ┌──────────────▼───────────────┐
                    │   Boîtier de carrefour         │
                    │   ESP32 (cœur connecté)        │
                    │   · Gestion des cycles feux    │
                    │   · Mesure consommation LED    │
                    │   · Remontée d'état réseau     │
                    │   · Détection présence piéton  │
                    └──────────┬────────────────────┘
                               │ Câblage
          ┌────────────────────┼────────────────────┐
          │                    │                    │
    Feux voiture          Feux piéton          Bouton piéton
    (3 LEDs)              (2 LEDs)             (capteur)
```

---

## Phases du projet — trajectoire annuelle

> **Règle :** chaque séquence cible **1 CC principale + 1 CC secondaire maximum**. Les autres CC sont mobilisées mais pas évaluées.

| Phase | Séquence | Contenu | CC principale | CC secondaire |
|-------|----------|---------|---------------|---------------|
| 1 — Prise en main | SEQ01 | Découverte Arduino/ESP32, lecture cahier des charges SmartUrb | **CC1** S'informer | CC4 Réaliser |
| 2 — Validation | SEQ02 | Machine à états, temporisation, bouton piéton | **CC6** Mettre en service | CC5 Opérations préalables |
| 3 — Prototype physique | SEQ03 | Brasure sur perfboard, implantation composants | **CC4** Réaliser | CC2 Organiser |
| 4 — Carrefour connecté | SEQ04 | Configuration WiFi ESP32, remontée d'état | **CC5** Opérations préalables | CC8 Renseigner |
| 5 — Bilan énergétique | SEQ05 | Mesure LED vs incandescent, analyse consommation | **CC3** Analyser | CC8 Renseigner |
| 6 — Compte rendu *(co-intervention)* | SEQ06 | Présentation du projet à la Métropole de Metz | **CC9** Communiquer | CC8 Renseigner |

### Couverture des CC sur l'année

| CC | Rôle | Séquence(s) |
|----|------|-------------|
| CC1 | Principale | SEQ01 |
| CC2 | Secondaire | SEQ03 |
| CC3 | Principale | SEQ05 |
| CC4 | Principale / Secondaire | SEQ03 / SEQ01 |
| CC5 | Principale / Secondaire | SEQ04 / SEQ02 |
| CC6 | Principale | SEQ02 |
| CC7 | — | *(non ciblée cette année — à envisager en maintenance future)* |
| CC8 | Secondaire | SEQ04, SEQ05, SEQ06 |
| CC9 | Principale | SEQ06 |

### SEQ06 — Co-intervention (note pédagogique)

La séquence finale est conçue en **co-intervention avec le professeur de Français/Communication**. Elle mobilise CC8 (production écrite du rapport de projet) et CC9 (présentation orale au "client" fictif — un représentant de la Métropole de Metz joué par l'enseignant ou un intervenant).

> Référence vademecum TNE : *"La compétence 'Rendre compte oralement' prend une place prépondérante lors d'un travail d'équipe qui intègre la co-activité. Il est recommandé en fin de chaque séquence d'organiser une restitution orale des résultats."*

---

## Enjeux TNE à mentionner dans chaque mise en situation

Toute mise en situation d'une séquence Seconde doit faire référence à **au moins un** de ces enjeux :

**Enjeu énergétique :**
- Réduction de consommation par passage aux LEDs
- Pilotage intelligent des cycles (extinction partielle la nuit)
- Mesure et suivi de la consommation par carrefour

**Enjeu numérique :**
- Carrefour connecté au réseau de la Métropole
- Remontée de données d'état (fonctionne / en panne / consommation)
- Maintenance à distance, télé-diagnostic

---

## Cahier des charges du carrefour SmartUrb (fonctionnalité 1)

*Version simplifiée pour la Seconde — une intersection voiture/piéton*

| Fonctionnalité | Spécification |
|----------------|---------------|
| Cycle voiture | Vert 5 s → Orange 2 s → Rouge permanent |
| Cycle piéton | Rouge permanent sauf activation bouton |
| Activation piéton | Bouton → Orange voiture 2 s → Rouge voiture + Vert piéton 5 s → Piéton rouge clignotant 2 s → retour cycle |
| Alimentation | 5V via USB (prototype) → 12V DC (déploiement) |
| Technologie LED | LEDs 5 mm standard (prototype) → LEDs haute luminosité IP65 (déploiement) |
| Communication | Non (prototype phase 1) → WiFi ESP32 (phase 2 — SEQ04) |

---

## Documents de référence

- [[00 - Référentiel/TNE — Famille de métiers Secondes]] — présentation de la famille TNE
- [[00 - Référentiel/Compétences TNE — Seconde]] — CC1–CC9 avec déclinaisons CIEL
- [[Projets/Feux de circulation/01 - Cahier des charges/Cahier des charges]] — documentation technique de base
