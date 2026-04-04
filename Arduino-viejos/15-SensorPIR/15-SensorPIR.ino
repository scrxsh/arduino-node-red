//Sensor de Movimiento PIR - Sensor el cual detecta movimiento con infrarrojo - Se debe calibrar manualmente
#define PINPIR 5
#define LED_MOVIMIENTO 6
#define LED_NORMAL 7



void setup() {
  // Inicializar como entrada el pin del PIR
  Serial.begin(9600);
  pinMode(PINPIR, INPUT);
  pinMode(LED_MOVIMIENTO, OUTPUT);
  pinMode(LED_NORMAL, OUTPUT);
}

void loop() {
  //Guardar el estado del PIN
  int valPir = 0;

  valPir = digitalRead(PINPIR);

  //Si hay movimiento se prende un led y se apaga el otro y viceversa
  if(valPir == HIGH){
    digitalWrite(LED_MOVIMIENTO, HIGH);
    digitalWrite(LED_NORMAL, LOW);
  } else {
    digitalWrite(LED_MOVIMIENTO, LOW);
    digitalWrite(LED_NORMAL, HIGH);
  }

  delay(2000);
  Serial.print("Estado del PIR: ");
  Serial.println(valPir);
}
