/*
 *	l v t a b . c
 *
 * Table management for local variables and arrays
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

/*
 * Some variables
 */

int lv_size = 0;
int lv_cnt;
int lv_first = 1;
struct lvtab *lvbase;
struct lvtab *lvone;
struct lvtab *lvtwo;

#include "extern.h"

/* Initialize LVTAB for local VAR and ARRAY declarations */

struct lvtab *lv_init(label, len)
char *label;
int len;
{
    struct lvtab *base;

    if ((base = (struct lvtab *) malloc(sizeof(struct lvtab))) == 0)
    {
        fprintf(stderr, "No more memory for lvtab. Bye.\n");
        exit(0);
    }
    base->addr = lv_cnt = lv_first = 0;
    lv_size = 1;
    base->addr = len;
    strncpy(base->lv_out.var_name, label, MAXVAR);
    base->lv_out.var_len = len;
    base->next = NULL;
    return (base);
}


/* Add one element to LVTAB */

struct lvtab *lv_add(lastnode, label, len)
struct lvtab *lastnode;
char *label;
int len;
{
    struct lvtab *ret;

    if ((ret = (struct lvtab *) malloc(sizeof(struct lvtab))) == 0)
    {
        fprintf(stderr, "No more memory for lvtab.Bye .\n");
        exit(0);
    }
    lastnode->next = ret;

/* this part changes from dtab.c */

    ret->addr = lastnode->addr + len;
    strncpy(ret->lv_out.var_name, label, MAXVAR);
    ret->lv_out.var_len = len;
    ret->next = NULL;
    lv_size++;
    return (ret);
}

/* Search for one entry in LVTAB given a pointer to start of list and label */

struct lvtab *lv_search(start, label)
struct lvtab *start;
char *label;
{
    struct lvtab *dummy;

    dummy = start;

    while (dummy != NULL)
    {
        if (strncmp(label, dummy->lv_out.var_name, MAXVAR) == 0)
        {
            return (dummy);
        }
        dummy = dummy->next;
    }
    return (NULL);
}

/*
 * Print contents of LVTAB for debugging purposes
 */

lv_print(start)
struct lvtab *start;
{
    struct lvtab *dummy;

    dummy = start;
    while (dummy != NULL)
    {
        printf("Addr = %d Var = %s Len = %d \n",
               dummy->addr, dummy->lv_out.var_name, dummy->lv_out.var_len);
        dummy = dummy->next;
    }
}

/*
 * Free LVTAB at end of compilation in order to start again
 * with enough free space
 */

lv_free(start)
struct lvtab *start;
{
    struct lvtab *dummy;

    dummy = start;

    while (dummy != NULL)
    {
        start = dummy->next;
        free(dummy);
        dummy = start;
    }
    lvbase = NULL;
}
