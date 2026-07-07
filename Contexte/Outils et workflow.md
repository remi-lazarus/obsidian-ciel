---
type: contexte
sujet: outils
mise_à_jour: 2026-04-05
---

# 🛠️ Outils et workflow

## Obsidian — organisation du vault

### Structure du vault

```
obsidian-ciel/                 ← racine du vault (= racine du dépôt)
├── 00 - Référentiel/          ← Compétences, Activités, Savoirs (partagé)
├── Contexte/                  ← Ce dossier — informations de contexte
├── Daily Notes/               ← Journal de bord quotidien
├── _Templates/                ← Gabarits Séquence et Séance
└── 2025-2026/
    ├── Secondes/
    │   ├── 01 - Séquences/
    │   ├── 02 - Séances/
    │   ├── 03 - Ressources/   (Cours · Évaluations · Supports élèves · TPs)
    │   └── 04 - Suivi de classe/
    └── Premières/
        ├── 01 - Séquences/
        ├── 02 - Séances/
        ├── 03 - Ressources/
        └── 04 - Suivi de classe/
```

### Conventions de nommage

| Type | Format | Exemple |
|------|--------|---------|
| Séquence Secondes | `2de-SEQxx - Titre` | `2de-SEQ01 - Découverte Arduino ESP32` |
| Séquence Premières | `1ere-SEQxx - Titre` | `1ere-SEQ01 - Météo57 Phase 2` |
| Séance | `[code séq] - SÉAxx - Titre` | `2de-SEQ01 - SÉA03 - Découvrir TinkerCAD` |
| Images | `[code séq]-nom-descriptif.png` dans `_assets/` | `SEQ02-tinkercad-circuit-led.png` |

### Plugins Obsidian utilisés

- **Dataview** — tableaux de bord dynamiques (progression, séances)
- *(à compléter — autres plugins actifs)*

### Frontmatter standard

Chaque fichier commence par un bloc YAML avec au minimum :
`type`, `titre`, `code`, `classe`, `semestre`, `statut`

### Convention de construction d'une séquence *(révisée 2026-04-07)*

Le point d'entrée est toujours **l'activité professionnelle** (E1–E5, R1–R5, D1–D3), pas les compétences.

**Ordre des sections :**
1. Activité professionnelle de référence → lien `[[Activités professionnelles#Exx]]`
2. Objectifs *(1–2 phrases, point de vue élève)*
3. **Prérequis** *(séquences précédentes, notions attendues)*
4. Mise en situation professionnelle
5. Compétences ciblées — **1 à 2 maximum** *(celles réellement évaluées)*
6. Découpage en séances · Ressources · Critères de réussite · Notes

**Frontmatter :** champ `activite_pro` obligatoire · `compétences` limité à 1–2 · pas de `savoirs`

## Workflow typique de préparation

```
Phase 1 — Conception technique        Phase 2 — Mise en pédagogie
─────────────────────────────          ──────────────────────────────────
@ingenieur-ciel                  →     @professeur-ciel
                                              ↓
  · Cahier des charges                  · Séquence (01 - Séquences/)
  · Schéma de câblage                   · Séances  (02 - Séances/)
  · Code source commenté                · Cours, TDs, TPs, Supports élèves
  · Documentation système                         ↓
                                        @evaluateur-ciel
                                         · Sujet d'évaluation
                                         · Grille par compétence
```

**Détail :**
1. `@ingenieur-ciel` — décrire le système à réaliser → il produit la doc technique complète
2. `@professeur-ciel` — lui passer la doc → il crée séquence, séances et ressources en respectant les conventions du vault et le référentiel CIEL
3. `@evaluateur-ciel` — à partir de la séquence → il génère le sujet et la grille d'évaluation par compétence

> Voir [[Agents IA]] pour le détail de chaque agent.

## Claude Code — comment je l'utilise

- Création de ressources pédagogiques via les agents `@ingenieur-ciel`, `@professeur-ciel`, `@evaluateur-ciel`
- Organisation et maintenance du vault (structure, liens, renommage)
- Extraction et mise en forme de données (ex. référentiel PDF)
- Complétion et mise à jour de fichiers Markdown
