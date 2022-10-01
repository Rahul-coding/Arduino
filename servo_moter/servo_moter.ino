int state;
#include <Servo.h>
Servo bubbu_motor;
void setup() 
{
  bubbu_motor.attach(2);
  pinMode(9, INPUT);
  pinMode(8,OUTPUT);

}

void loop()
{

    bubbu_motor.write(30);
    delay(5000);
    bubbu_motor.write(60);
    delay(5000);
     bubbu_motor.write(90);
    delay(5000);
    bubbu_motor.write(180);
    delay(5000);
    bubbu_motor.write(0);
    delay(5000);
 
}
