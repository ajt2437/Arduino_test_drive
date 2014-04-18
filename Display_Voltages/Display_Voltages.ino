/*
Display5vOrless sketch
 prints the voltage on analog pin to the serial port
 Warning - do not connect more than 5 volts directly to an Arduino pin.
 */
const int referenceVolts = 5;
const int batteryPin = 0;
// the default reference on a 5-volt board
// battery is connected to analog pin 0
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  float val = analogRead(batteryPin); // read the value from the sensor
  float volts = (val / 1023) * referenceVolts; // calculate the ratio
  Serial.println(volts); // print the value in volts
}

