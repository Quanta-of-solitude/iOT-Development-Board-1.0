/*
 * Based on MQTT Adafruit Example, changes made accordingly
 * Under FeedName avoid using <>
 * 
 * For IoT Development Board, 1.0 @Technomate Edubotics Pvt Ltd.
 * 
 */
#include<ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include"Adafruit_MQTT_Client.h"

char ssid[] = " "; //Your Network SSID Here
char password[] = " "; //Your Network password, here


//Adafruit io setup...
#define AIO_SERVER "io.adafruit.com"
#define AIO_SERVERPORT 1883
#define AIO_USERNAME " " //Adafruit Username
#define AIO_KEY " " //Adafruit Secret Key

#define ANALOG_INPUT A0

float get_value();

WiFiClient client;


Adafruit_MQTT_Client mqtt(&client,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY);
/***********feeds************/
Adafruit_MQTT_Publish Data = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME"/feeds/<FeedNameofDisplay>");

/***********feeds************/

void MQTT_connect();


void setup(){
  Serial.begin(115200);
  Serial.println();
  Serial.println("connecting to.......");
  Serial.println(ssid);

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
  
}


 void loop(){

  MQTT_connect();
  
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


/***********Function For reading AnalogValue from board A0 pin************/
float get_value(){
  
  float temp_val;
  int analogValue = analogRead(ANALOG_INPUT);
  return analogValue;
  
}
