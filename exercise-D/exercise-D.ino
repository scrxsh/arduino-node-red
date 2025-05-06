//Incluir la librería de JSON

#include <ArduinoJson.h>

//Variables de la alarma y del sensor PIR, digitales
#define LED_ALARMA 6
#define LED_INDICADOR 7
#define PINPIR 8

//Apagar de entrada el sensor PIR
int val_pir = 0;
//Configuracion

void setup() {
  // Inicalizar la calibracion del sensor en un minuto
  delay(60000);
  //Comunicacion swerial
  Serial.begin(9600);
  //Configuraciones de la salidas y entradas digitales
  pinMode(LED_ALARMA, OUTPUT);
  pinMode(PINPIR, INPUT);

  //Indicar si el sensor esta conectado
  pinMode(LED_INDICADOR, OUTPUT);
  digitalWrite(LED_INDICADOR, HIGH);
}

void loop() {
  //Tiempo de espera entre medidadas
  delay(4000);
  val_pir = digitalRead(PINPIR);

  if(val_pir == HIGH){
    StaticJsonDocument<200> doc;

    doc["pir"] = val_pir;
    doc["alarma"] = "Sensor PIR activo";

    serializeJsonPretty(doc, Serial);
    Serial.println();

    digitalWrite(LED_ALARMA, HIGH);
    delay(4000);
  }

  else
  {
    StaticJsonDocument<200> doc;

    doc["pir"] = val_pir;
    doc["alarma"] = "Sensor PIR inactivo";

    serializeJsonPretty(doc, Serial);
    Serial.println();

    
    digitalWrite(LED_ALARMA, LOW);
    delay(4000);
  }

/* 
-----------Documentacion de la calibración-----
****CON MULTIPLES DISPAROS*****
#PRUEBA 1 
TIEMPO ± 3 Segs
SENSIBILIDAD ± 3mts

En esta prueba el sensor es muy sensible y el rango es muy pequeño, lo cual hace que tenga bastantes interferencias con movimientos rapidos. Por otro lado detecta correctamente cuando no hay nadie cerca.

#PRUEBA 2
TIEMPO ± 3 Segs
SENSIBILIDAD un toque mas que 3mts 
*/

}
