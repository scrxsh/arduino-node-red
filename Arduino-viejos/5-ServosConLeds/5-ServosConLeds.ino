// Servomotor con Varios Leds sin Ciclo For
#include <Servo.h>
Servo servoA;
Servo servoB;

void setup()
{
    servoA.attach (7);
    servoB.attach (8);
    pinMode(1,OUTPUT); 
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
}

void loop ()
{
    servoA.write (0);
    delay(200);
    digitalWrite(1,HIGH);
    delay(200);
    digitalWrite(1,LOW);
    delay(200);
    servoA.write (90);
    delay (200);
    digitalWrite(2,HIGH);
    delay(500);
    digitalWrite(2,LOW);
    delay(500);
    servoA.write (180);
    delay (200);
    digitalWrite(3,HIGH);
    delay(300);
    digitalWrite(3,LOW);
    delay(300);
    servoB.write (0);
    delay (200);
    digitalWrite(4,HIGH);
    delay(200);
    digitalWrite(4,LOW);
    delay(200);
    servoB.write (90);
    delay (200);
    digitalWrite(5,HIGH);
    delay(400);
    digitalWrite(5,LOW);
    delay(400);
    servoB.write (180);
    delay (300);
    digitalWrite(6,HIGH);
    delay(200);
    digitalWrite(6,LOW);
    delay(200);
    servoA.write (0);
    delay (200);
    servoB.write (0);
    delay (200);
}
