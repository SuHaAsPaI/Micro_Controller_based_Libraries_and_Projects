/*
	Superfast LFR
	
	PA0=EXTREME RIGHT
	PA1=RIGHT
	PA2=MIDDLE
	PA3=LEFT
	PA4=EXTREME LEFT
*/

#include <avr/io.h>
#include "lcd118010.h"
#include "custom_char.h"
#include "lcd_bar.h"
#include "motor.h"
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 16000000UL

int main(void)
{

    TCCR1A=0xA1;
	TCCR1B=0x05;
	
	OCR1A=50;				//Left Motor PWM
	OCR1B=50;				//Right Motor PWM
	
	DDRD=0x30;				//Declaring PD4,PD5 as output
	
	int i;
	
	DDRA=0X00;				//Sensor Input
	PORTA=0X1F;
	
	lcd_init();
	
	lcd_cmd(0x40);
	{
		for(i=0;i<64;i++)
			{
				lcd_char(a[i]);
			}
	}

    while(1)
    {
	  switch(PINA & 0X1F)
	  {
		case 0x00: //0
		{
			lcdbar(0);
			slight_left();
		}
		break;
		
		case 0x01: //1
		{
			lcdbar(1);
			slight_right();
		}
		break;
		
		case 0x02: //2
		{
			lcdbar(2);
		}
		break;
		
		case 0x03: //3
		{
			lcdbar(3);
		}
		break;
		
		
		case 0x04: //4
		{
			lcdbar(4);
		}
		break;
		
		case 0x05: //5
		{
			lcdbar(5);
		}
		break;
		
		case 0x06: //6
		{
			lcdbar(6);
		}
		break;
		
		case 0x07: //7
		{
			lcdbar(7);
		}
		break;
		
		case 0x08: //8
		{
			lcdbar(8);
		}
		break;
		
		case 0x09: //9
		{
			lcdbar(9);
		}
		break;
		
		case 0x0A: //10
		{
			lcdbar(10);
		}
		break;
		
		case 0x0B: //11
		{
			lcdbar(11);
		}
		break;
		
		case 0x0C: //12
		{
			lcdbar(12);
		}
		break;
		
		case 0x0D: //13
		{
			lcdbar(13);
		}
		break;
		
		case 0x0E: //14
		{
			lcdbar(14);
		}
		break;
		
		case 0x0F: //15
		{
			lcdbar(15);
		}
		break;
		
		case 0x10: //16
		{
			lcdbar(16);
		}
		break;
		
		case 0x11: //17
		{
			lcdbar(17);
		}
		break;
		
		case 0x12: //18
		{
			lcdbar(18);
		}
		break;
		
		case 0x13: //19
		{
			lcdbar(19);
		}
		break;
		
		case 0x14: //20
		{
			lcdbar(20);
		}
		break;
		
		case 0x15: //21
		{
			lcdbar(21);
		}
		break;
		
		case 0x16: //22
		{
			lcdbar(22);
		}
		break;
		
		case 0x17: //23
		{
			lcdbar(23);
		}
		break;
		
		case 0x18: //24
		{
			lcdbar(24);
		}
		break;
		
		case 0x19: //25
		{
			lcdbar(25);
		}
		break;
		
		case 0x1A: //26
		{
			lcdbar(26);
		}
		break;
		
		case 0x1B: //27
		{
			lcdbar(27);
		}
		break;
		
		case 0x1C: //28
		{
			lcdbar(28);
		}
		break;
		
		case 0x1D: //29
		{
			lcdbar(29);
		}
		break;
		
		case 0x1E: //30
		{
			lcdbar(30);
		}
		break;
		
		case 0x1F: //31
		{
			lcdbar(31);
			straight();
		}
		break;
		
	
	  }	  
    }


    return 0;
}
