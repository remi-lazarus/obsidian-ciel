---
name: session-save
description: Sauvegarde le contexte de la session en cours dans Session récente.md et la daily note du jour.
argument-hint: ""
allowed-tools: [Read, Write, Bash, PowerShell]
version: 1.0.0
---

# Session Save

Ce skill permet de sauvegarder les points importants de la session en cours dans le vault Obsidian pour pouvoir reprendre le travail dans une future session sans repartir de zéro.

## Ce que tu dois faire quand ce skill s'active

### 1. Collecter les informations de la session

Avant d'écrire quoi que ce soit, rassemble :
- Les sujets et fichiers travaillés pendant cette session (depuis la conversation)
- Les décisions importantes prises (conventions, choix techniques, approches pédagogiques)
- Les fichiers créés ou modifiés (lire `git status` pour être exhaustif)
- Les problèmes rencontrés et leurs solutions
- Ce qui était prévu mais n'a pas encore été fait
- Les prochaines étapes immédiates

### 2. Écrire dans `Contexte/Session récente.md`

Remplace entièrement le contenu du fichier avec ce format :

```markdown
---
date: YYYY-MM-DD
durée_session: [estimation en heures ou "~Xh"]
---

# Session du [date en français]

## Ce qu'on a fait
- [action concrète 1]
- [action concrète 2]
- ...

## Décisions et conventions établies
- [décision 1 — pourquoi]
- [décision 2 — pourquoi]

## Fichiers créés / modifiés
- `chemin/fichier.md` — [ce qui a changé]
- ...

## Problèmes rencontrés
- [problème → solution trouvée] (ou "→ non résolu")

## Prochaines étapes immédiates
1. [action prioritaire 1]
2. [action prioritaire 2]
3. ...

## Contexte important à retenir
> [Ce que la prochaine session devra savoir pour reprendre efficacement — état d'avancement, contraintes, conventions spécifiques à ce projet]
```

### 3. Ajouter une entrée dans la daily note du jour

La daily note se trouve dans `Daily Notes/YYYY-MM-DD.md`.
Si elle n'existe pas, la créer.

Ajoute à la fin (ou crée le fichier avec) :

```markdown
## Session Claude Code — [heure approximative]

[Résumé en 3-5 lignes de ce qui a été fait, pour la trace historique du vault]

→ Détails complets : [[Session récente]]
```

### 4. Confirmer à l'utilisateur

Indique que la sauvegarde est faite et rappelle les 2-3 prochaines étapes les plus importantes.

## Règles

- Ne pas sur-détailler les fichiers modifiés : regrouper par thème si plus de 5 fichiers
- La section "Contexte important" doit être rédigée comme un briefing pour quelqu'un qui n'a pas assisté à la session — c'est la section la plus importante
- Toujours utiliser les noms de fichiers exacts (wikilinks Obsidian sans extension)
- Dater au format YYYY-MM-DD dans le frontmatter, en français dans le titre
