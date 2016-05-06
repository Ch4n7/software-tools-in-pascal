#include <stdio.h>

void
print_arg()
{
	printf("%d\n", argc);
}

int
main(int argc, char *argv[])
{
	print_arg();
}
