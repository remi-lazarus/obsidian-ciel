// =============================================================================
// SYSTÈME DE FEUX DE CIRCULATION COMPLET
// =============================================================================
// Fichier  : feux_circulation.ino
// Auteur   : Enseignement CIEL — [Établissement]
// Date     : 2026-04-03
// Version  : 1.0
// Niveau   : Bac Pro CIEL — Seconde / Première
//
// Description :
//   Simule un carrefour avec :
//     - Feu tricolore voiture + feu bicolore piéton (bouton de demande SW1)
//     - Barrière motorisée (servomoteur SG90, commandée par SW2)
//     - Mode nuit automatique par capteur LDR (orange clignotant)
//
// Matériel :
//   - Arduino Uno
//   - 3 LEDs feu voiture (rouge D2, orange D3, vert D4)
//   - 2 LEDs feu piéton  (rouge D5, vert D6)
//   - 2 boutons poussoirs (piéton D7, barrière D8) avec pull-down 10 kΩ
//   - 1 servomoteur SG90 (signal D9)
//   - 1 LDR + résistance 10 kΩ (pont diviseur sur A0)
//   - Résistances 220 Ω en série sur chaque LED
//
// Bibliothèque requise : Servo.h (incluse dans l'IDE Arduino)
// =============================================================================

#include <Servo.h>

// =============================================================================
// DÉCLARATION DES BROCHES
// =============================================================================

// --- Feu voiture (sorties numériques) ---
const int BROCHE_FEU_VOITURE_ROUGE  = 2;
const int BROCHE_FEU_VOITURE_ORANGE = 3;
const int BROCHE_FEU_VOITURE_VERT   = 4;

// --- Feu piéton (sorties numériques) ---
const int BROCHE_FEU_PIETON_ROUGE = 5;
const int BROCHE_FEU_PIETON_VERT  = 6;

// --- Boutons poussoirs (entrées numériques, pull-down externe) ---
const int BROCHE_BOUTON_PIETON   = 7;
const int BROCHE_BOUTON_BARRIERE = 8;

// --- Servomoteur barrière (sortie PWM) ---
const int BROCHE_SERVO = 9;

// --- Capteur de luminosité LDR (entrée analogique) ---
const int BROCHE_LDR = A0;

// =============================================================================
// CONSTANTES DE CONFIGURATION
// =============================================================================

// Durées des phases de la séquence piéton (en millisecondes)
const unsigned long DUREE_ORANGE_TRANSITION_MS = 2000;  // Feu voiture orange
const unsigned long DUREE_PASSAGE_PIETON_MS    = 5000;  // Feu piéton vert
const unsigned long DUREE_FIN_PASSAGE_MS       = 2000;  // Clignotement rouge piéton

// Délai minimum entre deux déclenchements de séquence piéton
const unsigned long DELAI_MIN_ENTRE_PASSAGES_MS = 10000;

// Période du clignotement mode nuit (500 ms ON + 500 ms OFF = 1 Hz)
const unsigned long PERIODE_CLIGNOTEMENT_MS = 500;

// Anti-rebond des boutons (durée de stabilité requise)
const unsigned long DUREE_DEBOUNCE_MS = 50;

// Seuil LDR pour passage en mode nuit (0 = obscurité totale, 1023 = pleine lumière)
// À calibrer selon l'environnement ! Voir Architecture système.md
const int SEUIL_LDR_NUIT = 300;   // En dessous : mode nuit activé
const int SEUIL_LDR_JOUR = 350;   // Au-dessus  : retour mode jour (hystérésis)

// Angles du servomoteur pour la barrière
const int ANGLE_BARRIERE_OUVERTE = 90;  // Barrière levée
const int ANGLE_BARRIERE_FERMEE  = 0;   // Barrière abaissée

// =============================================================================
// DÉFINITION DES ÉTATS DE LA MACHINE À ÉTATS (FSM)
// =============================================================================

