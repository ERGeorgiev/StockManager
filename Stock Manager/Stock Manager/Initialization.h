#ifndef __INIT_H__
#define __INIT_H__

// VARIABLE LENGTH WITH NULL TERMINATOR:
#define BARCODE_LEN 31
#define NAME_LEN 51
#define NAMEPROV_LEN 51
#define NOTE_LEN 51
// VARIABLE LENGTH WITHOUT NULL TERMINATOR:
#define BARCODE_LIMIT 30
#define NAME_LIMIT 50
#define NAMEPROV_LIMIT 50
#define NOTE_LIMIT 50


struct StockNode {
	long int ID;
	char barcode[BARCODE_LEN];
	char name[NAME_LEN];
	char nameProv[NAMEPROV_LEN];
	unsigned int qty;
	long long int price; //9 for whole, 9 for decimal
	long long int weight; //9 for whole, 9 for decimal
	long int dateImp;
	long int dateExp;
	char note[NOTE_LEN];
	struct StockNode *next;
};
typedef struct StockNode Stock;

#endif