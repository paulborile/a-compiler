/*
 * MODULE OF ETAB FUNCTIONS
 */

#include <stdio.h>
#include <stdlib.h>
#include "defstruct.h"

#define	MAX_ETAB	150

extern int errorfile();
static erec stack[MAX_ETAB];
static int max = 0;

inetab()
{
	max = 0;
}

max_etab()
{
	return (max);
}

erec *get_proc(in)
FILE *in;
{
	static erec buffer;
	erec *sp;

	if (1 != (fread((char *) &buffer, sizeof(erec), 1, in)))
		errorfile("Error in reading etab");
	sp = &buffer;
	return (sp);
}

erec *et_num_get(num)
int num;
{
	if ((num >= max) || (num < 0))
		errorfile("Error in accessing Etab");
	else
		return (&stack[num]);
}

put_etab(point)
erec *point;
{
	int i;

	if (MAX_ETAB <= max)
	{
		fprintf(stderr, "al : ETAB STACK OVERFLOW \n");
		exit(1);
	}
	stack[max].flag = point->flag;
	for (i = 0; i < MAXCHAR; i++)
		stack[max].name[i] = point->name[i];
	stack[max].address = point->address;
	max++;
}

erec *search_eta(name, flag)
char name[MAXCHAR];
char flag;
{
	int i;

	for (i = 0; i <= max; i++)
		if (((strncmp(name, stack[i].name, MAXCHAR)) == 0)
			&& (stack[i].flag == flag))
			return (&stack[i]);
	return (NULL);
}

change_ref(point)
erec *point;
{
	int i;

	for (i = 0; i <= max; i++)
		if (((strncmp(point->name, stack[i].name, MAXCHAR)) == 0)
			&& (stack[i].flag == 'I'))
		{
			stack[i].flag = 'E';
			stack[i].address = point->address;
		}
}


/*
 * END ETAB FUNCTIONS MODULE
 */
