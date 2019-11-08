/*
 * Based on Blynk Examples, changes made accordingly.
 * Under FeedName avoid using <>
 * 
 * For IoT Development Board, 1.0 @Technomate Edubotics Pvt Ltd.
 * 
 */
 
#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>


const char* ssid = " ";    //Your Network SSID Here
const char* password = " "; //Your Network password, here
char auth[] = " "; //Your aauthentication of Blynk App

int SOIL_MOISTURE= A0;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth,ssid,password);
}


void loop()
{
  int soil=analogRead(A0);
  Serial.println(soil);
  Blynk.run();
  delay(500);
}
