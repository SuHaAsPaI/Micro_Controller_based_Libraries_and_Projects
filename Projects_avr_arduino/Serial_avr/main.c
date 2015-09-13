#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 16000000
#include <inttypes.h>
#include <string.h>

volatile char b[10];
volatile int j=0;

void uart_init(uint16_t);
char uart_read_byte(void);
void uart_write_char(char);
void uart_flush(void);


ISR(USART_RXC_vect)
{
		b[j]=uart_read_byte();
		j++;
}



void uart_init(uint16_t ubrr_value)  // Function to initiate UART
{
    UBRRL = ubrr_value;
    UBRRH = (ubrr_value>>8);

    UCSRC=(1<<URSEL)|(3<<UCSZ0);
    UCSRB=(1<<RXEN)|(1<<TXEN);
	UCSRB |= (1<< RXCIE);
}



char uart_read_byte(void)			//Function to read the data {							// received from matlab or 
{   while(!(UCSRA & (1<<RXC)))		//any other sources
   {
   }

   return UDR;
}




void uart_write_char(char data)		//Function to send data to
{							//matlab or to any other
    while(!(UCSRA & (1<<UDRE)))		//device
   {
   }

   UDR=data;
}




void uart_flush(void) //TO CLEAR BUFFER
{
unsigned char dummy;
while( UCSRA & (1<<RXC) ) dummy = UDR;
}




void main()
{
	unsigned char data;
	
	char a[10]="Hi Suhaas ";
    int i=0;
	sei();

   uart_init(103); //9600 baud rate reffer data sheet

while(1)
{
//	 k=strs
	 if(b == 'Hi ')
	 {
		for(i=0;i<=9;i++)
		{
			uart_write_char(a[i]);		//send same data as received
		}
		uart_flush();
		j=0;
	}
	 //else

}
}