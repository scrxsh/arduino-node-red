//------------------------------------------------------------ CODIGO SENSOR TEMPERATURA Y HUMEDAD------------------------------------------------------------------------------
//BIBLIOTECA SENSOR DE TEMPERATURA DTH11//

#include <DHT.h>
//VARIABLES CONST INT VENTILADOR Y SENSOR//

const int v=3;//VENTILADOR 1
const int st=A2;//SENSOR

//PINES DIGITALES SOLO NUMERO, ANALOGICOS A+NUMERO//

int t;//TEMPERATURA
int h;//HUMEDAD

DHT dht (st, DHT11);//ASIGNAR VARIABLES Y ASIGNAR SENSORES//

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
void setup ()
{
//VELOCIDAD DE TRANSFERENCIA 9600 J//
 Serial.begin(9600);
//CONFIGURAR VENTILADOR//
 pinMode (v, OUTPUT);
//ACTIVAR SENSOR DHT
 dht.begin();
 }
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
void loop ()
{
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------  
//ACTIVAR VARIBALES HUMEDAD Y TEMPERATURA
 h = dht.readHumidity();//LECTURA HUMEDAD
 t = dht.readTemperature();//LECTURA TEMPERATURA
 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//IMPRESION DE PANTALLA TEMPERATURA Y HUMEDAD
Serial.println("La temperatura es: ");
Serial.println(t);
Serial.println("La humedad es: ");
Serial.println(h);
Serial.println("%");

//TIEMPO DE LECTURA
delay (1000);
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

//BUCLE CON WHILE VENTILADOR CONDICION A X GRADOS
while (t>=25){
  Serial.println("ENCIENDE VENTILADOR");
  digitalWrite (v, HIGH);
  t = dht.readTemperature();
 }
digitalWrite (v, LOW);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------
