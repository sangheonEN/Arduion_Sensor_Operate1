int ledPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int analogInput = analogRead(A0);
  int brightness = analogInput / 4;

  analogWrite(ledPin, brightness);
}
