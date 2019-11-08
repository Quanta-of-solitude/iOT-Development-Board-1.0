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


#define TRIGGERPIN D7
#define ECHOPIN    D8
char auth[] = " ";  //Your aauthentication of Blynk App
char ssid[] = " "; //Your Network SSID Here
char pass[] = " "; //Your Network password, here

int distance;
WidgetLCD lcd(V1);

void setup()
{
  Serial.begin(9600);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Blynk.begin(auth, ssid, pass);
  lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 0, "Distance in cm");
}


void loop()
{
  
  lcd.clear();
  lcd.print(0, 0, "Distance in cm");
  //lcd.print(0,0);
  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance= duration*0.034/2;
 // distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println("Cm");
  lcd.print(7, 1, distance);

  
  if (0 < distance && distance < 4)
  {
    Serial.println("Tank full");
    Blynk.virtualWrite(V2, 1023);
    Blynk.notify("Alert:Tank full");
  } 
  
  if( 5< distance && distance < 8)
  {
    Blynk.virtualWrite(V3, 1023);
    Serial.println("ALLMOST FULL");
    Blynk.notify("Alert:Tank half");
  }
  
  if(15< distance && distance < 18)
  {
    Serial.println("EMPTY");
    Blynk.virtualWrite(V4, 1023);
    Blynk.notify("Alert:EMPTY");
  }
    
  Blynk.virtualWrite(V1, distance);
  Blynk.run();
  delay(3500);
}
