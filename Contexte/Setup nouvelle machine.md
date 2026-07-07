---
type: procedure
titre: Setup Claude Code — Nouvelle machine
mise_à_jour: 2026-05-19
---

# Setup Claude Code sur une nouvelle machine

## Ce que git synchronise automatiquement (aucune action requise)

- `Contexte/Skills/` — les fichiers de skill (SKILL.md, plugin.json)
- `.claude/settings.local.json` — permissions projet
- Tout le reste du vault

**Après un `git pull`, les skills sont déjà là** — il suffit de configurer le profil PowerShell une fois par machine.

---

## Configuration requise une fois par machine

Les skills sont chargés via `--plugin-dir` au lancement de Claude Code. Cette option est injectée automatiquement par une fonction PowerShell dans `$PROFILE`.

### Méthode automatique (recommandée)

Ouvrir **PowerShell** et exécuter :

```powershell
& "<VAULT>\Contexte\setup-claude.ps1"
```

Exemple sur la machine principale :
```powershell
& "C:\Users\<vous>\Documents\Projets\obsidian-ciel\Contexte\setup-claude.ps1"
```

Le script ajoute dans `$PROFILE` :
```powershell
function claude {
    $vault = "C:\...\obsidian-ciel"
    if ((Get-Location).Path.StartsWith($vault)) {
        & claude.exe --plugin-dir "$vault\Contexte\Skills" @args
    } else {
        & claude.exe @args
    }
}
```

→ Ouvrir un **nouveau terminal** pour que le profil soit chargé, puis lancer Claude Code depuis le vault.

### Méthode manuelle

Ajouter le bloc ci-dessus dans `$PROFILE` (`C:\Users\<USER>\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1`), en adaptant les chemins.

---

## Utilisation

| Action | Commande |
|---|---|
| Charger le contexte de la session précédente | `/session-load` |
| Sauvegarder la session en cours avant de fermer | `/session-save` |

> ⚠️ Le plugin est chargé via `--plugin-dir` injecté par la fonction PowerShell.
> Claude Code doit être lancé depuis un terminal PowerShell (pas depuis le launcher graphique) pour que la fonction soit active.

---

## Résumé des fichiers concernés

| Fichier | Où | Dans git ? | Action au setup |
|---|---|---|---|
| `Contexte/Skills/` | Vault | ✅ Oui | Rien |
| `.claude/settings.local.json` | Projet | ✅ Oui | Rien |
| `$PROFILE` PowerShell | Global | ❌ Non | Script setup |

---

## Ajouter un nouveau skill

1. Créer `Contexte/Skills/skills/<nom>/SKILL.md` avec le frontmatter :
   ```yaml
   ---
   name: nom-du-skill
   description: Courte description de ce que fait le skill.
   argument-hint: ""
   allowed-tools: [Read, Write, Bash, PowerShell]
   version: 1.0.0
   ---
   ```
2. Relancer Claude Code — le skill apparaît automatiquement dans la liste.

---

## Dépannage

### `/session-load` n'apparaît pas dans la liste des skills

Causes possibles :
1. **Claude Code lancé depuis le launcher graphique** (pas depuis un terminal PowerShell) → lancer depuis PowerShell : `cd C:\...\vault ; claude`
2. **Profil PowerShell non chargé** → ouvrir un nouveau terminal et retester
3. **`$PROFILE` non configuré** → relancer le script `setup-claude.ps1`

### Vérifier que le plugin est chargé

Dans le terminal avant de lancer claude :
```powershell
Get-Command claude -CommandType Function  # doit retourner la fonction PS, pas l'exe
```

Si ça retourne l'Application et non une Function, le profil n'est pas chargé.

### Note technique

Claude Code v2.1.145 ne supporte pas l'installation permanente de plugins locaux via `claude plugin install`. Le mécanisme `--plugin-dir` (chargement par session) est la seule méthode supportée pour les plugins locaux.
