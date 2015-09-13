#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"

int main(void)
{
	adc_init();
	
	DDRD=0XFF;
	DDRB=0X0F;
	
	int i;
	
	while(1)
	{
		i=getdata(0x00);
	 
		
		if(i>=0 && i<=16)	//1
		{
			PORTD=0XFE;
			PORTB=0x0F;
		}
		else if(i>=17 && i<=32)	//2
		{
			PORTD=0XFC;
			PORTB=0x0F;
		}
		else if(i>=33 && i<=48)	//3
		{
			PORTD=0XF8;
			PORTB=0x0F;
		}
		else if(i>=49 && i<=64)	//4
		{
			PORTD=0XF0;
			PORTB=0x0F;
		}
		else if(i>=65 && i<=80)	//5
		{
			PORTD=0XE0;
			PORTB=0x0F;
		}
		else if(i>=81 && i<=96)	//6
		{
			PORTD=0XC0;
			PORTB=0x0F;
		}
		else if(i>=97 && i<=112)	//7
		{
			PORTD=0X80;
			PORTB=0x0F;
		}
		else if(i>=113 && i<=128)	//8
		{
			PORTD=0X00;
			PORTB=0x0F;
		}
		else if(i>=129 && i<=144)	//9
		{
			PORTD=0X00;
			PORTB=0x0E;
		}
		else if(i>=145 && i<=160)	//10
		{
			PORTD=0X00;
			PORTB=0x0C;
		}
		else if(i>=161 && i<=176)	//11
		{
	
			PORTD=0X00;
			PORTB=0x08;
		}
		else if(i>=177 && i<=255)	//12
		{
			PORTD=0X00;
			PORTB=0X00;
		}

	}
	
}