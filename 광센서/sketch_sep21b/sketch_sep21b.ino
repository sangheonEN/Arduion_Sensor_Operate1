int LEDout = 3;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(LEDout,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int val = analogRead(A0);
  int mappedValue = map(val, 0, 1023, 0 ,255);

  analogWrite(LEDout, mappedValue);
  
  Serial.println("Analog Input : " + String(val)+ ", PWM Output : " + String(mappedValue));
  
  delay(1000);
}
