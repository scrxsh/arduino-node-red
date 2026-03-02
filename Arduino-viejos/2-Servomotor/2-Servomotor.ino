//Hola mundo con el Servomotor de 180 gradps
//librerias
#include <Servo.h>
//Crear objetos
Servo servoA;

//Configurar el servomotor

void setup()
{
  servoA.attach (5);
}

void loop ()
{
  servoA.write (0);
  delay (700);
  servoA.write (90);
  delay (700);
  servoA.write (180);
  delay (700);
}