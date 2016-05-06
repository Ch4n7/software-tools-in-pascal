#include <stdio.h>
#include "entab.h"

int
main(int argc, char *argv[])
{
	char	ch;
	int	col, b_col;	// 'b_col' means a B side additional column that
				// moves away from col as SPACE are encountered.

	set_tabpos();
	
	// We think of the input to prog 'entab' as a repetition of the pattern:
	// zero or more SPACEs, followed by non-SPACE characters( or EOF).
	col = 1;
	while ((ch = getchar()) != EOF) {		
		// SPACE
		if (ch == SPACE) {
			b_col = col;				
			do {
				b_col++;
				if (is_stop(b_col)) {
					putchar(TAB);
					col = b_col;
				}
			} while ((ch = getchar()) == SPACE);
			while (b_col != col) {	// There may be some SPACEs left over.
				putchar(SPACE);
				col++;
			}
		}
		// non-SPACE
		if (ch == NEWLINE) {
			putchar(ch);
			col = 1;
		} else if (ch == TAB) {
			putchar(ch);
			do {	// 'col' increases up to next stop if ch is a TAB.
				col++;
			} while (!is_stop(col));
		} else if (ch == BACKSPACE) {
			putchar(ch);
			if (col > 1) col--;	// 'col' decreases if not the first column.
		} else {
			putchar(ch);
			col++;
		}
	}

	return 0;
}
