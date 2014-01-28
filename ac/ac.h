
/* 
 * Common defines for all elements
 */

#define	  USAGE		"ac : Usage : ac [-lS]  sourcefile(s) \n"
#define	  F_LEN		14
#define   MAXID		20
#define	  MAXVAR	8
#define   MAX_RES	20
#define   LINE		80

/* global variables */

int	fd_out;		/* output file descriptor */
int	fd_cref;	/* output cross reference file descriptor */
FILE	*fp_out;	/* file pointer */
FILE	*fp_ass;	/* file pointer for assembler output file */
FILE	*fp_cref;	/* file pointer for cross reference generation */
FILE	*fp_c;		/* file pointer for "C" language file	*/
int	i,j,k,endtab;
int	yret_code;	/* parser return code */
int	l_list = 0;	/* long listing flag */
int	s_flag = 0;	/* flag for assembler output */
int	c_flag = 0;	/* flag for "C" output	*/
int	oflag = 0; 	/* output flag */
int	lin_cnt = 1;   	 /* Line counter */
int	lin_sav = 0;   	 /* Line counter save */
int	ill_cnt = 0;  	 /* counter for illegal characters  */
int	err_cnt = 0;     /* error counter */
int	fatal = 0;	/* fatal error flag */
char	linebuf[LINE];	 /* line buffer for long listings */
char	yysave[200];	 /* save for yytext  */
char	ifile[F_LEN];	 /* input file name */
char	ofile[F_LEN];    /* output file name for intermediate code */
char	asfile[F_LEN];   /* output file name for assembler */
char	cfile[F_LEN];    /* output file name for "C" language output */
char	cbfile[F_LEN];	 /* temporary file for cb */
