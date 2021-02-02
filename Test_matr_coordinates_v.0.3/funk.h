#ifndef funk_h
#define funk_h

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <WiFi.h>
#include <PubSubClient.h>

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
void get_won();                                           //Winning function
void IRAM_ATTR isr();                                     //Button interuption funtion
void second_menu();                                       //Game board drawing function
void print_matrix();                                      //Array print function
bool connect_aws();
void send_data_to_aws();                                            //Send data on the aws
void start_config();                                                //Disconnects from AWS and turns of wifi, turns of BLE to start configuration
void start_transfer();                                              //Starts wifi and connects to aws to start transfering data
bool connect_wifi();
void callback(char* topic, byte* message, unsigned int length);

/*----------FUNKTIONS----------*/
void print_matrix(){
  int A[SIZE][SIZE];
  delay(1000);
  display.clearDisplay();
  display.setTextSize(2);             
  display.setTextColor(WHITE);
  randomSeed(9);
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      (A[i][j] = random(3));
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
bool setup_wifi(){
  bool conf_status = false;
  
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");   // We start by connecting to a WiFi network
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    conf_status = false;
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  conf_status = true;
  
  return conf_status;
}

bool connect_aws(){
  bool conf_status = false;
  
  while (!client.connected()){                          // Loop until we're reconnected
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client")) {              // Attempt to connect
      Serial.println("connected");
      client.subscribe("esp32/output");                 // Subscribe
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

void callback(char* topic, byte* message, unsigned int length){
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  Serial.println();
  // Feel free to add more if statements to control more GPIOs with MQTT
  // If a message is received on the topic esp32/output, you check if the message is either "on" or "off". 
  // Changes the output state according to the message
  if (String(topic) == "esp32/output") {
    Serial.print("Changing output to ");
  }
}

void send_data_to_aws(){
  
}

void start_transfer() {  
  conf_button_pressed = false;
  
  if (!connect_wifi()) {
    Serial.println("Failed connecting to wi-fi");
  } else {
    Serial.println("Succesfully connected to wi-fi");
    if (!connect_aws()) {
      Serial.println("Failed connecting to AWS");
    } else {
      Serial.println("Succesfully connected to AWS");
    } 
  }
}

void start_config() {
  Serial.println("Start config mode");
 
}

#endif
