 /*
 * LFR_mk7.c
 *
 * Created: 1/12/2014 12:53:56 AM
 *  Author: Delta
 *	Super fast LFR	
 *	PA0=EXTREME RIGHT
 *	PA1=RIGHT
 *	PA2=MIDDLE
 *	PA3=LEFT
 *	PA4=EXTREME LEFT
 *  PCO=RIGHT -VE MOTOR
 *  PC1=RIGHT +VE MOTOR
 *  PC2=LEFT -VE MOTOR
 *  PC3=LEFT +VE MOTOR
 *  PD4=RIGHT MOTOR ENABLE
 *  PD5=LEFT MOTOR ENABLE
*/



#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "motor.h"


int main(void)
{

    /*TCCR1A=0xA1;
	TCCR1B=0x05;
	
	
	
	OCR1A=150;				//Left Motor PWM
	OCR1B=150;				//Right Motor PWM
	
	DDRD=0x30;				//Declaring PD4,PD5 as output*/
	
	
	DDRA=0X00;				//Sensor Input
	PORTA=0X07;
	
	DDRB=0x0F;
	

    while(1)
    {
	  switch(PINA & 0X07)
	  {
		case 0x00: //0
		{
			left();
		}
		break;
		
		case 0x01: //1
		{
			left();
		}
		break;
		
		case 0x02: //2
		{
			straight();
		}
		break;
		
		case 0x03: //3
		{
			left();
		}
		break;
		
		
		case 0x04: //4
		{
			right();
		}
		break;
		
		case 0x05: //5
		{
			straight();
		}
		break;
		
		case 0x06: //6
		{
			right();
		}
		break;
		
		case 0x07: //7
		{
			u_turn();
		}
		break; 
		}
    }


    return 0;
}