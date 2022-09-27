int distance = 0; // 거리값을 저장할 변수
 
// push button을 디지털 2번 핀에 연결합니다.
const int button1Pin = 2; 
const int button2Pin = 3;
const int button3Pin = 4;
// led를 디지털 13번 핀에 연결합니다.
const int ledPin1 = 11;
const int ledPin2 = 12;
const int ledPin3 = 13;

// 실행시 가장 먼저 호출되는 함수이며, 최초 1회만 실행됩니다.

void setup() {
  //2번 핀을 입력 핀으로 설정합니다.
  pinMode(button1Pin, INPUT);
  //13번 핀을 출력 핀으로 설정합니다.
  pinMode(ledPin1, OUTPUT);  
  pinMode(button2Pin, INPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(button3Pin, INPUT);
  pinMode(ledPin3, OUTPUT);
  
   Serial.begin(9600); 
}

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행합니다.
void loop() {
  // 버튼에서 읽어 올 디지털 값을 저장할 변수를 선언합니다.
 int button1State;    
  int button2State;
  int button3State; 
  // 버튼이 눌렸는 지 아닌지 버튼의 상태를 읽어와서 앞에 선언한 변수에 저장

     
  int volt = map(analogRead(A0), 0, 1023, 0, 5000); // 0~1023 사이 값을 갖는 아날로그 신호값을
                                                    //  0~5000 (5V) 사이 값으로 변환
     
  distance = (27.61 / (volt - 0.1696)) * 1000; // 읽어들인 Voltage 값을 거리값(단위: cm)로 변환하는 공
   button1State = digitalRead(button1Pin); 
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  
  if(distance>=40)//거리가 40cm이상이면
  {
    if(button1State == LOW) {
    digitalWrite(ledPin1, HIGH);   
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW); 
    }
    if(button2State == LOW) {
    digitalWrite(ledPin1, LOW);   
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW); 
    }
   if(button3State == LOW){ 
    digitalWrite(ledPin1, LOW);   
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH); 
   }
   
  }
  // 버튼이 눌리지 않았다면
else
   {
    //LED를 OFF 시킵니다.
    digitalWrite(ledPin1, LOW);   
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW); 
   }
  Serial.print(distance);  //거리값을 시리얼모니터로 출력해줍니다.
 
  Serial.print(" cm");
  Serial.println(" ");
}
