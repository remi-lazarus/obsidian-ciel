---
type: tp-élève
titre: "Poste A — Prototype et intégration capteur"
séance: "[[1ere-SEQ01 - SÉA01 - Poste A — Prototype et intégration capteur]]"
séquence: "[[1ere-SEQ01 - Météo57 Phase 2]]"
classe: Première CIEL
compétences:
  - C07
  - C09
durée_minutes: 240
---

# TP — Poste A · Prototype et intégration capteur

---

> **Ta mission :** Tu es technicien en charge du nœud de mesure de la station Météo57. Tu dois assembler le prototype, fabriquer le câble du capteur, et envoyer les mesures de température vers le serveur de ton équipe. Sans toi, la chaîne entière est muette.

---

## ✅ Suivi d'avancement

Coche chaque étape au fur et à mesure.

- [ ] Étape 1 — Câblage DS18B20
- [ ] Étape 2 — Fabrication câble JST
- [ ] Étape 3 — Chaîne d'alimentation
- [ ] Étape 4 — Configuration et téléversement du code
- [ ] Étape 5 — Validation avec le Poste B
- [ ] Questions complétées

---

## Étape 1 — Câblage du capteur DS18B20

### 1.1 Identifier les broches du capteur

Le capteur DS18B20 câblé a 3 fils. Complète le tableau ci-dessous en t'aidant de la fiche projet.

| Fil | Couleur | Fonction | Destination sur l'ESP32 |
|-----|---------|----------|------------------------|
| 1 | | | |
| 2 | | | |
| 3 | | | |

### 1.2 Schéma de câblage à compléter

Reporte les connexions sur le schéma ci-dessous :

```
         ESP32
      ┌─────────┐
3,3V ─┤         ├─── ?
      │         │
GND  ─┤         ├─── ?
      │         │
GPIO4─┤         ├─── ?
      └─────────┘
          │
          R = ______ Ω
          │
      DS18B20
   VCC | Data | GND
    ?  |  ?   |  ?
```

### 1.3 Réalisation

Monte le circuit sur la breadboard. Fais vérifier par l'enseignant avant de mettre sous tension.

> [!warning] STOP — Validation enseignant
> ☐ Câblage vérifié par l'enseignant avant mise sous tension

---

## ❓ Question 1

**Pourquoi faut-il une résistance pull-up entre la broche Data et le 3,3V ? Que se passe-t-il si on l'oublie ?**

*(Ta réponse — 3 à 5 lignes)*

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

---

## Étape 2 — Fabrication du câble JST

Tu vas fabriquer le câble qui relie le capteur DS18B20 à la breadboard.

**Matériel nécessaire :** pince à sertir, dénudeur, 2 fils 28 AWG (~30 cm), 2 contacts JST, 1 boîtier JST 2 broches.

### Procédure

| N° | Action | ✓ |
|----|--------|---|
| 1 | Couper 2 fils à 30 cm | ☐ |
| 2 | Dénuder les extrémités sur 3 mm | ☐ |
| 3 | Insérer le fil dans le contact JST (côté ouvert vers le haut) | ☐ |
| 4 | Sertir : mâchoire large sur l'isolation, mâchoire fine sur le conducteur | ☐ |
| 5 | Clipper le contact dans le boîtier jusqu'au clic | ☐ |
| 6 | Vérifier la tenue par légère traction sur chaque fil | ☐ |

**Résultat du test de traction :**

| Fil | Résiste à la traction ? | À refaire ? |
|-----|------------------------|-------------|
| Fil 1 | ☐ Oui  ☐ Non | ☐ |
| Fil 2 | ☐ Oui  ☐ Non | ☐ |

---

## Étape 3 — Chaîne d'alimentation

### 3.1 Identifier les composants

Avant de câbler, identifie les bornes de chaque composant. Note tes observations :

| Composant | Borne + | Borne − | Tension nominale |
|-----------|---------|---------|-----------------|
| Panneau solaire | | | |
| Module TP4056 IN | | | |
| Module TP4056 BAT | | | |
| Module TP4056 OUT | | | |
| Batterie LiPo | | | |

### 3.2 Câblage

Réalise les connexions dans cet ordre (cocher au fur et à mesure) :

- [ ] Panneau solaire → `IN+` / `IN−` du TP4056
- [ ] Batterie LiPo → `BAT+` / `BAT−` du TP4056
- [ ] Sortie `OUT+` / `OUT−` → alimentation ESP32

> [!warning] Polarité LiPo
> Une inversion de polarité peut provoquer un échauffement rapide. Fais vérifier par l'enseignant avant de connecter la batterie.

> [!warning] STOP — Validation enseignant
> ☐ Câblage alimentation vérifié avant connexion batterie

---

## Étape 4 — Code et connexion WiFi

### 4.1 Cloner le dépôt

```bash
git clone git@github.com:remi-lazarus/projet-station-mesure.git
cd projet-station-mesure
```

Ouvrir le fichier principal dans l'Arduino IDE.

### 4.2 Paramètres réseau à modifier

Demande à l'élève du **Poste B** les informations réseau, puis renseigne-les dans le code :

| Paramètre | Valeur communiquée par Poste B |
|-----------|-------------------------------|
| SSID WiFi | |
| Mot de passe | |
| IP du serveur | |

Modifie les lignes correspondantes dans le code, puis téléverse sur l'ESP32.

### 4.3 Vérification dans le moniteur série

Ouvre le moniteur série (vitesse : **115 200 bauds**).

Note les messages affichés :

```
(Recopie ici les 5 premières lignes du moniteur série)




```

La valeur de température affichée est : _______ °C

Cette valeur te semble-t-elle cohérente avec la température ambiante ? ☐ Oui  ☐ Non

Si non, note le problème observé et la solution trouvée :

&nbsp;

&nbsp;

---

## ❓ Question 2

**L'ESP32 affiche une adresse IP (ex. `192.168.57.21`). Qui lui a attribué cette adresse ? Comment s'appelle ce mécanisme ?**

&nbsp;

&nbsp;

&nbsp;

---

## Étape 5 — Validation avec le Poste B

Préviens l'élève du Poste B que l'ESP32 est connecté. Vérifiez ensemble que les données arrivent côté serveur.

Résultat affiché côté serveur (JSON reçu) :

```json

```

- [ ] Données reçues et confirmées par le Poste B ✓

---

## ❓ Question 3

**Quel protocole utilise l'ESP32 pour envoyer les données de température au Raspberry Pi ? En quoi est-ce différent d'une communication Bluetooth ?**

*(3 à 5 lignes)*

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;
