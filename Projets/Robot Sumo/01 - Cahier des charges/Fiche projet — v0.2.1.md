---
type: projet-technique
titre: Robot Sumo compétition — Performance v0.2.1 (règlement TechnoBot 2026)
code: SUMO-01
version: 0.2.1
date: 2026-06-12
auteur: ingenieur-ciel
statut: étude
précédente: "[[Fiche projet — v0.2]]"
---

# Robot Sumo — Fiche projet technique (v0.2.1 — Performance, règlement réel)

> Révision de [[Fiche projet — v0.2]] après lecture du **règlement officiel TechnoBot Lycées 2026** ([[Reglement 2026 TechnoBot Lycees (1).pdf]]).
> La v0.2 reste le support pédagogique "conception pilotée par la stratégie" ; la v0.2.1 est la version **conforme et constructible**.

---

## 1. Ce que le règlement change par rapport à la v0.2

Les 4 questions bloquantes de la v0.2 (§2) ont leurs réponses — et elles invalident l'arme principale :

| Hypothèse v0.2 | Règlement TechnoBot 2026 | Conséquence |
|---|---|---|
| Dohyo acier → aimants | **Dohyo en bois** (Art. 3 : Ø 92 cm, 22 mm, noir mat, couronne blanc brillant 4 cm) | ❌ Aimants **inutiles** — abandonnés |
| Plan B : aspiration EDF | **Interdit** (Art. 6 : pas d'aspirateurs, ventouses, colle) | ❌ Aucune downforce active possible |
| Moteurs libres | **4 actionneurs maximum** (Art. 5) | ✓ 4WD = pile la limite, aucun autre actionneur (pas de bras, pas de flipper) |
| Bouton poussoir départ | **Interrupteur à levier** (Art. 8), délai 5 s contrôlé **à chaque rencontre** | Levier remplace le bouton |
| Lame affûtée ? | Pas d'interdiction explicite, mais "ne pas dégrader le Dohyo" (Art. 6) ni blesser (Art. 16) | Lame fine **à bord ébavuré non tranchant** |
| Adhérence pneus ? | Pas de test "feuille A4" ; la **colle** est interdite | Silicone haute adhérence sans résidu = légal |

**Autres règles qui dictent la conception :**

- **Anti-immobilité** (Art. 14) : un robot immobile > 5 s = violation → Yuko adverse. **La défense statique est illégale** — watchdog de mouvement obligatoire.
- **Contact obligatoire** (Art. 14) : deux robots qui s'évitent = violation pour les deux. La stratégie "fuite" est illégale.
- **3 configurations de départ aléatoires** (Art. 8) : flanc droit/flanc droit, flanc gauche/flanc gauche, dos à dos — *"le robot ne devra pas tenir compte de sa position avant le départ"* → le robot doit **trouver l'adversaire au capteur**, pas par position pré-programmée.
- **Contrôle technique retourné, voire secoué** (Art. 5) : tout élément solidaire — batterie clipsée ET sanglée, rien en appui simple.
- **Combat = 3 rencontres × 3 min** (Art. 7), préparation < 30 s entre rencontres (Art. 13), rencontre rejouée **sans maintenance** (Art. 10) → fiabilité et endurance comptent.
- **Bordure blanche incluse dans le Dohyo** (Art. 2-3) : être sur la bande blanche n'est pas perdu ; coincé en bordure sans pouvoir bouger = Yusei adverse (Art. 12).
- **Zone extérieure dégagée sur 92 cm** (Art. 4) : aucun obstacle plus haut que la piste → portée capteurs IR ≤ ~80 cm sans faux positifs.
- **Éclairage ambiant variable** (Art. 20) + chaque lycée apporte son dohyo (peintures différentes) → **calibration capteurs ligne sur site obligatoire**.
- **Énergie électrique uniquement**, non rechangeable en cours de combat (Art. 5).

---

## 2. Doctrine stratégique révisée — gagner sur du bois

Sans aimants ni aspiration, les deux robots sont soumis à la même physique :
`F_poussée_max = μ × m × g ≈ 0,9 × 0,75 × 9,81 ≈ 6,6 N` pour tout le monde.

**Personne ne peut être "impoussable" → le duel frontal est un 50/50. On le gagne par la géométrie, ou on l'évite.** Les piliers, reclassés :

| Pilier | Principe | Conséquence |
|---|---|---|
| **1. Géométrie (lame)** | La lame qui passe sous l'adversaire lui **vole son appui** : ses roues motrices se délestent, son μ×m×g s'effondre, le nôtre reste entier | Lame toute largeur, < 1 mm du sol, châssis rigide pour hauteur constante |
| **2. Réaction** | Dohyo de 92 cm : l'adversaire est à ~30 cm au départ, tout se joue en < 1 s | 7 IR < 1 ms, boucle 1 kHz, premier arrivé sur le flanc |
| **3. Attaque de flanc** | Un robot poussé perpendiculairement à ses roues ne peut pas résister avec ses moteurs | Trajectoires en arc, jamais lame contre lame si évitable |
| **4. Traction maximale légale** | À physique égale, 748 g > 600 g | Masse = 748 g pile (limite 750 g ± 10 g de tolérance de mesure), μ max (silicone), CG bas et avant, 4WD |

### 2.1 Départ (configurations imposées, ordre aléatoire)

Le règlement impose flanc/flanc ou dos/dos : l'adversaire démarre **hors du cône avant**. C'est exactement ce que couvre notre couronne de 7 IR (±90° + arrière) :

1. **t = 5,00 s** : lecture instantanée des 7 IR → cap adversaire connu en < 10 ms quelle que soit la configuration
2. **Pivot gyro** vers la cible (90° en ~150 ms, 180° en ~250 ms)
3. **Manœuvre sélectionnée** (micro-switchs) : assaut direct, arc gauche/droite vers le flanc, matador, attente courte (< 4 s, règle anti-immobilité)

> Les manœuvres restent **relatives au cap détecté**, jamais à une position supposée — conforme à l'esprit de l'Art. 8.

### 2.2 Attaque

- Charge en arc vers le **flanc**, pleine puissance au contact (courant moteur + IMU)
- Une fois la lame engagée : l'adversaire délesté ne tient plus — pousser vers le bord **le plus proche** (carte mentale du dohyo, Ø 92 cm = jamais plus de ~45 cm à pousser)
- **Anti-enlisement** : poussée sans progression (encodeurs ≈ 0 pendant 400 ms) → juke latéral et ré-attaque en biais. Bonus règlement : deux robots bloqués = rencontre rejouée (Art. 10), autant que ce soit nous qui cassions le blocage à notre avantage.

### 2.3 Défense

- **Rotation sur place plus rapide que la circulation adverse** (asservissement gyro) : toujours présenter la lame
- **Carte mentale du bord** : odométrie encodeurs + gyro recalée sur chaque détection de ligne ; en périphérie, replis uniquement vers le centre
- **Si soulevé/poussé** : juke latéral pour décrocher la lame adverse + pivot matador
- **Watchdog anti-immobilité** : toute consigne statique > 4 s déclenche une micro-oscillation (±5 mm) — on ne perd jamais par violation Art. 14
- **Yusei offensif** (Art. 12) : un adversaire coincé en bordure incapable de bouger donne un point — si l'adversaire est bloqué sur la bande, ne pas le libérer en le percutant inutilement

---

## 3. Architecture matérielle v0.2.1

### 3.1 Inchangé par rapport à la v0.2 (toujours optimal)

| Sous-système | Choix v0.2 conservé                                       | Rappel justification                                                                               |
| ------------ | --------------------------------------------------------- | -------------------------------------------------------------------------------------------------- |
| Cerveau      | **Teensy 4.1** (Cortex-M7 600 MHz)                        | Boucle 1 kHz, 4 décodeurs quadrature hardware, boot < 300 ms — le Pi 5 reste rejeté (voir v0.2 §4) |
| Moteurs      | **4× Maxon DCX16L + GPX16 ~16:1 + ENX16**                 | = 4 actionneurs pile (Art. 5). Précision des manœuvres gyro+encodeurs                              |
| Drivers      | 4× DRV8874 sur PCB custom 4 couches                       | Limitation courant 4 A + IPROPI = capteur de contact                                               |
| Perception   | 7× IR JS40F + 4× QRE1113 + IMU SPI + encodeurs + courants | Latences < 1 ms partout ; VL53L0X toujours disqualifié (20 ms)                                     |
| Énergie      | LiPo 3S 450 mAh 75C ×3, buck 5 V, XT60 coupure            | Un combat (3×3 min) < 150 mAh — une batterie par combat, swap entre combats                        |
| Télémétrie   | ESP32-C3 UART (option, hors chemin critique)              | Tuning entre matchs                                                                                |

> Portée IR : régler/choisir ~60–80 cm max — l'Art. 4 garantit une zone dégagée de 92 cm autour du dohyo, aucun faux positif possible à cette portée.

### 3.2 Modifié

**Traction (remplace les aimants) :**
- **Masse cible 748 g** — le lest acier revient (~130 g, plancher avant, remplace les aimants au même poste de masse)
- **CG bas et avant** : batterie au plancher, lest sous la lame — tout le poids utile sur l'avant où se joue le duel
- **Roues silicone coulé Shore 20–30 A** : μ ≈ 0,8–0,9 sur bois peint. Nettoyage alcool + adhésif avant chaque rencontre (légal : pas de colle/résidu)
- 4WD conservé : 100 % du poids sur roues motrices

**Lame :**
- Acier ressort 0,4–0,5 mm, toute largeur, angle 30–45°, **< 1 mm du sol**
- Bord **ébavuré non tranchant** : ne pas dégrader le dohyo bois (Art. 6 = rencontre perdue, Art. 15) ni blesser (gants et lunettes obligatoires au placement, Art. 8 — la lame côtoie des doigts)
- Déflecteurs latéraux inclinés conservés

**Démarrage :**
- **Interrupteur à levier** (Art. 8) en façade supérieure, accessible robot posé au sol → compte à rebours 5,0 s strict
- Le délai est contrôlé au CT **et à chaque rencontre** (Art. 5) : timer hardware, marge +100 ms (démarrer à 5,1 s ; bouger avant 5 s = avertissement Art. 13)

**Conformité contrôle technique (retourné/secoué, Art. 5) :**
- Batterie : logement clipsé **+ sangle velcro** ; tous connecteurs verrouillés (XT60 naturellement, JST avec clip)
- Aucune pièce en appui simple, visserie freinée (frein-filet)
- Châssis 160,0 × 160,0 mm → usiner à **158 × 158 mm** (marge instruments du jury, Art. 5)

### 3.3 Supprimé

- ❌ Aimants N52 + supports réglables (dohyo bois)
- ❌ Plan B ventilateur EDF (Art. 6)
- ❌ Bouton poussoir départ (remplacé par levier)

---

## 4. Budget masse (cible 748 g)

| Élément | Masse |
|---|---|
| 4× moteur + réducteur + encodeur Maxon 16 mm | 220 g |
| 4× roues (jante alu + silicone) | 80 g |
| Châssis alu 7075 + visserie | 160 g |
| Lame acier ressort + déflecteurs | 45 g |
| PCB + Teensy + capteurs + câblage | 60 g |
| LiPo 3S 450 mAh + sangle | 48 g |
| **Lest acier (plancher avant, ajusté à la pesée)** | **~135 g** |
| **Total** | **~748 g** ✓ |

> Le lest est usiné en dernier, ajusté sur balance de précision. Viser 748 g : sous la limite même si la balance du jury diffère de la nôtre.

---

## 5. Affectation des broches — Teensy 4.1 (delta v0.2)

Identique à la v0.2 §7, sauf :

| Broche | v0.2 | v0.2.1 |
|---|---|---|
| 40 | Bouton départ | **Interrupteur à levier départ** (Art. 8) |
| 20, 21, 41 | Micro-switchs stratégie ×3 | Inchangé — sélection de la manœuvre **relative au cap détecté** |

---

## 6. Architecture logicielle (delta v0.2)

Structure 1 kHz inchangée (perception / localisation / comportement / pilotage). Ajouts imposés par le règlement :

- **Watchdog anti-immobilité** : compteur de mouvement ; > 4 s statique → micro-oscillation automatique (Art. 14)
- **Acquisition départ omnidirectionnelle** : à t=5 s, cap adversaire depuis les 7 IR avant toute manœuvre (configurations aléatoires, Art. 8)
- **Calibration ligne sur site** : routine au placement — le robot lit le noir sous ses 4 QRE1113 pendant les 5 s d'attente (immobile = légal avant le départ) et ajuste ses seuils ; le blanc brillant vs noir mat donne un contraste fort sur tous les dohyos
- **Timer départ hardware 5,1 s** depuis le levier — jamais < 5,0 s (avertissement Art. 13, écart au CT = disqualification Art. 16)
- **Gestion 3 min** : pas de limite d'énergie atteignable, mais log télémétrie par rencontre pour ajuster la stratégie entre les 3 rencontres du combat (< 30 s de préparation, Art. 13 — tout réglage = micro-switchs uniquement)

---

## 7. BOM v0.2.1 (delta v0.2)

| Poste | Changement | ~Prix |
|---|---|---|
| Aimants N52 + supports | ❌ Supprimé | −40 € |
| Lest acier usiné | ➕ Ajouté (chutes atelier possibles) | ~10 € |
| Interrupteur à levier (toggle) | ➕ Remplace le bouton | ~2 € |
| **Dohyo d'entraînement** | ➕ **Obligatoire** : chaque lycée apporte sa piste (Art. 3) — bois Ø 92 cm, 22 mm min, noir mat, couronne blanc brillant 4 cm, Shikiri-sen 16 × 1,9 cm à 15 cm du centre | ~60 € (CTD 22 mm + peintures) |
| Reste de la BOM | Identique v0.2 §9 | ~1 660 € |
| **Total** | | **~1 730 €** |

---

## 8. Plan de validation révisé

1. ~~Banc aimants~~ → **Banc traction sur échantillon dohyo** (bois peint noir mat) : mesurer μ réel des roues silicone, propre vs poussiéreux
2. **Duel de poussée géométrique** : vérifier qu'avec la lame engagée sous un robot de 750 g, on le pousse avec < 50 % de notre traction
3. **Temps de réaction** : oscilloscope stimulus IR → inversion PWM, cible < 5 ms
4. **Les 3 configurations de départ** ×10 chacune : cap adversaire acquis en < 50 ms, contact en < 1,5 s
5. **Contrôle technique blanc** : peser (748 g), mesurer (158 mm), retourner, secouer, chronométrer le délai de 5 s ×10
6. **Endurance** : 3 rencontres × 3 min sur une batterie, dérive thermique moteurs/drivers
7. **Sparring contre v0.1** sur le dohyo d'entraînement
8. **Calibration ligne** sur 2–3 peintures noires différentes (les dohyos des autres lycées varient)

---

## 9. Note pédagogique — cadre du concours

- **Le robot v0.2.1 (prof) est hors concours** : démonstrateur et sparring. Le règlement exige que *"les élèves soient les seuls acteurs de l'étude, la conception, la réalisation, la mise au point et la programmation"* (Art. préliminaire) — kits et robots commerciaux disqualifiés, contrôleurs techniques interrogent les élèves. Les robots élèves de l'an prochain s'inspireront des principes, pas des fichiers.
- Projet élève attendu : **30 à 70 h** d'activités encadrées — compatible avec un fil rouge de l'année.
- **Épreuve de présentation en anglais** (Art. 23) : 5 min + 3 min de questions, dossier technique LV de 5–10 pages, pitch écrit de 5 lignes à l'inscription, algorithme du programme sur la fiche de contrôle technique. Elle pèse **150 points, autant que la 1re place en sumo** (Art. 24) — à intégrer au projet pédagogique dès le départ.
- Sécurité élèves : gants et lunettes obligatoires depuis 2019 (Art. 8).

---

## 10. Liens

- [[Reglement 2026 TechnoBot Lycees (1).pdf]] — règlement officiel (source de cette révision)
- [[Fiche projet — v0.2]] — version "stratégie d'abord" (support pédagogique, hypothèses avant règlement)
- [[Fiche projet — v0.1]] — version pédagogique/budget (sparring partner)
- [[Fiche projet — v0.3]] — exploration vision + télécommande ESP-NOW
- [[Robot Sumo — Journal de bord]]
