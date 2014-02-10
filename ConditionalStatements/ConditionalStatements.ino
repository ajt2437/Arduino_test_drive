/* 
 Pushbutton sketch
 a switch connected to pin 2 lights the LED on pin 13
 */

const int ledPin = 13;
const int inputPin = 2;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
}
// choose the pin for the LED
// choose the input pin (for a pushbutton)
// declare LED pin as output
// declare pushbutton pin as input
void loop(){
  int val = digitalRead(inputPin);
  if (val == HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
}


