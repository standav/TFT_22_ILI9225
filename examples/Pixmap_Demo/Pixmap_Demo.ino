// Include application, user and local libraries
#include "SPI.h"
#include "TFT_22_ILI9225.h"

#define TFT_RST 8
#define TFT_RS  9
#define TFT_CS  10  // SS
#define TFT_SDI 11  // MOSI
#define TFT_CLK 13  // SCK
#define TFT_LED 3   // 0 if wired to +5V directly

// Use hardware SPI (faster - on Uno: 13-SCK, 12-MISO, 11-MOSI)
TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED);
// Use software SPI (slower)
//TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED);

// Variables and constants
uint16_t x, y;
boolean flag = false;

// Setup
void setup() {
  tft.begin();
  Serial.begin(9600);
}

// Loop
void loop() {

  // fill one vertical line
  uint8_t line[tft.maxX()];

  for (uint8_t i = 0; i < tft.maxX(); i++)
  {
    line[i] = i;
  }

  // draw line

  for (uint8_t j = 0; j < tft.maxY(); j++)
  {
    tft.drawVerticalGrayLine (j, &line[0]);
  }

  delay(1000);
  
  tft.setBacklight(false);
  tft.setDisplay(false);
  
  while(true);

}
