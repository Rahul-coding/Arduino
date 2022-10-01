#include <SPI.h>           // SPI library
#include <SdFat.h>         // SDFat Library
#include <SFEMP3Shield.h>  // Mp3 Shield Library





const int TK_WELCOME        = 1;
const int TK_CONGRATS        = 2;
const int TK_SOME           = 3;
const int TK_NONE           = 4;
const int TK_AGAIN          = 5;
const int TK_THANK          = 6;

const long DURATION = 15000;

//mp3 player 
SdFat sd; 
SFEMP3Shield MP3player; 
const uint8_t volume = 0; // MP3 Player volume 0=max, 255=lowest (off)
const uint16_t monoMode = 1;  // Mono setting 0=off, 3=max

//timer 
auto timer = timer_create_default(); // create a timer with default settings

void setup() 
{
 
  Serial.begin(115200);
  Serial.println("Welcome to music test");
 
  
  //init mp3
  initSD();
  initMP3Player();
}

void loop() {
  playTrack(TK_THANK);
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
