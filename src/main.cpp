#include <Arduino.h>
#include<Wire.h>
#include<WiFi.h>
#include <Adafruit_I2CDevice.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <MQTTClient.h>
#include <math.h>
#include <string>
#include <ArduinoJson.h>
#include <key.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//=============================//
#define PIN_RX  16  //Pin read 
#define PIN_TX  17  //Pin text
#define DEVICE_NAME "DEV01"                                                            //The name of the device. This MUST match up with the name defined in the AWS console
#define AWS_IOT_ENDPOINT "xxx.amazonaws.com"              //The MQTTT endpoint for the device (unique for each AWS account but shared amongst devices within the account)
#define AWS_IOT_TOPIC "/"+ DEVICE_NAME+ "/comand"                                      //The MQTT topic that this device should publish to
#define AWS_MAX_RECONNECT_TRIES 50  
//=============================//
//wifi configuration
const int conf_par_size = 25;
char conf_wifi_ssid[conf_par_size] = "";                         //Login and password Wifi network
char conf_wifi_password[conf_par_size] = "";
bool conf_button_pressed = false;
const int max_connect_attempts = 10;                             //variable repeat connect
MQTTClient client = MQTTClient(256);
WiFiClientSecure net = WiFiClientSecure();
//==============================//
void init_wire();                                                   //Initialization I2C
bool connect_to_aws();                                              //Connect to aws
void disconnect_aws();                                              //Disconnect to aws
void send_data_to_aws();                                            //Send data on the aws
void message_handler(String &topic, String &payload);               //Forming a letter to send
bool connect_to_wifi();                                             //Connect to network
void disconnect_wifi();                                             //Disconnect network


void setup() {
  Serial.begin(115200);
  init_wire();                                                      //Wire bus initialization
  if (String(conf_wifi_ssid) == "" ||  String(conf_wifi_password) == "") {  //if we don't have credentials to wifi then lets start ble for initialization
    
  } else {   
    //otherway we can start connecting to wifi

  }
}

void loop() {
  send_data_to_aws();                                                     //Data transfer
}

//=================================Functions==========================================//
void init_wire() {
  Wire.begin();
 
}
bool connect_to_wifi(){
  bool c_status = false;
  WiFi.mode(WIFI_STA);
  WiFi.begin(conf_wifi_ssid, conf_wifi_password);
  int retries = 0;                                                                              //Only try $max_connect_attempts times to connect to the WiFi
  while(WiFi.status() != WL_CONNECTED && retries < max_connect_attempts && !conf_button_pressed) {
    delay(500);
    Serial.print(".");
    retries++;
  }
  Serial.println(".");
  if(WiFi.status() != WL_CONNECTED && !conf_button_pressed) {                                   //If we still couldn't connect to the WiFi, go to deep sleep for a minute and try again.
    esp_sleep_enable_timer_wakeup(1 * 10L * 1000000L);
    esp_deep_sleep_start();
    c_status = false;
  } else if (!conf_button_pressed) {
    c_status = true;
  }
  return c_status;
}
void disconnect_wifi(){
  Serial.println("disconnect_wifi");
  WiFi.disconnect();                                                              // cut off the WIFI connection
  WiFi.softAPdisconnect();                                                        // we disconnect the access point (if it was)
  WiFi.mode(WIFI_OFF);                                                            // Off WIFI
}
bool connect_to_aws() {
  bool c_status = false;
  
  net.setCACert(aws_cert_ca);                                                     //Configure WiFiClientSecure to use the AWS certificates we generated
  net.setCertificate(aws_cert_crt);
  net.setPrivateKey(aws_cert_private);
  client.begin(AWS_IOT_ENDPOINT, 8883, net);                                      //Connect to the MQTT broker on the AWS endpoint we defined earlier
  int retries = 0;
  Serial.println("Connecting to AWS IOT");                                        //Try to connect to AWS and count how many times we retried.
  while(!client.connect(DEVICE_NAME) && retries < AWS_MAX_RECONNECT_TRIES && !conf_button_pressed){
    Serial.print(".");
    delay(1000);
    retries++;
  }
  
  if(!client.connected()){                                                        //Make sure that we did indeed successfully connect to the MQTT broker
    Serial.println(" Timeout!");                                                  //If not we just end the function and wait for the next loop.
  } else {
    Serial.println("!!!Connected!!!");                                            //If we land here, we have successfully connected to AWS!And we can subscribe to topics and send messages.
    client.subscribe("/" DEVICE_NAME "/comm");
    client.onMessage(message_handler);     
    c_status = true;
  }
  return c_status;
}
void disconnect_aws() {
  Serial.println("disconnect_aws");
  client.disconnect();
}
void send_data_to_aws(){
  Serial.println("Reading data from sensors and preparing for sending to AWS.");
  StaticJsonDocument<512> json_doc;                                                       //AWS object formation
  //JsonObject state_obj = json_doc.createNestedObject("state");
  //JsonObject reported_obj = state_obj.createNestedObject("reported");

//=================================JSON=========================================//
  char json_buffer[512];
  serializeJson(json_doc, json_buffer);
  client.publish("$aws/things/" DEVICE_NAME "/shadow/update", json_buffer);                                      //blink the led to inform that data was succefuly sent
  Serial.println("Sending data to AWS");
}
void message_handler(String &topic, String &payload){
  Serial.println("incoming: " + topic + " - " + payload);
}

void start_config() {
  Serial.println("Start config mode");
  disconnect_aws();
  disconnect_wifi();
}
void start_transfer() {  
  if (!connect_to_wifi()) {
    Serial.println("Failed connecting to wi-fi");
  } else {
    Serial.println("Succesfully connected to wi-fi");
    if (!connect_to_aws()) {

    } else {
    } 
  }
}



