int LedPin[] = {11, 10, 9, 6, 5};

int currentVoltage = 0;
int previousVoltage = 0;

void setup() {
  for(int i = 0; i < sizeof(LedPin) / sizeof(int); i++){
    pinMode(LedPin[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int analogSign = analogRead(A1);
  currentVoltage = map(analogSign, 0, 1023, 0, 5);

  if(currentVoltage != previousVoltage){
    previousVoltage = currentVoltage;

    for(int i = 0; i < currentVoltage; i++){
      digitalWrite(LedPin[i], HIGH);
    }
    for(int i = currentVoltage; i < 5; i++){
      digitalWrite(LedPin[i], LOW); 
    }
  }
}
