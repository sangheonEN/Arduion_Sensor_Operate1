// the setup function runs once when you press reset or power the board
int led13 = 13;
int led12 = 12;
int led11 = 11;
#define BUTTON 6
int flag = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);            // 시리얼 모니터 serial 콘솔창을 이용하겠다.
  pinMode(led13, OUTPUT);            
  pinMode(led12, OUTPUT);       
  pinMode(led11, OUTPUT);       
  pinMode(BUTTON, INPUT);
}                                    // pinMode(신호 내보낼 번호, OUTPUT)

// the loop function runs over and over again forever
void loop() {
  //Serial.println("led 13번 출력");
  //led_function(led13);
  //Serial.println("led 12번 출력");
  //led_function(led12);
  //Serial.println("led 11번 출력");
  //led_function(led11);
  Serial.println("버튼");
  Button_Fuction(BUTTON, led13, led12, led11);
  
}

void led_function(int pin_num)
{
  digitalWrite(pin_num, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(pin_num, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second
}

void Button_Fuction(int BUTTON_NUM, int pin_num, int pin_num2, int pin_num3)
{
    if(digitalRead(BUTTON_NUM) == LOW){
    if(flag==0){
      digitalWrite(pin_num, HIGH);
      flag = 1;
    }
    else
    {
      digitalWrite(pin_num, LOW);
      flag =0;
    }
    }
    // pin 12
    if(digitalRead(BUTTON_NUM) == LOW){
    if(flag==0){
      digitalWrite(pin_num2, HIGH);
      flag = 1;
    }
    else
    {
      digitalWrite(pin_num2, LOW);
      flag =0;
    }
    }
    // pin 11
    if(digitalRead(BUTTON_NUM) == LOW){
    if(flag==0){
      digitalWrite(pin_num3, HIGH);
      flag = 1;
    }
    else
    {
      digitalWrite(pin_num3, LOW);
      flag =0;
    }
    while(digitalRead(BUTTON_NUM) == LOW);
 }
}
