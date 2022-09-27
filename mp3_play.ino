#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial Mp3Serial(2, 3); // SoftwareSerial(RX, TX) 

void setup() {
  // put your setup code here, to run once:
  Mp3Serial.begin(9600);
  mp3_set_serial (Mp3Serial);
  delay(10);
  mp3_set_volume(15);
  delay(10); 
}

void loop() {
  // put your main code here, to run repeatedly:
   mp3_play(1);
  delay(20000);

  mp3_play(2);
  delay(20000);
  
}
