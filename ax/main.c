/* 
 * MAIN PROGRAM OF INTERPRETER  
*/

#include "error.h"
#include <stdio.h>

extern int loader(), interpreter();

main(argc, argv)				/* main del interprete AX */
int argc;
char *argv[];
{
	int program_size;			/* numero di istruzioni del programma */

	switch (argc)
	{

		case 1:				/* manca il nome del file da eseguire */
			fprintf(stderr, "%s\n", USAGE);
			break;
		case 2:
			if ((program_size = loader(argv[1])) != ERROR_FUNCT)
				interpreter(program_size);
			break;
		default:				/* stampa l'usage del ax */
			fprintf(stderr, "%s\n", USAGE);
			break;
	}
}

/* END MAIN */
