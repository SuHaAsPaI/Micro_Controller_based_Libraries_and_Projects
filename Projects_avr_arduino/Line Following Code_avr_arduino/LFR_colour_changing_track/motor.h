#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED


void left();
void right();
void slight_left();
void slight_right();
void straight();
void u_turn();

void left()
{
	PORTC=0x06;
}


void right()
{
	PORTC=0x09;
}

void slight_left()
{
	PORTC=0x02;
}


void slight_right()
{
	PORTC=0x08;
}

void straight()
{
	PORTC=0x0A;
}

void u_turn()
{
	PORTC=0x06;
}


#endif // MOTOR_H_INCLUDED
