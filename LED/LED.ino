void setup() {
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);

}

void loop() {
  flash();

}

void flash(){
  digitalWrite(11,HIGH);
  digitalWrite(2,HIGH);
  delay(100);
  digitalWrite(12,HIGH);
  digitalWrite(3,HIGH);
  delay(100);
  digitalWrite(13,HIGH);
  digitalWrite(4,HIGH);
  delay(100);
  digitalWrite(11,LOW);
  digitalWrite(2,LOW);
  delay(100);
  digitalWrite(12,LOW);
  digitalWrite(3,LOW);
  delay(100);
  digitalWrite(13,LOW);
  digitalWrite(4,LOW);
  delay(100);
  
}
