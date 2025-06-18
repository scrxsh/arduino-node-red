//SERVOMOTOR
#include <Servo.h>
Servo s1;

//TALLER SENSOR TEMPERATURA

//SENSOR TEMPERATURA DEFINIR
int sf =0;
int c = 1;

//SENSOR ULTRASONICO

long d;
long t;
int l1 = 2;
int l2 = 3;

//VOID SETUP

void setup (){
  
//ACTIVAR SERVO
s1.attach (13,600,1500);
//SENSOR DE FUEGO

//ACTIVAR SENSOR US
Serial.begin (9600); 
pinMode (5, OUTPUT);//TRIGGER  
pinMode (4, INPUT);//ECHO

//ACTIVAR LEDS Y CHICHARRA

pinMode (c, OUTPUT);
pinMode (l1,OUTPUT);
pinMode (l2,OUTPUT);
}

void loop (){
//SENSOR DE TEMPERATURA  
sf = analogRead(A0);
Serial.println("el valor detectado del sensor es:");
Serial.println(sf);

//ACTIVAR SENSOR CON EL IF

if (sf<500){
  
//ACTIVAR LEDS Y SENSOR
digitalWrite (c, HIGH);
delay (100);
digitalWrite (l1, HIGH);
digitalWrite (l2, HIGH);

//MOVIMIENTOS DEL SERVO
  s1.write (0);//1
  delay (500);
  s1.write (180);
  delay (500);
  s1.write (0);//2
  delay (500);
  s1.write (180);
  delay (500);
  s1.write (0);//3
  delay (500);
  s1.write (180);
  delay (500);
  s1.write (0);//4
  delay (500);
  s1.write (180);
  delay (500);
  s1.write (0);//5
  delay (500);
  s1.write (180);
  delay (500);
  s1.write (0);//6
  delay (500);
  s1.write (180);
  delay (500);
  s1.write (0);//7
  delay (500);
  s1.write (180);
  delay (500);
  s1.write (0);//8
  delay (500);
  s1.write (180);
  delay (500);
  s1.write (0);//9
  delay (500);
  s1.write (180);
  delay (500);
  s1.write (0);//10
  delay (500);
  s1.write (180);
  delay (500);
  
  
//ACTIVAR SENSOR ULTRASONICO

  digitalWrite(5, LOW);
  delayMicroseconds (5);
  digitalWrite(5, HIGH);
  delayMicroseconds (10);
  
  t = pulseIn (4, HIGH);
  d = long(0.017*t); 
  
 Serial.println("La distancia detectada es: ");
 Serial.println(d);
 Serial.println("cm");
 delay (300);
}

else {
//APAGAR CHICHARRA Y LEDS
digitalWrite (c, LOW);
delay (50);
digitalWrite (l1,LOW);
digitalWrite (l2,LOW);
//SERVO POSICION INICIAL
s1.write (0);


}
}
