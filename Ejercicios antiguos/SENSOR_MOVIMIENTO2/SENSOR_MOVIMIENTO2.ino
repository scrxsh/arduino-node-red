const int pinpir = 1;
int pirestado = 0;

void setup (){

pinMode (pinpir, INPUT);
Serial.begin(9600);

}

void loop (){

pirestado = digitalRead(pinpir);

if (pirestado == HIGH){
Serial.println ("MOVIMIENTO DETECTADO");
}
else {
}

Serial.println (pirestado);
delay (2000);
}
