#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char ADC_Conversion(unsigned char);
unsigned char ADC_Value1;
unsigned char ADC_Value2;
unsigned int str[12];
unsigned int k1,k2,k;


void config()
{
cli();

//ADC pin configuration
 DDRA = 0x00;  //set PORTA direction as input
 PORTA = 0x00; //set PORTA pins floating
 DDRC=0x0F;
 DDRB=0X0F;
 TCCR1A=0xA1;
 TCCR1B=0x05;
 OCR1A=180;				//Left Motor PWM
 OCR1B=180;				//Right Motor PWM	
 DDRD=0x30;				//Declaring PD4,PD5 as output
  

//Function to Initialize ADC
 ADCSRA = 0x00;
 ADMUX = 0x20;		//Vref=5V external --- ADLAR=1 --- MUX4:0 = 0000
 ACSR = 0x80;
 ADCSRA = 0x86;		//ADEN=1 --- ADIE=1 --- ADPS2:0 = 1 1 0

sei();

}

//This Function accepts the Channel Number and returns the corresponding Analog Value
unsigned char ADC_Conversion(unsigned char Ch)
{
 unsigned char a;
 Ch = Ch & 0x07;
 ADMUX= 0x20| Ch;
 ADCSRA = ADCSRA | 0x40;		//Set start conversion bit
 while((ADCSRA&0x10)==0);	    //Wait for ADC conversion to complete
 a=ADCH;
 ADCSRA = ADCSRA|0x10;          //clear ADIF (ADC Interrupt Flag) by writing 1 to it
 return a;
}


int main(void)
{
config();

unsigned int a,ma,mb,m1,m2,m3,m4,x,y;


   PORTC=0x0F;
   _delay_ms(5000);
   PORTC=0x00;
    _delay_ms(1000);
 
   // For white line readings
   
   str[0]= ADC_Conversion(0);
   str[1]= ADC_Conversion(1);
   str[2]= ADC_Conversion(2);
   str[3]= ADC_Conversion(3);
   str[4]= ADC_Conversion(4);
   str[5]= ADC_Conversion(5);
   
   PORTC=0x0F;
   _delay_ms(5000);
   PORTC=0x00;
   
   // For Black line readings
   
   str[6]=  ADC_Conversion(0);
   str[7]=  ADC_Conversion(1);
   str[8]=  ADC_Conversion(2);
   str[9]=  ADC_Conversion(3);
   str[10]= ADC_Conversion(4);
   str[11]= ADC_Conversion(5);

   
   
   k1=((str[0]+str[1]+str[2]+str[3]+str[4]+str[5])/6);   // Taking average for white line
   
   k2=((str[6]+str[7]+str[8]+str[9]+str[10]+str[11])/6);  // Taking average for black line
   
   k=((k1+k2)/2);        // taking average of both
   
   _delay_ms(1000);
   

	for(a=0;a<=20;a++)
	{
		PORTC=0x01;
		_delay_ms(k);
		PORTC=0x00;
		_delay_ms(k);
	}

	while(1)
	{
	
		if(ADC_Conversion(1) > k)
		{
			m1=1;
		}
		else if(ADC_Conversion(1) < k)
		{
			m1=0;
		}
		
		if(ADC_Conversion(2) > k)
		{
			m2=10;
		}
		else if(ADC_Conversion(2) < k)
		{
			m2=0;
		}
		
		if(ADC_Conversion(3) > k)
		{
			m3=100;
		}
		else if(ADC_Conversion(3) < k)
		{
			m3=0;
		}
		
		if(ADC_Conversion(4) > k)
		{
			m4=1000;
		}
		else if(ADC_Conversion(4) < k)
		{
			m4=0;
		}
		
		if(ADC_Conversion(0) > k)
		{
			ma=1;
		}
		else if(ADC_Conversion(0) < k)
		{
			ma=0;
		}
		
		if(ADC_Conversion(5) > k)
		{
			mb=10;
		}
		else if(ADC_Conversion(5) < k)
		{
			mb=0;
		}
		
		
		x=(m1+m2+m3+m4);
		
		if((ADC_Conversion(0) > k) & (ADC_Conversion(5)  > k))
		{
		  PORTC=0x00;
		  switch(x)
		  {
			
			case 1110:		//right
			case 1100:
			PORTB=0x08;
			break;
			
			case 1000:		//cright
			case 0101:
			case 0100:
			case 1101:
			PORTB=0x08;
			break;
			
					//left
			case 110:
			case 1:
			case 0:	
			case 1011:
			case 1010:
			PORTB=0x02;
			break;
			
			case 10:		//cleft
			case 11:
			case 111:
			PORTB=0x02;
			break;
			
			
			
			//straight
			case 1001:
			
			case 1111:
			PORTB=0x0A;
			break;
			
		  }
		}
		else if((ADC_Conversion(0) < k) & (ADC_Conversion(5)  < k))
		{
		  PORTC=0x0F;
		  switch(x)
		  {
			case 1110:		//right
			case 1100:
			PORTB=0x02;
			break;
			
			case 1000:		//cright
			case 0101:
			case 0100:
			case 0:
			
			PORTB=0x02;
			break;
			case 1101:
			PORTB=0x06;
			break;
		//left
			case 110:
			case 1:
			case 1011:
			case 1010:
			PORTB=0x08;
			break;
			
			case 10:		//cleft
			case 11:
			case 111:
			PORTB=0x08;
			break;
			
			
			
			//straight
			case 1001:
			case 1111:
			PORTB=0x0A;
			break;
		  }
		}
		else if((ADC_Conversion(0) < k) & (ADC_Conversion(5)  > k))
		{
			//straight
			PORTC=0x00;
		
			PORTC=0x0F;
		}
		else if((ADC_Conversion(0) > k) & (ADC_Conversion(5)  < k))
		{
			//straight
			PORTC=0x00;

			PORTC=0x0F;
		}
		
	
	
	}


}

