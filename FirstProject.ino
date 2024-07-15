#include <Servo.h>
const int SERVO = 13;
Servo myservo;
int increase = 10;
int min_angle = 0;
int max_angle = 180;
int pos = min_angle;

const int trig_pin = 6;
const int echo_pin = 7;
int RED = 4;
int GREEN = 3;
int BLUE = 2;

void setup() {
pinMode(trig_pin, OUTPUT);
pinMode(echo_pin, INPUT);
pinMode(RED,OUTPUT);
pinMode(GREEN,OUTPUT);
pinMode(BLUE,OUTPUT);
myservo.attach(13);
Serial.begin(115200);

}

void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
 
  long duration = pulseIn(echo_pin, HIGH);  //pulseIn으로 받아들임
  long distance = duration/58;
  myservo.write(pos);      //
  pos += increase;
  if(pos <= min_angle || pos >= max_angle)
    increase = increase*  -1;
  delay(30);

 
  Serial.print(distance);
  Serial.println(" cm");


  if (distance <= 5) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }
  else if ((distance >= 6) && (distance <= 10)) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
  }
  else if ((distance >= 11) && (distance <= 15)){
    digitalWrite(BLUE,HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
  }
  delay(20);
  }






