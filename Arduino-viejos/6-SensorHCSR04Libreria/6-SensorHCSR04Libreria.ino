// Sensor ultrasónico HC-SR04 con librería

#include <NewPing.h>

#define TRIGGER_PIN  12  // Pin del Arduino conectado al pin trigger del sensor ultrasónico.
#define ECHO_PIN     11  // Pin del Arduino conectado al pin echo del sensor ultrasónico.
#define MAX_DISTANCE 255 // Distancia máxima que queremos medir (en centímetros). La distancia máxima del sensor es de 400-500 cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Configuración de NewPing con los pines y la distancia máxima.

void setup() {
  Serial.begin(9600); // Abrir el monitor serial a 9600 baudios para ver los resultados del ping.
}

void loop() {
  delay(50);                     // Esperar 50 ms entre mediciones (aprox. 20 mediciones/seg). 29 ms es el menor tiempo recomendado entre mediciones.
  Serial.print("Distancia: ");
  Serial.print(sonar.ping_cm()); // Enviar ping, obtener distancia en cm e imprimir el resultado (0 = fuera del rango configurado)
  Serial.println("cm");
}