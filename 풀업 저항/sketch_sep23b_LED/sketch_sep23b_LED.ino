int pushButton = 9;
int ledPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  int buttonStateCurrent = digitalRead(pushButton);

  if(buttonStateCurrent == LOW)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
