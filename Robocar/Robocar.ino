//. Motor driver shield- 2012 Copyright (c) Seeed Technology Inc.
// 
//  Original Author: Jimbo.we
//  Contribution: LG
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

int pinI1=8;//define I1 interface
int pinI2=11;//define I2 interface 
int speedpinA=9;//enable motor A
int pinI3=12;//define I3 interface 
int pinI4=13;//define I4 interface 
int speedpinB=10;//enable motor B
int spead = 127;//define the spead of motor
const int echoPin = 1;
const int trigPin = 2;
 
void setup()
{
  pinMode(pinI1,OUTPUT);
  pinMode(pinI2,OUTPUT);
  pinMode(speedpinA,OUTPUT);
  pinMode(pinI3,OUTPUT);
  pinMode(pinI4,OUTPUT);
  pinMode(speedpinB,OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}
 
void forward()
{
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,LOW);//turn DC Motor B move clockwise
     digitalWrite(pinI3,HIGH);
     digitalWrite(pinI2,HIGH);//turn DC Motor A move anticlockwise
     digitalWrite(pinI1,LOW);
}
void backward()//
{
     analogWrite(speedpinA,spead);//input a simulation value to set the speed
     analogWrite(speedpinB,spead);
     digitalWrite(pinI4,HIGH);//turn DC Motor B move anticlockwise
     digitalWrite(pinI3,LOW);
     digitalWrite(pinI2,LOW);//turn DC Motor A move clockwise
     digitalWrite(pinI1,HIGH);
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

void loop()
{
  forward();
  delay(4000);
  halt();
  delay(2000);
  left();
  delay(5000);
}
