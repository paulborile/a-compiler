%{

/*
 *	a s c a n . l
 *
 *	scanner for assembler
 */


#include	"y.tab.h"
#include	"extern.h"
int	ill_cnt;
char	label[MAXVAR];
%}

%%

[!@#\$\%\^&~`\|\{\}\\\?']	{ ill_char(); }

[\n]		{ lin_cnt++; } /* ignore also newlines */
[ \t]		; /* blanks and tabs are ignored */
[ \t]*"//".*"\n"	{ lin_cnt++; }

"."		{  return (YDOT) ; }
"end"		{  return (YEND); }
"start"		{  return (YSTART); }
"module"	{  return ( YMODULE ) ; }
"word"		{  return ( YWORD) ; }
"spfree"	{  return ( YSPFREE) ; }
"spalloc"	{  return ( YSPALLOC);	}
"pushir"	{  return ( YPUSHIR ) ; }
"output"	{  return ( YOUTPUT ) ; }
"import"	{  return ( YIMPORT ) ; }
"export"	{  return ( YEXPORT ) ; }

"pushi"		{  return ( YPUSHI ) ; }
"pushr"		{  return ( YPUSHR ) ; }
"push*"		{  return ( YPUSHX ) ; }
"input"		{  return ( YINPUT ) ; }

"push"		{  return ( YPUSH ) ; }
"popr"		{  return ( YPOPR ) ; }
"pop*"		{  return ( YPOPX ) ; }
"call"		{  return ( YCALL ) ; }
"stop"		{  return ( YSTOP ) ; }

"add"		{  return ( YADD ) ; }
"sub"		{  return ( YSUB ) ; }
"mul"		{  return ( YMUL ) ; }
"div"		{  return ( YDIV ) ; }
"cmp"		{  return ( YCMP ) ; }
"nop"		{  return ( YNOP ) ; }
"jmp"		{  return ( YJMP ) ; }
"jeq"		{  return ( YJEQ ) ; }
"jne"		{  return ( YJNE ) ; }
"jlt"		{  return ( YJLT ) ; }
"jle"		{  return ( YJLE ) ; }
"jgt"		{  return ( YJGT ) ; }
"jge"		{  return ( YJGE ) ; }
"ret"		{  return ( YRET ) ; }
"pop"		{  return ( YPOP ) ; }

[a-zA-Z_][_a-zA-Z0-9]*":"	{  return ( YLABYCOLON ) ; }
[a-zA-Z_][_a-zA-Z0-9]*		{	
				strncpy(label,yytext,MAXVAR);
				return ( YLABEL );
				}

[-]*[0-9]+		{  return ( YNUMBER ) ; }
. 		{ ill_char(); }

%%
