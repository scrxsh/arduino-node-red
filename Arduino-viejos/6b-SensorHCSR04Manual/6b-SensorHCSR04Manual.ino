// Sensor ultrasonico HC - SR04 sin libreria, calibración manual
#define led 11
long distancia;
long tiempo;

void setup ()

{
  Serial.begin (9600); //Comunicación en el monitor serial en Baudios - Estandar (9600)
  pinMode (10, OUTPUT);//TRIGGER - Determinar entrada o salida (input and output)
  pinMode (9, INPUT);//ECHO
  pinMode (led, OUTPUT);//LED
}

void loop ()
{
  digitalWrite(10, LOW);
  delayMicroseconds (5);//Delay en microsegundos para calibrar
  digitalWrite(10, HIGH);
  delayMicroseconds (5);
  
  tiempo = pulseIn (9, HIGH);
  distancia = long(0.017*tiempo); 
  
  if(distancia>10){
    digitalWrite (led, HIGH);//CONDICIONAL DISTANCIA
  } else {
    digitalWrite (led,LOW);
  }

  Serial.println("La distancia detectada es: ");//Monitor serial
  Serial.println(distancia);
  Serial.println("cm");
  delay (500);
  
}
