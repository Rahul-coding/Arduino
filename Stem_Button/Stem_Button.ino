int state;

void setup() {
  pinMode(4,INPUT);
  pinMode(3, OUTPUT);   
}

void loop() {
  state= digitalRead(4);
  if(state==HIGH)
  {
    digitalWrite (3, HIGH);
  }
  else 
  {
    digitalWrite (3, LOW);
    
  }
  
}
