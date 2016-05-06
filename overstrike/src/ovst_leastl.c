// NOT DONE YET
#include <stdio.h>
#include "overstrike.h"

#define MAXSTRIKES 6	// the most strikes on each postition

char	strike_map[MAXSTRIKES][MAXLINE+1];
int	strikes[MAXLINE+1];

int
main(int argc, char *argv[])
{
	char	ch;
	int	col, col_max, stk_max;
	int	i;

	col = col_max = 1;
	init_stk(strikes);
	while ((ch = getchar()) != EOF) {
		if (ch == BACKSPACE) {
			col = MAX(col-1, 1);
		}
		else if (ch == NEWLINE) {
			stk_max = max(strikes);
			if (stk_max == 0)
				continue;	// print nothing, go on the loop
			else {
				putchar(ADVANCE);
				for (i = 1; i < col_max; i++) {

				}
			}
			
			

		}
	}

	return 0;
}
