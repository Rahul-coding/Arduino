const int C_PIN = 2;
const int D_PIN = 3;
const int E_PIN = 4;
const int F_PIN = 5;
const int G_PIN = 6;
const int A_PIN = 7;
const int B_PIN = 8;
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;
const int SOUND_PIN = 12;

const int C_TONE = 1915;
const int D_TONE = 1700;
const int E_TONE = 1519;
const int F_TONE = 1432;
const int G_TONE = 1275;
const int A_TONE = 1136;
const int B_TONE = 1014;

const int DELAY = 300;

void setup() 
{
 pinMode (C_PIN, INPUT);
 pinMode (D_PIN,INPUT); 
 pinMode (E_PIN, INPUT);
 pinMode (F_PIN, INPUT);
 pinMode (G_PIN, INPUT);
 pinMode (A_PIN, INPUT);
 pinMode (B_PIN, INPUT);
 pinMode (RED_PIN, OUTPUT);
 pinMode (GREEN_PIN, OUTPUT);
 pinMode (BLUE_PIN, OUTPUT);
 pinMode (SOUND_PIN, OUTPUT);

 Serial.begin(115200);
 //playC();
 //playD();
 //playE();
 //playF();
 //playG();
 //playA();
 //playB();
 
}



void loop()
{
  
  int state;
  
  state=digitalRead(C_PIN);
  if(state==HIGH) 
  {
    Serial.println ("C pressed");
    playC();
  }
  state=digitalRead(D_PIN);
  if(state==HIGH) 
  {
    Serial.println ("D pressed");
    playD();
  }

  state=digitalRead(E_PIN);
  if(state==HIGH) 
  {
    Serial.println ("E pressed");
    playE();
  }


  state=digitalRead(F_PIN);
  if(state==HIGH) 
  {
    Serial.println ("F pressed");
    playF();
  }


  state=digitalRead(G_PIN);
  if(state==HIGH) 
  {
    Serial.println ("G pressed");
    playG();
  }


  state=digitalRead(A_PIN);
  if(state==HIGH) 
  {
    Serial.println ("A pressed");
    playA();
  }


  state=digitalRead(B_PIN);
  if(state==HIGH) 
  {
    Serial.println ("B pressed");
    playB();
  }




}
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(SOUND_PIN, HIGH);
    delayMicroseconds(tone);
    digitalWrite(SOUND_PIN, LOW);
    delayMicroseconds(tone);
  }
}

void ledOff ()
{
 digitalWrite(RED_PIN,LOW);
 digitalWrite(BLUE_PIN,LOW);
 digitalWrite(GREEN_PIN,LOW);
}

void playC ()
{
 // red
  digitalWrite(RED_PIN,HIGH);
  digitalWrite(BLUE_PIN,LOW);
  digitalWrite(GREEN_PIN,LOW);
  playTone(C_TONE,DELAY);
  ledOff();
}


void playD ()
{
 // yellow
  digitalWrite(RED_PIN,HIGH);
  digitalWrite(BLUE_PIN,LOW);
  digitalWrite(GREEN_PIN,HIGH);
  playTone(D_TONE,DELAY);
  ledOff();
}


void playE ()
{
  // white
  digitalWrite(RED_PIN,HIGH);
  digitalWrite(BLUE_PIN,HIGH);
  digitalWrite(GREEN_PIN,HIGH);
  playTone(E_TONE,DELAY);
  ledOff();
}


void playF ()
{
  // purple
  digitalWrite(RED_PIN,HIGH);
  digitalWrite(BLUE_PIN,HIGH);
  digitalWrite(GREEN_PIN,LOW);
  playTone(F_TONE,DELAY);
  ledOff();
}


void playG ()
{
  //blue
  digitalWrite(RED_PIN,LOW);
  digitalWrite(BLUE_PIN,HIGH);
  digitalWrite(GREEN_PIN,LOW);
  playTone(G_TONE,DELAY);
  ledOff();
}


void playA ()
{
  // green
  digitalWrite(RED_PIN,LOW);
  digitalWrite(BLUE_PIN,LOW);
  digitalWrite(GREEN_PIN,HIGH);
  playTone(A_TONE,DELAY);
  ledOff();
}


void playB ()
{
  // cyan
  digitalWrite(RED_PIN,LOW);
  digitalWrite(BLUE_PIN,HIGH);
  digitalWrite(GREEN_PIN,HIGH);
  playTone(B_TONE,DELAY);
  ledOff();
}
