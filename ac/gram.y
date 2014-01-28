/*
 *     g r a m . y   Parser for the "A" language
 */


/*
 * Define tokens  for the reserved words
 */

%token	YARRAY	YBEGIN	YCALL	YDO	YELSE	YEND
%token	YEXPORT	YIF	YIMPORT	YMODULE	YNULL	YPROG
%token	YPROC	YREAD	YR_STR	YTHEN	YVAR	YWHILE
%token	YWRITE	YW_STR

/*
 * Define tokens for special characters
 */

%token	YASSIGN	YEQ	YSEMICOL	YCOMMA	YMINUS
%token	YPLUS	YMULT	YDIV	YLBRA	YRBRA	YDOT	
%token	YLES_EQ	YGRE_EQ	YLESS	YGREAT	YNOTEQ	YSLBRA
%token	YSRBRA

/* 
 * Define precedence
 */

%left	YPLUS	YMINUS
%left	YMULT	YDIV

/*
 * Define tokens for types
 */

%token	YNUMBER	YSTRING	VNAME	

%{
#include	<stdio.h>
#include	<string.h>
#include 	"extern.h"
#include	"structs.h"
#include	"instcod.h"

/* working variables for dtab */

extern	int	d_size;
extern	int	d_cnt;
extern	int	d_first;
extern	struct	dtab	*dbase;
extern	struct	dtab	*done;
extern	struct	dtab	*dtwo;
struct	dtab	*d_dummy;
struct	dtab	*d_init(),*d_add(),*d_search();

/* working variables for etab */

extern	int	e_size;
extern	int	e_cnt;
extern	int	e_first;
extern	struct	etab	*ebase;
extern	struct	etab	*eone;
extern	struct	etab	*etwo;
struct	etab	*e_dummy;
struct	etab	*e_init(),*e_add(),*e_search();
struct	etab	*e_read,*e_write,*e_rd_str,*e_wr_str;

/* working variables for rtab */

extern	int	r_size;
extern	int	r_first;
extern	struct	rtab	*rbase;
extern	struct	rtab	*rone;
extern	struct	rtab	*rtwo;
struct	rtab	*r_init(),*r_add();

/* working variables for itab */

extern	int	i_size;
extern	int	i_cnt;

/* define externs for lvtab */

extern	int	lv_size;
extern	int	lv_cnt;
extern	int	lv_first;
extern	struct	lvtab	*lvbase;
extern	struct	lvtab	*lvone;
extern	struct	lvtab	*lvtwo;
extern	struct	lvtab	*lv_init(),*lv_add(),*lv_search();

/* for -S option only */

extern	char	*as_make_label();


int	l_cnt = 100;

struct	lvtab	*lv_dummy;

char	tsave[MAXVAR];
char	pname[MAXVAR];
char	p_param[MAXVAR];
char	procname[MAXVAR];
extern	char	yytext[];
int	a,b;
int	in_proc,act_sp;
int	is_param,ar_len;
int	io_in = 0;
int	n_tabs = 0;
%}

%start	unit

%%

unit 	:	YPROG	prog_head decl block YDOT
{
				if (!l_list) {
					printf("Program Compilation completed.");
					printf("Total errors = %d\n",err_cnt+ill_cnt);
				}
#ifdef TRACE
				d_print(dbase);
				e_print(ebase);
				lv_print(lvbase);
				r_print(rbase);
				printf("Dtab size= %d Etab size = %d\n",d_size,e_size);
				printf("Rtab size= %d Itab size = %d\n",r_size,i_size);
#endif
}
		|
		YMODULE	mod_head decl
{
	exp_tst();
}
		YNULL YDOT
		{
			if (!l_list) {
				printf("Module Compilation completed.");
				printf("Total errors = %d\n",err_cnt+ill_cnt);
			}
#ifdef TRACE
			d_print(dbase);
			e_print(ebase);
			printf("Dtab size = %d Etab size = %d\n",d_size,e_size);
#endif
		}
		|
		error	YSEMICOL
		{
			yyError("Invalid Starting line ");
		}
		;

