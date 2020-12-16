int ledPin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  establishConnection();

  
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available() > 0){
    int brightness = Serial.parseInt();
    brightness = constrain(brightness, 0, 255);
    analogWrite(ledPin, brightness);                     // analogWrite(led, 밝기 제약조건)

    Serial.println("Current brightness is " + String(brightness, DEC));
  }
}

void establishConnection()
{
  char buffer[100] = "";
  Serial.println("Send me back \'OK\'");

  while(true)
  {
    if(Serial.available())
    {
      int Count = Serial.readBytes(buffer, 99);
      buffer[Count+1] = '\0';
      Serial.println("Receive message : " + String(buffer));
      if(String("OK\n").equals(buffer))         // 컴파일에서 입력할때 개행까지 받아야 넘어감! 그렇지 않을 거면 시리얼 모니터 모드를 No line ending옵션 선택해서 /r이나 /n이 OK와 같이 입력되지 않도록 해야함.
      {
        break;
      }
    }
  }
  Serial.println("Now send me a brightness value.");
}
