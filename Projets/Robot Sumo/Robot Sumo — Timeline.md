---
type: timeline
projet: Robot Sumo
mis_à_jour: 2026-06-21
---

# Robot Sumo — Timeline des versions

```
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

 2026-06-10  ●  v0.0 — Prototype initial                [archivée]
             │
             │  · ESP32 + N20 30:1 + Sharp GP2Y0A21 ×2 (IR 10–80 cm)
             │  · TCRT5000 ×4 détection bord
             │  · Budget estimé 50–70€
             │
             ▼
 2026-06-10  ●  v0.1 — BOM complet                      [ACTIVE]
             │
             │  · VL53L0X ×3 frontaux (ToF I2C — remplace Sharp IR)
             │  · N20 500RPM 6V + DRV8833 + roues JSumo SLT20
             │  · Batterie OVONIC 2S 2200mAh XT60
             │  · Chargeur iMax B6AC (80W, 6A, ~22 min à 3C)
             │  · LM2596 buck 5V, OLED SSH1106 128×64
             │  · MPU-6050 (gyro + accél, I2C 0x68)
             │  · Pont diviseur batterie (R1=100kΩ R2=56kΩ → GPIO 34)
             │  · Détection bord hybride : TCRT5000 + ADNS-3080
             │  · Budget ~205€
             │
    ┌─────────┼──────────────────────────┐
    │         │                          │
    ▼         ▼                          ▼
    │         │                          │
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
BRANCHE COMPÉTITION               BRANCHE LIDAR        FUTUR
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
    │         │                          │
    ▼         ▼                          ▼

 2026-06-11  ●  v0.2              2026-06-18  ●  v0.2.0.1      v0.3 ○
             │  Haute perf.                  │  Concept LIDAR
             │  (étude)                      │
             │  · Doctrine :                 │  · 2× VL53L0X à 180°
             │    traction > réaction        │    sur servo SG90
             │    > géométrie                │  · Sweep ±90° → 360°
             │  · Teensy 4.1 (1kHz)          │    sans slip ring
             │  · 4WD Maxon DCX16L           │  · Stratégie attaque
             │  · Aimants néodyme            │    latérale
             │    (hypothèse)               │
             │  · Support pédagogique        ↓
             │                         ★  [Projet] Tourelle LIDAR
             ▼                              (projet indépendant)
 2026-06-12  ●  v0.2.1
                TechnoBot 2026             · Phase 1 : breadboard
                conforme                  · Phase 2 : Fusion 360
                                          · Phase 3 : intégration
                · Dohyo bois →
                  aimants abandonnés
                · Aspiration interdite
                  (Art. 6)
                · Lame acier ressort
                  → arme principale
                · Maxon DCX16L
                  + Teensy 4.1
                · Watchdog anti-
                  immobilité (Art. 14)
                · Présentation EN 5min
                · Budget ~1 730€
                · Poids cible 748g

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
                                                         v0.3 ○
                                           [futur — concept]
                                           · ESP32-S3 + OV2640
                                             caméra
                                           · Télécommande ESP-NOW
                                           · 4 stratégies
                                             sélectionnables
                                           · +25–35€ vs v0.1
                                                  │
                                                  ▼
 2026-06-21                                  v0.3.1 ○
                                           [futur — vitrine ML]
                                           · Deep RL embarqué
                                             (PPO + TFLite Micro)
                                           · Sim2real : simulateur
                                             Pymunk + 6 adv. synth.
                                           · Télémétrie SD 50 Hz
                                           · Imitation Learning
                                             via télécommande
                                           · ~250€ (+SD + S3 N16R8)
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

## Légende

| Symbole | Signification |
|---|---|
| `●` | Version/jalon réalisé |
| `○` | Concept / futur |
| `★` | Projet dérivé indépendant |
| `[ACTIVE]` | Version de travail principale |
| `[archivée]` | Remplacée, conservée pour référence |

## Fiches et documents

| Version | Fichier | Statut |
|---|---|---|
| v0.0 | [[Fiche projet — v0]] | Archivée |
| v0.1 | [[Fiche projet — v0.1]] | Active |
| v0.2 | [[Fiche projet — v0.2]] | Branche compétition |
| v0.2.0.1 | [[Fiche projet — v0.2.0.1]] | Concept → Tourelle LIDAR |
| v0.2.1 | [[Fiche projet — v0.2.1]] | TechnoBot 2026 |
| v0.3 | [[Fiche projet — v0.3]] | Vision futur |
| v0.3.1 | [[Fiche projet — v0.3.1]] | Vitrine ML — Deep RL + sim2real |
| Tourelle LIDAR | [[Tourelle LIDAR/01 - Cahier des charges/Fiche projet\|Fiche projet Tourelle LIDAR]] | En cours |

## Journal de bord

→ [[Robot Sumo — Journal de bord]]
