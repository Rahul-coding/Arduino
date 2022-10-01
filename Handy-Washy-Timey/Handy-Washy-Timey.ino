int state;
//pins
const int PIEZO = 3;
const int BUTTON = 2;
const int LED = 4; 

//delays
const int PIEZO_TIME = 200;
const int TONE_DURATION = 30;

//tones
const int C_TONE = 1915;
const int D_TONE = 1700;
const int E_TONE = 1519;
const int F_TONE = 1432;
const int G_TONE = 1275;
const int A_TONE = 1136;
const int B_TONE = 1014;


void setup() {
  pinMode(PIEZO,OUTPUT);
  pinMode(BUTTON,INPUT);
  pinMode(LED,OUTPUT);
  startup();

  Serial.begin(115200);

}

void loop() {
  state=digitalRead(BUTTON);
  if(state==LOW){
    Serial.println("button pressed");
    washHands20Sec();
  }

}

void startup(){
  tone(PIEZO,D_TONE,PIEZO_TIME);
  digitalWrite(LED,HIGH);
  delay(PIEZO_TIME);
  
  tone(PIEZO,C_TONE,PIEZO_TIME);
  digitalWrite(LED,LOW);
  delay(PIEZO_TIME);
  
  
  tone(PIEZO,B_TONE,PIEZO_TIME);
  digitalWrite(LED,HIGH);

  
 

}

void washHands2Sec(){
  digitalWrite(LED,LOW);
  tone(PIEZO,C_TONE,TONE_DURATION); //1
  delay(PIEZO_TIME);
  
  tone(PIEZO,F_TONE,TONE_DURATION); //2
  delay(PIEZO_TIME);
  
  tone(PIEZO,D_TONE,TONE_DURATION); //3
  delay(PIEZO_TIME);
  
  tone(PIEZO,E_TONE,TONE_DURATION); //4
  delay(PIEZO_TIME);
  
  tone(PIEZO,G_TONE,TONE_DURATION); //5
  delay(PIEZO_TIME);

  digitalWrite(LED,HIGH); //LED turn on
  
  tone(PIEZO,F_TONE,TONE_DURATION); //6
  delay(PIEZO_TIME);
  
  tone(PIEZO,A_TONE,TONE_DURATION); //7
  delay(PIEZO_TIME);
  
  tone(PIEZO,F_TONE,TONE_DURATION); //8
  delay(PIEZO_TIME);
  
  tone(PIEZO,E_TONE,TONE_DURATION); //9
  delay(PIEZO_TIME);
  
  tone(PIEZO,C_TONE,TONE_DURATION); //10
  delay(PIEZO_TIME);

}
void washHands20Sec(){
  for(int i=0; i<10; i++){
  Serial.println(i);
  washHands2Sec();
  }
}
