/*
 * MODULE OF MAP LISTING
 */

#include <stdio.h>
#include "defstruct.h"

extern int l_flag;

pr_line()
{
    if (l_flag)
        printf("\n");
}

pr_sep()
{
    if (l_flag)
    {
        printf("*******************************************");
        printf("*********\n");
    }
}

pr_mod_na(name)
char *name;
{
    if (l_flag)
        printf("* Module name : %10.8s  \t\t\t   *\n", name);
}

pr_proc(poine)
erec *poine;
{
    if (l_flag)
    {
        if ((poine->flag) != 'M')
            printf("* Procedure    : %10.8s  \t address =%8d *\n",
                   poine->name, poine->address);
        else
            printf("* Start        : %10.8s  \t address =%8d *\n",
                   poine->name, poine->address);
    }
}

pr_data(poind, address)
drec *poind;
int address;
{
    if (l_flag)
        printf("* Variable     : %10.8s  \t address =%8d *\n",
               poind->name, address);
}

/*
 * END MODULE MAP LISTING
 */
