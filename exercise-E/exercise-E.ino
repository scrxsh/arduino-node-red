//Incluir la librería de JSON
#include <ArduinoJson.h>
//Incluir libreria de Servo.h
#include <Servo.h>

//Variables de la alarma, del sensor PIR, y del servomotor
#define LED_ALARMA 13
#define PINPIR 8
#define SERVO_PIN 6

Servo myservo;  //Creacion del objeto del codigo
//Apagar de entrada el sensor PIR
int val_pir = 0;
int pos = 0; //Posición de apertura del servo en 0 grados
//Configuracion

void setup() {
  // Inicalizar la calibracion del sensor en un minuto
  delay(60000);
  //Comunicacion swerial
  Serial.begin(9600);
  //Configuraciones de la salidas y entradas digitales
  pinMode(LED_ALARMA, OUTPUT);
  pinMode(PINPIR, INPUT);
  myservo.attach(SERVO_PIN);  // Elegir el PIN DIGITAL DEL SERVO
}

void loop() {
  //Tiempo de espera entre medidadas
  
  val_pir = digitalRead(PINPIR);

  if(val_pir == HIGH){
    
    digitalWrite(LED_ALARMA, HIGH);
    delay(4000);

    StaticJsonDocument<200> doc;

    doc["pir"] = val_pir;
    doc["alarma"] = "Sensor PIR activo";
    doc["estado_puerta"] = "Puerta abierta";

    serializeJsonPretty(doc, Serial);
    Serial.println();
    //-------------------------------------------Apertura de puerta
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }



    delay(5000); //Delay de 5 segundos

    //--------------------------------------Cierre de puerta
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }

  }

  else
  {
    StaticJsonDocument<200> doc;

    doc["pir"] = val_pir;
    doc["alarma"] = "Sensor PIR inactivo";
    doc["estado_puerta"] = "Puerta cerrada"; 

    serializeJsonPretty(doc, Serial);
    Serial.println();

    
    digitalWrite(LED_ALARMA, LOW);
    delay(4000);
  }

}
