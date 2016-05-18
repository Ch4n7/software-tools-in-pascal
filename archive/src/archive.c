#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAXLINE 256
#define STR_BLANK (" ")
#define STR_NEWLINE ("\n")
#define STR_MINUS ("-")


const char tempfile[] = "/var/tmp/c7_archtmp";
const char archdr[] = "-h-";

void makehdr(const char *fname, char *header);
void clearstr(char *str);
char *itoc(int n, char *numstr);
off_t fsize(const char *fname);
void fcopy(FILE *src, FILE *des);

int
main(int argc, char *argv[])
{
	int	i;
	FILE	*fp, *fpt, *fparch;
	char	header[MAXLINE];

	if ((fpt = fopen(tempfile, "w+")) == NULL) {
		perror("fopen():");
		exit(EXIT_FAILURE);
	}
// remove() immediately after open(), in case of program crushes. File will be unlinked when file closed or program terminates
	if (remove(tempfile) < 0) {	
		perror("remove():");
	}

	for (i = 2; i < argc; i++) {
		if ((fp = fopen(argv[i], "r")) == NULL) {
			perror("fopen():");
			continue;
		}
		makehdr(argv[i], header);
		fputs(header, fpt);
		fcopy(fp, fpt);
	}

	if ((fparch = fopen(argv[1], "w")) == NULL) {
		perror("fopen():");
		exit(EXIT_FAILURE);
	}
	rewind(fpt);	// equals to: fseek(fpt, 0, SEEK_SET);
	fcopy(fpt, fparch);

	return 0;
}

void
makehdr(const char *filename, char *header)
{
	char	tmpstr[MAXLINE];
		// header format: "-h- filename size\n"
	clearstr(header);
	strcat(header, archdr);
	strcat(header, STR_BLANK);
	strcat(header, filename);
	strcat(header, STR_BLANK);
	clearstr(tmpstr);
	strcat(header, itoc(fsize(filename), tmpstr)); 
	strcat(header, STR_NEWLINE);
}

void
clearstr(char *str)
{
	str[0] = '\0';
}

char*
itoc(int n, char *numstr)
{
	char ctos[2];

	if (n < 0) {
		strcat(numstr, STR_MINUS);
		itoc(-n, numstr);
	} else if (n < 10) {
		ctos[0] = '0' + n;
		ctos[1] = '\0';
		strcat(numstr, ctos);
	} else {
		itoc(n/10, numstr);
		ctos[0] = '0' + n % 10;
		ctos[1] = '\0';
		strcat(numstr, ctos); 
	}

	return numstr;
}

off_t
fsize(const char *filename)
{
	struct stat stb;

	if (stat(filename, &stb) == -1) {
		perror("fsize():");
		return -1;	// on error, return -1 byte
	}
	return stb.st_size;
}

void
fcopy(FILE *fpsrc, FILE *fpdes)
{
	char	line[MAXLINE];

	while (fgets(line, MAXLINE, fpsrc) != NULL)
		fputs(line, fpdes);

}
