#ifndef funk_h
#define funk_h

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <ArduinoJson.h>

/*----------DEFINES----------*/
#define PIN_RX  16                                        //Pin read 
#define PIN_TX  17                                        //Pin text
#define SCREEN_WIDTH 128                                  // OLED display width, in pixels
#define SCREEN_HEIGHT 64                                  // OLED display height, in pixels
#define BUTTON_PIN 4                                      //button
#define SIZE 3                                            //size arr
#define NX 'X'                                            //X
#define NY '0'                                            //0
#define DEVICE_NAME "TIC"                                 //The name of the device. This MUST match up with the name defined in the AWS console 

/*----------VARIABLES----------*/
long lastMsg = 0;
bool conf_button_pressed = false;
const char* ssid = "EE";
const char* password = "EE@05kilogram";                   // Replace the next variables with your SSID/Password combination
const char* mqtt_server = "192.168.1.113";                // Add your MQTT Broker IP address, example const char* mqtt_server = "Х.Х.Х.Х"
WiFiClient espClient;
PubSubClient client(espClient);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

/*----------PROTOTYPE FUNCTIONS----------*/
void init_wire();                                         //Initialization I2C
void first_menu();                                        //Input menu function
void get_print_win();                                     //Winning function
void IRAM_ATTR isr();                                     //Button interuption funtion
void second_menu();                                       //Game board drawing function
void print_matrix();                                      //Array print function
bool connect_aws();
void start_config();                                            
bool connect_wifi();
void callback(char* topic, byte* message, unsigned int length);
void get_data_to_aws(String topic, byte* message, unsigned int length);
void mess_aws();
void get_win();

/*----------FUNKTIONS----------*/
void start_config() {
  Serial.println("Start config mode");
  init_wire();
  first_menu();
  connect_wifi();
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
}

bool connect_wifi(){
  bool conf_status = false;
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    conf_status = false;
  }
  //Serial.println("WiFi connected");
  conf_status = true;
  return conf_status;
}

bool connect_aws(){
  bool conf_status = false;
  while (!client.connected()){                        // Loop until we're reconnected
    if (client.connect("ESP32Client")) {              // Attempt to connect
      Serial.println("MQTT connected");
      client.subscribe("/tic");                       // Subscribe
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

void second_menu(){
  delay(1000);
  display.clearDisplay();                                 //Clear display
  display.drawLine(15, 21, 95, 21, WHITE);
  display.drawLine(15, 43, 95, 43, WHITE);
  display.drawLine(42, 0, 42, 63, WHITE);
  display.drawLine(71, 0, 71, 63, WHITE);
  display.setCursor(22,15);
  client.setCallback(callback);
  display.display();
}

void get_win(){
//  if(){
//    
//  }
  get_print_win();
}

void get_print_win(){
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
}

void mess_aws(){
  client.setServer(mqtt_server, 1883);
}

void callback(char* topic, byte* message, unsigned int length){
  get_data_to_aws(topic, message, length);
}

void get_data_to_aws(String topic, byte* message, unsigned int length){
  String messageTemp;
  for (int i = 0; i < length; i++) {
    messageTemp += (char)message[i];
  }
  //Serial.println(messageTemp);
  StaticJsonDocument<1024> doc;
  deserializeJson(doc, messageTemp);
  const String one = doc["data"];
  JsonArray array = doc["data"].as<JsonArray>();
  for(JsonVariant v : array) {
    //Serial.println(v.as<int>());
  }
  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    display.clearDisplay();
    display.setTextSize(2);             
    display.setTextColor(WHITE);
    for(int i = 0; i < SIZE; i++){
      for(int j = 0; j < SIZE; j++){
        if(array[j][i] == 0){
          display.setCursor(23+i*30,2+j*23);             
          display.println("0"); 
          display.display();
        } else if(array[j][i] == 1){
          display.setCursor(23+i*30,2+j*23);             
          display.println("X"); 
          display.display();
        }
      }
    }
  }
}

void IRAM_ATTR isr() {
  conf_button_pressed = !conf_button_pressed;
}

void init_wire(){
  Wire.begin();
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for(;;);
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
      (A[i][j] = random(2));
    }
  }
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      if(A[i][j] == 0){
        display.setCursor(23+i*30,2+j*23);             
        display.println("0"); 
        display.display();
      } else if(A[i][j] == 1){
        display.setCursor(23+i*30,2+j*23);             
        display.println("X"); 
        display.display();
      }
    }
  }
}

#endif
