#include <Servo.h>

Servo myServo;  // create a servo object

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int angle;   // variable to hold the angle for the servo motor

void setup() {

  myServo.attach(9); // attaches the servo on pin 9 to the servo object

// initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600); // open a serial connection to your computer
}

void loop() {

  // set the servo position
  myServo.write(angle);

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    angle = 180;
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    angle = 0;
  }
}
