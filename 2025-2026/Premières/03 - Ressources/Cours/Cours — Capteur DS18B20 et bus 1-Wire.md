---
type: cours
titre: "Capteur DS18B20 et bus 1-Wire"
séquence: "[[1ere-SEQ01 - Météo57 Phase 2]]"
classe: Première CIEL
compétences:
  - C07
  - C09
lié_au_poste: A
---

# Fiche cours — Capteur DS18B20 et bus 1-Wire

## 1. Le capteur DS18B20

Le DS18B20 est un capteur de température numérique fabriqué par Maxim Integrated. Il est très utilisé dans les projets embarqués et industriels car il est :
- **Précis** : ±0,5 °C entre −10 °C et +85 °C
- **Numérique** : la donnée sort déjà convertie, pas de conversion analogique-numérique nécessaire
- **Adressable** : plusieurs capteurs peuvent partager le même fil

### Brochage (version câblée)

```
DS18B20 vue de face (méplat en bas)
 ┌─────────────┐
 │  1  2  3    │
 └─────────────┘
    │  │  │
   GND Data VCC
```

| Broche | Couleur standard | Fonction |
|--------|-----------------|----------|
| 1 (GND) | Noir | Masse |
| 2 (Data) | Jaune | Données (bus 1-Wire) |
| 3 (VCC) | Rouge | Alimentation 3,3V ou 5V |

---

## 2. Le bus 1-Wire

Le 1-Wire est un protocole de communication série développé par Dallas Semiconductor. Il permet de faire transiter les données sur **un seul fil** (plus la masse).

### Caractéristiques

| Caractéristique | Valeur |
|-----------------|--------|
| Nombre de fils de données | 1 |
| Vitesse | ~16 kbps (mode standard) |
| Distance max | Plusieurs dizaines de mètres |
| Nombre de capteurs sur un bus | Illimité (chaque capteur a une adresse 64 bits unique) |

### La résistance pull-up — pourquoi est-elle indispensable ?

Le bus 1-Wire utilise une logique **open-drain** : les composants peuvent tirer le fil vers le bas (0V / niveau bas), mais ne peuvent pas le pousser vers le haut seuls.

La résistance pull-up connecte le fil de données au +3,3V. En l'absence de signal, elle maintient le bus à l'état haut (1 logique). Sans elle :
- Le bus reste à un niveau indéterminé
- Le capteur ne répond pas
- La valeur lue est généralement **−127 °C** (code d'erreur)

```
3,3V ──┬─── R pull-up (4,7 kΩ) ───┬─── Data DS18B20
       │                           │
       │                     ESP32 GPIO 4
       │
      GND
```

**Valeur typique :** 4,7 kΩ (entre 2,2 kΩ et 10 kΩ selon longueur du bus)

---

## 3. Valeurs de température particulières

| Valeur lue | Signification | Cause probable |
|------------|--------------|----------------|
| −127 °C | Capteur non détecté | Pull-up manquante, mauvais câblage, broche incorrecte |
| 85 °C | Valeur de reset | Capteur pas encore initialisé (lecture trop rapide au démarrage) |
| Valeur stable | Normal | Tout fonctionne |

---

## 4. Chaîne d'alimentation solaire

```
Énergie solaire
      │
      ▼
Panneau solaire (5V)
      │
      ▼
Module TP4056 ──────── Batterie LiPo (3,7V)
(chargeur)
      │
      ▼
   Sortie 3,7V → Step-up 5V → VIN ESP32
```

### Module TP4056

| Borne | Fonction |
|-------|----------|
| IN+ / IN− | Entrée panneau solaire |
| BAT+ / BAT− | Connexion batterie LiPo |
| OUT+ / OUT− | Sortie vers le circuit |

> Utiliser impérativement un module TP4056 **avec protection intégrée** (module DW01A incorporé) pour éviter la surcharge et la décharge profonde de la batterie.

---

## 5. Connecteurs JST — principe du sertissage

Le sertissage est un procédé de connexion **mécanique et électrique** sans brasure. Un contact métallique est écrasé autour du fil conducteur par une pince spéciale.

### Avantages
- Connexion démontable et re-connectable
- Pas de risque de mauvaise brasure ou de pont
- Utilisé en industrie pour tous les câbles internes

### Procédure de sertissage

```
Fil dénudé
│←3mm→│

1. Dénuder        2. Insérer dans     3. Sertir          4. Clipper
   le fil            le contact          (pince)             dans le
                   (côté ouvert ↑)                        boîtier (clic)
```

**Vérification :** Légère traction sur le fil — si le contact sort, recommencer.
