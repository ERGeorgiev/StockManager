#ifndef __GLOBALS_H_
#define __GLOBALS_H_

extern struct sColor prgColors;
extern struct sRect MainR;
//extern struct sWindow WinRec[13];// error: array type has incomplete element type (no notes)
extern int FieldsRow[];
extern int FieldsCol[];

extern char MainPath[MAX];
extern char Caption[MAX];

extern int CFIndex;
extern int KBIndex;
extern int PMIndex;
extern int PMSIndex;
extern int UseGUI;
extern int UseGUIIndex0;
extern int UseAPath;
extern int KBValue;

extern unsigned char chDBLT;
extern unsigned char chDBLB;
extern unsigned char chDBRT;
extern unsigned char chDBRB;
extern unsigned char chDBHL;
extern unsigned char chDBVL;
extern unsigned char chDBLSB;
extern unsigned char chDBRSB;
extern unsigned char chDBTSB;
extern unsigned char chDBBSB;
extern unsigned char chDBRDB;
extern unsigned char chDBLDB;
extern unsigned char chDBTDB;
extern unsigned char chDBBDB;
extern unsigned char chDBPLUS;

extern unsigned char chSBLT;
extern unsigned char chSBLB;
extern unsigned char chSBRT;
extern unsigned char chSBRB;
extern unsigned char chSBHL;
extern unsigned char chSBVL;
extern unsigned char chSBPLUS;
extern unsigned char chSBUT;
extern unsigned char chSBDT;

extern unsigned char chMBFCH;
extern unsigned char chWBFCH;
extern unsigned char chSBFCH;
extern unsigned char chPFCH;

extern CHAR_INFO *mainchInfo;
extern COORD coord;

#endif
