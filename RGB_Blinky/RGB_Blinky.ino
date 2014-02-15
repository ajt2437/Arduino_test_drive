/* Project 1:RGB Blinky
  Uses a single RGB LED to cycle through three color */
  
void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  digitalWrite(9,HIGH);
  // digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  delay(1000);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  delay(1000);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
  delay(1000);
  
}
