#include <WiFi.h>
#include <HTTPClient.h>
#include "M5Atom.h"

HTTPClient http;

const char *ssid="SPWN_N36_763a50";
const char *password="4b4c0834a9f4b";

const String url="http://192.168.179.4:16278/M5ButtonPushed";

int i;
int cnt = 0;
int httpcode = 0;
String payload;
long tmptime;

void btnPressed(){
  cnt++;
  Serial.println("button pressed. access to " + url);
  http.begin(url);
  httpcode = http.GET();
  if (httpcode > 0){
    payload = http.getString();
    Serial.println(payload);
  }
  else{
    Serial.println("failed");
  }
  http.end();
  return;
}

void setup() {
  // put your setup code here, to run once:
  WiFi.disconnect(false, true);
  M5.begin(true, false, true);
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED){
    M5.dis.drawpix(0, 0x707070);
    delay(250);
    M5.dis.clear();
    delay(250);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  for(i=0; i<3; i++){
    M5.dis.drawpix(0, 0xf00000);
    delay(500);
    M5.dis.clear();
    delay(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:M5.update();
  M5.update();
  if (M5.Btn.wasPressed()){
    btnPressed();
  }
  M5.dis.drawpix(0, 0x0000f0);
}
