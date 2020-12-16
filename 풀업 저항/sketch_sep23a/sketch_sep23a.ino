int pushButton = 2;
int buttonStatePrevious = LOW;
int buttonStateCurrent = LOW;

void setup() {

  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {

  buttonStateCurrent = digitalRead(pushButton);
  if(buttonStateCurrent != buttonStatePrevious){
    buttonStatePrevious = buttonStateCurrent;
    if(buttonStateCurrent == HIGH){
      Serial.println("Button is on.");
    }
    else if(buttonStateCurrent == LOW){
      Serial.println("Button is off.");
    }
  }
  delay(10);
}