enum EtatFeux {
    ETAT_JOUR_VERT,              // Feu voiture vert — attente demande piéton
    ETAT_JOUR_ORANGE_TRANSITION, // Feu voiture orange — transition (2 s)
    ETAT_JOUR_ROUGE_PIETON,      // Feu voiture rouge, piéton vert (5 s)
    ETAT_JOUR_FIN_PASSAGE,       // Fin traversée — piéton rouge clignotant (2 s)
    ETAT_NUIT                    // Mode nuit — orange clignotant, boutons inactifs
};

// =============================================================================
// VARIABLES GLOBALES
// =============================================================================

// --- Machine à états ---
EtatFeux etatCourant = ETAT_JOUR_VERT;      // État initial au démarrage
unsigned long tDebutEtat = 0;               // Horodatage du début de l'état courant

// --- Clignotement (mode nuit et fin passage) ---
unsigned long tDernierClignotement = 0;     // Dernier changement d'état du clignotement
bool etatClignotement = false;              // true = LED allumée, false = LED éteinte

// --- Séquence piéton ---
unsigned long tDernierPassage = 0;          // Horodatage de la dernière séquence piéton

// --- Barrière ---
Servo servoBarriere;
bool barriereOuverte = false;               // État courant de la barrière

// --- Anti-rebond bouton piéton ---
bool dernierEtatBrutPieton   = LOW;
unsigned long tDernierChangementPieton = 0;
bool etatValidePieton = LOW;

// --- Anti-rebond bouton barrière ---
bool dernierEtatBrutBarriere   = LOW;
unsigned long tDernierChangementBarriere = 0;
bool etatValideBarriere = LOW;
bool barriereDejaTraitee = false;           // Évite la répétition sur appui long

// =============================================================================
// FONCTIONS UTILITAIRES
// =============================================================================

/**
 * Commande l'ensemble des LEDs des deux feux en une seule instruction.
 *
 * @param rougeVoiture  true = LED rouge voiture allumée
 * @param orangeVoiture true = LED orange voiture allumée
 * @param vertVoiture   true = LED verte voiture allumée
 * @param rougePieton   true = LED rouge piéton allumée
 * @param vertPieton    true = LED verte piéton allumée
 */
void gererFeux(bool rougeVoiture, bool orangeVoiture, bool vertVoiture,
               bool rougePieton, bool vertPieton) {
    digitalWrite(BROCHE_FEU_VOITURE_ROUGE,  rougeVoiture  ? HIGH : LOW);
    digitalWrite(BROCHE_FEU_VOITURE_ORANGE, orangeVoiture ? HIGH : LOW);
    digitalWrite(BROCHE_FEU_VOITURE_VERT,   vertVoiture   ? HIGH : LOW);
    digitalWrite(BROCHE_FEU_PIETON_ROUGE,   rougePieton   ? HIGH : LOW);
    digitalWrite(BROCHE_FEU_PIETON_VERT,    vertPieton    ? HIGH : LOW);
}

/**
 * Éteint toutes les LEDs des deux feux.
 * Utilisé comme point de départ sûr avant d'allumer les bonnes LEDs.
 */
void eteindreTousLesFeux() {
    gererFeux(false, false, false, false, false);
}

/**
 * Bascule la position de la barrière (ouverte ↔ fermée).
 * Met à jour la variable barriereOuverte et commande le servo.
 */
void basculerBarriere() {
    barriereOuverte = !barriereOuverte;
    if (barriereOuverte) {
        servoBarriere.write(ANGLE_BARRIERE_OUVERTE);
    } else {
        servoBarriere.write(ANGLE_BARRIERE_FERMEE);
    }
}

/**
 * Lit un bouton avec anti-rebond logiciel (50 ms de stabilité requise).
 * Met à jour les variables de suivi passées par référence.
 *
 * @param broche          Numéro de broche Arduino du bouton
 * @param dernierEtatBrut Référence vers la variable mémorisant le dernier état brut lu
 * @param tDernierChgt    Référence vers l'horodatage du dernier changement d'état
 * @param etatValide      Référence vers l'état validé (stable depuis DUREE_DEBOUNCE_MS)
 * @return true si l'état est stable et vaut HIGH, false sinon
 */
