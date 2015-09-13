/***************************************************************************************************************************************************
C FILE:uart.c
****************************************************************************************************************************************************

*AUTHOR: Suhaas Pai
*Target system: AVR devlopment board
*Microcontroller: ATmega8/Atmega32A
*Clock: 16MHz
*COMPILER: WinAVR/ Amel Studio 6.1
*last modified 10/07/2014


DESCRIPTION:
	This C files have implementation of some common functions of the uart.
	Include this C file in your C code. Call the uart_init() function before
	calling any other functions to initialize the uart communication.

**********************************************************/

#define F_CPU 12000000
#include "uart.h"
#include <avr/io.h>
#include <avr/pgmspace.h>

#define USART_BAUDRATE 9600// Baud Rate value
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


void uart_init()
{
	UCSRA = 0x00; //disable while setting baud rate
	UCSRA = 0x00;
	UCSRC = 0x06;
	UBRRL = BAUD_PRESCALE;    // Load lower 8-bits of the baud rate value into the low byte of the UBRR register
	UBRRH = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value..
// into the high byte of the UBRR register
	UCSRB = 0x18;
}


unsigned char receiveByte( void )
{
	unsigned char data, status;

	while(!(UCSRA & (1<<RXC))); 	// Wait for incomming data

	status = UCSRA;
	data = UDR;

	return(data);
}


void transmitByte( unsigned char data )
{
	while ( !(UCSRA & (1<<UDRE)) )
		; 			                /* Wait for empty transmit buffer */
	UDR = data; 			        /* Start transmition */
}


void transmitHex( unsigned char dataType, unsigned long data )
{
	unsigned char count, i, temp;
	unsigned char dataString[] = "0x        ";

	if (dataType == CHAR) count = 2;
	if (dataType == INT) count = 4;
	if (dataType == LONG) count = 8;

	for(i=count; i>0; i--)
	{
		temp = data % 16;
		if((temp>=0) && (temp<10)) dataString [i+1] = temp + 0x30;
		else dataString [i+1] = (temp - 10) + 0x41;

		data = data/16;
	}

	transmitString ( dataString );
}


void transmitString_F(char* string)
{
	while ( pgm_read_byte(&(*string)) )
		transmitByte( pgm_read_byte(&(*string++)) );
}


void transmitString( unsigned char* string )
{
	while ( *string )
		transmitByte( *string++ );
}
