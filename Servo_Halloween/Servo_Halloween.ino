
#include <Servo.h> 

Servo servo; // servo object representing the MG 996R servo

void setup() {
  servo.attach(13); // servo is wired to Arduino on digital pin 3
}

void loop() {
  drop();
}

void drop() {
  delay(1000); // wait for one second
  servo.write(0); // move MG996R's shaft to angle 0°
  delay(1000); // wait for one second
  servo.write(180); // move MG996R's shaft to angle 45°
  delay(1000); // wait for one second 
  servo.write(0); // move MG996R's shaft to angle 90°
  delay(1000);
  
}
