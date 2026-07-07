---
type: journal
projet: Robot Sumo
date_début: 2026-06-10
---

# Robot Sumo — Journal de bord

## 2026-06-10 — Lancement du projet

- Définition du projet : robot sumo autonome ESP32, catégorie 16×16 cm / 750 g
- Création de la fiche projet technique : [[Fiche projet]]
- Matériel disponible : ESP32, imprimante 3D, Fusion 360
- Composants à commander : moteurs N20, DRV8833, TCRT5000 x4, Sharp GP2Y0A21 x2, LiPo 2S, régulateur 5V
- Budget estimé : 50–70 €

**Prochaine étape :** passer la commande de composants

## 2026-06-11 — Fiche v0.2 performance

- Création de [[Fiche projet — v0.2]] : variante compétition, budget illimité, conception pilotée par la stratégie
- Doctrine : traction (aimants néodyme + 4WD Maxon) > réaction (Teensy 4.1, boucle 1 kHz, IR < 1 ms) > géométrie (lame acier ressort)
- Raspberry Pi 5 rejeté (boot lent, non temps-réel) au profit du Teensy 4.1
- 8 manœuvres de départ pré-programmées sélectionnables par micro-switchs
- ⚠️ 4 questions de règlement bloquantes à poser à l'organisateur (dohyo acier ? aimants ? lame affûtée ? test adhérence ?)

**Prochaine étape :** vérifier le règlement (aimants/dohyo) avant tout achat v0.2

## 2026-06-12 — Fiche v0.2.1 : mise en conformité règlement TechnoBot 2026

- Lecture du règlement officiel ([[Reglement 2026 TechnoBot Lycees (1).pdf]]) → création de [[Fiche projet — v0.2.1]]
- **Dohyo en bois** (Ø 92 cm) → aimants abandonnés ; aspiration/ventouses explicitement interdites (Art. 6) → aucune downforce possible
- Doctrine reclassée : la **lame** devient l'arme n°1 (voler l'appui adverse), attaque de flanc, masse 748 g pile + lest acier
- Contraintes règlement intégrées : 4 actionneurs max (= nos 4 moteurs), interrupteur à levier, watchdog anti-immobilité (5 s), CT retourné/secoué, calibration ligne sur site
- Dohyo d'entraînement à construire (chaque lycée apporte sa piste)
- La v0.2 est conservée telle quelle comme support pédagogique (hypothèses avant règlement)

**Prochaine étape :** construire le dohyo d'entraînement + banc traction roues silicone sur bois peint
