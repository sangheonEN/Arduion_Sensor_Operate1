#include "DHT11.h"

DHT11 dht11(A0);

void setup() {
  Serial.begin(9600);

}

void loop() {
  float temp, humi;

  int result = dht11.read(humi, temp);

  if (result == 0) {
    Serial.print(temp);
    Serial.print(humi);
  }
  else {
    Serial.print("ERROR NO : ");
    Serial.print(result);
  }
  delay(DHT11_RETRY_DELAY);
}
