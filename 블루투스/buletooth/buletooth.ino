#include <SoftwareSerial.h>

int ledPin[2] = {5,6};


SoftwareSerial BTSerial(2, 3);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  if (BTSerial.available()) {
    char data = BTSerial.read();
    Serial.write(data);
    if (data == '1') {
      digitalWrite(13, HIGH);
      Serial.println("천재다.");
    }
    if (data == '0') {
      digitalWrite(13, LOW);
      Serial.println("바보다.");
    }
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }


}
