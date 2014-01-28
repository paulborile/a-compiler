/* 
 * Externs for code generation and semantic analisys
 * for variables and arrays
 */


extern	int	is_param,ar_len;
extern	int	d_size;
extern	int	d_cnt;
extern	int	d_first;

extern	int	e_size;
extern	int	e_cnt;
extern	int	e_first;

extern	int	in_proc;
extern	int	act_sp;
extern	char	p_param[];
extern	char	yytext[];
extern	char	tsave[];

extern	struct	dtab	*d_dummy;
extern	struct	etab	*e_dummy;
extern	struct	dtab	*dbase;
extern	struct	etab	*ebase;
extern  struct	lvtab	*lv_dummy;
extern  struct	lvtab	*lvbase;

extern  struct	dtab	*d_search();
extern	struct	etab	*e_search();
extern	struct	lvtab	*lv_search();
