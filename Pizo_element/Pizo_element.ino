void setup() {
pinMode (3, OUTPUT);
}

void loop() {
digitalWrite (3, HIGH);
delay (40);
digitalWrite (3, LOW);
delay (30);
digitalWrite (3, HIGH);
delay (10);
digitalWrite (3, LOW);
delay (100);
}
