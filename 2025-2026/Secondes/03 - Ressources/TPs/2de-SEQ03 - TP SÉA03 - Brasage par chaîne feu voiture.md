---
type: tp-élève
titre: TP SÉA03 — Brasage par chaîne — feu tricolore voiture
code: 2de-SEQ03-TP-SÉA03
séquence: "[[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]"
classe: Seconde TNE
à_imprimer: true
---

# TP SÉA03 — Brasage par chaîne — feu tricolore voiture

**Nom / Prénom :** ________________________________  **Date :** __________

> **Documents à avoir devant toi :** [[2de-SEQ03 - Schéma électronique]] · ton gabarit perfboard validé en SÉA02 · [[2de-SEQ03 - Fiche mémo brasage]]

---

> [!warning] Règle absolue
> L'Arduino ne se branche **jamais** pendant le brasage. On le connecte **uniquement** pour les tests, après accord de l'enseignant.

---

## Mise en place du poste

Coche chaque point avant de brancher le fer.

| Vérification | Fait ? |
|-------------|--------|
| Gabarit validé (SÉA02) posé devant moi | ⬜ |
| Schéma posé devant moi | ⬜ |
| Lunettes de protection enfilées | ⬜ |
| Blouse portée | ⬜ |
| Ventilation / extracteur allumé | ⬜ |
| Fer posé sur son support, réglé à **350 °C** | ⬜ |
| Éponge humide disponible à côté du fer | ⬜ |

**Validation enseignant avant de commencer :** ⬜

---

## Étape 0 — Fil GND commun

Le fil GND est commun à toutes les LEDs. Il doit être brasé **en premier** — sans lui, aucun test n'est possible.

**Procédure :**

1. Mesurer la distance GND perfboard → GND Arduino : __________ cm
2. Couper le fil noir à __________ cm (distance + 2 cm de marge)
3. Dénuder les deux extrémités sur **5 mm**
4. Étamer les deux extrémités
5. Braser côté perfboard, puis côté Arduino

**Test de continuité au multimètre (mode bip) :**

| Connexion testée | Bip ? | Observation |
|-----------------|-------|-------------|
| GND perfboard → GND Arduino | ⬜ | |

**Si pas de bip :** appeler l'enseignant avant de continuer.

**Validation enseignant :** ⬜

---

## Chaîne 1 — LED rouge voiture (D1 + R1)

### Brasage

| Étape | Description | Fait ? | Observation |
|-------|-------------|--------|-------------|
| 1 | Implanter R1 (220 Ω) à la position du gabarit | ⬜ | |
| 2 | Braser R1 (2 joints) | ⬜ | Aspect des joints : |
| 3 | Vérifier la polarité de D1 rouge (anode côté gabarit) — **appeler l'enseignant** | ⬜ | Validé par : |
| 4 | Implanter D1 rouge | ⬜ | |
| 5 | Braser D1 (2 joints) | ⬜ | Aspect des joints : |
| 6 | Préparer le fil rouge : mesure __________ cm, couper, dénuder 5 mm, étamer | ⬜ | |
| 7 | Braser le fil côté perfboard (anode de R1) | ⬜ | |
| 8 | Braser le fil côté Arduino (broche **D12**) | ⬜ | |

### Test chaîne 1

> Débrancher l'Arduino → brancher l'USB → appeler l'enseignant → lancer le sketch de test.

| Critère | Résultat | Conforme ? |
|---------|----------|------------|
| La LED rouge s'allume au bon moment dans la séquence | | ⬜ |

**Si non conforme :** débrancher l'Arduino, puis identifier le problème :

- [ ] Brasure froide → rebraser
- [ ] Polarité LED inversée → appeler l'enseignant
- [ ] Fil GND non connecté → vérifier continuité GND
- [ ] Autre : ______________________________________________________________

**Validation enseignant :** ⬜

---

## Chaîne 2 — LED orange voiture (D2 + R2)

### Brasage

| Étape | Description | Fait ? | Observation |
|-------|-------------|--------|-------------|
| 1 | Implanter R2 (220 Ω) à la position du gabarit | ⬜ | |
| 2 | Braser R2 (2 joints) | ⬜ | Aspect des joints : |
| 3 | Vérifier la polarité de D2 orange — **appeler l'enseignant** | ⬜ | Validé par : |
| 4 | Implanter D2 orange | ⬜ | |
| 5 | Braser D2 (2 joints) | ⬜ | Aspect des joints : |
| 6 | Préparer le fil orange : mesure __________ cm, couper, dénuder 5 mm, étamer | ⬜ | |
| 7 | Braser le fil côté perfboard (anode de R2) | ⬜ | |
| 8 | Braser le fil côté Arduino (broche **D11**) | ⬜ | |

### Test chaîne 2

| Critère | Résultat | Conforme ? |
|---------|----------|------------|
| La LED orange s'allume au bon moment dans la séquence | | ⬜ |

**Si non conforme :** *(même démarche que chaîne 1)*

**Validation enseignant :** ⬜

---

## Chaîne 3 — LED verte voiture (D3 + R3)

### Brasage

| Étape | Description | Fait ? | Observation |
|-------|-------------|--------|-------------|
| 1 | Implanter R3 (220 Ω) à la position du gabarit | ⬜ | |
| 2 | Braser R3 (2 joints) | ⬜ | Aspect des joints : |
| 3 | Vérifier la polarité de D3 verte — **appeler l'enseignant** | ⬜ | Validé par : |
| 4 | Implanter D3 verte | ⬜ | |
| 5 | Braser D3 (2 joints) | ⬜ | Aspect des joints : |
| 6 | Préparer le fil vert : mesure __________ cm, couper, dénuder 5 mm, étamer | ⬜ | |
| 7 | Braser le fil côté perfboard (anode de R3) | ⬜ | |
| 8 | Braser le fil côté Arduino (broche **D10**) | ⬜ | |

### Test chaîne 3

| Critère | Résultat | Conforme ? |
|---------|----------|------------|
| La LED verte s'allume au bon moment dans la séquence | | ⬜ |

**Validation enseignant :** ⬜

---

## Contrôle final — feu voiture complet

> Brancher l'Arduino et lancer le sketch de test complet.

| Critère | Conforme ? |
|---------|------------|
| LED rouge s'allume | ⬜ |
| LED orange s'allume | ⬜ |
| LED verte s'allume | ⬜ |
| Une seule LED allumée à la fois | ⬜ |
| Aucun composant ne chauffe anormalement | ⬜ |

**Résultat global :**
- [ ] ✅ Feu voiture **conforme** — les 3 chaînes fonctionnent
- [ ] ⚠️ Feu voiture **non conforme** — défaut(s) constaté(s) :

> _________________________________________________________________________

**Validation finale enseignant :** ⬜  *Signature :* ____________________

---

## Rangement du poste

- [ ] Fer éteint et posé sur son support
- [ ] Éponge retirée du porte-fer
- [ ] Lunettes rangées
- [ ] Plan de travail nettoyé (chutes de pattes, résidus d'étain)

---

*Référence : [[2de-SEQ03 - Fiche mémo brasage]] · [[2de-SEQ03 - Schéma électronique]]*
