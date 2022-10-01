int state;

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode (3, OUTPUT);
  pinMode(9,INPUT);
}

void loop()
{
  state=digitalRead(9);
  if(state==LOW)
  {
    digitalWrite(10, HIGH);
    digitalWrite(8,LOW);
    tone(3,100,300);
    delay(300);
    noTone(3);
    digitalWrite(8, HIGH);
    digitalWrite(10,LOW);
    tone(3,250,300);
    delay(300);
    noTone(3);
  }
  else 
  {
   digitalWrite(8,LOW);
   digitalWrite(10,LOW);
   noTone(3);
  } 
} 
