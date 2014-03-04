/*
 * BEGIN MODULE NEWINSTERR
 */

#include	<stdio.h>
#include	"error.h"

extern int pc, sp, flag;
extern unsigned ri;
extern unsigned memory[];
extern char *mnem[];

errinst(inst, messg)
register char *inst;
register char *messg;
{
	printf("%s\n", messg);
	printf("%s %s\n", MSG_INST, inst);
	printf("%s %d\t\t%s %d\n", MSG_PC, pc, MSG_SP, sp);
	printf("%s %s\t%s %o\n", MSG_RI, mnem[ri], MSG_FL, flag);
	return (ERROR_FUNCT);
}

out_of_memory(inst, pointer)
register char *inst;
register int pointer;
{
	printf("%s\n", MSG_OUT_MEM);
	printf("%s %u", MSG_POI, pointer);
	printf("%s %s\n", MSG_INST, inst);
	printf("%s %d\t\t%s %d\n", MSG_PC, pc, MSG_SP, sp);
	printf("%s %s\t%s %o\n", MSG_RI, mnem[ri], MSG_FL, flag);
	return (ERROR_FUNCT);
}

ufo(inst, top)
register unsigned inst;
register int top;
{
	printf("%s\n", MSG_NOT_INST);
	printf("%s %d\n", MSG_COD_INST, inst);
	printf("%s %d\t\t%s %d\n", MSG_PC, pc, MSG_SP, sp);
	printf("%s %d\t%s %o\n", CODE_RI, ri, MSG_FL, flag);
	return (ERROR_FUNCT);
}

#ifdef	DEBUG
inst_trace(inst, top)
unsigned inst;
int top;
{
	printf("***INSTR*********PC**************SP*******M[SP]*****FL**\n");
	printf("  %s(%d)	%-4d		%-4d	%-10d    %01o\n",
		   mnem[ri], ri, pc, sp, memory[sp], flag);
}
#endif	/* DEBUG */

/*
 * END MODULE NEWINSTERR
 */
