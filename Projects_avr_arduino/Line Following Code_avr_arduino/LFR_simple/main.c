//ICC-AVR application builder : 5/22/2014 3:55:49 PM
// Target : M8
// Crystal: 12.000Mhz

#include <avr\io.h>



void main(void)
{


PORTB =  0x00;
 DDRB  = 0x00;
 PORTC = 0x00; //m103 output only
 DDRC  = 0x00;
 PORTD = 0x00;
 DDRD  = 0xF0;
 
  while (1){
 switch(PINC&0b00001110){
 case 0b00001110:PORTD=0x80;
 	  			 break;
 case 0b00001100:PORTD=0x80;
 	  			 break;
 case 0b00001000:PORTD=0x80;
 	  			 break;
 case 0b00000110:PORTD=0x10;
 	  			 break;
 case 0b00000010:PORTD=0x10;
 	  			 break;
 case 0b00000000:PORTD=0x90;
 		  		 break;
 case 0b00001010:PORTD=0x90;
 		  		 break;
 default:PORTD=0x90;
 		 break;
 
 }
}
}

