/*----------LIBRARIES----------*/
#include "funk.h"
/*----------DEFINES----------*/
/*----------VARIABLES----------*/
int menu_flag = 0;
/*----------PROTOTYPE FUNCTIONS----------*/
/*----------SETUP----------*/
void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN,  INPUT_PULLUP);                     //Initialize the button and LED indicator
  attachInterrupt(BUTTON_PIN, isr, FALLING);

  init_wire();                                            //Wire bus initialization
  //first_menu();
  second_menu();
  
}

/*----------LOOP----------*/
void loop() {
//  input_data();
//  conf_button_pressed = digitalRead(BUTTON_PIN);
//  if((conf_button_pressed) &&(menu_flag==0)){
//    second_menu(); 
//    menu_flag = 1;
//    
//  } else if((conf_button_pressed)&&(menu_flag==1)){
//    first_menu();
//    menu_flag = 0;
//  }
}
