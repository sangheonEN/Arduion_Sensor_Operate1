// 1) iptime에 연결
// 2) 도메인 주소 server에

int pinNum[] = {5, 6, 9, 10, 11};
long time = millis();
int sunbun = 1;

#include "WiFiEsp.h"

#ifndef HAVE_HWEspSerial
#include "SoftwareSerial.h"
SoftwareSerial EspSerial(2, 3); // RX, TX
#endif

char ssid[] = "iptime";            // your network SSID (name)
char pass[] = "";        // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status
int pushButton = A0;

char server[] = "jteks5.dothome.co.kr";

// Initialize the Ethernet client object
WiFiEspClient client;                               // wifi에 연결하기 위한 클래스 값형식 stack에 올라감

void setup()                                        // 초기화 상황
{
  //LED OUTPUT
  for (int i = 0; i < 5; i++) {
    pinMode(pinNum[i], OUTPUT);
  }
  // Button Input
  pinMode(pushButton, INPUT);
  // initialize serial for debugging
  Serial.begin(9600);
  // initialize serial for ESP module
  EspSerial.begin(9600);
  // initialize ESP module
  WiFi.init(&EspSerial);                            // iptime 접속 초기화

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {                             // wifi 연결되면
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  // you're connected now, so print out the data
  Serial.println("You're connected to the network");

  printWifiStatus();                                            // wifi 관련 내용 출력 ssid, ip주소,

  Serial.println();
  Serial.println("Starting connection to server...");
  // if you get a connection, report back via serial
}

void loop()
{

  int buttonStateCurrent = digitalRead(pushButton);
  Serial.println("buttonState = " + String(buttonStateCurrent));
  if (buttonStateCurrent == 0) {
    // 불 밝히고
    for (int i = 0; i < 5; i++) {
      digitalWrite(pinNum[i], HIGH);
    }
    // 서버연결하고
    if (client.connect(server, 80)) {
      Serial.println("Connected to server");
      // Make a HTTP request
      client.println("GET /a.php?a=11&b=22 HTTP/1.1");
      client.println("Host: jteks5.dothome.co.kr");
      client.println("Connection: close");
      client.println();
    }
    // if there are incoming bytes available
    // from the server, read them and print them
    while (client.available()) {
      char c = client.read();
      Serial.write(c);
    }

    // if the server's disconnected, stop the client
    if (!client.connected()) {
      Serial.println();
      Serial.println("Disconnecting from server...");
      client.stop();
    }
  }
  else {
    if (time + 500 < millis() && sunbun == 1) {
      time = millis();
      sunbun = 2;
      digitalWrite(pinNum[0], HIGH);
      digitalWrite(pinNum[1], LOW);
      digitalWrite(pinNum[2], LOW);
      digitalWrite(pinNum[3], LOW);
      digitalWrite(pinNum[4], LOW);
    }
    if (time + 500 < millis() && sunbun == 2) {
      time = millis();
      sunbun = 3;
      digitalWrite(pinNum[0], LOW);
      digitalWrite(pinNum[1], HIGH);
      digitalWrite(pinNum[2], LOW);
      digitalWrite(pinNum[3], LOW);
      digitalWrite(pinNum[4], LOW);
    }
    if (time + 500 < millis() && sunbun == 3) {
      time = millis();
      sunbun = 4;
      digitalWrite(pinNum[0], LOW);
      digitalWrite(pinNum[1], LOW);
      digitalWrite(pinNum[2], HIGH);
      digitalWrite(pinNum[3], LOW);
      digitalWrite(pinNum[4], LOW);
    }
    if (time + 500 < millis() && sunbun == 4) {
      time = millis();
      sunbun = 5;
      digitalWrite(pinNum[0], LOW);
      digitalWrite(pinNum[1], LOW);
      digitalWrite(pinNum[2], LOW);
      digitalWrite(pinNum[3], HIGH);
      digitalWrite(pinNum[4], LOW);
    }
    if (time + 500 < millis() && sunbun == 5) {
      time = millis();
      sunbun = 1;
      digitalWrite(pinNum[0], LOW);
      digitalWrite(pinNum[1], LOW);
      digitalWrite(pinNum[2], LOW);
      digitalWrite(pinNum[3], LOW);
      digitalWrite(pinNum[4], HIGH);
    }
  }
  delay(200);
}


void printWifiStatus()
{
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
