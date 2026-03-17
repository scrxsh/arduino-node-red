/*Sensor de gas metano, lectura de valor analogico, 
sirve para cualquiera de la linea MQ, en este caso es el MQ-7 que es el encargado para fugas de gas tipo cocina, mide monoxido de carbono y CO2 con valores mas estables que el sketch anterior*/


//Definir las  constantes para los pines y una alarma que puede ser un buzzer, ventilador, led, lo que sea digital
#define ANALOG_PIN A1
#define DIGITAL_PIN 10
#define ALARMA 11

//Limites de Gas y valor del Gas, para medidas estables
int limiteGas;
int valorGas;

void setup (){
  Serial.begin (9600);
  pinMode (DIGITAL_PIN, INPUT);  //Pin digital para medidas más estables
  pinMode (ALARMA,OUTPUT); //Alarma
}


void loop (){
  valorGas = analogRead(ANALOG_PIN);//Valor de CO2
  limiteGas = digitalRead(DIGITAL_PIN);//Limite del CO2 con el pin digital 

  Serial.println("CO: ");
  Serial.println (valorGas);
  delay (500);
  
  Serial.println ("El limite de CO tomado fue: ");
  Serial.println (limiteGas);
  delay (500);

  if (valorGas>600){
    digitalWrite (ALARMA, HIGH);
  } else {
    digitalWrite (ALARMA,LOW);
  }

}
