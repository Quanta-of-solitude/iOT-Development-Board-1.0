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
int distance;
int TRIGGERPIN = D7;
int ECHOPIN  =  D8;
int RELAY=D6;

WidgetLCD lcd(V1);


void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth,ssid,password);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(RELAY,OUTPUT);
  pinMode(ECHOPIN, INPUT);
  lcd.clear();
}


void loop()
{ 
  lcd.clear();
  lcd.print(0, 0, "Distance in cm");
  int soil=analogRead(A0);
  long duration, distance;
  Serial.println(soil);
  delay(500);
  
  if(soil>600)
  {
   Serial.println("MOISTURE DETECTED");
   Blynk.notify("MOISTURE DETECTED ...NEED SOME WATER");                     
   digitalWrite(RELAY, HIGH);
  }
  else 
  {
   Serial.println("MOISTURE IS NORMAL");
   digitalWrite(RELAY, LOW);    
  }
  
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance= duration*0.034/2;
 // distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println("cm");
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
}
