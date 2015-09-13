

#include <Servo.h> 
#include <Keypad.h>
 
Servo servo_middle;  
Servo servo_right_arm;
Servo servo_left_arm;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'e','c','i','a'},
  {'f','d','f','b'},
  {'=','=','=','='},
  {'g','B','C','i'}
};
byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


//Output
//movement control
int motor_left_positive=A0;
int motor_left_negative=A1;
int motor_right_positive=A2;
int motor_right_negative=A3;

int canon_positive=A4;
int canon_negative=A5;

//Input


int pos = 0;    // variable to store the servo position 

char t;
 
void setup() 
{ 
  Serial.begin(9600);
  servo_middle.attach(9);
  servo_right_arm.attach(10);
  servo_left_arm.attach(11);
  
  pinMode(motor_left_positive,OUTPUT);
  pinMode(motor_left_negative,OUTPUT);
  pinMode(motor_right_positive,OUTPUT);
  pinMode(motor_right_negative,OUTPUT);
  
  pinMode(canon_positive,OUTPUT);
  pinMode(canon_negative,OUTPUT);
  
  
  
  
  //setting initial gripper movement
  servo_middle.write(180);
  servo_right_arm.write(130);
  servo_left_arm.write(55);
  
  
} 
 
 
void loop() {
 // if (Serial.available() > 0)
{
   t = customKeypad.getKey();//Serial.read();
  switch(t){
      
      case 'a':
            //Left Forward
            digitalWrite(motor_left_positive, HIGH);
            digitalWrite(motor_left_negative, LOW);
            Serial.println("Left Forward");
      break;
      
      case 'b':
            //Left Backward
            digitalWrite(motor_left_positive, LOW);
            digitalWrite(motor_left_negative, HIGH);
            Serial.println("Left Backward");
      break;
      
      case 'c':
            //Right Forward
            digitalWrite(motor_right_positive, HIGH);
            digitalWrite(motor_right_negative, LOW);
            Serial.println("Right Forward");
      break;
      
      case 'd':
            //Right Backward
            digitalWrite(motor_right_positive, LOW);
            digitalWrite(motor_right_negative, HIGH);
            Serial.println("Right Backward");
      break;
      
      case 'e':
            //Gripper lowered and open
            servo_middle.write(180);
            servo_right_arm.write(130);
            servo_left_arm.write(55);
            Serial.println("Gripper lowered and open");
      break;
      
      case 'f':
            //Gripper lowered and closed
            servo_middle.write(180);
            servo_right_arm.write(80);
            servo_left_arm.write(102);
            Serial.println("Gripper lowered and closed");
      break;
      
      case 'g':
              //Gripper Rasised and closed
              servo_middle.write(0);
              servo_right_arm.write(78);
              servo_left_arm.write(102);
              Serial.println("Gripper Rasised and closed");
      break;
      
      case 'h':
            //Cannon activated
            digitalWrite(canon_positive, HIGH);
            digitalWrite(canon_negative, LOW);
            Serial.println("Cannon activated");
      break;
      
      case 'i':
        digitalWrite(motor_left_positive, HIGH);
            digitalWrite(motor_left_negative, HIGH);
                        digitalWrite(motor_right_positive,HIGH );
                        digitalWrite(motor_right_negative, HIGH);
      break;
      /*default:
              Serial.println("Invalid Input");
      break;*/
      
    }
  }
} 
