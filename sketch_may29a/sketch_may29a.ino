#include <SevSeg.h>
SevSeg led;
float a=20;
float b=11;


void setup() {
Serial.begin(9600);
byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
  bool resistorsOnSegments = true;
  byte hardwareConfig = COMMON_CATHODE;

 led.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
led.setBrightness(90);
}
void loop() {

  led.setNumber(a,2);
  led.refreshDisplay();
  
  led.setNumber(b,1);
  led.refreshDisplay();
 delay(1);
}

  
