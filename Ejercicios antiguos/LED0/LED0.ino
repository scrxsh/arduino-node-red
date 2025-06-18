//Codigo de programacion servomotor :u
//librerias


void setup()
{

 pinMode(1,OUTPUT); 
 pinMode(2,OUTPUT);
 }

void loop ()
{
digitalWrite(1,HIGH);
delay(200);
digitalWrite(1,LOW);
delay(200);
}
