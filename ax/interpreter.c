/*
 * INTERPRETER MODULE
 */

#include    "error.h"
#include    "vmacdef.h"

unsigned memory[MEM_DIM];
int sp, pc;
int max_sp, flag = 007;
unsigned ri;

#ifdef  DEBUG
extern int inst_trace();
#endif  /* DEBUG */

extern int pushi(), pushir(), push(), pushr(), pop(), popr(),
pushin(), popin(), add(), sub(), mul(), div(), cmp(), jmp(), call(),
ret(), input(), output(), stop(), sp_alloc(), sp_free(), ufo();
nop();
typedef int (*PFI) ();

char *mnem[] = {
    "PUSHI", "PUSHIR", "PUSH", "PUSHR", "POP", "POPR", "PUSHIN", "POPIN",
    "ADD", "SUB", "MUL", "DIV", "CMP", "NOP", "UFO", "UFO",
    "UFO", "JEQ", "JGT", "JGE", "JLT", "JLE", "JNE", "JMP",
    "CALL", "RET", "STOP", "SP_ALLOC", "SP_FREE", "UFO", "UFO", "UFO",
    "INPUT", "OUTPUT"
};

static PFI vett[NUM_INST] = {
    pushi, pushir, push, pushr, pop, popr, pushin, popin,
    add, sub, mul, div, cmp, nop, ufo, ufo,
    ufo, jmp, jmp, jmp, jmp, jmp, jmp, jmp,
    call, ret, stop, sp_alloc, sp_free, ufo, ufo, ufo,
    input, output
};

interpreter(mem_size)
int mem_size;
{
    int state;
    do
    {
        if (pc >= mem_size)
            state = (int) (ERROR_FUNCT);
        else
        {
            ri = memory[pc];
#ifdef  DEBUG
            inst_trace(ri, mem_size);
#endif  /* DEBUG */
            pc++;
            if (((int) (ri)) < NUM_INST)
                state = (*vett[ri])(ri, mem_size);
            else
                state = ufo(ri, mem_size);
        }
    }
    while (state != ERROR_FUNCT);
}

/* END INTERPRETER */

next(top, next_cod)
int top;
unsigned *next_cod;
{
    *next_cod = memory[pc++];
#ifdef  DEBUG
    printf(">>>>  operand of instruction :%d  <<<<\n", memory[pc - 1]);
#endif  /* DEBUG */
    if (pc >= top)
        return (ERROR_FUNCT);
    else
        return (!ERROR_FUNCT);
}

/* END NEXT */

/*
 * END INTERPRETER MODULE
 */
