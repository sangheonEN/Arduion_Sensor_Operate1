int distance;

int triggerPin = 7;
int echoPin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {

  // 트리거 핀으로 펄스 값 출력
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  distance = pulseIn(echoPin, HIGH) / 58;

  Serial.println("Distance(cm) : " + String(distance));

  delay(100);
  
}
