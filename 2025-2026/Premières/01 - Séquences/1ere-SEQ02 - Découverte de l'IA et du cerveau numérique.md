---
type: séquence
titre: Découverte de l'IA et du cerveau numérique
code: 1ere-SEQ02
classe: Première CIEL
trimestre: T3
période: Fin d'année
durée_heures: 4
activite_pro: D1
compétences:
  - C01
statut: brouillon
fil_rouge: OS IA (vault de l'enseignant)
évaluée: non
---

# Découverte de l'IA et du cerveau numérique

> [!note] Séquence de découverte — fin d'année, **sans note**
> Objectif : éveiller la curiosité pour l'IA et l'organisation de la connaissance. Aucune évaluation sommative. On donne aux élèves les clés pour explorer par eux-mêmes.

## 🏭 Activité professionnelle de référence

> **Point d'entrée du référentiel :** [[Activités professionnelles#D1 — Élaboration et appropriation d'un cahier des charges|D1]]
>
> Un technicien CIEL passe sa vie à produire, organiser et transmettre de l'information technique (cahiers des charges, docs, comptes-rendus). Savoir structurer sa connaissance et dialoguer efficacement avec un assistant IA devient un savoir-faire professionnel transversal. Cette séquence aborde, par la découverte, **comment organiser l'information** et **comment formuler une demande claire** — compétences directement réinvesties en D1.

## 🎯 Objectifs de la séquence

> À l'issue de cette séquence, l'élève sera capable d'organiser ses idées dans un système de notes reliées (vault) et de dialoguer avec une IA en formulant des demandes claires et précises.

## 🏢 Mise en situation professionnelle

> Votre professeur ne prépare pas ses cours « à la main ». Il a construit un **cerveau numérique** : un coffre de notes (Obsidian) couplé à une IA qui l'aide à concevoir, rédiger et organiser. Le cours d'aujourd'hui, le projet Robot Sumo, la station Météo57 — tout est sorti de ce coffre.
>
> Aujourd'hui, on ouvre le capot. Vous allez comprendre comment ça marche, puis construire **votre propre coffre** et apprendre à parler à une IA pour qu'elle vous serve vraiment.

## 📚 Prérequis

- Séquence(s) précédente(s) : aucune en particulier
- Notions techniques attendues :
  - Savoir naviguer dans un système de fichiers (dossiers, fichiers)
  - Aucune connaissance préalable de l'IA ou du Markdown requise
- Posture attendue :
  - Curiosité, esprit critique, envie d'expérimenter

## 📋 Compétences ciblées

> Séquence **non évaluée**. Compétence transversale mobilisée à titre de découverte uniquement.

