#include <avr/io.h>

#include <util/delay.h>



int degree_to_pulse(int angle){

int min=550;//minimum pulse width us for 0 degree
int max=2400;//maximum pulse width us for 180 degree

int range=max-min;

//Range divided by servo max angle

float Mpd=range/180;//microseconds per degree Mpd

 int Servo_Angle =( (angle*Mpd) + min)/4;

  return Servo_Angle;

}



int main(void)
{
   //Configure TIMER1
   TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
   TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)

   ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).

   DDRD=0x30;
   PORTD=0x30;
   int i;

   while(1)
   {
	for(i=0;i<=180;i++){
      OCR1A=degree_to_pulse(i);
	  OCR1B=degree_to_pulse(i);
     _delay_ms(5);
	 }
	 _delay_ms(1000);
	 for(i=180;i>=0;i--){
	 OCR1A=degree_to_pulse(i);   //0 degree
	 OCR1B=degree_to_pulse(i);
     _delay_ms(5);
	 }
	 _delay_ms(1000);
	 
   }
}