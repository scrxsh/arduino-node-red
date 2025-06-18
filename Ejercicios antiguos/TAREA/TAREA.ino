#include <Servo.h>
#include <DHT.h>

//CONSTANTE VENTILADOR Y SENSOR
const int v=1;
const int st=A0;

//TEMPERATURA Y HUMEDAD
int t;
int h;
DHT dht (st, DHT11);

//SERVO
Servo s1;

void setup()
{//TEMPERATURA Y HUMEDAD 
Serial.begin (9600);
pinMode (v, OUTPUT);
dht.begin();

//SERVO
s1.attach (4,600,1500);

//LEDs
pinMode(2,OUTPUT);  
pinMode(3,OUTPUT);}

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

//CICLO IF POR SENSOR DE TEMPERATURA

//FASE 1
if (t>=27){
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
if (t<26) {
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
}
}





