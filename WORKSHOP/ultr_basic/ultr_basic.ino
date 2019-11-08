const int TRIGPIN = D7;  //Digital pin D5
const int ECHOPIN = D8;  //Digital pin D6

int distance;
 
void setup() 
{
  Serial.begin(9600);
  pinMode(ECHOPIN,INPUT);//receiver
  pinMode(TRIGPIN,OUTPUT);//sender
  
}

void loop() {
  
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN,LOW);
  float duration = pulseIn(ECHOPIN,HIGH);
  Serial.print("duration =   ");
  Serial.print( duration);
  distance= duration*0.034/2;
  Serial.print(" || distance =   ");
  Serial.print(distance);
  Serial.println("cm");
  delay(200);
}
