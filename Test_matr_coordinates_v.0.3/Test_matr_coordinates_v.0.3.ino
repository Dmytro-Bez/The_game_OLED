/*----------LIBRARIES----------*/
#include "funk.h"

/*----------VARIABLES----------*/
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
const long interval = 500;

/*----------SETUP----------*/
void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN,  INPUT_PULLUP);                     //Initialize the button and LED indicator
  attachInterrupt(BUTTON_PIN, isr, FALLING);              //Interrupt button

  start_config();                                         //Start and init system
}
/*----------LOOP----------*/
void loop() {
  
  if(!client.connected()){
    connect_aws();
  }
  client.loop();

  currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    conf_button_pressed = digitalRead(BUTTON_PIN);          //In the loop, read whether the button is pressed
    if((conf_button_pressed)){
      first_menu();
    } else {
      if(matrix_check()){
        move_win();
      } else {
        return_game();
      }
    }
 }
}
