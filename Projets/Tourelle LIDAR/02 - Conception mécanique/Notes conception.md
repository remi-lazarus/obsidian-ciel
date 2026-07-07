---
date: 2026-06-18
statut: à démarrer
---

# Notes de conception mécanique — Tourelle LIDAR

## Contraintes

- Rotation mécanique limitée à ±90° (les fils ne doivent pas faire plus d'un demi-tour)
- Les deux VL53L0X à exactement 180° l'un de l'autre (tolérance ±5°)
- Hauteur minimale pour garder le centre de gravité bas
- Fixation rigide du servo sur le châssis robot
- Passage des câbles I2C et XSHUT sans pincement ni torsion

## Pièces à concevoir

- [ ] Corps de tourelle (plateau tournant portant les 2 capteurs)
- [ ] Fixation servo → châssis
- [ ] Passage de câble (gouttière ou guide-câble)

## Dimensions de référence

| Élément | Dimension |
|---|---|
| VL53L0X breakout (Pololu / générique) | ~13 × 18 mm |
| SG90 corps | 22 × 11 × 27 mm |
| SG90 palonnier | Ø 25 mm env. |
| Robot Sumo max | 160 × 160 mm |

## Journal Fusion 360

*À compléter lors des sessions de conception.*
