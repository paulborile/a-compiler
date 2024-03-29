/*
 *	y y e r r o r . c
 *
 * User written subroutines supplied for YACC
 */

/*
 *  AC error routine
 */

#include <stdio.h>
#include "extern.h"

extern char yytext[];

yyError(mess)
char *mess;
{

    if (lin_cnt == lin_sav)
    {
        return;
    }
    if (l_list)
    {
        printf("\n\t***  At line %d %s\n", lin_cnt, mess);
        fflush(stdout);
    }
    else
    {
        fprintf(stderr, "\"%s\" : at line %d %s\n", ifile, lin_cnt, mess);
        fflush(stderr);
    }
    lin_sav = lin_cnt;
    err_cnt++;
    fatal = 1;
}

/*
 * Error routine for redeclaration of symbols
 */

yyredec(label)
char *label;
{

    if (l_list)
    {
        printf("\n\t***  At line %d redeclaration of ' ", lin_cnt);
        printf("%s", label);
        printf(" '\n");
        fflush(stdout);
    }
    else
    {
        fprintf(stderr, "\"%s\" : at line %d redeclaration of ' ", ifile,
                lin_cnt);
        fprintf(stderr, "%s", label);
        fprintf(stderr, " '\n");
        fflush(stderr);
    }
    err_cnt++;
    fatal = 1;
}

yygenerr(l1, l2, l3, l4)
char *l1;
char *l2;
char *l3;
char *l4;
{

    if (l_list)
    {
        printf("\n\t***  At line %d  ", lin_cnt);
        printf("%s", l1);
        printf("%s", l2);
        printf("%s", l3);
        printf("%s\n", l4);
        fflush(stdout);
    }
    else
    {
        fprintf(stderr, "\"%s\" : at line %d  ", ifile, lin_cnt);
        fprintf(stderr, "%s", l1);
        fprintf(stderr, "%s", l2);
        fprintf(stderr, "%s", l3);
        fprintf(stderr, "%s\n", l4);
        fflush(stderr);
    }
    err_cnt++;
    fatal = 1;
}



/*
 * Error message in case of illegal character
 */

ill_char()
{
    if (l_list)
    {
        printf("\n\t***  At line %d illegal character %s.\n", lin_cnt, yytext);
    }
    else
    {
        fprintf(stderr, "\"%s\" : at line %d ", ifile, lin_cnt);
        fprintf(stderr, "illegal character %s.\n", yytext);
    }
    ill_cnt++;
    fatal = 1;
}



/*
 * Could not find the way to take out YACC standard routine
 */

yyerror(mess)
char *mess;
{
}
