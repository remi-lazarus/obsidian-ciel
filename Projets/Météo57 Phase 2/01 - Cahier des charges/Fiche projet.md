---
type: projet-technique
titre: Météo57 — Phase 2 · Intégration système
code: METEO57-P2
version: 1.0
date: 2026-04-06
auteur: ingenieur-ciel
statut: validé
lié_à: "[[1ere-SEQ01 - Météo57 Phase 2]]"
---

# Météo57 Phase 2 — Fiche projet technique

## 1. Description du système

La station Météo57 Phase 2 est un système embarqué et réseau complet permettant l'acquisition d'une mesure de température via un capteur DS18B20 sur ESP32, la transmission de cette donnée via HTTP sur un réseau local dédié (Raspberry Pi serveur), et la fabrication du circuit imprimé support par fraisage CNC.

### Architecture générale

```
┌──────────────────────────────────────────────────────────────────────┐
│  Alimentation                                                         │
│  Panneau solaire → Chargeur LiPo → Batterie 3,7V → ESP32 (5V/USB)   │
└────────────────────────────┬─────────────────────────────────────────┘
                             │
              ┌──────────────▼──────────────┐
              │           ESP32              │
              │  • Lecture DS18B20 (GPIO 4)  │
              │  • WiFi client               │
              │  • HTTP POST /data toutes     │
              │    les 10 secondes           │
              └──────────────┬──────────────┘
                             │ WiFi — VLAN Météo57
              ┌──────────────▼──────────────┐
              │       Routeur WiFi           │
              │  SSID : meteo57             │
              │  VLAN dédié, pas d'internet  │
              └──────────────┬──────────────┘
                             │ Ethernet / WiFi
              ┌──────────────▼──────────────┐
              │       Raspberry Pi           │
              │  Serveur Python/Flask        │
              │  GET /data → JSON temp       │
              │  Terminal de vérification    │
              └─────────────────────────────┘
```

---

## 2. Organisation du travail par équipe

5 équipes de 3 élèves. Chaque élève prend en charge **un poste de travail indépendant** sur la durée de la séance (4h). Le CNC étant unique dans l'établissement, l'élève PCB travaille **en binôme** avec l'élève Prototype pendant les temps d'attente machine.

| Poste | Rôle | Tâches principales | Binôme CNC |
|-------|------|-------------------|------------|
| **A — Prototype** | Câblage et intégration matérielle | Assemblage sur breadboard, câblage JST, test capteur, envoi données | Oui (avec C) |
| **B — Serveur/Réseau** | Infrastructure réseau et serveur | Config routeur, VLAN, démarrage serveur Flask, vérification réception | Non |
| **C — PCB** | Fabrication circuit imprimé | Import Gerber, réglage Technodrill 3, fraisage, contrôle qualité | Oui (avec A) |

> **Règle binôme :** quand la CNC est en fonctionnement automatique (temps machine ~30 min), l'élève C rejoint l'élève A pour l'aider sur l'assemblage et le câblage.

---

## 3. Poste A — Prototype et intégration capteur

### 3.1 Composants

| Composant | Référence / Détail | Quantité |
|-----------|-------------------|----------|
| ESP32 DevKit | 30 ou 38 broches | 1 |
| Capteur température | DS18B20 (version câblée) | 1 |
| Résistance pull-up | 4,7 kΩ (1/4W) | 1 |
| Breadboard | Standard 830 pts | 1 |
| Panneau solaire | Mini 5V (ex. 0,5W) | 1 |
| Batterie LiPo | 3,7V — 1000 mAh min | 1 |
| Chargeur LiPo | TP4056 (avec protection) | 1 |
| Câble JST | 2 fils, pas 2,54 mm | 2 |
| Connecteurs JST | Mâle + femelle, 2 broches | 4 |
| Fils Dupont | Assortis M-M et M-F | ~10 |

### 3.2 Schéma de câblage

#### Capteur DS18B20 → ESP32

```
DS18B20 (vue de face, méplat en bas)
  ├── Broche 1 (GND)  → GND breadboard
  ├── Broche 2 (Data) → GPIO 4 (ESP32) + R pull-up 4,7kΩ → 3,3V
  └── Broche 3 (VCC)  → 3,3V ESP32
```

| Fil DS18B20 | Couleur standard | Destination ESP32 |
|-------------|-----------------|-------------------|
| GND | Noir | GND |
| Data | Jaune | GPIO 4 |
| VCC | Rouge | 3.3V |

> **Point de vigilance :** La résistance 4,7 kΩ est **obligatoire** entre Data et VCC. Sans elle, le bus 1-Wire ne fonctionne pas — erreur fréquente.

