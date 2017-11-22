#include "Declarations.h"

void menuLaunch(int menu, Stock **head)
{
	switch (menu)
	{
	case 1:
		menu_StockAdd(head);
		break;
	case 2:
		menu_StockFind(head);
		break;
	case 3:
		menu_StockBarcode(head);
		break;
	case 4:
		menu_StockAll(head);
		break;
	default:
		break;
	}
}

int menu_StockProv(Stock **head)
{
	static char fgr = 'G';
	static char bgr = 'N';

	unsigned int StocksTotal = 0, i;

	Stock ***toSort;
	memLoc((void**)&toSort, sizeof(Stock));

	StocksTotal = get_StockAll(head);
	memLoc(&(**toSort), StocksTotal * sizeof(Stock));

	for (i = 0; (StocksTotal > 0) && (i < StocksTotal) && (head != NULL); i++)
	{
		if (i == 0) (*toSort)[0] = *head;
		else
		{
			(*toSort)[i] = (*toSort)[i - 1]->next;
		}
	}

	clrScr();
	if (*head == NULL)
	{
		return 0;
	}
	else
	{
		sort_StockProv(toSort, StocksTotal);
		return 1;
		//sort_StockCrit(&StocksCrit, list, name, dateFrom, dateTo, head);
		//pages_StockCrit(StocksCrit, list, head, fgr, bgr);

		//free(list);
	}
}

void sort_StockProv(Stock ***toSort, unsigned int StocksTotal)
{
	unsigned int i;

	qsort(*toSort, StocksTotal, sizeof(Stock), cmp_StockProv);

	for (i = 0; StocksTotal > 0 && i < StocksTotal; i++)
	{
		printColor(-1, i, (*toSort)[i]->name, 'G', 'B');
	}

	system("pause");
}

int cmp_StockProv(const void *a, const void *b)
{
	return strcmp(((Stock *)a)->name, ((Stock *)b)->name);
}

void menu_StockCrit(Stock **head)
{
	static char fgr = 'G';
	static char bgr = 'N';

	int StocksCrit = 0, Stocks;
	unsigned int *list, dateFrom[3], dateTo[3];

	char name[NAME_LEN];

	clrScr();
	if (*head == NULL)
	{
		return;
	}
	else
	{
		Stocks = get_StockAll(head);
		memLoc(&list, Stocks * sizeof(unsigned int));

		get_StockCrit(name, dateFrom, dateTo, fgr, bgr);
		sort_StockCrit(&StocksCrit, list, name, dateFrom, dateTo, head);
		pages_StockCrit(StocksCrit, list, head, fgr, bgr);

		free(list);
	}
}

void get_StockCrit(char *name, unsigned int *dateFrom, unsigned int *dateTo, char fgr, char bgr)
{
	displayMsg_critStock(fgr, bgr);
	set_cursor_position(17, 3);
	if (!scan_Str(name, NAME_LIMIT)) return;

	printColor(8, 5, "  ", fgr, bgr);
	set_cursor_position(8, 5);
	if (!scan_UnsInt(&(dateTo[2]), 4)) return;
	printColor(11, 5, "  ", fgr, bgr);
	set_cursor_position(11, 5);
	if (!scan_UnsInt(&(dateFrom[1]), 2)) return;
	printColor(14, 5, "    ", fgr, bgr);
	set_cursor_position(14, 5);
	if (!scan_UnsInt(&(dateFrom[2]), 4)) return;
	printColor(25, 5, "  ", fgr, bgr);
	set_cursor_position(25, 5);
	if (!scan_UnsInt(&(dateTo[0]), 2)) return;
	printColor(28, 5, "  ", fgr, bgr);
	set_cursor_position(28, 5);
	if (!scan_UnsInt(&(dateTo[1]), 2)) return;
	printColor(31, 5, "    ", fgr, bgr);
	set_cursor_position(31, 5);
	if (!scan_UnsInt(&(dateTo[2]), 4)) return;
}

