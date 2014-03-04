/*
 *	 y y v a r s . c
 *
 * What to do when I find variable declarations
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"
#include "structs.h"
#define	TOBEDEF	-1

/* 
 * Extern variables
*/

/* For dtab */

extern int d_cnt;
extern int d_first;
extern struct dtab *dbase;
extern struct dtab *done;
extern struct dtab *dtwo;
struct dtab *d_init(), *d_add(), *d_search();

/* For etab */

extern int e_cnt;
extern int e_first;
extern struct etab *ebase;
extern struct etab *eone;
extern struct etab *etwo;
struct etab *e_init(), *e_add(), *e_search();

/* For rtab */

extern int r_first;
extern struct rtab *rbase;
extern struct rtab *rone;
extern struct rtab *rtwo;
struct rtab *r_init(), *r_add();


/* for itab */

extern int i_size;
extern int i_cnt;

/* for ltab */

extern int l_cnt;
extern int l_first;
extern struct ltab *lbase;
extern struct ltab *lone;
extern struct ltab *ltwo;
struct ltab *l_init(), *l_add(), *l_search();

/* externs for undefined labels table */

extern struct ultab *ulbase, *ulone, *ultwo, *ul_init(), *ul_add();
extern int ul_first;

/* general externs */

extern int found_start;
extern char yytext[];
extern char tsave[];
extern char pname[];

/* Also need space for PROGRAM statement */

prog_all()
{
	if (e_first)
	{
		ebase = e_init("M", pname);
		eone = etwo = ebase;
	}
}

/* fill program entry point with actual itab address */

fill_p_add()
{
	struct ltab *l_dummy;
	struct etab *e_dummy;

	if (found_start)
	{
		if ((l_dummy = l_search(lbase, pname)) == NULL)
		{
			yygenerr("Start directive without label ", "", "", "");
			return;
		}
		else
		{
			e_dummy = e_search(ebase, pname);
			e_dummy->e_out.addr = l_dummy->addr;
		}
	}
}

/* 
 * Make second pass to find unresolved labels
 */

s_pass()
{
	struct ltab *l_dummy;
	struct ultab *ul_dummy;

	ul_dummy = ulbase;

	while (ul_dummy != NULL)
	{
		if ((l_dummy = l_search(lbase, ul_dummy->lab_name)) == NULL)
		{
			yygenerr("Undefined label '", ul_dummy->lab_name, "'", "");
			return;
		}
		itab[(ul_dummy->i_addr)] = l_dummy->addr;
		ul_dummy = ul_dummy->next;
	}
}


/* 
 * Allocate space for import variables
 */

imp_all()
{
	if (e_first)
	{
		ebase = e_init("I", yytext);
		eone = etwo = ebase;
	}
	else
	{
		if (e_search(ebase, yytext) == NULL)
		{
			etwo = e_add(eone, "I", yytext);
			eone = etwo;
		}
		else
		{
			yyredec(yytext);
		}
	}
}


/*
 * Allocate space for export variables
 */

exp_all()
{
	struct etab *dummy;

	if (e_first)
	{
		ebase = e_init("E", yytext);
		eone = etwo = ebase;
		return;
	}
	dummy = e_search(ebase, yytext);
	if (dummy == NULL)
	{
		etwo = e_add(eone, "E", yytext);
		etwo->e_out.addr = TOBEDEF;
		eone = etwo;
		return;
	}
	if (dummy->e_out.type == 'P')
	{
		dummy->e_out.type = 'E';
		return;
	}
	yyredec(yytext);
}

/* 
 * Allocate space for LABELS
 */

lab_all()
{
	struct etab *dummy;

	if (l_first)
	{
		lbase = l_init(tsave, i_cnt);
		lone = ltwo = lbase;
	}
	else
	{
		if (l_search(lbase, tsave) == NULL)
		{
			ltwo = l_add(lone, tsave, i_cnt);
			lone = ltwo;
		}
		else
		{
			yyredec(tsave);
		}
	}
	dummy = e_search(ebase, tsave);
	if (dummy == NULL)
		return;
	dummy->e_out.addr = i_cnt;
}

/*
 * Allocate space for undefined labels 
 */

ul_all()
{
	if (ul_first)
	{
		ulbase = ul_init(yytext, i_cnt);
		ulone = ultwo = ulbase;
	}
	else
	{
		ultwo = ul_add(ulone, yytext, i_cnt);
		ulone = ultwo;
	}
	i2_add(-1);
	rel_all("J");
}


/*
 * Allocate space for array declarations 
 */

word_all()
{
	if (d_first)
	{
		dbase = d_init(tsave, atoi(yytext));
		done = dtwo = dbase;
	}
	else
	{
		if (d_search(dbase, tsave) == NULL)
		{
			dtwo = d_add(done, tsave, atoi(yytext));
			done = dtwo;
		}
		else
		{
			yyredec(tsave);
		}
	}
}


/*
 * Allocate entry for procedure
 */

proc_all()
{
	struct etab *dummy;

	if (e_first)
	{
		ebase = e_init("P", yytext);
		eone = etwo = ebase;
		return;
	}
	dummy = e_search(ebase, yytext);
	if (dummy == NULL)
	{
		etwo = e_add(eone, "P", yytext);
		eone = etwo;
		return;
	}
	if (dummy->e_out.type == 'E')
	{
		return;
	}
	yyredec(yytext);
}

/*
 *   Allocate entry in rtab for instruction to be relocated
 */

rel_all(flag)
char *flag;
{
	if (r_first)
	{
		rbase = r_init(flag, i_cnt - 1);
		rone = rtwo = rbase;
	}
	else
	{
		rtwo = r_add(rone, flag, i_cnt - 1);
		rone = rtwo;
	}
}


/*
 * Test if there are some export without procedures to be exported
 */


exp_tst()
{
	struct etab *e_scan;

	e_scan = ebase;
	while (e_scan != NULL)
	{
		if ((e_scan->e_out.type == 'E') && (e_scan->e_out.addr == -1))
		{
			yygenerr("Unresolved export :", e_scan->e_out.ep_name, "", "");
		}
		e_scan = e_scan->next;
	}
}
