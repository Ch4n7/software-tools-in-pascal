#include <stdio.h>
#include <unistd.h>

#define NEWLINE	('\n')

int
main(int argc, char *argv[])
{
	int	n = 0;
	char	ch;

	while ((ch = getc(stdin)) != EOF)
		if (ch == NEWLINE)
			n++;

	printf("%d\n", n);

	return 0;
}
