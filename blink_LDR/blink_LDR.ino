const int ledPin = 13;
const int sensorPin = 0;
// LED connected to digital pin 13
// connect sensor to analog input 0

// the next two lines set the min and max delay between blinks
const int minDuration = 100; // minimum wait between blinks
const int maxDuration = 1000; // maximum wait between blinks

void setup()
{
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT); // enable output on the led pin
  Serial.begin(9600);
}
void loop()
{
  int rate = analogRead(sensorPin);
  // read the analog input
  Serial.println(rate);
  rate = map(rate,200,800,minDuration, maxDuration); // convert to blink rate
  digitalWrite(ledPin, HIGH);
  // set the LED on
  delay(rate);
  // wait duration dependent on light level
  digitalWrite(ledPin, LOW);
  // set the LED off
  delay(rate);
}

