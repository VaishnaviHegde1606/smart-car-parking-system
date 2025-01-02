#include <Servo.h>

#define trigPin1 9
#define echoPin1 10
#define trigPin2 11
#define echoPin2 12
#define servoPin1 5
#define servoPin2 6


int count1 = 0;
int count2=0;
int count3=0;

Servo servo1;
Servo servo2;

void setup() {
  
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
}

void loop() {
  // Measure distance 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin1, LOW);
  long duration1 = pulseIn(echoPin1, HIGH);
  float distance1 = duration1 / 58;

  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  // Control servo motor 1
  if (distance1 < 6 || distance1 == 0) {
    servo1.write(0);
    Serial.println("Servo 1 closed");
  } else if (distance1 >6) {
    servo1.write(90);
    Serial.println("Servo 1 opened");
  }

  // Measure distance 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin2, LOW);
  long duration2 = pulseIn(echoPin2, HIGH);
  int distance2 = duration2 / 58;

  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Control servo motor 2
  if (distance2 > 6 || distance2 == 0) {
    servo2.write(180);
    Serial.println("Servo 2 closed");
  } else if (distance2 < 6 ) {
    servo2.write(90);
    Serial.println("Servo 2 opened");
  }
int sensor1Value = digitalRead(A0); 
int sensor2Value = digitalRead(A1);
int sensor3Value = digitalRead(A2);
Serial.print("Sensor Values=");
Serial.print(sensor1Value);
Serial.print(", ");
Serial.print(sensor2Value);
Serial.print(", ");
Serial.println(sensor3Value);

//delay(1000);
if (sensor1Value==0)
{
Serial.println("CAR DETECTED AT PARKING 1...!");

if(count1<1){
count1++;}

//Serial.print("count1=");
//Serial.println(count1);


//digitalWrite(LED, HIGH);
}
else if(sensor1Value==1)
{
Serial.println("No car detected at parking 1");
if(count1>0){
count1--;}

//Serial.println("count1=");
//Serial.println(count1);

//digitalWrite(LED, LOW);
}


if (sensor2Value==0)
{
Serial.println("CAR DETECTED AT PARKING 2...!");

if(count2<1){
count2++;}

//Serial.print("count2=");
//Serial.println(count2);


//digitalWrite(LED, HIGH);
}
else if(sensor2Value==1)
{
Serial.println("No car detected at parking 2");
if(count2>0){
count2--;}



//Serial.println("count2=");
//Serial.println(count2);

//digitalWrite(LED, LOW);
}


if (sensor3Value==0)
{
Serial.println("CAR DETECTED AT PARKING 3...!");

if(count3<1){
count3++;}

//Serial.print("count3=");
//Serial.println(count3);


//digitalWrite(LED, HIGH);
}
else if(sensor3Value==1)
{
Serial.println("No car detected at parking 3");
if(count3>0){
count3--;}

//Serial.println("count3=");
//Serial.println(count3);

//digitalWrite(LED, LOW);
}
Serial.print("Occupied Spots: ");
Serial.println(count1+count2+count3);
if(count1+count2+count3==3){
    Serial.println("NO VACANT SLOTS");
  }
delay(1000);

  delay(500); // Wait for a moment
}