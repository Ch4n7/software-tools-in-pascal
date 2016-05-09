#ifndef _C7_TRANSLIT

#define	SETSIZE	256
#define NO_MATCHED -1	
#define ALLBUT ('^')
#define	EOS ('\0')	// end of string
#define ESCAPE ('@')

int c7_index(char ch, char *charset);
int xindex(char ch, char *charset, bool allbut, int lastto);
int makeset(char *argstr, char *outset, int setsize, bool *allbut);
int expandash(char left, char right, char *charset, int starti);

#define _C7_TRANSLIT
#endif
