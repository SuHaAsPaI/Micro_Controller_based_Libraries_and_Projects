#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"
#include"uart.c"
int main(void)
{
	uart_init();
	DDRC=0x00;
	PORTC=0x00;
	
	while(1)
	{
		if((PINC & 0x03)==0x01)
		{
			transmitByte('a');
			_delay_ms(10);
			
		}
		else if((PINC & 0x03)==0x02)
		{
			transmitByte('b');
			_delay_ms(10);
			
		}
		
		
		
		
		
		if((PINC & 0x0C)==0x04)
		{
			transmitByte('c');
			_delay_ms(10);
			
		}
		else if((PINC & 0x0C)==0x08)
		{
			transmitByte('d');
			_delay_ms(10);
			
		}
		else if((PINC & 0x0C)==0x00)
		{
			transmitByte('e');
			_delay_ms(10);
			
		}
		
		
		if((PINC & 0x30)==0x20)
		{
			transmitByte('g');
			_delay_ms(10);
			
		}
		else if((PINC & 0x30)==0x10)
		{
			transmitByte('f');
			_delay_ms(10);
			
		}
		
		
	}
	
	
}