| Code | Intitulé | Niveau visé |
|------|----------|-------------|
| [[Compétences#C01\|C01]] | Communiquer en situation professionnelle | Découverte (formuler une demande claire à une IA) |

*Compétences also effleurées sans évaluation : organisation de l'information, culture numérique et esprit critique face à l'IA.*

## 🗓️ Découpage de la séance (bloc 4h)

> Séance unique de 4h en salle informatique. Support de présentation : `www/vault.html` (slideshow 10 slides). Démo live dans le vault de l'enseignant.

| Phase | Titre | Durée | Modalité |
|-------|-------|-------|----------|
| 1 | Découverte — *Le cerveau numérique* (slideshow + démo live) | 45 min | Classe entière |
| 2 | Atelier Obsidian — *Construire son coffre* (Exo 1 & 2) | 1h | Individuel / binôme |
| 3 | Atelier IA — *Apprendre à parler à une IA* (Exo 3) | 1h15 | Binôme |
| 4 | Mise en commun, débat & ouverture | 1h | Classe entière |

---

## 🧩 Phase 1 — Découverte (45 min)

**Support :** slideshow `www/vault.html` (10 slides — les 6 principes du vault).

1. Projeter le slideshow, slide par slide (≈ 25 min, avec échanges).
2. **Démo live** dans le vault réel (≈ 20 min) : ouvrir Obsidian, montrer une note, cliquer un `[[wikilink]]`, ouvrir le graphe, montrer une vraie session Claude Code qui lit/écrit un fichier.

> **Fil conducteur :** les 6 principes
> 1. Vos données vous appartiennent · 2. Le texte brut survit à tout · 3. Relier, c'est comprendre · 4. L'IA est un outil, pas un oracle · 5. Un rôle clair = un meilleur résultat · 6. Le contexte fait toute la différence.

## 🧩 Phase 2 — Atelier Obsidian (1h)

**Objectif :** comprendre par la pratique les principes 1, 2 et 3.

**Exo 1 — Créer son coffre (25 min)**
- Installer / ouvrir Obsidian, créer un nouveau vault « Mon cerveau »
- Créer **3 notes** sur une passion (jeu, sport, musique, métier visé…)
- Mettre en forme en Markdown : un titre `#`, du **gras**, une liste `-`

**Exo 2 — Relier et visualiser (35 min)**
- Ajouter des `[[liens]]` entre les 3 notes
- Créer une note « index » qui pointe vers les trois
- Ouvrir la **vue graphe** et observer le réseau qui apparaît
- *Bonus :* ajouter une 4ᵉ note et la relier — voir le graphe grandir

> **Critère de réussite (auto-évaluation) :** mes notes sont reliées et mon graphe forme un réseau, pas des points isolés.

## 🧩 Phase 3 — Atelier IA : le prompting (1h15)

**Objectif :** comprendre les principes 4, 5 et 6 — l'IA est un outil qui dépend de la qualité de la demande.

**Exo 3a — Vague vs précis (30 min)**
- Avec un assistant IA grand public, comparer deux demandes sur le même sujet :
  - Vague : « parle-moi des capteurs »
  - Précise : « explique en 5 lignes, pour un élève de 1ère, à quoi sert un capteur de température dans une station météo »
- Noter la différence de qualité → **le prompt fait le résultat**.

**Exo 3b — Donner un rôle (rejouer les agents) (25 min)**
- Demander à l'IA d'endosser un rôle : *« Tu es un professeur d'électronique. Explique-moi… »*
- Comparer avec / sans rôle → effet « agent ».

**Exo 3c — Esprit critique (20 min)**
- Poser une question piège ou pointue → repérer une **erreur / hallucination** de l'IA
- Conclusion : toujours **vérifier**. L'IA assiste, elle ne remplace pas le jugement.

> **Garde-fous à rappeler :** ne jamais saisir d'informations personnelles ; vérifier les sources ; l'IA peut se tromper avec aplomb.

## 🧩 Phase 4 — Mise en commun & ouverture (1h)

- Quelques élèves présentent leur graphe et leur meilleur prompt (10–15 min)
- **Débat (25 min) :** L'IA va-t-elle remplacer les techniciens ? Que change-t-elle pour votre futur métier ? Quelles limites éthiques ?
- **Ouverture (15 min) :** métiers de la donnée et de l'IA, le lien avec le Bloc 3 CIEL (valorisation de la donnée), comment continuer chez soi (Obsidian gratuit, assistants IA).

## 📦 Ressources nécessaires

- Matériel : salle informatique (1 poste / élève ou / binôme), vidéoprojecteur
- Logiciels : navigateur web, Obsidian (gratuit), un assistant IA grand public
- Documents :
  - Slideshow : `www/vault.html`
  - Démo live : vault de l'enseignant (exemples Météo57, Robot Sumo `www/sumo.html`)

## ✅ Critères de réussite de la séquence

- [ ] Chaque élève a créé un coffre avec au moins 3 notes reliées et a observé son graphe
- [ ] Chaque élève a expérimenté l'écart entre un prompt vague et un prompt précis
- [ ] Chaque élève sait citer au moins une limite de l'IA (vérification / hallucination)
- [ ] Les élèves repartent avec les moyens de continuer en autonomie

## 📝 Notes / Ajustements

- Séquence modulable en 2 × 2h si besoin (Phases 1-2 puis 3-4).
- Si accès IA restreint sur le réseau établissement : prévoir une démo unique au vidéoprojecteur pour la Phase 3.
