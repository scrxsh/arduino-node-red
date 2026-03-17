//Sensor de gas metano, lectura de valor analogico, sirve para cualquiera de la linea MQ, en este caso es el MQ-7 que es el encargado para fugas de gas tipo cocina, mide monoxido de carbono y CO2.

#define ANALOG_PIN A1
float valorGas;


void setup (){
  Serial.begin (9600);
}

void loop (){
  valorGas= analogRead(ANALOG_PIN);//Obtener datos del gas
  Serial.println ("El valor de gas es: ");
  Serial.println(valorGas);
  delay(1000);
}

