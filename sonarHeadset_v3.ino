#include <NewTone.h> //This library has been imported due to the newPing library conflicting with the normal tone() function
#include <NewPing.h> //for the ultrasonic sensor

NewPing sonar(10,11); //ultrasonic sensor
int speaker = 8; //speaker/buzzer

void setup() {
  Serial.begin(9600);
  pinMode(speaker, OUTPUT); //speaker/buzzer
  pinMode(A0, INPUT); //force-sensitive resistor
}

void loop() {
  delay(200);

  int pressure = analogRead(A0);
  int distance = sonar.ping_cm();
  int frequency = map(distance, 0, 100, 1500, 250); //registered distance by ultrasonic sensor is translated to a frequency between 1500 and 250
  int toneDelay = map(distance, 0, 100, 100, 1000); //same as above, but instead translated to a delay between 100 and 1000
  
  Serial.print("Distance=");
  Serial.println(distance);
  Serial.println(pressure);

  if (pressure > 300) {

    if (distance == 0) { //when the ultrasonic sensor registers a value of 0 no tone is being played, this is to prevent the device from beeping when it doesnt register anything
      noNewTone(speaker);
    } else {
      NewTone(speaker, frequency);
      delay(toneDelay);
      noNewTone(speaker);
    }
  }
}
