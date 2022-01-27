/*
 *	c o u t . c
 *
 * "C" printout functions
 */

#include <stdio.h>
#include "extern.h"


/*
 * Print one token to the "C" file
 */

c_put(str)
char *str;
{
    fprintf(fp_c, "%s", str);
}

/*
 * Put a TAB inside the "C" file
 */

c_put_tab(number)
int number;
{
    while (number--)
        fprintf(fp_c, "\t");
}


/*
 * Put a NL inside the "C" file
 */

c_put_nl()
{
    fprintf(fp_c, "\n");
}
