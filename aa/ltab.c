/*
 *	l t a b . c
 *
 * Table management for labels and their addresses
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

/*
 * Some variables
 */

int l_size = 0;
int l_cnt;
int l_first = 1;
struct ltab *lbase = NULL;
struct ltab *lone;
struct ltab *ltwo;

#include "extern.h"

/* Initialize LTAB for LABELS and addresses */

struct ltab *l_init(label, addr)
char *label;
int addr;
{
    struct ltab *base;

    if ((base = (struct ltab *) malloc(sizeof(struct ltab))) == 0)
    {
        fprintf(stderr, "No more memory for ltab. Bye.\n");
        exit(0);
    }
    l_cnt = l_first = 0;
    l_size = 1;
    base->addr = addr;
    strncpy(base->lab_name, label, MAXVAR);
    base->next = NULL;
    return (base);
}


/* Add one element to DTAB */

struct ltab *l_add(lastnode, label, addr)
struct ltab *lastnode;
char *label;
int addr;
{
    struct ltab *ret;

    if ((ret = (struct ltab *) malloc(sizeof(struct ltab))) == 0)
    {
        fprintf(stderr, "No more memory for ltab.Bye .\n");
        exit(0);
    }
    lastnode->next = ret;
    ret->addr = addr;
    strncpy(ret->lab_name, label, MAXVAR);
    ret->next = NULL;
    l_size++;
    return (ret);
}

/* Search for one entry in DTAB given a pointer to start of list and label */

struct ltab *l_search(start, label)
struct ltab *start;
char *label;
{
    struct ltab *dummy;

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

l_print(start)
struct ltab *start;
{
    struct ltab *dummy;

    dummy = start;
    while (dummy != NULL)
    {
        printf("Addr = %d Label = %s \n", dummy->addr, dummy->lab_name);
        dummy = dummy->next;
    }
}

/*
 * Free DTAB at end of compilation in order to start again
 * with enough free space
 */

l_free(start)
struct ltab *start;
{
    struct ltab *dummy;

    dummy = start;

    while (dummy != NULL)
    {
        start = dummy->next;
        free(dummy);
        dummy = start;
    }
    lbase = NULL;
}
