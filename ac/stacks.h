/*
 * Define jump back stacks for IF and WHILE instructions
 */

#define MAXNEST 20  /* maximum nesting for IF and WHILE */


int i_stack[MAXNEST];
int w_stack[MAXNEST];
