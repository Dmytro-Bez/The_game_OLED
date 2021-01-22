#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#define D8 18          //Serial clock out (SCLK)
#define D7 23          //Serial data out (DIN)
#define D6 19          //Data/Command select (D/C)
#define D5 5           //LCD chip select (CS)
#define D2 14          //LCD reset (RST)

Adafruit_PCD8544 display = Adafruit_PCD8544(D8, D7, D6, D5, D2);

void vect();
void text();
void goriz();

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

void vect(){
  display.drawFastHLine(28,0,0,BLACK);
  display.display();
  display.drawFastHLine(28,1,0,BLACK);
  display.display();
  display.drawFastHLine(28,2,0,BLACK);
  display.display();
  display.drawFastHLine(28,3,0,BLACK);
  display.display();
  display.drawFastHLine(28,4,0,BLACK);
  display.display();
  display.drawFastHLine(28,5,0,BLACK);
  display.display();
  display.drawFastHLine(28,6,0,BLACK);
  display.display();
  display.drawFastHLine(28,7,0,BLACK);
  display.display();
  display.drawFastHLine(28,8,0,BLACK);
  display.display();
  display.drawFastHLine(28,9,0,BLACK);
  display.display();
  display.drawFastHLine(28,10,0,BLACK);
  display.display();
  display.drawFastHLine(28,11,0,BLACK);
  display.display();
  display.drawFastHLine(28,12,0,BLACK);
  display.display();
  display.drawFastHLine(28,13,0,BLACK);
  display.display();
  display.drawFastHLine(28,14,0,BLACK);
  display.display();
  display.drawFastHLine(28,15,0,BLACK);
  display.display();
  display.drawFastHLine(28,16,0,BLACK);
  display.display();
  display.drawFastHLine(28,17,0,BLACK);
  display.display();
  display.drawFastHLine(28,18,0,BLACK);
  display.display();
  display.drawFastHLine(28,19,0,BLACK);
  display.display();
  display.drawFastHLine(28,20,0,BLACK);
  display.display();
  display.drawFastHLine(28,21,0,BLACK);
  display.display();
  display.drawFastHLine(28,22,0,BLACK);
  display.display();
  display.drawFastHLine(28,23,0,BLACK);
  display.display();
  display.drawFastHLine(28,24,0,BLACK);
  display.display();
  display.drawFastHLine(28,25,0,BLACK);
  display.display();
  display.drawFastHLine(28,26,0,BLACK);
  display.display();
  display.drawFastHLine(28,27,0,BLACK);
  display.display();
  display.drawFastHLine(28,28,0,BLACK);
  display.display();
  display.drawFastHLine(28,29,0,BLACK);
  display.display();
  display.drawFastHLine(28,30,0,BLACK);
  display.display();
  display.drawFastHLine(28,31,0,BLACK);
  display.display();
  display.drawFastHLine(28,32,0,BLACK);
  display.display();
  display.drawFastHLine(28,33,0,BLACK);
  display.display();
  display.drawFastHLine(28,34,0,BLACK);
  display.display();
  display.drawFastHLine(28,35,0,BLACK);
  display.display();
  display.drawFastHLine(28,36,0,BLACK);
  display.display();
  display.drawFastHLine(28,37,0,BLACK);
  display.display();
  display.drawFastHLine(28,38,0,BLACK);
  display.display();
  display.drawFastHLine(28,39,0,BLACK);
  display.display();
  display.drawFastHLine(28,40,0,BLACK);
  display.display();
  display.drawFastHLine(28,41,0,BLACK);
  display.display();
  display.drawFastHLine(28,42,0,BLACK);
  display.display();
  display.drawFastHLine(28,43,0,BLACK);
  display.display();
  display.drawFastHLine(28,44,0,BLACK);
  display.display();
  display.drawFastHLine(28,45,0,BLACK);
  display.display();
  display.drawFastHLine(28,46,0,BLACK);
  display.display();
  display.drawFastHLine(28,47,0,BLACK);
  display.display();

  display.drawFastHLine(56,0,0,BLACK);
  display.display();
  display.drawFastHLine(56,1,0,BLACK);
  display.display();
  display.drawFastHLine(56,2,0,BLACK);
  display.display();
  display.drawFastHLine(56,3,0,BLACK);
  display.display();
  display.drawFastHLine(56,4,0,BLACK);
  display.display();
  display.drawFastHLine(56,5,0,BLACK);
  display.display();
  display.drawFastHLine(56,6,0,BLACK);
  display.display();
  display.drawFastHLine(56,7,0,BLACK);
  display.display();
  display.drawFastHLine(56,8,0,BLACK);
  display.display();
  display.drawFastHLine(56,9,0,BLACK);
  display.display();
  display.drawFastHLine(56,10,0,BLACK);
  display.display();
  display.drawFastHLine(56,11,0,BLACK);
  display.display();
  display.drawFastHLine(56,12,0,BLACK);
  display.display();
  display.drawFastHLine(56,13,0,BLACK);
  display.display();
  display.drawFastHLine(56,14,0,BLACK);
  display.display();
  display.drawFastHLine(56,15,0,BLACK);
  display.display();
  display.drawFastHLine(56,16,0,BLACK);
  display.display();
  display.drawFastHLine(56,17,0,BLACK);
  display.display();
  display.drawFastHLine(56,18,0,BLACK);
  display.display();
  display.drawFastHLine(56,19,0,BLACK);
  display.display();
  display.drawFastHLine(56,20,0,BLACK);
  display.display();
  display.drawFastHLine(56,21,0,BLACK);
  display.display();
  display.drawFastHLine(56,22,0,BLACK);
  display.display();
  display.drawFastHLine(56,23,0,BLACK);
  display.display();
  display.drawFastHLine(56,24,0,BLACK);
  display.display();
  display.drawFastHLine(56,25,0,BLACK);
  display.display();
  display.drawFastHLine(56,26,0,BLACK);
  display.display();
  display.drawFastHLine(56,27,0,BLACK);
  display.display();
  display.drawFastHLine(56,28,0,BLACK);
  display.display();
  display.drawFastHLine(56,29,0,BLACK);
  display.display();
  display.drawFastHLine(56,30,0,BLACK);
  display.display();
  display.drawFastHLine(56,31,0,BLACK);
  display.display();
  display.drawFastHLine(56,32,0,BLACK);
  display.display();
  display.drawFastHLine(56,33,0,BLACK);
  display.display();
  display.drawFastHLine(56,34,0,BLACK);
  display.display();
  display.drawFastHLine(56,35,0,BLACK);
  display.display();
  display.drawFastHLine(56,36,0,BLACK);
  display.display();
  display.drawFastHLine(56,37,0,BLACK);
  display.display();
  display.drawFastHLine(56,38,0,BLACK);
  display.display();
  display.drawFastHLine(56,39,0,BLACK);
  display.display();
  display.drawFastHLine(56,40,0,BLACK);
  display.display();
  display.drawFastHLine(56,41,0,BLACK);
  display.display();
  display.drawFastHLine(56,42,0,BLACK);
  display.display();
  display.drawFastHLine(56,43,0,BLACK);
  display.display();
  display.drawFastHLine(56,44,0,BLACK);
  display.display();
  display.drawFastHLine(56,45,0,BLACK);
  display.display();
  display.drawFastHLine(56,46,0,BLACK);
  display.display();
  display.drawFastHLine(56,47,0,BLACK);
  display.display();
}

void text(){
  display.setTextSize(2);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(9,1);
  display.println("X");
  display.display();
  display.setCursor(36,1);
  display.println("X");
  display.display();
  display.setCursor(65,1);
  display.println("X");
  display.display();

  display.setCursor(9,17);
  display.println("0");
  display.display();
  display.setCursor(36,17);
  display.println("0");
  display.display();
  display.setCursor(65,17);
  display.println("0");
  display.display();

  display.setCursor(9,33);
  display.println("0");
  display.display();
  display.setCursor(36,33);
  display.println("X");
  display.display();
  display.setCursor(65,33);
  display.println("0");
  display.display();
}

void goriz(){
  display.drawFastHLine(0,16,83,BLACK);
  display.display();
  display.drawFastHLine(0,32,83,BLACK);
  display.display();
}
