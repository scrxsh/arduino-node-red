// Hola mundo en Arduino - Tip: PINES DIGITALES SOLO NUMERO, ANALOGICOS A junto al numero

void setup() {
  pinMode(5,OUTPUT); // Pin elegido #5 para el led

}

void loop ()
{
  digitalWrite(5,HIGH); // Encender el led
  delay(500); // Delay
  digitalWrite(5,LOW); // Apagar el led
  delay(500); // Delay
}


