#include <stdio.h>
#include <stdbool.h>
#include "translit.h"

// c7_index - find position of character 'ch' in string 'charset'
int
c7_index(char ch, char *charset)
{
	int	i, index;

	i = 0;
	while (charset[i] != EOS && charset[i] != ch)	// stop at either EOS or ch is matched
		i++;
	if (charset[i] == EOS)
		index = NO_MATCHED;
	else	// matched
		index = i;
	
	return index;
}

// xindex - conditionally invert value from index()
int
xindex(char ch, char *charset, bool allbut, int lastto)
{
	int	xindex;

	if (ch == EOF)
		xindex = NO_MATCHED;
	else if (!allbut)	// normal match
		xindex = c7_index(ch, charset);	
	else if (c7_index(ch, charset) != NO_MATCHED)	// 'all-but' matched, return result oppsite the 'index()'
		xindex = NO_MATCHED;
	else
		xindex = lastto;	// return 'lastto' to fit the function of deletion

	return xindex;
}

// expandash - expand the dash expression into 'charset' array from the start index 'starti', 
// return the current index which points to next place ready to be written in.
int
expandash(char left, char right, char *charset, int starti)
{
	char	ch;
	int	i;

	i = starti;
	for (ch = left; ch <= right; ch++, i++)
		charset[i] = ch;
	
	return i;
}

// makeset - make set from argv
int
makeset(char *argstr, char *outset, int setsize, bool *allbut)
{
	int	i, j;
	char	ch;

	i = j = 0;
	if (argstr[i] == ALLBUT) {
		*allbut = true;
		i++;
	}
	while (argstr[i] != EOS && i < (setsize - 1) && j < (setsize - 1)) {
		if (argstr[i] == ESCAPE) {
			switch (argstr[i+1]) {
				case 'b':	// '@b' means BLANK
					outset[j] = ' ';
					i += 2;
					j++;
					break;
				case 'n':	// '@n' means NEWLINE 
					outset[j] = '\n';
					i += 2;
					j++;
					break;
				case 't':	// '@t' means TAB
					outset[j] = '\t';
					i += 2;
					j++;
					break;
				case ALLBUT:	// '@^' means '^' literately
					outset[j] = '^';
					i += 2;
					j++;
					break;
				default:	// otherwise, '@' means just '@'
					outset[j] = ESCAPE;
					i++;
					j++;
			}
		} else if (argstr[i+1] == '-' && islower(argstr[i]) && islower(argstr[i+2])) {
			j = expandash(argstr[i], argstr[i+2], outset, j);		
			i += 3;
		} else if (argstr[i+1] == '-' && isupper(argstr[i]) && isupper(argstr[i+2])) {
			j = expandash(argstr[i], argstr[i+2], outset, j);		
			i += 3;
		} else if (argstr[i+1] == '-' && isdigit(argstr[i]) && isdigit(argstr[i+2])) {
			j = expandash(argstr[i], argstr[i+2], outset, j);		
			i += 3;
		} else {	
			outset[j] = argstr[i];
			i++;
			j++;
		}
	}
	outset[j] = EOS;

	return 0;
}
