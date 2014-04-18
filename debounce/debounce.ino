/* 5.1 a switch in pin 2 lights the LED on pin 13 */

const int ledPin = 13; 
const int inputPin = 2; // input pin for the pushbutton
const int debounceDelay = 10;

boolean debounce (int pin) {
  boolean state;
  boolean previousState;

  previousState = digitalRead(pin);
  for(int counter = 0; counter < debounceDelay; counter++) {
    delay(100);
    state = digitalRead(pin);
    if (state != previousState) {
      counter = 0;
      previousState = state;
    } 
  }
  return state;
}
int count;
void setup () {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin,INPUT);
  Serial.begin(9600);
  // digitalWrite(inputPin, HIGH);turn on pull-up resistor
}

void loop() {
  if (debounce(inputPin))
    digitalWrite(ledPin, HIGH);
    count++;
    Serial.println(count);

}



