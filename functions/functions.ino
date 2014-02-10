// blink an LED the number of times given in the count parameter
void setup() {
  pinMode(13, OUTPUT);
  blink2(10);
}

void loop() {
}

void blink2(int count)
{
while(count > 0 ) // repeat until count is no longer greater than zero
{
digitalWrite(13,HIGH);
delay(500);
digitalWrite(13,LOW);
delay(500);
count = count -1; // decrement count
}
}
