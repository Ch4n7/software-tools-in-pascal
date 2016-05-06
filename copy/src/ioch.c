#include <unistd.h>
#include "ioch.h"

char 
getc(char *pch)
{
	int	n;

	if ((n = read(STDIN_FILENO, pch, 1)) == 0)	//when EOF, read() return 0.
		return END_OF_FILE; 
	else if (n == 1) {
		return (*pch);
	}
}

void
putc(char ch)
{
	
	write(STDOUT_FILENO, &ch, 1);
}
