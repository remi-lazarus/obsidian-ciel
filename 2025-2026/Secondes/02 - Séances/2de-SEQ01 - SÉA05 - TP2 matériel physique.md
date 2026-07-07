---
type: séance
titre: TP2 — Réalisation sur du matériel physique
code: 2de-SEQ01-SÉA05
séquence: "[[2de-SEQ01 - Découverte Arduino ESP32]]"
classe: Seconde TNE
date: 
durée_minutes: 120
compétences:
  - C08
  - C09
savoirs:
  - Technologies de raccordement (breadboard, câbles)
  - Outillage spécifique (Arduino IDE)
  - Habilitation électrique niveau B1V (sensibilisation)
type_séance: TP
statut: fait
---

# TP2 — Réalisation sur du matériel physique

## 🎯 Objectif de la séance

À la fin de cette séance, l'élève sera capable de transposer le montage validé en simulation sur breadboard physique, de téléverser le programme via Arduino IDE et de faire fonctionner le feu de circulation sur du matériel réel.

## 🔗 Contexte dans la séquence

Séance appartenant à → [[2de-SEQ01 - Découverte Arduino ESP32]]

Séance de clôture — passage de la simulation à la réalité. La simulation TinkerCAD doit être validée (SÉA04) avant de commencer.

## ⏱️ Déroulé pédagogique

| Phase | Activité | Durée | Mode |
|-------|----------|-------|------|
| Lancement | Rappel des règles de sécurité, distribution du matériel | 10 min | Collectif |
| Câblage | Montage du circuit sur breadboard | 40 min | Binôme |
| Programmation | Ouverture Arduino IDE, import / saisie du code | 20 min | Binôme |
| Téléversement | Connexion USB, compilation, téléversement | 20 min | Binôme |
| Validation | Appel professeur pour démonstration | 20 min | Binôme |
| Bilan | Retour collectif sur les difficultés physiques vs simulation | 10 min | Collectif |

## 📋 Contenu

### Mise en situation

La simulation TechSignal est validée. Il est maintenant temps de monter le vrai circuit et de le faire fonctionner. Le matériel est fourni par le professeur.

### Activité élève

1. **Récupérer le matériel** auprès du professeur :
   - 1 carte Arduino Uno
   - 3 LEDs (rouge, orange, verte)
   - 3 résistances 220 Ω
   - 1 breadboard
   - Câbles de connexion
   - Câble USB

2. **Réaliser le câblage sur breadboard** en s'appuyant sur le schéma validé dans TinkerCAD

3. **Ouvrir Arduino IDE** sur le poste de travail

4. **Saisir ou importer le code** du feu de circulation (peut être recopié depuis TinkerCAD)

5. **Connecter la carte Arduino en USB**, sélectionner le bon port COM et le bon modèle de carte

6. **Compiler et téléverser** le programme (`Ctrl+U`)

7. **Vérifier le fonctionnement** du feu sur le matériel physique

8. **Appeler le professeur pour validation**

### Éléments de correction / Points de vigilance

- Vérifier la sélection du bon port COM si le téléversement échoue
- Vérifier la polarité des LEDs sur breadboard (plus fragile qu'en simulation)
- Si une LED ne s'allume pas : tester avec le multimètre en mode continuité
- Rappeler les règles de manipulation (ne pas alimenter le circuit hors connexion USB)

## 📦 Ressources

- [ ] Énoncé TP : [[2de-SEQ01 - SÉA05 - TP2 Feu de circulation matériel physique]]
- [ ] Grille d'évaluation : [[2de-SEQ01 - Grille d'évaluation]]
- [ ] Matériel : Arduino Uno, 3 LEDs, 3 résistances 220 Ω, breadboard, câbles, USB
- [ ] Arduino IDE installé sur les postes (ou portable)

## ✅ Critères de réussite

- [ ] Le câblage sur breadboard est conforme au schéma
- [ ] Le programme est téléversé sans erreur de compilation
- [ ] Le feu de circulation fonctionne sur le matériel physique
- [ ] La validation professeur est obtenue

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
