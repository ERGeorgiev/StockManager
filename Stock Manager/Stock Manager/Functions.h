#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

int check_Date(int day, int month, int year);
void clrStr(char *str);
int memLoc(void **var, int size);
void hide_Input(int total);
int memLoc_Stock(Stock **head);
const char *itoc(int integer);
int add_Stock(Stock **head);
int assign_StockID(Stock **stock, Stock **head);
void sortStock_ID(Stock **head);
int isFirst(Stock **stock);
void remove_Stock(Stock **remove, Stock **head);
void reset_Stock(Stock **reset);
int get_StockAll(Stock **head);
Stock* get_Stock(unsigned int StockID, Stock **head);

#endif