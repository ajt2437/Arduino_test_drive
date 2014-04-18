/* slot machine uses arrays */

int col1[] = { 
  2, 3, 4 };
int col2[] = { 
  5, 6, 7 };
int col3[] = { 
  8, 9, 10 };
int length = 3;
int fast = 50;
int slow = 200;
int slower = 500;
int buttonPin = 12;
boolean play = LOW;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(col1[i], OUTPUT);
    pinMode(col2[i], OUTPUT);
    pinMode(col3[i], OUTPUT);
    pinMode(buttonPin, INPUT);
  }

}

void loop() {
  // push buttom should go here
  if (digitalRead(buttonPin) == HIGH)
    play = HIGH;
  if (play) {
    intro();
    slot();
  }
}


// little intro row light up
void intro () {
  for (int repeat = 0; repeat < 5; repeat++) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(col1[i], HIGH);
      digitalWrite(col2[i], HIGH);
      digitalWrite(col3[i], HIGH);
      delay (fast);
      digitalWrite(col1[i], LOW);
      digitalWrite(col2[i], LOW);
      digitalWrite(col3[i], LOW);
      delay (fast);
    }
  }
}

void slot() {
  int stopcol1 = random(0, 3);
  int stopcol2 = random(3);
  int stopcol3 = 1;

  digitalWrite(col1[stopcol1], HIGH); // first column stops
  for (int repeat = 0; repeat < 3; repeat++) {
    for (int i = 0; i < 3; i++) {

      digitalWrite(col2[i], HIGH);
      digitalWrite(col3[i], HIGH);
      delay(slow);
      digitalWrite(col2[i], LOW);
      digitalWrite(col3[i], LOW);
      delay(slow);
    }
  }
  digitalWrite(col2[stopcol2], HIGH); // second column stops

  for (int repeat = 0; repeat < 3; repeat++) {
    for (int i = 0; i < 3; i++) {

      digitalWrite(col3[i], HIGH);
      delay(slow);
      digitalWrite(col3[i], LOW);
      delay(slow);
    }
  }

  digitalWrite(col3[stopcol3], HIGH); // third column stops
  delay(500);

  digitalWrite(col1[stopcol1], LOW);
  digitalWrite(col2[stopcol2], LOW);
  digitalWrite(col3[stopcol3], LOW);
  
  // winner
  if (stopcol1 == stopcol2 && stopcol2 == stopcol3) {

    // a check mark for winner
    for (int repeat = 0; repeat < 2; repeat++) {
      digitalWrite(col1[1], HIGH);
      digitalWrite(col2[2], HIGH);
      digitalWrite(col2[1], HIGH);
      digitalWrite(col3[0], HIGH);
      delay(slower);
      digitalWrite(col1[1], LOW);
      digitalWrite(col2[2], LOW);
      digitalWrite(col2[1], LOW);
      digitalWrite(col3[0], LOW);
      delay(slower);
    }
  }

  // loser
  else {

    // a cross for loser
    for (int repeat = 0; repeat < 2; repeat++) {
      digitalWrite(col1[0], HIGH);
      digitalWrite(col1[2], HIGH);
      digitalWrite(col2[1], HIGH);
      digitalWrite(col3[0], HIGH);
      digitalWrite(col3[2], HIGH);
      delay(slower);
      digitalWrite(col1[0], LOW);
      digitalWrite(col1[2], LOW);
      digitalWrite(col2[1], LOW);
      digitalWrite(col3[0], LOW);
      digitalWrite(col3[2], LOW);
      delay(slower);
    }
  }


  // reset back to initial state
  play = LOW;
}








