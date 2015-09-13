

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL

int main(void)
{
	DDRA=0X0F;
	
	while(1)
	{
		
			PORTA=0X01;
			_delay_us(2000);
			
			PORTA=0X02;
			_delay_us(2000);
			
			PORTA=0X04;
			_delay_us(2000);
			
			PORTA=0X08;
			_delay_us(2000);
				}

    return 0;
}
