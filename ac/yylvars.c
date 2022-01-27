/*
 * y y l v a r s . c
 *
 * What to do when I find local variable declarations
 */

#include <stdio.h>
#include "extern.h"
#include "structs.h"
#define TOBEDEF -1

/*
 * Extern variables
 */

/* For lvtab */

extern int lv_cnt;
extern int lv_first;
extern struct lvtab *lvbase;
extern struct lvtab *lvone;
extern struct lvtab *lvtwo;
struct lvtab *lv_init(), *lv_add(), *lv_search();

extern char yytext[];
extern char tsave[];
extern char pname[];

/*
 * Allocate space for local VAR declarations
 */

lvar_all()
{
    if (lv_first)
    {
        lvbase = lv_init(yytext, 1);
        lvone = lvtwo = lvbase;
    }
    else
    {
        if (lv_search(lvbase, yytext) == NULL)
        {
            lvtwo = lv_add(lvone, yytext, 1);
            lvone = lvtwo;
        }
        else
        {
            yyredec(yytext);
        }
    }
}

/*
 * Allocate space for local ARRAY declarations
 */

larr_all()
{
    if (lv_first)
    {
        lvbase = lv_init(tsave, atoi(yytext));
        lvone = lvtwo = lvbase;
    }
    else
    {
        if (lv_search(lvbase, tsave) == NULL)
        {
            lvtwo = lv_add(lvone, tsave, atoi(yytext));
            lvone = lvtwo;
        }
        else
        {
            yyredec(yytext);
        }
    }
}
