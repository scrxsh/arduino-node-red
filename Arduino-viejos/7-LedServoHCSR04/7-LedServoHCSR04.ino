// Ejercicio con Leds, Servo y Sensor HCSR04 - Calibracion Manual 
#include <Servo.h>


#define ledA 5 /* Definir los leds y el sensor como constantes que no gastan RAM, const int o #define, no usar variables innecesarias*/
#define ledB 6
#define TRIGGER_PIN 12 /* Preferiblemente ~PWM*/
#define ECHO_PIN 11

Servo servo; /* Servo */

long distancia;
long tiempo;

void setup ()
{
    Serial.begin (9600); 

    pinMode(ledA,OUTPUT); 
    pinMode(ledB,OUTPUT);

    servo.attach (7);
    pinMode (TRIGGER_PIN, OUTPUT);//TRIGGER  
    pinMode (ECHO_PIN, INPUT);//ECHO
}

void loop ()
{
    digitalWrite(5, LOW); // Calibración del sensor
    delayMicroseconds (5);
    digitalWrite(5, HIGH);
    delayMicroseconds (5);


    tiempo = pulseIn (ECHO_PIN, HIGH);
    distancia = long(0.017*tiempo); 
  
  //Condiciones
  if(distancia<40){
    digitalWrite (ledA, HIGH);
    delay(3000);
  }

  if(distancia<20){
    servo.write(5);
    delay (3000);
  }
  
  if(distancia>20){
    servo.write (90);
    delay (3000);
    digitalWrite (ledB, HIGH);
    delay (3000);
  }
  
  if(distancia>40){
    digitalWrite (ledA, LOW);
    delay (5000);
  }

  //Monitor serial
  Serial.println("La distancia detectada es: ");
  Serial.println(distancia);
  Serial.println("cm");
  delay (500);
  
}
