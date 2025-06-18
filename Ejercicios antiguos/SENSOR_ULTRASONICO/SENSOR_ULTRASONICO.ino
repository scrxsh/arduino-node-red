//-----------------------------------sensor 

long d;
long t;
int led1 = 11;


void setup ()

{
 //--------comunicacion serial pc y arduino y velocidad----------------
  Serial.begin (9600); 
  //-----------determinar entrada o salida (input and output)-------------------
  pinMode (10, OUTPUT);//TRIGGER  
  pinMode (9, INPUT);//ECHO
  pinMode (11, OUTPUT);//LED
}

void loop ()
{
  digitalWrite(10, LOW);
  delayMicroseconds (5);//delay microsegundos
  digitalWrite(10, HIGH);
  delayMicroseconds (10);
  
  t = pulseIn (9, HIGH); //VARIABLE TIEMPO
  d = long(0.017*t); //VARIABBLE DISTANCIA
  
  if(d>10){
  digitalWrite (11, HIGH);//CONDICIONAL DISTANCIA
  }
  
  else 
  {
    digitalWrite (11,LOW);
  }
 
 
 Serial.println("La distancia detectada es: ");//IMPRESION DE PANTALLA
 Serial.println(d);
 Serial.println("cm");
 delay (500);
 
 
 
  
}
