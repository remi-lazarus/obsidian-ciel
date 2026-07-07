---
type: contexte
sujet: skills-ia
mise_à_jour: 2026-05-19
---

# ⚡ Skills IA

Les skills sont des comportements que Claude charge **automatiquement** selon le contexte de la demande — sans qu'on ait à les invoquer explicitement (contrairement aux agents `@nom-agent`).

Ils sont stockés dans `Contexte/Skills/skills/` et chargés via le plugin local `obsidian`.

## Différence agents / skills

| | Agents | Skills |
|---|---|---|
| **Invocation** | Explicite (`@nom-agent`) | Automatique (selon contexte) |
| **Rôle** | Persona complet avec expertise | Comportement ou guidance ciblée |
| **Usage** | Phases de travail longues | Règles transverses, contraintes, patterns |

## Skills actifs

| Skill | Déclencheur | Description |
|---|---|---|
| [[skills/session-save/SKILL\|session-save]] | "sauvegarde la session", "fin de session", "note ce qu'on a fait" | Écrit un résumé structuré dans [[Session récente]] + daily note |
| [[skills/session-load/SKILL\|session-load]] | "charge le contexte", "reprends où on en était", "on reprend" | Lit [[Session récente]] + TODO et présente un brief |

---

## Ajouter un skill

1. Créer un dossier `skills/nom-du-skill/`
2. Copier le contenu de [[Template - Nouveau skill]]
3. Nommer le fichier `SKILL.md`
4. Mettre à jour ce fichier index