bool lireBoutonDebounce(int broche,
                        bool &dernierEtatBrut,
                        unsigned long &tDernierChgt,
                        bool &etatValide) {
    bool lecture = digitalRead(broche);

    // Si l'état brut a changé, réinitialiser le compteur anti-rebond
    if (lecture != dernierEtatBrut) {
        tDernierChgt = millis();
        dernierEtatBrut = lecture;
    }

    // Si l'état est stable depuis au moins DUREE_DEBOUNCE_MS, le valider
    if ((millis() - tDernierChgt) >= DUREE_DEBOUNCE_MS) {
        etatValide = lecture;
    }

    return (etatValide == HIGH);
}

// =============================================================================
// GESTION DE CHAQUE ÉTAT DE LA FSM
// =============================================================================

/**
 * ETAT_JOUR_VERT : feu voiture vert, piéton rouge.
 * Attend l'appui sur SW1 (et le délai minimum entre passages).
 * Surveille aussi la luminosité pour passer en mode nuit.
 */
void gererEtatVert() {
    // Appliquer l'affichage de cet état (une seule fois à l'entrée est préférable,
    // mais on le remet à chaque appel pour la robustesse)
    gererFeux(false, false, true,   // Voiture : VERT
              true,  false);        // Piéton  : ROUGE

    // Vérifier si le bouton piéton est pressé ET si le délai minimum est respecté
    bool boutonPieton = lireBoutonDebounce(BROCHE_BOUTON_PIETON,
                                           dernierEtatBrutPieton,
                                           tDernierChangementPieton,
                                           etatValidePieton);

    bool delaiRespect = (millis() - tDernierPassage) >= DELAI_MIN_ENTRE_PASSAGES_MS;

    if (boutonPieton && delaiRespect) {
        // Transition vers l'état ORANGE_TRANSITION
        etatCourant = ETAT_JOUR_ORANGE_TRANSITION;
        tDebutEtat = millis();
        gererFeux(false, true,  false,  // Voiture : ORANGE
                  true,  false);        // Piéton  : ROUGE (inchangé)
    }
}

/**
 * ETAT_JOUR_ORANGE_TRANSITION : feu voiture orange pendant 2 s.
 * Prépare le passage piéton.
 */
void gererEtatOrangeTransition() {
    if ((millis() - tDebutEtat) >= DUREE_ORANGE_TRANSITION_MS) {
        // Transition vers l'état ROUGE_PIETON
        etatCourant = ETAT_JOUR_ROUGE_PIETON;
        tDebutEtat = millis();
        gererFeux(true,  false, false,  // Voiture : ROUGE
                  false, true);         // Piéton  : VERT
    }
}

/**
 * ETAT_JOUR_ROUGE_PIETON : feu voiture rouge, piéton vert pendant 5 s.
 * Les piétons traversent.
 */
void gererEtatPassagePieton() {
    if ((millis() - tDebutEtat) >= DUREE_PASSAGE_PIETON_MS) {
        // Transition vers FIN_PASSAGE
        etatCourant = ETAT_JOUR_FIN_PASSAGE;
        tDebutEtat = millis();
        tDernierClignotement = millis();
        etatClignotement = true;
        // Initialiser le clignotement : piéton rouge allumé d'abord
        gererFeux(true, false, false,   // Voiture : ROUGE (inchangé)
                  true, false);         // Piéton  : ROUGE (début clignotement)
    }
}

/**
 * ETAT_JOUR_FIN_PASSAGE : piéton rouge clignotant pendant 2 s.
 * Avertissement que la traversée se termine.
 * Le feu voiture reste rouge.
 */
