---
name: session-load
description: Charge le contexte de la dernière session de travail — lit Session récente.md, Todo.md et la dernière daily note.
argument-hint: ""
allowed-tools: [Read, Glob, Bash, PowerShell]
version: 1.0.0
---

# Session Load

Ce skill permet de retrouver rapidement le contexte de la dernière session de travail pour reprendre efficacement sans repartir de zéro.

## Ce que tu dois faire quand ce skill s'active

### 1. Lire les sources de contexte

Lis dans cet ordre :

1. **`Contexte/Session récente.md`** — contexte de la dernière session Claude Code
2. **`📋 Todo.md`** — état des priorités (items urgents et en cours seulement)
3. **La daily note la plus récente** dans `Daily Notes/` — pour avoir la trace chronologique

Si `Session récente.md` n'existe pas encore ou est vide : lire les 2 dernières daily notes disponibles.

### 2. Présenter un brief structuré

Présente le résumé sous cette forme (concise, pas de blabla) :

---

**Dernière session : [date]**

**Ce qui a été fait :**
[2-4 points clés, en bullets]

**Décisions à garder en tête :**
[conventions ou choix importants encore actifs]

**Où on en est :**
[état d'avancement du ou des chantiers en cours — 2-3 phrases max]

**Pour cette session :**
[les 2-3 prochaines étapes immédiates, telles que notées en fin de session]

**Urgences TODO :**
[items marqués 🔴 dans le Todo, s'il y en a]

---

### 3. Demander confirmation

Termine par : *"On reprend sur [sujet probable] ? Ou tu veux travailler sur autre chose ?"*

## Règles

- Ne pas tout recopier — synthétiser. Le brief doit tenir en 20-30 lignes max
- Si la dernière session date de plus de 2 semaines, signaler que le contexte est peut-être périmé
- Mettre en gras les décisions et conventions qui ont un impact sur le travail actuel
- Ne pas lire les fichiers des ressources pédagogiques (séquences, séances, cours) sauf si explicitement demandé — ça consomme des tokens inutilement
- Si le fichier Session récente.md n'a jamais été créé, le dire clairement et suggérer d'utiliser le skill session-save en fin de prochaine session
