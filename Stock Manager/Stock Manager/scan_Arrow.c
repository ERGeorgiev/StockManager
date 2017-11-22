#include "Declarations.h"

int scan_Arrow(int axis, int limit, int X, int Y, char fgr, char bgr)
{
	int place = 0, axisX = X, axisY = Y;
	unsigned char ch;

	if (limit > 0)
	{
		printColor(axisX, axisY, "*", fgr, bgr);
		set_cursor_position(axisX, axisY);
		do
		{
			ch = (char)_getch();
			if (ch == 0 || ch == 0xE0)
			{
				ch = (char)_getch();
				switch (ch)
				{
				case KEY_UP:
					if (axis == 0 || axis == 1)
					{
						if (place > 0)
						{
							printf(" \b");
							axisY--;
							printColor(axisX, --axisY, "*", fgr, bgr);
							set_cursor_position(axisX, axisY);
							place--;
						}
						else if (place == 0)
						{
							printf(" \b");
							axisY += ((limit - 1) * 2);
							printColor(axisX, axisY, "*", fgr, bgr);
							set_cursor_position(axisX, axisY);
							place = limit - 1;
						}
					}
					break;
				case KEY_DOWN:
					if (axis == 0 || axis == 1)
					{
						if (place + 1 < limit)
						{
							printf(" \b");
							axisY++;
							printColor(axisX, ++axisY, "*", fgr, bgr);
							set_cursor_position(axisX, axisY);
							place++;
						}
						else if (place + 1 == limit)
						{
							printf(" \b");
							axisY = Y;
							printColor(axisX, axisY, "*", fgr, bgr);
							set_cursor_position(axisX, axisY);
							place = 0;
						}
					}
					break;
				case KEY_LEFT:
					if (axis == 0 || axis == 2)	return ch;
					break;
				case KEY_RIGHT:
					if (axis == 0 || axis == 2)	return ch;
					break;
				}
			}
		} while (ch != KEY_ENTER && ch != KEY_ESC);
		if (ch == KEY_ESC) return ch;
		return place+1;
	}
	else
	{
		return place;
	}
}