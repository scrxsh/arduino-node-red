// Servomotor, ventilador, sensor ultrasonico y sensor de temperatura de acuerdo a condiciones - DHT11/HCSR04

#include <Servo.h>
#include "DHT.h"

//Constantes de los pines del ventilador

#define ventilador 11
#define DHTPIN 10
#define SERVOPIN 5
#define led1 6
#define led2 7
#define led3 8
#define led4 9
#define TRIGGER_PIN 4 /* Preferiblemente ~PWM*/
#define ECHO_PIN 3

//Variables temperatura y humedad instanciando el sensor
int temp;
int humedad;
DHT dht (DHTPIN, DHT11);

//Distancia y tiempo
long distancia;
long tiempo;

//SERVO
Servo servo;

void setup()
{
  //DHT11, leds y ventilador
  Serial.begin (9600);
  pinMode (ventilador, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  dht.begin();

  //Sensor ultrasonico
  pinMode (TRIGGER_PIN, OUTPUT);//TRIGGER  
  pinMode (ECHO_PIN, INPUT);//ECHO

  //Servomotor
  servo.attach (SERVOPIN);
}

void loop (){
  //Lecturas de la temperatura/Humedad
  humedad = dht.readHumidity();
  temp = dht.readTemperature();

  //Monitor serial de Temperatura/Humedad
  Serial.println("La temperatura es: ");
  Serial.println(temp);
  Serial.println("La humedad es: ");
  Serial.println(humedad);
  Serial.println("%");
  
  delay (1000);

  //Calibracion ultrasonico
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds (5);//delay microsegundos
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds (5);
  
  //Lectura HCSR04
  tiempo = pulseIn (ECHO_PIN, HIGH); 
  distancia = long(0.017*tiempo); 

  Serial.println("La distancia detectada es: ");
  Serial.println(distancia);
  Serial.println("cm");

  controlSensores();
  delay (500);

}


//Funcion control de sensores
void controlSensores(){
  // Condiciones de temperatura
  if (temp>=24){
    Serial.println("Ventilador encedido");
    digitalWrite (ventilador, HIGH);
    temp = dht.readTemperature();

    servo.write (0);
    delay (700);
    servo.write (180);
    delay (700);
    digitalWrite (led1,HIGH);
    delay (3000);
    digitalWrite (led2,LOW);
    delay(3000);
  } 

  if(temp<24){
    Serial.println("Ventilador apagado");
    digitalWrite (ventilador, LOW);
    temp = dht.readTemperature();

    servo.write (180);
    delay (700);
    servo.write (0);
    delay (700);
    digitalWrite (led2, HIGH);
    delay (3000);
    digitalWrite (led1,HIGH);
    delay(3000);
  } 

  //Condiciones de distancia
  if(distancia > 40){
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  } else {
    digitalWrite(led4, HIGH);
    digitalWrite(led3, LOW);
  }

}