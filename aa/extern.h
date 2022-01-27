
/*
 * Common defines for all elements
 */

#define   USAGE     "ac : Usage : ac [-l] [-o outfile] sourcefile(s) \n"
#define   F_LEN     14
#define   MAXID     20
#define   MAXVAR    8
#define   MAX_RES   20
#define   LINE      80
#define   MAXITAB   5000
#define   YYMAXDEPTH    300
#define   forever   while(1)

/* global variables */

extern int fd_out;
extern FILE *fp_out;
extern int i, j, k, endtab;
extern int yret_code;   /* parser return code */
extern int l_list;      /* long listing flag */
extern int oflag;       /* output flag */
extern int lin_cnt;     /* Line counter */
extern int lin_sav;     /* Line counter save */
extern int ill_cnt;     /* counter for illegal characters  */
extern int err_cnt;     /* error counter */
extern int fatal;       /* fatal error flag */
extern char linebuf[];      /* line buffer for long listings */
extern char yysave[];       /* save for yytext  */
extern char ofile[];        /* output file name */
extern char ifile[];        /* input file name */
