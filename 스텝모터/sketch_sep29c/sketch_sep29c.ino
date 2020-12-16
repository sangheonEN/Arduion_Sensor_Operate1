#include <Stepper.h>

int IN1 = 4; //IN1은 2번 핀에 연결
int IN2 = 5; //IN2는 3번 핀에 연결
int IN3 = 6; //IN3는 4번 핀에 연결
int IN4 = 7; //IN4는 5번 핀에 연결
Stepper step1(2048, IN1, IN3, IN2, IN4);

int lap = 2048; //2048-->360도 회전

void setup() {
  step1.setSpeed(10); //분당 10회 회전
}

void loop() {
  step1.step(lap); //오른쪽으로 한바퀴
  delay(1000); //1초 딜레이
  step1.step(-lap); //왼쪽으로 한바퀴
  delay(1000);
}
