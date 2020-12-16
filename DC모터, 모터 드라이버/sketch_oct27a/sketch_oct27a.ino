int motorPin[4] = {2, 3, 4, 5};    // motor 센서
int speedPin[2] = {9, 10};         // pwm 속력 제어
int irPin[2] = {6, 7};             // 적외선
int Speed = 90;                   // 최대 속도
int pSpeed = 0;                    //

// 오른쪽 바퀴 제어 속도 speedPin[0], 왼쪽 바퀴 제어 속도 speedPin[1]
// 오른쪽 바퀴 motorPin[0, 1], 왼쪽 바퀴 motorPin[2, 3]
// 오른쪽 적외선센서 irPin[0] 왼쪽 적외선센서 irPin[1]

void leftMove();
void stopMove();
void rightMove();
void straightMove();

void setup() {
  Serial.begin(9600);
  for (int i = 0 ; i < 4; i++) {
    pinMode(motorPin[i], OUTPUT);
  }
  for (int i = 0 ; i < 2; i++) {
    pinMode(speedPin[i], OUTPUT);
  }
  for (int i = 0 ; i < 2; i++) {
    pinMode(irPin[i], INPUT);
  }
}

void loop() {

  int val1 = digitalRead(irPin[0]); // 오른쪽 적외선
  int val2 = digitalRead(irPin[1]); // 왼쪽 적외선

  Serial.print("1번 : ");
  Serial.print(val1);
  Serial.print("\t");
  Serial.print("2번 : ");
  Serial.println(val2);

  // 오른쪽 적외선 센서 인식 시 오른쪽 바퀴 속력 감소
  if (val1 == 1 && val2 == 0) {
    leftMove();
  }
  // 왼쪽 적외선 센서 인식 시 왼쪽 바퀴 속력 감소
  else if (val1 == 0 && val2 == 1) {
    rightMove();
  }
  else if (val1 == 1 && val2 == 1) {
    straightMove();
  }
  else if (val1 == 0 && val2 == 0) {
    stopMove();
  }
}

void leftMove() {
  digitalWrite(motorPin[0], HIGH);
  digitalWrite(motorPin[1], LOW);
  digitalWrite(motorPin[2], HIGH);
  digitalWrite(motorPin[3], LOW);
  for (int i = pSpeed; i <= Speed; i = i + 5) {
    analogWrite(speedPin[1], i * 1.8);
    analogWrite(speedPin[0], i * (1.2));
  }
  delay(5);
  pSpeed = Speed;
}

void rightMove() {
  digitalWrite(motorPin[0], LOW);
  digitalWrite(motorPin[1], HIGH);
  digitalWrite(motorPin[2], LOW);
  digitalWrite(motorPin[3], HIGH);
  for (int i = pSpeed; i <= Speed; i = i + 5) {
    analogWrite(speedPin[1], i * (1.2));
    analogWrite(speedPin[0], i * 1.8);
  }
  delay(5);
  pSpeed = Speed;
}

void stopMove() {
  for (int i = 0; i < 2; i++) {
    analogWrite(speedPin[i], 0);
  }
}

void straightMove() {
  digitalWrite(motorPin[0], LOW);
  digitalWrite(motorPin[1], HIGH);
  digitalWrite(motorPin[2], HIGH);
  digitalWrite(motorPin[3], LOW);
  // 점차 증가하게 함.
  for (int i = pSpeed; i <= Speed; i = i + 5) {
    analogWrite(speedPin[0], i);
    analogWrite(speedPin[1], i);
  }
  delay(5);
  //  analogWrite(speedPin[1], 70);
  //  analogWrite(speedPin[0], 70);
  pSpeed = Speed;
}


// R후진 L전진
//  digitalWrite(motorPin[0], HIGH);
//  digitalWrite(motorPin[1], LOW);
//  digitalWrite(motorPin[2], HIGH);
//  digitalWrite(motorPin[3], LOW);

//후진
//  digitalWrite(motorPin[0], HIGH);
//  digitalWrite(motorPin[1], LOW);
//  digitalWrite(motorPin[2], LOW);
//  digitalWrite(motorPin[3], HIGH);
//  analogWrite(speedPin[1], 255);
//  analogWrite(speedPin[0], 255);
