// Sensor DHT11 Libreria DHT11 de adaferuit - Temperatura y Humedad con un ventilador (buzzer, led o lo que sea)

#include "DHT.h"

#define controlTemp 11
#define DHTPIN 10//Pin del sensor segun la libreria

int temp;
int humedad;

DHT dht (DHTPIN, DHT11);//Instanciar el pin y el tipo de sensor

void setup ()
{
  Serial.begin(9600);
  pinMode (controlTemp, OUTPUT);
  dht.begin(); //Iniciar el sensor dht definido antes
}

void loop ()
{
  humedad = dht.readHumidity();//LECTURA HUMEDAD
  temp = dht.readTemperature();//LECTURA TEMPERATURA

  //Valores de la temperatura y humedad
  Serial.println("La temperatura es: ");
  Serial.println(temp);
  Serial.println("La humedad es: ");
  Serial.println(humedad);
  Serial.println("%");

  delay (1000);

//Encender el control de temperatura con un ciclo while cuando supere los 25 grados de temperatura
  while (temp>=25){
    Serial.println("ENCIENDE EL VENTILADOR");
    digitalWrite (controlTemp, HIGH);
    temp = dht.readTemperature();
  }
  
  digitalWrite (controlTemp, LOW);
}