#### Chaîne d'alimentation

```
Panneau solaire → TP4056 (IN+ / IN-)
                → TP4056 (BAT+ / BAT-) → Batterie LiPo
                → TP4056 (OUT+ / OUT-) → ESP32 (VIN ou USB via step-up 5V)
```

> **Point de vigilance :** Le TP4056 seul sans module de protection peut endommager la batterie en décharge profonde. Utiliser un module TP4056 **avec protection intégrée** (DW01A).

### 3.3 Fabrication du câble JST

Outillage requis : pince à sertir (Dupont/JST), dénudeur, fil 28 AWG.

**Procédure :**
1. Couper le fil à longueur (~30 cm)
2. Dénuder les extrémités sur 3 mm
3. Insérer le fil dans le contact JST (côté ouvert face vers le haut)
4. Sertir avec la pince (mâchoire large pour l'isolation, mâchoire fine pour le conducteur)
5. Clipper le contact dans le boîtier JST jusqu'au clic
6. Vérifier la tenue mécanique (légère traction)

> **EPI requis :** Pas de risque électrique, mais attention aux doigts lors du sertissage (force importante). Travailler sur plan de travail stable.

### 3.4 Code fourni

Le code ESP32 est disponible sur Git :
```
git@github.com:remi-lazarus/projet-station-mesure.git
```

Cloner sur la machine de l'élève → ouvrir dans Arduino IDE → vérifier les paramètres WiFi (SSID : `meteo57`, mot de passe communiqué par l'élève B) → téléverser.

### 3.5 Procédure de mise en service (Poste A)

1. Assembler le circuit sur breadboard selon le schéma
2. Fabriquer le câble JST (ou utiliser câble pré-monté si disponible)
3. Cloner le dépôt Git et ouvrir le projet Arduino
4. Vérifier/modifier les paramètres WiFi dans le code
5. Téléverser le code sur l'ESP32
6. Ouvrir le moniteur série (115200 bauds) — vérifier les messages de connexion et les valeurs de température
7. Confirmer avec l'élève B que les données arrivent sur le serveur

---

## 4. Poste B — Réseau et serveur

### 4.1 Architecture réseau (approche générique)

Le réseau est **isolé d'internet**, avec un VLAN dédié au projet. L'approche est générique et doit être adaptée selon le routeur disponible.

```
┌─────────────────────────────────────────────┐
│  VLAN Météo57 — 192.168.57.0/24             │
│                                              │
│  Raspberry Pi  : 192.168.57.10 (fixe)       │
│  ESP32 (x5)    : 192.168.57.20–24 (DHCP)   │
│  Terminal élève: 192.168.57.50+ (DHCP)      │
│                                              │
│  Passerelle    : 192.168.57.1 (routeur)     │
│  DNS           : aucun (pas internet)        │
└─────────────────────────────────────────────┘
```

**Paramètres WiFi à configurer sur le routeur :**

| Paramètre | Valeur suggérée |
|-----------|----------------|
| SSID | `meteo57` |
| Mot de passe | À définir avec l'enseignant |
| Fréquence | 2,4 GHz (compatibilité ESP32) |
| DHCP | Activé, plage 192.168.57.20–100 |
| IP Raspberry Pi | Fixe : 192.168.57.10 |
| Accès internet | Désactivé (VLAN isolé ou blocage WAN) |

> **Si le routeur ne supporte pas les VLAN :** utiliser simplement un point d'accès WiFi dédié (hotspot routeur ou smartphone en mode AP) avec la plage IP ci-dessus. L'isolation est assurée par l'absence de connexion WAN.

### 4.2 Configuration Raspberry Pi

**Prérequis :** Raspberry Pi avec Raspbian/Raspberry Pi OS, Python 3 installé.

**Vérification de l'adresse IP :**
```bash
ip addr show wlan0
# ou
hostname -I
```

**Démarrage du serveur (code fourni via Git) :**
```bash
git clone git@github.com:remi-lazarus/projet-station-mesure.git
cd projet-station-mesure
python3 serveur.py
```

**Vérification de réception depuis un terminal :**
```bash
# Sur le Raspberry Pi ou depuis n'importe quelle machine du VLAN
curl http://192.168.57.10:5000/data
# Réponse attendue : {"temperature": 23.5, "timestamp": "2026-04-06T10:00:00"}
```

**Depuis un navigateur (terminal élève) :**
```
http://192.168.57.10:5000/data
```

### 4.3 Procédure de mise en service (Poste B)

