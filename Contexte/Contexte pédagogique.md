---
type: contexte
sujet: pédagogie
mise_à_jour: 2026-04-07
---

# 🎓 Contexte pédagogique

## Approche générale

- Pédagogie inductive : partir du concret (manipulation, observation) pour aller vers l'abstrait
- Apprentissage par projet, pédagogie active, fil rouge annuel
- **Pédagogie ancrée dans le référentiel mais toujours en phase avec les technologies actuelles** : l'objectif est qu'un élève soit employable l'année de son diplôme.

## Deux niveaux, deux référentiels

| Classe | Référentiel de référence | Logique |
|--------|--------------------------|---------|
| **Seconde TNE** | [[00 - Référentiel/Compétences TNE — Seconde\|Compétences communes CC1–CC9 (famille TNE)]] | Découverte de la famille de métiers — les séquences partent d'une CC, dans un contexte bâtiment/énergie partagé entre toutes les spécialités TNE |
| **Première CIEL** | [[00 - Référentiel/Compétences\|Compétences C01–C11 (référentiel CIEL)]] | Spécialisation dans la filière CIEL — les séquences partent d'une activité professionnelle E/R/D |

> **Point clé :** En Seconde, [Prénom] enseigne en tant que prof CIEL mais dans le cadre de la **famille TNE**. Ses projets doivent donc couvrir les enjeux de la transition numérique ET énergétique, pas uniquement le périmètre CIEL.

---

## Fils rouges par classe

| Classe | Fil rouge | Statut | Description |
|--------|-----------|--------|-------------|
| Seconde TNE | **SmartUrb** | 🔄 En cours | Bureau d'études en mobilité urbaine connectée (Metz). Les élèves sont techniciens en contrat de pro sur le déploiement de carrefours intelligents pour la Métropole de Metz. Enjeux TNE : LEDs efficaces (énergie) + carrefour connecté ESP32 (numérique). Voir [[Projets/SmartUrb/Contexte projet — SmartUrb]]. |
| Première CIEL | **Météo57** | 🔄 En cours | Station météorologique connectée — fabrication PCB, capteur DS18B20 sur ESP32, transmission HTTP/REST vers Raspberry Pi. |

---

## Veille technologique

La progression et les outils sont révisés régulièrement pour rester alignés avec l'industrie.

| Domaine | Exemples de questions |
|---------|----------------------|
| Électronique embarquée | ESP32 toujours pertinent ? RISC-V ? RP2040 ? |
| Programmation | MicroPython vs C++ Arduino ? Rust embarqué ? |
| Réseaux & IoT | MQTT, Matter, Thread, Zigbee — quoi enseigner ? |
| Cybersécurité | Nouvelles menaces, certifications niveau 4 |
| Industrie 4.0 / Bâtiment | Cobotique, jumeaux numériques, GTB, edge computing |
| Outils pédago | Nouveaux simulateurs, IDE en ligne |
| Offres d'emploi | Quelles compétences recrutent les entreprises locales ? |

> Voir [[Boite à idées/IDÉE — Veille technologique et pédagogie prospective]] · Agent prévu : `@veilleur-ciel`

---

## Progression 2025-2026

### Secondes TNE

> ⚠️ Les séquences SEQ01 et SEQ02 ont été réalisées avant l'intégration du cadre TNE. Elles restent dans le vault mais le fil rouge sera refactoré à partir de SEQ03 (ou d'une nouvelle séquence dédiée).

| Code | Titre | Référentiel | Statut |
|------|-------|-------------|--------|
| [[2de-SEQ01 - Découverte Arduino ESP32\|2de-SEQ01]] | Découverte Arduino / ESP32 | CIEL *(hors cadre TNE)* | ✅ Fait |
| [[2de-SEQ02 - Évaluation Arduino Feux de circulation\|2de-SEQ02]] | Évaluation — Feux de circulation | CIEL *(hors cadre TNE)* | ✅ Fait |
| [[2de-SEQ03 - Prototype feux de circulation sur plaque à souder\|2de-SEQ03]] | Prototype feux de circulation | CIEL *(à refactorer)* | 🔄 En cours |

### Premières CIEL

| Code | Titre | Statut |
|------|-------|--------|
| [[1ere-SEQ01 - Météo57 Phase 2\|1ere-SEQ01]] | Météo57 — Phase 2 · Fabrication PCB et intégration réseau | 🔄 En cours |

---

## Contraintes horaires

- **Volume horaire hebdomadaire par classe :** *(à compléter)*
- **Salle(s) disponible(s) :** *(à compléter — atelier, salle info, labo…)*
- **Matériel disponible :** Arduino Uno, ESP32, breadboards, LEDs, résistances, boutons, composants CMS, fraiseuse CNC (Technodrill 3), Raspberry Pi
- **Logiciels disponibles :** TinkerCAD, IDE Arduino, KiCad, GALAAD 3
- **Plugins Obsidian actifs :** Excalidraw — utilisé pour créer des schémas pédagogiques embarqués dans les fiches (diagrammes de séquence, représentations de composants, schémas explicatifs). Les fichiers Excalidraw sont des `.md` avec frontmatter `excalidraw-plugin: parsed`, stockés dans `03 - Ressources/Cours/` et intégrés dans les fiches via `![[nom-du-fichier]]`.

## Points de vigilance récurrents

*(À compléter — difficultés fréquentes des élèves, notions à retravailler…)*
