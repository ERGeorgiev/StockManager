#ifndef __MENU_H__
#define __MENU_H__

void menuLaunch(int menu, Stock **head);

int menu_StockProv(Stock **head);
void sort_StockProv(Stock ***toSort, unsigned int StocksTotal);
int cmp_StockProv(const void *Ap, const void *Bp);

void menu_StockCrit(Stock **head);
void get_StockCrit(char *name, unsigned int *dateFrom, unsigned int *dateTo, char fgr, char bgr);
void sort_StockCrit(int *StocksCrit, unsigned int *list, char *name, unsigned int *dateFrom, unsigned int *dateTo, Stock **head);
void pages_StockCrit(int StocksCrit, unsigned int *list, Stock **head, char fgr, char bgr);

void menu_StockAdd(Stock **head);
int get_StockInput(Stock **head, char fgr, char bgr);

void menu_StockBarcode(Stock **head);
void menu_StockFind(Stock **head);
void menu_StockMod(int chosen, int qty, Stock **head, char fgr, char bgr);

void menu_StockQty(Stock **head);

void menu_StockAll(Stock **head);
void pages_StockAll(Stock **head, int elements, int *page, int pages, int *cell, char fgr, char bgr);

void menu_StockInfo(unsigned int choice, Stock **head, char fgr, char bgr);

/*Colors menu slot*/

void menu_StockFree(Stock **head);

#endif