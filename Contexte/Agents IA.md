---
type: contexte
sujet: agents-ia
mise_à_jour: 2026-04-04
---

# 🤖 Agents IA

Les agents sont stockés dans `~/.claude/agents/` et s'invoquent avec `@nom-agent` dans Claude Code.

## Workflow

```
Documentation technique    →    Ressources pédagogiques
   @ingenieur-ciel         →       @professeur-ciel
                                         ↓
                                  @evaluateur-ciel
```

---

## @ingenieur-ciel

**Rôle :** Concevoir le système technique, écrire le code, produire la documentation.

**Quand l'utiliser :** Phase 1 — avant de créer les ressources pédagogiques.

**Ce qu'il produit :**
- Cahier des charges technique + BOM
- Schéma de câblage
- Code source commenté (C++/Arduino, Python)
- Documentation système (architecture, protocoles, mise en service)

---

## @professeur-ciel

**Rôle :** Transformer la documentation technique en ressources pédagogiques CIEL.

**Quand l'utiliser :** Phase 2 — à partir de la doc produite par @ingenieur-ciel.

**Ce qu'il produit :**
- Séquences (`01 - Séquences/`)
- Séances (`02 - Séances/`)
- Cours, TDs, TPs, supports élèves (`03 - Ressources/`)

**Sait :**
- Référentiel CIEL (C01–C11, blocs U2/U31/U32)
- Pédagogie inductive, fil rouge
- Différenciation pour les 1ères CIEL
- Conventions du vault (nommage, frontmatter, wikilinks)

---

## @evaluateur-ciel

**Rôle :** Créer sujets et grilles d'évaluation par compétences.

**Quand l'utiliser :** Pour toute évaluation formative ou sommative.

**Ce qu'il produit :**
- Sujets contextualisés (fil rouge TechSignal / Météo57)
- Grilles d'évaluation par compétence
- Analyse de couverture des compétences
- Aménagements pour besoins particuliers

---

## Exemple de session type

```
1. "Crée le système [description] pour les 2des" → @ingenieur-ciel
2. "À partir de cette doc, crée la séquence 2de-SEQ03" → @professeur-ciel  
3. "Crée l'évaluation pour 2de-SEQ03" → @evaluateur-ciel
```
