
int LED_yellow  = 5 ;
int LED_green = 1;
int LED_blue = 3;

void setup() {
// etting up pins
  pinMode(LED_yellow,OUTPUT);
  pinMode(LED_green,OUTPUT);
  pinMode(LED_blue,OUTPUT);
  

}

void loop() 


  {
  // yellow LED blink
  
 digitalWrite(LED_yellow,HIGH);
 delay(500);
 digitalWrite(LED_yellow,LOW);
 delay(500);

 // green LED blink

 digitalWrite(LED_green,HIGH);
 delay(500);
 digitalWrite(LED_green,LOW);
 delay(500);

 // blue LED blink


digitalWrite(LED_blue,HIGH);
delay(500);
digitalWrite(LED_blue,LOW);
delay(500);
 
 




 

}
