/*
 * Bluetooth_ctrl_technolite.c
 *
 * Created: 6/25/2014 3:42:08 PM
 *  Author: Suhaas
 */ 
#define F_CPU 12000000

#include <avr/io.h>
#include <util/delay.h>
#include "UART_routines.h"
#include "UART_routines.c"
#include <avr/interrupt.h>

char temp,temp1;
 void init_times()
 {
	 TCCR1A=0XA0;
	 TCCR1B=0X13;
	 ICR1=1250;
 }
 
 /*ISR(INT0_vect)
 {
	OCR1A=OCR1B=1250;
	PORTD=0x60;
	_delay_ms(400); 
 }


ISR(INT1_vect)
{
	OCR1A=OCR1B=1250;
	PORTD=0x60;
	_delay_ms(300); 
	
}*/
/* #define Bluetooth_ON PORTD|=(1<<PD7)
#define Bluetooth_OFF PORTD&=~(1<<PD7)
*/
 
int main(void)
{
	cli();
	
	uart1_init();
	init_times();
	
	DDRD=0Xf0;
	DDRC=0X00;
	DDRB=0XFF;
	//Bluetooth_ON;
	_delay_ms(100);
	//MCUCR=0X00;
	//GICR=0b11000000;
	sei();
    while(1)
    {
		//PORTD=0x00;
        //TODO:: Please write your application code 
		temp=receiveByte();
		switch(temp){
			case 'W': PORTD=0x90 ;
						OCR1A=OCR1B=1250;
					  break;
			case 'X': PORTD=0x60 ;
					OCR1A=OCR1B=1250;
					  break;
			case 'A': PORTD=0xA0;
						OCR1A=OCR1B=700;
					  break;
			case 'D': PORTD=0x50 ;
					OCR1A=OCR1B=700;
					  break;
			case 'S': PORTD=0x00 ;
					  break;
			case 'Q': PORTD=0b10000000;
					  OCR1A=OCR1B=700;
					  break;
			case 'Z': PORTD=0b01000000 ;
					  break;
					  
		case 'E': PORTD=0b00010000;
					  OCR1A=OCR1B=700;
					  break;
					  case 'C': PORTD=0b00100000 ;
					  break;
		}	
		
    }
}