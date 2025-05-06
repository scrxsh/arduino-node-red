#include <ArduinoJson.h>
#include <NewPing.h>
#include "DHT.h"
#include <Servo.h>
#include <TimeLib.h>

//Sensor ultrasonico 
#define TRIGGER_PIN  9  // Disparador (OUT) ~PWM
#define ECHO_PIN     8  // Receptor de información (IN)
#define MAX_DISTANCE 255 // Distancia maxima en CM
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); //Instanciar metodo sonar de NewPing, que permite calcular la distancia del sensor ultrasonido

//Temperatura y humedad
#define DHTTYPE DHT11 //Definir el tipo de sensor.
#define DHTPIN 10 //Definir el pin digital del sensor DHT11.
DHT dht(DHTPIN, DHTTYPE); //Instanciar el objeto del sensor para trabajar con este.

//PIR
#define PINPIR 11 //Definir el pin digital del sensor PIR.
int val_pir = 0; //Valor inicial del PIR

//Servomotor
#define SERVO_PIN 6
Servo myservo; //Objeto del servo para trabajar con este.
int posServo = 0; //posición de apertura del servo en 0 grados

//Definir variables para trabajar con los delays
unsigned long tiempoInicialUltrasonido = 0, tiempoInicialDHT = 0, tiempoInicialPIR = 0, tiempoInicialJSON = 0, tiempoActual = 0;
unsigned long delayUltrasonido = 60, delayDHT = 2000, delayPIR = 4000, delayJSON = 6000;

//Variables para la información
int distanciaUltra = 0;
float humidity = 0;
float temperature = 0;
String estadoServo = "Inactivo";

void setup() {
  Serial.begin(9600); // Protocolo de comunicación serial
  dht.begin(); //Inicializar el dht11

  pinMode(PINPIR, INPUT); //Inicializar el PIR
  Serial.println("Calibrando sensor PIR....");
  delay(60000);//Calibración del PIR
  Serial.println("Fin de calibración PIR");

  myservo.attach(SERVO_PIN); //Iniciar el pin del servo
  setTime(13, 12, 24, 21, 4, 2025); //Definir una fecha simulada (horas, minutos, segundos, dia, mes, año)
}

void loop() {
  tiempoActual=millis();
  lecturaUltrasonido();
  lecturaControlPIR();
  lecturaDHT();
  enviarJSON();
}

void lecturaUltrasonido(){
    if(tiempoActual - tiempoInicialUltrasonido >= delayUltrasonido){ // Se le resta el tiempo actual cuando el delay sea mayor o igual al 60milisegundos (delay ultrasonido)
      tiempoInicialUltrasonido = tiempoActual; //Guarda el tiempo del ultrasonido en la variable actual
      distanciaUltra = sonar.ping_cm();
    }
}

void lecturaDHT(){
    if(tiempoActual - tiempoInicialDHT >= delayDHT){ // Se le resta el tiempo actual cuando el delay sea mayor o igual a 2000 (delay DHT11)
      tiempoInicialDHT = tiempoActual; //Guarda el tiempo del DHT11 en la variable actual
      humidity = dht.readHumidity();
      temperature = dht.readTemperature();
    }
}

void lecturaControlPIR(){
    if(tiempoActual - tiempoInicialPIR >= delayPIR){ // Se le resta el tiempo actual cuando el delay sea mayor o igual a 4000 (delay PIR)
      tiempoInicialPIR = tiempoActual; //Guarda el tiempo del PIR en la variable actual
      val_pir = digitalRead(PINPIR);
      
        if(val_pir == HIGH){ //Control del servomotor
          posServo = 180;
          myservo.write(posServo);
          estadoServo = "Activo";                
        } 
        else{
          posServo = 0;
          myservo.write(posServo);
          estadoServo = "Inactivo";
        }
    }
}

String obtenerFecha(){
  time_t T = now();// Captura la fecha y hora del computador
  int d = day(T);
  int m = month(T);
  int y = year(T);
  int hr = hour(T);
  int minu = minute(T);
  int seg = second(T);

  String Fecha = String(y)+"-"+String(m)+"-"+String(d) + " ";
  String Hora = String(hr)+":"+String(minu)+":"+String(seg);
  String fechaCompleta = Fecha + Hora;
  return fechaCompleta;
}
     
void enviarJSON(){
    if(tiempoActual - tiempoInicialJSON >= delayJSON){ // Se le resta el tiempo actual cuando el delay sea mayor o igual a 3000 (delay JSON)
      tiempoInicialJSON = tiempoActual; //Guarda el tiempo del JSON en la variable actual
      StaticJsonDocument<400> doc;

      JsonObject sistema_monitoreo =  doc["sistema_monitoreo"].to<JsonObject>();
      JsonArray sensores = sistema_monitoreo["sensores"].to<JsonArray>();
      JsonArray actuadores = sistema_monitoreo["actuadores"].to<JsonArray>();
      
      //Objetos creados para sus JSONs, Sensores/Actuadores correspondientes
      JsonObject ultrasonido = sensores.add<JsonObject>(); //Se agrega el JSON para el ultrasonido
      ultrasonido["nombre"] = "Sensor Ultrasonico";
      ultrasonido["referencia"] = "HC-SR04";
      ultrasonido["tipo"] = "Digital";
      ultrasonido["distancia"] = distanciaUltra; //Valores del sensor

      JsonObject dht11 = sensores.add<JsonObject>(); //Se agrega el JSON para el dht11
      dht11["nombre"] = "Sensor de temperatura y humedad";
      dht11["referencia"] = "DHT11";
      dht11["tipo"] = "Digital";
      JsonObject datosObtenidosDHT11 =  dht11["datos_obtenidos"].to<JsonObject>(); //Valores del sensor
      datosObtenidosDHT11["temperatura"] = temperature;
      datosObtenidosDHT11["humedad"] = humidity;

      JsonObject pir = sensores.add<JsonObject>(); //Se agrega el JSON para el ultrasonido
      pir["nombre"] = "Sensor Piroelectrico";
      pir["referencia"] = "PIR HC-SR501";
      pir["tipo"] = "Digital";
      pir["estado"] = val_pir;//Valores del sensor

      JsonObject servomotorA = actuadores.add<JsonObject>(); //Se agrega el JSON para el servomotor
      servomotorA["nombre"] = "Servomotor de puerta";
      servomotorA["referencia"] = "SG90";
      servomotorA["angulo_giro"] = posServo;
      servomotorA["estado"] = estadoServo;/**/

      sistema_monitoreo["fecha"] = obtenerFecha(); //Agregando fecha
      serializeJson(doc, Serial);
      Serial.println();
  }
}