1. Connecter le Raspberry Pi en Ethernet au routeur (ou en WiFi sur le VLAN)
2. Configurer l'IP fixe du Raspberry Pi (voir paramètres réseau)
3. Allumer le routeur, vérifier le SSID `meteo57` diffusé
4. Cloner le dépôt et démarrer le serveur Flask
5. Vérifier l'accès depuis un terminal avec `curl` ou navigateur
6. Communiquer le SSID et le mot de passe à l'élève A
7. Attendre la connexion de l'ESP32 et vérifier les données reçues

---

## 5. Poste C — Fabrication PCB sur Technodrill 3

### 5.1 Prérequis

- Fichiers Gerber générés sous Fusion 360 (déjà disponibles)
- PCB vierge FR4 simple face (format adapté au dessin)
- Mèche à graver 0,1 mm (V-bit 30°) + mèche de perçage Ø 0,8/1,0 mm selon trous
- Logiciel GALAAD 3 installé sur le poste CNC

### 5.2 Procédure de fabrication (Technodrill 3)

**Étape 1 — Import des fichiers Gerber dans GALAAD**
1. Lancer GALAAD 3
2. `Fichier > Importer > Gerber RS-274X`
3. Sélectionner le fichier `.gtl` (cuivre top) et le fichier `.drl` (perçages)
4. Vérifier l'aperçu — les pistes et pastilles doivent être visibles
5. Ajuster le zéro pièce si nécessaire (centrer sur le PCB vierge)

**Étape 2 — Paramètres d'usinage**

| Opération | Outil | Vitesse (tr/min) | Avance (mm/min) | Profondeur |
|-----------|-------|-----------------|-----------------|------------|
| Gravure isolation | V-bit 30° Ø 0,1 | 20 000 | 300 | −0,1 mm |
| Perçage composants | Foret Ø 0,8 ou 1,0 | 15 000 | 200 | Traversant |
| Détourage | Fraise Ø 2,0 | 10 000 | 100 | Traversant (passes) |

> **Points de vigilance :**
> - Bien **brider le PCB** sur le plateau — tout mouvement pendant l'usinage détruit la pièce
> - Vérifier la **mise à zéro Z** avec précision (feuille de papier entre la mèche et le cuivre)
> - Porter les **lunettes de protection** pendant l'usinage (éclats de fibre de verre)
> - Ne jamais laisser la machine sans surveillance

**Étape 3 — Contrôle qualité après fraisage**
1. Nettoyer le PCB à l'air comprimé (éclats de FR4)
2. Vérifier à la loupe : pas de ponts entre pistes, pistes continues
3. Mesurer la continuité et l'isolation au multimètre (mode continuité)
4. Vérifier les diamètres de perçage avec les composants à insérer

### 5.3 Intégration avec Poste A (binôme)

Pendant la **phase d'usinage automatique** (~30 min selon la complexité du PCB), l'élève C rejoint l'élève A pour :
- Aider à l'assemblage des composants sur breadboard
- Réaliser le câblage JST sous supervision
- Revenir au CNC pour le contrôle qualité final

---

## 6. Points de vigilance globaux

| Risque | Poste concerné | Prévention |
|--------|----------------|------------|
| Court-circuit LiPo | A | Module TP4056 avec protection, ne jamais court-circuiter les bornes |
| Mauvaise polarité DS18B20 | A | Vérifier le méplat, couleurs des fils |
| Surcharge TP4056 (panneau > 1A) | A | Vérifier les specs du panneau solaire |
| IP conflictuelle ESP32 | B | Réserver les IP via filtre MAC sur le routeur |
| Serveur Flask non accessible | B | Vérifier le firewall Raspberry Pi (`ufw status`) |
| Éclats FR4 lors du fraisage | C | Lunettes obligatoires, aspiration si disponible |
| Bris de mèche | C | Ne jamais forcer, vérifier la mise à zéro Z |
| PCB non bridé | C | Toujours utiliser les brides, double vérification |

---

## 7. Dépôt Git du projet

```
git@github.com:remi-lazarus/projet-station-mesure.git
```

Les élèves clonent le dépôt en début de séance. Le code leur est fourni **prêt à l'emploi** — ils n'ont qu'à adapter les paramètres réseau (SSID, mot de passe, IP serveur).

---

## 8. Critères de réussite (fin de séance)

| Critère | Poste responsable | Vérification |
|---------|------------------|--------------|
| Température lue et affichée dans le moniteur série | A | Moniteur série Arduino IDE |
| Données reçues sur le serveur | A + B | `curl http://192.168.57.10:5000/data` |
| PCB gravé sans pont ni rupture | C | Contrôle multimètre |
| Tous les postes connectés au VLAN | B | `ping 192.168.57.10` depuis ESP32 |
