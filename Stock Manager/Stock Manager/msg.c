#include "Declarations.h"

/*
possible values for color attribute are (multiple of these can be used with bitwise OR):

#define fgrGROUND_BLUE      0x0001 // text color contains blue.
#define fgrGROUND_GREEN     0x0002 // text color contains green.
#define fgrGROUND_RED       0x0004 // text color contains red.
#define fgrGROUND_INTENSITY 0x0008 // text color is intensified.
#define BACKGROUND_BLUE      0x0010 // background color contains blue.
#define BACKGROUND_GREEN     0x0020 // background color contains green.
#define BACKGROUND_RED       0x0040 // background color contains red.
#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.
*/
void displayMsg_critStock(char fgr, char bgr)
{
	clrScr();
	printColor(-1, 0, "================================================================================", fgr, bgr);
	printColor(-1, 1, "=                                   CRITERIA                                   =", fgr, bgr);
	printColor(-1, 2, "================================================================================", fgr, bgr);
	printColor(-1, 3, "= Provider Name:                                                               =", fgr, bgr);
	printColor(-1, 4, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 5, "= From: dd/mm/yyyy = To: dd/mm/yyyy                                            =", fgr, bgr);
	printColor(-1, 6, "================================================================================", fgr, bgr);
}

void displayMsg_findStock(char fgr, char bgr)
{
	clrScr();
	printColor(-1, 0, "========================", fgr, bgr);
	printColor(-1, 1, "=      EDIT Stock      =", fgr, bgr);
	printColor(-1, 2, "========================", fgr, bgr);
	printColor(-1, 3, "= Enter ID:            =", fgr, bgr);
	printColor(-1, 4, "========================", fgr, bgr);
}

void displayMsg_qtyStock(char fgr, char bgr)
{
	clrScr();
	printColor(-1, 0, "========================", fgr, bgr);
	printColor(-1, 1, "=      EDIT Stock      =", fgr, bgr);
	printColor(-1, 2, "========================", fgr, bgr);
	printColor(-1, 3, "= Enter ID:            =", fgr, bgr);
	printColor(-1, 4, "=----------------------=", fgr, bgr);
	printColor(-1, 5, "= Value:               =", fgr, bgr);
	printColor(-1, 6, "========================", fgr, bgr);
}

void displayMsg_barcodeStock(char fgr, char bgr)
{
	clrScr();
	printColor(-1, 0, "=================================================", fgr, bgr);
	printColor(-1, 1, "=                  EDIT Stock                   =", fgr, bgr);
	printColor(-1, 2, "=================================================", fgr, bgr);
	printColor(-1, 3, "= Enter Barcode:                                =", fgr, bgr);
	printColor(-1, 4, "=-----------------------------------------------=", fgr, bgr);
	printColor(-1, 5, "= Value:                                        =", fgr, bgr);
	printColor(-1, 6, "=================================================", fgr, bgr);
}

