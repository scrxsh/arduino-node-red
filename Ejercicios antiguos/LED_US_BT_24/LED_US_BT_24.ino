
int Echo = 5; 
int Trigger = 6; 

double d;  
long t;  




void setup()
{
  Serial.begin(9600);  
  pinMode(Trigger, OUTPUT); 
  pinMode(Echo, INPUT); 
  //----------------------------------------------------
  pinMode(1,OUTPUT); 
  pinMode(2,OUTPUT);
 }


 

void loop()
{
  digitalWrite(Trigger, LOW);  
  delayMicroseconds(5); 
  digitalWrite(Trigger, HIGH);  
  delayMicroseconds(10);  

  t = (pulseIn(Echo, HIGH) / 2);  
  d = (t * 0.0343); 
  
  
  h = dht.readHumidity();//LECTURA HUMEDAD
  t = dht.readTemperature();//LECTURA TEMPERATURA
                                                                       
  Serial.println(d);  
  delay(500);   
  
  if(d>30)
  {
  digitalWrite (1, HIGH);
   }
  else 
  {
 digitalWrite (1, LOW);
   }
  
}
