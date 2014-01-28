/*
 * a r e f . c
 *
 * Code generation and semantic analisys for
 * array as reference
 */

#include <stdio.h>
#include "structs.h"
#include "instcod.h"
#include "extern.h"
#include "var.h"


aref()
{
	is_param = 0;
	ar_len = 1;

	if (l_list) put_ref(yysave,"U");
	if ((in_proc) &&(strncmp(yysave,p_param,MAXVAR) == 0)) {
		ia_add(PUSHR,(act_sp + 3));
		if (s_flag) {
			as_i_int("pushr",(act_sp + 3));
		}
		act_sp += 1;
		return;
	}

	d_dummy = d_search(dbase,yysave);
	lv_dummy = lv_search(lvbase,yysave);

/* same for array as variable refernce */

	if (in_proc) {
		if ((d_dummy == NULL ) && ( lv_dummy == NULL))  {
			yygenerr("undefined variable '",yysave,"'","");
			return;
		}
		if ( lv_dummy != NULL ) {
			ia_add(PUSHIR,(act_sp - (lv_dummy->addr) + 1));
			if ( s_flag) {
		  as_i_int("pushir",(act_sp -(lv_dummy->addr) + 1));
			}
			act_sp += 1;
		}
		else {
			ia_add(PUSHI,(d_dummy->addr));
			rel_all("D");
			act_sp += 1;
			if (s_flag) {
				as_inst_pr("pushi",yysave);
			}
		}
	}
/* here is outside procedure body */
	else {
		if (d_dummy == NULL ) {
			yygenerr("undefined variable '",yysave,"'","");
			return;
		}
		ia_add(PUSHI,(d_dummy->addr));
		rel_all("D");
		if (s_flag) {
			as_inst_pr("pushi",yysave);
		}
	}
}
