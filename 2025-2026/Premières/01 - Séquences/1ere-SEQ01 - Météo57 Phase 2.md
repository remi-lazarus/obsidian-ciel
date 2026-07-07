---
type: séquence
titre: Météo57 — Phase 2 · Fabrication PCB et intégration réseau
code: 1ere-SEQ01
classe: Première CIEL
trimestre: T1
période: 
durée_heures: 12
compétences:
  - C07
  - C09
  - C12
savoirs:
  - S3
  - S4
statut: en cours
fil_rouge: Météo57
---

# Météo57 — Phase 2 · Fabrication PCB et intégration réseau

## 🎯 Objectifs de la séquence

À l'issue de cette séquence, les élèves seront capables de fabriquer un PCB par fraisage CNC à partir de fichiers Gerber, d'intégrer un capteur DS18B20 sur ESP32 et de transmettre les données à un serveur Raspberry Pi via HTTP/REST.

## 🏭 Mise en situation professionnelle

La station météorologique Météo57 doit être opérationnelle. Les fichiers de conception sont validés — il est maintenant temps de passer à la fabrication réelle du circuit imprimé, puis d'intégrer la chaîne de mesure complète jusqu'au serveur de données.

## 📋 Compétences ciblées

| Code | Intitulé | Niveau visé |
|------|----------|-------------|
| [[Compétences#C07\|C07]] | | Approfondissement |
| [[Compétences#C09\|C09]] | | Découverte |
| [[Compétences#C12\|C12]] | | Approfondissement |

## 🗓️ Découpage en séances

> [!info] Organisation par postes parallèles
> La séance unique de 4h est organisée en **3 postes simultanés** au sein de chaque équipe de 3 élèves. L'élève du Poste C (PCB) travaille en binôme avec l'élève du Poste A pendant le temps machine CNC. Une seule CNC est disponible — planning d'accès géré par l'enseignant.

| N° | Titre | Durée | Compétences | Poste | Statut |
|----|-------|-------|-------------|-------|--------|
| [[1ere-SEQ01 - SÉA01 - Poste A — Prototype et intégration capteur\|SÉA01]] | Poste A — Prototype et intégration capteur | 4h | C07, C09 | A | ⬜ |
| [[1ere-SEQ01 - SÉA02 - Poste B — Réseau et serveur\|SÉA02]] | Poste B — Réseau et serveur | 4h | C09, C10 | B | ⬜ |
| [[1ere-SEQ01 - SÉA03 - Poste C — Fabrication PCB sur Technodrill 3\|SÉA03]] | Poste C — Fabrication PCB sur Technodrill 3 | 4h | C07 | C | ⬜ |

## 📦 Ressources nécessaires

- Matériel : ESP32, Raspberry Pi, DS18B20, résistance 4,7 kΩ, fraiseuse Technodrill 3
- Logiciels : Fusion 360 Electronics, GALAAD 3, Arduino IDE, Python 3
- Documents : fiches TPs SÉA01 à SÉA05

## ✅ Critères de réussite de la séquence

- [ ] PCB fabriqué et câblé sans erreur
- [ ] Température transmise et affichée sur le serveur Raspberry Pi
- [ ] Code ESP32 et Python fonctionnels et commentés

## 📝 Notes / Ajustements

