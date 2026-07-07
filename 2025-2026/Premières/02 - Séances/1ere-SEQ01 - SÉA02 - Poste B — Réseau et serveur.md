---
type: séance
titre: "Poste B — Réseau et serveur"
code: 1ere-SEQ01-SÉA02
séquence: "[[1ere-SEQ01 - Météo57 Phase 2]]"
classe: Première CIEL
date: 
durée_minutes: 240
compétences:
  - C09
  - C10
type_séance: TP
statut: brouillon
poste: B
parallèle_avec:
  - "[[1ere-SEQ01 - SÉA01 - Poste A — Prototype et intégration capteur]]"
  - "[[1ere-SEQ01 - SÉA03 - Poste C — Fabrication PCB]]"
---

# Poste B — Réseau et serveur

> [!info] Organisation de la séance
> Cette séance se déroule **en parallèle** avec les postes A et C au sein de chaque équipe. L'élève du poste B est responsable de l'infrastructure réseau et du serveur. Sans lui, ni le Poste A ni le terminal de vérification ne peuvent fonctionner. La séance dure **4 heures**.

## 🎯 Objectif de la séance

À l'issue de cette séance, l'élève sera capable de configurer un réseau WiFi local isolé (VLAN dédié sans accès internet), de démarrer un serveur Flask sur Raspberry Pi, et de vérifier la réception des données de température depuis l'ESP32.

## 🔗 Contexte dans la séquence

Séance appartenant à → [[1ere-SEQ01 - Météo57 Phase 2]]

> **Mise en situation professionnelle — TechMétéo57**
> Tu es technicien réseau en charge de l'infrastructure de la station. Ta mission : créer un réseau local sécurisé et isolé pour que l'ESP32 de ton collègue puisse envoyer ses mesures au serveur que tu vas démarrer. Aucune donnée ne doit transiter par internet — le réseau est entièrement local.

## ⏱️ Déroulé pédagogique

| Phase | Activité | Durée | Mode |
|-------|----------|-------|------|
| Lancement | Présentation des 3 postes, distribution des rôles, récupération du matériel | 15 min | Collectif |
| Configuration routeur | Paramétrage du réseau WiFi (SSID, DHCP, IP fixe RPi, isolation WAN) | 40 min | Individuel |
| Vérification réseau | Test de connectivité entre le Raspberry Pi et le routeur | 20 min | Individuel |
| Clonage Git & serveur | Cloner le dépôt, démarrer le serveur Flask | 25 min | Individuel |
| Vérification locale | Tester le serveur en local sur le Raspberry Pi | 20 min | Individuel |
| Communication Poste A | Transmettre SSID/MDP à Poste A, attendre connexion ESP32 | 15 min | Binôme B+A |
| Validation croisée | Vérifier la réception des données sur le serveur (curl + navigateur) | 30 min | Équipe |
| Analyse des trames | Observer et analyser les requêtes reçues, interpréter les logs | 20 min | Individuel |
| Bilan | Remplissage de la fiche de résultats, questions de synthèse | 15 min | Individuel |

## 📋 Contenu

### Mise en situation

Sans réseau fonctionnel, la station entière est muette. C'est toi qui permets la communication entre l'ESP32 et le serveur. Tu dois être **opérationnel avant** que le Poste A ait fini son câblage.

### Activité élève

#### Étape 1 — Configuration du routeur WiFi

