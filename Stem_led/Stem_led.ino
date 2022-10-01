
void setup() {

  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {
digitalWrite(4,HIGH);
tone(3,1915,30);
delay(300);
tone(3,1432,30);
delay(300);
tone(3,1700,30);
delay(300);
tone(3,1519,30);
delay(300);
tone(3,1275,30);
delay(300);
tone(3,1432,30);
delay(500);
tone(3,1136,30);


}
