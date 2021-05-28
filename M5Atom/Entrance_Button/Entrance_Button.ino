#include <WiFi.h>
#include "M5Atom.h"

const char *ssid="SPWN_N36_763a50";
const char *password="4b4c0834a9f4b";

int i;

void setup() {
  // put your setup code here, to run once:
  WiFi.disconnect(false, true);
  M5.begin(true, false, true);

  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED){
    M5.dis.drawpix(0, 0x707070);
    delay(250);
    M5.dis.clear();
    delay(250);
    Serial.print(".");
  }

  for(i=0; i<3; i++){
    M5.dis.drawpix(0, 0xf00000);
    delay(500);
    M5.dis.clear();
    delay(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  M5.dis.drawpix(0, 0x0000f0);
}