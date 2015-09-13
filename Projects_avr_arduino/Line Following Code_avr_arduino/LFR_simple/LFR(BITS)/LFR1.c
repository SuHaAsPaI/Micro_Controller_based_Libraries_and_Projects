// Code to solve the line follwer competition at Quark '13

/* 
Connections for this line follower

Left sensor>>PORT B0
Middle sensor>>PORT B 1
Right sensor>>PORT B 2

LED>> PORT C0;

PORTD= Ob 0000 RIGHTMOTOR LEFTMOTOR

*/


#include<avr/io.h>


#define L 0x06  						
#define S 0x0A 
#define R 0x09
#define U 0x06
/*
unsigned int a=0;		
 //sei();		*/									// int a is a global variable

/*

ISR(TIMER0_OVF_vect){

switch(a){

case 0: break;

case 1: break;
case 2: break;

case 3:{
PORTC=0x01;  							// LED blink!!
	
	a=0;								
										//
}

}

}
*/

int main(void)
{


DDRD=0x00;
PORTD=0x07;
DDRB=0x0F; 

while(1)
{


switch(PIND & 0x07)
{

case 0x00:{

PORTB= R;								 // T-junction function here = turn Right

}

case 0x01:{

PORTB= L;
/*								//Go-left function>>Hard turn
a++;
*/
break;

}

case 0x02 :
{
PORTB=0X00;
}	
 break;			//impossible configuration>>rail-like


case 0x03:{

		
PORTB= L;						//small left>>notice here i dont increment 'a'
break;
}


case 0x04:{

PORTB= R;								//Go-right function>>Hard turn

//a++;

break;

}

case 0x05:{

PORTB= S;								//Go-straight function 

break;

}

case 0x06:{

PORTB=R;
break;


}

case 0x07:{
				
									//U-turn function
	while((PIND & 0X07)==0X07);
    PORTB=U;
	//while(((PIND & 0X07)!=0X07)||((PIND & 0X07)==0X00)||((PIND & 0X07)==0X04)||((PIND & 0X07)==0X06));
	break;
									//basic structure here is 
	
									//turn around>>go straight>>blink at next junction>>TURN!>>set the particular value of a!
/*


switch(a){


	case(0){								//set a=0 after blinking at the junction
	
	PORTD=U;
	
	while();
	while();
	
	PORTD=S;
	
	if(PINB==0X01 || PINB==0X04){
	a=3;	
	
	}
	
	a=0;
	
	}				
	
	case:(1){								//set a=2 after.........
	
	
	PORTD=U;
	
	while();
	while();
	
	PORTD=S;
	
	if(PINB==0X01 || PINB==0X04){
	a=3;	
	
	}
	
	a=2;
	
	}		
	
	case:(2){										//set a=1 after.......


	PORTD=U;
	
	while();
	while();
	
	PORTD=S;
	
	if(PINB==0X01 || PINB==0X04){
	a=3;	
	
	}
	
	a=1;

}

}

break;

}
*/




}









}}}