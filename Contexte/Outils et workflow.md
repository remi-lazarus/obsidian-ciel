---
type: contexte
sujet: outils
mise_à_jour: 2026-07-07
---

# 🛠️ Outils et workflow

## Obsidian — organisation du vault

### Structure du vault

```
obsidian-ciel/                 ← racine du vault (= racine du dépôt)
├── 00 - Référentiel/          ← Compétences, Activités, Savoirs (partagé)
├── Contexte/                  ← Ce dossier — informations de contexte
│   └── Agents/                ← Prompts des agents IA
├── Daily Notes/               ← Journal de bord quotidien (YYYY-MM-DD.md)
├── Projets/                   ← Un dossier par projet (voir @ingenieur-ciel)
│   ├── SmartUrb/
│   ├── Météo57 Phase 2/
│   └── [NouveauProjet]/
├── _Templates/                ← Gabarits Séquence et Séance
│   ├── Projet/                ← Gabarits livrables projet (@ingenieur-ciel)
│   └── Évaluation/            ← Gabarits contrat/évaluation/correction (@evaluateur-ciel)
├── 2025-2026/                 ← Année scolaire ACTIVE (exemples fournis : Secondes · Premières)
│   └── [Niveau]/
│       ├── 01 - Séquences/
│       ├── 02 - Séances/
│       ├── 03 - Ressources/   (Cours · TPs · Évaluations · Supports élèves)
│       └── 04 - Suivi de classe/
└── zz - Archives/             ← ⛔ jamais lu par Claude sauf demande explicite
    └── [Année terminée]/
```

> [!warning] Convention archives
> Le contenu de `zz - Archives/` n'est **jamais lu par Claude** (agents inclus) sauf demande explicite de l'utilisateur — économie de tokens. Une année scolaire terminée y est déplacée entière (`git mv` pour préserver l'historique). Les wikilinks continuent de fonctionner, Obsidian résout par nom de fichier.

### Conventions de nommage

| Type               | Format                                                      | Exemple                                      |
| ------------------ | ----------------------------------------------------------- | -------------------------------------------- |
| Séquence Secondes  | `2de-SEQxx - Titre.md` dans `01 - Séquences/`               | `2de-SEQ01 - Découverte Arduino ESP32.md`    |
| Séquence Premières | `1ere-SEQxx - Titre.md` dans `01 - Séquences/`              | `1ere-SEQ01 - Météo57 Phase 2.md`            |
| Séquence Terminales| `tle-SEQxx - Titre.md` dans `01 - Séquences/`               | `tle-SEQ01 - ….md`                           |
| Séance             | `[code séq] - SÉAxx - Titre.md` dans `02 - Séances/`        | `2de-SEQ01 - SÉA03 - Découvrir TinkerCAD.md` |
| TP élève           | `[code séq] - TP SÉAxx - Titre.md` dans `03 - Ressources/TPs/` | `2de-SEQ03 - TP SÉA01 - Brasage.md`       |
| Grille             | `[code séq] - Grille d'évaluation - Sujet.md`               | dans `03 - Ressources/Évaluations/`          |
| Images             | `[code séq]-nom-descriptif.png` dans `_assets/`             | `SEQ02-tinkercad-circuit-led.png`            |

### Plugins Obsidian utilisés

- **Dataview** — tableaux de bord dynamiques (progression, séances). Les requêtes scannent l'année active (ex. `"2025-2026/Secondes"`) de façon récursive, filtrées par `type`. ⚠️ À la bascule d'année, mettre à jour les chemins dans les requêtes.
- **Excalidraw** — schémas pédagogiques embarqués (gestes techniques, architecture, comparaisons visuelles). Fichiers `.md` stockés dans `Cours/` de la séquence concernée.

### Frontmatter standard

Chaque fichier commence par un bloc YAML avec au minimum :
`type`, `titre`, `code`, `classe`, `semestre`, `statut`

### Convention de construction d'une séquence *(révisée 2026-04-07)*

Le point d'entrée est toujours **l'activité professionnelle** (E1–E5, R1–R5, D1–D3 pour 1ère ; CC1–CC9 pour 2de), pas les compétences.

**Ordre des sections :**
1. Activité professionnelle de référence → lien `[[Activités professionnelles#Exx]]`
2. Objectifs *(1–2 phrases, point de vue élève)*
3. **Prérequis** *(séquences précédentes, notions attendues, + outil de vérification pronostique)*
4. Mise en situation professionnelle
5. Compétences ciblées — **1 à 2 maximum** *(celles réellement évaluées)*
6. **Stratégie d'évaluation** *(tableau phase/forme/outil/statut — voir [[Formes d'évaluation]])*
7. Découpage en séances *(canevas : lancement → découverte/formalisation → TP guidé → TP autonome → éval finale)* · Ressources · Critères de réussite · Notes

**Frontmatter :** champ `activite_pro` obligatoire · `compétences` limité à 1–2 · pas de `savoirs`

---

## Workflow de création d'un projet

### Lancer avec le skill `/nouveau-projet`

```
/nouveau-projet
```

Ce skill active le workflow complet piloté par `@chef-de-projet-ciel`.

### Vue d'ensemble du workflow *(révisé 2026-07-08 — l'évaluateur intervient AVANT la rédaction des séances)*

```
/nouveau-projet
      │
      ▼
@chef-de-projet-ciel   Phase 0 — Cadrage : interview, Contexte + Plan de projet
      │
      ▼
@ingenieur-ciel        Phase 1 — Technique : fiche projet (objectifs O1, O2…)
      │                ✋ validation, puis cadrage, BOM, code, tests
      ▼                (templates _Templates/Projet/)
@professeur-ciel       Phase 2 — Structure : séquence selon le canevas
      │                (4 jalons d'évaluation, voir [[Formes d'évaluation]])
      ▼
@evaluateur-ciel       Phase 3 — Outils d'évaluation : contrat (5-6 critères),
      │                sujet, correction + quiz pronostique et auto-évaluation
      ▼                (templates _Templates/Évaluation/)
@professeur-ciel       Phase 4 — Rédaction : séances, cours, TPs, supports
      │                (le contrat d'évaluation est distribué dès le TP guidé)
      ▼
✋ validation finale
```

### Détail des phases

| Phase | Agent | Déclenchement | Livrable |
|-------|-------|---------------|----------|
| 0 — Cadrage | `@chef-de-projet-ciel` | `/nouveau-projet` | `Projets/[X]/Contexte projet.md` + `Plan de projet.md` |
| 1 — Technique | `@ingenieur-ciel` | Sur instruction du chef de projet | Fiche projet **validée d'abord**, puis livrables `_Templates/Projet/` |
| 2 — Structure pédagogique | `@professeur-ciel` | Après la doc technique | Séquence : canevas + stratégie d'évaluation |
| 3 — Outils d'évaluation | `@evaluateur-ciel` | Dès la séquence structurée | Trio contrat / évaluation / correction + outils des 4 formes |
| 4 — Rédaction des séances | `@professeur-ciel` | Contrat d'évaluation en main | Séances, cours, TPs, supports élèves |

> Voir [[Agents IA]] pour le détail de chaque agent.

---

## Claude Code — comment je l'utilise

- **`/nouveau-projet`** — lancer la création d'un nouveau projet ou séquence
- Maintenance du vault (structure, liens brisés, renommage)
- Extraction et mise en forme de données (ex. référentiel PDF)
- Complétion et mise à jour de fichiers Markdown