void sort_StockCrit(int *StocksCrit, unsigned int *list, char *name, unsigned int *dateFrom, unsigned int *dateTo, Stock **head)
{
	int temp, i, i2;

	Stock *curr;

	for ((*StocksCrit) = 0, curr = *head; curr != NULL;)
	{
		if (strcmp(curr->nameProv, name) == 0)
		{
			if (1)
			{
				list[(*StocksCrit)] = curr->ID;
				(*StocksCrit)++;
			}
		}
		curr = curr->next;
	}

	for (i = 0, i2 = (*StocksCrit) - 1; ((*StocksCrit) / 2) > i; i++, i2--)
	{
		temp = list[i];
		list[i] = list[i2];
		list[i2] = temp;
	}
}

void pages_StockCrit(int StocksCrit, unsigned int *list, Stock **head, char fgr, char bgr)
{
	int StocksTemp = StocksCrit, choice, chosen, cell = 0, pages = 0, page = 0;

	Stock *curr;

	clrScr();

	printCell(-1, cell, 13, fgr, bgr);
	printColor(-1, cell++, "NO Stock", fgr, bgr);

	curr = *head;
	if (StocksCrit != 0)
	{
		displayMsg_StockCritBgr(&cell, fgr, bgr);
		displayMsg_StockCritCells(&cell, page, list, StocksCrit, head, fgr, bgr);

		while (log10(StocksTemp) > 1)
		{
			StocksTemp -= 10;
			pages++;
		}

		displayMsg_StockPage(page, pages, fgr, bgr);

		do
		{
			choice = scan_Arrow(0, ((cell - 4) / 2), 2, 4, fgr, bgr);

			switch (choice)
			{
			case KEY_LEFT:
				printf(" \b");
				if (page > 0)
				{
					clrScr();
					cell = 0;
					page--;
					printCell(-1, cell++, 13, fgr, bgr);
					displayMsg_StockCritBgr(&cell, fgr, bgr);
					displayMsg_StockCritCells(&cell, page, list, StocksCrit, head, fgr, bgr);
					displayMsg_StockPage(page, pages, fgr, bgr);
				}
				break;
			case KEY_RIGHT:
				printf(" \b");
				if (page < pages)
				{
					clrScr();
					cell = 0;
					page++;
					printCell(-1, cell++, 13, fgr, bgr);
					displayMsg_StockCritBgr(&cell, fgr, bgr);
					displayMsg_StockCritCells(&cell, page, list, StocksCrit, head, fgr, bgr);
					displayMsg_StockPage(page, pages, fgr, bgr);
				}
				break;
			}
		} while (choice == KEY_LEFT || choice == KEY_RIGHT);
		if (choice == KEY_ESC) return;

		chosen = choice + (10 * page);
		menu_StockInfo(list[chosen], head, fgr, bgr);
	}
	else _getch();
}

void menu_StockQty(Stock **head)
{
	static char fgr = 'G';
	static char bgr = 'N';

	int add;
	unsigned int choice;

	Stock *curr;

	curr = *head;
	if (curr != NULL)
	{
		displayMsg_qtyStock(fgr, bgr);
		do
		{
			printSpace(40, 3, 10, fgr, bgr);
			set_cursor_position(40, 3);
			if (scan_UnsInt(&choice, 10) == 0) return;
		} while (log10(choice) < 9);
		set_cursor_position(37, 5);
		scan_Int(&add, 9, 1);
		menu_StockMod(choice, add, head, fgr, bgr);
	}
	else
	{
		clrScr();
		printColor(-1, 0, "= NO Stock =", fgr, bgr);
		_getch();
	}
}

void menu_StockAdd(Stock **head)
{
	static char fgr = 'G';
	static char bgr = 'N';

	Stock *curr;

	clrScr();
	displayMsg_add_Stock(fgr, bgr);
	if (add_Stock(head))
	{
		if (!get_StockInput(head, fgr, bgr))
		{
			remove_Stock(&curr, head); /*Input Stock attributes, remove on esc/failure.*/
		}
	}
	else
	{
		clrScr();
		printColor(-1, 0, "STOCK LIMIT REACHED.", fgr, bgr);
		_getch();
	}

}

