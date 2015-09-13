// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// make some custom characters:
byte state1[8] = { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F };
byte state0[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };


int sensor1 = A4;      // Extreme Right Sensor
int sensor2 = A3;      // Right Sensor
int sensor3 = A2;      // Middle sensor
int sensor4 = A1;      // Left sensor
int sensor5 = A0;      // Extreme Left sensor

int motor1 = 8;      // Right +ve terminal of motor
int motor2 = 9;      // Right -ve terminal of motor
int motor3 = 10;     // Left +ve terminal of motor
int motor4 = 11;     // Left -ve terminal of motor

void setup()
{
  // create a new character
  lcd.createChar(1, state1); 
  // create a new character
  lcd.createChar(2, state0);
  // set up the lcd's number of columns and rows: 
  lcd.begin(16, 2);
  // set the cursor to the first row, 0th position:

  
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);
  pinMode(sensor5,INPUT);

  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  int sen1=digitalRead(sensor1);
  int sen2=digitalRead(sensor2);
  int sen3=digitalRead(sensor3);
  int sen4=digitalRead(sensor4);
  int sen5=digitalRead(sensor5);
 

  if(sen5==LOW && sen4==LOW && sen3==LOW && sen2==LOW && sen1==LOW)//0
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    Serial.println(0);
  }
  else if(sen5==LOW && sen4==LOW && sen3==LOW && sen2==LOW && sen1==HIGH)//1
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    lcd.write(1);
    Serial.println(1);
  }
  else if(sen5==LOW && sen4==LOW && sen3==LOW && sen2==HIGH && sen1==LOW)//2
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    Serial.println(2);
  }
  else if(sen5==LOW && sen4==LOW && sen3==LOW && sen2==HIGH && sen1==HIGH)//3
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    lcd.write(1);
    lcd.write(1);
    Serial.println(3);
  }
  else if(sen5==LOW && sen4==LOW && sen3==HIGH && sen2==LOW && sen1==LOW)//4
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    lcd.write(2);
    Serial.println(4);
  }
  else if(sen5==LOW && sen4==LOW && sen3==HIGH && sen2==LOW && sen1==HIGH)//5
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
    Serial.println(5);
  }
  else if(sen5==LOW && sen4==LOW && sen3==HIGH && sen2==HIGH && sen1==LOW)//6
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(2);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
    Serial.println(6);
  }
  else if(sen5==LOW && sen4==LOW && sen3==HIGH && sen2==HIGH && sen1==HIGH)//7
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(2);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    Serial.println(7);
  }
   else if(sen5==LOW && sen4==HIGH && sen3==LOW && sen2==LOW && sen1==LOW)//8
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    Serial.println(8);
  }
  else if(sen5==LOW && sen4==HIGH && sen3==LOW && sen2==LOW && sen1==HIGH)//9
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    lcd.write(2);
    lcd.write(1);
    Serial.println(9);
  }
  else if(sen5==LOW && sen4==HIGH && sen3==LOW && sen2==HIGH && sen1==LOW)//10
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    Serial.println(10);
  }
  else if(sen5==LOW && sen4==HIGH && sen3==LOW && sen2==HIGH && sen1==HIGH)//11
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
    lcd.write(1);
    Serial.println(11);
  }
  else if(sen5==LOW && sen4==HIGH && sen3==HIGH && sen2==LOW && sen1==LOW)//12
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
    lcd.write(2);
    Serial.println(12);
  }
  else if(sen5==LOW && sen4==HIGH && sen3==HIGH && sen2==LOW && sen1==HIGH)//13
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
    Serial.println(13);
  }
  else if(sen5==LOW && sen4==HIGH && sen3==HIGH && sen2==HIGH && sen1==LOW)//14
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
    Serial.println(14);
  }
  else if(sen5==LOW && sen4==HIGH && sen3==HIGH && sen2==HIGH && sen1==HIGH)//15
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    Serial.println(15);
  }
  else if(sen5==HIGH && sen4==LOW && sen3==LOW && sen2==LOW && sen1==LOW)//16
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    Serial.println(16);
  }
  else if(sen5==HIGH && sen4==LOW && sen3==LOW && sen2==LOW && sen1==HIGH)//17
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    lcd.write(1);
    Serial.println(17);
  }
  else if(sen5==HIGH && sen4==LOW && sen3==LOW && sen2==HIGH && sen1==LOW)//18
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(2);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    Serial.println(18);
  }
  else if(sen5==HIGH && sen4==LOW && sen3==LOW && sen2==HIGH && sen1==HIGH)//19
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(2);;
    lcd.write(2);
    lcd.write(1);
    lcd.write(1);
    Serial.println(19);
  }
  else if(sen5==HIGH && sen4==LOW && sen3==HIGH && sen2==LOW && sen1==LOW)//20
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    lcd.write(2);
    Serial.println(20);
  }
  else if(sen5==HIGH && sen4==LOW && sen3==HIGH && sen2==LOW && sen1==HIGH)//21
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
    Serial.println(21);
  }
  else if(sen5==HIGH && sen4==LOW && sen3==HIGH && sen2==HIGH && sen1==LOW)//22
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
    Serial.println(22);
  }
  else if(sen5==HIGH && sen4==LOW && sen3==HIGH && sen2==HIGH && sen1==HIGH)//23
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    Serial.println(23);
  }
   else if(sen5==HIGH && sen4==HIGH && sen3==LOW && sen2==LOW && sen1==LOW)//24
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    Serial.println(24);
  }
  else if(sen5==HIGH && sen4==HIGH && sen3==LOW && sen2==LOW && sen1==HIGH)//25
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
    lcd.write(2);
    lcd.write(1);
    Serial.println(25);
  }
  else if(sen5==HIGH && sen4==HIGH && sen3==LOW && sen2==HIGH && sen1==LOW)//26
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    Serial.println(26);
  }
  else if(sen5==HIGH && sen4==HIGH && sen3==LOW && sen2==HIGH && sen1==HIGH)//27
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
    lcd.write(1);
    Serial.println(27);
  }
  else if(sen5==HIGH && sen4==HIGH && sen3==HIGH && sen2==LOW && sen1==LOW)//28
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
    lcd.write(2);
    Serial.println(28);
  }
  else if(sen5==HIGH && sen4==HIGH && sen3==HIGH && sen2==LOW && sen1==HIGH)//29
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
    Serial.println(29);
  }
  else if(sen5==HIGH && sen4==HIGH && sen3==HIGH && sen2==HIGH && sen1==LOW)//30
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
    Serial.println(30);
  }
  else if(sen5==HIGH && sen4==HIGH && sen3==HIGH && sen2==HIGH && sen1==HIGH)//31
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
    Serial.println(31);
  }
}

