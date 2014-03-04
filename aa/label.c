/*
 *	l a b e l . c
 *
 * What to do when I find a label as operand of an instruction
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "extern.h"

extern struct dtab *dbase;
struct dtab *d_dummy;
struct dtab *d_search();

extern struct etab *ebase;
struct etab *e_dummy;
struct etab *e_search();

extern struct ltab *lbase;
struct ltab *l_dummy;
struct ltab *l_search();

extern char yytext[];

/* action to be perfomed */

eval_lab()
{
	d_dummy = d_search(dbase, yytext);
	e_dummy = e_search(ebase, yytext);
	l_dummy = l_search(lbase, yytext);

/* see if in DTAB */

	if (d_dummy != NULL)
	{
		i2_add(d_dummy->addr);
		rel_all("D");
		return;
	}

/* see if in ETAB */

	if (e_dummy != NULL)
	{
		i2_add(e_dummy->ecnt);
		rel_all("E");
		return;
	}

/* see if already in LTAB */

	if (l_dummy != NULL)
	{
		i2_add(l_dummy->addr);
		rel_all("J");
		return;
	}

	ul_all();
}
