#include "ioch.h"
#include <unistd.h>

int
main(int argc, char *argv[])
{
	char ch;
	
	while (getc(&ch) != END_OF_FILE)
		putc(ch);

	return 0;
}