void gererEtatFinPassage() {
    // Gestion du clignotement du feu piéton rouge
    if ((millis() - tDernierClignotement) >= PERIODE_CLIGNOTEMENT_MS) {
        tDernierClignotement = millis();
        etatClignotement = !etatClignotement;
        // Voiture reste rouge, piéton rouge clignote
        digitalWrite(BROCHE_FEU_PIETON_ROUGE, etatClignotement ? HIGH : LOW);
    }

    // Vérifier si la durée totale de fin de passage est écoulée
    if ((millis() - tDebutEtat) >= DUREE_FIN_PASSAGE_MS) {
        // Mémoriser l'instant de fin du passage
        tDernierPassage = millis();
        // Retour à l'état VERT
        etatCourant = ETAT_JOUR_VERT;
        tDebutEtat = millis();
        gererFeux(false, false, true,   // Voiture : VERT
                  true,  false);        // Piéton  : ROUGE
    }
}

/**
 * ETAT_NUIT : tous les feux en orange clignotant à 1 Hz.
 * Boutons piéton et barrière inactifs.
 * Retour en mode jour si la luminosité remonte au-dessus de SEUIL_LDR_JOUR.
 */
void gererEtatNuit() {
    // Clignotement orange synchronisé (voiture + piéton)
    if ((millis() - tDernierClignotement) >= PERIODE_CLIGNOTEMENT_MS) {
        tDernierClignotement = millis();
        etatClignotement = !etatClignotement;

        if (etatClignotement) {
            // Allumer les oranges (voiture) — pas de LED orange dédiée côté piéton,
            // on utilise la LED rouge piéton pour signaler l'état nuit
            gererFeux(false, true,  false,  // Voiture : ORANGE
                      true,  false);        // Piéton  : ROUGE (signalisation nuit)
        } else {
            eteindreTousLesFeux();
        }
    }
}

// =============================================================================
// GESTION DU MODE NUIT (détection LDR)
// =============================================================================

/**
 * Vérifie la luminosité ambiante et gère les transitions mode jour / mode nuit.
 * Applique une hystérésis pour éviter les oscillations au seuil.
 *
 * @return true si le système est en mode nuit, false en mode jour
 */
bool gererDetectionNuit() {
    int valeurLDR = analogRead(BROCHE_LDR);

    if (etatCourant != ETAT_NUIT) {
        // --- Mode jour : surveiller si on doit passer en mode nuit ---
        if (valeurLDR < SEUIL_LDR_NUIT) {
            // Luminosité insuffisante → passer en mode nuit
            // On ne coupe une séquence qu'en état VERT (séquence déjà terminée)
            if (etatCourant == ETAT_JOUR_VERT) {
                etatCourant = ETAT_NUIT;
                tDebutEtat = millis();
                tDernierClignotement = millis();
                etatClignotement = false;
                eteindreTousLesFeux();
                return true;
            }
        }
        return false;
    } else {
        // --- Mode nuit : surveiller si on doit revenir en mode jour ---
        if (valeurLDR > SEUIL_LDR_JOUR) {
            // Luminosité revenue → retour en mode jour, état VERT
            etatCourant = ETAT_JOUR_VERT;
            tDebutEtat = millis();
            tDernierPassage = millis(); // Reset délai pour éviter déclenchement immédiat
            gererFeux(false, false, true,   // Voiture : VERT
                      true,  false);        // Piéton  : ROUGE
            return false;
        }
        return true;
    }
}

// =============================================================================
// GESTION DE LA BARRIÈRE (indépendante de la FSM feux)
// =============================================================================

/**
 * Gère la commande de la barrière par le bouton SW2.
 * Utilise un anti-rebond et une détection de front montant
 * pour ne basculer qu'une fois par appui.
 *
 * @param modeNuit true si le système est en mode nuit (bouton ignoré)
 */
void gererBarriere(bool modeNuit) {
    bool boutonBarriere = lireBoutonDebounce(BROCHE_BOUTON_BARRIERE,
                                              dernierEtatBrutBarriere,
                                              tDernierChangementBarriere,
                                              etatValideBarriere);

    if (modeNuit) {
        // En mode nuit, le bouton barrière est inactif
        barriereDejaTraitee = true; // Évite un déclenchement au retour en mode jour
        return;
    }

    if (boutonBarriere && !barriereDejaTraitee) {
        // Front montant détecté (appui frais, non encore traité)
        basculerBarriere();
        barriereDejaTraitee = true;
    }

    if (!boutonBarriere) {
        // Bouton relâché → prêt pour le prochain appui
        barriereDejaTraitee = false;
    }
}

