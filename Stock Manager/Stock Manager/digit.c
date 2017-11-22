#include "Declarations.h"

//Digit is given in a right-to-left order.
char get_digit(long long int number, char place)
{
	long long int target = number;
	char digit = 0;

	target /= (long long int)pow(10, place);
	digit = target % 10;

	return digit;
}

//Digit is given in a right-to-left order.
long long int put_digit(long long int number, char place, char digit)
{
	long long int result = number;

	result -= get_digit(number, place)*(long long int)pow(10, (place));
	result += digit*(long long int)pow(10, (place));

	return result;
}

long long int switch_digit(long long int number, char placeA, char placeB)
{
	long long int result = number;
	char remainder = 0;

	remainder = get_digit(number, placeA);
	result = put_digit(result, placeA, get_digit(result, placeB));
	result = put_digit(result, placeB, remainder);
	return result;
}

char count_digit(long long int number)
{
	long long int target = llabs(number);
	char digits = 0;

	while (target)
	{
		target /= 10;
		digits++;
	}

	return digits;
}