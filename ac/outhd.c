/*
 *     o u t h d . c
 * 
 * Create header for .o file
 */

#include <stdio.h>
#include "extern.h"
#include "outhd.h"

extern	char	yytext[];
struct	head	*ptr;

upd_magic()
{
	magic.mag = 'a';
	strncpy(magic.label,yytext,MAXVAR);
}

/*
 * Put header on file
 */

put_hd()
{
	write(fd_out, &magic, (sizeof (struct head)));
}
