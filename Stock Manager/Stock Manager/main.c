#include "Declarations.h"

int main(void)
{
	int choice;
	int i;

	static char fgr = 'G';
	static char bgr = 'N';
	
	Stock *head;	
	head = NULL;

	display_noScrollbar();
	display_fullscreen();
	displayMsg_startInfo(fgr, bgr);
	do
	{
		clrScr();
		displayMsg_menuChoice(fgr, bgr);
		choice = scan_Arrow(1, 5, 20, 3, fgr, bgr);
		menuLaunch(choice, &head);
	} while (choice < 5);
	free_allStocks(&head);

	return 0;
}