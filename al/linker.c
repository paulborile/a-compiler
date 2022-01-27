/*
 * START OF LINKER MODULE
 */

#include <stdio.h>
#include <stdlib.h>
#include "vmacdef.h"

#define LIBDIR  "/home/paul/lib/io.o"

extern inetab();
extern first();
extern second();
extern put_num();
int l_flag;
FILE *fopen();
int in_mod = 0;
int addisp = 0;
int splow = MEM_DIM;
extern char tmp_name[];
extern FILE *tmp_crea();

link(argc, argv)
int argc;
char *argv[];
{
    int i;
    int inetab();
    FILE *fp;

    inetab();                   /* start of first pass */
    fp = tmp_crea();
    for (i = 1; i < argc; i++)
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == 'o')
                i++;
        }
        else
            first(argv[i], fp);
    l_flag = 0;
    if (in_mod)
        first(LIBDIR, fp);
    put_num(-1, fp);
    fclose(fp);
    if ((fp = fopen(tmp_name, "r")) == NULL)
    {
        fprintf(stderr, "al : ");
        perror(tmp_name);
        exit(1);
    }
    second(fp);
    fclose(fp);
    unlink(tmp_name);
}

/*
 * END OF LINKER MODULE
 */
