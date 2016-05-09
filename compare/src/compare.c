// #1 fopen, fgets
// #2 statement1 && statement2, if s1 is false, s2 will be ignored; likewise, in the '||' expression

#include <stdio.h>
#include <string.h>
#include "error.h"

#define MAXLINE 256

void diffmsg(char *line1, char *line2, int lineno);

int
main(int argc, char *argv[])
{
	FILE	*fp1, *fp2;
	int	lineno;
	char	line1[MAXLINE], line2[MAXLINE];
	char	*ret1, *ret2;

	if ((fp1 = fopen(argv[1], "r")) == NULL)
		err_quit("can't open %s", argv[1]);
	if ((fp2 = fopen(argv[2], "r")) == NULL)
		err_quit("can't open %s", argv[2]);
	
	lineno = 0;
	do {
		ret1 = fgets(line1, MAXLINE, fp1);
		ret2 = fgets(line2, MAXLINE, fp2);

		if (ret1 == NULL || ret2 == NULL)
			break;

		lineno++;
		if (strcmp(line1, line2) != 0) 
			diffmsg(line1, line2, lineno);
	} while (7);

	if (ret1 == NULL && ret2 != NULL)
		printf("%s: end of file on %s\n", argv[0], argv[1]);
	else if (ret1 != NULL && ret2 == NULL)
		printf("%s: end of file on %s\n", argv[0], argv[2]);
	
	return 0;
}

void
diffmsg(char *line1, char *line2, int lineno)
{
	printf("%d:\n", lineno);
	puts(line1);
	puts(line2);
}