int get_StockInput(Stock **curr, char fgr, char bgr)
{
	int offset = 21;
	char ID[11];

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	set_cursor_position(offset, 17);
	printf("%d.%d.%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

	sprintf(ID, "%d", (*curr)->ID);
	printColor(offset, 3, ID, fgr, bgr);
	set_cursor_position(offset, 5);
	if (!scan_Str((*curr)->barcode, BARCODE_LIMIT)) return 0;
	set_cursor_position(offset, 7);
	if (!scan_Str((*curr)->name, NAME_LIMIT)) return 0;
	set_cursor_position(offset, 9);
	if (!scan_Str((*curr)->nameProv, NAMEPROV_LIMIT)) return 0;
	set_cursor_position(offset, 11);
	if (!scan_UnsInt(&(*curr)->qty, 9)) return 0;
	set_cursor_position(offset, 13);
	if (!scan_Real(&(*curr)->price, 9, 0)) return 0;
	set_cursor_position(offset, 15);
	if (!scan_Real(&(*curr)->weight, 9, 0)) return 0;
	set_cursor_position(offset, 17);
	printf("%d.%d.%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	if (_getch() != KEY_CR)
	{
		set_cursor_position(offset, 17);
		if (!scan_date(&(*curr)->dateImp)) return 0;
	}
	else
	{
		(*curr)->dateImp = (tm.tm_mday + ((tm.tm_mon+1)*pow(10, 2)) + ((tm.tm_year+1900)*pow(10, 4)));
	}
	set_cursor_position(offset, 19);
	if (!scan_date(&(*curr)->dateExp)) return 0;
	set_cursor_position(offset, 21);
	if (!scan_Str((*curr)->note, NOTE_LIMIT)) return 0;
	return 1;
}

void menu_StockFind(Stock **head)
{
	static char fgr = 'G';
	static char bgr = 'N';

	unsigned int choice;

	Stock *curr;

	curr = *head;
	if (curr != NULL)
	{
		displayMsg_findStock(fgr, bgr);
		do
		{
			printSpace(40, 3, 10, fgr, bgr);
			set_cursor_position(40, 3);
			if (scan_Int(&choice, 9, 0) == 0) return;
		} while ((choice <= ID_MIN) && (choice >= ID_MAX));
		menu_StockInfo(choice, head, fgr, bgr);
	}
	else
	{
		clrScr();
		printColor(-1, 0, "= NO Stock =", fgr, bgr);
		_getch();
	}
}

void menu_StockBarcode(Stock **head)
{
	static char fgr = 'G';
	static char bgr = 'N';

	int offset = 21;
	int cell = 0, choice = 0, found = 0, i;

	char input = 0, barcode[BARCODE_LEN];

	Stock *curr;

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	displayMsg_barcodeStock(fgr, bgr);
	
	set_cursor_position(24, 5);
	scan_Str(barcode, BARCODE_LIMIT);

	for (curr = *head; curr != NULL; curr = curr->next)
	{
		if (strcmp(barcode, curr->barcode) == 0)
		{
			found = 1;
			break;
		}
	}

	if (found)
	{
		clrScr();
		displayMsg_editStock(fgr, bgr);
		set_cursor_position(offset, 3);
		printf("%d", curr->ID);
		set_cursor_position(offset, 5);
		printf("%s", curr->barcode);
		set_cursor_position(offset, 7);
		printf("%s", curr->name);
		set_cursor_position(offset, 9);
		printf("%s", curr->nameProv);
		set_cursor_position(offset, 11);
		printf("%d", curr->qty);
		set_cursor_position(offset, 13);
		printf("%ld.%ld", real_whole(curr->price), real_decimal(curr->price));
		set_cursor_position(offset, 15);
		printf("%ld.%ld", real_whole(curr->weight), real_decimal(curr->weight));
		//Date Import
		set_cursor_position(offset, 17);
		printf("%d.%d.%d", date_day(curr->dateImp), date_month(curr->dateImp), date_year(curr->dateImp));
		//Date Export
		set_cursor_position(offset, 19);
		printf("%d.%d.%d", date_day(curr->dateExp), date_month(curr->dateExp), date_year(curr->dateExp));
		//Note
		set_cursor_position(offset, 21);
		printf("%s", curr->note);

		set_cursor_position(offset, 5);
		printf("%s", curr->barcode);
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 5, 50, fgr, bgr);
			set_cursor_position(offset, 5);
			scan_Str(curr->barcode, BARCODE_LIMIT);
			set_cursor_position(offset, 5);
			printf("%s", curr->barcode);
		}
		set_cursor_position(offset, 7);
		printf("%s", curr->name);
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 7, 50, fgr, bgr);
			set_cursor_position(offset, 7);
			scan_Str(curr->name, NAME_LIMIT);
			set_cursor_position(offset, 7);
			printf("%s", curr->name);
		}
		set_cursor_position(offset, 9);
		printf("%s", curr->nameProv);
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 9, 50, fgr, bgr);
			set_cursor_position(offset, 9);
			scan_Str(curr->nameProv, NAMEPROV_LEN);
			set_cursor_position(offset, 9);
			printf("%s", curr->nameProv);
		}
		set_cursor_position(offset, 11);
		printf("%d", curr->qty);
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 11, 50, fgr, bgr);
			set_cursor_position(offset, 11);
			scan_UnsInt(&curr->qty, 9);
			set_cursor_position(offset, 11);
			printf("%d", curr->qty);
		}
		set_cursor_position(offset, 13);
		printf("%ld.%ld", real_whole(curr->price), real_decimal(curr->price));
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 13, 50, fgr, bgr);
			set_cursor_position(offset, 13);
			scan_Real(&curr->price, 9, 0);
			set_cursor_position(offset, 13);
			printf("%ld.%ld", real_whole(curr->price), real_decimal(curr->price));
		}
		set_cursor_position(offset, 15);
		printf("%ld.%ld", real_whole(curr->weight), real_decimal(curr->weight));
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 15, 50, fgr, bgr);
			set_cursor_position(offset, 15);
			scan_Real(&curr->weight, 9, 0);
			set_cursor_position(offset, 15);
			printf("%ld.%ld", real_whole(curr->weight), real_decimal(curr->weight));
		}
		set_cursor_position(offset, 17);
		printf("%d.%d.%d", date_day(curr->dateImp), date_month(curr->dateImp), date_year(curr->dateImp));
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 17, 50, fgr, bgr);
			set_cursor_position(offset, 17);
			scan_date(&curr->dateImp);
			set_cursor_position(offset, 17);
			printf("%d.%d.%d", date_day(curr->dateImp), date_month(curr->dateImp), date_year(curr->dateImp));
		}
		set_cursor_position(offset, 19);
		printf("%d.%d.%d", date_day(curr->dateExp), date_month(curr->dateExp), date_year(curr->dateExp));
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 19, 50, fgr, bgr);
			set_cursor_position(offset, 19);
			scan_date(&curr->dateExp);
			set_cursor_position(offset, 19);
			printf("%d.%d.%d", date_day(curr->dateExp), date_month(curr->dateExp), date_year(curr->dateExp));
		}
		set_cursor_position(offset, 21);
		printf("%s", curr->note);
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 21, 50, fgr, bgr);
			set_cursor_position(offset, 21);
			scan_Str(curr->note, NOTE_LIMIT);
			set_cursor_position(offset, 21);
			printf("%s", curr->note);
		}
	}
	else
	{
		clrScr();
		printCell(-1, 0, 13, fgr, bgr);
		printColor(-1, 0, "NOT FOUND", fgr, bgr);
		_getch();
	}
}

