#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define SPACE (' ')
#define NEWLINE ('\n')
#define TAB ('\t')

int
main(int argc, char *argv[])
{
	int	n;
	char	ch;
	bool	in_word;	// Transition from not being in a word to being in a 
				// word signals another word to count. The variable 
				// 'in_word' records which state the program is in at
				// any given time.

	n = 0;
	in_word = false;	// 'in_word' is false at first.
	while ((ch = getc(stdin)) != EOF) {
		if (ch == SPACE || ch == NEWLINE || ch == TAB)	// deal with whitespaces
			in_word = false;
		else {	// deal with non-whitespaces
			if (in_word == false)	// transition occurs
				n++;
			in_word = true;
		}
	}

	printf("%d\n", n);

	return 0;
}
