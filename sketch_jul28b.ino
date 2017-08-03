
#include <Servo.h>

Servo Left; 
Servo Right;
Servo Middle;

String inputString = "";
boolean stringComplete = false;

// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600); //initialize serial
  inputString.reserve(200);
  
  Left.attach(9);
  Right.attach(10);
  Middle.attach(11);   // attaches the servo on pin 11 to the servo object
}

void loop() {
  if (stringComplete) {
    Serial.print(inputString);

    if(inputString = "L\n") {
      Serial.print("Left");
     } else {
      Serial.print("Commands are L,R,F,B");
      Serial.print(inputString);
      
     }
     inputString = "";
     stringComplete = false; 
  }
}

