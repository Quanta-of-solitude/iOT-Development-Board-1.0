/*
 * Based on MQTT Adafruit Example and Blynk Example, changes made accordingly.
 * Under FeedName avoid using <>
 * 
 * For IoT Development Board, 1.0 @Technomate Edubotics Pvt Ltd.
 * 
 * Using 4051 IC
 */

#include<ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include"Adafruit_MQTT_Client.h"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = " "; //Your Network SSID Here
char password[] = " "; //Your Network password, here

char auth[] = " "; //Your aauthentication of Blynk App

//Adafruit io setup...
#define AIO_SERVER "io.adafruit.com"
#define AIO_SERVERPORT 1883
#define AIO_USERNAME " " //Adafruit Username
#define AIO_KEY " " //Adafruit Secret Key

#define MUX_A D4
#define MUX_B D3
#define MUX_C D2

#define ANALOG_INPUT A0

float get_value();

WiFiClient client;

Adafruit_MQTT_Client mqtt(&client,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY);
/***********feeds************/
Adafruit_MQTT_Publish Data = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME"/feeds/<FeedNameofDisplay>");

/***********feeds************/

void MQTT_connect();

/***********Reading Values to Blynk From Sensors************/

BLYNK_READ(V4) //VirtualPin 4
{
  float val = get_value(); 
  Blynk.virtualWrite(V4, val); //sending to Blynk
}



void setup(){
  Serial.begin(115200);
  Serial.println();
  Serial.println("connecting to.......");
  Serial.println(ssid);
  pinMode(MUX_A, OUTPUT);
  pinMode(MUX_B, OUTPUT);     
  pinMode(MUX_C, OUTPUT);     
  WiFi.begin(ssid,password);
  
  while(WiFi.status()!= WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
  }
  Serial.println();
  Serial.println("Wifi connected...");
  Serial.println("IP = ");
  Serial.println(WiFi.localIP());
  Blynk.begin(auth,ssid,password);
}


 void loop(){

  MQTT_connect();
  Blynk.run();
  
 Serial.println("\nSending the Value");
   if (! Data.publish(get_value())){
    Serial.println("Failed!");
    }
  else{
    Serial.println("Value Sent!");  
  }
  delay(2000);

 }
/***********Creating Connection************/
void MQTT_connect(){
  int8_t ret;
  //stop if already connected
  if(mqtt.connected())
  {
    return;
  }
  Serial.print("connecting to MQTT.......");
  uint8_t retries=1;
  while((ret=mqtt.connect())!=0)
  {
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds.....");
    mqtt.disconnect();
    delay(5000);
    retries--;
    if(retries==0)
    {
      while(1);
      
    }
  }
  Serial.println("MQTT CONNECTED.......//");
}

/***********Function For reading AnalogValue at A0************/
float get_value(){
 
  int analogValue = analogRead(ANALOG_INPUT);
  return analogValue;
  
}