void displayMsg_chooseSort(char fgr, char bgr)
{
	printColor(-1, 0, "======================================================================", fgr, bgr);
	printColor(-1, 1, "=                           SORTING METHOD                           =", fgr, bgr);
	printColor(-1, 2, "======================================================================", fgr, bgr);
	printColor(-1, 3, "= Sort by ID                                =", fgr, bgr);
	printColor(-1, 4, "=--------------------------------------------------------------------=", fgr, bgr); printColor(3, 4, "==", fgr, bgr);
	printColor(-1, 5, "= Sort by Stock Name                                                             =", fgr, bgr); printColor(3, 5, "= ", fgr, bgr);
	printColor(-1, 6, "=--------------------------------------------------------------------=", fgr, bgr); printColor(3, 6, "=-", fgr, bgr);
	printColor(-1, 7, "= Sort by Provider's Name                                                            =", fgr, bgr); printColor(3, 7, "= ", fgr, bgr);
	printColor(-1, 8, "=--------------------------------------------------------------------=", fgr, bgr); printColor(3, 8, "=-", fgr, bgr);
	printColor(-1, 9, "= Quantity:                                                          =", fgr, bgr); printColor(3, 9, "= ", fgr, bgr);
	printColor(-1, 10, "=--------------------------------------------------------------------=", fgr, bgr); printColor(3, 10, "=-", fgr, bgr);
	printColor(-1, 11, "= Date:   .  .                                                       =", fgr, bgr); printColor(3, 11, "= ", fgr, bgr);
	printColor(-1, 12, "=--------------------------------------------------------------------=", fgr, bgr); printColor(3, 12, "=-", fgr, bgr);
	printColor(-1, 13, "= Provider's name:                                                   =", fgr, bgr); printColor(3, 13, "= ", fgr, bgr);
	printColor(-1, 14, "=--------------------------------------------------------------------=", fgr, bgr); printColor(3, 14, "=-", fgr, bgr);
	printColor(-1, 15, "= Provider's town:                                                   =", fgr, bgr); printColor(3, 15, "= ", fgr, bgr);
	printColor(-1, 16, "=--------------------------------------------------------------------=", fgr, bgr); printColor(3, 16, "=-", fgr, bgr);
	printColor(-1, 17, "= Provider's street:                                                 =", fgr, bgr); printColor(3, 17, "= ", fgr, bgr);
	printColor(-1, 18, "=--------------------------------------------------------------------=", fgr, bgr); printColor(3, 18, "=-", fgr, bgr);
	printColor(-1, 19, "= Provider's telephone: +                                            =", fgr, bgr); printColor(3, 19, "= ", fgr, bgr);
	printColor(-1, 20, "======================================================================", fgr, bgr); printColor(3, 20, "==", fgr, bgr);
	printColor(-1, 21, "= Note: Press ESCAPE to go back or ENTER to save and continue.       =", fgr, bgr);
	printColor(-1, 22, "======================================================================", fgr, bgr);
}

void displayMsg_editStock(char fgr, char bgr)
{
	printColor(-1, 0, "================================================================================", fgr, bgr);
	printColor(-1, 1, "=                                  EDIT Stock                                  =", fgr, bgr);
	printColor(-1, 2, "================================================================================", fgr, bgr);
	printColor(-1, 3, "= Stock ID (auto)  :                                                           =", fgr, bgr);
	printColor(-1, 4, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 5, "= Barcode          :                                                           =", fgr, bgr);
	printColor(-1, 6, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 7, "= Name of Product  :                                                           =", fgr, bgr);
	printColor(-1, 8, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 9, "= Name of Provider :                                                           =", fgr, bgr);
	printColor(-1, 10, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 11, "= Quantity         :                                                           =", fgr, bgr);
	printColor(-1, 12, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 13, "= Price per Unit   :                                                           =", fgr, bgr);
	printColor(-1, 14, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 15, "= Weight per Unit  :                                                           =", fgr, bgr);
	printColor(-1, 16, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 17, "= Date of Import   :                                                           =", fgr, bgr);
	printColor(-1, 18, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 19, "= Date of Export   :                                                           =", fgr, bgr);
	printColor(-1, 20, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 21, "= Note             :                                                           =", fgr, bgr);
	printColor(-1, 22, "================================================================================", fgr, bgr);
	printColor(-1, 23, "= Note: Press ESCAPE to go back or ENTER to save and continue.                 =", fgr, bgr);
	printColor(-1, 24, "================================================================================", fgr, bgr);
}

void displayMsg_StockCritBgr(int *cell, char fgr, char bgr)
{
	printColor(-1, 0, "ALL Stock", fgr, bgr);
	printBorder(3, (*cell), 74, fgr, bgr);
	printCell(3, ++(*cell), 77, fgr, bgr);
	printColor(5, (*cell), "Provider:", fgr, bgr);
	printCell(3, (*cell), 64, fgr, bgr);
	printColor(65, (*cell)++, "Produced:", fgr, bgr);
	printBorder(1, (*cell)++, 76, fgr, bgr);
}

