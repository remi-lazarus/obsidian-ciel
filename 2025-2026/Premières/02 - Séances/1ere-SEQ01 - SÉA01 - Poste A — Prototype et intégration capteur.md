---
type: séance
titre: "Poste A — Prototype et intégration capteur"
code: 1ere-SEQ01-SÉA01
séquence: "[[1ere-SEQ01 - Météo57 Phase 2]]"
classe: Première CIEL
date: 
durée_minutes: 240
compétences:
  - C07
  - C09
type_séance: TP
statut: brouillon
poste: A
parallèle_avec:
  - "[[1ere-SEQ01 - SÉA02 - Poste B — Réseau et serveur]]"
  - "[[1ere-SEQ01 - SÉA03 - Poste C — Fabrication PCB]]"
---

# Poste A — Prototype et intégration capteur

> [!info] Organisation de la séance
> Cette séance se déroule **en parallèle** avec les postes B et C au sein de chaque équipe. L'élève du poste A est également **en binôme** avec l'élève du poste C pendant les temps d'attente CNC. La séance dure **4 heures**.

## 🎯 Objectif de la séance

À l'issue de cette séance, l'élève sera capable d'assembler un prototype fonctionnel intégrant un capteur DS18B20 sur ESP32, de fabriquer un câble JST par sertissage, et de transmettre une mesure de température vers un serveur distant via WiFi.

## 🔗 Contexte dans la séquence

Séance appartenant à → [[1ere-SEQ01 - Météo57 Phase 2]]

> **Mise en situation professionnelle — TechMétéo57**
> Tu es technicien en charge de l'assemblage du nœud de mesure de la station. Les fichiers PCB ont été validés par l'équipe conception, le serveur est en cours de mise en place par ton collègue. Ta mission : assembler le prototype sur breadboard, câbler le capteur, et valider l'envoi des données vers le serveur.

## ⏱️ Déroulé pédagogique

| Phase | Activité | Durée | Mode |
|-------|----------|-------|------|
| Lancement | Présentation des 3 postes, distribution des rôles, récupération du matériel | 15 min | Collectif |
| Câblage DS18B20 | Montage du capteur sur breadboard selon le schéma de câblage | 30 min | Individuel |
| Fabrication câble JST | Sertissage des connecteurs JST sur les fils du capteur | 30 min | Individuel |
| Chaîne d'alimentation | Connexion panneau solaire → TP4056 → batterie → ESP32 | 20 min | Individuel |
| Clonage Git & configuration | Cloner le dépôt, adapter les paramètres WiFi (SSID, IP serveur) | 20 min | Individuel |
| Téléversement & test | Téléverser sur l'ESP32, vérifier le moniteur série, confirmer avec Poste B | 30 min | Individuel |
| Binôme CNC | Aide à l'assemblage Poste C pendant le temps machine | 30 min | Binôme A+C |
| Intégration finale | Vérification croisée avec Poste B — données reçues sur le serveur | 20 min | Équipe |
| Bilan | Remplissage de la fiche de résultats, questions de synthèse | 15 min | Individuel |

## 📋 Contenu

### Mise en situation

La mission de ton poste : faire fonctionner le **nœud de mesure**. Sans capteur opérationnel et sans connexion WiFi, le reste de l'équipe ne peut pas valider son travail. Tu es le premier maillon de la chaîne.

### Activité élève

#### Étape 1 — Câblage du capteur DS18B20

