/*eeprom.h
*******************************************************************************************

*AUTHOR: Suhaas Pai
*Target system: AVR devlopment board
*Microcontroller: ATmega8/Atmega32A
*Clock: 16MHz
*COMPILER: WinAVR/ Amel Studio 6.1
*last modified 09/03/2012
#ifndef EEPROM_H_INCLUDED
#define EEPROM_H_INCLUDED

#include<avr/eeprom.h>

void EEPROM_write(unsigned int, unsigned char);
unsigned char EEPROM_read(unsigned int );

unsigned char EEMEM a=0x00;

void EEPROM_write(unsigned int Address, unsigned char Data)
{
/* Wait for completion of previous write */
while(EECR & (1<<EEWE));
/* Set up address and data registers */
EEAR = Address;
EEDR = Data;
/* Write logical one to EEMWE */
EECR |= (1<<EEMWE);
/* Start eeprom write by setting EEWE */
EECR |= (1<<EEWE);
}

unsigned char EEPROM_read(unsigned int Address)
{
/* Wait for completion of previous write */
while(EECR & (1<<EEWE));
/* Set up address register */
EEAR = Address;
/* Start eeprom read by writing EERE */
EECR |= (1<<EERE);
/* Return data from data register */
return EEDR;
}


#endif // EEPROM_H_INCLUDED
