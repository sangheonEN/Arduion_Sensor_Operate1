#include <core_build_options.h>
#include <swRTC.h>
swRTC rtc;           // 클래스 개채 선언

int trigerPin = 13;
int echoPin = 12;
int ledPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(trigerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.println("CLEARDATA");
  Serial.println("Duration, Distance, Time");

  // swRTC
  rtc.stopRTC();
  rtc.setTime(4, 37, 0);
  rtc.setDate(22, 10, 2020);
  rtc.startRTC();
}

void loop() {


  digitalWrite(trigerPin, HIGH);
  delay(10);
  digitalWrite(trigerPin, LOW);

  float duration = pulseIn(echoPin, HIGH); // echoPin이 HIGH로 유지되는 시간을 마이크로초로 반환. 즉, 초음파를 보냈다가 다시 들어오는 시간을 반환(왕복시간 us(마이크로초)단위로 반환)

  //물체와의 거리 계산 거 = 속 * 시  cm 단위로 계산 초음파 속력 : 340m/s

  float distance = ((float)(340 * duration) / 10000) / 2;

  //  Serial.print("Duration : ");
  Serial.print("DATA,");
  Serial.print(duration);
  Serial.print("us");
  Serial.print(",");
  // Serial.print(" distance : ");
  Serial.print(distance);
  Serial.println("cm");
  Serial.print(",");
//  // 시간
//  Serial.print(rtc.getHours(), DEC);
//  Serial.print(" : ");
//  Serial.print(rtc.getMinutes(), DEC);
//  Serial.print(" : ");
//  Serial.print(rtc.getSeconds(), DEC);
//  Serial.print("\t");
//  Serial.print(rtc.getYear(), DEC);
//  Serial.print("/");
//  Serial.print(rtc.getMonth(), DEC);
//  Serial.print("/");
//  Serial.println(rtc.getDay(), DEC);

//  if (distance >= 50)
//  {
//    digitalWrite(ledPin, HIGH);
//  }
//  else
//  {
//    digitalWrite(ledPin, LOW);
//  }

  delay(500);

}
