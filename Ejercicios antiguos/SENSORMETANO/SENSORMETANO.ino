//----------------------------------------------SENSOR DE GAS METANO MQ-7-------------------------------------

const int AOUTpin=0; //----puerto 0 analagico
const int DOUTpin=8; //puerto 8 digital
const int lp=12;

//LIMITES Y VALOR.
int l;
int v;
//-----------------------------------------------------------------------------------------------------------------------------
void setup (){
Serial.begin (9600);
pinMode (DOUTpin, INPUT);//PIN DIGITAL COMO ENTRADA
pinMode (lp,OUTPUT);//LED
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

if (v>600){
digitalWrite (lp, HIGH);
}
else {
digitalWrite (lp,LOW);
}

}
