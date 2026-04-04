//Sensor de Bluetooth - HC-O6 
//El sensor sus pines RX Y TX van cruzados con los de la placa Arduino, pines 0 y 1, igualmente con libreria se puede cambiar a otros pines

#define LedA 10
#define LedB 11

void setup (){
  Serial.begin(9600);
  pinMode(LedA, OUTPUT);
  pinMode(LedB, OUTPUT);
}

void loop (){
  //Comandos que recibe del sensor Bluetooth el dispositivo, en este caso son 4 condiciones que enviamos y alternas el estado de los dos leds
  int comando = 0;
  //Verificar si tenemos monitor serial, señal*
  if (Serial.available()){
    comando = Serial.read();
    Serial.print("Comando recibido: ");
    Serial.println(comando);
  }

  //Switch para hacer las condiciones
  switch (comando){

    case '1':
      digitalWrite(LedA, HIGH);
      break;

    case '2':
      digitalWrite(LedA, LOW);
      break;

    case '3':
      digitalWrite(LedB, HIGH);
      break;

    case '4':
      digitalWrite(LedB, LOW);
      break;
  }
}