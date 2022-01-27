/*
 * STACK MODULE
 */

#include "error.h"
#include "vmacdef.h"

extern int errinst();

extern unsigned memory[];
extern int pc, sp, flag, max_sp;

static char *cod_table[] = {
    "JEQ", "JLT", "JLE",
    "JGT", "JGE", "JNE", "JUMP"
};

jmp(inst, top)
register unsigned inst;
register int top;
{
    unsigned next_ad;
    if (next(top, &next_ad) == ERROR_FUNCT)
        return (errinst(cod_table[inst - 17], MSG_PC_ERR));
    else if (next_ad >= top)
        return (errinst(cod_table[inst - 17], MSG_PC_ERR));
    else
    {
        if ((inst & flag) != 0)
            pc = next_ad;
        return (!ERROR_FUNCT);
    }
}

call(inst, top)
register unsigned inst;
register int top;
{
    unsigned next_ad;
    if (next(top, &next_ad) == ERROR_FUNCT)
        return (errinst("CALL", MSG_PC_ERR));
    else if (--sp <= top)
        return (errinst("CALL", MSG_OVR));
    else
    {
        memory[sp] = pc;
        if (next_ad >= top)
            return (errinst("CALL", MSG_PC_ERR));
        else
        {
            pc = next_ad;
            return (!ERROR_FUNCT);
        }
    }
}

ret(inst, top)
register unsigned inst;
register int top;
{
    unsigned next_ad;
    if (++sp > max_sp)
        return (errinst("RET", MSG_UND));
    else if ((next_ad = memory[sp - 1]) >= top)
        return (errinst("RET", MSG_PC_ERR));
    else
    {
        pc = next_ad;
        return (!ERROR_FUNCT);
    }
}

stop(inst, top)
unsigned inst;
int top;
{
    return (ERROR_FUNCT);
}


/*
 * END JUMP MODULE
 */
