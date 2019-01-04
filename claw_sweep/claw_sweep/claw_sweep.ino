/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo servo2;


int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  servo2.attach(10);
  myservo.write(0);
}

void loop() {
  
    myservo.write(0);              // tell servo to go to position in variable 'pos'

    servo2.write(40);
    delay(1000);

    
    myservo.write(30);              // tell servo to go to position in variable 'pos'
    servo2.write(30+40);
    delay(1000);                       // waits 15ms for the servo to reach the position

 
  
}
