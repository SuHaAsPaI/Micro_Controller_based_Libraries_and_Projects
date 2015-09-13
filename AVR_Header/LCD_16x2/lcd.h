/***************************************************************************************************************************************************
HEADER:LCD.h
****************************************************************************************************************************************************

*AUTHOR: Suhaas Pai
*Target system: AVR devlopment board
*Microcontroller: ATmega8/Atmega32A
*Clock: 16MHz
*COMPILER: WinAVR/ Amel Studio 6.1
*last modified 09/03/2012


DESCRIPTION:
	This header files have implementation of some common finctions of the LCD.
	Include this header file in your C code. Call the lcd_init() function before
	calling any other functions to initialize the lcd.


	lcd_init() ----- Call the lcd_init() function before calling any other functions
			  to initialize the lcd.
	lcd_cmd() ------ This function is used to give any command instructions to the
			  LCD. For e.g lcd_cmd(0x01) will give the clear command.
	lcd_char() ----- This function will display a single character on the LCD display.
			  For example lcd_char(0x61) will display A. Again lcd_char('b')
			  will display b.
	lcd_string()---- This function will display a string. An example of this would be
			  like lcd_string("This is AVR")
	lcd_showvalue()- This will show a 3-digit decimal value on the LCD. For example if
			  we give lcd_showvalue(0xFF) then 255 will be displayed.
	lcd_gotoxy()--- Will set the cursor at a particular position on of the LCD.
			  So lcd_gotoxy(1,4) will set the cursor at the 2d row 3rd column
			  row and column address are starts from(0,0)
	lcd_clear()---To clear the LCD

LCD connection Details

Data mode--------4bit

RS----------------PORTB 4
RW----------------Ground
E-----------------PORTB 5
D0----------------open
D1----------------open
D2----------------open
D3----------------open
D4----------------PORTB 0
D5----------------PORTB 1
D6----------------PORTB 2
D7----------------PORTB 3

*************************************************************************************************************************************/

#ifndef LCD_H_INCLUDED
#define LCD_H_INCLUDED

unsigned char k=0,j=0;
unsigned char save=0;

void lcd_init(void);
void lcd_cmd(unsigned char cmd);
void latch(void);
void delay_ns_lcd(unsigned char tim);
void lcd_char(unsigned char single);
void lcd_string(unsigned char str[32]);
void lcd_showvalue(unsigned char num);
void lcd_gotoxy(unsigned char row,unsigned char column);
void delay_ms_lcd(unsigned int ms);
void lcd_clear();

#endif // LCD_H_INCLUDED
