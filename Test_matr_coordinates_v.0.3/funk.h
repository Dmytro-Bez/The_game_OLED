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
#define SIZE 3                                            //size arr
#define NX 'X'                                              //X
#define NY 'Y'                                              //Y

/*----------VARIABLES----------*/
bool conf_button_pressed = false;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

/*----------PROTOTYPE FUNCTIONS----------*/
void init_wire();                                         //Initialization I2C
void first_menu();                                        //Input menu function
void get_won();                                           //Winning function
void IRAM_ATTR isr();                                     //Button interuption funtion
void second_menu();                                       //Game board drawing function
void input_data();                                        //Data retrieval function
void creat_arr();                                         //Array fill function
void print_matrix();                                      //Array print function
//void display_screen();                                    //Game board drawing function

/*----------FUNKTIONS----------*/
void creat_arr(){
  int arr[SIZE][SIZE];
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      arr[i][j] = 0;
      Serial.println(arr[i][j]);
    }
  }
}

void print_matrix(){
  int A[SIZE][SIZE];
  delay(1000);
  display.clearDisplay();
  display.setTextSize(2);             
  display.setTextColor(WHITE);
  randomSeed(9);
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      (A[i][j] == random(3));
    }
  }
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      if(A[i][j] == 0){
        display.setCursor(23+i*30,2+j*23);             
        display.println("0"); 
        display.display();
      } else {
        display.setCursor(23+i*30,2+j*23);             
        display.println("X"); 
        display.display();
      }
    }
  }
}

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
//  display.drawLine(40, 0, 40, 63, WHITE);
//  display.drawLine(80, 0, 80, 63, WHITE);
//  display.drawLine(11, 21, 106, 21, WHITE);
//  display.drawLine(11, 40, 106, 40, WHITE);
print_matrix();
  display.drawLine(15, 21, 95, 21, WHITE);
  display.drawLine(15, 43, 95, 43, WHITE);
  display.drawLine(42, 0, 42, 63, WHITE);
  display.drawLine(71, 0, 71, 63, WHITE);
  display.setCursor(22,15);
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

void input_data(){
  char rx_byte, ry_byte;
  if (Serial.available() > 0){                         //is a character available?
    delay(1000);
    display.clearDisplay();                            //Clear display
    second_menu();
    rx_byte = Serial.read();                             //get the character
    ry_byte = Serial.read();
    if ((rx_byte || ry_byte >= '0') && (rx_byte || ry_byte <= '9')) {        //check if a number was received
      Serial.print("Number received: ");
      Serial.print(rx_byte);
      Serial.println(ry_byte);
      display.setTextSize(2);             
      display.setTextColor(WHITE);        
      
      if(rx_byte%2 == 0){
        //display.setCursor(80,2);
        //display.setCursor(80,25);
        //display.setCursor(80,47);
        //display.setCursor(23,2);
        //display.setCursor(53,2);
        //display.setCursor(23,25);
        //display.setCursor(23,47);
        //display.setCursor(53,25); 
        display.setCursor(53,47);                
        display.println("0"); 
        display.display(); 
      } else {
        //display.setCursor(80,2);
        //display.setCursor(80,25); 
        //display.setCursor(80,47);
        //display.setCursor(23,2);
        //display.setCursor(53,2);
        //display.setCursor(23,25);
        //display.setCursor(23,47);
        //display.setCursor(53,25); 
        display.setCursor(53,47);                
        display.println("X"); 
        display.display(); 
      }
//      if(ry_byte%2 == 0){
//        //display.setCursor(53,2);
//        //display.setCursor(23,2);
//        display.setCursor(80,2);             
//        display.println("0"); 
//        display.display(); 
//      } else {
//        //display.setCursor(53,2);
//        //display.setCursor(23,2);
//        display.setCursor(80,2);             
//        display.println("X"); 
//        display.display(); 
//      }     
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
