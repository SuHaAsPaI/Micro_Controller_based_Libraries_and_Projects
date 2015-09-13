
/***********************************************************************

Headerfile for make ADC convertion

***********************************************************************
*AUTHOR: Suhaas Pai
*Target system: AVR devlopment board
*Microcontroller: ATmega8/Atmega32A
*Clock: 16MHz
*COMPILER: WinAVR/ Amel Studio 6.1
*last modified 09/03/2012



//************************************************************//**//*********//*	adc.h

*/

#ifndef _ADC_H_
#define _ADC_H_						//This is the header for AVR Microcontroller.

unsigned int adcdata,adcdata1;

 void adc_init()
 {
  ADCSRA=0X86;						//ADC enable, ADC interrupt enable, set prescaller to 64
  		
 }
 unsigned char getdata(unsigned char chno)	
  {
    ADMUX=0X60;						//right align the ADC result
    ADMUX|=chno;					//select the ADC channel
    ADCSRA|=0X40;					//start ADC convertion
    _delay_ms(1);					//give some time delay to complit the aDC convertion
	return ADCH;
  }

#endif 