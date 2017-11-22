#include "Declarations.h"

int scan_date(long int *date)
{
	long int input = 0;

	char total = 0, ch = 0;

	printf("DD.MM.YYYY\b\b\b\b\b\b\b\b\b\b");
	while (input_date(&ch, &input, &total))
	{
		if (total < 8)
		{
			print_date(&ch, &input, &total);
		}
	}

	if (ch != KEY_ESC)
	{
		*date = input;
		return 1;
	}
	else
	{
		return 0;
	}
}

char date_day(long int date)
{
	return ((get_digit(date, 1) * 10) + (get_digit(date, 0) * 1));
}

char date_month(long int date)
{
	return ((get_digit(date, 3) * 10) + (get_digit(date, 2) * 1));
}

int date_year(long int date)
{
	return ((get_digit(date, 7) * 1000) + (get_digit(date, 6) * 100) + (get_digit(date, 5) * 10) + (get_digit(date, 4) * 1));
}

int check_date(long int date)
{
	char day = date_day(date);
	char month = date_month(date);
	int year = date_year(date);

	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	timeinfo->tm_mon++;
	timeinfo->tm_year += 1900;

	// Code block to deny dates after the current date.
	//if (year > timeinfo->tm_year)	return 0;
	//else if (year == timeinfo->tm_year)
	//{
	//	if (month > timeinfo->tm_mon) return 0;
	//	else if (((int)month == timeinfo->tm_mon) && (day > timeinfo->tm_mday)) return 0;
	//}
	if (month > 12)	return 0;
	if ((month % 2) == 0)
	{
		if (month == 2)
		{
			if ((year % 4) == 0)
			{
				if (day > 29) return 0;
			}
			else if (day > 28) return 0;
		}
		else if ((month <= 7 && day > 31) || (month >= 8 && day > 30)) return 0;
	}
	else if ((month <= 7 && day > 30) || (month >= 8 && day > 31)) return 0;

	return 1;
}

int input_date(char *ch, long int *input, char *total)
{
	*ch = (char)_getch();

	switch (*ch)
	{
	case KEY_ARROW:
		_getch();
		break;
	case KEY_ESC:
		erase_date(input, total, *total);
		return 0;
		break;
	case KEY_BACKSPACE:
		erase_date(input, total, 1);
		break;
	case KEY_ENTER:
	case KEY_DOT:
	case KEY_RSLASH:
		switch (*total)
		{
		case 0:
			printf("00.");
			*total = 2;
			break;
		case 1:
			printf("\b0%d.", date_day(*input));
			*total = 2;
			break;
		case 2:
			printf("00.");
			*total = 4;
			break;
		case 3:
			printf("\b0%d.", date_month(*input));
			*total = 4;
			break;
		case 4:
			printf("0000\b");
			*total = 8;
			break;
		case 5:
			printf("\b000%d\b", date_year(*input));
			*total = 8;
			break;
		case 6:
			printf("\b\b00%d\b", date_year(*input));
			*total = 8;
			break;
		case 7:
			printf("\b\b\b0%d\b", date_year(*input));
			*total = 8;
			break;
		case 8:
			if (check_date(*input))
			{
				return 0;
			}
			break;
		}
		break;
	}
	return 1;
}

void print_date(char *ch, long int *input, char *total)
{
	int toInt = 0;

	if (((*ch) >= KEY_0) && ((*ch) <= KEY_9))
	{
		toInt = (*ch) - '0';
		*input = put_digit(*input, *total, toInt);
		switch (*total)
		{
		case 0:
			printf("  \b\b");
			printf("%d", toInt);
			break;
		case 1:
			printf("%d", toInt);
			printf(".");
			*input = switch_digit(*input, 0, 1);
			break;
		case 2:
			printf("%d", toInt);
			printf(" \b");
			break;
		case 3:
			printf("%d", toInt);
			printf(".");
			*input = switch_digit(*input, 2, 3);
			break;
		case 4:
			printf("%d", toInt);
			printf("    \b\b\b\b");
			break;
		case 5:
			printf("%d", toInt);
			*input = switch_digit(*input, 4, 5);
			break;
		case 6:
			printf("%d", toInt);
			*input = switch_digit(*input, 5, 6);
			*input = switch_digit(*input, 4, 5);
			break;
		case 7:
			printf("%d\b", toInt);
			*input = switch_digit(*input, 6, 7);
			*input = switch_digit(*input, 5, 6);
			*input = switch_digit(*input, 4, 5);
			break;
		}
		(*total)++;
	}
}

void erase_date(long int *input, char *total, int times)
{
	int count;

	if (*total > 0)
	{
		for (count = 0; count < times; count++)
		{
			if (total > 0)
			{
				switch (*total)
				{
				case 1:
					printf("\bDD\b\b");
					*input = put_digit(*input, 0, 0);
					break;
				case 2:
					printf("\b\b \b");
					*input = put_digit(*input, 0, 0);
					*input = switch_digit(*input, 0, 1);
					break;
				case 3:
					printf("\bMM\b\b");
					*input = put_digit(*input, 2, 0);
					break;
				case 4:
					printf("\b\b \b");
					*input = put_digit(*input, 2, 0);
					*input = switch_digit(*input, 2, 3);
					break;
				case 5:
					printf("\bYYYY\b\b\b\b");
					*input = put_digit(*input, 4, 0);
					break;
				case 6:
					printf("\b \b");
					*input = put_digit(*input, 4, 0);
					*input = switch_digit(*input, 4, 5);
					break;
				case 7:
					printf("\b \b");
					*input = put_digit(*input, 4, 0);
					*input = switch_digit(*input, 4, 5);
					*input = switch_digit(*input, 5, 6);
					break;
				case 8:
					printf(" \b");
					*input = put_digit(*input, 4, 0);
					*input = switch_digit(*input, 4, 5);
					*input = switch_digit(*input, 5, 6);
					*input = switch_digit(*input, 6, 7);
					break;
				}
				(*total)--;
			}
			else
			{
				break;
			}
		}
	}
}