#include <stdio.h>
#include <unistd.h>
#include "detab.h"	// stdbool.h is in detab.h

int	g_argc;
char	**g_argv;

int
main(int argc, char *argv[])
{
	char	ch;
	int	col;

	g_argc = argc;	// share the command line among functions
	g_argv = argv;

	set_tabpos();

	col = 1;
	while ((ch = getchar()) != EOF) {
		if ( ch == TAB) {
			do {
				putchar(SPACE);
				col++;
			} while (!is_stop(col));
		} else if ( ch == NEWLINE) {
			putchar(ch);
			col = 1;
		} else if ( ch == BACKSPACE) {
			putchar(ch);
			if (col > 1) col--;	// 'col' decreases if not the first column.
		}
		else {
			putchar(ch);
			col++;
		}
	}

	return 0;
}

