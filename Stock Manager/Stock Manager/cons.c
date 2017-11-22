#include "Declarations.h"

/*
possible values for color attribute are (multiple of these can be used with bitwise OR):

#define FOREGROUND_BLUE      0x0001 // text color contains blue.
#define FOREGROUND_GREEN     0x0002 // text color contains green.
#define FOREGROUND_RED       0x0004 // text color contains red.
#define FOREGROUND_INTENSITY 0x0008 // text color is intensified.
#define BACKGROUND_BLUE      0x0010 // background color contains blue.
#define BACKGROUND_GREEN     0x0020 // background color contains green.
#define BACKGROUND_RED       0x0040 // background color contains red.
#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.
*/

int
GetKey()
{
	int ch;
	ch = _getch();
	if (ch == 0 || ch == 224){
		ch = _getch();
		ch += 256;
	}
	return ch;
}

void
InitProgram(void)
{
	sprintf_s(Caption, _countof(Caption), "Stock MANAGER v1.0");
	mainchInfo = get_screen(&coord);
	init_console(KBValue);
}

void
init_console(unsigned int Value)
{
	SetConsoleCP(Value);
	SetConsoleOutputCP(Value);
	return;
}

void
set_cursor_position(int x, int y)
{
	COORD c;
	HANDLE hCons;
	hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	c.X = (SHORT)x;
	c.Y = (SHORT)y;
	SetConsoleCursorPosition(hCons, c);
	return;
}

void
set_cursor_visible(int Visible)
{
	HANDLE hCons;
	CONSOLE_CURSOR_INFO c;
	hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hCons, &c);
	c.bVisible = Visible;
	SetConsoleCursorInfo(hCons, &c);
	return;
}

void
set_cursor_size(int large)
{
	HANDLE hCons;
	CONSOLE_CURSOR_INFO c;
	hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	if (large)
		c.dwSize = 100;
	else
		c.dwSize = 25;
	c.bVisible = 1;
	SetConsoleCursorInfo(hCons, &c);
	return;
}

CHAR_INFO *get_screen(COORD *cd)
{
	HANDLE hCons;
	CONSOLE_SCREEN_BUFFER_INFO ConsInfo;
	CHAR_INFO *buffer;
	SMALL_RECT rect;
	COORD c1;
	hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hCons, &ConsInfo);
	c1.X = 0;
	c1.Y = 0;
	rect = ConsInfo.srWindow;
	buffer = (CHAR_INFO *)calloc(ConsInfo.dwSize.X * ConsInfo.dwSize.Y, sizeof (CHAR_INFO));
	if (ReadConsoleOutput(hCons, buffer, ConsInfo.dwSize, c1, &ConsInfo.srWindow) == 0) {
		printf("Failed reading %d\n", (int)GetLastError());
		GetKey();
		return NULL;
	}
	if (cd != NULL)
		*cd = ConsInfo.dwSize;
	return buffer;
}

void put_screen(COORD *cd, CHAR_INFO *buffer)
{
	HANDLE hCons;
	COORD c1;
	//	SMALL_RECT rect;
	CONSOLE_SCREEN_BUFFER_INFO ConsInfo;

	hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	c1.X = 0;
	c1.Y = 0;
	GetConsoleScreenBufferInfo(hCons, &ConsInfo);

	if (WriteConsoleOutput(hCons, buffer, *cd, c1, &ConsInfo.srWindow) == 0) {
		printf("Failed writing\n");
		return;
	}
	return;
}
//
//void
//set_window_title(char *str)
//{
//	SetConsoleTitle(str);
//	return;
//}

void clrScr(void)
{
	CHAR_INFO *x;
	COORD cd;
	int i, j;
	x = get_screen(&cd);
	for (j = 0; j < cd.Y; j++)
	for (i = 0; i < cd.X; i++) {
		x[j * cd.X + i].Char.AsciiChar = 0;
		x[j * cd.X + i].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
	}
	put_screen(&cd, x);
	free(x);
	return;
}
