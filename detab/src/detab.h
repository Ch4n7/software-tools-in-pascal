#ifndef _C7_DETAB

#include <stdbool.h>

#define MAX_LINE 100
#define TABSTOPS 8

#define TAB ('\t')
#define SPACE (' ')
#define NEWLINE ('\n')
#define BACKSPACE ('\b')
#define ARG_SH_SIGN ('+')	// shorthand cmd-line arguments

void set_tabpos();	
bool is_stop(int col);	

#define _C7_DETAB
#endif
