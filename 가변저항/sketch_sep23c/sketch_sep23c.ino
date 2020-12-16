void setup() {

  Serial.begin(9600);

}

void loop() {

  String echoStr;
  int read = analogRead(A0);

  echoStr = "Current analog input : " + String(read);

  Serial.println(echoStr);
  delay(10);
  
}
