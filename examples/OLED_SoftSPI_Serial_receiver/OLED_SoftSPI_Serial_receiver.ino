/*  OLED          arduino
     D0-----------10
     D1-----------9
     RST----------7
     DC-----------11
     VCC----------5V
     GND----------GND*/
// Simple software SPI test for ebay 128x64 oled.

// pin definitions
#define OLED_DC    5
#define OLED_CS    4
#define OLED_D0    9
#define OLED_D1    8
#define OLED_RST   7

#define trigPin    3
#define echoPin    2

#include <SSD1306Ascii.h>
#include <SSD1306AsciiSoftSpi.h>

//  uint32_t m = micros();
String readString = "";            //Variable for storing received data
SSD1306AsciiSoftSpi oled;

//------------------------------------------------------------------------------

void setup() {         
  oled.begin(&Adafruit128x64, OLED_CS, OLED_DC, OLED_D0, OLED_D1, OLED_RST);
  oled.setFont(Adafruit5x7);
  oled.clear();  

  Serial.begin(9600);   //Sets the baud for serial data transmission      
  delay(300);
  
  oled.println("Listen serial port..");
}

//------------------------------------------------------------------------------

char flagNewDataReceived = 0;
 
void loop(){

  while (Serial.available()) {
    flagNewDataReceived = 1;
    delay(3);  //delay to allow buffer to fill 
    if (Serial.available() >0) {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
    } 
  }

  if (readString.length() > 0 && flagNewDataReceived) {
    oled.clear();
    oled.set1X();  
    oled.println("Received: ");
    oled.set2X();
    oled.println(readString);
    flagNewDataReceived = 0;
    readString = "";
  }
  
}
