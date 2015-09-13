/***************************************************************************************************************************************************
HEADER:uart.h
****************************************************************************************************************************************************

*AUTHOR: Suhaas Pai
*Target system: AVR devlopment board
*Microcontroller: ATmega8/Atmega32A
*Clock: 16MHz
*COMPILER: WinAVR/ Amel Studio 6.1
*last modified 10/07/2014


DESCRIPTION:
	This header files have implementation of some common functions of the uart.
	Include this header file in your C code. Call the uart_init() function before
	calling any other functions to initialize the uart communication.




	uart_init()-----  Call the uart_init() function before calling any other functions
			                  to initialize the uart.
    receiveByte() -----Function to receive a single byte.
    transmitByte()-----Function to transmit a single byte
    transmitHex() ----- Function to transmit hex format data first argument
                         indicates type: CHAR, INT or LONGSecond argument is the data to be displayed.
    transmitString_F()----- Function to transmit a string in Flash.
    transmitString()----- Function to transmit a string in RAM.
*/


#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED

#define CHAR 0
#define INT  1
#define LONG 2

#define TX_NEWLINE {transmitByte(0x0d); transmitByte(0x0a);}

void uart_init(void);
unsigned char receiveByte(void);
void transmitByte(unsigned char);
void transmitString_F(char*);
void transmitString(unsigned char*);
void transmitHex( unsigned char dataType, unsigned long data );


#endif // UART_H_INCLUDED
