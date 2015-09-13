
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD=0xFF;
	DDRB=0x0F;
	int i,k;
	int a[]={0X83,0X54,0X70,0X69,0X36,0X28,0X07,0X34,0X67,0X29,0X84,0X43,0X10,0x33,0x54,0x45};
	
	while(1)
	{
		
		for(i=0;i<=10;i++)
		{
			PORTD=0XFF;
			PORTB=0X0D;
			_delay_ms(100);
			PORTB=0X0B;
			_delay_ms(100);
			PORTB=0X07;
			_delay_ms(100);
			PORTB=0X0B;
			_delay_ms(100);
		}
		
		for(i=0;i<=10;i++)
		{
			PORTB=0X00;
			PORTD=0X1C;
			_delay_ms(100);
			PORTB=0X01;
			PORTD=0X22;
			_delay_ms(100);
			PORTB=0X00;
			PORTD=0XC1;
			_delay_ms(100);
			PORTB=0X01;
			PORTD=0X22;
			_delay_ms(100);
		}
		
		
		for(i=0;i<=6;i++)
		{
			PORTB=0X01;
			PORTD=0X11;
			_delay_ms(100);
			PORTD=0X22;
			_delay_ms(100);
			PORTD=0X44;
			_delay_ms(100);
			PORTD=0X88;
			_delay_ms(100);
		}
		
		
		for(i=0;i<=20;i++)
		{
			PORTD=a[i];
			PORTB=0X0D;
			_delay_ms(75);
			PORTB=0X0B;
			_delay_ms(75);
			PORTB=0X07;
			_delay_ms(75);
		}
		
		for(i=0;i<=20000;i++)
		{
			PORTD=0XFF;
			PORTB=0X0C;
			_delay_us(100);
			PORTD=0X55;
			PORTB=0X0A;
			_delay_us(100);
			PORTD=0XFF;
			PORTB=0X06;
			_delay_us(100);
		}
		
		
		
		
		
		for(k=0;k<=5;k++)
		{
		
	    for(i=0;i<=400;i++)	//E3
		{
			PORTD=0x1C;
			PORTB=0X0C;
			_delay_us(100);
			PORTD=0X0C;
			PORTB=0X0A;
			_delay_us(100);
			PORTD=0X1C;
			PORTB=0X06;
			_delay_us(100);
		}
		
		for(i=0;i<=400;i++)	//E2
		{
			PORTD=0x22;
			PORTB=0X0D;
			_delay_us(100);
			PORTD=0X02;
			PORTB=0X0B;
			_delay_us(100);
			PORTD=0X22;
			PORTB=0X07;
			_delay_us(100);
		}
		
		for(i=0;i<=1000;i++)	//E1
		{
			PORTD=0xC1;
			PORTB=0X0C;
			_delay_us(100);
			PORTD=0X81;
			PORTB=0X0A;
			_delay_us(100);
			PORTD=0XC1;
			PORTB=0X06;
			_delay_us(100);
		}
		
		for(i=0;i<=400;i++)	//T3
		{
			PORTD=0x1C;
			PORTB=0X0C;
			_delay_us(100);
			PORTD=0X08;
			PORTB=0X0A;
			_delay_us(100);
			PORTB=0X06;
			_delay_us(100);
		}
		
		for(i=0;i<=400;i++)	//T2
		{
			PORTD=0x22;
			PORTB=0X0D;
			_delay_us(100);
			PORTD=0X00;
			PORTB=0X0B;
			_delay_us(100);
			PORTB=0X07;
			_delay_us(100);
		}
		
		for(i=0;i<=1000;i++)	//T1
		{
			PORTD=0xC1;
			PORTB=0X0C;
			_delay_us(100);
			PORTD=0X80;
			PORTB=0X0A;
			_delay_us(100);
			PORTB=0X06;
			_delay_us(100);
		}
		
		for(i=0;i<=400;i++)	//C3
		{
			PORTD=0x1C;
			PORTB=0X0C;
			_delay_us(100);
			PORTD=0X04;
			PORTB=0X0A;
			_delay_us(100);
			PORTD=0X1C;
			PORTB=0X06;
			_delay_us(100);
		}
		
		for(i=0;i<=400;i++)	//C2
		{
			PORTD=0x22;
			PORTB=0X0D;
			_delay_us(100);
			PORTD=0X02;
			PORTB=0X0A;
			_delay_us(100);
			PORTD=0X22;
			PORTB=0X07;
			_delay_us(100);
		}
		
		for(i=0;i<=1000;i++)	//C1
		{
			PORTD=0xC1;
			PORTB=0X0C;
			_delay_us(100);
			PORTD=0X01;
			PORTB=0X0A;
			_delay_us(100);
			PORTD=0XC1;
			PORTB=0X06;
			_delay_us(100);
			PORTB=0X0E;
		}
		
		_delay_ms(500);
		}
	
	}
}