prog_head	:
		VNAME
{
		strncpy(pname,yytext,MAXVAR);
		upd_magic();
		prog_all();
		if (s_flag) {
			as_inst_pr(".start",pname);
			as_line_pr();
		/*
			Always add to assembly printout the standard I/O imports
		*/
			as_inst_pr(".import","read");
			as_inst_pr(".import","write");
			as_inst_pr(".import","readstr");
			as_inst_pr(".import","writestr");
		}
		if (!fatal && c_flag) {
			c_put("#include <stdio.h>\n\n");
			c_put("/*\n");
			c_put(" * 'C' translation of 'A' program named ");
			c_put(yytext);
			c_put_nl();
			c_put(" */\n\n");
		}
		if (l_list)  put_ref(pname,"D");
}
		YSEMICOL
		|
		error	VNAME	YSEMICOL
		{
			yyError("Malformed PROGRAM statement");
		}
		;
mod_head	:
		VNAME
{
		upd_magic();
		if (s_flag) {
			as_inst_pr(".module",yytext);
			as_line_pr();
		/*
			Always add to assembly printout the standard I/O imports
		*/
			as_inst_pr(".import","read");
			as_inst_pr(".import","write");
			as_inst_pr(".import","readstr");
			as_inst_pr(".import","writestr");
		}
		if (l_list) put_ref(yytext,"D");
}
		YSEMICOL
		|
		error	VNAME	YSEMICOL
		{
			yyError("Malformed MODULE statement");
		}
		;
decl	:	/* empty */
		|
		YIMPORT	 Im_dec YSEMICOL decl
		|
		YEXPORT	 Ex_dec YSEMICOL decl	
		|
		YVAR	 Var_dec   YSEMICOL
{
		if (!fatal && c_flag) {
			c_put(";");
			c_put_nl();
		}
}
		decl	
		|
		YARRAY	Ar_dec YSEMICOL
{
		if (!fatal && c_flag) {
			c_put(";");
			c_put_nl();
		}
}
		decl	
		|
		YPROC	p_head  p_decl  p_block YSEMICOL decl
		|
		error
		{
			yyError("Malformed DECLARATIONS");
		}
		;

/*
 * Import declaration section
 */


Im_dec	:	VNAME
{
		if (!fatal) imp_all();
		if (!fatal && s_flag) {
			as_inst_pr(".import",yytext);
		}
		if (l_list) put_ref(yytext,"D");
}
		|

		Im_dec	YCOMMA	VNAME 
{
		if (!fatal) imp_all();
		if (!fatal && s_flag) {
			as_inst_pr(".import",yytext);
		}
		if (l_list) put_ref(yytext,"D");
}
		|

		error
		{
			yyError("Malformed IMPORT declaration");
		}
		;

/*
 * Export declaration section
 */

Ex_dec	:	VNAME
{
		if (!fatal) exp_all();
		if (!fatal && s_flag) {
			as_inst_pr(".export",yytext);
		}
		if (l_list) put_ref(yytext,"D");
}
		|

		Ex_dec	YCOMMA	VNAME
{
		if (!fatal) exp_all();
		if (!fatal && s_flag) {
			as_inst_pr(".export",yytext);
		}
		if (l_list) put_ref(yytext,"D");
}
		|

		error
		{
			yyError("Malformed EXPORT declaration");
		}
		;

/*
 * Var declaration section
 */

Var_dec	:	VNAME
{
		if (!fatal) var_all();
		if (!fatal && s_flag ) {
			as_stat(yytext,".word","1");
		}
		if (!fatal && c_flag) {
			c_put("int");
			c_put_tab(1);
			c_put(yytext);
		}
		if (l_list) put_ref(yytext,"D");
}
		|

		Var_dec	YCOMMA	VNAME
{
		if (!fatal) var_all();
		if (!fatal && c_flag) {
			c_put(", ");
			c_put(yytext);
		}
		if (!fatal && s_flag ) {
			as_stat(yytext,".word","1");
		}
		if (l_list) put_ref(yytext,"D");
}
		|

		error
		{
			yyError("Malformed VAR declaration");
		}
		;
/*
 *  Array declaration section
 */

Ar_dec	:	VNAME

