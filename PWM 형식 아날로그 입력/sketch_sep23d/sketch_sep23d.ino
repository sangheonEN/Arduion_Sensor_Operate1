int ledPinNum = 9;
int brightness = 0;      // 밝기 값 (이 행은 초기 값)
int fadeAmount = 10;     // 밝기 변화량

void setup() {
  Serial.begin(9600);

  pinMode(ledPinNum, OUTPUT);
  
}

void loop() {

  analogWrite(ledPinNum, brightness);

  brightness += fadeAmount;
  if(brightness > 255)
  {
    brightness = 255;
    fadeAmount *= -1;
  }

  if(brightness < 0)
  {
    brightness = 0;
    fadeAmount *= -1;
  }
  delay(50);
}
