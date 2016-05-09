#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "translit.h"

int
main(int argc, char *argv[])
{
	char	ch;
	char	fromset[SETSIZE], toset[SETSIZE];
	char	emptystr[] = "";
	int	i, tolen, lastto;
	bool	squash, allbut, junkbool;

	if (argc == 3) {
		makeset(argv[1], fromset, SETSIZE, &allbut);
		makeset(argv[2], toset, SETSIZE, &junkbool);
	} else if (argc == 2) {	// <toset> missing means to delete all occurences of characters in fromset
		makeset(argv[1], fromset, SETSIZE, &allbut);
		makeset(emptystr, toset, SETSIZE, &junkbool);
	} else {
		fprintf(stderr, "usage: %s <fromset> <toset>\n", argv[0]);
		exit(1);
	}

	tolen = strlen(toset); // toset length 
	lastto = ((tolen > 0) ? (tolen - 1) : 0);	// the index of last character in toset; 0 if toset is empty 
	squash = strlen(fromset) > tolen;
	do {
		ch = getchar();	// #1
		i = xindex(ch, fromset, allbut, lastto);
	// squash
		if (squash && i >= lastto) {	
				// Deletion will also work! 'toset[lastto]' is EOS when toset is empty
			putchar(toset[lastto]);	
			do {
				ch = getchar(); // #2
				i = xindex(ch, fromset, allbut, lastto);
			} while (i >= lastto);	// ignore the squashed character
		}
	// EOF, should occur after #1 and #2 getchar()
		if (ch == EOF) break;
	// no squash, normal translit
		if (i >= 0) {	// matched
			putchar(toset[i]);
		} else {	// not matched
			putchar(ch);
		}
	} while (true);	

	return 0;
}
