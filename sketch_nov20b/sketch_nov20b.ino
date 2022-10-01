int state;

void setup() {
  pinMode(3,INPUT);
  pinMode(2, OUTPUT);   
}

void loop() {
  state= digitalRead(3);
  if(state==HIGH)
  {
    digitalWrite (2, HIGH);
  }
  else 
  {
    digitalWrite (2, LOW);
    
  }
  
}
