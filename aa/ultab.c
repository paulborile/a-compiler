/*
 *	u l t a b . c
 *
 * Table management for labels and thir address
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

/*
 * Some variables
 */

int ul_size = 0;
int ul_cnt;
int ul_first = 1;
struct ultab *ulbase = NULL;
struct ultab *ulone;
struct ultab *ultwo;

#include "extern.h"

/* Initialize ULTAB for undefined LABELS and addresses */

struct ultab *ul_init(label, addr)
char *label;
int addr;
{
	struct ultab *base;

	if ((base = (struct ultab *) malloc(sizeof(struct ultab))) == 0)
	{
		fprintf(stderr, "No more memory for ultab. Bye.\n");
		exit(0);
	}
	ul_cnt = ul_first = 0;
	ul_size = 1;
	base->i_addr = addr;
	strncpy(base->lab_name, label, MAXVAR);
	base->next = NULL;
	return (base);
}


/* Add one element to ULTAB */

struct ultab *ul_add(lastnode, label, addr)
struct ultab *lastnode;
char *label;
int addr;
{
	struct ultab *ret;

	if ((ret = (struct ultab *) malloc(sizeof(struct ultab))) == 0)
	{
		fprintf(stderr, "No more memory for ultab.Bye .\n");
		exit(0);
	}
	lastnode->next = ret;
	ret->i_addr = addr;
	strncpy(ret->lab_name, label, MAXVAR);
	ret->next = NULL;
	ul_size++;
	return (ret);
}

/* Search for one entry in ULTAB given a pointer to start of list and label */

struct ultab *ul_search(start, label)
struct ultab *start;
char *label;
{
	struct ultab *dummy;

	dummy = start;

	while (dummy != NULL)
	{
		if (strncmp(label, dummy->lab_name, MAXVAR) == 0)
		{
			return (dummy);
		}
		dummy = dummy->next;
	}
	return (NULL);
}

/* 
 * Print contents of DTAB for debugging purposes 
 */

ul_print(start)
struct ultab *start;
{
	struct ultab *dummy;

	dummy = start;
	while (dummy != NULL)
	{
		printf("Addr = %d Label = %s \n", dummy->i_addr, dummy->lab_name);
		dummy = dummy->next;
	}
}

/*
 * Free ULTAB at end of compilation in order to start again
 * with enough free space
 */

ul_free(start)
struct ultab *start;
{
	struct ultab *dummy;

	dummy = start;

	while (dummy != NULL)
	{
		start = dummy->next;
		free(dummy);
		dummy = start;
	}
	ulbase = NULL;
}
