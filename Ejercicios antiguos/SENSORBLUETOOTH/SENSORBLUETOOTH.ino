//-------------------------------------------SENSOR BLUETOOTH HC-05----------------------------------------

int l1=2;
int l2=3;

int eb=0; //ESTADO INICIAL.

//---------------------------------------------------------------------------------------------------------

void setup (){
Serial.begin(9600);
pinMode (l1, OUTPUT);
pinMode (l2, OUTPUT);

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
}

}
