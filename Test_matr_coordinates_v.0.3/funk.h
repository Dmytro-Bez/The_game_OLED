#ifndef funk_h
#define funk_h

#include <Adafruit_GFX.h>                                 //Connect lib. full oled  
#include <Adafruit_SSD1306.h>                             //Connect lib. SSD1306
#include <WiFi.h>                                         //Connect lib.work wifi
#include <PubSubClient.h>                                 //Connect work mqtt 
#include <Wire.h>                                         //Connect lib.work I2c bus
#include <ArduinoJson.h>                                  //Connect lib.work json

/*----------DEFINES----------*/
#define PIN_RX  16                                        //Pin read 
#define PIN_TX  17                                        //Pin text
#define SCREEN_WIDTH 128                                  //OLED display width, in pixels
#define SCREEN_HEIGHT 64                                  //OLED display height, in pixels
#define BUTTON_PIN 4                                      //button
#define SIZE 3                                            //size arr
#define DEVICE_NAME "TIC"                                 //The name of the device. This MUST match up with the name defined in the AWS console 

/*----------VARIABLES----------*/
bool conf_button_pressed = false;                         //Variable to work button
bool O_win = false;                                       //Variable win '0'
bool X_win = false;                                       //Variable win 'X'
const char* ssid = "***";                                  //Variable network
const char* password = "***";                   // Replace the next variables with your SSID/Password combination
const char* mqtt_server = "192.168.1.113";                // Add your MQTT Broker IP address, example const char* mqtt_server = "Х.Х.Х.Х"
WiFiClient espClient;                                     //Create client wifi
PubSubClient client(espClient);                           //Create client messege mqtt
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);             //Create object display
int Array[SIZE][SIZE] = {{0,1,1}, {0,1,1}, {1,1,0}};      //Create test array

/*----------PROTOTYPE FUNCTIONS----------*/
void init_wire();                                         //Initialization I2C
void first_menu();                                        //Input menu function
void IRAM_ATTR isr();                                     //Button interuption funtion
void second_menu();                                       //Game board drawing function
bool connect_aws();                                       //Function connect AWS
void start_config();                                      //Settings function  
bool connect_wifi();                                      //Function connect Wifi
void callback(char* topic, byte* message, unsigned int length);               //Function callback
void get_data_to_aws(String topic, byte* message, unsigned int length);       //Function get data to aws
void mess_aws();                                          //Function mess AWS
void pr_win();                                            //Function print win
void move_win();                                          //Function move win
void return_game();                                       //Function return game
bool matrix_check();                                      //Function matrix check

/*----------FUNKTIONS----------*/
void start_config() {
  Serial.println("Start config mode");                    //Add function setting 
  init_wire();                                            //Initialization I2C
  first_menu();                                           //Input menu function
  connect_wifi();                                         //Function connect Wifi
  mess_aws();                                             //Start connect AWS
}

void first_menu(){                                        //Create input menu function
  delay(1000);
  display.clearDisplay();                                 //Clear display
  display.setTextSize(1.5);             
  display.setTextColor(WHITE);        
  display.setCursor(0,0);             
  display.println("Hello user.");
  display.setCursor(0,15);   
  display.println("GAME TicTacToe.");
  display.display();
  delay(5000);
  second_menu();                                          //Game board drawing function
}

void second_menu(){                                       //Create game board drawing function
  delay(1000);
  display.clearDisplay();                                 //Clear display
  display.drawLine(15, 21, 95, 21, WHITE);                //Create line matrix
  display.drawLine(15, 43, 95, 43, WHITE);
  display.drawLine(42, 0, 42, 63, WHITE);
  display.drawLine(71, 0, 71, 63, WHITE);
  display.setCursor(22,15);
  client.setCallback(callback);                           //Connect and set callback
  display.display();

//  pr_win();                                           //Testing win
}

bool matrix_check(){                                      //Create function matrix check
  bool status_arr = false;
  
  for(int i = 0; i < 3; i++){                             //Check the horizontals of the diagonals
    if((Array[0][i] == Array[1][i]) && (Array[0][i] == Array[2][i])) {
      if(Array[0][i] == 0){
        O_win = true;
        status_arr = true;
      }
        else if(Array[0][i] == 1){
          X_win = true;
          status_arr = true;
        }
    }
    for(int j = 0; j < 3; j++){                           //Check the verticals of the diagonal
      if((Array[j][0] == Array[j][1]) && (Array[j][0] == Array[j][2])) {
        if(Array[j][0] == 0){
          O_win = true;
          status_arr = true; 
        }
          else if(Array[j][0] == 1){
            X_win = true;
            status_arr = true;
          }
        }
      }
    }
    if ((Array[0][0] == Array[1][1]) && (Array[1][1] == Array[2][2])) {   //Check the winning diagonals
      if (Array[0][0] == 0){
        O_win = true;
        status_arr = true; 
      }
      else if (Array[0][0] == 1){
        X_win = true;
        status_arr = true;
      }
    }
    if((Array[0][2] == Array[1][1]) && (Array[1][1] == Array[2][0])) {    //Check the winning diagonals
      if(Array[0][2] == 0){
        O_win = true;
        status_arr = true; 
      }
      else if (Array[0][2] == 1){
        X_win = true;
      }
    }
    //Serial.print(status_arr);
    return status_arr; 
}

