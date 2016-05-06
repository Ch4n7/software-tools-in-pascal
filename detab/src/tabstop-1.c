#include "detab.h"

// Another way to write detab.
//
// KEYPOINT: Always keep the different, and that should be information we
// need.

int tabstops[MAX_LINE+1];

// The 'tabstops' array contains a list of the columns which contain tab
// stops; the list in terminated by zero entry.
void
set_tabpos()
{
	int	i;
	extern int tabstops[];

	tabstops[0] = 1;
	for (i = 1; tabstops[i-1] <= MAX_LINE; i++) {
		tabstops[i] = 1 + TABSTOPS * i; 
	}
	tabstops[i] = 0;

}

// Return true if column 'col' in array 'tabpos' is a stop; or false.
bool
is_stop(int col)
{
	int	i;
	bool	ret;
	extern int tabstops[];

	if (col > MAX_LINE)	// Always stop if column greater than MAX_LINE.
		ret = true;
	else {	// search 'tabstops' array to check if column 'col' is a tab stop.
		i = 0;
		while (tabstops[i] != 0 && col > tabstops[i]) i++;	// linear comparision
		if (col == tabstops[i])
			ret = true;
		else
			ret = false;
	}

	return ret;
}
