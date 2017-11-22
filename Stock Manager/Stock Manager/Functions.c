#include "Declarations.h"

void clrStr(char *str)
{
	memset(str, 0, sizeof(str));
}

void hide_Input(int total)
{
	int count;

	for (count = 0; count < total; count++)
	{
		printf("\b \b");
	}
}

int memLoc(void **var, int size)
{
	if (NULL == (*var = malloc(size)))
	{
		return 0;
	}
	else return 1;
}

int memLoc_Stock(Stock **fHead)
{
	int place;

	Stock *curr = NULL;

	for (place = 1; place < STOCKMAX; place++)
	{
		if (curr == NULL)
		{
			memLoc(&curr, sizeof(Stock));
			reset_Stock(&curr);
			curr->ID = 0;
			*fHead = curr;
		}
		else
		{
			memLoc(&curr, sizeof(Stock));
			reset_Stock(&curr);
			curr->ID = 0;
			curr->next = (*fHead);
			*fHead = curr;
		}
	}

	return 1;
}

const char *itoc(int integer)
{
	static char tmpChar[11];

	sprintf(tmpChar, "%d", integer);

	return tmpChar;
}

int add_Stock(Stock **head)
{
	Stock *prevhead;

	prevhead = *head;	
	memLoc(head, sizeof(Stock));
	reset_Stock(head);
	if (*head != NULL)
	{
		(*head)->next = prevhead;
	}
	else
	{
		(*head)->next = NULL;
	}

	if (!assign_StockID(head, head))
	{
		free(*head);
		*head = prevhead;
		return 0;
	}
	sortStock_ID(head);
	return 1;
}

int assign_StockID(Stock **stock, Stock **head)
{
	unsigned int total = 0, nextid, lowest = (unsigned int)ID_MAX;
	Stock *curr;

	(*stock)->ID = 0; /*Nullifying ID so the algorithm can give it the same ID if it's correct*/
	if (isFirst(stock))
	{
		(*stock)->ID = ID_MIN;
		(*stock)->next = NULL;
		return 1;
	}
	else 
	{
		/*Getting lowest missed number, if any.*/
		for (curr = *head, total = 0; curr->next != NULL; curr = curr->next, total++) /*Check for and fill missing ID*/
		{
			/*Stop at maximum stocks allowed*/
			if (total >= STOCKMAX)
			{
				return 0;
			}
			/*Skip the given stock as it's nullified*/
			if (curr->next == (*stock))
			{
				nextid = (((curr->next)->next)->ID + 1);
				if ((curr->ID != nextid) && (nextid < lowest))
				{
					lowest = nextid;
				}
				if (curr->next == NULL)
				{
					break;
				}
				curr = curr->next;
				total++; /*We are jumping over the given stock so we are adding it to the total number*/
			}
			/*Search for the lowest ID mismatch*/
			else
			{
				nextid = (curr->next)->ID + 1;
				if ((curr->ID != nextid) && (nextid < lowest))
				{
					lowest = nextid;
				}
			}
		}

		/*First element ID minimum check*/
		if (isFirst(&curr) && (curr->ID != ID_MIN))
		{
			lowest = ID_MIN;
		}
		/*Check to assign lowest as the max total*/
		else if ((total < ID_MAX) && (total < lowest) && (lowest == ID_MAX))
		{
			lowest = total;
		}

		(*stock)->ID = lowest;
		return 1;
	}
	return 0;
}

void sortStock_ID(Stock **head)
{
	Stock *curr, *compare;

	for (curr = *head; compare = curr->next, compare != NULL; curr = curr->next)
	{
		if (curr->ID < compare->ID)
		{
			curr->next = compare->next;
			compare->next = curr;
		}
	}
}
/*
prior = (*stock)->next;
subsequent->next = prior;
(*stock)->next = prior->next;
prior->next = *stock;*/

int isFirst(Stock **stock)
{
	if ((*stock)->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void remove_Stock(Stock **remove, Stock **head)
{
	Stock *curr;

	if (*remove == *head)
	{
		curr = (*head)->next;
		free(*head);
		*head = curr->next;
	}
	else
	{
		for (curr = *head; curr->next != NULL; curr = curr->next)
		{
			if (curr->next == *remove)
			{
				curr->next = (*remove)->next;
				free(*remove);
				break;
			}
		}
	}
}

void reset_Stock(Stock **reset)
{
	strcpy((*reset)->barcode, "");
	strcpy((*reset)->name, "");
	strcpy((*reset)->nameProv, "");
	(*reset)->qty = 0;
	(*reset)->price = 0;
	(*reset)->weight = 0;
	(*reset)->dateImp = 0;
	(*reset)->dateExp = 0;
	strcpy((*reset)->note, "");
}

int get_StockAll(Stock **head)
{
	int num;

	Stock *curr;

	for (curr = *head, num = 0; curr != NULL; curr = curr->next)
	{
		num++;
	}
	return num;
}

Stock* get_Stock(unsigned int StockID, Stock **head)
{
	Stock *curr;

	for (curr = *head; curr != NULL; curr = curr->next)
	{
		if (curr->ID == StockID)
		{
			return curr;
		}
	}
	return NULL;
}

void free_allStocks(Stock **head)
{
	Stock *nextToFree;

	while ((*head) != NULL)
	{		
		nextToFree = (*head)->next;
		free(*head);
		*head = nextToFree;
	}
}

void display_noScrollbar()
{
	/*Remove ScrollBar*/
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

void display_fullscreen()
{
	/*Full screen*/
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
	/*EOF Full Screen*/
}