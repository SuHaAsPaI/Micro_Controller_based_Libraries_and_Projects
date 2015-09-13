#include <Servo.h> 
 
Servo servo_middle;  
Servo servo_right_arm;
Servo servo_left_arm;

void setup() {
  
  servo_middle.attach(9);
  servo_right_arm.attach(10);
  servo_left_arm.attach(11);

}

void loop() {
  servo_middle.write(180);
  servo_right_arm.write(130);
  servo_left_arm.write(55);
  delay(2500);
  servo_middle.write(180);
  servo_right_arm.write(80);
  servo_left_arm.write(102);
  delay(2500);
  servo_middle.write(0);
  servo_right_arm.write(80);
  servo_left_arm.write(102);
  delay(2500);
  servo_middle.write(180);
  servo_right_arm.write(80);
  servo_left_arm.write(102 );
  delay(2500); 
  
}
