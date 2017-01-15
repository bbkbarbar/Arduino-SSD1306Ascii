// Simple software SPI test for ebay 128x64 oled.

// pin definitions
#define OLED_DC    5
#define OLED_CS    4
#define OLED_CLK   9
#define OLED_DATA  8
#define OLED_RST   7

#include <SSD1306Ascii.h>
#include <SSD1306AsciiSoftSpi.h>

SSD1306AsciiSoftSpi oled;
//------------------------------------------------------------------------------
void setup() {         
  oled.begin(&Adafruit128x64, OLED_CS, OLED_DC, OLED_CLK, OLED_DATA, OLED_RST);
  oled.setFont(Adafruit5x7);
    
  uint32_t m = micros();
  oled.clear();  
  oled.println("SoftSpiOled 5 wire");
  oled.println("A long line may be truncated");
  oled.println();
  oled.set2X();
  oled.println("2X demo");
  oled.set1X();
  oled.print("\nmicros: ");
  oled.print(micros() - m);
}
//------------------------------------------------------------------------------
void loop() {}
