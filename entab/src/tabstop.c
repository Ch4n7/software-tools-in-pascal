#include "entab.h"

// Initialize TAB positions in the array of 'tabpos'.
void
set_tabpos()
{
	int	i;
	extern bool tabpos[];

	for (i = 1; i <= MAX_LINE; i++) {
		tabpos[i] = ((i % TABSTOPS) == 1) ? true : false;
	}
}

// Return true if column 'col' in array 'tabpos' is a stop; or false.
bool
is_stop(int col)
{
	bool	ret;
	extern bool tabpos[];

	if (col > MAX_LINE)	// Always stop if column greater than MAX_LINE.
		ret = true;
	else 
		ret = tabpos[col];

	return ret;
}
