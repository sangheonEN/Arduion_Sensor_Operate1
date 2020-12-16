int ledPins[] = {3, 4, 5};
String inputString = "0";

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 3; i++)
  {
    pinMode(ledPins[i], OUTPUT); 
  }
  LEDOnOff();
}

void loop() {}

void LEDOnOff(){
  long no = inputString.toInt();
  String echoStr = "";

  for(int i = 0; i < 3; i++)
  {
    int on_off = no & (0x01 << i);
    if(on_off){
      digitalWrite(ledPins[i], HIGH);
      echoStr = echoStr + "LED " + String(i + 1) + " : ON ";
    }
    else{
      digitalWrite(ledPins[i], LOW);
      echoStr = echoStr + "LED " + String(i + 1) + " : OFF "; 
    }
  }
  Serial.println(echoStr);
}

void serialEvent(){
  char buffer[100] = "";

  if(Serial.available()){
    int len = Serial.readBytesUntil('\n', buffer, 99);
    buffer[len] = '\0';
    inputString = buffer;
    LEDOnOff();
  }
}