void displayMsg_StockCritCells(int *cell, int page, unsigned int *list, int StocksCrit, Stock **head, char fgr, char bgr)
{
	int element;

	Stock *curr;

	(*cell) = 4;
	for (element = 0; element < 10 && (10 * page + 2 + element) <= StocksCrit; element++)
	{
		curr = get_Stock(list[10 * page + 1 + element], head);
		printCell(1, *cell, 4, fgr, bgr);
		printCell(3, *cell, 77, fgr, bgr);
		printColor(5, *cell, curr->name, fgr, bgr);
		printCell(3, *cell, 64, fgr, bgr);
		printColor(65, *cell, (char*)itoc(curr->ID), fgr, bgr);
		printLine(1, ++(*cell), 3, fgr, bgr);
		printLine(3, (*cell)++, 74, fgr, bgr);
	}
}

void displayMsg_StockAllBgr(int *cell, char fgr, char bgr)
{
	printColor(-1, 0, "ALL Stock", fgr, bgr);
	printBorder(3, (*cell), 74, fgr, bgr);
	printCell(3, ++(*cell), 77, fgr, bgr);
	printColor(5, (*cell), "Name:", fgr, bgr);
	printCell(3, (*cell), 64, fgr, bgr);
	printColor(65, (*cell)++, "ID:", fgr, bgr);
	printBorder(1, (*cell)++, 76, fgr, bgr);
}

void displayMsg_StockAllCells(int *cell, int page, Stock **head, char fgr, char bgr)
{
	int element;
	Stock *curr;

	(*cell) = 4;
	curr = *head;
	for (element = 0; (page != 0) && (element < 10 * page) && (curr != NULL); element++)
	{
		curr = curr->next;
	}
	for (element = 0; element < 10 && (curr != NULL); element++)
	{
		printCell(1, *cell, 4, fgr, bgr);
		printCell(3, *cell, 77, fgr, bgr);
		printColor(5, *cell, curr->name, fgr, bgr);
		printCell(3, *cell, 64, fgr, bgr);
		printColor(65, *cell, (char*)itoc(curr->ID), fgr, bgr);
		printLine(1, ++(*cell), 3, fgr, bgr);
		printLine(3, (*cell)++, 74, fgr, bgr);
		curr = curr->next;
	}
}

void displayMsg_StockPage(int page, int pages, char fgr, char bgr)
{
	printColor(36, 24, (char*)itoc(page + 1), fgr, bgr);
	printColor(38, 24, "of", fgr, bgr);
	printColor(41, 24, (char*)itoc(pages + 1), fgr, bgr);
}

void
displayMsg_add_Stock(char fgr, char bgr)
{
	printColor(-1, 0, "================================================================================", fgr, bgr);
	printColor(-1, 1, "=                                   NEW Stock                                  =", fgr, bgr);
	printColor(-1, 2, "================================================================================", fgr, bgr);
	printColor(-1, 3, "= Stock ID (auto)  :                                                           =", fgr, bgr);
	printColor(-1, 4, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 5, "= Barcode          :                                                           =", fgr, bgr);
	printColor(-1, 6, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 7, "= Name of Product  :                                                           =", fgr, bgr);
	printColor(-1, 8, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 9, "= Name of Provider :                                                           =", fgr, bgr);
	printColor(-1, 10, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 11, "= Quantity         :                                                           =", fgr, bgr);
	printColor(-1, 12, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 13, "= Price per Unit   :                                                           =", fgr, bgr);
	printColor(-1, 14, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 15, "= Weight per Unit  :                                                           =", fgr, bgr);
	printColor(-1, 16, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 17, "= Date of Import   :                                                           =", fgr, bgr);
	printColor(-1, 18, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 19, "= Date of Export   :                                                           =", fgr, bgr);
	printColor(-1, 20, "=------------------------------------------------------------------------------=", fgr, bgr);
	printColor(-1, 21, "= Note             :                                                           =", fgr, bgr);
	printColor(-1, 22, "================================================================================", fgr, bgr);
	printColor(-1, 23, "= Note: Press ESCAPE to go back or ENTER to save and continue.                 =", fgr, bgr);
	printColor(-1, 24, "================================================================================", fgr, bgr);
}

