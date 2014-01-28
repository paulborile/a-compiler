/*
 *	a s o u t . c
 *
 * Assembler printout functions
 */

#include <stdio.h>
#include "extern.h"


/* Print opcode and operand */

as_inst_pr(opcode,operand)
char	*opcode;
char	*operand;
{
	fprintf(fp_ass,"\t%s\t%.8s\n",opcode,operand);
}

/* Same "as_inst_pr" before but operand is now an integer */

as_i_int(opcode,operand)
char	*opcode;
int	operand;
{
	fprintf(fp_ass,"\t%s\t%d\n",opcode,operand);
}

/* Print complete statement */

as_stat(label,opcode,operand)
char	*label,*opcode,*operand;
{
	fprintf(fp_ass,"%s\t%s\t%s\n",label,opcode,operand);
}

/* Print label with colon */

as_label_pr(label)
char	*label;
{
	fprintf(fp_ass,"%s:\n",label);
}

/* Print newline */

as_line_pr()
{
	fprintf(fp_ass,"\n");
}

/* create new label name and return it */

char	*as_make_label(count)
int	count;
{
	static	char	label[MAXVAR];

	sprintf(label,"L%d",count);
	return(label);
}
