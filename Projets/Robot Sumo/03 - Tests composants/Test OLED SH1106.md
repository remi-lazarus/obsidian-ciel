---
type: test-composant
composant: OLED 1.3" SSH1106
interface: I2C
date: 2026-06-13
statut: à tester
---

# Test OLED 1.3" SSH1106 — I2C

## Câblage

```
ESP32 DevKit          OLED 1.3" SSH1106
┌─────────────┐       ┌───────────────┐
│         3V3 ├──────►│ VCC           │
│         GND ├──────►│ GND           │
│      GPIO21 ├──────►│ SDA           │
│      GPIO22 ├──────►│ SCL           │
└─────────────┘       └───────────────┘
```

> ⚠️ Alimenter en **3.3V** (pas 5V) — l'ESP32 est 3.3V logique.
> L'adresse I2C est **0x3C** (vérifiable avec le scanner I2C ci-dessous).

---

## Librairie requise

**U8g2** — à installer via le gestionnaire de bibliothèques Arduino IDE :
`Outils > Gérer les bibliothèques > rechercher "U8g2" > installer`

---

## Programme 1 — Scanner I2C (à lancer en premier)

Vérifie que l'écran est bien détecté avant de lancer le test d'affichage.

```cpp
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // SDA=GPIO21, SCL=GPIO22
  Serial.println("Scan I2C...");
}

void loop() {
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Périphérique trouvé : 0x");
      Serial.println(addr, HEX);
    }
  }
  Serial.println("Scan terminé.");
  delay(5000);
}
```

**Résultat attendu :** `Périphérique trouvé : 0x3C`

---

## Programme 2 — Test affichage

```cpp
#include <Wire.h>
#include <U8g2lib.h>

// SSH1106 128x64, I2C hardware, adresse 0x3C
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

void setup() {
  Wire.begin(21, 22); // SDA=GPIO21, SCL=GPIO22
  u8g2.begin();
}

void loop() {
  // Ecran 1 : texte statique
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB10_tr);
  u8g2.drawStr(10, 20, "Robot Sumo");
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(20, 38, "ESP32 + SSH1106");
  u8g2.drawStr(30, 52, "I2C : 0x3C");
  u8g2.sendBuffer();
  delay(3000);

  // Ecran 2 : rectangle animé (gauche → droite)
  for (int x = 0; x <= 108; x += 4) {
    u8g2.clearBuffer();
    u8g2.drawFrame(0, 0, 128, 64);      // bordure
    u8g2.drawBox(x, 22, 20, 20);        // carré mobile
    u8g2.sendBuffer();
    delay(40);
  }

  // Ecran 3 : barre de progression simulée
  for (int p = 0; p <= 100; p += 5) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x10_tr);
    u8g2.drawStr(40, 20, "Batterie");
    u8g2.drawFrame(4, 30, 120, 16);
    u8g2.drawBox(4, 30, p * 120 / 100, 16);
    char buf[8];
    sprintf(buf, "%d%%", p);
    u8g2.drawStr(56, 56, buf);
    u8g2.sendBuffer();
    delay(60);
  }
}
```

---

## Résultats

- [x] Scanner I2C détecte 0x3C
- [x] Texte statique s'affiche correctement
- [x] Animation rectangle OK
- [x] Barre de progression OK

## Notes
<!-- noter ici tout comportement inattendu -->
