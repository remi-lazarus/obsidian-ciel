---
type: guide
titre: Claude Code — Guide rapide
mise_à_jour: 2026-05-19
---

# Claude Code — Guide rapide

## Nouvelle machine : 3 étapes

### 1. Cloner le vault
```powershell
git clone <url-du-repo> C:\Users\<TOI>\Documents\Projets\obsidian-ciel
cd obsidian-ciel
```

### 2. Lancer le script de config (une seule fois par machine)
```powershell
& "C:\Users\<TOI>\Documents\Projets\obsidian-ciel\Contexte\setup-claude.ps1"
```
Le script configure automatiquement `~/.claude/` pour que Claude Code reconnaisse les skills.

### 3. Redémarrer Claude Code et tester
Ouvrir le dossier du vault dans Claude Code, puis taper :
```
/session-load
```
Si le skill apparaît et s'exécute → tout est bon.

---

## Usage quotidien

| Quand | Commande |
|---|---|
| **Début de session** — reprendre où j'en étais | `/session-load` |
| **Fin de session** — sauvegarder avant de fermer | `/session-save` |

---

## Mise à jour depuis git (machine existante)

```powershell
git pull
```
Pas besoin de relancer le script — la config `~/.claude/` est déjà en place.

---

## Fichiers importants

| Fichier | Rôle |
|---|---|
| `Contexte/Session récente.md` | Contexte de la dernière session |
| `📋 Todo.md` | Priorités et tâches en cours |
| `Contexte/Skills/skills/session-load/SKILL.md` | Ce que fait `/session-load` |
| `Contexte/Skills/skills/session-save/SKILL.md` | Ce que fait `/session-save` |
| `Contexte/setup-claude.ps1` | Script de config nouvelle machine |
| `Contexte/Setup nouvelle machine.md` | Procédure détaillée si le script échoue |

---

## Ajouter un skill

1. Créer `Contexte/Skills/skills/<nom>/SKILL.md`
2. Y coller ce frontmatter minimal :
   ```yaml
   ---
   name: nom-du-skill
   description: Ce que fait le skill en une phrase.
   argument-hint: ""
   allowed-tools: [Read, Write, Bash, PowerShell]
   version: 1.0.0
   ---
   ```
3. Redémarrer Claude Code → le skill est disponible avec `/nom-du-skill`

---

## Si quelque chose ne marche pas

| Symptôme | Action |
|---|---|
| `/session-load` n'apparaît pas | Relancer le script setup, puis redémarrer Claude Code |
| Skill apparaît mais plante | Vérifier `~/.claude/settings.json` contient `"enabledPlugins": {"obsidian": true}` |
| Jonction cassée | Voir `Contexte/Setup nouvelle machine.md` → section Dépannage |
