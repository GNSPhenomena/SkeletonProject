#include <Servo.h>
const int trigPin = 10,echoPin = 11,led1 = 3,led2 = 2;
Servo myservo;
int pos = 0;

void setup()
{ 
  myservo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  long duration,distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance < 70) 
  {
    for(pos = 90; pos < 120; pos++)
    {
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      myservo.write(pos);
      delay(15);
    }
    for(pos = 120; pos > 60; pos--)
    {
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      myservo.write(pos);
      delay(20);
    }
  }
  else
  { 
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    while(pos>92)
    {
      myservo.write(pos);
      delay(20);
      pos--;
    }
    while(pos<88)
    {
      myservo.write(pos);
      delay(20);
      pos++;
    }
  }
}
