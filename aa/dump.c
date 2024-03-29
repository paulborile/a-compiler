/*
 *  d u m p . c
 *
 *  Utilities to dump tables and sizes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dump.h"
#include "extern.h"
#include "structs.h"


/* externs for dtab */

extern int d_size;
extern struct dtab *dbase;

/* externs for etab */

extern int e_size;
extern struct etab *ebase;

/* externs for rtab */

extern int r_size;
extern struct rtab *rbase;

/* externs for itab */

extern int i_size;


d_dump()
{
    struct dtab *dummy;

    t_size.tab_size = d_size;
    write(fd_out, &t_size, sizeof(struct size));

    dummy = dbase;

    while (dummy != NULL)
    {
        write(fd_out, &dummy->d_out, sizeof(struct dout));
        dummy = dummy->next;
    }
}

e_dump()
{
    struct etab *dummy;

    t_size.tab_size = e_size;
    write(fd_out, &t_size, sizeof(struct size));

    dummy = ebase;

    while (dummy != NULL)
    {
        write(fd_out, &dummy->e_out, sizeof(struct eout));
        dummy = dummy->next;
    }
}

r_dump()
{
    struct rtab *dummy;

    t_size.tab_size = r_size;
    write(fd_out, &t_size, sizeof(struct size));

    dummy = rbase;
    while (dummy != NULL)
    {
        write(fd_out, &dummy->r_out, sizeof(struct rout));
        dummy = dummy->next;
    }
}

i_dump()
{
    int cnt;

    t_size.tab_size = i_size;
    write(fd_out, &t_size, sizeof(struct size));

    if ((cnt =
             write(fd_out, itab, (i_size * sizeof(cnt)))) != (i_size * sizeof(cnt)))
    {
        fprintf(stderr, "Error in writing itab\n");
        exit(1);
    }
}
