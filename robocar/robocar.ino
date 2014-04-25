//. Motor driver shield- 2012 Copyright (c) Seeed Technology Inc.
//
// Original Author: Jimbo.we
// Contribution: LG
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

const int echoPin = 4;
const int trigPin = 5;
int pinI1=8;//define I1 interface
int pinI2=11;//define I2 interface
int speedpinA=9;//enable motor A
int pinI3=12;//define I3 interface
int pinI4=13;//define I4 interface
int speedpinB=10;//enable motor B
int spead = 100;//define the spead of motor
int leftLDR = 0;
int centerLDR = 1;
int rightLDR = 2;
// calibration offsets
int leftOffset = 0, rightOffset = 0, centre = 0;
// sensor threshold
int threshhold = 5;


void setup()
{
  pinMode(pinI1,OUTPUT);
  pinMode(pinI2,OUTPUT);
  pinMode(speedpinA,OUTPUT);
  pinMode(pinI3,OUTPUT);
  pinMode(pinI4,OUTPUT);
  pinMode(speedpinB,OUTPUT);
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  calibrate();
}

void loop()
{
  int analogLeft = analogRead(leftLDR);
  int analogCenter = analogRead(centerLDR);
  int analogRight = analogRead(rightLDR);

  double distance = ping();
  Serial.println(distance);
  
  if (distance < 0.15) {
    halt();
  }
  
  else if (analogLeft > analogRight && analogCenter > analogRight) {
       spead += 45;
       left();
       Serial.println("big left");
       spead -= 45; 
  }
  
  else if (analogCenter < 650) {
     forward();
      Serial.println("forward"); 
  }
  
  // if analogLeft is greater than the analogCentre sensor + threshold turn right
  else if (analogLeft > analogCenter - threshhold) {
    left();
    Serial.println("left");

  }
  // if LDR3 is greater than the centre sensor + threshold turn left
  else if (analogRight > analogCenter - 3 * threshhold) { 
    right();
    Serial.println("right");

  }
  else 
    forward();
  //check if left goes in black
  delay(1000);
  Serial.print("LeftLDR: ");
  Serial.println(analogLeft);
  Serial.print("CenterLDR: ");
  Serial.println(analogCenter);
  Serial.print("RightLDR: ");
  Serial.println(analogRight);





  //  left();
  //  delay(2000);
  //  halt();
  //  right();
  //  delay(2000);
  //  halt();
  //  delay(2000);
  //  forward();
  //  delay(2000);
  //  halt();
  //  backward();
  //  delay(2000);
  //  halt();
}

void forward()
{
  analogWrite(speedpinA,spead);//input a simulation value to set the speed
  analogWrite(speedpinB,spead);
  digitalWrite(pinI4,HIGH);//turn DC Motor B move clockwise
  digitalWrite(pinI3,LOW);
  digitalWrite(pinI2,LOW);//turn DC Motor A move anticlockwise
  digitalWrite(pinI1,HIGH);
}
void backward()//
{
  analogWrite(speedpinA,spead);//input a simulation value to set the speed
  analogWrite(speedpinB,spead);
  digitalWrite(pinI4,LOW);//turn DC Motor B move anticlockwise
  digitalWrite(pinI3,HIGH);
  digitalWrite(pinI2,HIGH);//turn DC Motor A move clockwise
  digitalWrite(pinI1,LOW);
}
void left()//
{
  analogWrite(speedpinA,spead);//input a simulation value to set the speed
  analogWrite(speedpinB,spead);
  digitalWrite(pinI4,LOW);//turn DC Motor B move clockwise
  digitalWrite(pinI3,HIGH);
  digitalWrite(pinI2,LOW);//turn DC Motor A move clockwise
  digitalWrite(pinI1,HIGH);
}
void right()//
{
  analogWrite(speedpinA,spead);//input a simulation value to set the speed
  analogWrite(speedpinB,spead);
  digitalWrite(pinI4,HIGH);//turn DC Motor B move anticlockwise
  digitalWrite(pinI3,LOW);
  digitalWrite(pinI2,HIGH);//turn DC Motor A move clockwise
  digitalWrite(pinI1,LOW);
}
void halt()//
{
  digitalWrite(speedpinA,LOW);// Unenble the pin, to stop the motor. this should be done to avid damaging the motor.
  digitalWrite(speedpinB,LOW);
  delay(1000);

}

double ping() {
  int measurementsPerSec = 2;
  for (int i = 0; i < measurementsPerSec; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    double duration = pulseIn(echoPin,HIGH)/2;
    const float speedOfSound = 343.2;
    double distance = (duration/1000000) * speedOfSound;
    return distance;
  }
}
void calibrate() {
  for (int x=0; x<10; x++) { // run this 10 times to obtain average
    delay(100);
    int analogLeft = analogRead(leftLDR);
    int analogCenter = analogRead(centerLDR);
    int analogRight = analogRead(rightLDR);
    leftOffset = leftOffset + analogLeft; // add value of left sensor to total
    centre = centre + centerLDR; // add value of centre sensor to total
    rightOffset = rightOffset + rightLDR; // add value of right sensor to total
    delay(200);

  }
  // obtain average for each sensor
  leftOffset = leftOffset / 10;
  rightOffset = rightOffset / 10;
  centre = centre /10;
  // calculate offsets for left and right sensors
  leftOffset = centre - leftOffset;
  rightOffset = centre - rightOffset;
}






