// Sensor de fuego sensores de la linea MH que detectan fuego, son sensores similares al de gas, solo que estos se encargan del fuego

#define ANALOG_PIN A1 /* Definir el pin analogo*/ /*Analogo mide la radiciacion detectada del ambiente y en digital si hay o no fuego*/
#define alarma 13 /*Definir cierta alerta para el fuego*/
int valorFuego = 0;


void setup() {
  //Comunicación serial
  Serial.begin(9600);
  pinMode(alarma, OUTPUT);
}

void loop() {

  valorFuego = analogRead(ANALOG_PIN); //Lectura del sensor
  Serial.println("El valor detectado de fuego es: ");
  Serial.println(valorFuego);
  delay(2000);

  //Generalmente si el valor se acerca a cero hay fuego
  if(valorFuego < 500){
    digitalWrite(alarma, 1);
  } else {
    digitalWrite(alarma, 0);
  }

}