void menu_StockAll(Stock **head)
{
	static char fgr = 'G';
	static char bgr = 'N';

	int cell = 0, elements, pages, page = 0;

	clrScr();
	printCell(-1, cell, 13, fgr, bgr);
	printColor(-1, cell++, "NO Stock", fgr, bgr);
	if ((*head) != NULL)
	{
		displayMsg_StockAllBgr(&cell, fgr, bgr);
		displayMsg_StockAllCells(&cell, page, head, fgr, bgr);
		elements = get_StockAll(head);
		pages = elements / 11;
		displayMsg_StockPage(page, pages, fgr, bgr);
		pages_StockAll(head, elements, &page, pages, &cell, fgr, bgr);
	}
	else _getch();
}

void pages_StockAll(Stock **head, int elements, int *page, int pages, int *cell, char fgr, char bgr)
{
	unsigned int choice, chosen;

	do
	{
		choice = scan_Arrow(0, (((*cell) - 4) / 2), 2, 4, fgr, bgr);
		switch (choice)
		{
		case KEY_LEFT:
			printf(" \b");
			if ((*page) > 0)
			{
				clrScr();
				(*cell) = 0;
				printCell(-1, (*cell)++, 13, fgr, bgr);
				displayMsg_StockAllBgr(cell, fgr, bgr);
				displayMsg_StockAllCells(cell, --(*page), head, fgr, bgr);
				displayMsg_StockPage((*page), pages, fgr, bgr);
			}
			break;
		case KEY_RIGHT:
			printf(" \b");
			if ((*page) < pages)
			{
				clrScr();
				(*cell) = 0;
				printCell(-1, (*cell)++, 13, fgr, bgr);
				displayMsg_StockAllBgr(cell, fgr, bgr);
				displayMsg_StockAllCells(cell, ++(*page), head, fgr, bgr);
				displayMsg_StockPage((*page), pages, fgr, bgr);
			}
			break;
		}
	} while (choice == KEY_LEFT || choice == KEY_RIGHT);
	if (choice == KEY_ESC) return;
	chosen = elements - choice - (10 * (*page)) + ID_MIN;
	menu_StockInfo(chosen, head, fgr, bgr);
}

