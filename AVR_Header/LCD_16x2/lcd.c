/***************************************************************************************************************************************************
C File:lcd.c
****************************************************************************************************************************************************

*AUTHOR: Suhaas Pai
*Target system: AVR devlopment board
*Microcontroller: ATmega8/Atmega32A
*Clock: 16MHz
*COMPILER: WinAVR/ Amel Studio 5
*last modified 10/07/2014


DESCRIPTION:
	This C files have implementation of some common finctions of the LCD.
	Include this C file in your C code. Call the lcd_init() function before
	calling any other functions to initialize the lcd.

****************************************************************************************************************************************************/


#include "lcd.h"
#include <avr/io.h>
#include <avr/pgmspace.h>



void lcd_init(void)	//init the lcd
{

	DDRB=0x3F;
	delay_ms_lcd(20);


	PORTB=0x03;
	latch();
	delay_ms_lcd(5);
	PORTB=0x03;
	latch();
	delay_ms_lcd(1);
	PORTB=0x03;
	latch();
	delay_ms_lcd(1);
	PORTB=0x02;			//Enable 4 bit mode
	latch();
	delay_ms_lcd(5);


	lcd_cmd(0x28);		//Set interface 4 bit 2 line
	delay_ms_lcd(1);

	lcd_cmd(0x08);		//Enable display/cursor
	delay_ms_lcd(1);

	lcd_cmd(0x01);		//clear the display
	delay_ms_lcd(1);

	lcd_cmd(0x06);		//Set cursor move, Move cursor right
	delay_ms_lcd(1);


	lcd_cmd(0X0C);		//Turn on display
	delay_ms_lcd(2);

}

void latch(void)
{
PORTB&=~0x20;
delay_ns_lcd(200);
PORTB|=0x20;
delay_ns_lcd(200);
PORTB&=~0x20;
}

void delay_ns_lcd(unsigned char tim)
{
	for(j=0;j<tim;j++)
	{
		for(k=0;k<11;k++)
		{};
	}
}

void lcd_cmd(unsigned char cmd)
{   unsigned char cmd_temp=cmd;
	PORTB&=~0x30;
	cmd_temp>>=4;
	PORTB=((cmd_temp & 0x0F));
	latch();
	PORTB=(cmd & 0x0F);
	latch();
}


void lcd_char(unsigned char single)
{
    unsigned char temp_single=single;
	temp_single>>=4;
	PORTB=0x10;
	PORTB=0x00;
	PORTB=(temp_single & 0x0F)|0x10;
	latch();
	PORTB=(single & 0x0F)|0x10;
	latch();
}

void lcd_string(unsigned char *str)
{
	unsigned char k=0;

		while(*str!='\0')	//Till null character is encountered
		{
			lcd_char(*str);
			str++;
		}
}



void lcd_showvalue(unsigned char num)	//prints the decimal 3digit value of num
{
	unsigned char H=0,T=0,O=0;
	H=num/100;
	T=(num - (H*100))/10;
	O=(num - (H*100) - (T*10));

	lcd_char(H+48);
	lcd_char(T+48);

	lcd_char(O+48);
}

void lcd_gotoxy(unsigned char row,unsigned char column)			//move cursor to the specified position
{
   if(row==0)
    {
	 lcd_cmd(0x80+column);
	}
   else if(row==1)
	{
	 lcd_cmd(0xC0+column);
	}
}


void delay_ms_lcd(unsigned int ms)
{
	int i;

	while (ms-- > 0)
	{

		for (i = 0; i < 3276; ++i)
			asm("nop");
	}
}

void lcd_clear()
{
 lcd_cmd(0x01);
}
