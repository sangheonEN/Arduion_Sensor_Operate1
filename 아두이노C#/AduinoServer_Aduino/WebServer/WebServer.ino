#include "WiFiEsp.h"
#include <RingBuf.h>


// Emulate EspSerial on pins 6/7 if not present
#ifndef HAVE_HWEspSerial
#include "SoftwareSerial.h"
  SoftwareSerial EspSerial(2, 3); // RX, TX
#endif

// 아두이노 server 도 되면서 client 된다.

char connec_server[] = "dron512.dothome.co.kr";

char ssid[] = "iptime";            // your network SSID (name)
char pass[] = "";        // your network password

int status = WL_IDLE_STATUS;     // the Wifi radio's status
int reqCount = 0;                // number of requests received

WiFiEspServer server(80);
RingBuffer buf(8);

// Initialize the Ethernet client object
WiFiEspClient client; //iptime 연결 하기 위한 클래스

int mypin11 = 11; int mypin10 = 10; int mypin9 = 9; int mypin6 = 6; int mypin5 = 5;

void setup()
{
  pinMode(mypin11, OUTPUT);  // initialize digital pin mypin as an output.
  pinMode(mypin10, OUTPUT); // initialize digital pin mypin as an output.
  pinMode(mypin9, OUTPUT);  // initialize digital pin mypin as an output.
  pinMode(mypin6, OUTPUT);  // initialize digital pin mypin as an output.
  pinMode(mypin5, OUTPUT);  // initialize digital pin mypin as an output.
  
  // initialize serial for debugging
  Serial.begin(9600);
  // initialize serial for ESP module
  EspSerial.begin(9600);
  
  // initialize ESP module 
  WiFi.init(&EspSerial);  // iptime 접속 해서 인터넷 되게해라

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");
  printWifiStatus();
  
  // start the web server on port 80
  server.begin();

  /* 
  -- dron512.dothome.co.kr 서버로 접속 시작
  if (client.connect(connec_server, 80)) {
    Serial.println("Connected to server");
    // Make a HTTP request
    client.println("GET /a.php?a=33&b=44 HTTP/1.1");
    client.println("Host: dron512.dothome.co.kr");
    client.println("Connection: close");
    client.println("aa"); // println 서버로 보내는거 send
    client.flush();
  }
  while (client.available()) {
    char c = client.read(); //client.read 서버로부터 받는거
    Serial.write(c);
  }
  if (!client.connected()) {
    Serial.println();
    Serial.println("Disconnecting from server...");
    client.stop();   
  }
  -- dron512.dothome.co.kr 서버로 접속 끝
  */ 
}


