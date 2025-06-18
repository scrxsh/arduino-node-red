//Codigo de programacion servomotor :u
//librerias
#include <Servo.h>
//Crear objetos
Servo servo1;

//Configurar el servomotor

void setup()
{
 servo1.attach (5,600,1500);
 
}

void loop ()
{
  servo1.write (0);
  delay (700);
  servo1.write (90);
  delay (700);
  servo1.write (180);
  delay (700);
}
