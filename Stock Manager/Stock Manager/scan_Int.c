#include "Declarations.h"

int scan_Int(int *output, int limit, int allowMinus)
{
	int total, input = 0, minus = allowMinus;

	char ch;

	total = 0;
	ch = 0;

	while (input_Int(&ch, &input, &total, limit, &minus))
	{
		print_Int(&ch, &input, &total, limit);
	}
	if (ch != KEY_ESC)
	{
		trans_Int(output, input, minus);
		return 1;
	}
	else return 0;
}

int input_Int(char *ch, int *input, int *total, int limit, int *minus)
{
	*ch = (char)_getch();

	switch (*ch)
	{
	case KEY_ENTER:
		return 0;
		break;
	case KEY_ESC:
		erase_Int(input, total, limit+1, minus);
		return 0;
		break;
	case KEY_BACKSPACE:
		erase_Int(input, total, 1, minus);
		break;
	case KEY_MINUS:
		if (*minus == 1)
		{
			*minus = 2;
			hide_Input(*total);
			printf("-");
			if (*input != 0)
			{
				printf("%d", *input);
			}
		}
		else if (*minus == 2)
		{
			*minus = 1;
			hide_Input(*total);
			printf("\b \b");
			if (*input != 0)
			{
				printf("%d", *input);
			}
		}
		break;
	}
	return 1;
}

void print_Int(char *ch, int *input, int *total, int limit)
{
	int toInt;

	toInt = *ch - '0';
	if (*total < limit && *ch >= KEY_0 && *ch <= KEY_9)
	{
		*input *= 10;
		*input += toInt;
		printf("%c", *ch);
		*total += 1;
	}
}

void erase_Int(int *input, int *total, int times, int *minus)
{
	int count;

	for (count = 0; count < times; (count)++)
	{
		if (*total == 0 && *minus == 2)
		{
			printf("\b \b");
			*minus = 1;
		}
		else if (*total > 0)
		{
			printf("\b \b");
			*total -= 1;
			*input /= 10;
		}
	}
}

void trans_Int(int *output, int input, int minus)
{
	*output = input;
	if (minus == 2)
	{
		*output *= -1;
	}
}