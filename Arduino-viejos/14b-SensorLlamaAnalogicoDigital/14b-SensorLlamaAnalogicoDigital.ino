// Sensor de fuego sensores de la linea MH que detectan fuego, son sensores similares al de gas, solo que estos se encargan del fuego

#define ANALOG_PIN A1 /* Definir el pin analogo*/ /*Analogo mide la radiciacion detectada del ambiente y en digital si hay o no fuego*/
#define DIGITAL_PIN 11
#define alarma 13 /*Definir cierta alerta para el fuego*/

int valorFuego = 0;
int estado;

void setup() {
  //Comunicación serial
  Serial.begin(9600);
  pinMode(DIGITAL_PIN, INPUT);
  pinMode(alarma, OUTPUT);
}

void loop() {

  valorFuego = analogRead(ANALOG_PIN); //Lectura del sensor valores de infrarrojo
  
  estado = !digitalRead(DIGITAL_PIN); //Lectura del estado
  Serial.println("El valor detectado de fuego es: ");
  Serial.println(valorFuego);
  delay(2000);


  if(estado == 1){
    digitalWrite(alarma, HIGH);
  } else {
    digitalWrite(alarma, LOW);
  }

}

