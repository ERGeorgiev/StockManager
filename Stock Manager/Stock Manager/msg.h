#ifndef __MSG_H__
#define __MSG_H__

void displayMsg_critStock(char fgr, char bgr);
void displayMsg_findStock(char fgr, char bgr);
void displayMsg_qtyStock(char fgr, char bgr);
void displayMsg_editStock(char fgr, char bgr);
void displayMsg_StockCritBgr(int *cell, char fgr, char bgr);
void displayMsg_StockCritCells(int *cell, int page, unsigned int *list, int StocksCrit, Stock **head, char fgr, char bgr);
void displayMsg_StockAllBgr(int *cell, char fgr, char bgr);
void displayMsg_StockPage(int page, int pages, char fgr, char bgr);
void displayMsg_StockAllCells(int *cell, int page, Stock **head, char fgr, char bgr);
void displayMsg_add_Stock(char fgr, char bgr);
void displayMsg_startInfo(char fgr, char bgr);
void displayMsg_menuChoice(char fgr, char bgr);

void printColor(int col, int row, char msg[MAX], char fgr, char bgr);
void printColor_Real(int col, int row, long long int number, char fgr, char bgr);
void printLine(int col, int row, int length, char fgr, char bgr);
void printBorder(int col, int row, int length, char fgr, char bgr);
void printCell(int col, int row, int length, char fgr, char bgr);
void printSpace(int col, int row, int length, char fgr, char bgr);
void charToColor(char fgr, char bgr, WORD *fgrColor, WORD *bgrColor);

#endif
