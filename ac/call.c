/*
 *	c a l l . c
 *
 * Code generation and semantic analisys 
 * for CALL statement
 *
 */


#include <stdio.h>
#include "structs.h"
#include "instcod.h"
#include "extern.h"
#include "var.h"


call()
{

	if (( e_dummy = e_search(ebase,tsave)) == NULL) {
		yygenerr("undefined procedure '",tsave,"'",""); 
		return;
	}
	if (is_param) {
		ia_add(PUSHR,ar_len);
		if (s_flag) {
			as_i_int("pushr",ar_len);
		}
	}
	else {
		ia_add(PUSHI,ar_len);
		if (s_flag) {
			as_i_int("pushi",ar_len);
		}
	}
	if (in_proc) act_sp += 1;
	ia_add(CALL,e_dummy->ecnt);
	rel_all("E");
	ia_add(SP_FREE,2);
	if (in_proc)	act_sp -= 2;
	if (s_flag) {
		as_inst_pr("call",tsave);
		as_inst_pr("spfree","2");
	}
}
