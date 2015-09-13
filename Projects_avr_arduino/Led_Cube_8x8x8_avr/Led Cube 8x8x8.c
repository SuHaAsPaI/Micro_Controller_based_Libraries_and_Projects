/*
LED CUBE 8X8X8 PROGRAM
      IC 74HC573
PORT C0 = D0 OF IC 74HC573
PORT C1 = D1 OF IC 74HC573
PORT C2 = D2 OF IC 74HC573
PORT C3 = D3 OF IC 74HC573
PORT C4 = D4 OF IC 74HC573
PORT C5 = D5 OF IC 74HC573
PORT C6 = D6 OF IC 74HC573
PORT C7 = D7 OF IC 74HC573

GROUND CONNECTION FOR THE CUBE

PORT B0 = 1ST LAYER (TOP)
PORT B1 = 2ND LAYER
PORT B2 = 3RD LAYER
PORT B3 = 4TH LAYER
PORT B4 = 5TH LAYER
PORT B5 = 6TH LAYER
PORT B6 = 7TH LAYER
PORT B7 = 8TH LAYER (BOTTOM)

FOR CONTROL LATCHES

PORT D0 = A OF IC 74HC138
PORT D1 = B OF IC 74HC138
PORT D2 = B OF IC 74HC138

PORT D4 = G1 OF IC 74HC138 (TO DISABLE IC 74HC138)
PORT D5 = OUT ENALBE OF IC 74HC573 

*/
#include<avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

