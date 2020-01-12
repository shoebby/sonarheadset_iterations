#include <NewTone.h>
#include <NewPing.h>

NewPing sonar(5,6);
NewPing sonar(10,11);
int speakerLeft = 7;
int speakerRight = 8;

void setup() {
  Serial.begin(9600);
  pinMode(speakerLeft, OUTPUT);
  pinMode(speakerRight, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  delay(200);

  int value1 = analogRead(A0);
  int value2 = analogRead(A1);
  int distance = sonar.ping_cm();
  int frequency = map(distance, 0, 100, 1500, 250);
  int toneDelay = map(distance, 0, 100, 100, 1000);
  
  //Serial.print("Afstand=");
  //Serial.println(distance);
  Serial.println(value1);
  Serial.println(value2);

  if (value1 > 100 && value2 > 10) {

    if (distance == 0) {
      noNewTone(speakerRight);
      noNewTone(speakerRight);
    } else {
      NewTone(speakerRight, frequency);
      NewTone(speakerLeft, frequency);
      delay(toneDelay);
      noNewTone(speakerRight);
      noNewTone(speakerLeft);
    }
  }
}