void menu_StockInfo(unsigned int chosen, Stock **head, char fgr, char bgr)
{
	int offset = 21;
	int cell = 0, choice = 0, found = 0, i;

	char input = 0;

	Stock *curr;

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	for (curr = *head; curr != NULL; curr = curr->next)
	{
		if (curr->ID == chosen)
		{
			found = 1;
			break;
		}
	}
	if (found)
	{
		clrScr();
		displayMsg_editStock(fgr, bgr);
		set_cursor_position(offset, 3);
		printf("%d", curr->ID);
		set_cursor_position(offset, 5);
		printf("%s", curr->barcode);
		set_cursor_position(offset, 7);
		printf("%s", curr->name);
		set_cursor_position(offset, 9);
		printf("%s", curr->nameProv);
		set_cursor_position(offset, 11);
		printf("%d", curr->qty);
		set_cursor_position(offset, 13);
		printf("%ld.%ld", real_whole(curr->price), real_decimal(curr->price));
		set_cursor_position(offset, 15);
		printf("%ld.%ld", real_whole(curr->weight), real_decimal(curr->weight));
		//Date Import
		set_cursor_position(offset, 17);
		printf("%d.%d.%d", date_day(curr->dateImp), date_month(curr->dateImp), date_year(curr->dateImp));
		//Date Export
		set_cursor_position(offset, 19);
		printf("%d.%d.%d", date_day(curr->dateExp), date_month(curr->dateExp), date_year(curr->dateExp));
		//Note
		set_cursor_position(offset, 21);
		printf("%s", curr->note);

		set_cursor_position(offset, 5);
		printf("%s", curr->barcode);
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 5, 50 ,fgr, bgr);
			set_cursor_position(offset, 5);
			scan_Str(curr->barcode, BARCODE_LIMIT);
			set_cursor_position(offset, 5);
			printf("%s", curr->barcode);
		}
		set_cursor_position(offset, 7);
		printf("%s", curr->name);
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 7, 50, fgr, bgr);
			set_cursor_position(offset, 7);
			scan_Str(curr->name, NAME_LIMIT);
			set_cursor_position(offset, 7);
			printf("%s", curr->name);
		}
		set_cursor_position(offset, 9);
		printf("%s", curr->nameProv);
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 9, 50, fgr, bgr);
			set_cursor_position(offset, 9);
			scan_Str(curr->nameProv, NAMEPROV_LIMIT);
			set_cursor_position(offset, 9);
			printf("%s", curr->nameProv);
		}
		set_cursor_position(offset, 11);
		printf("%d", curr->qty);
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 11, 50, fgr, bgr);
			set_cursor_position(offset, 11);
			scan_UnsInt(&curr->qty, 9);
			set_cursor_position(offset, 11);
			printf("%d", curr->qty);
		}
		set_cursor_position(offset, 13);
		printf("%ld.%ld", real_whole(curr->price), real_decimal(curr->price));
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 13, 50, fgr, bgr);
			set_cursor_position(offset, 13);
			scan_Real(&curr->price, 9, 0);
			set_cursor_position(offset, 13);
			printf("%ld.%ld", real_whole(curr->price), real_decimal(curr->price));
		}
		set_cursor_position(offset, 15);
		printf("%ld.%ld", real_whole(curr->weight), real_decimal(curr->weight));
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 15, 50, fgr, bgr);
			set_cursor_position(offset, 15);
			scan_Real(&curr->weight, 9, 0);
			set_cursor_position(offset, 15);
			printf("%ld.%ld", real_whole(curr->weight), real_decimal(curr->weight));
		}
		set_cursor_position(offset, 17);
		printf("%d.%d.%d", date_day(curr->dateImp), date_month(curr->dateImp), date_year(curr->dateImp));
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 17, 50, fgr, bgr);
			set_cursor_position(offset, 17);
			scan_date(&curr->dateImp);
			set_cursor_position(offset, 17);
			printf("%d.%d.%d", date_day(curr->dateImp), date_month(curr->dateImp), date_year(curr->dateImp));
		}
		set_cursor_position(offset, 19);
		printf("%d.%d.%d", date_day(curr->dateExp), date_month(curr->dateExp), date_year(curr->dateExp));
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 19, 50, fgr, bgr);
			set_cursor_position(offset, 19);
			scan_date(&curr->dateExp);
			set_cursor_position(offset, 19);
			printf("%d.%d.%d", date_day(curr->dateExp), date_month(curr->dateExp), date_year(curr->dateExp));
		}
		set_cursor_position(offset, 21);
		printf("%s", curr->note);
		input = _getch();
		if (input != KEY_CR)
		{
			if (input == KEY_ESC) return;
			printSpace(offset, 21, 50, fgr, bgr);
			set_cursor_position(offset, 21);
			scan_Str(curr->note, NOTE_LIMIT);
			set_cursor_position(offset, 21);
			printf("%s", curr->note);
		}
	}
	else
	{
		clrScr();
		printCell(-1, 0, 13, fgr, bgr);
		printColor(-1, 0, "NOT FOUND", fgr, bgr);
		_getch();
	}
}

