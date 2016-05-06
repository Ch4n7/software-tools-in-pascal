#include "detab.h"
#include <stdlib.h>

extern int g_argc;
extern char **g_argv;
bool tabpos[MAX_LINE+1];

void
init_tabpos()
{
	int	i;

	for (i = 1; i <= MAX_LINE; i++)
		tabpos[i] = false;
}

// Initialize TAB positions in the array of 'tabpos'.
void
set_tabpos()
{
	int	i;
	int	n, m;
	
	if (g_argc == 1) {
	// no cmd-line arguments, default setting
		for (i = 1; i <= MAX_LINE; i++) {
			tabpos[i] = ((i % TABSTOPS) == 1) ? true : false;
		}
	} else { 
	// there is some cmd-line arguments
		if (g_argc == 3 && g_argv[2][0] == '+') {	
		// shorthand args
			init_tabpos();
			m = atoi(g_argv[1]);
			n = atoi(g_argv[2] + 1); // now, point to the character right after ARG_SH_SIGN
			for (i = m; i <= MAX_LINE; i += n)
				tabpos[i] = true;
		} else {	
		// normal cmd-line args
			init_tabpos();
			for (i = 1; i < g_argc; i++) {
				n = atoi(g_argv[i]);
				if (n > 0 && n <= MAX_LINE)
					tabpos[n] = true;	
			}
		}
	}
}

// Return true if column 'col' in array 'tabpos' is a stop; or false.
bool
is_stop(int col)
{
	bool	ret;

	if (col > MAX_LINE)	// Always stop if column greater than MAX_LINE.
		ret = true;
	else 
		ret = tabpos[col];

	return ret;
}
