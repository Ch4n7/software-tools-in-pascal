#include <stdio.h>
#include "error.h"

void fcopy(FILE *in, FILE *out);

int
main(int argc, char *argv[])
{
	int	i;
	FILE	*fp;

	for (i = 1; i < argc; i++) {
		if ((fp = fopen(argv[i], "r")) == NULL)
			err_msg("%s: can't open file '%s'", argv[0], argv[i]);
		else {
			fcopy(fp, stdout);
			fclose(fp);
		}
	}

	return 0;
}

void
fcopy(FILE *fpin, FILE *fpout)
{
	char	ch;

	while ((ch = fgetc(fpin)) != EOF)
		fputc(ch, fpout);
}
