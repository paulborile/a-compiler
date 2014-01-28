%{

/*
 *  s c a n . l   -  source file for "A" language lexical analizer
*/

/*
 * Include parser definitions
 */

#include	<stdio.h>
#include	<ctype.h>
#include	"y.tab.h"
#include	"extern.h"



static	struct	tok_tab {
		char	tok_name[MAXID];
		int	ytoke;
		} token_tab[MAX_RES] = {
/*
 *      Tok_name		ytoke
*/
	"ARRAY",		YARRAY,	
	"BEGIN",		YBEGIN,
	"CALL",			YCALL,
	"DO",			YDO,
	"ELSE",			YELSE,
	"END",			YEND,
	"EXPORT",		YEXPORT,
	"IF",			YIF,
	"IMPORT",		YIMPORT,
	"MODULE",		YMODULE,
	"NULL",			YNULL,
	"PROCEDURE",		YPROC,
	"PROGRAM",		YPROG,
	"READ",			YREAD,
	"READSTR",		YR_STR,
	"THEN",			YTHEN,
	"VAR",			YVAR,
	"WHILE",		YWHILE,
	"WRITE",		YWRITE,
	"WRITESTR",		YW_STR
	};

extern	int	yylval;
char	yysave1[200];
%}

%%

[!@#\$\%\^&~`\|\{\}\\\?']	{ 
				ill_char();
				upd_line();
				}
[\n]			{
			lin_cnt++;	 /* increment line counter */
				/* long listing option */
				if(l_list) {
					printf("%4.0d\t%s\n",lin_cnt-1,linebuf);
					linebuf[0] = '\0';
				}
			}
[ \t]			{ /* blanks newlines and tabs are ignored */
				upd_line();
			}

"/*".*"\n"		{
				lin_cnt++;
				upd_line();
				if(l_list) {
					printf("%4.0d\t%s",lin_cnt-1,linebuf);
					linebuf[0] = '\0';
				}
			}   /* skip comment lines  */

":="			{ 
			upd_line();
			return(YASSIGN); 
			}
"="			{ 
			upd_line();
			return(YEQ); 
			}

";"			{ 
			upd_line();
			lin_sav--; 	/* In order to have errors again */
			return(YSEMICOL); 
			}

","			{ 
			upd_line();
			return(YCOMMA); 
			}

"-"			{ 
			upd_line();
			return(YMINUS); 
			}

"+"			{ 
			upd_line();
			return(YPLUS); 
			}

"*"			{ 
			upd_line();
			return(YMULT); 
			}

"/"			{ 
			upd_line();
			return(YDIV); 
			}

"("			{ 
			upd_line();
			return(YLBRA); 
			}

")"			{ 
			upd_line();
			return(YRBRA); 
			}

"."			{ 
			upd_line();
			return(YDOT); 
			}

"<>"			{ 
			upd_line();
			return(YNOTEQ); 
			}

"<="			{ 
			upd_line();
			return(YLES_EQ); 
			}

">="			{ 
			upd_line();
			return(YGRE_EQ); 
			}

"<"			{ 
			upd_line();
			return(YLESS); 
			}

">"			{ 
			upd_line();
			return(YGREAT); 
			}

"["			{ 
			upd_line();
			return(YSLBRA); 
			}

"]"			{ 
			upd_line();
			return(YSRBRA); 
			}

[0-9]+			{ 
			upd_line();
			yylval = atoi(yytext);
			return(YNUMBER); 
			}

["][^\"\n]*["]		{ 
			upd_line();
			return(ret_str()); 
			}

["]			{ 
			upd_line();
			ill_char(); 
			}

[_A-Za-z][_A-Za-z0-9]*	{


/* 
 * make binary search to find reserved words
*/

		upd_line(); 

		endtab = MAX_RES;

		strcpy(yysave1,yysave);
		strcpy(yysave,yytext);

		for(i = 0; i< yyleng; i++) {
			yytext[i] = toupper(yytext[i]);
		}

		i = 0;
		while(i <= endtab) {
			k = (i+endtab)/2;
			if(( j = strcmp(yytext,token_tab[k].tok_name)) > 0 )
				i = k + 1;
			else {
				if(j < 0) endtab = k -1;
				else {
					strcpy(yysave,yysave1);
					return(token_tab[k].ytoke);
				}
			}
		}
		strcpy(yytext,yysave);
		return(VNAME);
	} /* end of binary search for reserved words  */
%%

/*
 * Supplied subroutines to help YACC
 */

/*
 * Return string inside double quotes
 */

ret_str()
{
	int	y;

	for(y=0; y < yyleng - 1; y++ ) {
		yytext[y] = yytext[y+1];
	}
	yytext[yyleng-2] = '\0';
	yyleng -= 2;
	return(YSTRING);
}

/* 
 * Update line buffer whith all tokens
 */

upd_line()
{
	if (!l_list) return;
	strcat(linebuf,yytext);
}
