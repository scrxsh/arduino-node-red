#include <Servo.h>
Servo s1;
long d;
long t;
int l1, l2;


void setup ()

{
  //LED
   pinMode(1,OUTPUT); 
   pinMode(2,OUTPUT);
  //SERVO
  s1.attach (3,600,1500);
  //SENSOR
  Serial.begin (9600); 
  pinMode (5, OUTPUT);//TRIGGER  
  pinMode (4, INPUT);//ECHO
}

void loop ()
{
  digitalWrite(5, LOW);
  delayMicroseconds (5);
  digitalWrite(5, HIGH);
  delayMicroseconds (10);
  t = pulseIn (4, HIGH);
  d = long(0.017*t); 
  
  //FASE 1
  if(d<40){
  digitalWrite (1, HIGH);
  delay(3000);
  }
  
  //FASE 2
  if(d<20){
  s1.write (5);
  delay (3000);
  }
  
  //FASE 3
  if(d>20){
  s1.write (90);
  delay (3000);
  digitalWrite (2, HIGH);
  delay (3000);
  }
  
  //FASE 4 Y FINAL
  if(d>40){
  digitalWrite (1, LOW);
  delay (5000);
  }
  
  //IMPRESION DE PANTALLA
  Serial.println("La distancia detectada es: ");
  Serial.println(d);
  Serial.println("cm");
  delay (500);
}
