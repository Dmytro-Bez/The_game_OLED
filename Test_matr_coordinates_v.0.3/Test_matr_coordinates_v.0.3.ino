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
  attachInterrupt(BUTTON_PIN, isr, FALLING);              //Interrupt button

  start_config();                                         //Start and init system
  Serial.print("O_win = ");
  Serial.println(O_win);
  Serial.print("X_win = ");
  Serial.println(X_win);

  //mess_aws();                                         //Start connect AWS
}
/*----------LOOP----------*/
void loop() {
  //  if(!client.connected()){
//    connect_aws();
//  }
//  client.loop();
  
  conf_button_pressed = digitalRead(BUTTON_PIN);          //In the loop, read whether the button is pressed
  if((conf_button_pressed) &&(menu_flag==0)){
    second_menu();
  } else {
    
  }
}
