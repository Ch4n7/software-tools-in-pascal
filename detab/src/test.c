#include <stdio.h>
#include <unistd.h>
#include "detab.h"	// stdbool.h is in detab.h

int
main(int argc, char *argv[])
{
	char	ch;
	int	col;
	extern int tabstops[];
	int	i;

	set_tabpos();
	
	for (i = 1; i < MAX_LINE + 10; i++) {
		printf("%d:%s\n", i, is_stop(i) ? "STOP" : "NO");
	}
}

