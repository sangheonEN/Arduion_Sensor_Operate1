int LedPin = 11;
int inputA1 = A1;

void setup() {
  pinMode(LedPin, OUTPUT);
  pinMode(inputA1, INPUT);
  Serial.begin(9600);
}

void loop() {
  int a = analogRead(inputA1);

  Serial.println(a);

  int delaytime = map(a, 0, 1023, 100, 1000);

  digitalWrite(LedPin, HIGH);
  delay(delaytime);
  digitalWrite(LedPin, LOW);
  delay(delaytime);
}