void menu_StockMod(int chosen, int qty, Stock **head, char fgr, char bgr)
{
	int found = 0;
	Stock *curr;

	for (curr = *head; curr != NULL; curr = curr->next)
	{
		if (curr->ID == (unsigned int)chosen)
		{
			found = 1;
			break;
		}
	}
	if (found)
	{
		if (qty > 0)
		{
			printColor(-1, 21, curr->name, fgr, bgr);
			printColor(-1, 22, "modified by", fgr, bgr);
			printColor(-1, 23, (char*)itoc(qty), fgr, bgr);
			curr->qty += qty;
			_getch();
		}
		else if (qty < 0)
		{
			if (curr->qty < (unsigned int)(qty * -1))
			{
				printColor(-1, 22, "ERROR! Not enough", fgr, bgr);
				printColor(-1, 23, curr->name, fgr, bgr);
				_getch();
			}
			else if (curr->qty == (unsigned int)(qty * -1))
			{
				printColor(-1, 22, curr->name, fgr, bgr);
				printColor(-1, 23, "removed successfully.", fgr, bgr);
				_getch();
				remove_Stock(&curr, head);
			}
			else
			{
				printColor(-1, 21, curr->name, fgr, bgr);
				printColor(-1, 22, "modified by", fgr, bgr);
				printColor(-1, 23, (char*)itoc(qty), fgr, bgr);
				curr->qty += qty;
				_getch();
			}
		}
		else
		{
			printColor(-1, 22, curr->name, fgr, bgr);
			printColor(-1, 23, "not modified.", fgr, bgr);
			_getch();
		}
	}
	else
	{
		clrScr();
		printColor(-1, 0, "NOT FOUND", fgr, bgr);
		_getch();
	}
}

/*colors here*/

void menu_StockFree(Stock **head) /*Deallocating all stocks and exiting*/
{
	Stock *curr;

	for (curr = *head; curr != NULL; curr = curr->next)
	{
		free(curr);
	}
}