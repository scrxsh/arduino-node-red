// Servomotor, ventilador y sensor de temperatura de acuerdo a condiciones - DHT11
#include <Servo.h>
#include "DHT.h"

//Constantes del pin, del ventilador y del servo
#define ventilador 11
#define ledA 5
#define ledB 6
#define DHTPIN 10
#define SERVOPIN 9
//Variables temperatura y humedad instanciando el sensor
int temp;
int humedad;
DHT dht (DHTPIN, DHT11);

//Servomotor
Servo servo;

void setup(){
  //DHT11, leds y ventilador
  Serial.begin (9600);
  pinMode (ventilador, OUTPUT);
  pinMode (ledA, OUTPUT);
  pinMode (ledB, OUTPUT);
  dht.begin();
  
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

  //Condiciones del ventilador, leds, y control
  if (temp>=27){
    Serial.println("Ventilador encendido");
    digitalWrite (ventilador, HIGH);

    temp = dht.readTemperature();

    //Mover el servo activar leds
    servo.write (0);
    delay (700);
    servo.write (180);
    delay (700);
    digitalWrite (ledA,HIGH);
    delay (3000);
    digitalWrite (ledB,LOW);
    delay(3000);
  } 
  if (temp<27) {
    Serial.println("ventilador apagado");
    digitalWrite (ventilador, LOW);
    
    temp = dht.readTemperature();
    
    //Mover el servo activar leds
    servo.write (180);
    delay (700);
    servo.write (0);
    delay (700);
    digitalWrite (ledB, HIGH);
    delay (3000);
    digitalWrite (ledA,LOW);
    delay(3000);
  }
}

void controlSensores(){

}