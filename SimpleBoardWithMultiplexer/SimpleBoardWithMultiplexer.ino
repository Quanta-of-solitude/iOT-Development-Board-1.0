/*
 * Based on MQTT Adafruit Example, changes made accordingly
 * Under FeedName avoid using <>
 * 
 * For IoT Development Board, 1.0 @Technomate Edubotics Pvt Ltd.
 * 
 * Using 4051 IC
 */
 
#define MUX_A D4
#define MUX_B D3
#define MUX_C D2

#define ANALOG_INPUT A0



void changeMux(int c, int b, int a) {
  digitalWrite(MUX_A, a);
  digitalWrite(MUX_B, b);
  digitalWrite(MUX_C, c);
}

void setup() {
  Serial.begin(115200);
  pinMode(MUX_A, OUTPUT);
  pinMode(MUX_B, OUTPUT);     
  pinMode(MUX_C, OUTPUT); 
}



void loop() {

  
  Serial.print("Moisture: ");
  Serial.print(soilSensor());
  Serial.print(" | temp: ");
  Serial.println(get_temp());
  delay(100);
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
