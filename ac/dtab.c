/*
 *	d t a b . c
 *
 * Table management for variables and arrays
 */

#include <stdio.h>
#include "structs.h"

/*
 * Some variables
 */

int	d_size = 0;
int	d_cnt;
int	d_first = 1;
struct	dtab	*dbase;
struct	dtab	*done;
struct	dtab	*dtwo;

#include "extern.h"

/* Initialize DTAB for VAR and ARRAY declarations */

struct	dtab
*d_init(label,len)
char	*label;
int	len;
{
	struct	dtab	*base;

	if ((base = (struct dtab *) malloc(sizeof (struct dtab))) == 0 ) {
		fprintf(stderr,"No more memory for dtab. Bye.\n");
		exit(0);
	}
	d_cnt = d_first = 0;
	d_size = 1;
	base->addr = d_cnt;
	strncpy(base->d_out.var_name,label,MAXVAR);
	base->d_out.var_len = len;
	base->next = NULL;
	return(base);
}


/* Add one element to DTAB */

struct	dtab
*d_add(lastnode,label,len)
struct	dtab	*lastnode;
char	*label;
int	len;
{
	struct	dtab	*ret;

	if ((ret = (struct dtab *) malloc(sizeof(struct dtab))) == 0) {
		fprintf(stderr,"No more memory for dtab.Bye .\n");
		exit(0);
	}
	lastnode->next = ret;	
	ret->addr = ++d_cnt;
	strncpy(ret->d_out.var_name,label,MAXVAR);
	ret->d_out.var_len = len;
	ret->next = NULL;
	d_size++;
	return(ret);
}

/* Search for one entry in DTAB given a pointer to start of list and label */

struct	dtab
*d_search(start,label)
struct	dtab	*start;
char	*label;
{
	struct	dtab	*dummy;

	dummy = start;
	
	while ( dummy != NULL ) {
		if (strncmp(label,dummy->d_out.var_name,MAXVAR) == 0) {
			return(dummy);
		}
		dummy = dummy->next;
	}
	return(NULL);
}

/* 
 * Print contents of DTAB for debugging purposes 
 */

d_print(start)
struct	dtab	*start;
{
	struct	dtab	*dummy;
	
	dummy = start;
	while ( dummy != NULL ) {
		printf("Addr = %d Var = %s Len = %d \n",
		dummy->addr,dummy->d_out.var_name,dummy->d_out.var_len);
		dummy = dummy->next;
	}
}

/*
 * Free DTAB at end of compilation in order to start again
 * with enough free space
 */

d_free(start)
struct	dtab	*start;
{
	struct	dtab	*dummy;

	dummy = start;
	
	while ( dummy != NULL ) {
		start = dummy->next;
		free(dummy);
		dummy = start;
	}
	dbase = NULL;
}
