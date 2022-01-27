
/*
 * MODULE OF RBUFFER FUNCTIONS
 */

#include <stdio.h>
#include <stdlib.h>
#include "defstruct.h"

#define MAX_RBUFFER 50

extern int put_num();
static rrec stack[MAX_RBUFFER];
static int max = 0;

inrbuffer()
{
    max = 0;
}

put_f2_rt(point)
rrec *point;
{
    if (MAX_RBUFFER <= max)
    {
        fprintf(stderr, "al : RBUFFER STACK OVERFLOW \n");
        exit(1);
    }
    stack[max].flag = point->flag;
    stack[max].address = point->address;
    max++;
}

rrec *rt_f2_pass(num)
int num;
{
    if (num < max)
        return (&stack[num]);
    else
        return (NULL);
}

put_out(out)
FILE *out;
{
    rrec *poinr;
    int i;

    put_num(max, out);
    for (i = 0; i < max; i++)
    {
        poinr = rt_f2_pass(i);
        fwrite((char *) poinr, sizeof(rrec), 1, out);
    }
}


/*
 * END RBUFFER FUNCTIONS MODULE
 */
