int state;
void setup() {
 pinMode(2,INPUT);
 pinMode(4,OUTPUT);
 Serial.begin(115200);
}

void loop(){
  state=digitalRead(2);
  if(state==LOW){
    Serial.println("button pressed");
    digitalWrite(4,HIGH);
  
  } 
  else{
    Serial.println("button not pressed");
    digitalWrite(4,LOW);
  }
  }
