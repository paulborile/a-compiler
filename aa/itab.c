/*
 *	i t a b . c
 *
 * Instruction Table management 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

/*
 * Some variables
 */

int i_size = 0;
int i_cnt;

#include "extern.h"


i1_add(opcode)
int opcode;
{
	if (i_size > MAXITAB)
	{
		fprintf(stderr, "No more space for itab \n");
		exit(1);
	}
	itab[i_cnt] = opcode;
	i_cnt++;
	i_size++;
}

i2_add(operand)
int operand;
{
	if (i_size > MAXITAB)
	{
		fprintf(stderr, "No more space for itab \n");
		exit(1);
	}
	itab[i_cnt] = operand;
	i_cnt++;
	i_size++;
}

i_print()
{
	int i;

	printf("Itab size = %d \n", i_size);
	for (i = 0; i < i_size; i++)
	{
		printf("%d\t%d\n", i, itab[i]);
	}
}
