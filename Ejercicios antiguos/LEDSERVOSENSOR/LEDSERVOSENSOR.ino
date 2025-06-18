//librerias
#include <Servo.h>
//---------------
Servo servo1;

//---------------------
long distancia;
long tiempo;
int led1 = 11;
int led2 = 8;
//----------------------------
void setup(){
 servo1.attach (6,600,1500);
 
 Serial.begin(9600); 
  pinMode (10,OUTPUT);
  pinMode (9,INPUT);
  pinMode (11,OUTPUT);
  pinMode (8,OUTPUT);
  
}
void loop(){
  
  digitalWrite(10,LOW);
  delayMicroseconds(5);
  
  //Indica al tigger a hacer pulso
  digitalWrite(10,HIGH);
  delayMicroseconds(5);
  
  
  //tiempo y distancia
  tiempo = pulseIn (9, HIGH);
  distancia = long (0.017*tiempo);
  
  //led1-----------
  if (distancia<40){
    digitalWrite(11,HIGH);
  }
  else{
  if (distancia>40){
    digitalWrite(8,HIGH);
  }
  }
  if (distancia<40){
    digitalWrite(8,LOW);
  }
  if(distancia>40){
  }
  else{
    digitalWrite(11,LOW);
  }
  //servo1---------------
  if (distancia<20){
    servo1.write(0);
    delay(700);
  }
  
  //servo1----------------
  if (distancia>20){
    servo1.write(90);
    delay(700);
  }
  
  
}
