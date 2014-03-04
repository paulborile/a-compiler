/*
 * 	a g r a m . y
 *
 * Assembler syntax
 *
 * Define tokens for instruction names
 */


/* push instructions */

%token	YPUSHI YPUSHIR YPUSH YPUSHR YPOP YPOPR YPUSHX YPOPX

/* aritmetic instructions */

%token	YADD YSUB YMUL YDIV YCMP YNOP

/* jumps */

%token	YJMP YJEQ YJNE YJLT YJLE YJGT YJGE YCALL YRET

/* I/O */

%token	YINPUT YOUTPUT

%token	YWORD YIMPORT YEXPORT
%token	YSTOP YMODULE YEND
%token	YDOT	YSTART YSPFREE YSPALLOC
%token	YLABEL	YNUMBER YLABYCOLON

%{

#include	<stdio.h>
#include 	"extern.h"
#include	"structs.h"
#include	"instcod.h"


extern	struct	dtab	*dbase;
extern	struct	etab	*ebase;
extern	struct	ltab	*lbase;
extern	struct	ultab	*ulbase;
extern	struct	rtab	*rbase;

char	tsave[MAXVAR];
char	pname[MAXVAR];
extern	char	yytext[];
extern	char	label[];
extern	int	yyleng;
extern	int	ill_char;
int	found_start;
int	i,a,b;
%}

%start	unit

%%

unit		:
		head	code	YDOT	YEND
{
	exp_tst();
	fill_p_add();
	s_pass();

#ifdef	TRACE
	d_print(dbase);
	e_print(ebase);
	l_print(lbase);
	ul_print(ulbase);
	r_print(rbase);
	i_print();
#endif	TRACE
}
		;

head		:
		head_dir
		|
		head	head_dir
		;

code		:
		instructions
		|
		code	instructions
		;

head_dir	:
		YDOT	YSTART	YLABEL
{
	strncpy(pname,yytext,MAXVAR);
	found_start = 1;
	upd_magic();
	prog_all();
}
		|
		YDOT	YMODULE	YLABEL
{
	upd_magic();
}
		|
		YDOT	YIMPORT	YLABEL
{
	imp_all();
}
		|
		YDOT	YEXPORT	YLABEL
{
	exp_all();
}
		|
		YLABEL
{
	strncpy(tsave,label,MAXVAR);
}
		YDOT	YWORD	YNUMBER
{
	word_all();
}
		;

instructions	:
		b_opcode
{	i1_add($1);	}
		|
		a_opcode   YLABEL
{
	i1_add($1);
	eval_lab();
}
		|
		a_opcode   YNUMBER
{
	i1_add($1);
	i2_add(atoi(yytext));
}
		|
		YLABYCOLON
{
	strncpy(tsave,yytext,(yyleng - 1));
	tsave[(yyleng - 1)] = '\0';

		lab_all();
}
		;

b_opcode	:
		YPUSHX
{	$$ = PUSH_ ;	}
		|
		YPOPX
{	$$ = POP_ ;	}
		|
		YADD
{	$$ = ADD;	}
		|
		YSUB
{	$$ = SUB;	}
		|
		YMUL
{	$$ = MUL;	}
		|
		YDIV
{	$$ = DIV;	}
		|
		YCMP
{	$$ = CMP;	}
		|
		YRET
{	$$ = RET;	}
		|
		YSTOP
{	$$ = STOP;	}
		|
		error b_opcode
		{
			yyError("Unrecognized instruction");
		}
		;


a_opcode	:

		YPUSHI
{	$$ = PUSHI;	}
		|
		YPUSHIR
{	$$ = PUSHIR;	}
		|
		YPUSH
{	$$ = PUSH;	}
		|
		YPUSHR
{	$$ = PUSHR;	}
		|
		YPOP
{	$$ = POP;	}
		|
		YPOPR
{	$$ = POPR;	}
		|
		YINPUT
{	$$ = INPUT;	}
		|
		YOUTPUT
{	$$ = OUTPUT;	}
		|
		YSPFREE
{	$$ = SP_FREE;	}
		|
		YSPALLOC
{	$$ = SP_ALLOC;	}
		|
		YJMP
{	$$ = JUMP;	}
		|
		YJEQ
{	$$ = JEQ;	}
		|
		YJNE
{	$$ = JNE;	}
		|
		YJLT
{	$$ = JLT;	}	
		|
		YJLE
{	$$ = JLE;	}
		|
		YJGT
{	$$ = JGT;	}
		|
		YJGE
{	$$ = JGE;	}
		|
		YCALL
{	$$ = CALL;	}
		|
		error a_opcode
		{
			yyError("Unrecognized instruction");
		}
		;

%%
