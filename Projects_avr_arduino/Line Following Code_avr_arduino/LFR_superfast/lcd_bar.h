#ifndef LCD_BAR_H_INCLUDED
#define LCD_BAR_H_INCLUDED


void lcdbar(unsigned char);

unsigned char b;

void lcdbar(unsigned char a)
{
    b=a;
	
	switch (b)
	  {
		case 0: //0
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(0);
			lcd_char(0);
			lcd_char(0);
			lcd_char(0);
		}
		break;

		case 1: //1
		{
            lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(0);
			lcd_char(0);
			lcd_char(0);
			lcd_char(1);
        }
		break;

		case 2: //2
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(0);
			lcd_char(0);
			lcd_char(1);
			lcd_char(0);
		}
		break;

		case 3: //3
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(0);
			lcd_char(0);
			lcd_char(1);
			lcd_char(1);
		}
		break;


		case 4: //4
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(0);
			lcd_char(1);
			lcd_char(0);
			lcd_char(0);
		}
		break;

		case 5: //5
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(0);
			lcd_char(1);
			lcd_char(0);
			lcd_char(1);
		}
		break;

		case 6: //6
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(0);
			lcd_char(1);
			lcd_char(1);
			lcd_char(0);
		}
		break;

		case 7: //7
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(0);
			lcd_char(1);
			lcd_char(1);
			lcd_char(1);
		}
		break;

		case 8: //8
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(1);
			lcd_char(0);
			lcd_char(0);
			lcd_char(0);
		}
		break;

		case 9: //9
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(1);
			lcd_char(0);
			lcd_char(0);
			lcd_char(1);
		}
		break;

		case 10: //10
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(1);
			lcd_char(0);
			lcd_char(1);
			lcd_char(0);
		}
		break;

		case 11: //11
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(1);
			lcd_char(0);
			lcd_char(1);
			lcd_char(1);
		}
		break;

		case 12: //12
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(1);
			lcd_char(1);
			lcd_char(0);
			lcd_char(0);
		}
		break;

		case 13: //13
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(1);
			lcd_char(1);
			lcd_char(0);
			lcd_char(1);
		}
		break;

		case 14: //14
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(1);
			lcd_char(1);
			lcd_char(1);
			lcd_char(0);
		}
		break;

		case 15: //15
		{
			lcd_gotoxy(0,5);
			lcd_char(0);
			lcd_char(1);
			lcd_char(1);
			lcd_char(1);
			lcd_char(1);
		}
		break;

		case 16: //16
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(0);
			lcd_char(0);
			lcd_char(0);
			lcd_char(0);
		}
		break;

		case 17: //17
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(0);
			lcd_char(0);
			lcd_char(0);
			lcd_char(1);
		}
		break;

		case 18: //18
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(0);
			lcd_char(0);
			lcd_char(1);
			lcd_char(0);
		}
		break;

		case 19: //19
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(0);
			lcd_char(0);
			lcd_char(1);
			lcd_char(1);
		}
		break;

		case 20: //20
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(0);
			lcd_char(1);
			lcd_char(0);
			lcd_char(0);
		}
		break;

		case 21: //21
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(0);
			lcd_char(1);
			lcd_char(0);
			lcd_char(1);
		}
		break;

		case 22: //22
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(0);
			lcd_char(1);
			lcd_char(1);
			lcd_char(0);
		}
		break;

		case 23: //23
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(0);
			lcd_char(1);
			lcd_char(1);
			lcd_char(1);
		}
		break;

		case 24: //24
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(1);
			lcd_char(0);
			lcd_char(0);
			lcd_char(0);
		}
		break;

		case 25: //25
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(1);
			lcd_char(0);
			lcd_char(0);
			lcd_char(1);
		}
		break;

		case 26: //26
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(1);
			lcd_char(0);
			lcd_char(1);
			lcd_char(0);
		}
		break;

		case 27: //27
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(1);
			lcd_char(0);
			lcd_char(1);
			lcd_char(1);
		}
		break;

		case 28: //28
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(1);
			lcd_char(1);
			lcd_char(0);
			lcd_char(0);
		}
		break;

		case 29: //29
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(1);
			lcd_char(1);
			lcd_char(0);
			lcd_char(1);
		}
		break;

		case 30: //30
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(1);
			lcd_char(1);
			lcd_char(1);
			lcd_char(0);
		}
		break;

		case 31: //31
		{
			lcd_gotoxy(0,5);
			lcd_char(1);
			lcd_char(1);
			lcd_char(1);
			lcd_char(1);
			lcd_char(1);
		}
		break;


	  }

}


#endif // LCD_BAR_H_INCLUDED
