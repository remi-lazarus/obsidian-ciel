---
type: séance
titre: TD1 — Réaliser un feu de circulation
code: 2de-SEQ01-SÉA04
séquence: "[[2de-SEQ01 - Découverte Arduino ESP32]]"
classe: Seconde TNE
date: 
durée_minutes: 120
compétences:
  - C08
  - C09
savoirs:
  - Principes fondamentaux de programmation (variables, boucles)
  - Technologies de raccordement (câblage LED / résistance)
  - Schéma électronique
type_séance: TD
statut: fait
---

# TD1 — Réaliser un feu de circulation

## 🎯 Objectif de la séance

À la fin de cette séance, l'élève sera capable de câbler et de programmer un feu de circulation tricolore fonctionnel dans TinkerCAD, en respectant les temporisations imposées.

## 🔗 Contexte dans la séquence

Séance appartenant à → [[2de-SEQ01 - Découverte Arduino ESP32]]

Activité centrale de la séquence — réalisation complète sur simulateur avant passage au matériel physique (SÉA05).

## ⏱️ Déroulé pédagogique

| Phase | Activité | Durée | Mode |
|-------|----------|-------|------|
| Lancement | Rappel du fonctionnement d'un feu tricolore | 10 min | Collectif |
| Présentation | Explication du cahier des charges | 10 min | Collectif |
| Activité principale | Câblage + programmation dans TinkerCAD | 85 min | Individuel |
| Validation | Appel professeur pour démonstration | 10 min | Individuel |
| Bilan | Mise en commun des difficultés | 5 min | Collectif |

## 📋 Contenu

### Mise en situation

Chez **TechSignal**, la première mission est de prototyper un feu de signalisation. Le responsable technique attend une simulation fonctionnelle avant toute commande de matériel.

### Activité élève

**Cahier des charges — cycles du feu :**

| Couleur | Durée | Signification |
|---------|-------|---------------|
| 🟢 Vert  | 10 s  | Les véhicules peuvent avancer |
| 🟠 Orange | 3 s  | Les véhicules doivent s'arrêter |
| 🔴 Rouge | 10 s  | Les véhicules sont immobilisés |

**Travail à réaliser :**
1. Créer le circuit dans TinkerCAD avec 3 LEDs (rouge, orange, verte) + 3 résistances de protection
2. Câbler chaque LED sur une broche numérique distincte (ex. D11=rouge, D12=orange, D13=verte)
3. Écrire le code Arduino (langage C ou blocs) pour faire défiler les couleurs dans l'ordre correct
4. S'assurer que **chaque LED est bien éteinte** avant d'allumer la suivante
5. Tester le programme en simulation
6. **Appeler le professeur pour validation**

### Éléments de correction / Points de vigilance

- Rappeler `pinMode(pin, OUTPUT)` dans `setup()`
- Vérifier que les `delay()` correspondent aux bonnes durées (×1000 pour secondes)
- Pièges fréquents : oublier d'éteindre la LED précédente, mauvais câblage du GND commun
- Ordre attendu : vert → orange → rouge → vert (boucle infinie dans `loop()`)

## 📦 Ressources

- [ ] Énoncé TD : [[2de-SEQ01 - SÉA04 - TD1 Feu de circulation]]
- [ ] Cours de référence : [[2de-SEQ01 - SÉA03 - TinkerCAD prise en main]]
- [ ] TinkerCAD : https://www.tinkercad.com/

## ✅ Critères de réussite

- [ ] Les 3 LEDs sont câblées correctement avec résistances
- [ ] La séquence vert → orange → rouge est respectée
- [ ] Les temporisations (10 s / 3 s / 10 s) sont correctes
- [ ] La simulation est validée par le professeur

## 📝 Bilan après séance

> À remplir après le cours.

- Ce qui a bien fonctionné :
- Ce qui est à revoir :
- Ajustements pour la prochaine fois :
