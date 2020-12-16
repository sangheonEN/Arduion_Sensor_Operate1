#include <Stepper.h>

int IN1 = 4; //IN1은 2번 핀에 연결
int IN2 = 5; //IN2는 3번 핀에 연결
int IN3 = 6; //IN3는 4번 핀에 연결
int IN4 = 7; //IN4는 5번 핀에 연결
Stepper step1(2048, IN1, IN3, IN2, IN4);

int lap = 2048; //2048-->360도 회전
int motorSpeed;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int value = analogRead(A2);                                       // 가변저항 출력 값 0 ~ 1023
  //value = map(value, 0, 1023, 0, 2047);
  Serial.println("Potentionmeter : " + String(value));
  
  if (value >= 400 && value <= 700) {
    lap = 0;
  }
  else if (value < 400) {
    lap = -100;
    motorSpeed = map(value, 0, 400, 15, 5);
  }
  else if (value > 700) {
    lap = 100;
    motorSpeed = map(value, 700, 1023, 5, 15);
  }

  step1.setSpeed(motorSpeed);
  step1.step(lap);
  delay(10);
}
