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

  start_config();

  mess_aws();
}
/*----------LOOP----------*/
void loop() {
  if(!client.connected()){
    connect_aws();
  }
  client.loop();
  
  conf_button_pressed = digitalRead(BUTTON_PIN);
  if((conf_button_pressed) &&(menu_flag==0)){
    second_menu();
//    print_matrix();
  } else {

  }
}
