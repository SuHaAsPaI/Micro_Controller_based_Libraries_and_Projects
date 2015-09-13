//**************************************************************
// ****** FUNCTIONS FOR SPI COMMUNICATION *******
//**************************************************************
/*
*AUTHOR: Suhaas Pai
*Target system: AVR devlopment board
*Microcontroller: ATmega8/Atmega32A
*Clock: 16MHz
*COMPILER: WinAVR/ Amel Studio 6.1
*last modified 09/03/2012
*/

//**************************************************************

#ifndef _SPI_ROUTINES_H_
#define _SPI_ROUTINES_H_

#define SPI_SD             SPCR = 0x52
#define SPI_HIGH_SPEED     SPCR = 0x50; SPSR |= (1<<SPI2X)


void spi_init(void);
unsigned char SPI_transmit(unsigned char);
unsigned char SPI_receive(void);

#endif
