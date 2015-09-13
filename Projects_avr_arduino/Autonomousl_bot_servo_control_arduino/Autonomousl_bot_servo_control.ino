#include <Servo.h> 
 
Servo servo_left_middle;
Servo servo_right_middle; 
Servo servo_right_arm;
Servo servo_left_arm;

char t;

void setup() {
  
  servo_left_middle.attach(9);
  servo_right_middle.attach(10);
  servo_right_arm.attach(11);
  servo_left_arm.attach(13);
  
  Serial.begin(4800);
  
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
 
}

void loop() {
  
  if (Serial.available() > 0) {
     // get incoming byte:
    t = Serial.read();
    Serial.print(t);
  }
}



void start(){ 
    digitalWrite(8,HIGH);
    digitalWrite(12,LOW);
    servo_left_middle.write(50);
    servo_right_middle.write(130);
    servo_right_arm.write(120);
    servo_left_arm.write(40);
    delay(3000);
    servo_left_middle.write(90);
    servo_right_middle.write(90);
    delay(2500);
  }
  
void grap_block(){
    servo_right_arm.write(85);
    servo_left_arm.write(65);
  }
  
void release_block(){
  servo_right_arm.write(120);
  servo_left_arm.write(40);
}

void grap_n_raise(){
  delay(500);
  digitalWrite(8,HIGH);
  digitalWrite(12,HIGH);
  grap_block();
  delay(500);
  servo_left_middle.write(70);
  servo_right_middle.write(110);
  digitalWrite(8,HIGH);
  digitalWrite(12,LOW);
  delay(14000);
  digitalWrite(8,HIGH);
  digitalWrite(12,HIGH);
  delay(500);
}


void place_at_platform(){
  delay(500);
  servo_left_middle.write(150);
  servo_right_middle.write(30);
  delay(600);
  release_block();
  digitalWrite(8,HIGH);
  digitalWrite(12,HIGH);
  delay(500);
}

void hold_on_arm(){

  delay(500);
  servo_left_middle.write(70);
  servo_right_middle.write(110);
  delay(600);
  grap_block();
  digitalWrite(8,HIGH);
  digitalWrite(12,HIGH);
  delay(500);
  
}

void lowering_the_block(){

  delay(500);
  servo_left_middle.write(70);
  servo_right_middle.write(110);
  digitalWrite(8,LOW);
  digitalWrite(12,HIGH);
  delay(14000);
  digitalWrite(8,HIGH);
  digitalWrite(12,HIGH);
  delay(500);
  servo_left_middle.write(90);
  servo_right_middle.write(90);
    delay(500);
}
