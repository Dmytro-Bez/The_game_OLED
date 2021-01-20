#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

void matr();
void coordinates();
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  matr();
  // Display static text
  display.display(); 
}

void loop() {
  
}

void matr(){
  display.drawLine(42, 0, 42, 63, WHITE);
  display.drawLine(84, 0, 84, 63, WHITE);
  display.drawLine(0, 21, 127, 21, WHITE);
  display.drawLine(0, 42, 127, 42, WHITE);
  coordinates();
}

void coordinates(){
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(100,2);             
  display.println("X");
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(58,2);             
  display.println("X");
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(16,2);             
  display.println("X");
  
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(16,24);             
  display.println("0");
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(58,24);             
  display.println("0");
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(100,24);             
  display.println("0");

  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(16,48);             
  display.println("X");
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(58,48);             
  display.println("0");
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(100,48);             
  display.println("X");
}