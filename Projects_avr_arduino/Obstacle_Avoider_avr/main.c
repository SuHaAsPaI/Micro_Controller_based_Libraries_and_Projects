/*
 * Bluetooth_ctrl_technolite.c
 *
 * Created: 6/25/2014 3:42:08 PM
 *  Author: Suhaas
 */ 
#define F_CPU 12000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

char temp,temp1;
 void init_times()
 {
	 TCCR1A=0XA0;
	 TCCR1B=0X13;
	 ICR1=1250;
 }
 
 ISR(INT0_vect)
 {
	OCR1A=OCR1B=700;
	PORTD=0xF0;
	main();
 }


ISR(INT1_vect)
{
	OCR1A=OCR1B=700;
	PORTD=0xF0;
}
 
 
int main(void)
{
	cli();
	
	init_times();
	
	DDRD=0XF0;
	DDRC=0X11;
	DDRB=0XFF;
	
	sei();//activate glabal interrupt
    GICR=0xC0;//select interrupt channel
    MCUCR=0x0A;//select nature of interrupt signal
	
	
    while(1)
    {
		//PORTD=0x00;
        //TODO:: Please write your application code 
			
		
    }
}