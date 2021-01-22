#include <Arduino.h>
#include"coord.h"

#define D8 18          //Serial clock out (SCLK)
#define D7 23          //Serial data out (DIN)
#define D6 19          //Data/Command select (D/C)
#define D5 5           //LCD chip select (CS)
#define D2 14          //LCD reset (RST)

Adafruit_PCD8544 display = Adafruit_PCD8544(D8, D7, D6, D5, D2);

void setup() {
  // put your setup code here, to run once:
  display.begin();
  display.setContrast(10);
  display.clearDisplay();
  text();
  goriz();
  vect();
}

void loop() {
  // put your main code here, to run repeatedly:

}

