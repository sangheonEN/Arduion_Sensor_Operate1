//setup()실행 후 loop() 실행
/*
 * 입력 
 * mode 1 : 
 * mode 2 : 
 */

int pinNumbers[] = {9, 10, 11, 12};
int selectNum = 1;
int flag = 0;

int time = millis();

void inputNumber(){
  if(Serial.available()>0)
  {
    selectNum = Serial.parseInt();
    Serial.println("selectNum = " + String(selectNum));
  }

  if(selectNum == 1)
  {
    Serial.println("1로가냐?");
    mode1();
  }
  else if(selectNum == 2)
  {
    Serial.println("2로가냐?");
    mode2();
  }
}

void mode1()
{
  if(time + 500 > millis() && flag == 0){
    time = millis();
    Serial.println("flag == 1");
    flag = 1;
    digitalWrite(pinNumbers[0], HIGH);
    digitalWrite(pinNumbers[2], HIGH);
    digitalWrite(pinNumbers[1], LOW);
    digitalWrite(pinNumbers[3], LOW);
  }
  else if(time + 500 > millis() && flag == 1){
    time = millis();
    Serial.println("flag == 0");
    flag = 0;
    digitalWrite(pinNumbers[1], HIGH);
    digitalWrite(pinNumbers[3], HIGH);
    digitalWrite(pinNumbers[0], LOW);
    digitalWrite(pinNumbers[2], LOW);
  }
}

void mode2()
{
  digitalWrite(pinNumbers[0], HIGH);
  digitalWrite(pinNumbers[1], LOW);
  digitalWrite(pinNumbers[2], LOW);
  digitalWrite(pinNumbers[3], LOW);

  delay(500);

  digitalWrite(pinNumbers[0], LOW);
  digitalWrite(pinNumbers[1], HIGH);
  digitalWrite(pinNumbers[2], LOW);
  digitalWrite(pinNumbers[3], LOW);

  delay(500);
  
  digitalWrite(pinNumbers[0], LOW);
  digitalWrite(pinNumbers[1], LOW);
  digitalWrite(pinNumbers[2], HIGH);
  digitalWrite(pinNumbers[3], LOW);

  delay(500);
  
  digitalWrite(pinNumbers[0], LOW);
  digitalWrite(pinNumbers[1], LOW);
  digitalWrite(pinNumbers[2], LOW);
  digitalWrite(pinNumbers[3], HIGH);
}


void setup() {
  Serial.begin(9600);
  for(int i = 0 ; i < 4; i++)
  {
      pinMode(pinNumbers[i], OUTPUT);
  }
}

void loop() {
  inputNumber();
  delay(500);
}
