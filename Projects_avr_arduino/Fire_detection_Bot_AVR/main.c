//blink led using external interrupt
//interrupt at falling edge
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 12000000UL

ISR(INT1_vect)//external interrupt 1 interrupt definition
{
    OCR1A=OCR1B=500;
	PORTB=0x0F;//toggle on board led
	PORTD=0x60;
	PORTC=0x01;
	_delay_ms(2000);
	PORTD=0xF0;
	PORTB=0x00;
}

void main()
{
    sei();//activate glabal interrupt
    GICR=0x80;//select interrupt channel
    MCUCR=0x0C;//select nature of interrupt signal
	TCCR1A=0XA0;
	 TCCR1B=0X13;
	 ICR1=1250;
    OCR1A=OCR1B=500;
    DDRC=0x01;
	DDRB=0x0F;
	DDRD=0xF0;
	
	PORTD=0x90;
	PORTB=0x0F;
	PORTC=0x00;

    while(1)//create external signal.
    //for external interrupt to work we need and external interrupt
    //to do this we are generating and signal at the PORTA0 and feeding it to the INT1 pin of the MCU
    //you have to physically connect(or short-circuit) INT0 pin and PORTA0
    //INT0 pin is PORTD3
    {//toggle output to create external signal

    }
}
