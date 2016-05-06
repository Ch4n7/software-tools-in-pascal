#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	int	n = 0;

	while (getc(stdin) != EOF)
		n++;
	printf("%d\n", n);

	return 0;
}