int main(void)
{
  DDRC=0xFF;
  DDRB=0XFF;
  DDRD=0XFF;
  unsigned char a,b,c;
  
  while(1)
  {
     PORTB=0X00;
	 for(a=0;a<3;a++)   /*1*/
	 {
	   for(b=0x10;b<=0x17;b++)
	   {
	      PORTD=b;
		  PORTC=0XFF;
		  _delay_ms(50);
		  PORTC=0X00;
	   }
	   
	   for(b=0X16;b>=0X10;b--)
	   {
	      PORTD=b;
		  PORTC=0XFF;
		  _delay_ms(50);
		  PORTC=0X00;
	   }
	   
	 }
	 
	 for(a=0;a<3;a++)    /*2*/
	 {
	   PORTC=0X01; //1
	   	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;  
	   _delay_ms(50);
	   
	   
	   PORTC=0X02;//2
	   	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;  
	   _delay_ms(50);
	   
	   
	   PORTC=0X04;//3
	   	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;
	   _delay_ms(50);
	   
	   
	   PORTC=0X08;//4
	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;
	   _delay_ms(50);
	   
	   PORTC=0X10;//5
	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;
	   _delay_ms(50);
	   
	   PORTC=0X20;//6
	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;
	   _delay_ms(50);
	   
	   
	   PORTC=0X40;//7
	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;
	   _delay_ms(50);
  
	   
	   PORTC=0X80;//8
	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;
	   _delay_ms(50);
	   
	   PORTC=0X40;//7
	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;
	   _delay_ms(50);
	   
	   PORTC=0X20;//6
	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;
	   _delay_ms(50);
	   
	   PORTC=0X10;//5
	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;
	   _delay_ms(50);
	   
	  PORTC=0X08;//4
	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;
	   _delay_ms(50);
	   
	   PORTC=0X04;//3
	   	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;
	   _delay_ms(50);
	   
	   PORTC=0X02;//2
	   	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;  
	   _delay_ms(50);
	   
	   PORTC=0X01; //1
	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   	   PORTD=0x01;  
	   _delay_ms(50);
	   
	 }
	 
	 for(a=0;a<3;a++) /*3*/
	 {
	   PORTC=0XFF;
	   for(b=0X30;b<=0X37;b++)
	   {
	      PORTD=b;
	   }
	   PORTD=0X01;
	   
	   PORTB=0XFE;//1
	   _delay_ms(50);
	   
	   PORTB=0XFD;//2
	   _delay_ms(50);
	   
	   PORTB=0XFB;//3
	   _delay_ms(50);
	   
	   PORTB=0XF7;//4
	   _delay_ms(50);
	   
	   PORTB=0XEF;//5
	   _delay_ms(50);
	   
	   PORTB=0XDF;//6
	   _delay_ms(50);
	   
	   PORTB=0XBF;//7
	   _delay_ms(50);
	   
	   PORTB=0X7F;//8
	   _delay_ms(50);
	   
	   PORTB=0XBF;//7
	   _delay_ms(50);
	   
	   PORTB=0XDF;//6
	   _delay_ms(50);
	   
	   PORTB=0XEF;//5
	   _delay_ms(50);
	   
	   PORTB=0XF7;//4
	   _delay_ms(50);
	   
	   PORTB=0XFB;//3
	   _delay_ms(50);
	   
	   PORTB=0XFD;//2
	   _delay_ms(50);
	   
	   PORTB=0XFE;//1
	   _delay_ms(50);
	 }
	 
	 
	 for(a=0;a<3;a++)/*4*/
	 {
	    {
		PORTC=0X85;
		PORTD=0X30;
		
		PORTC=0X58;
		PORTD=0X31;
		
		PORTC=0X26;
		PORTD=0X32;
		
		PORTC=0X35;
		PORTD=0X33;
		
		PORTC=0X41;
		PORTD=0X34;
		
		PORTC=0X52;
		PORTD=0X35;
		
		PORTC=0X79;
		PORTD=0X36;
		
		PORTC=0X86;
		PORTC=0X37;
		
	   PORTD=0X01;
	   
	   PORTB=0XFE;//1
	   _delay_ms(100);
	   
	   PORTB=0XFD;//2
	   _delay_ms(100);
	   
	   PORTB=0XFB;//3
	   _delay_ms(100);
	   
	   PORTB=0XF7;//4
	   _delay_ms(100);
	   
	   PORTB=0XEF;//5
	   _delay_ms(100);
	   
	   PORTB=0XDF;//6
	   _delay_ms(100);
	   
	   PORTB=0XBF;//7
	   _delay_ms(100);
	   
	   PORTB=0X7F;//8
	   _delay_ms(100);
	   }
	   
	   {
	   PORTC=0X38;
	   PORTD=0X30;
	   
	   PORTC=0X31;
	   PORTD=0X31;
	   
	   PORTC=0X62;
	   PORTD=0X32;
	   
	   PORTC=0X73;
	   PORTD=0X33;
	   
	   PORTC=0X93;
	   PORTD=0X34;
	   
	   PORTC=0X07;
	   PORTD=0X35;
	   
	   PORTC=0X49;
	   PORTD=0X36;
	   
	   PORTC=0X74;
	   PORTD=0X37;
	   
	   	   PORTD=0X01;
	   
	   PORTB=0XFE;//1
	   _delay_ms(100);
	   
	   PORTB=0XFD;//2
	   _delay_ms(100);
	   
	   PORTB=0XFB;//3
	   _delay_ms(100);
	   
	   PORTB=0XF7;//4
	   _delay_ms(100);
	   
	   PORTB=0XEF;//5
	   _delay_ms(100);
	   
	   PORTB=0XDF;//6
	   _delay_ms(100);
	   
	   PORTB=0XBF;//7
	   _delay_ms(100);
	   
	   PORTB=0X7F;//8
	   _delay_ms(100);
	   
	   }
	   
	   {
	   PORTC=0X54;
	   PORTD=0X30;
	   
	   PORTC=0X37;
	   PORTD=0X31;
	   
	   PORTC=0X30;
	   PORTD=0X32;
	   
	   PORTC=0X71;
	   PORTD=0X33;
	   
	   PORTC=0X83;
	   PORTD=0X34;
	   
	   PORTC=0X36;
	   PORTD=0X35;
	   
	   PORTC=0X61;
	   PORTD=0X36;
	   
	   PORTC=0X59;
	   PORTD=0X37;
	   
	   	   PORTD=0X01;
	   
	   PORTB=0XFE;//1
	   _delay_ms(100);
	   
	   PORTB=0XFD;//2
	   _delay_ms(100);
	   
	   PORTB=0XFB;//3
	   _delay_ms(100);
	   
	   PORTB=0XF7;//4
	   _delay_ms(100);
	   
	   PORTB=0XEF;//5
	   _delay_ms(100);
	   
	   PORTB=0XDF;//6
	   _delay_ms(100);
	   
	   PORTB=0XBF;//7
	   _delay_ms(100);
	   
	   PORTB=0X7F;//8
	   _delay_ms(100);
	   }
	   
	   {
	   PORTC=0X62;
	   PORTD=0X30;
	   
	   PORTC=0X95;
	   PORTD=0X31;
	   
	   PORTC=0X61;
	   PORTD=0X32;
	   
	   PORTC=0X97;
	   PORTD=0X33;
	   
	   PORTC=0X32;
	   PORTD=0X34;
	   
	   PORTC=0X42;
	   PORTD=0X35;
	   
	   PORTC=0X35;
	   PORTD=0X36;
	   
	   PORTC=0X46;
	   PORTD=0X37;
	   
	   	   	   PORTD=0X01;
	   
	   PORTB=0XFE;//1
	   _delay_ms(100);
	   
	   PORTB=0XFD;//2
	   _delay_ms(100);
	   
	   PORTB=0XFB;//3
	   _delay_ms(100);
	   
	   PORTB=0XF7;//4
	   _delay_ms(100);
	   
	   PORTB=0XEF;//5
	   _delay_ms(100);
	   
	   PORTB=0XDF;//6
	   _delay_ms(100);
	   
	   PORTB=0XBF;//7
	   _delay_ms(100);
	   
	   PORTB=0X7F;//8
	   _delay_ms(100);
	   }

	   
	  

	 }
	 
  
  }

}