{
		if (!fatal) strncpy(tsave,yytext,MAXVAR);
		if (l_list) put_ref(yytext,"D");
		if (!fatal && c_flag) {
			c_put("int");
			c_put_tab(1);
			c_put(yytext);
		}
}
		YSLBRA	YNUMBER	
{
		if (!fatal) array_all();
		if (!fatal && s_flag ) {
			as_stat(tsave,".word",yytext);
		}
		if (!fatal && c_flag) {
			c_put("[");
			c_put(yytext);
			c_put("]");
		}
}
		YSRBRA

		|
		Ar_dec	YCOMMA  VNAME
{
		if (!fatal) strncpy(tsave,yytext,MAXVAR);
		if (l_list) put_ref(yytext,"D");
		if (!fatal && c_flag) {
			c_put(", ");
			c_put(yytext);
		}
}
		YSLBRA	YNUMBER	
{
		if (!fatal) array_all();
		if (!fatal && s_flag ) {
			as_stat(tsave,".word",yytext);
		}
		if (!fatal && c_flag) {
			c_put("[");
			c_put(yytext);
			c_put("]");
		}
}
		YSRBRA
		|
		error
		{
			yyError("Malformed ARRAY declaration");
		}
		;
p_head		:
		VNAME
{
if (!fatal)
	{
		strncpy(procname,yytext,MAXVAR);
		if (l_list) put_ref(procname,"D");
		proc_all();
		if ( s_flag ) {
			as_line_pr();
			as_label_pr(yytext);
		}
	}
}
		YLBRA	VNAME
{
	if (!fatal )	strncpy(p_param,yytext,MAXVAR);
}
	
		YRBRA

		YSEMICOL

		|
		error
		{
			yyError("Malformed PROCEDURE head");
		}
		;

p_decl	:	/* empty */
		|
		YVAR	p_Var_dec    YSEMICOL	p_decl
		|
		YARRAY	p_Arr_dec  YSEMICOL   p_decl
		;

p_Var_dec :	VNAME

{
		if (!fatal) {
			lvar_all();
			ia_add(SP_ALLOC,1);
			act_sp += 1;
			if (s_flag) {
				as_inst_pr("spalloc","1");
			}
		}
}
		|
		p_Var_dec	YCOMMA VNAME
{
		if (!fatal) {
			lvar_all();
			ia_add(SP_ALLOC,1);
			act_sp += 1;
			if (s_flag) {
				as_inst_pr("spalloc","1");
			}
		}
}
		|
		error
		{
			yyError("Malformed VAR declaration in PROCEDURE");
		}
		;
p_Arr_dec :	VNAME
{
		if (!fatal) strncpy(tsave,yytext,MAXVAR);
}
		YSLBRA	YNUMBER
{
if (!fatal) 
	{
		larr_all();
		ia_add(SP_ALLOC,atoi(yytext));
		act_sp += atoi(yytext);
		if (s_flag) {
			as_inst_pr("spalloc",yytext);
		}
	}
}
		YSRBRA
		|
		p_Arr_dec	YCOMMA  VNAME
{
		if (!fatal) strncpy(tsave,yytext,MAXVAR);
}
		YSLBRA	YNUMBER
{
if (!fatal) 
	{
		larr_all();
		ia_add(SP_ALLOC,atoi(yytext));
		act_sp += atoi(yytext);
		if (s_flag) {
			as_inst_pr("spalloc",yytext);
		}
	}
}
		YSRBRA
		|
		error
		{
			yyError("Malformed ARRAY declaration in PROCEDURE");
		}
		;

p_block:	YBEGIN

{ if (!fatal) in_proc = 1; }

		stat_list YEND
{
if (!fatal)
	{
		if ( lv_size != 0 ) {
			ia_add(SP_FREE,lvtwo->addr);
			if (s_flag) {
				as_i_int("spfree",lvtwo->addr);
			}
			act_sp-=lvtwo->addr;
			lv_free(lvbase);
			lv_size = 0;
			lv_first = 1;
		}
		ib_add(RET);
		in_proc = 0;
		if (s_flag) {
			as_inst_pr("ret","");
		}
	}
}
		|
		error
		{
			yyError("Proc block : Syntax Error");
		}
		;

/*
 * Block of program 
 */

block	:	YBEGIN 

