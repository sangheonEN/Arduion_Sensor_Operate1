int distance;
int triggerPin = 7;
int echoPin = 6;

int pinNum = 3;
int speakerPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pinNum, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // 트리거 핀으로 펄스 값 출력
  distancef();

  //거리에 따라 밝기 조절
  int val = map(distance, 0, 300, 255, 0);

  if (distance >= 30) {
    digitalWrite(pinNum, LOW);
  }
  else {
    analogWrite(pinNum, val);
  }

  // tone 함수를 이용해 물체의 거리에 따라 단음 연주
  if (distance >= 30) {
    noTone(speakerPin);
  }
  else {
    tone(speakerPin, 988);
  }
  delay(100);
}

void distancef() {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  distance = pulseIn(echoPin, HIGH) / 58;

  Serial.println("Distance(cm) : " + String(distance));
}
