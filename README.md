# Vault Obsidian — Enseignement Bac Pro CIEL

Template de vault [Obsidian](https://obsidian.md) pour l'enseignement en Bac Pro **CIEL** (Cybersécurité, Informatique et réseaux, Électronique) et en Seconde famille de métiers **TNE** (Transitions Numérique et Énergétique).

Il contient des séquences et séances prêtes à l'emploi, les référentiels de compétences, des templates, et un workflow de création de cours assisté par IA avec [Claude Code](https://claude.com/claude-code).

## Contenu

- **`00 - Référentiel/`** — Compétences CIEL (C01–C11), compétences communes TNE (CC1–CC9), activités professionnelles E/R/D, taxonomie
- **`2025-2026/`** — Séquences, séances, cours, TPs et évaluations pour Seconde TNE (fil rouge **SmartUrb** : carrefours intelligents Arduino/ESP32) et Première CIEL (fil rouge **Météo57** : station météo connectée, PCB, réseau)
- **`Projets/`** — Dossiers techniques des projets supports (Feux de circulation, Météo57, SmartUrb) et projets R&D (Robot Sumo, Tourelle LIDAR)
- **`_Templates/`** — Gabarits Séquence et Séance ancrés dans le référentiel
- **`Contexte/`** — Documentation du workflow, agents IA, skills Claude Code
- **`Contexte/Agents/`** — Pipeline de création de cours en 3 agents : `@ingenieur-ciel` (conception technique) → `@professeur-ciel` (transposition pédagogique) → `@evaluateur-ciel` (grilles d'évaluation par compétences)

## Démarrage

1. **Cloner** le dépôt, puis dans Obsidian : *Ouvrir un dossier comme coffre* → sélectionner le dossier cloné.
2. **Personnaliser** : remplacer les placeholders `[Prénom]`, `[Prénom Nom]` et `[Établissement]` dans `Contexte/` et `Contexte/Agents/` par vos informations.
3. **(Optionnel) Claude Code** : suivre `Contexte/Setup nouvelle machine.md` pour installer le workflow IA (`/session-load`, `/session-save`, agents). Guide d'usage : `Contexte/Claude Code — Guide rapide.md`.

## Conventions

- Nommage : `2de-SEQ01 - SÉA02 - Titre.md` (niveau, séquence, séance)
- Wikilinks Obsidian entre tous les fichiers
- Chaque séquence part d'une activité professionnelle du référentiel et cible 1–2 compétences max
- Évaluation par positionnement NA / PA / A / D

## Licence et partage

Ressources partagées entre collègues de l'enseignement professionnel — libre réutilisation et adaptation dans un cadre pédagogique.
