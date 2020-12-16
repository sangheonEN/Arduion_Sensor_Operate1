#include <DHT.h>

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int inputA0 = A0; int inputD2 = 2;
int pin6=5;int pin9=6;int pin11=9;int pin12=10;int pin13=11;
void setup() {
  dht.begin();
  
  Serial.begin(9600);
  pinMode(inputA0,INPUT);
  pinMode(inputD2,INPUT);
  pinMode(pin6,OUTPUT);pinMode(pin9,OUTPUT);pinMode(pin11,OUTPUT);pinMode(pin12,OUTPUT);pinMode(pin13,OUTPUT);
}

void loop() {
  float temperature = dht.readTemperature();  // 온도 가져오기
  float humidity = dht.readHumidity();  //습도 가져오기
  
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");
 
  if (isnan(humidity) || isnan(temperature) ) {
    Serial.println("DHT 센서 읽기 실패!");
    return;
  }
  
  int a0 = analogRead(inputD2);
  Serial.println("a0"+String(a0));
  
  // 110 ~ 140 1개
  // 141 ~ 170 2개
  // 171 ~ 200 3개
  // 201 ~ 250 4개
  // 250 5개

  if( 110 <a0 && a0< 140){
    digitalWrite(pin6,HIGH);
    digitalWrite(pin9,LOW);
    digitalWrite(pin11,LOW);
    digitalWrite(pin12,LOW);
    digitalWrite(pin13,LOW);
  }
  else if(140 <=a0 && a0< 170){
    digitalWrite(pin6,HIGH);
    digitalWrite(pin9,HIGH);
    digitalWrite(pin11,LOW);
    digitalWrite(pin12,LOW);
    digitalWrite(pin13,LOW);
  }
  else if(170 <=a0 && a0< 200){
    digitalWrite(pin6,HIGH);
    digitalWrite(pin9,HIGH);
    digitalWrite(pin11,HIGH);
    digitalWrite(pin12,LOW);
    digitalWrite(pin13,LOW);
  }
  else if(201 <=a0 && a0< 250){
    digitalWrite(pin6,HIGH);
    digitalWrite(pin9,HIGH);
    digitalWrite(pin11,HIGH);
    digitalWrite(pin12,HIGH);
    digitalWrite(pin13,LOW);
  }
  else if(250 <= a0){
    digitalWrite(pin6,HIGH);
    digitalWrite(pin9,HIGH);
    digitalWrite(pin11,HIGH);
    digitalWrite(pin12,HIGH);
    digitalWrite(pin13,HIGH);
  }

//  int a1 = analogRead(inputA1);
//  float voltage = a1 * 5 /1024;
//   
//  Serial.println("voltage = "+String(voltage));
//  // 섭씨온도
//  float tempeC = (voltage - 0.5) *100;
//  Serial.println(" 섭씨온도 = "+String(tempeC));
//  // 화씨 온도
//  float tempeF = (tempeC * 9.0 /5.0) + 32.0;
//  Serial.println(" 화씨온도 = "+String(tempeF));
  
  
  delay(10);
}