void loop()
{
  
  
  // 서버가 클라이언트 기다림
  WiFiEspClient client = server.available();
  if (client) {
    Serial.println("New client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    
    RingBuf<char, 10> myBuffer;
    while (client.connected()) {  
      if (client.available()) {
        char c = client.read();
        buf.push(c);
        myBuffer.push(c);    
        
        if (c == '\n' && currentLineIsBlank) {
          Serial.print("myBuffer[myBuffer.size()-5]");
          Serial.println(myBuffer[myBuffer.size()-5]);
          Serial.print("myBuffer[myBuffer.size()-4]");
          Serial.println(myBuffer[myBuffer.size()-4]);          
          Serial.print("myBuffer[myBuffer.size()-3]");
          Serial.println(myBuffer[myBuffer.size()-3]);
          Serial.print("myBuffer[myBuffer.size()-2]");
          Serial.println(myBuffer[myBuffer.size()-2]);
          Serial.print("myBuffer[myBuffer.size()-1]");
          Serial.println(myBuffer[myBuffer.size()-1]);

        if ((myBuffer[myBuffer.size()-5]=='1') && (myBuffer[myBuffer.size()-4]=='1')) {
          int cnt = 0;
          // 아스키코드 값이 32가 빈공백
          // 아스키코드 값이 49가 1
          if( myBuffer[myBuffer.size()-1] == 32)
          {
            cnt = myBuffer[myBuffer.size()-2]-48;
          }
          else
          {
            cnt = (myBuffer[myBuffer.size()-2]-48)*10 + myBuffer[myBuffer.size()-1]-48;
          } 
          Serial.println("cnt = "+String(cnt));
          
          while(cnt>0){
            digitalWrite(mypin11, HIGH);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
            delay(500);
            cnt--;
            digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
            delay(500);
          }  
        }
        if ((myBuffer[myBuffer.size()-5]=='1') && (myBuffer[myBuffer.size()-4]=='0') ) {
          int cnt = 0;
          // 아스키코드 값이 32가 빈공백
          // 아스키코드 값이 49가 1
          if( myBuffer[myBuffer.size()-1] == 32)
          {
            cnt = myBuffer[myBuffer.size()-2]-48;
          }
          else
          {
            cnt = (myBuffer[myBuffer.size()-2]-48)*10 + myBuffer[myBuffer.size()-1]-48;
          } 
          Serial.println("cnt = "+String(cnt));
          
          while(cnt>0){
            digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin10, HIGH);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
            delay(500);
            cnt--;
            digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
            delay(500);
          }  
        }
        if ( (myBuffer[myBuffer.size()-5]=='9') ) {
          int cnt = 0;
          // 아스키코드 값이 32가 빈공백
          // 아스키코드 값이 49가 1
          if( myBuffer[myBuffer.size()-2] == 32)
          {
            cnt = myBuffer[myBuffer.size()-3]-48;
          }
          else
          {
            cnt = (myBuffer[myBuffer.size()-3]-48)*10 + myBuffer[myBuffer.size()-2]-48;
          } 
          Serial.println("cnt = "+String(cnt));
          
          while(cnt>0){
            digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin9, HIGH);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
            delay(500);
            cnt--;
            digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
            delay(500);
          }
        }
        if ((myBuffer[myBuffer.size()-5]=='6') ) {
          int cnt = 0;
          // 아스키코드 값이 32가 빈공백
          // 아스키코드 값이 49가 1
          if( myBuffer[myBuffer.size()-2] == 32)
          {
            cnt = myBuffer[myBuffer.size()-3]-48;
          }
          else
          {
            cnt = (myBuffer[myBuffer.size()-3]-48)*10 + myBuffer[myBuffer.size()-2]-48;
          } 
          Serial.println("cnt = "+String(cnt));
          
          while(cnt>0){
            digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin6, HIGH);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
            delay(500);
            cnt--;
            digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
            delay(500);
          }
        }
        if ((myBuffer[myBuffer.size()-5]=='5') ) {
          int cnt = 0;
          // 아스키코드 값이 32가 빈공백
          // 아스키코드 값이 49가 1
          if( myBuffer[myBuffer.size()-2] == 32)
          {
            cnt = myBuffer[myBuffer.size()-3]-48;
          }
          else
          {
            cnt = (myBuffer[myBuffer.size()-3]-48)*10 + myBuffer[myBuffer.size()-2]-48;
          } 
          Serial.println("cnt = "+String(cnt));
          while(cnt>0){
            digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin5, HIGH);   // turn the LED on (HIGH is the voltage level)
            delay(500);
            cnt--;
            digitalWrite(mypin11, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin10, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin9, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin6, LOW);   // turn the LED on (HIGH is the voltage level)
            digitalWrite(mypin5, LOW);   // turn the LED on (HIGH is the voltage level)
            delay(500);
          }
        }
          
          
          Serial.println("Sending response");
          
          // send a standard http response header
          // use \r\n instead of many println statements to speedup data send
          client.print(
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Connection: close\r\n"  // the connection will be closed after completion of the response
            "Refresh: 20\r\n"        // refresh the page automatically every 20 sec
            "\r\n");
          client.print("<!DOCTYPE HTML>\r\n");
          client.print("<html>\r\n");
          client.print("<h1>Hello World!</h1>\r\n");
          client.print("AAAAAAAAAAAAAAAAAA");
          client.print("Requests received: ");
          client.print(++reqCount);
          client.print("<br>\r\n");
          client.print("Analog input A0: ");
          client.print(analogRead(0));
          client.print("<br>\r\n");
          client.print("</html>\r\n");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
         
        }
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(10);

    // close the connection:
    client.stop();
    Serial.println("Client disconnected");
  }
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
