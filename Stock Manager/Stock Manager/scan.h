#ifndef __SUI_h__
#define __SUI_h__
//scan_Arrow
int scan_Arrow(int axis, int limit, int X, int Y, char fgr, char bgr);

//scan_Int
int scan_Int(int *output, int limit, int allowMinus);
	int input_Int(char *ch, int *input, int *total, int limit, int *minus);
	void print_Int(char *ch, int *input, int *total, int limit);
	void erase_Int(int *input, int *total, int times, int *minus);
	void trans_Int(int *output, int input, int minus);

//sscan_UnsInt
int scan_UnsInt(unsigned int *output, int limit);
	int input_UnsInt(char *ch, unsigned int *input, int *total, int limit);
	void print_UnsInt(char *ch, unsigned int *input, int *total, int limit);
	void erase_UnsInt(unsigned int *input, int *total, int times);
	void trans_UnsInt(char ch, unsigned int *output, unsigned int input);

//scan_Real.c
long long int scan_Real(long long int *output, char limit, char minus);
long int real_whole(long long int number);
long int real_decimal(long long int number);
char input_Real(char *ch, long long int *output, char *total, char *decimal, char limit, char minus, char *negative);
void print_Real(char *ch, long long int *output, char *total, char *decimal, char limit);
void erase_Real(long long int *output, char *total, char *decimal, char *negative, int times);

//scan_Str
int scan_Str(char *input, int limit);
  int input_Str(char *input, int *total);
  void print_Str(char *input, int *total, int limit);
  void erase_Str(char *input, int *total, int times);

//digits
char get_digit(long long int number, char digit);
long long int put_digit(long long int number, char place, char digit);
long long int switch_digit(long long int number, char placeA, char placeB);
char count_digit(long long int number);

//scan_date
int scan_date(long int *date);
	char date_day(long int date);
	char date_month(long int date);
	int date_year(long int date);
	int check_date(long int date);
	int input_date(char *ch, long int *input, char *total);
	void print_date(char *ch, long int *input, char *total);
	void erase_date(long int *input, char *total, int times);

#endif
