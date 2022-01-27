
/*
 * MODULE OF DTAB FUNCTIONS
 */

#include <stdio.h>
#include <stdlib.h>
#include "defstruct.h"

#define MAX_DTAB    500

extern int errorfile();
static dtab stack[MAX_DTAB];
static int max = 0;

indtab()
{
    max = 0;
}

drec *get_data(in)
FILE *in;
{
    static drec buffer;
    drec *sp;

    if (1 != (fread((char *) &buffer, sizeof(drec), 1, in)))
        errorfile("Error in reading dtab");
    sp = &buffer;
    return (sp);
}

dtab *dt_num_get(num)
int num;
{
    return (&stack[num]);
}

put_dtab(point, address)
drec *point;
int address;
{
    int i;

    if (MAX_DTAB <= max)
    {
        fprintf(stderr, "al : DTAB STACK OVERFLOW \n");
        exit(1);
    }
    stack[max].cont.length = point->length;
    for (i = 0; i < MAXCHAR; i++)
        stack[max].cont.name[i] = point->name[i];
    stack[max].address = address;
    max++;
}

/*
 * END DTAB FUNCTIONS MODULE
 */
