#define trigPin 7
#define echoPin 6
#define led 11
#define led2 10
#include <Servo.h> 

//pins:
//trigpin D7
//echopin D6
//servopin D9

Servo myservo;  
int pos = 0;   
int measure;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  myservo.attach(9);
}

void loop() {
  int  distance = getDistance();
  if (distance <= 400){
  int temp = distance/2.2222;
  measure = 180 - temp;
  myservo.write(measure);
 Serial.print("distance:");
 Serial.println(distance);
  Serial.print("servo:");
  Serial.println(measure);
  };
  delay(500);
} 

int getDistance(){
  long duration;
  long distance = 0;
  int y;
  for (int i=0;i<10;i++){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.6;
  if (distance > 400){
    i--;
    }
  else{  
  y = y + distance;
  }
  }
  int x = y / 10;
  y = 0;
  Serial.println (x);
  return x;
  }
