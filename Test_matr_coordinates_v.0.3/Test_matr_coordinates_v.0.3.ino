/*----------LIBRARIES----------*/
#include "funk.h"                                         //Connect librarise

/*----------VARIABLES----------*/
unsigned long currentMillis = 0;                          //Create variable mil.sec
unsigned long previousMillis = 0;
const long interval = 500;                                //Create variable interval

/*----------SETUP----------*/
void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN,  INPUT_PULLUP);                     //Initialize the button and LED indicator
  attachInterrupt(BUTTON_PIN, isr, FALLING);              //Interrupt button

  start_config();                                         //Start and init system
}
/*----------LOOP----------*/
void loop() {
  
  if(!client.connected()){                                //Check connect AWS
    connect_aws();
  }
  client.loop();                                          //Poll client

  currentMillis = millis();                               //Call delay functions
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    conf_button_pressed = digitalRead(BUTTON_PIN);        //In the loop, read whether the button is pressed
    if((conf_button_pressed)){                            //wait by pressing the button
      first_menu();                                       //If you press the button, go to the first menu
    } else {
      if(!matrix_check()){                                 //Check array on the win
        move_win();                                       //If someone wins, go to the first menu and repeat the process of filling the matrix
      } else {
        return_game();                                    //If not, then the problems with entering the matrix or field are not filled
      }
    }
 }
}
