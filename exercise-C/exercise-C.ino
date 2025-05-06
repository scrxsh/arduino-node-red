#include <ArduinoJson.h>
#include "DHT.h"

#define DHTPIN 8
#define DHTTYPE DHT11
#define LED_TEMP 7
#define LED_HUM 6

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED_TEMP, OUTPUT);
  pinMode(LED_HUM, OUTPUT);
}

void loop() {
  delay(2000); //Frecuencia de 0.5hz ~ f=1/t
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();

  StaticJsonDocument<200> doc;

  doc["Humedad"] = humidity;
  doc["Temperatura"] = temp;
  doc["id"] = "DHT11";
  doc["latitud"] = 5.619454609357036;
  doc["longitud"] = -73.81699785629826;
;
  serializeJsonPretty(doc, Serial);
  /*
  {
    "humedad": float, 
    "temperatura": float,
    "id": str,

  }*/

//Inicializar los leds en 0 o apagadp
  digitalWrite(LED_TEMP, LOW);
  digitalWrite(LED_HUM, LOW);

//Condiciones despues de inicializar los leds apagados, para que no pasen cosas raras
  if(temp > 30 ){
    digitalWrite(LED_TEMP, HIGH);
  }
  if(humidity > 50){
    digitalWrite(LED_HUM, HIGH);
  }
  
  Serial.println();

}
