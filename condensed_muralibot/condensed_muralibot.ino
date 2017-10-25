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
  Serial.begin(9600); // initialize serial
  inputString.reserve(200);

  Left.attach(9); //pin that servo is attached to 
  Right.attach(10);
  Middle.attach(11);

  Right.detach();
  Left.detach();
  Middle.detach();
  
}
void loop() {
  if(stringComplete) {
    Serial.print(inputString);

    if(inputString == "L\n"){
      Right.attach(9);
      Left.attach(10);
      Middle.attach(11);
      
      Right.write(180);  
      Left.write(180);
      Middle.write(180);
      Serial.flush();
    } else {
      Serial.print(inputString);
    } if(inputString =="R\n"){
        Right.attach(9);
        Left.attach(10);
        Middle.attach(11);

        Right.write(0);
        Left.write(0);
        Middle.write(0);
        Serial.flush();
      } else {
        Serial.print(inputString);
      } if(inputString == "F\n"){
        Right.attach(9);
        Left.attach(10);
        Middle.detach();

        Right.write(0);
        Left.write(180);
        Serial.flush();
      } else {
        Serial.print(inputString);
      } if(inputString == "B\n"){
        Right.attach(9);
        Left.attach(10);
        Middle.detach();

        Right.write(180);
        Left.write(0);
        Serial.flush();
      } else {
        Serial.print(inputString);
      } if(inputString == "S\n"){
        Right.detach();
        Left.detach();
        Middle.detach();
        Serial.flush();
      } inputString = "";
      stringComplete = false;
    } else {
      Serial.print(inputString);
    } if(inputString == "LS\n"){
      Right.detach();
      Left.detach();
      Middle.attach(11);
      
      Middle.write(180);
      Serial.flush();
    } else {
      Serial.print(inputString);
    } if(inputString == "RS\n"){
      Right.detach();
      Left.detach();
      Middle.attach(11);
      
      Middle.write(0);
      Serial.flush();
    }
  }
void serialEvent() {
  while(Serial.available()) {
    //get the new byte:
    char inChar = (char)Serial.read();
    //add it to the inputString;
    inputString +=inChar;
    // if the incoming character is a newline, set a flag so the main loop 
    //can do something about it:
    if(inChar == '\n') {
      stringComplete = true;
    }
  }
}


