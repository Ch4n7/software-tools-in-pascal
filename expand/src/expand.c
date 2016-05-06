#include <stdio.h>
#include "expand.h"

int
main(int argc, char *argv[])
{
	char	ch;
	int	n, i;

	while ((ch = getchar()) != EOF) {
		if (ch == TILDE) {
			ch = getchar(); // #1	
			n = ch - 'A' + 1;	
			if ( n >= 0 && n < MAXREP) {	// the count number is in legal range
				ch = getchar();	// #2
				if (ch == EOF) {	// deal with EOF after #2 getchar()
					putchar(TILDE);
					putchar('A' + n - 1);
					break;
				} else {
					for (i = 0; i < n; i++)	
						putchar(ch);	
				}
			} else {
				if (ch == EOF) {	// deal with EOF after #1 getchar()
					putchar(TILDE);
					break;	
				} else {
					putchar(TILDE);
					putchar(ch);
				}
			}
		} else {			
			putchar(ch);
		}
	}

	return 0;
}
// getchar() will remember EOF state, and avoid further calls.
// if an EOF is encountered while reading into count character
// getchar() will keep EOF state until the while-statement.
// And EOF == -1, so under this circumstances, n < 0. 
// The for-loop body statement will not be executed at all.
// Alright here.
