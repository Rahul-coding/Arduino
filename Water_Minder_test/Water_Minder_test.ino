#include <SPI.h>           // SPI library
#include <SdFat.h>         // SDFat Library
#include <SFEMP3Shield.h>  // Mp3 Shield Library

#include "HX711.h" // load cell

const int BUT_ON_OFF  = 5;

const int LED_RED     = 11;
const int LED_GREEN   = 10;

const int WT_CLK      = 3;
const int WT_DT       = 4;
const float WT_CALI_FACTOR = -3200000.0; //This value is obtained by using the SparkFun_HX711_Calibration sketch

const int ST_OFF          = 0;
const int ST_ON_NO_WATER  = 1;
const int ST_ON_WEIGHT    = 2;

const int TK_WELCOME        = 1;
const int TK_COGRATULATIONS = 2;
const int TK_SOME           = 3;
const int TK_NONE           = 4;
const int TK_AGAIN          = 5;
const int TK_THANK          = 6;


int curState;
// scale
HX711 scale;

//mp3 player 
SdFat sd; 
SFEMP3Shield MP3player; 
const uint8_t volume = 0; // MP3 Player volume 0=max, 255=lowest (off)
const uint16_t monoMode = 1;  // Mono setting 0=off, 3=max

void setup() 
{
  pinMode (BUT_ON_OFF, INPUT);  
  pinMode (LED_RED, OUTPUT);
  pinMode (LED_GREEN, OUTPUT);

  
  Serial.begin(115200);
  Serial.println("Welcome to water-minder");
  
  // init scale
  scale.begin(WT_DT, WT_CLK);
  scale.set_scale(WT_CALI_FACTOR); 
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0

  
  //init mp3
  initSD();
  initMP3Player();

  setStateNoWater();
}

void loop() {
    Serial.print("Current State:");
    Serial.println(curState);

    int state;
    state= digitalRead(BUT_ON_OFF);
    if(state==HIGH)
    {
      toggleState();
    }
    else
    {
      float weight = scale.get_units(10);
      Serial. print(" weight measured: ");
      Serial.print(weight);
      Serial.println(" lbs");
      continueState(weight);
    }
    delay(1000);
}

void setStateOff()
{
  curState = ST_OFF;
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, LOW);
  playTrack(TK_THANK);
  
}

void setStateNoWater()
{
  curState = ST_ON_NO_WATER;
  playTrack(TK_WELCOME);
  doBlink();
  
}

void setStateWater()
{
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN,HIGH);
}


void doBlink()
{
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN,HIGH);
  delay(300);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN,LOW);
}

void toggleState()
{
  if(curState == ST_OFF)
  {
    setStateNoWater();
  }
  else
  {
    setStateOff();
  }

}

void continueState(float weight)
{
  if (curState == ST_ON_NO_WATER)
  {
    doBlink();
  }
}

void playTrack(int track)
{
  // If another track is playing, stop it
  if (MP3player.isPlaying())
    MP3player.stopTrack();

  //Use the playTrack function to play a numbered track:
  uint8_t result = MP3player.playTrack(track);
  if (result == 0)  
  {
    Serial.print("playing track");
    Serial.println(track);
  }
  else 
  {
    Serial.print(" Error in initializing mp3 player:");
    Serial.println(result);
  }
}
// initSD() initializes the SD card and checks for an error.
void initSD()
{
  //Initialize the SdCard.
  if(!sd.begin(SD_SEL, SPI_HALF_SPEED)) 
    sd.initErrorHalt();
  if(!sd.chdir("/")) 
    sd.errorHalt("sd.chdir");
}

// initMP3Player() sets up all of the initialization for the
// MP3 Player Shield. It runs the begin() function, checks
// for errors, applies a patch if found, and sets the volume/
// stero mode.
void initMP3Player()
{
  uint8_t result = MP3player.begin(); // init the mp3 player shield
  if(result != 0) // check result, see readme for error codes.
  {
    Serial.print(" Error in initializing mp3 player:");
    Serial.println(result);
  }
  MP3player.setVolume(volume, volume);
  MP3player.setMonoMode(monoMode);
}
