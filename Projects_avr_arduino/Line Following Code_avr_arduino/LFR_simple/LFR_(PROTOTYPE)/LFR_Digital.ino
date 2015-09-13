// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// make some custom characters:
byte state1[8] = { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F };
byte state0[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };


int sensor1 = A2;      // Right Sensor
int sensor2 = A1;      // Middle sensor
int sensor3 = A0;      // Left sensor

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
 

  if(sen1==LOW && sen2==LOW && sen3==LOW)//1
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(2);
    lcd.write(2);
    Serial.println(0);
    /*digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);*/
  }
  else if(sen1==LOW && sen2==LOW && sen3==HIGH)//2
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(2);
    lcd.write(1);
    Serial.println(1);
    /*digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);*/
  }
  else if(sen1==LOW && sen2==HIGH && sen3==LOW)//3
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(1);
    lcd.write(2);
    delay(1);
    Serial.println(2);
    /*digitalWrite(motor1, HIGH);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, HIGH);*/
  }
  else if(sen1==LOW && sen2==HIGH && sen3==HIGH)//4
  {
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(1);;
    lcd.write(1);
     delay(1);
    Serial.println(3);
   /* digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);*/
  }
  else if(sen1==HIGH && sen2==LOW && sen3==LOW)//5
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(2);
    lcd.write(2);
     delay(1);
    Serial.println(4);
    /*digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);*/
  }
  else if(sen1==HIGH && sen2==LOW && sen3==HIGH)//6
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(2);
    lcd.write(1);
     delay(1);
    Serial.println(5);
    /*digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);*/
  }
  else if(sen1==HIGH && sen2==HIGH && sen3==LOW)//7
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(1);
    lcd.write(2);
     delay(1);
    Serial.println(6);
   /* digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);*/
  }
  else if(sen1==HIGH && sen2==HIGH && sen3==HIGH)//8
  {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.write(1);
    lcd.write(1);
     delay(1);
    Serial.println(7);
    /*digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);*/
  }
}

