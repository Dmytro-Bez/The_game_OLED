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
  setup_wifi();
  first_menu(); 
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);   
}

/*----------LOOP----------*/
void loop() {
  conf_button_pressed = digitalRead(BUTTON_PIN);
  if((conf_button_pressed) &&(menu_flag==0)){
    start_config();
  } else {
    start_transfer();
  }
}
