---
type: idée
statut: à explorer
priorité: haute
date: 2026-04-05
tags: [OS, github, template, collègues, amélioration]
---

# 💡 GitHub + distribution du template OS

## Idée 1 — Versionner l'OS via GitHub avec Pull Requests

Utiliser GitHub pour gérer les évolutions du vault Obsidian comme un vrai projet logiciel :

- Le vault (ou sa partie "structure OS") est versionné dans un dépôt GitHub
- Chaque amélioration structurelle (nouveau template, nouvel agent, nouvelle convention) passe par une **Pull Request**
- Permet de documenter les changements, de revenir en arrière en cas de régression, et de collaborer proprement

**Avantages :**
- Historique complet des évolutions de l'OS
- Possibilité de tester des changements sur une branche sans impacter le vault actif
- Base solide pour partager le template avec des collègues (fork du dépôt)

**Questions à trancher :**
- [ ] Versionner tout le vault ou uniquement la structure (sans les contenus de cours) ?
- [ ] Dépôt public (partageable facilement) ou privé (avec accès par invitation) ?
- [ ] Gérer les fichiers binaires (images `_assets/`) avec Git LFS ou les exclure via `.gitignore` ?
- [ ] Utiliser GitHub Desktop pour simplifier l'usage quotidien ?

**`.gitignore` suggéré :**
```
# Contenu personnel / données élèves
2025-2026/
Daily Notes/
Contexte/Profil enseignant.md

# Fichiers système
.DS_Store
.obsidian/workspace.json
.obsidian/workspace-mobile.json
```

---

## Idée 2 — Nettoyer l'OS pour en faire un template générique

Créer une version "blank" du vault, sans aucune donnée personnelle, distribuable à des collègues enseignants CIEL.

**Ce qui reste dans le template :**
- Structure des dossiers (`00 - Référentiel/`, `_Templates/`, `Boite à idées/`, `Contexte/`, `2025-2026/Secondes/`, `2025-2026/Premières/`…)
- Référentiel officiel CIEL complet (`Compétences.md`, `Activités professionnelles.md`, `Savoirs associés.md`)
- Templates de séquence et séance
- Agents IA (`Contexte/Agents/`) avec les prompts génériques
- Fichier `Contexte/Agents/🆕 Template - Nouvel agent.md`
- `README.md` d'explication pour les nouveaux utilisateurs

**Ce qui est retiré / anonymisé :**
- Toutes les séquences/séances/ressources spécifiques (`2025-2026/`)
- `Contexte/Profil enseignant.md` → remplacé par un template vierge
- `Daily Notes/` → dossier vide
- Références au lycée, aux élèves, aux projets personnels dans les agents

**Actions à prévoir :**
- [ ] Créer une branche `template` sur GitHub avec la version nettoyée
- [ ] Rédiger un `README.md` d'accueil avec le workflow (ingenieur → professeur → évaluateur)
- [ ] Tester le template en l'ouvrant dans un Obsidian vierge
- [ ] Écrire un guide de prise en main (1 page) pour les collègues

---

## Prochaines étapes suggérées

1. Initialiser le dépôt GitHub (`git init` dans le vault)
2. Définir le `.gitignore`
3. Premier commit avec la structure actuelle
4. Créer la branche `template` et y retirer les données personnelles
5. Partager le lien du dépôt avec les collègues intéressés
