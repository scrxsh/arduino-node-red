//Sensor ultrasonico o de fuego
//variable sensor e igualarla

int sf=0;
int v1= 1;
//-----------------------------------------------------------------------------------------------------------------------------------------------------

void setup (){
  
  Serial.begin (9600);
  pinMode (v1, OUTPUT);
}

void loop (){
//-------------------------------------leer sensor---------------------------------------------------------------------------------------------
sf = analogRead(A0); //Definir variable en el puerto analogico
Serial.println("el valor detectado es:");//Impresion de pnatalla
Serial.println(sf);
//-----------------------activar alarma-------------------------------------------------------------------------------------------------------------
if (sf<500){
digitalWrite (v1, HIGH);
delay (100);
}

else{
digitalWrite (v1, LOW);
delay (50);
}

}

