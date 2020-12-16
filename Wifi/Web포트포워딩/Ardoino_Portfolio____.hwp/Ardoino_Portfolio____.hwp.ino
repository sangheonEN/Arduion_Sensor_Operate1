#include "WiFiEsp.h"

#ifndef HAVE_HWEspSerial
#include "SoftwareSerial.h"
SoftwareSerial EspSerial(2, 3); // RX, TX
#endif

char ssid[] = "iptime";            // your network SSID (name)
char pass[] = "";        // your network password
int status = WL_IDLE_STATUS;

int ledStatus = LOW;

int mypin11 = 11; int mypin10 = 10; int mypin9 = 9; int mypin6 = 6; int mypin5 = 5;

WiFiEspServer server(80);

// use a ring buffer to increase speed and reduce memory allocation
RingBuffer buf(8);

void setup()
{
  pinMode(mypin11, OUTPUT);  // initialize digital pin mypin as an output.
  pinMode(mypin10, OUTPUT);  // initialize digital pin mypin as an output.
  pinMode(mypin9, OUTPUT);  // initialize digital pin mypin as an output.
  pinMode(mypin6, OUTPUT);  // initialize digital pin mypin as an output.
  pinMode(mypin5, OUTPUT);  // initialize digital pin mypin as an output.

  Serial.begin(9600);   // initialize serial for debugging
  EspSerial.begin(9600);    // initialize serial for ESP module
  WiFi.init(&EspSerial);    // initialize ESP module

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");
  printWifiStatus();

  // start the web server on port 80
  server.begin();
}


void loop()
{
  WiFiEspClient client = server.available();  // listen for incoming clients

  if (client) {                               // if you get a client,
    Serial.println("New client");             // print a message out the serial port
    buf.init();                               // initialize the circular buffer
    while (client.connected()) {              // loop while the client's connected
      if (client.available()) {               // if there's bytes to read from the client,
        char c = client.read();               // read a byte, then
        buf.push(c);                          // push it to the ring buffer

        // printing the stream to the serial monitor will slow down
        // the receiving of data from the ESP filling the serial buffer
        //Serial.write(c);

        // you got two newline characters in a row
        // that's the end of the HTTP request, so send a response
        if (buf.endsWith("\r\n\r\n")) {
          sendHttpResponse(client);
          break;
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (buf.endsWith("GET /H")) {
          Serial.println("Turn led ON");
          ledStatus = HIGH;
          digitalWrite(mypin11, HIGH);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin10, HIGH);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin9, HIGH);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin6, HIGH);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin5, HIGH);   // turn the LED on (HIGH is the voltage level)
        }
        else if (buf.endsWith("GET /L")) {
          Serial.println("Turn led OFF");
          ledStatus = LOW;
          digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
        }
        else if (buf.endsWith("GET /11")) {
          Serial.println("Turn led ON");
          ledStatus = HIGH;
          digitalWrite(mypin11, HIGH);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
        }
        else if (buf.endsWith("GET /10")) {
          Serial.println("Turn led ON");
          ledStatus = HIGH;
          digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin10, HIGH);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
        }
        else if (buf.endsWith("GET /9")) {
          Serial.println("Turn led ON");
          ledStatus = HIGH;
          digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin9, HIGH);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
        }
        else if (buf.endsWith("GET /6")) {
          Serial.println("Turn led ON");
          ledStatus = HIGH;
          digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin6, HIGH);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
        }
        else if (buf.endsWith("GET /5")) {
          Serial.println("Turn led ON");
          ledStatus = HIGH;
          digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
          digitalWrite(mypin5, HIGH);   // turn the LED on (HIGH is the voltage level)
        }
      }
    }

    // close the connection
    client.stop();
    Serial.println("Client disconnected");
  }
}


void sendHttpResponse(WiFiEspClient client)
{
  // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
  // and a content-type so the client knows what's coming, then a blank line:
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();

  // the content of the HTTP response follows the header:
  client.print("The LED is ");
  client.print(ledStatus);
  client.println("<br>");
  client.println("<br>");

  client.println("Click <a href=\"/H\">here</a> turn the LED on<br>");
  client.println("Click <a href=\"/L\">here</a> turn the LED off<br>");
  client.println("Click <a href=\"/11\">here</a> turn the LED on<br>");
  client.println("Click <a href=\"/10\">here</a> turn the LED on<br>");
  client.println("Click <a href=\"/9\">here</a> turn the LED on<br>");
  client.println("Click <a href=\"/6\">here</a> turn the LED on<br>");
  client.println("Click <a href=\"/5\">here</a> turn the LED on<br>");


  // The HTTP response ends with another blank line:
  client.println();
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

  // print where to go in the browser
  Serial.println();
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
  Serial.println();
}
