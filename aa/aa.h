
/* 
 * Common defines for all elements
 */

#define	  USAGE		"aa : Usage : aa [-l] [-o outfile] sourcefile(s) \n"
#define	  F_LEN		14
#define   MAXID		20
#define	  MAXVAR	8
#define   MAX_RES	20
#define   LINE		80

/* global variables */

int	fd_out;		/* output file descriptor */
FILE	*fp_out;	/* file pointer */
int	i,j,k,endtab;
int	yret_code;	/* parser return code */
int	l_list = 0;	/* long listing flag */
int	oflag = 0; 	/* output flag */
int	lin_cnt = 1;   	 /* Line counter */
int	lin_sav = 0;   	 /* Line counter save */
int	ill_cnt = 0;  	 /* counter for illegal characters  */
int	err_cnt = 0;     /* error counter */
int	fatal = 0;	/* fatal error flag */
char	linebuf[LINE];	 /* line buffer for long listings */
char	yysave[200];	 /* save for yytext  */
char	ofile[F_LEN];	 /* output file */
char	ifile[F_LEN];	 /* input file name */
