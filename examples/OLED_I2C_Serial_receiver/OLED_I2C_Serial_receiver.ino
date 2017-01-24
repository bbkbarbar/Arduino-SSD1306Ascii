// Simple I2C test for ebay 128x64 oled.
// Use smaller faster AvrI2c class in place of Wire.
//
#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"

//  uint32_t m = micros();
String readString = "";            // Variable for storing received data
// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

SSD1306AsciiAvrI2c oled;

//------------------------------------------------------------------------------

void setup() {         
  oled.begin(&Adafruit128x64, I2C_ADDRESS, false);
  oled.setFont(Adafruit5x7);  
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
