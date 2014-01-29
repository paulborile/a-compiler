
/*
 * MODULE OF RTAB FUNCTIONS
 */

#include <stdio.h>
#include <stdlib.h>
#include "defstruct.h"

#define	MAX_RTAB	400

extern int errorfile();
static rrec bustack[MAX_RTAB];
static int max = 0;
static rrec rmod_buff;

inrtab()
{
	max = 0;
}

rrec *get_fi_rel(in)
FILE *in;
{
	rrec *sp;

	if (1 != (fread((char *) &rmod_buff, sizeof(rrec), 1, in)))
		errorfile("Error in reading rtab");
	sp = &rmod_buff;
	return (sp);
}

rrec *rt_f1_pass(num)
int num;
{
	if (num < max)
		return (&bustack[num]);
	else
		return (NULL);
}

put_f1_rt(point)
rrec *point;
{
	if (MAX_RTAB <= max)
	{
		fprintf(stderr, "al : RTAB STACK OVERFLOW \n");
		exit(1);
	}
	bustack[max].flag = point->flag;
	bustack[max].address = point->address;
	max++;
}

/*
 * END RTAB FUNCTIONS MODULE
 */