void
displayMsg_menuChoice(char fgr, char bgr)
{
	printColor(-1, 0, "==========================================", fgr, bgr);
	printColor(-1, 1, "=                  MENU                  =", fgr, bgr);
	printColor(-1, 2, "==========================================", fgr, bgr);
	printColor(-1, 3, "= = Add Stock                            =", fgr, bgr);
	printColor(-1, 4, "=----------------------------------------=", fgr, bgr);
	printColor(-1, 5, "= = Edit Stock by ID                     =", fgr, bgr);
	printColor(-1, 6, "=----------------------------------------=", fgr, bgr);
	printColor(-1, 7, "= = Edit Stock by Barcode                =", fgr, bgr);
	printColor(-1, 8, "=----------------------------------------=", fgr, bgr);
	printColor(-1, 9, "= = Display all Stocks                   =", fgr, bgr);
	printColor(-1, 10, "=----------------------------------------=", fgr, bgr);
	printColor(-1, 11, "= = Exit                                 =", fgr, bgr);
	printColor(-1, 12, "==========================================", fgr, bgr);
	set_cursor_position(29, 23);
}


void
displayMsg_startInfo(char fgr, char bgr)
{

	printColor(-1, 1, "You are running \"Stock Manager v1.0\".", fgr, bgr);
	printColor(0, 3, "After these messages, a menu will appear.", fgr, bgr);
	printColor(0, 5, "You can make your choice using the keyboard's arrows.", fgr, bgr);
	printColor(0, 6, "Up and Down keys to browse the menu.", fgr, bgr);
	printColor(0, 7, "When available, Left and Right keys switch between pages.", fgr, bgr);
	printColor(0, 9, "You can press ESCAPE to go back in many situations.", fgr, bgr);
	printColor(0, 10, "You can press ENTER to save and continue in many situations.", fgr, bgr);
	printColor(0, 12, "This message only shows the first time you start this program.", fgr, bgr);
	printColor(-1, 23, "Press any key to continue to the menu...", fgr, bgr);
	_getch();
}

void printColor(int col, int row, char msg[MAX], char fgr, char bgr)
{
	int ch; WORD fgrColor, bgrColor;

	charToColor(fgr, bgr, &fgrColor, &bgrColor);
	InitProgram();

	if (col == -1)
	{
		col = (80 - strlen(msg)) / 2;
	}
	for (ch = 0; msg[ch] != 0; col++, ch += 1)
	{
		mainchInfo[row * coord.X + col].Char.AsciiChar = msg[ch];
		mainchInfo[row * coord.X + col].Attributes = fgrColor | bgrColor | FOREGROUND_INTENSITY;
	}

	set_cursor_position(col, row);
	put_screen(&coord, mainchInfo);
	free(mainchInfo);
}

void printLine(int col, int row, int length, char fgr, char bgr)
{
	int ch; WORD fgrColor, bgrColor;

	charToColor(fgr, bgr, &fgrColor, &bgrColor);

	InitProgram();

	if (col == -1)
	{
		col = (80 - length) / 2;
	}
	mainchInfo[row * coord.X + col].Char.AsciiChar = '=';
	mainchInfo[row * coord.X + col].Attributes = fgrColor | bgrColor | FOREGROUND_INTENSITY;
	col++;
	for (ch = 1; (length - 1) != ch; col++, ch += 1)
	{
		mainchInfo[row * coord.X + col].Char.AsciiChar = '-';
		mainchInfo[row * coord.X + col].Attributes = fgrColor | bgrColor | FOREGROUND_INTENSITY;
	}
	mainchInfo[row * coord.X + col].Char.AsciiChar = '=';
	mainchInfo[row * coord.X + col].Attributes = fgrColor | bgrColor | FOREGROUND_INTENSITY;

	set_cursor_position(col, row);
	put_screen(&coord, mainchInfo);
	free(mainchInfo);
}