Accéder à l'interface d'administration du routeur (adresse selon le modèle — vérifier avec l'enseignant).

Paramètres à configurer :

| Paramètre | Valeur |
|-----------|--------|
| SSID | `meteo57` |
| Fréquence | 2,4 GHz |
| Sécurité | WPA2 |
| Mot de passe | *(à définir avec l'enseignant)* |
| Plage DHCP | 192.168.57.20 → 192.168.57.100 |
| IP passerelle | 192.168.57.1 |
| Accès WAN/Internet | Désactivé |

> [!warning] Pourquoi désactiver l'accès internet ?
> Le projet est un réseau industriel interne. Les données de mesure ne doivent pas quitter le site. C'est une exigence de sécurité courante en milieu industriel.

**Question 1 :** Qu'est-ce qu'un VLAN ? En quoi isole-t-il le trafic réseau ?

*(Espace réponse)*

---

#### Étape 2 — Configuration de l'adresse IP fixe du Raspberry Pi

Sur le Raspberry Pi, ouvrir un terminal et configurer l'IP fixe.

**Méthode A — via l'interface graphique (Raspberry Pi OS Desktop) :**
Clic droit sur l'icône réseau → Paramètres réseau → IP manuelle : `192.168.57.10` / masque : `255.255.255.0` / passerelle : `192.168.57.1`

**Méthode B — en ligne de commande :**
```bash
# Vérifier l'interface réseau active
ip addr show
# Affiche wlan0 ou eth0 selon la connexion
```

Vérifier l'attribution :
```bash
hostname -I
# Doit afficher : 192.168.57.10
```

Tester la passerelle :
```bash
ping 192.168.57.1
# Doit répondre (TTL=64)
```

> [!tip] Si le ping échoue
> Vérifier que le Raspberry Pi est bien connecté au bon réseau WiFi (`meteo57`) ou en Ethernet au routeur.

---

#### Étape 3 — Démarrage du serveur Flask

```bash
# Cloner le dépôt
git clone git@github.com:remi-lazarus/projet-station-mesure.git
cd projet-station-mesure

# Démarrer le serveur
python3 serveur.py
```

Message attendu au démarrage :
```
 * Running on http://0.0.0.0:5000
 * Debug mode: off
```

> [!info] Que fait `0.0.0.0` ?
> Cela signifie que le serveur écoute sur **toutes les interfaces réseau** du Raspberry Pi — pas seulement sur localhost. C'est indispensable pour être joignable depuis l'ESP32.

**Question 2 :** Quelle est la différence entre `0.0.0.0` et `127.0.0.1` pour un serveur ?

*(Espace réponse)*

---

#### Étape 4 — Test local du serveur

Sur le Raspberry Pi (dans un second terminal) :
```bash
curl http://127.0.0.1:5000/data
```

Réponse attendue :
```json
{"message": "Aucune donnée reçue pour l'instant"}
```

(Pas encore de donnée — c'est normal, l'ESP32 n'est pas encore connecté.)

---

#### Étape 5 — Communication avec le Poste A

Transmettre à l'élève du Poste A :
- **SSID :** `meteo57`
- **Mot de passe :** *(celui configuré à l'étape 1)*
- **IP du serveur :** `192.168.57.10`

Attendre que le moniteur série du Poste A affiche "Connecté".

---

#### Étape 6 — Validation et analyse des données reçues

Depuis le Raspberry Pi (terminal) :
```bash
curl http://192.168.57.10:5000/data
```

Depuis un terminal élève (navigateur ou curl) :
```bash
curl http://192.168.57.10:5000/data
# ou ouvrir dans Firefox : http://192.168.57.10:5000/data
```

Réponse attendue :
```json
{"temperature": 23.4, "timestamp": "2026-04-06T10:23:00"}
```

Surveiller les logs du serveur dans le premier terminal — chaque requête ESP32 doit apparaître.

**Question 3 :** À quelle fréquence l'ESP32 envoie-t-il les données ? Comment le vérifies-tu ?

*(Espace réponse)*

**Question 4 :** Que se passe-t-il si tu coupes le WiFi du routeur pendant 30 secondes, puis le rallumes ? Teste et observe.

*(Espace réponse)*

### Éléments de correction / Points de vigilance

| Étape | Erreur fréquente | Cause | Remédiation |
|-------|-----------------|-------|-------------|
| Routeur | ESP32 ne se connecte pas | SSID/MDP mal saisi dans le code | Vérifier avec Poste A |
| IP fixe | RPi garde une IP DHCP | Config IP non sauvegardée | Redémarrer le RPi après config |
| Flask | `Address already in use` | Serveur déjà lancé | `kill $(lsof -t -i:5000)` puis relancer |
| curl | `Connection refused` | Serveur non démarré | Vérifier que `python3 serveur.py` tourne |
| Données | JSON vide | ESP32 non connecté | Attendre connexion Poste A |

## 📦 Ressources

- [ ] Énoncé TP : [[TP — Poste B — Réseau et serveur]]
- [ ] Support cours : [[Cours — Réseaux locaux et architecture client-serveur]]
- [ ] Grille d'évaluation : [[1ere-SEQ01 - Grille d'évaluation - Poste B]]
- [ ] Fiche projet technique : [[Projets/Météo57 Phase 2/01 - Cahier des charges/Fiche projet]]
- [ ] Matériel : Raspberry Pi (avec OS installé), routeur WiFi, câble Ethernet, câble alimentation RPi
- [ ] Logiciel : Terminal Linux, Git, Python 3, Flask (installé), navigateur web

## ✅ Critères de réussite

- [ ] SSID `meteo57` visible et accessible depuis un autre appareil
- [ ] Raspberry Pi joignable à l'adresse `192.168.57.10` (ping OK)
- [ ] Serveur Flask démarré et accessible en local (`curl http://127.0.0.1:5000/data`)
- [ ] Données de température reçues et affichées après connexion ESP32 (Poste A)
- [ ] Questions 1, 2, 3 et 4 renseignées

## 🔀 Différenciation

> [!help] Aide — si la configuration réseau bloque
> Demander à l'enseignant la procédure spécifique au routeur disponible. Un aide-mémoire des commandes Linux de base est disponible si besoin. Se concentrer en priorité sur le démarrage du serveur (étape 3) pendant que le routeur est configuré.

> [!success] Approfondissement — si tu termines en avance
> Modifier le serveur pour **stocker l'historique** des 10 dernières valeurs et les afficher en JSON via un endpoint `/history`. Documenter la modification dans le code.

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
