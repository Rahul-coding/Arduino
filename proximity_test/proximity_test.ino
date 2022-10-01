 #include <SPI.h>

//Add the SdFat Libraries
#include <SdFat.h>
#include <FreeStack.h>

//and the MP3 Shield Library
#include <SFEMP3Shield.h>

// Below is not needed if interrupt driven. Safe to remove if not using.
#if defined(USE_MP3_REFILL_MEANS) && USE_MP3_REFILL_MEANS == USE_MP3_Timer1
  #include <TimerOne.h>
#elif defined(USE_MP3_REFILL_MEANS) && USE_MP3_REFILL_MEANS == USE_MP3_SimpleTimer
  #include <SimpleTimer.h>
#endif



#define PIR_AOUT A0  // PIR analog output on A0
#define PIR_DOUT 2   // PIR digital output on D2
#define LED_PIN  3  // LED to illuminate on motion
#define LED_GREEN 1
#define LED_BLUE 5

#define PRINT_TIME 200 // Rate of serial printouts
unsigned long lastPrint = 0; // Keep track of last serial out




SdFat sd;
SFEMP3Shield MP3player;
uint8_t result; //result code from some function as to be tested at later time.

void setup() 
{
  Serial.begin(115200);  // Serial is used to view Analog out
  // Analog and digital pins should both be set as inputs:
  pinMode(PIR_AOUT, INPUT);
  pinMode(PIR_DOUT, INPUT);
  pinMode(10,OUTPUT);
 

  // Configure the motion indicator LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Turn the LED off
  digitalWrite(LED_GREEN,LOW);
  digitalWrite(LED_BLUE,LOW);

  //Initialize the SdCard.
  if(!sd.begin(SD_SEL, SPI_FULL_SPEED)) sd.initErrorHalt();
  // depending upon your SdCard environment, SPI_HAVE_SPEED may work better.
  if(!sd.chdir("/")) sd.errorHalt("sd.chdir");

  //Initialize the MP3 Player Shield
  result = MP3player.begin();
  //check result, see readme for error codes.
 

}

void loop() 
{
  // Read OUT pin, and set onboard LED to mirror output
  readDigitalValue(); 

  // Read A pin, print that value to serial port:
  printAnalogValue();
}

void readDigitalValue()
{
  // The OpenPIR's digital output is active high
  int motionStatus = digitalRead(PIR_DOUT);

  // If motion is detected, turn the onboard LED on:
  if (motionStatus == HIGH)
    digitalWrite(10, HIGH);
  else // Otherwise turn the LED off:
    digitalWrite(10, LOW);
}

void printAnalogValue()
{
  if ( (lastPrint + PRINT_TIME) < millis() )
  {
    lastPrint = millis();
    // Read in analog value:
    unsigned int analogPIR = analogRead(PIR_AOUT);
    // Convert 10-bit analog value to a voltage
    // (Assume high voltage is 5.0V.)
    float voltage = (float) analogPIR / 1024.0 * 5.0;
    // Print the reading from the digital pin.
    // Mutliply by 5 to maintain scale with AOUT. 
    Serial.print(5*digitalRead(PIR_DOUT));
    Serial.print(',');    // Print a comma
    Serial.print(2.5);    // Print the upper limit
    Serial.print(',');    // Print a comma
    Serial.print(1.7);    // Print the lower limit
    Serial.print(',');    // Print a comma
    Serial.print(voltage); // Print voltage
    Serial.println();
  if(digitalRead(PIR_AOUT)== 1)
  {
    digitalWrite(10,HIGH);
    delay(1000);
    digitalWrite(10,LOW);
    MP3player.playTrack(4);
  }
  else if(digitalRead(PIR_AOUT)==0)
  {
    digitalWrite(10,LOW); 
  }
    
     }    
  
}
