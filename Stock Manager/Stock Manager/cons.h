#ifndef __CONS_H__
#define __CONS_H__

int GetKey(void);
void InitProgram(void);
void init_console(unsigned int Value);
void set_cursor_visible(int Visible);
void set_cursor_position(int x, int y);
void set_cursor_size(int large);
CHAR_INFO *get_screen(COORD *cd);
void put_screen(COORD *cd, CHAR_INFO *buffer);
void set_window_title(char *str);
void clrScr(void);

#endif
