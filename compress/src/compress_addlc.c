#include <stdio.h>

#define NEWLINE ('\n')
#define TILDE ('~')
#define MAXREP1 26
#define MAXREP2 26
#define RUN_THRESH 4
#define MIN(x,y) ((x) < (y) ? (x) : (y))

void putrepr(int n, char ch);	// output compression representation
void putrrr(int n, char ch);	// output 'n' times of 'ch'

int
main(int argc, char *argv[])
{
	char	ch, lastc;
	int	n;
	
	n = 1;
	lastc = getchar();
	while (lastc != EOF) {
		// EOF
		if ((ch = getchar()) == EOF) {
			if (n >= RUN_THRESH || lastc == TILDE) {
				putrepr(n, lastc);
			} else {
				putrrr(n, lastc);
			}

			break;
		} 
		
		if (ch == lastc) {
			n++;
		} else { // must have sth to the output
			if (n >= RUN_THRESH || lastc == TILDE) {
				putrepr(n, lastc);
			} else {
				putrrr(n, lastc);
			}

			n = 1;
		}
		lastc = ch;
	}

	return 0;
}

void
putrepr(int n, char ch)
{
	int	m;
	char	basec;

	do {
		putchar(TILDE);
		m = MIN(n, MAXREP1 + MAXREP2) - 1;
		if ( m < MAXREP1) {
			basec = 'a';
		} else {
			basec = 'A';
			m -= MAXREP1;
		}
		putchar((char)(basec + m));
		putchar(ch);
		n = n - (MAXREP1 + MAXREP2);
	} while (n > RUN_THRESH);	// e.g. 00..0 ('0'*27) -> ~Z0 0, directly output if less than RUN_THRESH
					//      00..0 ('0'*28) -> ~Z0 00
	putrrr(n, ch);
}

void
putrrr(int n, char ch)
{
	while ((n--) > 0)
		putchar(ch);
}
