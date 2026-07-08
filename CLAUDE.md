# Vault CIEL — Instructions Claude Code

## Démarrage automatique

Au début de chaque conversation dans ce vault, charge le contexte de la dernière session **sans attendre que l'utilisateur le demande** :

1. Lis `Contexte/Session récente.md`
2. Lis les items urgents/en cours de `📋 Todo.md`
3. Lis la daily note la plus récente dans `Daily Notes/`

Si `Session récente.md` est absent ou vide, lis les 2 dernières daily notes. Si aucune n'existe (premier lancement du vault), présente-toi brièvement, résume la structure du vault et propose de commencer par lire `Contexte/Outils et workflow.md`.

Présente ensuite ce brief structuré (20-30 lignes max) :

```
**Dernière session : [date]**

**Ce qui a été fait :**
[2-4 bullets]

**Décisions à garder en tête :**
[conventions ou choix importants encore actifs]

**Où on en est :**
[état d'avancement — 2-3 phrases]

**Pour cette session :**
[2-3 prochaines étapes immédiates]

**Urgences TODO :**
[items 🔴 s'il y en a]
```

Termine par : *"On reprend sur [sujet probable] ? Ou tu veux travailler sur autre chose ?"*

---

## /session-load

Quand l'utilisateur écrit `/session-load` : exécute la même procédure que le démarrage automatique ci-dessus.

---

## /session-save

Quand l'utilisateur écrit `/session-save` :

1. Collecte depuis la conversation : sujets travaillés, décisions prises, fichiers modifiés (via `git status`), problèmes résolus, prochaines étapes.
2. Si une nouvelle version de robot (v0.x, v0.x.y…), un nouveau sous-projet ou un jalon majeur a été créé cette session, mets à jour `Projets/Robot Sumo/Robot Sumo — Timeline.md` : ajoute la version avec date, idées principales, et lien wikilink vers la fiche. Pour un projet dérivé, ajoute une branche `★` avec son nom et sa fiche.
3. Remplace entièrement `Contexte/Session récente.md` avec ce format :

```markdown
---
date: YYYY-MM-DD
durée_session: ~Xh
---

# Session du [date en français]

## Ce qu'on a fait
- [action concrète]

## Décisions et conventions établies
- [décision — pourquoi]

## Fichiers créés / modifiés
- `chemin/fichier.md` — [ce qui a changé]

## Problèmes rencontrés
- [problème → solution]

## Prochaines étapes immédiates
1. [priorité 1]
2. [priorité 2]

## Contexte important à retenir
> [Briefing pour la prochaine session — état d'avancement, contraintes, conventions]
```

4. Ajoute une entrée dans la daily note du jour (`Daily Notes/YYYY-MM-DD.md`) :

```markdown
## Session Claude Code — [heure]

[Résumé 3-5 lignes]

→ Détails : [[Session récente]]
```

5. Confirme que c'est sauvegardé et rappelle les 2-3 prochaines étapes.

---

## Règles générales

- Réponses concises, pas de blabla ni de récapitulatif en fin de réponse
- Ne pas lire les fichiers séquences/séances/cours sauf si demandé explicitement
- **Ne jamais lire `zz - Archives/`** (années scolaires terminées) sauf demande explicite — économie de tokens
- Utiliser les wikilinks Obsidian (`[[nom du fichier]]`) dans les fichiers du vault
- Langue : français

---

## Personnalisation

Ce vault est un template partagé. Avant la première utilisation, remplacer les placeholders `[Prénom]`, `[Prénom Nom]` et `[Établissement]` dans `Contexte/` et `Contexte/Agents/` par tes propres informations (voir le README).
