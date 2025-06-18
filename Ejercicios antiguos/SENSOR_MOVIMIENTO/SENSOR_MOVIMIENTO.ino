//-------------------SENSOR DE MOVIMIENTO----------------------------------------------------------------------------
int l1 = 2;
int s = 1;
int es = LOW; //ESTADO DEL SENSOR SIEMPRE APAGADO
int v = 0;
//---------------------------------------------------------------------------------------------------------------------

void setup (){

pinMode (l1,OUTPUT);
pinMode (s,INPUT); //---------------------CONFIGURACION SENSOR ENTRADA----------------------------------------------
Serial.begin(9600);
}

//--------------------------------------------------------------------------------------------------------------------

void loop (){
v = digitalRead (s); //TOMAR DATOS DEL SENSOR INICIALMENTE

//-------------------------------------CONDICION IF Y ELSE-----------------------------------------------------------------
if (v == HIGH){  
digitalWrite (l1,HIGH);//CONDICION TRAS ENCENDER SENSOR
delay (200);

if (es == HIGH){
Serial.println("MOVIMIENTO DETECTADO");
es = HIGH;
}
}


else {
digitalWrite (l1 == LOW);
delay (200);

if (es, LOW)
Serial.println("¡NO SE DETECTA MOVIMIENTO");
es = LOW;
}
}

