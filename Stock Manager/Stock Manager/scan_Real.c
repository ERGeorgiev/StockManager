#include "Declarations.h"

long long int scan_Real(long long int *output, char limit, char minus)
{
	long long int input = 1000000000000000000;

	char total[2] = { 0, 0 }, ch = 0, decimal = 0, negative = 0;

	while (input_Real(&ch, &input, total, &decimal, limit, minus, &negative))
	{
		print_Real(&ch, &input, total, &decimal, limit);
	}

	if (ch != KEY_ESC)
	{
		*output = input;
		return 1;
	}
	else
	{
		return 0;
	}
}

long int real_whole(long long int number)
{
	long long int whole = number;

	if (whole <= 1000000000000000000)
	{
		return 0;
	}
	else
	{
		whole -= 1000000000000000000;
		whole /= (long int)pow(10, 9);
		return (long int)whole;
	}
}

long int real_decimal(long long int number) //Returns decimal without the zeros on its left, so be careful.
{
	long long int decimal = number;

	if (number <= 1000000000000000000)
	{
		return 0;
	}
	else
	{
		decimal -= 1000000000000000000;
		decimal %= (long int)pow(10, 9);
		return (long int)decimal;
	}
}

char input_Real(char *ch, long long int *output, char *total, char *decimal, char limit, char minus, char *negative)
{
	*ch = (char)_getch();

	switch (*ch)
	{
	case KEY_ARROW:
		_getch();
		break;
	case KEY_ENTER:
		if (*negative)
		{
			*output *= -1;
		}
		return 0;
		break;
	case KEY_ESC:
		*output = 0;
		return 0;
		break;
	case KEY_BACKSPACE:
		erase_Real(output, total, decimal, negative, 1);
		break;
	case KEY_MINUS:
		if (minus)
		{
			hide_Input(total[0]+total[1]);
			if (*negative)
			{
				*negative = 0;
				if (*decimal != 0)
				{
					printf("\b \b");
					printf("\b \b");
					printf("%d.%d", real_whole(*output), real_decimal(*output));
				}
				else
				{
					printf("\b \b");
					printf("%d", real_whole(*output));
				}
			}
			else
			{
				*negative = 1;
				if (*decimal != 0)
				{
					printf("\b \b");
					printf("-");
					printf("%d.%d", real_whole(*output), real_decimal(*output));
				}
				else
				{
					printf("-");
					printf("%d", real_whole(*output));
				}
			}
		}
		break;

	case KEY_DOT:
		if ((*decimal == 0) && ((limit*2) > (total[0] + total[1])))
		{
			if ((*output == 0) && (total[0] == 0))
			{
				printf("0");
			}
			*decimal = 1;
			printf("%c", *ch);
		}
		break;
	}
	return 1;
}

void print_Real(char *ch, long long int *output, char *total, char *decimal, char limit)
{
	int toInt, i;

	if (*decimal == 0) //If no decimal
	{
		if ((limit > total[0]) && ((*ch) >= KEY_0 && (*ch) <= KEY_9))
		{
			if ((*ch != KEY_0) || (total[0] != 0))
			{
				toInt = (*ch) - '0';
				for (i = ((limit - 1) + total[0]); i >= limit; i--)
				{
					*output = put_digit(*output, i + 1, get_digit(*output, i));
				}
				*output = put_digit(*output, limit, toInt);
				printf("%d", toInt);
				total[0]++;
			}
		}
	}
	else
	{
		if ((limit > total[1]) && ((*ch) >= KEY_0 && (*ch) <= KEY_9))
		{
			toInt = (*ch) - '0';
			for (i = (total[1] - 1); i >= 0; i--)
			{
				*output = put_digit(*output, i + 1, get_digit(*output, i));
			}
			*output = put_digit(*output, 0, toInt);
			printf("%d", toInt);
			total[1]++;
		}
	}
}

void erase_Real(long long int *output, char *total, char *decimal, char *negative, int times)
{
	int count, i;

	for (count = 0; count < times; count++)
	{
		if (*decimal)
		{
			if (total[1] > 0)
			{
				for (i = 1; i < (total[0]); i++)
				{
					*output = put_digit(*output, i, get_digit(*output, i + 1));
				}
				printf("\b \b");
				*output = put_digit(*output, 9 - total[1], 0);
				total[1]--;
			}
			else
			{
				printf("\b \b");
				*decimal = 0;
				if (*output == 0)
				{
					printf("\b \b");
				}
			}
		}
		else if (total[0] > 0)
		{
			for (i = 9; i < ((9-1) + total[0]); i++)
			{
				*output = put_digit(*output, i, get_digit(*output, i + 1));
			}
			printf("\b \b");
			*output = put_digit(*output, ((9 - 1) + total[0]), 0);
			total[0]--;
		}
		else if (*negative)
		{
			printf("\b \b");
			*negative = 0;
		}
	}
}