void printBorder(int col, int row, int length, char fgr, char bgr)
{
	int *ch; WORD fgrColor, bgrColor;

	memLoc(&ch, sizeof(*ch));

	charToColor(fgr, bgr, &fgrColor, &bgrColor);

	InitProgram();

	if (col == -1)
	{
		col = (80 - length) / 2;
	}
	for (*ch = 0; length > *ch; col++, *ch += 1)
	{
		mainchInfo[row * coord.X + col].Char.AsciiChar = '=';
		mainchInfo[row * coord.X + col].Attributes = fgrColor | bgrColor | FOREGROUND_INTENSITY;
	}
	free(ch);

	set_cursor_position(col, row);
	put_screen(&coord, mainchInfo);
	free(mainchInfo);
}

void printCell(int col, int row, int length, char fgr, char bgr)
{
	WORD fgrColor, bgrColor;

	charToColor(fgr, bgr, &fgrColor, &bgrColor);

	InitProgram();

	if (col == -1)
	{
		col = (80 - length) / 2;
		mainchInfo[row * coord.X + col].Char.AsciiChar = '=';
		mainchInfo[row * coord.X + col].Attributes = fgrColor | bgrColor | FOREGROUND_INTENSITY;
		col = col + length - 1;
		mainchInfo[row * coord.X + col].Char.AsciiChar = '=';
		mainchInfo[row * coord.X + col].Attributes = fgrColor | bgrColor | FOREGROUND_INTENSITY;
	}
	else
	{
		mainchInfo[row * coord.X + col].Char.AsciiChar = '=';
		mainchInfo[row * coord.X + col].Attributes = fgrColor | bgrColor | FOREGROUND_INTENSITY;
		col = length - 1;
		mainchInfo[row * coord.X + col].Char.AsciiChar = '=';
		mainchInfo[row * coord.X + col].Attributes = fgrColor | bgrColor | FOREGROUND_INTENSITY;
	}

	set_cursor_position(col, row);
	put_screen(&coord, mainchInfo);
	free(mainchInfo);
}

void printSpace(int col, int row, int length, char fgr, char bgr)
{
	WORD fgrColor, bgrColor;

	charToColor(fgr, bgr, &fgrColor, &bgrColor);

	InitProgram();

	if (col == -1)
	{
		col = (80 - length) / 2;
	}
	for (; length != 0; col++, length--)
	{
		mainchInfo[row * coord.X + col].Char.AsciiChar = ' ';
		mainchInfo[row * coord.X + col].Attributes = fgrColor | bgrColor | FOREGROUND_INTENSITY;
	}

	set_cursor_position(col, row);
	put_screen(&coord, mainchInfo);
	free(mainchInfo);
}

void charToColor(char fgr, char bgr, WORD *fgrColor, WORD *bgrColor)
{
	switch (fgr)
	{
	case 'B':
		*fgrColor = 0x0001;
		break;
	case 'G':
		*fgrColor = 0x0002;
		break;
	case 'R':
		*fgrColor = 0x0004;
		break;
	case 'N':
		*fgrColor = 0;
		break;
	}
	switch (bgr)
	{
	case 'B':
		*bgrColor = 0x0010;
		break;
	case 'G':
		*bgrColor = 0x0020;
		break;
	case 'R':
		*bgrColor = 0x0040;
		break;
	case 'N':
		*bgrColor = 0;
		break;
	}
}