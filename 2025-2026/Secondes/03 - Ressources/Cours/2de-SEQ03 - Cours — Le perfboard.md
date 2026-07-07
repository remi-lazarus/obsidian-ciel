---
type: cours
titre: Le perfboard — présentation et utilisation
code: 2de-SEQ03-cours-perfboard
séquence: "[[2de-SEQ03 - Prototype feux de circulation sur plaque à souder]]"
séance: "[[2de-SEQ03 - SÉA02 - Lecture de schéma électronique]]"
classe: Seconde TNE
---

# Le perfboard — présentation et utilisation

> À lire avant de compléter le gabarit d'implantation (SÉA02). Document de référence pour SÉA03 et SÉA04.

---

## 1. C'est quoi un perfboard ?

Un **perfboard** (aussi appelé *plaque à braser*, *plaque à pastilles* ou *veroboard*) est une plaque en résine époxy percée de trous régulièrement espacés. Chaque trou est entouré d'un petit anneau de cuivre appelé **pastille**.

```
Vue de dessus (face composants) :

  ○  ○  ○  ○  ○  ○  ○  ○  ○  ○
  ○  ○  ○  ○  ○  ○  ○  ○  ○  ○
  ○  ○  ○  ○  ○  ○  ○  ○  ○  ○
  ○  ○  ○  ○  ○  ○  ○  ○  ○  ○

Chaque ○ = un trou avec sa pastille de cuivre
Espacement entre trous : 2,54 mm (= 0,1 pouce)
```

> **C'est le même espacement que sur une breadboard.** Un composant qui tenait sur breadboard tiendra sur perfboard sans plier les pattes.

---

## 2. Quelle différence avec la breadboard ?

|                               | Breadboard                   | Perfboard                       |
| ----------------------------- | ---------------------------- | ------------------------------- |
| **Connexion**                 | Par enclipsage (réversible)  | Par brasure (permanente)        |
| **Robustesse**                | Fragile — connexion instable | Solide — résiste aux vibrations |
| **Modification**              | Immédiate                    | Difficile (débraser)            |
| **Utilisation**               | Prototypage, test            | Prototype livrable, démo        |
| **Les trous se connectent ?** | Oui — rails intégrés         | **Non — isolés par défaut**     |

> ⚠️ **Point clé :** sur un perfboard, **les trous ne sont pas reliés entre eux**. Contrairement à la breadboard, il n'y a pas de rails internes. C'est toi qui crées chaque connexion, soit par l'étain (brasure directe entre deux pastilles adjacentes), soit par un fil de connexion.

---

## 3. Les deux faces du perfboard

```
┌──────────────────────────────┐    ┌──────────────────────────────┐
│  FACE COMPOSANTS (dessus)    │    │  FACE BRASURE (dessous)      │
│                              │    │                              │
│  Les composants sont         │    │  Les brasures sont faites    │
│  insérés par le dessus,      │    │  sur cette face — les pattes │
│  pattes passant au travers   │    │  dépassent et sont brasées   │
│  des trous                   │    │  sur les pastilles           │
└──────────────────────────────┘    └──────────────────────────────┘
```

**Méthode de travail :**
1. Poser le perfboard face composants vers le haut
2. Insérer les pattes du composant dans les trous
3. Retourner le perfboard — les pattes dépassent côté brasure
4. Braser sur les pastilles côté brasure
5. Couper les pattes en excédent avec la pince coupante

---

## 4. Comment créer une connexion ?

### Connexion directe par étain (pour deux pastilles voisines)

Si deux composants ont leurs pattes dans deux trous **adjacents** et doivent être reliés, on peut simplement laisser l'étain former un pont entre les deux pastilles lors de la brasure.

```
  pastille A ──[étain]── pastille B
```

> À utiliser avec prudence : ne pas créer de pont involontaire entre deux pistes qui ne doivent pas être reliées.

### Connexion par fil (pour deux pastilles éloignées)

Quand deux points à relier sont distants, on utilise un **fil de connexion** brasé aux deux extrémités.

```
  pastille A ──[fil brasé]──────────────────── pastille B
```

> C'est ce que vous ferez en SÉA04 pour relier le perfboard à l'Arduino.

### Nœud commun (masse ou alimentation)

Pour les connexions qui concernent plusieurs composants (par exemple, toutes les cathodes des LEDs reliées à GND), on crée un **bus commun** : une ligne de trous reliés entre eux par des courts fils ou une piste d'étain continue.

```
  GND Arduino ──── fil ──── ○──○──○──○──○  ← ligne GND commune
                             ↑  ↑  ↑  ↑  ↑
                            cathodes des 5 LEDs
```

---

## 5. Règles d'implantation

### Orientation des composants polarisés

Les **LEDs** et les **condensateurs électrolytiques** ont une polarité — si on les braser à l'envers, ils ne fonctionnent pas (ou se détruisent). **Vérifier la polarité avant d'insérer le composant.**

| Composant          | Repère anode (+)           | Repère cathode (−)                   |
| ------------------ | -------------------------- | ------------------------------------ |
| LED                | Patte longue               | Patte courte + méplat sur le boîtier |
| Condensateur élec. | Marquage + ou patte longue | Bande blanche sur le corps           |

### Espacement minimal entre composants

Laisser **au moins un trou libre** entre deux composants voisins pour :
- Pouvoir accéder à chaque pastille avec la panne du fer
- Éviter les ponts de brasure involontaires
- Faciliter les interventions de maintenance

### Ordre logique d'implantation

Braser du plus bas au plus haut (en hauteur) pour que le perfboard reste stable posé sur la table :

1. **Résistances** (composants plats)
2. **LEDs** et **boutons** (hauteur moyenne)
3. **Fils de connexion** (en dernier)

---

## 6. Vérification avant mise sous tension

Avant de connecter l'Arduino, toujours vérifier avec le multimètre en mode **continuité (bip)** :

- ✅ Chaque connexion prévue émet un bip (circuit fermé)
- ✅ Aucun bip entre deux connexions qui ne doivent **pas** être reliées (pas de court-circuit)

> Un court-circuit non détecté peut détruire la carte Arduino dès la mise sous tension.

---

## Résumé en une phrase

> Le perfboard, c'est une breadboard **permanente** : même espacement, mêmes composants, mais les connexions sont créées par brasure — ce qui le rend robuste et livrable, mais irréversible.
