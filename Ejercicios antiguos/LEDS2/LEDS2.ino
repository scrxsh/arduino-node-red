//--------------------------------------------------Encender y apagar diodos led---------------------

void setup ()// VARIABLE DE INICIALIZACION
{
  pinMode(10, OUTPUT);// pin 10 como salida
}

void loop ()
{
  digitalWrite(8,HIGH);//Pin 10 funcion prender (ciclo)
  delay(500);
  digitalWrite(8,LOW);//Pin 10 funcion apagar
  delay(200);
  digitalWrite(9,HIGH);//Pin 10 funcion prender (ciclo)
  delay(300);
  digitalWrite(9,LOW);//Pin 10 funcion apagar
  delay(300);
  digitalWrite(10,HIGH);//Pin 10 funcion prender (ciclo)
  delay(600);
  digitalWrite(10,LOW);//Pin 10 funcion apagar
  delay(100);
  digitalWrite(11,HIGH);//Pin 10 funcion prender (ciclo)
  delay(200);
  digitalWrite(11,LOW);//Pin 10 funcion apagar
  delay(500);
  digitalWrite(12,HIGH);//Pin 10 funcion prender (ciclo)
  delay(100);
   digitalWrite(12,LOW);//Pin 10 funcion apagar
  delay(600);
  digitalWrite(13,HIGH);//Pin 10 funcion prender (ciclo)
  delay(400);
  digitalWrite(13,LOW);//Pin 10 funcion apagar
  delay(300);
}
