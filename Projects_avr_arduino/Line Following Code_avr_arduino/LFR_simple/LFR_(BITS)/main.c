#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 12000000
#include <avr/interrupt.h>
#include "motor.h"
#include "adc.h"

int main(void)
{
    DDRB |= (1 << DDB3);		// PB3 is now an output

    OCR2 = 255;					// set PWM for n % duty cycle
	TCCR2 |= (1 << COM21);		 // set none-inverting mode
	TCCR2 |= (1 << WGM21) | (1 << WGM20);	// set fast PWM Mode
	TCCR2 |= (1 << CS21);// set prescaler to 8 and starts PWM
	
	unsigned int adc[12];
	unsigned int k1,k2,k;
	
    adc[1]= getdata(0x00);
    adc[2]= getdata(0x01);
    adc[3]= getdata(0x02);
    adc[4]= getdata(0x03);
    adc[5]= getdata(0x04);
    adc[6]= getdata(0x05);
	
	while (1)
    {
    }
}