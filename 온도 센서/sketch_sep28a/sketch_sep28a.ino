#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int pinNum[] = {5, 6, 9, 10, 11};


void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(pinNum[i], OUTPUT);
  }
}

void loop() {

  // 광센서 문제 1번
  int val = analogRead(A1);
  int mappedValue = map(val, 0, 1023, 0, 5);
  Serial.println(mappedValue);

  for (int i = 0; i < mappedValue; i++) {
    digitalWrite(pinNum[i], HIGH);
  }
  for (int i = mappedValue; i < 5; i++) {
    digitalWrite(pinNum[i], LOW);
  }
  delay(500);

  // 온도 센서 문제 2번
  voltage = (readSign * 5.0) / 1024.0;
  Serial.print(" V : ");
  Serial.print(voltage);

  int temperatureC = dht.readTemperature();

  Serial.print(temperatureC);
  
  float temperatureF = ((temperatureC * 1.8) + 32.0);

  Serial.print(" 섭씨온도 : ");
  Serial.print(temperatureC);
  Serial.print(" 화씨온도 : ");
  Serial.println(temperatureF);

  int mappedValue_temp = map(readSign, 0, 1023, 0, 5);
  Serial.println(mappedValue_temp);

  for (int i = 0; i < mappedValue_temp; i++) {
  digitalWrite(pinNum[i], HIGH);
  }
  for (int i = mappedValue_temp; i < 5; i++) {
  digitalWrite(pinNum[i], LOW);
  }
  delay(500);
}
