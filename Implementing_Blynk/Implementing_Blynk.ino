/*
 * Based on Blynk Examples, changes made accordingly.
 * Under FeedName avoid using <>
 * 
 * For IoT Development Board, 1.0 @Technomate Edubotics Pvt Ltd.
 * 
 * Using 4051 IC
 */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define MUX_A D4
#define MUX_B D3
#define MUX_C D2

#define ANALOG_INPUT A0

char auth[] = " "; //Your aauthentication of Blynk App
char ssid[] = " "; //Your Network SSID Here
char password[] = " "; //Your Network password, here

/***********Reading Values to Blynk From Sensors************/
BLYNK_READ(V5) //VirtualPin 5
{
  float moist =soilSensor(); 
  Blynk.virtualWrite(V5,moist); //sending to Blynk
}
BLYNK_READ(V4) //VirtualPin 4
{
  float tempval = get_temp(); 
  Blynk.virtualWrite(V4, tempval); //sending to Blynk
}
//More can be added accordingly
/***********Reading Values to Blynk From Sensors************/


void setup() {
  Serial.begin(115200);
  Blynk.begin(auth,ssid,password);
  pinMode(MUX_A, OUTPUT);
  pinMode(MUX_B, OUTPUT);     
  pinMode(MUX_C, OUTPUT);     
}

void changeMux(int c, int b, int a) {
  digitalWrite(MUX_A, a);
  digitalWrite(MUX_B, b);
  digitalWrite(MUX_C, c);
}

void loop() {

  /*
   * Serial.print("ldr: ");
   * Serial.print(luminisence());
   * Serial.print(" | temp: ");
   * Serial.println(get_temp());
   */
  Blynk.run();
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
