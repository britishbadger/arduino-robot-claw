#include <VarSpeedServo.h>

/**
 * Notes:
 *  Having played with the kit a while and taking into account how I've mounted it, I've settled for using a single joystick. 
 *  I've found this prevents the servos for the arm acting against each other and burning out. 
 *  In the new setup, the the servos move together in seperate directions to accomplish the motion.
 * 
 * Changes:
 * 31-DEC-2018 : 
 *    - Changed to use a single joystick
 *    - Added ability to control claw using switch.
 */

#define Y_LEFT_PIN A1                  //X axis reading from joystick will go into analog pin A1
#define X_LEFT_PIN A0                  //X axis reading from joystick will go into analog pin A1

#define X_RIGHT_PIN  A3
#define Y_RIGHT_PIN  A4

const int SW_pin = 12; // digital pin connected to analogue joystick.


// Controlled by LEFT JOYSTICK
VarSpeedServo a;  
VarSpeedServo b;

VarSpeedServo c;
VarSpeedServo d;   

int SPEED = 50;

void setup()
{
 Serial.begin(9600);

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);

  a.attach(11); // lateral
  b.attach(6);  // extend in and out   RIGHT SERVO
  
  c.attach(5);  // extend up and down  LEFT SERVO
  d.attach(10); // claw 

}
 
void loop()
{
  
  delay(200);                    

  // The map function takes the following args
  // map(value, fromLow, fromHigh, toLow, toHigh)

  // LEFT JOYSTICK - LATERAL MOTION
  int leftYVal = analogRead(Y_LEFT_PIN) ; 
  leftYVal = map(leftYVal, 0, 1023, 20, 150);
 
//  Serial.print("Y=");
//  Serial.println(leftYVal);
  
  a.write(leftYVal, SPEED);      // extend arm in and out.  

// LATERAL MOTION
  int leftXVal = analogRead(X_LEFT_PIN) ;  
  leftXVal = map(leftXVal, 0, 1023, 0,150);
//  Serial.print("X=");
//  Serial.println(leftXVal);

  b.write(leftXVal, SPEED);      // rotate 

  int rightXVal = analogRead(X_RIGHT_PIN) ;
  // right joystick
  rightXVal = map(rightXVal,0 ,1023, 0, 150);
  c.write(rightXVal, SPEED);

  //  extend up and down
  int rightYVal = analogRead(Y_RIGHT_PIN) ;
  rightYVal = map(rightYVal, 40, 1023, 0, 150);
  d.write(rightYVal, SPEED);
    
  int val = digitalRead(SW_pin);

  if (val == HIGH){
    d.write(30);    
  }
  else{
    d.write(0);
  }
  
}
