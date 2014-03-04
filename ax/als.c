/*
 * START ARITMETIC LOGIC MODULE 
 */

#include	"error.h"
#include	"vmacdef.h"

extern int errinst();

extern unsigned memory[];
extern int pc, sp, flag, max_sp;
extern unsigned ri;

add(inst, top)
register unsigned inst;
register int top;
{
	if (++sp >= max_sp)
		return (errinst("ADD", MSG_UND));
	else
	{
		memory[sp] = ((int) memory[sp] + (int) memory[sp - 1]);
		return (!ERROR_FUNCT);
	}
}

sub(inst, top)
register unsigned inst;
register int top;
{
	if (++sp >= max_sp)
		return (errinst("SUB", MSG_UND));
	else
	{
		memory[sp] = (int) memory[sp] - (int) memory[sp - 1];
		return (!ERROR_FUNCT);
	}
}

mul(inst, top)
register unsigned inst;
register int top;
{
	register long res;

	if (++sp >= max_sp)
		return (errinst("MUL", MSG_UND));
	else
	{
		res = (long) memory[sp] * (long) memory[sp - 1];
		memory[sp] = (int) res;
/*		if ((long)((int)res)!=res)
			return(errinst("MUL",ARIT_OVER)); 
		else */ return (!ERROR_FUNCT);
	}
}

div(inst, top)
register unsigned inst;
register int top;
{
	if (++sp >= max_sp)
		return (errinst("DIV", MSG_UND));
	else if ((int) memory[sp - 1] == 0)
		return (errinst("DIV", DIV_BY_ZERO));
	else
	{
		memory[sp] = (int) memory[sp] / (int) memory[sp - 1];
		return (!ERROR_FUNCT);
	}
}

cmp(inst, top)
register unsigned inst;
register int top;
{
	int a, b;
	if ((sp += 2) > max_sp)
		return (errinst("CMP", MSG_UND));
	else
	{
		if (((int) memory[sp - 1]) == ((int) memory[sp - 2]))
			flag = EQ_MASK;
		else if (((int) memory[sp - 1]) > ((int) memory[sp - 2]))
			flag = GR_MASK;
		else
			flag = LE_MASK;
		return (!ERROR_FUNCT);
	}
}

nop(inst, top)
unsigned inst;
int top;
{
	return (!ERROR_FUNCT);
}

/*
 * END ARITMETIC LOGIC MODULE
 */
