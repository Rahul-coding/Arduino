int state;

void setup() {
  pinMode(2,INPUT);
  pinMode(4, OUTPUT);   
}

void loop() {
  state= digitalRead(2);
  if(state==HIGH)
  {
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

    digitalWrite (4, HIGH);
  }
  else 
  {
    digitalWrite (4, LOW);
    
  }
  
}
