/*
 *	s t a c k s . c
 *
 * Stacks manage for IF and WHILE statements
 */

#include "stacks.h"


/* define stack for label generation */

#define	MAXLSTACK	(MAXNEST*2)
int	l_stack[MAXLSTACK];
int	l_sp = -1;

/* define some variables */

int	i_sp = -1;
int	w_sp = -1;

/* In IF 
 * push address of JMP operand to be filled after */

i_push(addr)
int	addr;
{
	i_sp++;
	if (i_sp >= MAXNEST ) {
		yyError("Internal IF stack overflow ( To much nesting )\n");
		exit(1);
	}
	i_stack[i_sp] = addr;
}

/* In IF
 * get address of JMP operand to be filled */

i_pop()
{
	if ( i_sp == -1) {
		yyError("Internal IF stack underflow ( To much nesting )\n");
		exit(1);
	}
	return(i_stack[i_sp--]);
}

/* In WHILE
 * push address of JMP operand to be filled */

w_push(addr)
int	addr;
{
	w_sp++;
	if (w_sp >= MAXNEST ) {
		yyError("Internal WHILE stack overflow ( To much nesting )\n");
		exit(1);
	}
	w_stack[w_sp] = addr;
}

/* In WHILE
 * get address of JMP operand to be filled */

w_pop()
{
	if ( w_sp == -1) {
		yyError("Internal WHILE stack underflow ( To much nesting )\n");
		exit(1);
	}
	return(w_stack[w_sp--]);
}

l_push(addr)
/* 
 * Push counter of current label number in label stack
 */

int	addr;
{
	l_sp++;
	if (l_sp >= MAXLSTACK ) {
		yyError("Internal LABEl stack overflow ( To much nesting )\n");
		exit(1);
	}
	l_stack[l_sp] = addr;
}


/*
 * Pop counter for label creation
 */

l_pop()
{
	if ( l_sp == -1) {
	    yyError("Internal LABEl stack underflow ( To much nesting )\n");
	    exit(1);
	}
	return(l_stack[l_sp--]);
}

/*
 * Get previous value in stacl pointer
 * without changing position to stack pointer
 */

l_prev()
{
	if (( l_sp -1 ) < 0) {
	    yyError("Internal LABEl stack underflow ( To much nesting )\n");
	    exit(1);
	}
	return(l_stack[l_sp-1]);
}
