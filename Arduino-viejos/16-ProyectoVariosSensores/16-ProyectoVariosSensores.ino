#include <Servo.h>
#include <NewPing.h>
#include "DHT.h"

//Hacerlo despues con APPInventor + Bluetooth
//Servo
Servo servoA;
Servo servoB;
int pos = 0;
//Sensor ultrasonico
#define TRIGGER_PIN  3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     2  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 255
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int distancia;

//Sensor de temperatura y humedad DHT11
#define DHTPIN 4
DHT dht(DHTPIN, DHT11); //Instanciar el DHT11
int temp;
int humedad;

//Sensor PIR
#define PINPIR 5
int estadoPir = 0;

//Leds y ventiladores
#define led1 6
#define led2 7
#define led3 8
#define ventilador 9
#define chicharra 10


void setup() {
  Serial.begin(9600);//Monitor serial
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (ventilador, OUTPUT);
  pinMode(chicharra, OUTPUT);

  //Los sensores y los servos
  servoA.attach (11);
  servoB.attach (12);
  dht.begin();
  pinMode(estadoPir, INPUT);

}

void loop() {

  //Humedad y temperatura lecturas
  humedad = dht.readHumidity();

  distancia = sonar.ping_cm();

  temp = dht.readTemperature();

  estadoPir = digitalRead(PINPIR);


  delay(2000);
  Serial.println("");
  Serial.print("Distancia: ");
  Serial.print(distancia); // Enviar ping, obtener distancia en cm e imprimir el resultado (0 = fuera del rango configurado)
  Serial.println("cm");

  //Monitor serial de Temperatura/Humedad
  Serial.print("Temperatura: ");
  Serial.print(temp); // Enviar ping, obtener distancia en cm e imprimir el resultado (0 = fuera del rango configurado)
  Serial.println("°C");
  Serial.print("Humedad: ");
  Serial.print(humedad); // Enviar ping, obtener distancia en cm e imprimir el resultado (0 = fuera del rango configurado)
  Serial.println("%");
  Serial.print("PIR: ");
  Serial.print(estadoPir); // Enviar ping, obtener distancia en cm e imprimir el resultado (0 = fuera del rango configurado)

  //Monitor serial del PIR
  if (estadoPir == 1 && temp >= 30 && distancia >= 70){
  
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servoA.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
    }

    for (pos = 0; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees
      servoB.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
    }

    digitalWrite(ventilador, HIGH);
    digitalWrite(chicharra, HIGH);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);

  } else if (estadoPir == 1 && temp >= 25 && distancia >= 50){
    
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      servoB.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
    }

    for (pos = 0; pos <= 180; pos += 1) { // goes from 180 degrees to 0 degrees
      servoA.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
    }

    digitalWrite(ventilador, LOW);
    digitalWrite(chicharra, HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3,LOW);
  } else {
    servoA.write(0);
    servoB.write(0);
    digitalWrite(ventilador, LOW);
    digitalWrite(chicharra, LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3,HIGH);
  }




}
