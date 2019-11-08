/*
 * Based on Blynk Examples, changes made accordingly.
 * Under FeedName avoid using <>
 * 
 * For IoT Development Board, 1.0 @Technomate Edubotics Pvt Ltd.
 * 
 */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define ANALOG_INPUT A0

char auth[] = " "; //Your aauthentication of Blynk App
char ssid[] = " "; //Your Network SSID Here
char password[] = " "; //Your Network password, here

/***********Reading Values to Blynk From Sensors************/

BLYNK_READ(V4) //VirtualPin 4
{
  float val = get_value(); 
  Blynk.virtualWrite(V4, val); //sending to Blynk
}

void setup() {
  //Serial.begin(115200);
  Blynk.begin(auth,ssid,password);
 
}


void loop() {
  Blynk.run();
}



  /***********Function For reading AnalogValue at A0************/
float get_value(){
 
  int analogValue = analogRead(ANALOG_INPUT);
  return analogValue;
  
}
