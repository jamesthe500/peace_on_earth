#include <NewPing.h>

const int markPin = A1;
const int twainPin = A2;
const int min_dist = 10;
const int max_distance = 200;
const int max_trigger = 100;
const int dovesFly = 3;

int centimeters1 = 0;
int centimeters2 = 0;
/*
int centimeters3 = 0;
int centimeters4 = 0;
int centimeters5 = 0;
*/
unsigned long startTime = 0;

NewPing sonar(markPin, twainPin, max_distance);

void setup() {
  //Serial.begin(9600);
  pinMode(dovesFly, OUTPUT);
}

void loop() {
  //
  unsigned long currentTime = millis();
  
  
  int uS = sonar.ping_median();
  int cms = uS / US_ROUNDTRIP_CM;
  /*
  Serial.print("cms: ");
  Serial.println(cms);
  */
  if (cms > max_trigger){
    centimeters2 = 0;
  } else {
    centimeters2 = cms;
  }
  /*
  Serial.print("cm1: ");
  Serial.print(centimeters1);
  Serial.print("  cm2: ");
  Serial.println(centimeters2);
  //Serial.print("  cm3: ");
  //Serial.println(centimeters3);
 
  //Serial.println(centimeters5);
  */
  
  if (centimeters1 > min_dist && centimeters2 > min_dist ) {
    digitalWrite(dovesFly, HIGH);
    startTime = millis();
    //Serial.println("on");
    } else if (currentTime - startTime > 4000) {
    digitalWrite(dovesFly, LOW);
    startTime = 0;
    //Serial.println("off");
    }

  centimeters1 = centimeters2;
  //centimeters2 = centimeters3;
  //centimeters3 = centimeters4;
  //centimeters4 = centimeters5;
  delay(100);
}
