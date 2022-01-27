/*
 * STACK MODULE
 */

#include "error.h"
#include "vmacdef.h"

extern int errinst(), out_of_memory();

extern unsigned memory[];
extern int pc, sp, flag, max_sp;

pushi(ri, top)
register unsigned ri;
register int top;
{
    if (--sp <= top)
        return (errinst("PUSHI", MSG_OVR));
    else if (next(top, &memory[sp]) == ERROR_FUNCT)
        return (errinst("PUSHI", MSG_PC_ERR));
    else
        return (!ERROR_FUNCT);
}

pushir(ri, top)
register unsigned ri;
register int top;
{
    unsigned opcod;

    if (--sp <= top)
        return (errinst("PUSHIR", MSG_OVR));
    else if (next(top, &opcod) == ERROR_FUNCT)
        return (errinst("PUSHIR", MSG_PC_ERR));
    else
    {
        memory[sp] = opcod + sp;
        return (!ERROR_FUNCT);
    }
}

push(ri, top)
register unsigned ri;
register int top;
{
    unsigned opcod;

    if (--sp <= top)
        return (errinst("PUSH", MSG_OVR));
    else if (next(top, &opcod) == ERROR_FUNCT)
        return (errinst("PUSH", MSG_PC_ERR));
    else if (opcod >= MEM_DIM)
        return (out_of_memory("PUSH", opcod));
    else
    {
        memory[sp] = memory[opcod];
        return (!ERROR_FUNCT);
    }
}

pushr(ri, top)
register unsigned ri;
register int top;
{
    unsigned opcod;

    if (--sp <= top)
        return (errinst("PUSHR", MSG_OVR));
    else if (next(top, &opcod) == ERROR_FUNCT)
        return (errinst("PUSHR", MSG_PC_ERR));
    else if ((opcod += (unsigned) sp) >= MEM_DIM)
        return (out_of_memory("PUSHR", opcod));
    else
    {
        memory[sp] = memory[opcod];
        return (!ERROR_FUNCT);
    }
}

pop(ri, top)
register unsigned ri;
register int top;
{
    unsigned opcod;

    if (next(top, &opcod) == ERROR_FUNCT)
        return (errinst("POP", MSG_PC_ERR));
    else if (opcod >= MEM_DIM)
        return (out_of_memory("POP", opcod));
    else
    {
        memory[opcod] = memory[sp];
        if (++sp > max_sp)
            return (errinst("POP", MSG_UND));
        else
            return (!ERROR_FUNCT);
    }
}

popr(ri, top)
register unsigned ri;
register int top;
{
    unsigned opcod;

    if (next(top, &opcod) == ERROR_FUNCT)
        return (errinst("POPR", MSG_PC_ERR));
    else if ((opcod += sp) >= MEM_DIM)
        return (out_of_memory("POPR", opcod));
    else
    {
        memory[opcod] = memory[sp];
        if (++sp > max_sp)
            return (errinst("POPR", MSG_UND));
        else
            return (!ERROR_FUNCT);
    }
}

pushin(ri, top)
register unsigned ri;
register int top;
{
    register unsigned temp;

    temp = memory[sp];
    if (temp >= MEM_DIM)
        return (out_of_memory("PUSH*", temp));
    else
    {
        memory[sp] = memory[temp];
        return (!ERROR_FUNCT);
    }
}

popin(ri, top)
register unsigned ri;
register int top;
{
    register unsigned temp;

    if ((sp += 2) > max_sp)
        return (errinst("POP*", MSG_UND));
    else
    {
        temp = memory[sp - 1];
        if (temp >= MEM_DIM)
            return (out_of_memory("POP*", temp));
        else
        {
            memory[temp] = memory[sp - 2];
            return (!ERROR_FUNCT);
        }
    }
}

sp_alloc(ri, top)
register unsigned ri;
register int top;
{
    int tmp;

    if (next(top, &tmp) == ERROR_FUNCT)
        return (errinst("SP_ALLOC", MSG_PC_ERR));
    else if ((sp -= tmp) <= top)
        return (errinst("SP_ALLOC", MSG_OVR));
    else
        return (!ERROR_FUNCT);
}

sp_free(ri, top)
register unsigned ri;
register int top;
{
    int tmp;

    if (next(top, &tmp) == ERROR_FUNCT)
        return (errinst("SP_FREE", MSG_PC_ERR));
    else if ((sp += tmp) > max_sp)
        return (errinst("SP_FREE", MSG_UND));
    else
        return (!ERROR_FUNCT);
}

/*
 * END STACK MODULE
 *
 */
