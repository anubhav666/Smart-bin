#include <Ultrasonic.h>
//#include <Servo.h>
Ultrasonic ultrasonic(13, 12);
//Servo myservo;
int c=0;  
void setup() {
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
Serial.begin(9600);
}

void loop() {
  //myservo.attach(9);
  Serial.print("Distance in CM: ");
  // Pass INC as a parameter to get the distance in inches
  Serial.println(ultrasonic.distanceRead());
  if(ultrasonic.distanceRead()>10 && ultrasonic.distanceRead()<30)
  {
    if(c==0)
    {
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      delay(1000); 
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      c=1; 
    }
    else
    {
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);          
    } 
  }
  else
  {
    if(c!=0)
    {
      digitalWrite(11,LOW);
      digitalWrite(10,HIGH);
      delay(750); 
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);  
      c=0;
    }
    else
    {
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);          
    }
  }
  delay(500);
}