// =============================================================================
// SETUP — Initialisation
// =============================================================================

void setup() {
    // --- Configuration des broches de sortie (LEDs) ---
    pinMode(BROCHE_FEU_VOITURE_ROUGE,  OUTPUT);
    pinMode(BROCHE_FEU_VOITURE_ORANGE, OUTPUT);
    pinMode(BROCHE_FEU_VOITURE_VERT,   OUTPUT);
    pinMode(BROCHE_FEU_PIETON_ROUGE,   OUTPUT);
    pinMode(BROCHE_FEU_PIETON_VERT,    OUTPUT);

    // --- Configuration des broches d'entrée (boutons, pull-down externe) ---
    pinMode(BROCHE_BOUTON_PIETON,   INPUT);  // Pull-down 10 kΩ câblé sur breadboard
    pinMode(BROCHE_BOUTON_BARRIERE, INPUT);  // Pull-down 10 kΩ câblé sur breadboard

    // --- Configuration du servomoteur ---
    servoBarriere.attach(BROCHE_SERVO);
    servoBarriere.write(ANGLE_BARRIERE_FERMEE); // Barrière fermée au démarrage

    // --- Initialisation du port série (pour débogage et calibration LDR) ---
    Serial.begin(9600);
    Serial.println("=== Feux de circulation — démarrage ===");
    Serial.print("Valeur LDR initiale : ");
    Serial.println(analogRead(BROCHE_LDR));

    // --- État initial : feu voiture VERT, feu piéton ROUGE ---
    etatCourant = ETAT_JOUR_VERT;
    tDebutEtat = millis();
    tDernierPassage = 0; // Permet un premier déclenchement immédiat si nécessaire
    gererFeux(false, false, true,   // Voiture : VERT
              true,  false);        // Piéton  : ROUGE

    Serial.println("État initial : JOUR_VERT — barrière fermée");
}

// =============================================================================
// LOOP — Boucle principale
// =============================================================================

void loop() {
    // ------------------------------------------------------------------
    // ÉTAPE 1 : Détecter le mode nuit via la LDR
    // ------------------------------------------------------------------
    bool modeNuit = gererDetectionNuit();

    // ------------------------------------------------------------------
    // ÉTAPE 2 : Exécuter la machine à états des feux
    // ------------------------------------------------------------------
    switch (etatCourant) {
        case ETAT_JOUR_VERT:
            gererEtatVert();
            break;
        case ETAT_JOUR_ORANGE_TRANSITION:
            gererEtatOrangeTransition();
            break;
        case ETAT_JOUR_ROUGE_PIETON:
            gererEtatPassagePieton();
            break;
        case ETAT_JOUR_FIN_PASSAGE:
            gererEtatFinPassage();
            break;
        case ETAT_NUIT:
            gererEtatNuit();
            break;
    }

    // ------------------------------------------------------------------
    // ÉTAPE 3 : Gérer la barrière (indépendant des feux)
    // ------------------------------------------------------------------
    gererBarriere(modeNuit);

    // ------------------------------------------------------------------
    // ÉTAPE 4 (optionnel) : Affichage de débogage sur le port série
    // Décommenter pour calibrer la LDR ou suivre les états
    // ------------------------------------------------------------------
    // static unsigned long tDernierAffichage = 0;
    // if ((millis() - tDernierAffichage) >= 1000) {
    //     tDernierAffichage = millis();
    //     Serial.print("LDR = ");
    //     Serial.print(analogRead(BROCHE_LDR));
    //     Serial.print(" | Etat = ");
    //     Serial.print(etatCourant);
    //     Serial.print(" | Barriere = ");
    //     Serial.println(barriereOuverte ? "OUVERTE" : "FERMEE");
    // }
}

// =============================================================================
// FIN DU FICHIER
// =============================================================================