void move_win(){                                            //Create function move win
  if(O_win){
    display.clearDisplay();                                 //Clear display
    display.setTextSize(1);             
    display.setTextColor(WHITE);        
    display.setCursor(0,0);             
    display.print("User won: 0");
    display.setCursor(0,30); 
    display.println("Please."); 
    display.println("Pressed button!");
    display.display();
  } else {
    display.clearDisplay();                                 //Clear display
    display.setTextSize(1);             
    display.setTextColor(WHITE);        
    display.setCursor(0,0);             
    display.print("User won: X");
    display.setCursor(0,30); 
    display.println("Please."); 
    display.println("Pressed button!");
    display.display();
  } 
}

void return_game(){                                       //Create function return game
  display.clearDisplay();                                 //Clear display
  display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(0,0);             
  display.print("You have not entered all the cells of the matrix or completely filled.");
  display.setCursor(0,40); 
  display.println("Please.");
  display.println("Click the button and start a new game."); 
  display.display();
}

bool connect_wifi(){                                     //Create function connect wifi
  bool conf_status = false;
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){                 //Network connection check wifi
    delay(500);
    //Serial.print(".");
    conf_status = false;
  }
  //Serial.println("WiFi connected");
  conf_status = true;
  return conf_status;
}

bool connect_aws(){                                     //Create function connect aws
  bool conf_status = false;
  while (!client.connected()){                          // Loop until we're reconnected
    if (client.connect("ESP32Client")) {                // Attempt to connect
      //Serial.println("MQTT connected");
      client.subscribe("/tic");                         // Subscribe
      conf_status = true;
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);                                      // Wait 5 seconds before retrying
      conf_status = false;
    }
  }
  return conf_status;
}

void mess_aws(){                                        //Create function mess aws
  client.setServer(mqtt_server, 1883);                  //Connect port and server
}

void callback(char* topic, byte* message, unsigned int length){                 //Create function callback
  if ((X_win==false)&&(O_win==false)) get_data_to_aws(topic, message, length);
//  get_data_to_aws(topic, message, length);
}

void get_data_to_aws(String topic, byte* message, unsigned int length){         //Create function get data to aws
  String messageTemp;
  for (int i = 0; i < length; i++) {
    messageTemp += (char)message[i];
  }
  //Serial.println(messageTemp);
  StaticJsonDocument<1024> doc;                             //Create object json get                     
  deserializeJson(doc, messageTemp);
  const String one = doc["data"];
  JsonArray Array = doc["data"].as<JsonArray>();
  for(JsonVariant v : Array) {
    //Serial.println(v.as<int>());
  }
  
  display.clearDisplay();
  display.setTextSize(2);                                   //Display setting
  display.setTextColor(WHITE);
  for(int i = 0; i < SIZE; i++){                            //Create cycle in cycle to fill
    for(int j = 0; j < SIZE; j++){                
      if(Array[j][i] == 0){
        display.setCursor(23+i*30,2+j*23);             
        display.println("0"); 
        display.display();
      } else if(Array[j][i] == 1){
        display.setCursor(23+i*30,2+j*23);             
        display.println("X"); 
        display.display();
      }
    }
  } 
  matrix_check();                                           //Check win
  display.clearDisplay();
  display.display();
  
  //move_win();
}

void IRAM_ATTR isr() {                                      //Create function interrupt
  conf_button_pressed = !conf_button_pressed;               //Pining button
}

void init_wire(){                                           //Create function init wire
  Wire.begin();                                             //Init work I2C bus
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {          //Audit physical connect oled
    Serial.println("SSD1306 allocation failed");
    for(;;);
  } 
}

void pr_win(){                                              //Create function printing win
  display.setTextSize(2);                                   //Display setting
  display.setTextColor(WHITE);
  for(int i = 0; i < SIZE; i++){                            //Create cycle in cycle to fill
    for(int j = 0; j < SIZE; j++){
      if(Array[j][i] == 0){
        display.setCursor(23+i*30,2+j*23);             
        display.println("0"); 
        display.display();
      } else if(Array[j][i] == 1){
        display.setCursor(23+i*30,2+j*23);             
        display.println("X");
        display.display();
      }
    }
  }
}

#endif
