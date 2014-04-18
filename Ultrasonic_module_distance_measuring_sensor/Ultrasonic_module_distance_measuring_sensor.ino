/* Ping))) Sensor
 * prints distance and changes LED flash rate
 * depending on distance from the Ping))) sensor
 */
const int echoPin = 6;
const int trigPin = 7;
const int greenLed = 2;
const int redLed = 3;

void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  double cumulativeDistance;
  double averagedDistance;
  double lowDistance;
  double highDistance;
  int i;
  int measurementsPerSec = 2;

  for (i = 0; i < measurementsPerSec; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    double duration = pulseIn(echoPin,HIGH)/2;
    const float speedOfSound = 343.2;
    double distance = (duration/1000000) * speedOfSound;
    if (distance < 2.00) {
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed,LOW);
    }
    else {
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, LOW);
    }

    Serial.print("Averaged distance = ");
    Serial.println(averagedDistance);
    Serial.print("current distance = ");
    Serial.println(distance);
    delay(1000/measurementsPerSec);
  }
}


