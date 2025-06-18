#include <DHT.h>

const int st=A0;

int Echo = 5; 
int Trigger = 6; 

double d;  
long t;  

int temp;//TEMPERATURA
int hum;//HUMEDAD

DHT dht (st, DHT11);//ASIGNAR VARIABLES Y ASIGNAR SENSORES//


void setup()
{
  Serial.begin(9600);  
  pinMode(Trigger, OUTPUT); 
  pinMode(Echo, INPUT); 
  dht.begin();
 }


 

void loop()
{
  digitalWrite(Trigger, LOW);  
  delayMicroseconds(5); 
  digitalWrite(Trigger, HIGH);  
  delayMicroseconds(10);  

  t = (pulseIn(Echo, HIGH) / 2);  
  d = (t * 0.0343); 
  
 hum = dht.readHumidity();
 temp = dht.readTemperature();
                                                                                       
  
  Serial.println(d);  
  delay(500); 
  Serial.println(temp);  
  delay(500); 
  Serial.println(hum);  
  delay(500); 
  
}
