#include <stdio.h>

#define EOS ('\0')	// a convention in C lan of ending of string 
#define SPACE (' ')
#define NEWLINE ('\n')

//Enviroment: GNU/Linux

int
main(int argc, char *argv[])
{
	int	i, j;

	for (i = 1; i < argc; i++) {
		j = 0;
		while (argv[i][j] != EOS)
			putchar(argv[i][j++]);
		putchar(SPACE);
	}
	if (i > 1)
		putchar(NEWLINE);

	return 0;
}
