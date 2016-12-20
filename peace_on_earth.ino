#include <NewPing.h>

const int markPin = A1;
const int twainPin = A2;
const int min_dist = 40;
const int max_distance = 800;
const int dovesFly = 3;

int centimeters1 = 0;
int centimeters2 = 0;
int centimeters3 = 0;
unsigned long startTime = 0;

NewPing sonar(markPin, twainPin, max_distance);

void setup() {
  Serial.begin(9600);
  pinMode(dovesFly, OUTPUT);
}

void loop() {
  //
  unsigned long currentTime = millis();
  
  
  int uS = sonar.ping_median();
  centimeters3 = uS / US_ROUNDTRIP_CM;
  /*
  Serial.print("cm1: ");
  Serial.print(centimeters1);
  Serial.print("  cm2: ");
  Serial.print(centimeters2);
  Serial.print("  cm3: ");
  Serial.println(centimeters3);
  */
  
  if (centimeters1 > min_dist && centimeters2 > min_dist && centimeters3 > min_dist) {
    digitalWrite(dovesFly, HIGH);
    startTime = millis();
    //Serial.println("on");
    } else if (currentTime - startTime > 2000) {
    digitalWrite(dovesFly, LOW);
    startTime = 0;
    //Serial.println("off");
    }

  centimeters1 = centimeters2;
  centimeters2 = centimeters3;
}
