#include <stdio.h>
#include "overstrike.h"

int
main(int argc, char *argv[])
{
	char	ch;
	int	col, b_col;	// 'b_col' records changes of the column because of BACKSAPCEs.
	int	i;
	bool	carr_ctrl;

	col = 1;
	carr_ctrl = true;
	do {
		// BACKSPACE
		b_col = col;
		while ((ch = getchar()) == BACKSPACE) {
			b_col = MAX(b_col-1, 1);	// 'col' decreases if not the first column 
		}
		if (b_col < col) {
			putchar(NEWLINE);
			putchar(NO_ADVANCE);
			for (i = 0; i < b_col - 1; i++)	// Output 'b_col-1' of SPACEs.
				putchar(SPACE);
			col = b_col;
		}
		// non-BACKSPACE
		if (ch == EOF) break;	// EOF should be dealt with at first.
		if (carr_ctrl) {	// Output ADVANCE once at first of each line.
			putchar(ADVANCE);
			carr_ctrl = false;
		}
		putchar(ch);	// normal character
		if (ch == NEWLINE) {
			col = 1;
			carr_ctrl = true;	
		} else {
			col++;
		}
	} while (true);	
}
