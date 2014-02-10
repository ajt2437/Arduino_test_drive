int blinkRate;
char strValue[6];
int index = 0;
const int ledPin = 13;

// blink rate stored in this variable
// must be big enough to hold all the digits and the
// 0 that terminates the string
// the index into the array storing the received digits
void setup () {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT); 
}
void loop() {
  if(Serial.available()) {
    char ch = Serial.read();
    Serial.print(ch);
    if(index < 5 && ch >= '0' && ch <= '9'){
      strValue[index++] = ch; // add the ASCII to the string
    }
    else {
      // here when buffer full or on the first non digit
      strValue[index] = 0;
      // terminate the string with a 0
      blinkRate = atoi(strValue); // use atoi
      index = 0;
    }
  }
  blink();
}

void blink() {
  digitalWrite(ledPin,HIGH);
  delay(blinkRate); // delay depends on blinkrate value
  digitalWrite(ledPin,LOW);
  delay(blinkRate);

}


