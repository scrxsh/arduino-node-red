#define led1 6

void setup() {
  pinMode(led1, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);  
  delay(50);       
  digitalWrite(led1, LOW);   
  delay(50);              
}
