#ifndef funk_h
#define funk_h

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

/*----------DEFINES----------*/
#define PIN_RX  16                                        //Pin read 
#define PIN_TX  17                                        //Pin text
#define SCREEN_WIDTH 128                                  // OLED display width, in pixels
#define SCREEN_HEIGHT 64                                  // OLED display height, in pixels
#define BUTTON_PIN 4                                      //button

/*----------VARIABLES----------*/
bool conf_button_pressed = false;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

/*----------PROTOTYPE FUNCTIONS----------*/
void init_wire();                                         //Initialization I2C
void first_menu();
void get_won();
void IRAM_ATTR isr();                                     //Button interuption funtion
void second_menu();
void coordinates();

/*----------FUNKTIONS----------*/
void first_menu(){
  delay(1000);
  display.clearDisplay();                                 //Clear display
  display.setTextSize(1.5);             
  display.setTextColor(WHITE);        
  display.setCursor(0,0);             
  display.println("Hello user.");
  display.setCursor(0,15);   
  display.println("GAME TicTacToe.");
  display.setCursor(0,30); 
  display.println("Please."); 
  display.println("Pressed button!");
  display.display();
  
  /*----------MENU SERIAL PORT----------*/
  Serial.println("Hello user.");  
  Serial.println("GAME TicTacToe.");
  Serial.println("Please pressed button!"); 
  Serial.println("");
}

void second_menu(){
  delay(1000);
  display.clearDisplay();                                 //Clear display
  display.drawLine(42, 0, 42, 63, WHITE);
  display.drawLine(84, 0, 84, 63, WHITE);
  display.drawLine(0, 21, 127, 21, WHITE);
  display.drawLine(0, 42, 127, 42, WHITE);
  display.display();

  /*----------MENU SERIAL PORT----------*/
  Serial.println("============="); 
  Serial.println("-1-||-2-||-3-"); 
  Serial.println("-4-||-5-||-6-"); 
  Serial.println("-7-||-8-||-9-");
  Serial.println("=============");  
  Serial.println("");
  display.display();
}

void get_won(){
  display.clearDisplay();                                 //Clear display
  display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(0,0);             
  display.print("User won: ");
  display.print("X");
  display.setCursor(0,15);   
  display.println("Please.");
  display.println("Click the button to");
  display.print("start a new game!");
  display.display();
    
  /*----------MENU SERIAL PORT----------*/
  Serial.print("User won: ");  
  Serial.println("X");
  Serial.print("Please."); 
  Serial.println("Click the button to start a new game!");
  Serial.println("");
}

void coordinates(){
  if (Serial.available() > 0){                         //is a character available?
    delay(1000);
    display.clearDisplay();                            //Clear display
    second_menu();
    char rx_byte = Serial.read();                      //get the character
    if ((rx_byte >= '0') && (rx_byte <= '9')) {        //check if a number was received
      Serial.print("Number received: ");
      Serial.println(rx_byte);
      display.setTextSize(2);             
      display.setTextColor(WHITE);        
      
      if(rx_byte%2 == 0){
        //display.setCursor(100,2);             
        display.println("0"); 
        display.display(); 
      } else {
        //display.setCursor(100,2);             
        display.println("X"); 
        display.display(); 
      }
    } else {
      Serial.println("Not a number.");
    }
  }
}

void init_wire(){
  Wire.begin();
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for(;;);
  } 
}

void IRAM_ATTR isr() {
  conf_button_pressed = !conf_button_pressed;
}

#endif
