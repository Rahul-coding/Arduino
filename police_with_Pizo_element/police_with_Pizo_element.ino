void setup() {
 pinMode(8, OUTPUT);
// pinMode(10,OUTPUT);
//pinMode (3, OUTPUT);
 }

void loop() {
 //digitalWrite(10, HIGH);
 //digitalWrite(8,LOW);
 tone(3,500,300);
 delay(300);
 noTone(3);
 //digitalWrite(8, HIGH);
 //digitalWrite(10,LOW);
 tone(3,250,300);
 delay(300);
 noTone(3);
}
