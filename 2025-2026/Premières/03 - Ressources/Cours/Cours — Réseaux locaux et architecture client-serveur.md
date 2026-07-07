---
type: cours
titre: "Réseaux locaux et architecture client-serveur"
séquence: "[[1ere-SEQ01 - Météo57 Phase 2]]"
classe: Première CIEL
compétences:
  - C09
  - C10
lié_au_poste: B
---

# Fiche cours — Réseaux locaux et architecture client-serveur

## 1. Adressage IPv4

Chaque appareil sur un réseau IP possède une **adresse IP** qui l'identifie de façon unique sur ce réseau.

### Structure d'une adresse IP

Une adresse IPv4 est composée de **4 octets** séparés par des points : `192.168.57.10`

Le **masque de sous-réseau** indique quelle partie de l'adresse identifie le réseau et quelle partie identifie l'hôte.

| Adresse | Masque | Réseau | Hôtes possibles |
|---------|--------|--------|-----------------|
| 192.168.57.10 | 255.255.255.0 (/24) | 192.168.57.0 | .1 à .254 |

### Adresses particulières

| Adresse | Signification |
|---------|--------------|
| `192.168.57.1` | Passerelle (routeur) |
| `192.168.57.255` | Broadcast (tous les appareils) |
| `127.0.0.1` | Loopback — l'appareil lui-même (localhost) |
| `0.0.0.0` | Toutes les interfaces de l'appareil |

---

## 2. DHCP — Attribution automatique des adresses

Le **DHCP** (Dynamic Host Configuration Protocol) est un service réseau qui attribue automatiquement une adresse IP à chaque appareil qui se connecte.

```
ESP32 se connecte au WiFi
        │
        ▼ "J'ai besoin d'une adresse IP"
      Routeur
        │
        ▼ "Voici ton IP : 192.168.57.21, valable 24h"
      ESP32 → IP : 192.168.57.21
```

**Avantage :** pas besoin de configurer manuellement chaque appareil.
**Inconvénient :** l'adresse peut changer d'une connexion à l'autre → pour le serveur, on préfère une **IP fixe (statique)**.

---

## 3. VLAN — Réseau local virtuel

Un **VLAN** (Virtual Local Area Network) est un réseau logique qui isole un groupe d'appareils du reste du réseau physique, même s'ils partagent la même infrastructure.

### Pourquoi utiliser un VLAN pour Météo57 ?

- **Sécurité** : les données de mesure restent sur le réseau interne, sans accès internet
- **Isolation** : les appareils du projet ne peuvent pas communiquer avec d'autres réseaux
- **Maîtrise du trafic** : on sait exactement qui communique avec qui

```
Réseau global de l'établissement
┌─────────────────────────────────────┐
│  Réseau admin  │  VLAN Météo57      │
│  192.168.1.x   │  192.168.57.x     │
│                │  ┌─────┐ ┌─────┐  │
│                │  │ RPi │ │ESP32│  │
│                │  └─────┘ └─────┘  │
└─────────────────────────────────────┘
         ↑ Trafic isolé entre les deux réseaux
```

---

## 4. Architecture client-serveur

Dans l'architecture client-serveur :
- Le **serveur** attend les connexions et traite les requêtes
- Le **client** initie la connexion et envoie des requêtes

Dans notre projet :

| Rôle | Appareil | Action |
|------|----------|--------|
| Client | ESP32 | Envoie les données de température (HTTP POST) |
| Serveur | Raspberry Pi | Reçoit et stocke les données |
| Client de vérification | PC / terminal | Consulte les données (HTTP GET) |

---

## 5. Protocole HTTP

Le **HTTP** (HyperText Transfer Protocol) est le protocole de communication utilisé sur le Web, mais aussi dans l'IoT pour transmettre des données entre appareils.

### Méthodes principales

| Méthode | Usage | Exemple |
|---------|-------|---------|
| GET | Lire une donnée | `GET /data` → retourne la température |
| POST | Envoyer une donnée | `POST /data` avec `{"temperature": 23.4}` |

### Structure d'une URL

```
http://192.168.57.10:5000/data
  │        │            │    │
 Protocole  IP serveur  Port  Chemin
```

**Port 5000** : port par défaut du serveur Flask (Python). Le port 80 est le port HTTP standard.

---

## 6. Flask — Serveur Python léger

Flask est un framework Python qui permet de créer un serveur HTTP en quelques lignes de code. Il est très utilisé pour les projets IoT et les prototypes.

```python
from flask import Flask, jsonify
app = Flask(__name__)

@app.route('/data', methods=['GET'])
def get_data():
    return jsonify({"temperature": 23.4})

app.run(host='0.0.0.0', port=5000)
```

- `host='0.0.0.0'` : écoute sur toutes les interfaces (accessible depuis le réseau)
- `host='127.0.0.1'` : écoute uniquement en local (accessible uniquement sur le Raspberry Pi lui-même)
- `port=5000` : port d'écoute

---

## 7. Commandes Linux utiles (Raspberry Pi)

| Commande | Utilité |
|----------|---------|
| `ip addr show` | Afficher les interfaces réseau et adresses IP |
| `hostname -I` | Afficher l'adresse IP de la machine |
| `ping 192.168.57.1` | Tester la connectivité vers la passerelle |
| `curl http://192.168.57.10:5000/data` | Envoyer une requête GET HTTP et afficher la réponse |
| `python3 serveur.py` | Démarrer le serveur Flask |
| `git clone <url>` | Copier un dépôt Git sur la machine |
