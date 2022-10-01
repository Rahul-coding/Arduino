/*******************Setup Loop***************************/
void setup() {                
  // The EL channels are on pins 2 through 9 on the ATMega328
  // Initialize the pins as outputs
  pinMode(2, OUTPUT);  // channel A  
  pinMode(3, OUTPUT);  // channel B   
  pinMode(5, OUTPUT);  // channel D    
  
//Uncomment the following line if using this on the EL Escudo Dos. 
 // Pin 10 is a status LED on the EL Escudo.  
  pinMode(10, OUTPUT);

//Pin 13 is the status LED on both the EL Sequencer and Arduino for use with the EL Escudo Dos. 
   pinMode(13, OUTPUT);    
}
/*******************Main Loop***************************/
void loop() 
{
 digitalWrite(2,HIGH);
 delay(1000);
 digitalWrite(2,LOW);
 digitalWrite(3,HIGH);
 delay(1000);
 digitalWrite(3,LOW);
 digitalWrite(5,HIGH);
 delay(1000);
 digitalWrite(5,LOW);


  }
