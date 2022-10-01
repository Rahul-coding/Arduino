void setup() {
  pinMode(8, OUTPUT);
  pinMode(10,OUTPUT);
 
}

void loop() {
 digitalWrite(10, HIGH);
 digitalWrite(8,LOW);
 delay(300);
 digitalWrite(8, HIGH);
 digitalWrite(10,LOW);
 delay(300);
}
