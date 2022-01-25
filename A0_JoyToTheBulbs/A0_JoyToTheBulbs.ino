/*
  "Joy to the Bulbs"

  Turns single LED bulbs on (arranged in a cross) according to the direction that a joystick is moved in.
  Turns ALL 4 LEDs on if button is clicked.

  created Jan 2022
  by Alice Norman
  :-)
  
  See ReadMe for references and more info.

*/

// Re-defining pins A0 and A1, since they will be used for the joystick X and Y
#define joyX A0
#define joyY A1

const int ledPin_top =  10;  // Top LED
const int ledPin_right =  11;  // Right LED
const int ledPin_bottom =  12;  // Bottom LED
const int ledPin_left =  13;  // Left LED

// Initializing joystick X and Y variables
int xValue = 0; 
int yValue = 0;

// Initializing 'button' state and pin number ('button' = middle click on joystick)
int button_state = 0;
int buttonPin = 2; // connected to joystick's "SW" pin


void setup() 
{
  Serial.begin(9600); // Opening serial port and setting data rate to 9600 bits per sec (joy stick)
  
  // Setting each LED pin as "output"
  pinMode(ledPin_top, OUTPUT);
  pinMode(ledPin_right, OUTPUT);
  pinMode(ledPin_bottom, OUTPUT);
  pinMode(ledPin_left, OUTPUT);
  
  // Setting joystick's middle button to pin 2 as input (buttonPin var)
  pinMode(buttonPin, INPUT_PULLUP); 
  
}

// Small helper function to make joystick value comparison's easier later
// (tried to write code without this helper first and it was way too messy/confusing!)
// Checks if given value, n, is in the given range (between lowerBound and upperBound)
bool isInRange(int lowerBound, int upperBound, int n)
{
    return (lowerBound <= n && n <= upperBound);
}


void loop() 
{
  
  xValue = analogRead(joyX); // retrieving x value from the joystick
  yValue = analogRead(joyY); // retrieving y value from the joystick
  
  button_state = digitalRead(buttonPin);
  
  // See ReadMe for info on these numbers.
  if (isInRange(0, 20, xValue) && isInRange(440, 465, yValue)) // joystick value ranges for UP direction
  {
    digitalWrite(ledPin_top, HIGH); // joystick up = top LED on
  }
  else if (isInRange(440, 465, xValue) && isInRange(0, 20, yValue)) // RIGHT direction
  {
    digitalWrite(ledPin_right, HIGH); // joystick right = right LED on
  }
  else if (isInRange(880, 920, xValue) && isInRange(440, 465, yValue)) // DOWN direction
  {
    digitalWrite(ledPin_bottom, HIGH); // joystick down = bottom LED on
  }
  else if (isInRange(440, 465, xValue) && isInRange(880, 920, yValue)) // LEFT direction
  {
    digitalWrite(ledPin_left, HIGH); // joystick left = left LED on
  }
  else if (button_state == 0) // if joystick button is clicked
  {
    // turn on ALL the LEDs
    digitalWrite(ledPin_top, HIGH);
    digitalWrite(ledPin_right, HIGH);
    digitalWrite(ledPin_bottom, HIGH);
    digitalWrite(ledPin_left, HIGH);
  }
  else // turn all LEDs off (since no valid 'triggers' identified)
  {  
  
    digitalWrite(ledPin_top, LOW);
    digitalWrite(ledPin_right, LOW);
    digitalWrite(ledPin_bottom, LOW);
    digitalWrite(ledPin_left, LOW);
  
  }
  
  
}