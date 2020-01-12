#include <NewTone.h>
#include <NewPing.h>

NewPing sonarLeft(5,6);
NewPing sonarRight(10,11);
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

  int pressure1 = analogRead(A0);
  int pressure2 = analogRead(A1);
  int distanceLeft = sonarLeft.ping_cm();
  int distanceRight = sonarRight.ping_cm();
  int frequencyLeft = map(distanceLeft, 0, 100, 1500, 250);
  int toneDelayLeft = map(distanceLeft, 0, 100, 100, 1000);
  int frequencyRight = map(distanceRight, 0, 100, 1500, 250);
  int toneDelayRight = map(distanceRight, 0, 100, 100, 1000);
  
  //Serial.print("Afstand=");
  //Serial.println(distance);
  Serial.println(pressure1);
  Serial.println(pressure2);

  if (pressure1 > 100 && pressure2 > 10) {

    if (distance == 0) {
      noNewTone(speakerLeft);
      noNewTone(speakerRight);
    } else {
      NewTone(speakerRight, frequencyLeft);
      NewTone(speakerLeft, frequencyRight);
      delay(toneDelayLeft);
      delay(toneDelayRight);
      noNewTone(speakerLeft);
      noNewTone(speakerRight);
    }
  }
}
