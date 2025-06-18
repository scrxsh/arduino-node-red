#include <Servo.h>

//-----------------------------------------------------------SENSOR DE GAS METANO II----------------------------------------------------------------------------------------//----------------------------------------------SENSOR DE GAS METANO MQ-7-------------------------------------

const int AOUTpin=0; //----puerto 0 analagico
const int DOUTpin=0; //puerto 8 digital
const int lp=1;
const int lp2=2;
const int vE=3;
Servo s1;
Servo s2;


//LIMITES Y VALOR.
int l;
int v;
//-----------------------------------------------------------------------------------------------------------------------------
void setup (){
Serial.begin (9600);
pinMode (DOUTpin, INPUT);//PIN DIGITAL COMO ENTRADA
pinMode (lp,OUTPUT);//LED
pinMode (lp2,OUTPUT);
pinMode (vE,OUTPUT);
s1.attach (4,600,1500);

}
//-------------------------------------------------------------------------------------------------------------------
void loop (){
v= analogRead(AOUTpin);//CONFIGURAR VALOR
l = digitalRead(DOUTpin);//CONFIGURAR VALOR
//IMPRESION DE PANTALLA
Serial.println("VALOR DE CO2:");
Serial.println (v);
delay (500);
//IMPRESION DE PANTALLA DEL LIMITE
Serial.println ("EL LIMITE TOMADO ES: ");
Serial.println (l);
delay (500);
//CONDICIONA IF 

if (v>385){
digitalWrite (lp2, LOW);
digitalWrite (vE, LOW);
digitalWrite (lp, HIGH);
s1.write (0);
}
else {
digitalWrite (lp, LOW);
digitalWrite (vE, HIGH);
digitalWrite (lp2, HIGH);
s1.write (180);
delay (700);
}

}
