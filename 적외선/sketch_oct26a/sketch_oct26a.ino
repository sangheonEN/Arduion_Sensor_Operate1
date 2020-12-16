int sensor[4] = {8, 9, 10, 11};
int ledPin[2] = {4, 5};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(sensor[i], INPUT);
  }
  for (int i = 0; i < 2; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  int val1 = digitalRead(sensor[0]);
  int val2 = digitalRead(sensor[1]);
  int val3 = digitalRead(sensor[2]);
  int val4 = digitalRead(sensor[3]);

  Serial.print("1번 : ");
  Serial.print(val1);
  Serial.print("\t");
  Serial.print("2번 : ");
  Serial.print(val2);
  Serial.print("\t");
  Serial.print("3번 : ");
  Serial.print(val3);
  Serial.print("\t");
  Serial.print("4번 : ");
  Serial.println(val4);

  if (val1 = 0) {
    digitalWrite(ledPin[0], HIGH);
  }
  else{
    digitalWrite(ledPin[0], LOW);
  }
  if (val2 = 0) {
    digitalWrite(ledPin[1], HIGH);
  }
  else{
    digitalWrite(ledPin[1], LOW);
  }

  delay(300);
}
