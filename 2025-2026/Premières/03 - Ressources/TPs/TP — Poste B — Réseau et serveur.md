---
type: tp-élève
titre: "Poste B — Réseau et serveur"
séance: "[[1ere-SEQ01 - SÉA02 - Poste B — Réseau et serveur]]"
séquence: "[[1ere-SEQ01 - Météo57 Phase 2]]"
classe: Première CIEL
compétences:
  - C09
  - C10
durée_minutes: 240
---

# TP — Poste B · Réseau et serveur

---

> **Ta mission :** Tu es technicien réseau en charge de l'infrastructure de la station Météo57. Tu dois créer un réseau local sécurisé et isolé, démarrer le serveur qui recevra les mesures de l'ESP32 de ton équipe, et vérifier que tout communique correctement. Tu es le pilier de la chaîne : sans toi, personne ne peut valider son travail.

---

## ✅ Suivi d'avancement

- [ ] Étape 1 — Configuration du routeur WiFi
- [ ] Étape 2 — Configuration IP fixe du Raspberry Pi
- [ ] Étape 3 — Démarrage du serveur Flask
- [ ] Étape 4 — Test local du serveur
- [ ] Étape 5 — Communication avec Poste A et validation croisée
- [ ] Questions complétées

---

## Étape 1 — Configuration du routeur WiFi

### 1.1 Schéma du réseau à compléter

Complète le schéma en renseignant les adresses IP manquantes :

```
        ┌──────────────────────────────────┐
        │   Réseau : 192.168.57.0 / ___    │
        │                                   │
        │  Routeur WiFi                     │
        │  IP passerelle : 192.168.___.___  │
        │  SSID : ___________               │
        │  DHCP : ___.___.___.20 → .100    │
        └───────────┬──────────────────────┘
                    │
        ┌───────────┴────────────┐
        │                        │
   Raspberry Pi              ESP32
   IP : ___.___.57.___      IP : (DHCP)
   (fixe)
```

### 1.2 Paramètres à configurer sur le routeur

Accéder à l'interface d'administration (adresse fournie par l'enseignant : ________________).

| Paramètre | Valeur à saisir | Fait ✓ |
|-----------|----------------|--------|
| SSID | `meteo57` | ☐ |
| Fréquence | 2,4 GHz | ☐ |
| Sécurité | WPA2 | ☐ |
| Mot de passe | *(à définir)* : _____________ | ☐ |
| Plage DHCP | 192.168.57.20 → 192.168.57.100 | ☐ |
| IP passerelle | 192.168.57.1 | ☐ |
| Accès internet / WAN | Désactivé | ☐ |

Note le mot de passe choisi ici (tu devras le communiquer au Poste A) : ________________________

---

## ❓ Question 1

**Qu'est-ce qu'un VLAN ? En quoi isole-t-il le trafic réseau d'un autre réseau ? Donne un exemple d'utilisation en milieu industriel.**

*(3 à 5 lignes)*

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

---

## Étape 2 — Configuration de l'adresse IP fixe du Raspberry Pi

### 2.1 Vérifier l'interface réseau active

Dans un terminal du Raspberry Pi :

```bash
ip addr show
```

Note le nom de l'interface réseau utilisée (ex. `wlan0`, `eth0`) : _______________

### 2.2 Configurer l'IP fixe

Méthode utilisée (entoure) : **Interface graphique** / **Ligne de commande**

Après configuration, vérifier :

```bash
hostname -I
```

Adresse IP affichée : ___________________________

Est-ce bien `192.168.57.10` ? ☐ Oui  ☐ Non (si non, noter le problème : _____________)

### 2.3 Tester la passerelle

```bash
ping 192.168.57.1 -c 4
```

Résultat (recopie la dernière ligne) :

```

```

La passerelle répond ? ☐ Oui  ☐ Non

---

## Étape 3 — Démarrage du serveur Flask

### 3.1 Cloner le dépôt

```bash
git clone git@github.com:remi-lazarus/projet-station-mesure.git
cd projet-station-mesure
```

### 3.2 Démarrer le serveur

```bash
python3 serveur.py
```

Message affiché au démarrage (recopie) :

```

```

Le serveur écoute sur le port : _______________

---

## ❓ Question 2

**Le serveur écoute sur `0.0.0.0`. Quelle est la différence avec `127.0.0.1` ? Pourquoi `0.0.0.0` est-il indispensable ici ?**

&nbsp;

&nbsp;

&nbsp;

&nbsp;

---

## Étape 4 — Test local du serveur

Dans un **second terminal** sur le Raspberry Pi :

```bash
curl http://127.0.0.1:5000/data
```

Réponse affichée :

```json

```

Cette réponse est-elle normale à ce stade ? Explique pourquoi :

&nbsp;

&nbsp;

---

## Étape 5 — Communication avec Poste A et validation

### 5.1 Informations à transmettre au Poste A

Donne à l'élève du Poste A les informations suivantes :

| Information | Valeur |
|-------------|--------|
| SSID WiFi | `meteo57` |
| Mot de passe | |
| IP du serveur | `192.168.57.10` |

### 5.2 Vérification de réception

Quand le Poste A a téléversé et connecté l'ESP32, vérifier depuis le Raspberry Pi :

```bash
curl http://192.168.57.10:5000/data
```

JSON reçu (recopie) :

```json

```

Température reçue : _______ °C   —   Timestamp : _______________________

Dans les logs du serveur (premier terminal), note ce qui apparaît à chaque envoi ESP32 :

```

```

### 5.3 Vérification depuis un autre terminal (navigateur ou autre machine)

URL testée : ________________________________

Résultat :

```json

```

---

## ❓ Question 3

**À quelle fréquence l'ESP32 envoie-t-il les données ? Comment l'as-tu déterminé ?**

&nbsp;

&nbsp;

&nbsp;

---

## ❓ Question 4 — Test de robustesse

**Coupe le WiFi du routeur pendant 30 secondes, puis rallume-le. Observe et décris ce qui se passe :**
- Côté logs serveur :
- Côté moniteur série de l'ESP32 (Poste A) :
- Quand la connexion revient-elle ?

&nbsp;

&nbsp;

&nbsp;

&nbsp;

**Quel mécanisme du code permet à l'ESP32 de se reconnecter automatiquement ?** *(si tu peux l'observer dans le code)*

&nbsp;

&nbsp;

