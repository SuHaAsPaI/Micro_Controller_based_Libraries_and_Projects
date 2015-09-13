#include <LiquidCrystal.h>
#include <IRremote.h>

int RECV_PIN =13;
IRrecv irrecv(RECV_PIN);
decode_results results;
int a=0,b=0,c=0,d=0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup()
{
  Serial.begin(9600);
  pinMode(A0,OUTPUT);  // left +ve motor
  pinMode(A1,OUTPUT);  // left -ve motor
  pinMode(A2,OUTPUT);  // right +ve motor
  pinMode(A3,OUTPUT);  // right -ve motor
  pinMode(9,OUTPUT);
  lcd.begin(16, 2);
  
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  analogWrite(9, 100);
  if (irrecv.decode(&results))
{


  if(results.value==16718055)      // straight
    {
        Serial.println(results.value,HEX);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(results.value,HEX);
        lcd.setCursor(0,1);
        lcd.print("Turning Straight");
        a++;
        {
         if(a<=1)
           {
              digitalWrite(A0,HIGH);
              digitalWrite(A1,LOW);
              digitalWrite(A2,HIGH);
              digitalWrite(A3,LOW);
           }
         else
           {
             digitalWrite(A0,LOW);
             digitalWrite(A1,LOW);
             digitalWrite(A2,LOW);
             digitalWrite(A3,LOW);
              a=0;
           }

         }
   }


  else if(results.value==16716015)
    {
      Serial.println(results.value,HEX);    // LEFT
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(results.value,HEX);
      lcd.setCursor(0,1);
        lcd.print("Turning Left");
       b++;
    {
      if(b<=1)
        {
          digitalWrite(A0,LOW);
          digitalWrite(A1,HIGH);
          digitalWrite(A2,HIGH);
          digitalWrite(A3,LOW);
        }
      else
        {
          digitalWrite(A0,LOW);
          digitalWrite(A1,LOW);
          digitalWrite(A2,LOW);
          digitalWrite(A3,LOW);
          b=0;
        }

    }
}

  else if(results.value==16734885)    // RIGHT
    {
      Serial.println(results.value,HEX);
      lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(results.value,HEX);
        lcd.setCursor(0,1);
        lcd.print("Turning Right");
      c++;
    {
        if(c<=1)
          {
            digitalWrite(A0,HIGH);
            digitalWrite(A1,LOW);
            digitalWrite(A2,LOW);
            digitalWrite(A3,HIGH);
          }
        else
          {
            digitalWrite(A0,LOW);
            digitalWrite(A1,LOW);
            digitalWrite(A2,LOW);
            digitalWrite(A3,LOW);
            c=0;
           }

    }
}

   else if(results.value==16730805)    // BACKWARD
    {
        Serial.println(results.value,HEX);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(results.value,HEX);
        lcd.setCursor(0,1);
        lcd.print("Turning Back");
        d++;
        {
        if(d<=1)
          {
            digitalWrite(A0,LOW);
            digitalWrite(A1,HIGH);
            digitalWrite(A2,LOW);
            digitalWrite(A3,HIGH);
          }
          else
           {
            digitalWrite(A0,LOW);
            digitalWrite(A1,LOW);
            digitalWrite(A2,LOW);
            digitalWrite(A3,LOW);
            d=0;
           }

        }
}

irrecv.resume(); // Receive the next value
}
}
