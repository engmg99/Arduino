#include <virtuabotixRTC.h>
#include <SevSeg.h>
SevSeg led;
virtuabotixRTC myRTC(A0,A1,A2); //If you change the wiring change the pins here also
float a,b;

void setup() {
Serial.begin(9600);
byte numdigit=4;
byte digitpin[]={10,11,12,13};
byte segpin[]={9, 2, 3, 5, 6, 8, 7, 4};
bool resistor=true;
led.begin(COMMON_CATHODE,numdigit,digitpin,segpin,resistor);
led.setBrightness(90);
}
void Time() {
  myRTC.updateTime();
  a=myRTC.minutes;
  b=myRTC.hours;
}
void loop()
{
 Time();

 led.setNumber(b,2);
 led.refreshDisplay();
 

}

  
