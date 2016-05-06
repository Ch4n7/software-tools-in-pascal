#include <stdio.h>
#include "overstrike.h"

int
main(int argc, char *argv[])
{
	char	ch;
	char	buf_line[MAXLINE];	
	int	out_col, b_col, buf_col;	// 'b_col' records changes of the column because of BACKSAPCEs.
	int	i;
	bool	carr_ctrl;

	buf_line[0] = NO_ADVANCE;
	out_col = buf_col = b_col = 1; 
	carr_ctrl = true;
	do {
		// BACKSPACE
		while ((ch = getchar()) == BACKSPACE) {
			b_col = MAX(b_col-1, 1);	// 'col' decreases if not the first column 
		}
		
		// non-BACKSPACE
		if (ch == EOF) break;	// EOF should be dealt with at first.
		if (b_col < out_col) {
			if (b_col < buf_col) {
				putchar(NEWLINE);
				for (i = 0; i < buf_col; i++)
					putchar(buf_line[i]);
				out_col = buf_col;
				buf_col = 1;
			}
			while (buf_col < b_col) {
				buf_line[buf_col++] = SPACE;
			}
			buf_line[buf_col++] = ch;
			b_col = buf_col;
		} else {
			if (carr_ctrl) {	// Output ADVANCE once at first of each line.
				putchar(ADVANCE);
				carr_ctrl = false;
			}
			if (ch == NEWLINE) {	// a new line, output the buf_line, and reset
				if (buf_col != 1) {
					putchar(NEWLINE);
					for (i = 0; i< buf_col; i++)
						putchar(buf_line[i]);
				}
				putchar(NEWLINE);
				out_col = buf_col = b_col = 1;
				carr_ctrl = true;	
			} else {
				putchar(ch);	// normal character
				out_col++;
				b_col = out_col;
			}
		}
	} while (true);	

	return 0;
}
