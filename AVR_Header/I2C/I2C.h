
/***************************************************************************************************************************************************
HEADER:I2C.h
****************************************************************************************************************************************************

*AUTHOR: Suhaas Pai
*Target system: AVR devlopment board
*Microcontroller: ATmega8/Atmega32A
*Clock: 16MHz
*COMPILER: WinAVR/ Amel Studio 6.1
*last modified 09/03/2012
*/


#ifndef _I2C_H_
#define _I2C_H_

unsigned char write(unsigned char add,unsigned char data)
{
	TWBR=0XFF;							//lowest possible scl frequency
	TWSR=0X00;							//precscalar set to 1

	TWCR=0XA4;							//start bit
	while(!(TWCR&0x80));				//checking if TWINT is set
	while(TWSR!=0x08);					//checking if  status code is correct



	TWDR=0xA0;							//selecting the slave(1010 000)[first 4 bits is unique device id for 24c02 ,3 bits chip enable and last bit for write mode is 0]
	TWCR=0x84;							//enabling TWI and set TWINT
	while(!(TWCR&0x80));				//checking if TWINT is set
	while(TWSR!=0x18);					//checking if  status code is correct



	TWDR=add;							//choosing the memory address    ON 24c02
	TWCR=0x84;							//enabling TWI and set TWINT
	while(!(TWCR&0x80));				//checking if TWINT is set
	while(TWSR!=0x28);					//checking if  status code is correct



	TWDR=data;							//sending data byte
	TWCR=0x84;							//enabling TWI and set TWINT
	while(!(TWCR&0x80));				//checking if TWINT is set
	while(TWSR!=0x28);					//checking if  status code is correct



	TWCR=0x94;							//sending stop bit
	delayms(20);


}

unsigned char read(unsigned char add)	//random address read
{
	unsigned char a;

	TWBR=0XFF;							//lowest possible scl frequency
	TWSR=0X00;							//precscalar set to 1

	TWCR=0XA4;							//start bit
	while(!(TWCR&0x80));				//checking if TWINT is set
	while(TWSR!=0x08);					//checking if  status code is correct



	TWDR=0xA0;							//selecting the slave in write mode
	TWCR=0x84;							//enabling TWI and set TWINT
	while(!(TWCR&0x80));				//checking if TWINT is set
	while(TWSR!=0x18);					//checking if  status code is correct


	TWDR=add;							//choosing the address   0X08 ON 24c02
	TWCR=0x84;							//enabling TWI and set TWINT
	while(!(TWCR&0x80));				//checking if TWINT is set
	while(TWSR!=0x28);					//checking if  status code is correct


	TWCR=0XA4;							//ReStart bit
	while(!(TWCR&0x80));				//checking if TWINT is set
	while(TWSR!=0x10);					//checking if  status code is correct

	TWDR=0xA1;							//selecting the slave and READ mode
	TWCR=0x84;							//enabling TWI and set TWINT
	while(!(TWCR&0x80));				//checking if TWINT is set
	while(TWSR!=0x40);					//checking if  status code is correct

	TWCR=0x84;							//enabling TWI and set TWINT

	while(!(TWCR&0x80));				//checking if TWINT is set
	while(TWSR!=0x58);					//checking if  status code is correct
	a=TWDR;
	TWCR=0x94;							//stop bit

	delayms(2);
	return a;
}
#endif
