#include <Servo.h> //서보 라이브러리를 불러옵니다.

Servo myservo1;  // 서보를 제어할 서보 오브젝트를 만듭니다.

int servoPin = 9;     // 서보 위치를 저장할 변수를 선언합니다.

void setup()
{
  myservo1.attach(servoPin);
}


void loop()
{
  int value = analogRead(A2);
  value = map(value, 0, 1023, 0, 179);
  myservo1.write(value);

  delay(20);
}
