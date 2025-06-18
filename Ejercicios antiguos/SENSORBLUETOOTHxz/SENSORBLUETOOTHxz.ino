   #include <Servo.h>
Servo s1;
Servo s2;
//-------------------------------------------SENSOR BLUETOOTH HC-05----------------------------------------

int l1=2;
int l2=3;
int l3=4;
int l4=5;
int l5=6;
int l6=7;

int eb=0; //ESTADO INICIAL.

//---------------------------------------------------------------------------------------------------------

void setup (){
Serial.begin(9600);
pinMode (l1, OUTPUT);
pinMode (l2, OUTPUT);
s1.attach (8,600,1500);
s2.attach (9,600,1500);
}

//------------------------------------------------------------------------------------------------------------
void loop (){

if (Serial.available ()>0){
eb = Serial.read();
}

//CONDICIONALES ENCENDER Y APAGAR
switch (eb){

case 'a':
digitalWrite(l1,HIGH);
break;

case 'b':
digitalWrite(l1,LOW);
break;

case 'c':
digitalWrite(l2,HIGH);
break;

case 'd':
digitalWrite(l2,LOW);
break;

case 'e':
digitalWrite(l3,HIGH);
break;

case 'f':
digitalWrite(l3,LOW);
break;

case 'g':
digitalWrite(l4,HIGH);
break;

case 'h':
digitalWrite(l4,LOW);
break;

case 'i':
digitalWrite(l5,HIGH);
break;

case 'j':
digitalWrite(l5,LOW);
break;

case 'k':
digitalWrite(l6,HIGH);
break;

case 'l':
digitalWrite(l6,LOW);
break;

case 'm':
s1.write (180);
  delay (700);
  s1.write (90);
  delay (700);
  s1.write (180);
  delay (700);
break;

case 'n':
s1.write (0);
  delay (700);
  s1.write (90);
  delay (700);
  s1.write (180);
  delay (700);
break;

case 'o':
s1.write (180);
break;

case 'p':
s1.write (0);
break;

case 'q':
s2.write (180);
break;

case 'r':
s2.write (0);
break;

case 's':
s2.write (0);
  delay (700);
  s2.write (90);
  delay (700);
  s2.write (180);
  delay (700);
break;

case 't':
s2.write (180);
  delay (700);
  s2.write (90);
  delay (700);
  s2 .write (180);
  delay (700);
break;

}

}
