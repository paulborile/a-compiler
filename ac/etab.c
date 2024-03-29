/*
 *	e t a b . c
 *
 * Table management for import export and procedure
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

/*
 * Some variables
 */

int e_size = 0;
int e_cnt;
int e_first = 1;
struct etab *ebase;
struct etab *eone;
struct etab *etwo;

#include "extern.h"

/* Initialize ETAB for IMPORT , EXPORT and PROCEDURE declarations */

struct etab *e_init(flag, label)
char *flag;
char *label;
{
    struct etab *base;

    if ((base = (struct etab *) malloc(sizeof(struct etab))) == 0)
    {
        fprintf(stderr, "No more memory for etab. Bye.\n");
        exit(0);
    }
    e_cnt = e_first = 0;
    e_size = 1;
    base->ecnt = e_cnt;
    base->e_out.type = *flag;
    strncpy(base->e_out.ep_name, label, MAXVAR);
    base->next = NULL;
    return (base);
}


/* Add one element to ETAB */

struct etab *e_add(lastnode, flag, label)
struct etab *lastnode;
char *flag;
char *label;
{
    struct etab *ret;

    if ((ret = (struct etab *) malloc(sizeof(struct etab))) == 0)
    {
        fprintf(stderr, "No more memory for etab.Bye .\n");
        exit(0);
    }
    lastnode->next = ret;
    ret->ecnt = ++e_cnt;
    ret->e_out.type = *flag;
    strncpy(ret->e_out.ep_name, label, MAXVAR);
    ret->next = NULL;
    e_size++;
    return (ret);
}

/* Search for one element in ETAB given a pointer to start of list and label */

struct etab *e_search(start, label)
struct etab *start;
char *label;
{
    struct etab *dummy;

    dummy = start;

    while (dummy != NULL)
    {
        if (strncmp(label, dummy->e_out.ep_name, MAXVAR) == 0)
        {
            return (dummy);
        }
        dummy = dummy->next;
    }
    return (NULL);
}


/*
 * Print contents of ETAB for debug purposes only
 */

e_print(start)
struct etab *start;
{
    struct etab *dummy;

    dummy = start;
    while (dummy != NULL)
    {
        printf("Count = %d Type = %c Name = %s Addr = %d\n",
               dummy->ecnt, dummy->e_out.type, dummy->e_out.ep_name,
               dummy->e_out.addr);
        dummy = dummy->next;
    }
}

/*
 * Free ETAB at end of compilation in order to start again
 * with enough free space
 */

e_free(start)
struct etab *start;
{
    struct etab *dummy;

    dummy = start;

    while (dummy != NULL)
    {
        start = dummy->next;
        free(dummy);
        dummy = start;
    }
    ebase = NULL;
}
