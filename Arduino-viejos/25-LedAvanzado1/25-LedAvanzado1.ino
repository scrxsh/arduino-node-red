// Definimos los pines de inicio y fin para no hacer muchas variables
const int pinInicio = 4;
const int pinFin = 9;


void setup() {
  // Ciclo para iniciar todos los puertos digitales como salida
  for (int i = pinInicio; i <= pinFin; i++ ){
      pinMode(i, OUTPUT);
  }
}

void loop() {
  // Secuencia 4 al 9
  for (int secuenciaAsc = pinInicio; secuenciaAsc <= pinFin; secuenciaAsc++){
    blinkPin(secuenciaAsc, 500);
  }
  // Secuencia 9 al 4
  for (int secuenciaDesc = pinFin; secuenciaDesc >= pinInicio; secuenciaDesc--){
    blinkPin(secuenciaDesc, 200);
  }
}

// Funcion para la secuencia de encender y apagar los leds con el delay correspondiente
void blinkPin(int pin, int tiempo){
    digitalWrite(pin, HIGH);
    delay(tiempo);
    digitalWrite(pin, LOW);
    delay(tiempo);
}

