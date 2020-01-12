#include <NewTone.h> //deze is erin gehaald omdat de newPing library een conflict heeft met de normale tone() gerelateerde functies
#include <NewPing.h> //voor de sonar

NewPing sonar(10,11); //sonar
int speaker = 8; //buzzer

void setup() {
  Serial.begin(9600);
  pinMode(speaker, OUTPUT); //buzzer
  pinMode(A0, INPUT); //druksensor
}

void loop() {
  delay(200);

  int pressure = analogRead(A0);
  int distance = sonar.ping_cm();
  int frequency = map(distance, 0, 100, 1500, 250); //geregistreerde afstand door sonar wordt omgezet naar een waarde die bruikbaar is als frequentie van een toon
  int toneDelay = map(distance, 0, 100, 100, 1000); //zelfde maar dan voor de delay tussen de tonen
  
  Serial.print("Afstand=");
  Serial.println(distance);
  Serial.println(pressure);

  if (pressure > 300) {

    if (distance == 0) { //wanneer de sonar niks oppikt komt er 0 uit als waarde, dus om eindeloos gepiep te voorkomen komt er geen toon wanneer de afstand 0 wordt geregistreerd
      noNewTone(speaker);
    } else {
      NewTone(speaker, frequency);
      delay(toneDelay);
      noNewTone(speaker);
    }
  }
}
