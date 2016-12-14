#include <NewPing.h>

const int markPin = A1;
const int twainPin = A2;
const int min_lowDist = 40;
const int max_distance = 400;
const int dovesFly = 3;
NewPing sonar(markPin, twainPin, max_distance);

void setup() {
  Serial.begin(9600);
  pinMode(dovesFly, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int uS = sonar.ping_median();
  int centimeters = uS / US_ROUNDTRIP_CM;
  Serial.print("cm: ");
  Serial.println(centimeters);
  if (centimeters > min_lowDist) {
    digitalWrite(dovesFly, HIGH);
    } else {
    digitalWrite(dovesFly, LOW);
  }
}
