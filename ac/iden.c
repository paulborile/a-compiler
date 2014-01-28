/*
 *	i d e n . c
 *
 * Identifier in writestr
 */

#define	MAXMESS	200
#define	LF	10
#include <stdio.h>
#include "instcod.h"
#include "structs.h"
#include "extern.h"
#include "var.h"

extern	char	yytext[];
extern	int	act_sp,s_flag,in_proc;
extern	struct	etab	*e_read,*e_write,*e_rd_str,*e_wr_str;

string()
{
	char	mess[MAXMESS];
	int	messlen,i;

	strcpy(mess,yytext);
	messlen = strlen(mess);
#ifdef	TRACE
	printf("%s  %d\n",mess,messlen);
#endif

	ia_add(PUSHI,LF);
	if (in_proc) act_sp += 1;
	if (s_flag)  {
		as_i_int("pushi",LF);
	}
	for (i = messlen - 1; i >= 0; i-- ) {
#ifdef TRACE
		printf("%d\t",mess[i]);
#endif
		ia_add(PUSHI,mess[i]);
		if (s_flag) {	
			as_i_int("pushi",mess[i]);
		}
		if (in_proc) act_sp += 1;
	}
	ia_add(PUSHIR,1);
	ia_add(PUSHI,messlen + 1);
	if (in_proc) act_sp += 2;
	if (s_flag) {
		as_inst_pr("pushir","1");
		as_i_int("pushi",messlen + 1);
	}
	ia_add(CALL,e_wr_str->ecnt);
	rel_all("E");
	ia_add(SP_FREE,3+messlen);
	if (in_proc)	act_sp -= 3+messlen;
	if (s_flag) {
		as_inst_pr("call","writestr");
		as_i_int("spfree",3+messlen);
	}
}



/*
 *	Put variable for writestr
 */


ident()
{

	if ((in_proc) &&(strncmp(yytext,p_param,MAXVAR) == 0)) {
		ia_add(PUSHR,(act_sp + 3));
		if (s_flag) {
			as_i_int("pushr",(act_sp + 3));
		}
		act_sp += 1;
		ia_add(PUSHR,(act_sp + 2));
		if (s_flag) {
			as_i_int("pushr",(act_sp + 3));
		}
		act_sp += 1;
		return;
	}
		
	d_dummy = d_search(dbase,yytext);
	lv_dummy = lv_search(lvbase,yytext);

/* here we are in procedure module */

	if (in_proc) {
		if ((d_dummy == NULL ) && ( lv_dummy == NULL))  {
			yygenerr("undefined variable '",yytext,"'","");
			return;
		}
		if ( lv_dummy != NULL ) {

/* in procedure with local variable */

			ia_add(PUSHIR,(act_sp - (lv_dummy->addr) + 1));
			if ( s_flag) {
			      as_i_int("pushir",(act_sp -(lv_dummy->addr) + 1));
			}
			act_sp += 1;
			ia_add(PUSHI,lv_dummy->lv_out.var_len);
			if (s_flag) {
			   as_i_int("pushi",lv_dummy->lv_out.var_len);
			}
			act_sp += 1;
		}
		else {

/* in procedure with global variable */

			ia_add(PUSHI,(d_dummy->addr));
			rel_all("D");
			act_sp += 1;
			if (s_flag) {
				as_inst_pr("pushi",yytext);
			}
			ia_add(PUSHI,(d_dummy->d_out.var_len));
			if (s_flag) {
				as_i_int("pushi",(d_dummy->d_out.var_len));
			}
			act_sp += 1;
		}
	}

/* outside procedure body */

	else {
		if (d_dummy == NULL ) {
			yygenerr("undefined variable '",yytext,"'","");
			return;
		}
		ia_add(PUSHI,(d_dummy->addr));
		rel_all("D");
		ia_add(PUSHI,(d_dummy->d_out.var_len));
		if (s_flag) {
			as_inst_pr("pushi",yytext);
		        as_i_int("pushi",(d_dummy->d_out.var_len));
		}
	}
}

/*
 *	Generate code for WRITESTR call
 */


wrcall()
{
	ia_add(CALL,e_wr_str->ecnt);
	rel_all("E");
	ia_add(SP_FREE,2);
	if (in_proc)	act_sp -= 2;
	if (s_flag) {
		as_inst_pr("call","writestr");
		as_inst_pr("spfree","2");
	}
}


/*
 *	Generate code for READSTR call
 */

rdcall()
{
	ia_add(CALL,e_rd_str->ecnt);
	rel_all("E");
	ia_add(SP_FREE,2);
	if (in_proc)	act_sp -= 2;
	if (s_flag) {
		as_inst_pr("call","readstr");
		as_inst_pr("spfree","2");
	}
}