{
	/* test to find unresolved exports */

	exp_tst();

	if (!fatal) {
	/* fill program entry with correct address */
 		fill_p_add();
		if (s_flag) {
			as_line_pr();
			as_label_pr(pname);
		}
		if (c_flag) {
			n_tabs++;	/* tab level for c generation */
			c_put("\nmain()\n");
			c_put("{\n");
		}
	}
}

		stat_list YEND
{
if (!fatal)
	{
		/* Add stop instruction at end of program */

		ib_add(STOP);
		if (s_flag) {
			as_inst_pr("stop","");
			as_inst_pr(".end","");
		}
		if (!fatal && c_flag) {
			c_put("}\n");
		}
	}
}
		|
		error
		{
			yyError("Syntax Error");
		}
		;

stat_list	: stat
		|
		stat  stat_list 
		;
stat	:
		YNULL YSEMICOL
{
	if (!fatal && c_flag) {
		c_put(";\n");
	}
}
		|
		assign YSEMICOL
{
	if (!fatal && c_flag) {
		c_put(";\n");
	}
}
		|
		YCALL	VNAME
{
		if (!fatal) {
			strncpy(tsave,yytext,MAXVAR);
			if (c_flag) {
				c_put(yytext);
				c_put(" ( ");
			}
		}
		if (l_list) put_ref(tsave,"U");
}
		YLBRA var_ref
{
/*
 *    CALL PROCEDURE
 */

		if (!fatal)  call();

}
		YRBRA YSEMICOL
{
	if (!fatal && c_flag) {
		c_put(" );\n");
	}
}

		|
		YREAD

{
	if (!fatal)
		io_all();
	if (l_list)	 put_ref("read","U");
	if (!fatal && c_flag) {
		c_put("scanf(\"\%d\\n\", ");
	}
}

		YLBRA var_ref
{
if (!fatal)
	{
		strcpy(tsave,"read");
		call();
	}
}
		YRBRA YSEMICOL
{
	if (!fatal && c_flag) {
		c_put(");\n");
	}
}
		|
		YR_STR

{
	if (!fatal)	io_all();
	if (l_list)	put_ref("readstr","U");
}

		YLBRA VNAME
{
if (!fatal)
	{
		ident();
		rdcall();
		if (c_flag) {
			yyError("Unable to create C code for this statement");
/*
			c_put_tab(n_tabs);
			c_put("gets ( ");
			c_put("(char *)&");
			c_put(yytext);
			c_put("[0]");
			c_put(" );\n");
*/
		}
	}
}
		YRBRA YSEMICOL
		|
		YWRITE

{
	if (!fatal) {
		io_all();
		if (c_flag) {
			c_put("printf(\"\%d\\n\", ");
		}
	}
	if (l_list) 	put_ref("write","U");
}

		YLBRA var_ref
{
if (!fatal)
	{
		strcpy(tsave,"write");
		call();
	}
}
		YRBRA YSEMICOL
{
	if (!fatal && c_flag) {
		c_put(");\n");
	}
}
		|
		YW_STR

{
	if (!fatal) {
		io_all();
		if (c_flag) {
			yyError("Unable to create C code for this statement");
/*
			c_put_tab(n_tabs);
			c_put("puts (");
*/
		}
	}
	if (l_list)	put_ref("writestr","U");
}

		YLBRA iden YRBRA YSEMICOL
{
	if (!fatal && c_flag) {
		c_put(");\n");
	}
}

		|

		YIF
{
	if (!fatal && c_flag) {
		c_put("if ( ");
	}
}
		cond_stat
{
		if (!fatal) i_push(i_cnt-1);
}
		YTHEN
{
	if (!fatal && c_flag ) {
		c_put(" ) ");
	}
}
		stat
{
if (!fatal)
	{
		ia_add(JUMP,0);
		rel_all("J");
		if (s_flag) {
			l_push(l_cnt);
			as_inst_pr("jmp",as_make_label(l_cnt));
			l_cnt++;
		}
	}
}
		YELSE
{
if (!fatal) 
	{
		if (s_flag) {
			as_label_pr(as_make_label(l_prev()));
		}
		if (c_flag) {
			c_put("else");
		}
		itab[i_pop()] = i_cnt;
		i_push(i_cnt-1);
	}
}
		stat
{
if (!fatal)
	{
		if (s_flag) {
			as_label_pr(as_make_label(l_pop()));
			l_pop();
		}
		if (c_flag) {
			n_tabs--;
		}
		itab[i_pop()] = i_cnt;
	}
}
		|
		YWHILE
{
if (!fatal)
	{
	/* save this address push(i_cnt) */
		i_push(i_cnt);
		if (s_flag) {
			l_push(l_cnt);
			as_label_pr(as_make_label(l_cnt));
			l_cnt++;
		}
		if (c_flag) {
			c_put("while ( ");
		}
	}
}
		cond_stat
{
	/* push address of jmp to be filled */

		if (!fatal) i_push(i_cnt-1);
}
		YDO
{
	if (!fatal && c_flag) {
		c_put(" ) ");
	}
}
		stat
{
if (!fatal)
	{
	/* fill address  ( pop )  ,*/

		itab[i_pop()] = i_cnt+2;

	/*	jump back to (pop) */

		ia_add(JUMP,i_pop());
		rel_all("J");
		if (s_flag) {
			as_inst_pr("jmp",as_make_label(l_prev()));
			as_label_pr(as_make_label(l_pop()));
			l_pop();
		}
	}
}
		|
		YBEGIN
{
	if (!fatal && c_flag) {
		c_put("{\n");
		n_tabs++;
	}
}
		stat_list
		YEND
{
	if (!fatal && c_flag) {
		n_tabs--;
		c_put("}\n");
	}
}
		YSEMICOL
		|
		error YSEMICOL
		{
			yyError("Malformed STATEMENT");
		}
		;
		
