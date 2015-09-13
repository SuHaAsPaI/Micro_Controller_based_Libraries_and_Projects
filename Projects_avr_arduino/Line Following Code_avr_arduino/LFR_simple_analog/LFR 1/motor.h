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
	PORTD=0x02;
}


void right()
{
	PORTD=0x08;
}


void straight()
{
	PORTD=0x0A;
}

void u_turn()
{
	PORTD=0x0A;
}


#endif // MOTOR_H_INCLUDED
