#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// --- Positions de base ---
#define EYE_L_X  36
#define EYE_R_X  92
#define EYE_Y    24
#define EYE_RX   11
#define EYE_RY   12
#define PUPIL_R   6
#define MOUTH_X  64
#define MOUTH_Y  50

// --- Utilitaire : dessine les deux yeux avec pupilles et reflets ---
void drawEyes(int offX, int offY, int rx = EYE_RX, int ry = EYE_RY) {
  u8g2.drawEllipse(EYE_L_X, EYE_Y, rx, ry, U8G2_DRAW_ALL);
  u8g2.drawEllipse(EYE_R_X, EYE_Y, rx, ry, U8G2_DRAW_ALL);
  u8g2.drawDisc(EYE_L_X + offX, EYE_Y + offY, PUPIL_R);
  u8g2.drawDisc(EYE_R_X + offX, EYE_Y + offY, PUPIL_R);
  // Reflets blancs (petits points dans les pupilles)
  u8g2.setDrawColor(0);
  u8g2.drawDisc(EYE_L_X + offX + 2, EYE_Y + offY - 2, 2);
  u8g2.drawDisc(EYE_R_X + offX + 2, EYE_Y + offY - 2, 2);
  u8g2.setDrawColor(1);
}

// --- Label centré en bas de l'écran ---
void drawLabel(const char* label) {
  u8g2.setFont(u8g2_font_5x7_tr);
  int w = u8g2.getStrWidth(label);
  u8g2.drawStr((128 - w) / 2, 63, label);
}

// ==============================================
//  ATTENTE — visage kawaii neutre avec blush
// ==============================================
void drawAttente() {
  drawEyes(0, 2);
  // Petit sourire
  u8g2.drawCircle(MOUTH_X, MOUTH_Y - 10, 11,
    U8G2_DRAW_LOWER_RIGHT | U8G2_DRAW_LOWER_LEFT);
  // Blush (3 petits points sur chaque joue)
  for (int i = 0; i < 3; i++) {
    u8g2.drawPixel(14 + i * 4, 38);
    u8g2.drawPixel(14 + i * 4, 40);
    u8g2.drawPixel(108 + i * 4, 38);
    u8g2.drawPixel(108 + i * 4, 40);
  }
}

// ==============================================
//  RECHERCHE — pupilles animées gauche/droite
// ==============================================
void drawRecherche(int pupilOffX) {
  drawEyes(pupilOffX, 2);
  // Bouche "o" (curieux)
  u8g2.drawEllipse(MOUTH_X, MOUTH_Y, 7, 5, U8G2_DRAW_ALL);
}

// ==============================================
//  ATTAQUE — sourcils en V, regard déterminé
// ==============================================
void drawAttaque() {
  drawEyes(0, 2);
  // Sourcils colère (diagonales vers le centre)
  u8g2.drawLine(EYE_L_X - EYE_RX,     EYE_Y - EYE_RY - 3,
                EYE_L_X + EYE_RX - 2, EYE_Y - EYE_RY);
  u8g2.drawLine(EYE_L_X - EYE_RX,     EYE_Y - EYE_RY - 2,
                EYE_L_X + EYE_RX - 2, EYE_Y - EYE_RY + 1);
  u8g2.drawLine(EYE_R_X - EYE_RX + 2, EYE_Y - EYE_RY,
                EYE_R_X + EYE_RX,     EYE_Y - EYE_RY - 3);
  u8g2.drawLine(EYE_R_X - EYE_RX + 2, EYE_Y - EYE_RY + 1,
                EYE_R_X + EYE_RX,     EYE_Y - EYE_RY - 2);
  // Bouche ligne droite (déterminé)
  u8g2.drawLine(MOUTH_X - 14, MOUTH_Y,     MOUTH_X + 14, MOUTH_Y);
  u8g2.drawLine(MOUTH_X - 14, MOUTH_Y + 1, MOUTH_X + 14, MOUTH_Y + 1);
}

