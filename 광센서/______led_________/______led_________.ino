int pinNum[] = {5, 6, 9, 10, 11};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(pinNum[i], OUTPUT);
  }
}

void loop() {

  int val = analogRead(A1);
  int mappedValue = map(val, 0, 1023, 0, 5);
  Serial.println(mappedValue);
 
  for(int i = 0; i< mappedValue; i++){
    digitalWrite(pinNum[i], HIGH);
  }
  for(int i = mappedValue; i < 5; i++){
    digitalWrite(pinNum[i], LOW);
  }
  delay(500);
  
}
