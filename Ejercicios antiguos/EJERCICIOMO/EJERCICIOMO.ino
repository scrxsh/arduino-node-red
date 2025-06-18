const int pinpir = 1;
int pirestado = 0;

void setup (){

pinMode (pinpir, INPUT);
Serial.begin(9600);

//------LEDS Y BUZZER

pinMode(2,OUTPUT); 
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);

}

void loop (){

pirestado = digitalRead(pinpir);

if (pirestado == HIGH){
Serial.println ("MOVIMIENTO DETECTADO");
digitalWrite(2,HIGH);
delay (500);
digitalWrite(3,LOW);
delay (500);
digitalWrite(4,LOW);
delay (500);
}
else {
}

Serial.println (pirestado);
delay (2000);
digitalWrite(2,LOW);
delay (500);
digitalWrite(3,HIGH);
delay (500);
digitalWrite(4,HIGH);
delay (500);
}
