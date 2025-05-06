#include <NewPing.h> 

#define TRIGGER_PIN  6  // Disparador (OUT) ~PWM
#define ECHO_PIN     7  // Receptor de información (IN)
#define MAX_DISTANCE 255 // Distancia maxima en CM
#define led 8 // Led indicador

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Instanciar metodo sonar de NewPing, que permite calcular la distancia del sensor

void setup() {
  Serial.begin(9600); // Protocolo de comunicación serial
  pinMode(led, OUTPUT); //Indicador del led
}

void loop() {
  
  delay(60); // Tiempo de espera entre señales en ms y calibración del sensor segun el DataSheet del HC-SR04

  int distanciaUltra = sonar.ping_cm();
  Serial.println(distanciaUltra); // Mostrar la distancia del ultrasonido en CM, en Node-Red se utilizara la libreria convert para transformar el valor a metros

  if(distanciaUltra == 0){ //Cicli IF que permite encender el led de acuerdo si encuentra un objeto el sensor
    digitalWrite(led, LOW);
    delay(500);
  }
  else{
    digitalWrite(led, HIGH);
    delay(500);
  }

}