/*
 * START OF MODULE OPEN
 */

#include    <stdio.h>
#include <stdlib.h>

extern int l_flag;
char *out_name;

options(argc, argv)
int *argc;
char *argv[];
{
    int c;
    int errflag = 0;
    int al_def = 0;
    extern int optind;
    extern char *optarg;

    while ((c = getopt(*argc, argv, "lo:")) != EOF)
        switch (c)
        {
        case 'l':
            l_flag++;
            break;
        case 'o':
            if (al_def)
                errflag++;
            out_name = optarg;
            al_def++;
            break;
        case '?':
            errflag++;
        }
    if (errflag)
    {
        fprintf(stderr, "al: usage [-l] [-o out_file] args\n");
        exit(2);
    }
    return (1);
}

/*
 * END OF GET_OPTION
 */

cmp(str1, str2)
char *str1, *str2;
{
    while (*str1 && *str2)
        if (*(str1++) != *(str2++))
            return (0);
    return (1);
}

/*
 * END OF CMP
 */

/*
 * END OF OPEN MODULE
 */
