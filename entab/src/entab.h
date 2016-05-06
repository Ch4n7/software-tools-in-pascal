#ifndef _C7_ENTAB

#include <stdbool.h>

#define MAX_LINE 100
#define TABSTOPS 8

#define TAB ('\t')
#define SPACE (' ')
#define NEWLINE ('\n')
#define BACKSPACE ('\b')

bool tabpos[MAX_LINE+1]; // TAB positions

void set_tabpos();	
bool is_stop(int col);	

#define _C7_ENTAB
#endif
