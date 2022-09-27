#include <DFPlayer_Mini_Mp3.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerial(0,1);
void setup()
{
  Serial.begin (9600);
  mp3_set_serial (Serial);
  delay(1);
  mp3_set_volume (50);
}

void loop ()
{
  mp3_play (1);
  delay(6000);
}

