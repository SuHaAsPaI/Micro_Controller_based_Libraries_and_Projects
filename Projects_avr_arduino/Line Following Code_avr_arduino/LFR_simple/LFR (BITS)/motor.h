#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED


void left();
void right();
void straight();
void u_turn();

void left()
{
	PORTB=0x06;
}


void right()
{
	PORTB=0x09;
}


void straight()
{
	PORTB=0x05;
}

void u_turn()
{
	PORTB=0x06;
}


#endif // MOTOR_H_INCLUDED