iden		:
		YSTRING
{
if (!fatal)
	{
		string();
		if (c_flag) {
			c_put("\"");
			c_put(yytext);
			c_put("\"");
		}
	}
}
		|
		VNAME
{
if (!fatal) 
	{
		if (l_list)	put_ref(yytext,"U");
		ident();
		wrcall();
		if (c_flag) {
			c_put("(char *)&");
			c_put(yytext);
			c_put("[0]");
		}
	}
}
		;

cond_stat	:
		YLBRA
{
	if (!fatal && c_flag) {
		c_put("(");
	}
}
		cond_stat
		YRBRA
{
	if (!fatal && c_flag) {
		c_put(")");
	}
}
		|
		expr
		YEQ
{
	if (!fatal && c_flag) {
		c_put(" == ");
	}
}
		expr
{
if (!fatal)
	{
		ib_add(CMP);
		if (in_proc) act_sp -= 2;
		if (s_flag) {
			as_inst_pr("cmp","");
			l_push(l_cnt);
			as_inst_pr("jne",as_make_label(l_cnt));
			l_cnt++;
		}
		ia_add(JNE,0);
		rel_all("J");
	}
}
		|
		expr
		YNOTEQ
{
	if (!fatal && c_flag) {
		c_put(" != ");
	}
}
		expr
{
if (!fatal)
	{
		ib_add(CMP);
		if (in_proc) act_sp -= 2;
		if (s_flag) {
			as_inst_pr("cmp","");
			l_push(l_cnt);
			as_inst_pr("jeq",as_make_label(l_cnt));
			l_cnt++;
		}
		ia_add(JEQ,0);
		rel_all("J");
	}
}
		|
		expr
		YLESS
{
	if (!fatal && c_flag) {
		c_put(" < ");
	}
}
		expr
{
if (!fatal)
	{
		ib_add(CMP);
		if (in_proc) act_sp -= 2;
		if (s_flag) {
			as_inst_pr("cmp","");
			l_push(l_cnt);
			as_inst_pr("jge",as_make_label(l_cnt));
			l_cnt++;
		}
		ia_add(JGE,0);
		rel_all("J");
	}
}
		|
		expr
		YGREAT
{
	if (!fatal && c_flag) {
		c_put(" > ");
	}
}
		expr
{
if (!fatal)
	{
		ib_add(CMP);
		if (in_proc) act_sp -= 2;
		if (s_flag) {
			as_inst_pr("cmp","");
			l_push(l_cnt);
			as_inst_pr("jle",as_make_label(l_cnt));
			l_cnt++;
		}
		ia_add(JLE,0);
		rel_all("J");
	}
}
		|
		expr
		YLES_EQ
{
	if (!fatal && c_flag) {
		c_put(" <= ");
	}
}
		expr
{
if (!fatal)
	{
		ib_add(CMP);
		if (in_proc) act_sp -= 2;
		if (s_flag) {
			as_inst_pr("cmp","");
			l_push(l_cnt);
			as_inst_pr("jgt",as_make_label(l_cnt));
			l_cnt++;
		}
		ia_add(JGT,0);
		rel_all("J");
	}
}
		|
		expr
		YGRE_EQ
{
	if (!fatal && c_flag) {
		c_put(" >= ");
	}
}
		expr
{
if (!fatal)
	{
		ib_add(CMP);
		if (in_proc) act_sp -= 2;
		if (s_flag) {
			as_inst_pr("cmp","");
			l_push(l_cnt);
			as_inst_pr("jlt",as_make_label(l_cnt));
			l_cnt++;
		}
		ia_add(JLT,0);
		rel_all("J");
	}
}
		|
		error
		{
			yyError("Wrong logical operator");
		}
		;

