void setup() {
  pinMode(3,OUTPUT);

}

void loop() {
 ruff();

 
}

void ruff() {   
  uint16_t i;
  for(i=890; i<910; i+=2) 
  {
    tone(3,i,3);           /// rrr     
    delay(3); 
    noTone(3);
  }
  tone(3,1664,150);     /// uuu   
  delay(150);
  noTone(3);
  tone(3,12200,70);     /// fff    
  delay(70);
  noTone(3);
}
 
void arf() {    // dog arf
  uint16_t i;
  tone(3,890,25);          // "a"    (short)
  delay(25);
  noTone(3);
  for(i=890; i<910; i+=2)    // "rrr"  (vary down)
  {
     tone(3,i,5);
     delay (5);
     noTone(3);
  }
  tone(3,4545,80);         // intermediate
  delay(80);
  noTone(3);
  
  tone(3,12200,70);        // "ff"   (shorter, hard to do)
  delay(70);
  noTone(3);
}
