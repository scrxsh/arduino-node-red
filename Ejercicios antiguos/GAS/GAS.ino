
const int AOUTpin=0;
const int DOUTpin=2; 



int v;
//-----------------------------------------------------------------------------------------------------------------------------
void setup (){
Serial.begin (9600);
pinMode (DOUTpin, INPUT);
}
//-------------------------------------------------------------------------------------------------------------------
void loop (){
v= analogRead(AOUTpin);//CONFIGURAR VALOR
Serial.println (v);
delay (500);
}

