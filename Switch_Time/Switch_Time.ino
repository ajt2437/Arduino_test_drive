/* SwitchTime sketch
Countdown timer that decrements every tenth of a second
lights an LED when 0
Pressing buttom increments count, holding button down increase
rate of increment
*/

const int ledPin = 13;
const int inputPin = 2;

const int debounceTime = 20;
const int fastIncrement = 1000;
const int veryFastIncrement = 4000;
int count = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  digitalWrite(inputPin,HIGH);
  Serial.begin(9600);
}

void loop() {
  int duration = switchTime();
  if (duration > veryFastIncrement)
  count +=10;
  else if (duration > fastIncrement)
  count += 4;
  else if (duration > debounceTime)
  count +=1;
  
  else {
    if (count == 0)
    digitalWrite(ledPin, HIGH);
    else {
      digitalWrite(ledPin,LOW);
      count -= 1;
    }
  }
  Serial.println(count);
  delay(100);
}
    
    long switchTime(){
  static unsigned long startTime = 0;
  static boolean state;
  
  if (digitalRead(inputPin) != state) {
    state = !state;
    startTime = millis();
  }
  if (state == LOW)
    return millis() - startTime;
    else
    return 0;
}
  
