/*
 *	r t a b . c
 *
 * Table management for Relocation of addresses
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"
#include "extern.h"

/*
 * Some variables
 */

int r_size = 0;
int r_first = 1;
struct rtab *rbase;
struct rtab *rone;
struct rtab *rtwo;


/* Initialize RTAB for relocation addresses */

struct rtab *r_init(flag, addr)
char *flag;
int addr;
{
    struct rtab *base;

    if ((base = (struct rtab *) malloc(sizeof(struct rtab))) == 0)
    {
        fprintf(stderr, "No more memory. Bye.\n");
        exit(0);
    }
    r_first = 0;
    r_size = 1;
    base->r_out.rel_ref = *flag;
    base->r_out.i_addr = addr;
    base->next = NULL;
    return (base);
}

/* Add one element to RTAB */

struct rtab *r_add(lastnode, flag, addr)
struct rtab *lastnode;
char *flag;
int addr;
{
    struct rtab *ret;

    if ((ret = (struct rtab *) malloc(sizeof(struct rtab))) == 0)
    {
        fprintf(stderr, "No more memory. Bye.\n");
        exit(0);
    }
    lastnode->next = ret;
    ret->r_out.rel_ref = *flag;
    ret->r_out.i_addr = addr;
    ret->next = NULL;
    r_size++;
    return (ret);
}


/* Print RTAB contents for debugging purposes */

r_print(start)
struct rtab *start;
{
    struct rtab *dummy;

    while (dummy != NULL)
    {
        printf("Flag = %c Addr = %d \n",
               dummy->r_out.rel_ref, dummy->r_out.i_addr);
        dummy = dummy->next;
    }
}


/* Free RTAB at end of compilation in order to
   start again with enough free space
 */

r_free(start)
struct rtab *start;
{
    struct rtab *dummy;

    dummy = start;

    while (dummy != NULL)
    {
        start = dummy->next;
        free(dummy);
        dummy = start;
    }
    rbase = NULL;
}
