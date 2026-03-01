#include <Servo.h>
#include <DHT.h>

//CONSTANTE VENTILADOR Y SENSOR
const int v=1;
const int st=A0;

//TEMPERATURA Y HUMEDAD
int t;
int h;
DHT dht (st, DHT11);
//DISTANCIA Y TIEMPO
long d;
long td;
//SERVO
Servo s1;

void setup()
{//TEMPERATURA Y HUMEDAD 
Serial.begin (9600);
pinMode (v, OUTPUT);
dht.begin();

//distancia
pinMode (7, OUTPUT);//TRIGGER  
pinMode (6, INPUT);//ECHO


//SERVO
s1.attach (8,600,1500);

//LEDs
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
}

void loop (){
  //CONFIGURAR TIEMPO Y HUMEDAD
  h = dht.readHumidity();
  t = dht.readTemperature();
  //IMPRESION DE PANTALLA
  Serial.println("La temperatura es: ");
  Serial.println(t);
  Serial.println("La humedad es: ");
  Serial.println(h);
  Serial.println("%");
  
delay (1000);

//CONFIGURAR SENSOR ULTRASONICO
  digitalWrite(7, LOW);
  delayMicroseconds (5);//delay microsegundos
  digitalWrite(7, HIGH);
  delayMicroseconds (10);
  
  td = pulseIn (6, HIGH); //VARIABLE TIEMPO
  d = long(0.017*t); //VARIABBLE DISTANCIA
//CICLO IF POR SENSOR DE TEMPERATURA

//FASE 1
if (t>=24){
  Serial.println("ENCIENDE VENTILADOR");
  digitalWrite (v, HIGH);
  t = dht.readTemperature();
  //ENCENDER SERVO
  s1.write (0);
  delay (700);
  s1.write (180);
  delay (700);
  //ENCENDER LED1
  digitalWrite (2,HIGH);
  delay (3000);
  //APAGAR LED2
  digitalWrite (3,LOW);}

//FASE 2
else {
if (t<24) {
  //APAGAR VENTILADOR
  Serial.println("Apaga ventilador");
  digitalWrite (v, LOW);
  t = dht.readTemperature();
  //SERVO POSICION 2
  s1.write (180);
  delay (700);
  s1.write (0);
  delay (700);
  //ENCENDER LED2
  digitalWrite (3, HIGH);
  delay (3000);
  //APAGAR LED1
  digitalWrite (2,LOW);}
  
  //Fase 3
  if(d>40){
  digitalWrite (4, HIGH);//CONDICIONAL DISTANCIA
  }
  
  else 
  {
    digitalWrite (5,LOW);
  }
  
    if(d<40){
  digitalWrite (5, HIGH);//CONDICIONAL DISTANCIA
  }
  
  else 
  {
    digitalWrite (4,LOW);
  }
  
  Serial.println("La distancia detectada es: ");//IMPRESION DE PANTALLA
  Serial.println(d);
  Serial.println("cm");
  delay (500);
 
}
}
