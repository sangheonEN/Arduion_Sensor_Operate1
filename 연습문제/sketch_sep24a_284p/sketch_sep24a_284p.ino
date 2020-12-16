int ledPin[] = {9, 10, 11};
int inPinA = A0;
int sunbun = 1;
int time = millis();

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
  pinMode(inPinA, INPUT);
}

void loop() {
  int read = digitalRead(inPinA);
  Serial.println("inPinA : " + String(read));

  // LED ON/OFF (조건문 사용 digitalRead 논리 값이 1일때는 HIGH, 0일때는 LOW)
  if (read == 0)
  {
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPin[i], HIGH);
    }
  }
  else
  {
    if (time + 1000 < millis() && sunbun == 1) {
      time = millis();
      sunbun = 2;
      digitalWrite(ledPin[0], HIGH);
      digitalWrite(ledPin[1], LOW);
      digitalWrite(ledPin[2], LOW);
    }
    if (time + 1000 < millis() && sunbun == 2) {
      time = millis();
      sunbun = 3;
      digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[1], HIGH);
      digitalWrite(ledPin[2], LOW);
    }
    if (time + 1000 < millis() && sunbun == 3) {
      time = millis();
      sunbun = 1;
      digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[1], LOW);
      digitalWrite(ledPin[2], HIGH);
    }
  }
}

// 딜레이 주고
// 디지털리드 넣고  만약 READ == 1이라면 LED ON/OFF 함수 호출
// 딜레이

// time 변수 선언해서 millis();로 현재 시간을 받아서 내가 원하는 반복 시간 더해서 밀리값이 더한 값 보다 크고 순번이 0일때 다음 순번으로 바꿔주고 다음 순번으로 줌
