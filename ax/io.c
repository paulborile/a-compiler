/*
 * IO.C MODULE
 */

#include "error.h"
#include <stdio.h>

get_byte(fp)
FILE *fp;
{
    char key;

    if (1 != fread(&key, sizeof(char), 1, fp))
        return (ERROR_FUNCT);
    return ((int) key);
}

get_word(fp, num)
FILE *fp;
register int *num;
{
    if (1 != fread((char *) num, sizeof(int), 1, fp))
        return (ERROR_FUNCT);
    return (!ERROR_FUNCT);
}

/*
 * END IO.C MODULE
 */
