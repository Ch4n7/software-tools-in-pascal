#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define SPACE (' ')
#define NEWLINE ('\n')
#define TAB ('\t')

int
main(int argc, char *argv[])
{
	int	nl, nw, nc;	// the number of lines, words, and characters
	char	ch;
	bool	in_word;	// Transition from not being in a word to being in a 
				// word signals another word to count. The variable 
				// 'in_word' records which state the program is in at
				// any given time.

	nl = nw = nc = 0;
	in_word = false;	// 'in_word' is false at first.
	while ((ch = getc(stdin)) != EOF) {
		// count characters
		nc++;
		// count lines
		if ( ch == NEWLINE )
			nl++;
		// count words
		if (ch == SPACE || ch == NEWLINE || ch == TAB)	// deal with whitespaces
			in_word = false;
		else {	// deal with non-whitespaces
			if (in_word == false)	// transition occurs
				nw++;
			in_word = true;
		}
	}

	printf("%5d%5d%5d\n", nl, nw, nc);

	return 0;
}
