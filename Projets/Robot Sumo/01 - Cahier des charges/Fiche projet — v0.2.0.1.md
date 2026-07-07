---
version: v0.2.0.1
date: 2026-06-18
parent: "[[Fiche projet — v0.1]]"
statut: concept
---

# Fiche projet — v0.2.0.1 : Tourelle pseudo-LIDAR

> Déclinaison de la v0.2 — remplacement des 3 capteurs frontaux fixes par une tourelle rotative à 2× VL53L0X.

## Concept

Plutôt que 3 capteurs VL53L0X fixes pointant vers l'avant, on monte **2 VL53L0X à 180° l'un de l'autre** sur un servo SG90.  
Un sweep de ±90° suffit à couvrir **360°** sans anneau tournant (slip ring), les fils restant dans la plage de rotation.

```
        0° (avant)
        ↑
-90° ←  [Servo SG90]  → +90°
        VL53L0X_A (0°)
        VL53L0X_B (180°)

Pendant le sweep :
  angle servo  |  VL53L0X_A couvre  |  VL53L0X_B couvre
  -90°         |  -90°              |  +90°
   0°          |    0°              |  180°
  +90°         |  +90°             |  -90°
→ 360° couverts sans jamais dépasser ±90° de rotation mécanique
```

## Paramètres de scan

| Paramètre | Valeur |
|---|---|
| Fréquence VL53L0X | 50 Hz |
| Vitesse SG90 | ~600°/s |
| Durée d'un sweep ±90° | ~300 ms |
| Points par capteur par sweep | ~15 |
| Résolution angulaire | ~12° |
| Portée utile | 30–1200 mm |

## Cartographie

```cpp
float carte[360];  // distance en mm par angle (0–359°)

// Pendant le sweep :
int angle_reel = angle_servo + (capteur == A ? 0 : 180);
carte[angle_reel % 360] = distance_mm;

// Détection adversaire :
// si carte[angle] < rayon_dohyo - marge → adversaire trouvé
```

## Stratégie d'attaque latérale

Connaître l'angle de l'adversaire permet d'**attaquer de côté** plutôt que de face :
- Attaque frontale : les moteurs adverses opposent une résistance maximale
- Attaque perpendiculaire : aucune composante de traction ne s'oppose à la poussée → plus facile à sortir du dohyo

```
Machine à états étendue :
RECHERCHE → détecte adversaire (angle θ) 
         → POSITIONNEMENT (se déplace pour que θ ≈ 90°)
         → ATTAQUE LATÉRALE (pousse perpendiculairement)
```

## GPIO

| Pin | Rôle |
|---|---|
| GPIO 13 | XSHUT VL53L0X_A (tourelle) |
| GPIO 12 | XSHUT VL53L0X_B (tourelle, +180°) |
| GPIO 14 | PWM servo SG90 |

Adresses I2C assignées au démarrage (XSHUT séquentiel) : 0x30 et 0x31.  
Les GPIO 13/12 sont libérés par rapport à la v0.2 qui utilisait 3 capteurs fixes à l'avant.

## Composants additionnels vs v0.1

| Composant | Qté | Prix estimé |
|---|---|---|
| VL53L0X (déjà dans BOM) | 2 sur 5 utilisés | — |
| Servo SG90 | 1 | ~3€ |
| Support/tourelle imprimé 3D | 1 | filament |

## Points encore à définir

- [ ] Conception de la tourelle (Fusion 360) : fixation servo, support 2 capteurs à 180°, passage des fils
- [ ] Calibration : compensation de la vitesse du robot pendant le scan (le robot bouge → l'angle réel ≠ angle servo pur)
- [ ] Gestion du balayage pendant ATTAQUE : figer la tourelle vers l'avant ou continuer à scanner ?
- [ ] Intégration MPU-6050 : le gyroscope peut corriger l'angle de scan en temps réel

## Lien avec les autres versions

- [[Fiche projet — v0.1]] — robot de base (capteurs frontaux fixes)
- [[Fiche projet — v0.2.1]] — spec compétition TechnoBot 2026 (Teensy 4.1, autre projet)
- [[Fiche projet — v0.3]] — vision caméra ESP32-S3 + télécommande ESP-NOW
