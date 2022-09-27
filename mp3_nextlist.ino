#include <DFPlayer_Mini_Mp3.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1); // RX, TX (아두이노 업로드를 위해 가상 시리얼 사용)

  int btnNext = 2;  // 다음 곡 재생 버튼

  

  void setup () {

    pinMode(btnNext, INPUT);    // "다음 곡 버튼"을 입력 핀으로 설정

    digitalWrite(btnNext, HIGH);   // "다음 곡 버튼"을 HIGH 상태로 설정

    

    mySerial.begin (9600);        // 소프트웨어 시리얼 통신 시작(9600 Baud rate)

    mp3_set_serial (mySerial);    // DFPlayer-mini mp3 모듈에 소프트웨어 시리얼 설정

    

    mp3_set_volume (15);         // 볼륨은 중간 볼륨인 15로 설정(0~30)

    delay(10);                      // 볼륨이 설정될 동안 10ms 대기

    

   

  }

  

  void loop () {

    // "다음 곡 재생" 버튼이 눌리면
 mp3_play(1);                   // 1 번 곡 실행

    delay(10);                      // 첫 번째 곡이 재생될 동안 10ms 대기
    if(digitalRead(btnNext) == LOW){

      mp3_next ();  // 다음 곡 재생

    }

  }
