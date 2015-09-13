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

    TCCR1A=0xA1;
	TCCR1B=0x05;
	
	
	
	OCR1A=150;				//Left Motor PWM
	OCR1B=150;				//Right Motor PWM
	
	DDRD=0x30;				//Declaring PD4,PD5 as output
	
	
	DDRA=0X00;				//Sensor Input
	PORTA=0X1F;
	
	DDRC=0x0F;
	

    while(1)
    {
	  switch(PINA & 0X1F)
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
			left();
		}
		break;
		
		case 0x03: //3
		{
			left();
		}
		break;
		
		
		case 0x04: //4
		{
			left();
		}
		break;
		
		case 0x05: //5
		{
			left();
		}
		break;
		
		case 0x06: //6
		{
			left();
		}
		break;
		
		case 0x07: //7
		{
			left();
		}
		break;
		
		case 0x08: //8
		{
			straight();
		}
		break;
		
		case 0x09: //9
		{
			straight();
		}
		break;
		
		case 0x0A: //10
		{
			straight();
		}
		break;
		
		case 0x0B: //11
		{
			straight();
		}
		break;
		
		case 0x0C: //12
		{
			right();
		}
		break;
		
		case 0x0D: //13
		{
			left();
		}
		break;
		
		case 0x0E: //14
		{
			left();
		}
		break;
		
		case 0x0F: //15
		{
			left();
		}
		break;
		
		case 0x10: //16
		{
			right();
		}
		break;
		
		case 0x11: //17
		{
			straight();
		}
		break;
		
		case 0x12: //18
		{
			left();
		}
		break;
		
		case 0x13: //19
		{
			straight();
		}
		break;
		
		case 0x14: //20
		{
			right();
		}
		break;
		
		case 0x15: //21
		{
			straight();
		}
		break;
		
		case 0x16: //22
		{
			right();
		}
		break;
		
		case 0x17: //23
		{
			left();
		}
		break;
		
		case 0x18: //24
		{
			right();
		}
		break;
		
		case 0x19: //25
		{
			straight();
		}
		break;
		
		case 0x1A: //26
		{
			straight();
		}
		break;
		
		case 0x1B: //27
		{
			straight();
		}
		break;
		
		case 0x1C: //28
		{
			right();
		}
		break;
		
		case 0x1D: //29
		{
			right();
		}
		break;
		
		case 0x1E: //30
		{
			right();
		}
		break;
		
		case 0x1F: //31
		{
			left();
		}
		break;
		
	
	  }	  
    }


    return 0;
}