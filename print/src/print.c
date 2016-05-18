#include <stdio.h>
#include "error.h"

#define MAXLINE 256
#define MARGIN1 2
#define MARGIN2 2
#define BOTTOM 64
#define PAGELEN 66
#define NEWLINE ('\n')

void fprint(char *fname, FILE *in, FILE *out);
void skip(int n, FILE *out);
void head(char *fname, int pageno, FILE *out);

int
main(int argc, char *argv[])
{
	int	i;
	FILE	*fp;
	char	emptystr[] = "";

	if (argc == 1) {	// reverts input to output if no filename arguments specified
		fprint(emptystr, stdin, stdout);	
	} else {
		for (i = 1; i < argc; i++) {
			if ((fp = fopen(argv[i], "r")) == NULL)
				err_msg("%s: can't open file '%s'", argv[0], argv[i]);
			else {
				fprint(argv[i], fp, stdout);
				fclose(fp);
			}
		}
	}

	return 0;
}

void
fprint(char *filename, FILE *fpin, FILE *fpout)
{
	char	line[MAXLINE];
	int	lineno, pageno;

	skip(MARGIN1, fpout);
	head(filename, pageno, fpout);
	skip(MARGIN2, fpout);
	lineno = 1 + MARGIN1 + 1 + MARGIN2; // line number starts from 1, anthor 1 is for header information
	pageno = 1;
	while (fgets(line, MAXLINE, fpin) != NULL) {
		if (lineno == 1) {
			pageno++;
			skip(MARGIN1, fpout);
			head(filename, pageno, fpout);
			skip(MARGIN2, fpout);
			lineno = 1 + MARGIN1 + 1 + MARGIN2;
		}
		fputs(line, fpout);
		lineno++;
		if (lineno >= BOTTOM) {
			skip(PAGELEN - lineno + 1, fpout);
			lineno = 1;
		}
	}
	if (lineno > 1)	// complement the rest lines
		skip(PAGELEN - lineno + 1, fpout);
}

void
skip(int n, FILE *fpout)
{
	int	i;
	
	for (i = 0; i < n; i++)
		fputc(NEWLINE, fpout);
}

void
head(char *filename, int pageno, FILE *fpout)
{
	fprintf(fpout, "%s  Page %d\n", filename, pageno);
}
