//Smart Dustbin
#include<Servo.h>
Servo lid;
int trigPin = 9;
int echoPin = 8;
long distance;
long duration;

void setup(){
    lid.attach(7);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    lid.write(90);
}
void loop(){
    measureDistance();
    if(distance <= 10){
        Serial.println("Object detected, door open");
        lid.write(180);
        delay(3000);
    }
    else{
        Serial.println("No Object detected, Closing door");
        lid.write(90);
    }
    delay(1000);
}
void measureDistance(){
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(7);
    digitalWrite(trigPin,LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" CM");
}
