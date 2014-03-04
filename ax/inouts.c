/*
 * STACK MODULE
 */

#include <stdio.h>
#include "error.h"
#include "vmacdef.h"

extern errinst(), out_of_memory();

extern unsigned memory[];
extern int pc, sp, flag;
extern unsigned ri;


input(inst, top)
register unsigned inst;
register int top;
{
	unsigned cloc;

	if (next(top, &cloc) == ERROR_FUNCT)
		return (errinst("INPUT", MSG_PC_ERR));
	else if (cloc >= MEM_DIM)
		return (out_of_memory("INPUT", cloc));
	else
	{
		memory[cloc] = 0377 & getchar();
		return (!ERROR_FUNCT);
	}
}

output(inst, top)
register unsigned inst;
register int top;
{
	unsigned cloc;

	if (next(top, &cloc) == ERROR_FUNCT)
		return (errinst("INPUT", MSG_PC_ERR));
	else if (cloc >= MEM_DIM)
		return (out_of_memory("INPUT", cloc));
	else
	{
		putchar(0377 & memory[cloc]);
		fflush(stdout);
		return (!ERROR_FUNCT);
	}
}

/*
 * END INOUTS MODULE
 */
