/*
*/
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "motor.h"
#include "adc.h"
#define F_CPU 16000000

int main(void)
{
    //DDRB |= (1 << DDB3);					// PB3 is now an output
	DDRD=0x0F;

   /* OCR2 = 255;								// set PWM for n % duty cycle
	TCCR2 |= (1 << COM21);					// set none-inverting mode
	TCCR2 |= (1 << WGM21) | (1 << WGM20);	// set fast PWM Mode
	TCCR2 |= (1 << CS21);					// set prescaler to 8 and starts PWM*/
	
	unsigned int adc[12];
	unsigned int k1,k2,k,swap;
	unsigned int ma,mb,m0,m1,m2,m3,A,B;
	
    adc[1]= getdata(0x00);
    adc[2]= getdata(0x01);
    adc[3]= getdata(0x02);
    adc[4]= getdata(0x03);
    adc[5]= getdata(0x04);
    adc[6]= getdata(0x05);
	
	for(k1=1;k1<8;k1++)
	{
		for(k2=1;k2<5;k2++)
		{
			if(adc[k2]>adc[k2+1]) /* For decreasing order use < */
			{
				swap= adc[k2];
				adc[k2]= adc[k2+1];
				adc[k2+1]= swap;
			}
		}
	}
	
	k=((adc[1]+adc[6])/2);
	
	while (1)
    {
		if(getdata(0x00) > k)//0
		{
			ma=1;
		}
		else if(getdata(0x00) < k)
		{
			ma=0;
		}
		
		if(getdata(0x01) > k)//1
		{
			m0=1;
		}
		else if(getdata(0x01) < k)
		{
			m0=0;
		}
		
		if(getdata(0x02) > k)//2
		{
			m1=10;
		}
		else if(getdata(0x02) < k)
		{
			m1=0;
		}
		
		if(getdata(0x03) > k)//3
		{
			m2=100;
		}
		else if(getdata(0x03) < k)
		{
			m2=0;
		}
		
		if(getdata(0x04) > k)//4
		{
			m3=1000;
		}
		else if(getdata(0x04) < k)
		{
			m3=0;
		}
		
		if(getdata(0x05) > k)//5
		{
			mb=10;
		}
		else if(getdata(0x05) < k)
		{
			mb=0;
		}
		
		
		A=(m0+m1+m2+m3);
		
		B=(ma+mb);
		
		
		switch(A)
		{
			case 0:
			case 101:
			case 110:
			case 1001:
			case 1010:
			case 1011:
			case 1101:
			case 1111:
			straight();
			PORTD=0x0A;
			
			break;
			
			case 1:
			case 10:
			case 11:
			case 111:
			left();
			PORTD=0x02;
			break;
			
			case 100:
			case 1000:
			case 1100:
			case 1110:
			 right();
			 PORTD=0x08;
			 break;
			
		}
		
    }
}