// ==============================================
//  REPLI — yeux écarquillés, grimace, sueur
// ==============================================
void drawRepli() {
  // Yeux très grands, petites pupilles (peur)
  u8g2.drawEllipse(EYE_L_X, EYE_Y, EYE_RX + 2, EYE_RY + 2, U8G2_DRAW_ALL);
  u8g2.drawEllipse(EYE_R_X, EYE_Y, EYE_RX + 2, EYE_RY + 2, U8G2_DRAW_ALL);
  u8g2.drawDisc(EYE_L_X, EYE_Y, 3);
  u8g2.drawDisc(EYE_R_X, EYE_Y, 3);
  // Grimace (frown = arc du haut avec centre en-dessous)
  u8g2.drawCircle(MOUTH_X, MOUTH_Y + 10, 12,
    U8G2_DRAW_UPPER_RIGHT | U8G2_DRAW_UPPER_LEFT);
  // Goutte de sueur
  u8g2.drawLine(112, 8, 115, 20);
  u8g2.drawDisc(114, 22, 3);
}

// ==============================================
//  VICTOIRE — yeux plissés ^_^, grand sourire
// ==============================================
void drawVictoire() {
  // Yeux fermés joyeux (arc vers le haut = demi-cercle supérieur)
  u8g2.drawCircle(EYE_L_X, EYE_Y + 5, 10,
    U8G2_DRAW_UPPER_RIGHT | U8G2_DRAW_UPPER_LEFT);
  u8g2.drawCircle(EYE_R_X, EYE_Y + 5, 10,
    U8G2_DRAW_UPPER_RIGHT | U8G2_DRAW_UPPER_LEFT);
  // Grand sourire
  u8g2.drawCircle(MOUTH_X, MOUTH_Y - 14, 16,
    U8G2_DRAW_LOWER_RIGHT | U8G2_DRAW_LOWER_LEFT);
  // Blush joues (gros, festif)
  u8g2.drawDisc(14, 40, 6);
  u8g2.drawDisc(114, 40, 6);
  u8g2.setDrawColor(0);
  u8g2.drawDisc(14, 40, 4);
  u8g2.drawDisc(114, 40, 4);
  u8g2.setDrawColor(1);
  // Etoiles
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(2, 14, "*");
  u8g2.drawStr(119, 14, "*");
}

// ==============================================
//  SETUP & LOOP
// ==============================================
void setup() {
  Wire.begin(21, 22);
  u8g2.begin();
}

void loop() {
  // --- ATTENTE (3s) ---
  for (int t = 0; t < 3000; t += 20) {
    u8g2.clearBuffer();
    drawAttente();
    drawLabel("ATTENTE");
    u8g2.sendBuffer();
    delay(20);
  }

  // --- RECHERCHE : pupilles qui balayent gauche/droite (3 cycles) ---
  for (int cycle = 0; cycle < 3; cycle++) {
    for (int off = -4; off <= 4; off++) {
      u8g2.clearBuffer();
      drawRecherche(off);
      drawLabel("RECHERCHE");
      u8g2.sendBuffer();
      delay(60);
    }
    for (int off = 4; off >= -4; off--) {
      u8g2.clearBuffer();
      drawRecherche(off);
      drawLabel("RECHERCHE");
      u8g2.sendBuffer();
      delay(60);
    }
  }

  // --- ATTAQUE (3s) ---
  for (int t = 0; t < 3000; t += 20) {
    u8g2.clearBuffer();
    drawAttaque();
    drawLabel("ATTAQUE");
    u8g2.sendBuffer();
    delay(20);
  }

  // --- REPLI (3s) ---
  for (int t = 0; t < 3000; t += 20) {
    u8g2.clearBuffer();
    drawRepli();
    drawLabel("REPLI");
    u8g2.sendBuffer();
    delay(20);
  }

  // --- VICTOIRE (3s) ---
  for (int t = 0; t < 3000; t += 20) {
    u8g2.clearBuffer();
    drawVictoire();
    drawLabel("VICTOIRE");
    u8g2.sendBuffer();
    delay(20);
  }
}
