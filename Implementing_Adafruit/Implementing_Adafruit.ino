/*
 * Based on MQTT Adafruit Example, changes made accordingly
 * Under FeedName avoid using <>
 * 
 * For IoT Development Board, 1.0 @Technomate Edubotics Pvt Ltd.
 * 
 * Using 4051 IC
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

#define MUX_A D4
#define MUX_B D3
#define MUX_C D2

#define ANALOG_INPUT A0

float soilSensor();
float get_temp();

WiFiClient client;


Adafruit_MQTT_Client mqtt(&client,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY);
/***********feeds************/
Adafruit_MQTT_Publish TemperatureBoard = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME"/feeds/<FeedNameofTemperatureDisplay>");
Adafruit_MQTT_Publish SoilMoisture = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME"/feeds/<FeedNameofSoilMoistureDisplay>");
/***********feeds************/

void MQTT_connect();


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
  
}

void changeMux(int c, int b, int a) {
  digitalWrite(MUX_A, a);
  digitalWrite(MUX_B, b);
  digitalWrite(MUX_C, c);
}

 void loop(){

  MQTT_connect();
  
  Serial.println("\nSending the Temperature");
   if (! TemperatureBoard.publish(get_temp())){
    Serial.println("Failed!");
    }
  else{
    Serial.println("Value Sent!");  
  }
  delay(2000);

  //Sending Moisture Sensor Value
  Serial.println("\nSending the Moisture");
  if (! SoilMoisture.publish(soilSensor())){
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


/***********Function For reading AnalogValue at X0, board pin 13************/
float soilSensor(){

  float lum;
  changeMux(LOW, LOW, LOW);
  lum = analogRead(ANALOG_INPUT);//X0
  delay(10);            
  lum = analogRead(ANALOG_INPUT);
  delay(10);
  return lum;
  
  }

/***********Function For reading AnalogValue at X2, board pin 15************/
float get_temp(){
  
  float temp_val;
  changeMux(LOW,HIGH,LOW); //X2
  int analogValue = analogRead(ANALOG_INPUT);
  temp_val = (analogValue * 3.30);
  delay(10); 
  temp_val = (analogValue * 3.30);
  delay(10);
  temp_val = (temp_val/10); 
  return temp_val;
  
}
