//Codigo de programacion servomotor :u
//librerias
#include <Servo.h>
//Crear objetos
Servo servo1;
Servo servo2;
//Configurar el servomotor

void setup()
{
 servo1.attach (7,600,1500);
 servo2.attach (8,600,1500);
 pinMode(1,OUTPUT); 
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);

 
}

void loop ()
{
  
servo1.write (0);
delay(200);
digitalWrite(1,HIGH);
delay(200);
digitalWrite(1,LOW);
delay(200);
servo1.write (90);
delay (200);
digitalWrite(2,HIGH);
delay(500);
digitalWrite(2,LOW);
delay(500);
servo1.write (180);
delay (200);
digitalWrite(3,HIGH);
delay(300);
digitalWrite(3,LOW);
delay(300);
servo2.write (0);
delay (200);
digitalWrite(4,HIGH);
delay(200);
digitalWrite(4,LOW);
delay(200);
servo2.write (90);
delay (200);
digitalWrite(5,HIGH);
delay(400);
digitalWrite(5,LOW);
delay(400);
servo2.write (180);
delay (300);
digitalWrite(6,HIGH);
delay(200);
digitalWrite(6,LOW);
delay(200);
servo1.write (0);
delay (200);
servo2.write (0);
delay (200);

}
