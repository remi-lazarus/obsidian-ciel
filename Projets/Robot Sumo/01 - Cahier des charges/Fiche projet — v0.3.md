---
type: projet-technique
titre: Robot Sumo autonome ESP32 — Vision v0.3
code: SUMO-01
version: 0.3
date: 2026-06-11
auteur: ingenieur-ciel
statut: vision
précédente: "[[Fiche projet — v0.1]]"
---

# Robot Sumo — Fiche projet technique (v0.3 — Vision)

> Document de vision pour les évolutions futures. La version active de référence est [[Fiche projet — v0.1]].
> **Changements vs v0.1 :** caméra pour la vision embarquée · télécommande ESP-NOW (déclenchement compte à rebours + sélection de stratégie)

---

## 1. Caméra embarquée

### Objectif

Remplacer ou compléter la détection adversaire (VL53L0X) par de la vision : identifier la position, la forme et le mouvement de l'adversaire pour une stratégie plus adaptative.

### Options techniques

| Option | Avantages | Inconvénients |
|---|---|---|
| **ESP32-CAM** (remplacement du DevKit) | Caméra OV2640 intégrée, tout-en-un | Perd les GPIO actuels, reconfiguration complète, ~10€ |
| **ESP32-S3** + module caméra | Plus puissant (dual-core 240MHz, PSRAM 8MB), meilleur support vision | Migration complète, ~15–20€ |
| **ArduCam Mini SPI** | Compatible ESP32 actuel, interface SPI partageable | Résolution limitée, latence SPI |

**Recommandation pour v0.3 :** migrer vers **ESP32-S3** — meilleure puissance de calcul pour traiter les images en temps réel, PSRAM intégrée pour les buffers, support caméra natif.

### Cas d'usage

- **Détection adversaire par vision** : remplace ou complète les VL53L0X — plus robuste aux angles, permet d'estimer la taille et la vitesse de l'adversaire
- **Reconnaissance de stratégie adverse** : si l'adversaire tourne toujours dans le même sens, adapter l'attaque
- **Détection de bord par vision** : ligne blanche visible à la caméra — redondance avec TCRT5000

### Points d'attention

- Traitement image en temps réel sur ESP32-S3 → privilégier des algorithmes légers (seuillage couleur, binarisation) plutôt que du ML embarqué
- Éclairage du dohyo variable selon la salle → calibration adaptative nécessaire
- La caméra oriente vers l'avant — angle mort à l'arrière toujours couvert par TCRT5000

---

## 2. Télécommande ESP-NOW

### Objectif

Permettre depuis le bord du dohyo de :
1. **Déclencher le compte à rebours** de 5s (sans toucher le robot — règlement concours)
2. **Sélectionner la stratégie** avant chaque match en fonction de l'adversaire observé

### Technologie retenue : ESP-NOW

ESP-NOW est un protocole Espressif peer-to-peer intégré à l'ESP32 :
- Latence < 1ms (temps réel garanti)
- Portée ~10–50m en champ libre — largement suffisant pour un dohyo
- Pas de WiFi ni d'infrastructure réseau nécessaire
- Fonctionne en même temps que le WiFi si besoin

**Matériel nécessaire :** un second ESP32 DevKit (~5€) utilisé comme télécommande, avec 2–3 boutons physiques.

### Interface de la télécommande

| Bouton | Action |
|---|---|
| **DÉPART** | Envoie le signal de départ → le robot lance le compte à rebours 5s |
| **STRATÉGIE +** | Cycle entre les stratégies disponibles (affichage sur OLED du robot) |
| **CONFIRM** | Verrouille la stratégie sélectionnée |

### Stratégies sélectionnables

| ID | Nom | Description |
|---|---|---|
| 0 | **Agressif** | Fonce dès détection, priorité vitesse d'attaque |
| 1 | **Circulaire** | Tourne autour de l'adversaire avant d'attaquer |
| 2 | **Attente** | Reste en zone centrale, attend que l'adversaire s'approche |
| 3 | **Push direct** | Pousse en ligne droite sans rotation de recherche |

### Intégration dans la machine à états

```
[TÉLÉCOMMANDE reçoit DÉPART]
        ↓
[ATTENTE 5s] → [RECHERCHE (selon stratégie)] ←→ [ATTAQUE]
                        ↑                              ↓
                   [REPLI BORD] ←── (si bord détecté)
```

La stratégie sélectionnée modifie uniquement les paramètres de la phase RECHERCHE et ATTAQUE (vitesse, angle de rotation, seuil de déclenchement).

---

## 3. Impact sur l'architecture

### Changements vs v0.1

- ESP32 DevKit → **ESP32-S3 DevKit** (si caméra embarquée retenue)
- Ajout **caméra OV2640** (connecteur FPC 24 broches sur ESP32-S3)
- Ajout **ESP32 télécommande** (second module, ~5€)
- Le bus I2C, SPI et les GPIO moteurs/capteurs restent identiques (compatibilité ESP32-S3)

### Budget supplémentaire estimé

| Ajout | Prix estimé |
|---|---|
| ESP32-S3 DevKit (remplacement) | ~10–15 € |
| Module caméra OV2640 | ~5–8 € |
| ESP32 télécommande + boîtier + boutons | ~8–12 € |
| **Total ajouts v0.3** | **~25–35 €** |

---

## 4. Prochaines étapes pour cette version

- [ ] Valider le prototype v0.1 sur dohyo avant de migrer
- [ ] Tester ESP-NOW entre deux ESP32 DevKit (peut être fait sur v0.1 sans toucher au reste)
- [ ] Évaluer la charge CPU de la caméra sur ESP32-S3 avec un benchmark simple
- [ ] Définir les stratégies en fonction des retours des matchs v0.1

---

## 5. Liens

- [[Fiche projet — v0.1]] — version active en cours de construction
- [[Robot Sumo — Journal de bord]]
