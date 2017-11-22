#include "Declarations.h"

//struct sColor prgColors;
//struct sRect MainR;
//struct sWindow WinRec[13];

int FieldsRow[10];
int FieldsCol[10];

char MainPath[MAX];
char Caption[MAX];

int CFIndex = 0;
int KBIndex = 0;
int PMIndex = -1;
int PMSIndex = 0;
int UseGUI = 1;
int UseGUIIndex = 0;
int UseAPath = 0;
int KBValue = 1251;

unsigned char chDBLT = 201;
unsigned char chDBLB = 200;
unsigned char chDBRT = 187;
unsigned char chDBRB = 188;
unsigned char chDBHL = 205;
unsigned char chDBVL = 186;
//unsigned char chDBLSB = chDBVL;//199;
//unsigned char chDBRSB = chDBVL;//182;
unsigned char chDBTSB = 209;
unsigned char chDBBSB = 207;
unsigned char chDBRDB = 185;
unsigned char chDBLDB = 204;
unsigned char chDBTDB = 203;
unsigned char chDBBDB = 202;
unsigned char chDBPLUS = 206;

unsigned char chSBLT = 218;
unsigned char chSBLB = 192;
unsigned char chSBRT = 191;
unsigned char chSBRB = 217;
unsigned char chSBHL = 196;
unsigned char chSBVL = 179;
unsigned char chSBPLUS = 197;
unsigned char chSBUT = 194;
unsigned char chSBDT = 193;

unsigned char chMBFCH = 0;
unsigned char chWBFCH = 219;
unsigned char chSBFCH = 178;
unsigned char chPFCH = 219;//177;


CHAR_INFO *mainchInfo;
COORD coord;


