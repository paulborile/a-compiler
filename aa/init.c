/* 
 *    Thu Oct 10 1985
 *
 *    i n i t . c    Initialize variables for other compilations 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extern.h"

extern char tsave[];
extern struct dtab *dbase;
extern struct etab *ebase;
extern struct rtab *rbase;
extern int d_first, e_first, r_first;

ac_init()
{

/*	if (!d_first) d_free(dbase);
	if (!e_first) e_free(ebase);
	if (!r_first) r_free(rbase); */
	dbase = NULL;
	rbase = NULL;
	ebase = NULL;
	tsave[0] = '\0';
	lin_sav = ill_cnt = err_cnt = fatal = 0;
	e_first = r_first = d_first = lin_cnt = 1;
}
