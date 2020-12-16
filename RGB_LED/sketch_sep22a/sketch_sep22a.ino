
int redP = 5;
int blueP = 6;
int greenP = 3;

void setup() {
  Serial.begin(9600);
  pinMode(redP, OUTPUT);
  pinMode(blueP, OUTPUT);
  pinMode(greenP, OUTPUT);

  digitalWrite(redP, 0);
  digitalWrite(blueP, 0);
  digitalWrite(greenP, 0);
}

void loop() {
  while(Serial.available() > 0)
  {
    int red = Serial.parseInt();
    int blue = Serial.parseInt();
    int green = Serial.parseInt();
  

  if(Serial.read() == '\n')
  {
    red = 255 - constrain(red, 0, 255);
    blue = 255 - constrain(blue, 0, 255);
    green = 255 - constrain(green, 0, 255);

    analogWrite(redP, red);
    analogWrite(blueP, blue);
    analogWrite(greenP, green);

    Serial.print("Red : " + String(255 - red));
    Serial.print(", Blue : " + String(255 - blue));
    Serial.println(", Green : " + String(255 - green));
  }
 }
}
