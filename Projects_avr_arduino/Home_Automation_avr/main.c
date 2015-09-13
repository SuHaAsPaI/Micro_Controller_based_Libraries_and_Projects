#include<avr/io.h>
#include"uart.c"
#include"uart.h"
#include<util/delay.h>

int main(void)
{
	uart_init();
	DDRC=0x1F;
	int i,j,k,l,m;
	i=j=k=l=m=1;
	
	DDRB |= (1 << DDB3);
	OCR2 = 5;
	
	TCCR2 |= (1 << COM21);
    // set none-inverting mode

    TCCR2 |= (1 << WGM21) | (1 << WGM20);
    // set fast PWM Mode

    TCCR2 |= (1 << CS21);
    // set prescaler to 8 and starts PWM
	
	
	int z1,z2,z3,z4,z5,z;
	z1=z2=z3=z4=z5=0;
	
	char t;
	PORTC=0x00;
	while(1)
	{
		
		t=receiveByte();
		switch(t)
		{
			case 'a':
				if(i==1)
				{
					//on led 1
					z1=0b00000001;
					i=2;
				}
				else if(i==2)
				{
					//off led 1
					z1=0b00000000;
					i=1;
				}
			break;
			
			case 'b':
				if(j==1)
				{
					//on led 2
					z2=0b00000010;
					j=2;
				}
				else if(j==2)
				{
					//off led 2
					z2=0b00000000;
					j=1;
				}
			break;
			
			case 'c':
				if(k==1)
				{
					//on led 3
					z3=0b00000100;
					k=2;
				}
				else if(k==2)
				{
					//off led 3
					z3=0b00000000;
					k=1;
				}
			break;
			
			case 'd':
				if(l==1)
				{
					//on led 4
					z4=0b00001000;
					l=2;
				}
				else if(l==2)
				{
					//off led 4
					z4=0b00000000;
					l=1;
				}
			break;
			
			case 'e':
				if(m==1)
				{
					//on fan
					z5=0b00010000;
					m=2;
				}
				else if(m==2)
				{
					//off fan
					z5=0b00000000;
					m=1;
				}
			break;
			
			case 'f':
				if(OCR2<255)
				{
					OCR2=OCR2+50;
				}
				else if(OCR2==255)
				{
					OCR2=OCR2;
				}
				
			break;
			
			case 'g':
				if(OCR2>5)
				{
					OCR2=OCR2-50;
				}
				else if(OCR2==5)
				{
					OCR2=OCR2;
				}
				
			break;
			
		}
		z=z1+z2+z3+z4+z5;
		PORTC=z;
	}
} 