assign		:
		var_ref YASSIGN	
{
	if (!fatal && c_flag) {
		c_put(" = ");
	}
}
		expr  
{
if (!fatal)
	{
		ib_add(POP_);
		if (in_proc) act_sp -= 2;
		if (s_flag) {
			as_inst_pr("pop*","");
		}
	}
}
		;

expr	:	YLBRA
{
	if (!fatal && c_flag) {
		c_put("(");
	}
}
		expr YRBRA
{
	if (!fatal && c_flag) {
		c_put(")");
	}
}
		|
		expr	YPLUS
{
	if (!fatal && c_flag) {
		c_put(" + ");
	}
}
		expr
{
if (!fatal)
	{
		if (in_proc) act_sp -= 1;
		ib_add(ADD);
		if (s_flag) {
			as_inst_pr("add","");
		}
	}
}
		|
		expr	 YMINUS	
{
	if (!fatal && c_flag) {
		c_put(" - ");
	}
}
		expr
{
if (!fatal) 
	{
		if (in_proc) act_sp -= 1;
		ib_add(SUB);
		if (s_flag) {
			as_inst_pr("sub","");
		}
	}
}
		|
		expr	YMULT
{
	if (!fatal && c_flag) {
		c_put(" * ");
	}
}
		expr
{
if (!fatal)
	{
		if (in_proc) act_sp -= 1;
		ib_add(MUL);
		if (s_flag) {
			as_inst_pr("mul","");
		}
	}
}
		|
		expr	YDIV	
{
	if (!fatal && c_flag) {
		c_put(" / ");
	}
}
		expr
{
if (!fatal)
	{
		if (in_proc) act_sp -= 1;
		ib_add(DIV);
		if (s_flag) {
			as_inst_pr("div","");
		}
	}
}
		|
		YNUMBER
{
if (!fatal)
	{
		if (in_proc) act_sp += 1;
		ia_add(PUSHI,atoi(yytext));
		if (s_flag) {
			as_inst_pr("pushi",yytext);
		}
		if (c_flag) {
			c_put(yytext);
		}
	}
}
		|
		variable
		;
 
variable	:
		VNAME
{
/*
 *     VAR VALUE
*/

		if (!fatal) {
			vval();
			if (c_flag) {
				c_put(yysave);
			}
		}
}
		|
		VNAME
{
/*
 *      ARRAY VALUE
*/

		if (!fatal) {
			aval();
			if (c_flag) {
				c_put(yysave);
				c_put("[");
			}
		}

}
		YSLBRA expr YSRBRA
{
if (!fatal)
	{
		ib_add(ADD);
	    	if (in_proc )  act_sp -= 1;
		ib_add(PUSH_);
		if (s_flag) {
			as_inst_pr("add","");
			as_inst_pr("push*","");
		}
		if (c_flag) {
			c_put("]");
		}
	}
}
		;

var_ref	:
		VNAME
{
/* 
 *        VAR REFERENCE
*/
		if (!fatal) {
			vref();
			if (c_flag) {
				c_put(yysave);
			}
		}
}
		|
		VNAME
{
/*
 *    ARRAY REFERENCE
*/
		if (!fatal) {
			aref();
			if (c_flag) {
				c_put(yysave);
			}
		}

}
		YSLBRA
{
	if (!fatal && c_flag) {
		c_put("[");
	}
}
		expr
		YSRBRA
{
if (!fatal)
	{
		ib_add(ADD);
		if (in_proc) act_sp -= 1;
		if (s_flag) {
			as_inst_pr("add","");
		}
		if (c_flag) {
			c_put("]");
		}
	}
}
		;
%% 	/* end of rules section */