Récupère le schéma de câblage dans la fiche projet :
→ [[Projets/Météo57 Phase 2/01 - Cahier des charges/Fiche projet#Poste A — Prototype et intégration capteur]]

Réalise le montage sur breadboard en respectant :
- [ ] Fil rouge (VCC) → 3,3V ESP32
- [ ] Fil noir (GND) → GND ESP32
- [ ] Fil jaune (Data) → GPIO 4 + résistance 4,7 kΩ vers 3,3V

> [!warning] Point critique
> La résistance pull-up **4,7 kΩ** est indispensable. Sans elle, le bus 1-Wire reste silencieux et aucune donnée ne sera lue.

**Question 1 :** Pourquoi faut-il une résistance pull-up sur le bus 1-Wire ?

*(Espace réponse)*

---

#### Étape 2 — Fabrication du câble JST

Matériel : pince à sertir, dénudeur, fils 28 AWG, contacts JST 2 broches.

Procédure :
1. Couper 2 fils à 30 cm
2. Dénuder sur 3 mm
3. Sertir le contact (côté conducteur + côté isolation)
4. Clipper dans le boîtier jusqu'au **clic**
5. Vérifier la tenue par légère traction

> [!tip] Vérification
> Tirer doucement sur chaque fil après sertissage. Si le contact sort, recommencer.

---

#### Étape 3 — Chaîne d'alimentation

Câbler dans cet ordre :
1. Panneau solaire → bornes `IN+` / `IN−` du module TP4056
2. Batterie LiPo → bornes `BAT+` / `BAT−` du TP4056
3. Sortie `OUT+` / `OUT−` → alimentation de l'ESP32 (via step-up 5V ou directement sur VIN)

> [!warning] Polarité LiPo
> Une inversion de polarité sur la batterie LiPo peut provoquer un court-circuit et un échauffement rapide. Vérifier deux fois avant de connecter.

---

#### Étape 4 — Code et connexion WiFi

```bash
# Sur le poste de travail
git clone git@github.com:remi-lazarus/projet-station-mesure.git
cd projet-station-mesure
```

Ouvrir le fichier principal dans l'Arduino IDE. Localiser les paramètres réseau et les modifier :

```cpp
const char* ssid = "meteo57";        // SSID communiqué par le Poste B
const char* password = "...";        // Mot de passe communiqué par le Poste B
const char* server_ip = "192.168.57.10";  // IP du Raspberry Pi (Poste B)
```

Téléverser sur l'ESP32. Ouvrir le **moniteur série** (115200 bauds).

Messages attendus :
```
Connexion WiFi...
Connecté — IP : 192.168.57.21
Température : 23.4 °C — envoi OK
```

**Question 2 :** Que signifie l'IP affichée ? Qui l'a attribuée ?

*(Espace réponse)*

---

#### Étape 5 — Validation avec le Poste B

Prévenir l'élève du Poste B que l'ESP32 est connecté. Vérifier ensemble que les données apparaissent côté serveur.

**Question 3 :** Quel protocole utilise l'ESP32 pour envoyer les données ? Quelle est la différence avec une transmission Bluetooth ?

*(Espace réponse)*

### Éléments de correction / Points de vigilance

| Étape | Erreur fréquente | Cause | Remédiation |
|-------|-----------------|-------|-------------|
| DS18B20 | Valeur −127°C ou 85°C | Pull-up manquante ou mauvaise broche | Vérifier GPIO 4 et résistance |
| JST | Contact qui sort | Sertissage insuffisant | Recommencer avec pince bien positionnée |
| LiPo | ESP32 ne démarre pas | Batterie déchargée ou polarité inversée | Vérifier tension avec multimètre |
| WiFi | Pas de connexion | SSID/MDP incorrect | Contrôler avec Poste B |
| HTTP | Timeout | Serveur non démarré côté B | Attendre que Poste B confirme |

## 📦 Ressources

- [ ] Énoncé TP : [[TP — Poste A — Prototype et intégration capteur]]
- [ ] Support cours : [[Cours — Capteur DS18B20 et bus 1-Wire]]
- [ ] Grille d'évaluation : [[1ere-SEQ01 - Grille d'évaluation - Poste A]]
- [ ] Fiche projet technique : [[Projets/Météo57 Phase 2/01 - Cahier des charges/Fiche projet]]
- [ ] Matériel : ESP32, DS18B20, breadboard, R 4,7 kΩ, fils Dupont, module TP4056, batterie LiPo, panneau solaire, kit JST, pince à sertir
- [ ] Logiciel : Arduino IDE, accès Git

## ✅ Critères de réussite

- [ ] Câblage DS18B20 correct (confirmé visuellement avant mise sous tension)
- [ ] Câble JST fabriqué et testé mécaniquement
- [ ] Température affichée dans le moniteur série (valeur cohérente entre 15 et 35 °C)
- [ ] Données reçues et confirmées côté serveur (Poste B)
- [ ] Questions 1, 2 et 3 renseignées

## 🔀 Différenciation

> [!help] Aide — si tu bloques sur le câblage
> Consulte la section "Schéma de câblage" de la fiche projet. Un schéma textuel broche par broche est disponible. Appelle l'enseignant si la valeur −127°C persiste après vérification.

> [!success] Approfondissement — si tu termines en avance
> Modifier le code pour envoyer aussi la **valeur minimale et maximale** depuis le démarrage, et les inclure dans la requête HTTP. Documenter la modification dans le code.

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
