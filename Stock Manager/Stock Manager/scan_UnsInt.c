#include "Declarations.h"

int scan_UnsInt(unsigned int *output, int limit)
{
	int total = 0;
	unsigned int input = 0;

	char ch = 0;

	while (input_UnsInt(&ch, &input, &total, limit))
	{
		print_UnsInt(&ch, &input, &total, limit);
	}
	if (ch != KEY_ESC)
	{
		trans_UnsInt(ch, output, input);
		return 1;
	}
	else return 0;
}

int input_UnsInt(char *ch, unsigned int *input, int *total, int limit)
{
	*ch = (char)_getch();

	switch (*ch)
	{
	case KEY_ENTER:
		return 0;
		break;
	case KEY_ESC:
		erase_UnsInt(input, total, limit + 1);
		return 0;
		break;
	case KEY_BACKSPACE:
		erase_UnsInt(input, total, 1);
		break;
	}
	return 1;
}

void print_UnsInt(char *ch, unsigned int *input, int *total, int limit)
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

void erase_UnsInt(unsigned int *input, int *total, int times)
{
	int count;

	for (count = 0; count < times; (count)++)
	{
		if (*total > 0)
		{
			printf("\b \b");
			*total -= 1;
			*input /= 10;
		}
	}
}

void trans_UnsInt(char ch, unsigned int *output, unsigned int input)
{
	if (ch != KEY_ESC)
	{
		*output = input;
	}
}