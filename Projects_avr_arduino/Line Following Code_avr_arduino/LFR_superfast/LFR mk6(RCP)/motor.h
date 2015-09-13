#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED

#include "lcd118010.h"

void left(void);
void right(void);
void slight_left(void);
void slight_right(void);
void straight(void);
void u_turn(void);


void left(void)
{
	OCR1A=255;				//Left Motor PWM
	OCR1B=255;              //Right Motor PWM
	lcd_gotoxy(1,4);
	lcd_showvalue(OCR1A);
	lcd_gotoxy(1,8);
	lcd_showvalue(OCR1B);

}


void right(void)
{
	OCR1A=255;				//Left Motor PWM
	OCR1B=255;				//Right Motor PWM
	lcd_gotoxy(1,4);
	lcd_showvalue(OCR1A);
	lcd_gotoxy(1,8);
	lcd_showvalue(OCR1B);
}

void slight_left(void)
{
	OCR1A=255;				//Left Motor PWM
	OCR1B=25;				//Right Motor PWM
	lcd_gotoxy(1,4);
	lcd_showvalue(OCR1A);
	lcd_gotoxy(1,8);
	lcd_showvalue(OCR1B);
}


void slight_right(void)
{
	OCR1A=25;				//Left Motor PWM
	OCR1B=255;				//Right Motor PWM
	lcd_gotoxy(1,4);
	lcd_showvalue(OCR1A);
	lcd_gotoxy(1,8);
	lcd_showvalue(OCR1B);
}

void straight(void)
{
	OCR1A=255;				//Left Motor PWM
	OCR1B=255;				//Right Motor PWM
	lcd_gotoxy(1,4);
	lcd_showvalue(OCR1A);
	lcd_gotoxy(1,8);
	lcd_showvalue(OCR1B);
}

void u_turn(void)
{
	OCR1A=255;				//Left Motor PWM
	OCR1B=255;				//Right Motor PWM
	lcd_gotoxy(1,4);
	lcd_showvalue(OCR1A);
	lcd_gotoxy(1,8);
	lcd_showvalue(OCR1B);
}


#endif // MOTOR_H_INCLUDED
