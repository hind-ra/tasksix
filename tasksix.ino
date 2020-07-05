
#include <Servo.h>

Servo servomotor; 
 

int trigPin1  =   6;
int echoPin1  =   7;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  servomotor.attach(5);
  }
void loop() {
  long duration1, distance1;
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

//let's suppose that the track width is 90cm  
  
  if ( distance1 >= 40 && distance1 <= 80)
  {
    Serial.println(distance1);
    servomotor.write(45);
  }
  else
     if (  distance1 < 40 && distance1 >=  35)
   {
     Serial.println(distance1);
     servomotor.write(90);
     
  }
     else
     if (  distance1 < 35 && distance1 >= 30 )

   {
     Serial.println(distance1);
     servomotor.write(180);
     
  }
  else
       {
     Serial.println(distance1);
     Serial.println("Out of range");
     servomotor.write(0);
     
  }
    delay(50);

}
  
