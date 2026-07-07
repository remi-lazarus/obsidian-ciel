---
date: 2026-06-18
statut: en cours
projet_parent: "[[Fiche projet — v0.1]]"
---

# Tourelle LIDAR — Fiche projet

> Sous-projet du [[Fiche projet — v0.1|Robot Sumo]]. Remplacement des 3 capteurs VL53L0X frontaux fixes par une tourelle rotative offrant une couverture 360° du dohyo.

## Objectif

Localiser l'adversaire en permanence (angle + distance) pour adopter une stratégie d'attaque latérale plus efficace qu'une attaque frontale directe.

---

## Principe de fonctionnement

Deux VL53L0X positionnés à **180° l'un de l'autre** sur un servo SG90. Un balayage de **±90°** suffit à couvrir les 360° du dohyo — les fils ne font jamais plus d'un demi-tour, pas de slip ring nécessaire.

```
         0° (avant robot)
         ↑
-90° ←  [SG90]  → +90°
     ┌──────────┐
     │ VL53L0X_A│  pointe à : angle_servo
     │ VL53L0X_B│  pointe à : angle_servo + 180°
     └──────────┘

 angle servo | A couvre | B couvre
    -90°     |   -90°   |  +90°
      0°     |    0°    |  180°
    +90°     |  +90°    |  -90°
→ 360° couverts, rotation mécanique ≤ 180°
```

### Paramètres de scan

| Paramètre | Valeur |
|---|---|
| Fréquence VL53L0X | 50 Hz |
| Vitesse SG90 | ~600°/s |
| Durée sweep ±90° | ~300 ms |
| Points / capteur / sweep | ~15 |
| Résolution angulaire | ~12° |
| Portée utile | 30 – 1200 mm |

---

## Composants

| Composant | Qté | Source | Prix |
|---|---|---|---|
| VL53L0X | 2 | Déjà dans BOM Robot Sumo | — |
| Servo SG90 | 1 | À commander | ~3€ |
| Support tourelle imprimé 3D | 1 | Filament atelier | — |
| Câbles souples 26 AWG | ~30 cm | Stock atelier | — |

---

## Câblage / GPIO

| Pin ESP32 | Rôle |
|---|---|
| GPIO 21 | SDA (I2C partagé) |
| GPIO 22 | SCL (I2C partagé) |
| GPIO 13 | XSHUT VL53L0X_A |
| GPIO 12 | XSHUT VL53L0X_B |
| GPIO 14 | PWM servo SG90 |
| 3V3 | VCC VL53L0X + servo |
| GND | GND commun |

**Assignation des adresses I2C au démarrage :**
1. XSHUT_A LOW, XSHUT_B LOW → les deux en reset
2. XSHUT_A HIGH → VL53L0X_A démarre à 0x29 (défaut)
3. Assigner 0x30 via API → VL53L0X_A = 0x30
4. XSHUT_B HIGH → VL53L0X_B démarre à 0x29
5. Assigner 0x31 → VL53L0X_B = 0x31

---

## Architecture logicielle

### Cartographie

```cpp
float carte[360];        // distance (mm) indexée par angle (0–359°)
bool  valide[360];       // true si la mesure est récente

void maj_carte(int angle_servo, float dist_A, float dist_B) {
    int angle_A = ((angle_servo       + 360) % 360);
    int angle_B = ((angle_servo + 180 + 360) % 360);
    carte[angle_A] = dist_A;  valide[angle_A] = true;
    carte[angle_B] = dist_B;  valide[angle_B] = true;
}

int trouver_adversaire() {
    // retourne l'angle où distance < rayon_dohyo - marge
    const float RAYON_DOHYO = 460.0;  // mm (dohyo Ø92cm)
    const float MARGE = 80.0;
    for (int a = 0; a < 360; a++) {
        if (valide[a] && carte[a] < (RAYON_DOHYO - MARGE))
            return a;
    }
    return -1;  // pas détecté
}
```

### Machine à états étendue

```
ATTENTE (5s)
  → RECHERCHE
      tourelle sweep continu
      → adversaire détecté à angle θ
          → POSITIONNEMENT
              robot tourne jusqu'à θ ≈ 90° (attaque de côté)
              → ATTAQUE LATÉRALE
                  tourelle figée vers l'avant
                  poussée perpendiculaire à l'adversaire
                  → si bord détecté → REPLI
                  → si adversaire perdu → RECHERCHE
```

### Pourquoi l'attaque latérale est plus efficace

- **Attaque frontale** : les moteurs adverses s'opposent directement (force vs. force)
- **Attaque perpendiculaire** : la composante de traction adverse ≈ 0 dans la direction de poussée → robot sorti avec moins d'effort

---

## Conception mécanique (Fusion 360)

Voir [[02 - Conception mécanique/Notes conception]]

Contraintes :
- Hauteur mini (centre de gravité bas)
- Passage des fils sans torsion excessive sur ±90°
- Fixation rigide du servo sur le châssis
- Les deux VL53L0X exactement à 180° (tolérance ±5° acceptable)
- Dégagement pour le câble I2C souple vers le PCB principal

---

## Étapes de réalisation

### Phase 1 — Validation du concept (banc de test)
- [ ] Commander servo SG90
- [ ] Câbler VL53L0X_A + VL53L0X_B avec XSHUT sur breadboard
- [ ] Tester l'assignation d'adresses I2C en séquence
- [ ] Lire les deux capteurs simultanément sans conflit
- [ ] Faire tourner le servo et lire les distances en continu
- [ ] Afficher la carte sur moniteur série

### Phase 2 — Conception mécanique
- [ ] Concevoir la tourelle sur Fusion 360 (MCP disponible)
- [ ] Imprimer et ajuster
- [ ] Valider le sweep sans accroc mécanique

### Phase 3 — Intégration robot
- [ ] Intégrer dans le code principal Robot Sumo
- [ ] Implémenter POSITIONNEMENT + ATTAQUE LATÉRALE
- [ ] Calibrer la compensation de déplacement (robot en mouvement → angle corrigé par gyro MPU-6050)
- [ ] Tests sur dohyo

### Phase 4 — Optimisations
- [ ] Décider si la tourelle continue à scanner pendant ATTAQUE ou se fige
- [ ] Ajuster résolution / vitesse de sweep selon les retours terrain
- [ ] Tester la robustesse face à des surfaces réfléchissantes (robot adverse en alu)

---

## Retours de réalisation

*Section à compléter au fil du projet.*

| Date | Étape | Résultat | Notes |
|---|---|---|---|
| — | — | — | — |

---

## Liens

- [[Fiche projet — v0.1]] — Robot Sumo (projet parent)
- [[Fiche projet — v0.2.0.1]] — Fiche concept origine
- [[03 - Tests composants/Test VL53L0X tourelle]] — à créer
- [[04 - Code/tourelle-lidar]] — à créer
