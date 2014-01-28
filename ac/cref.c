/*
 *	c r e f . c
 *
 * Cross reference tables manage
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extern.h"
#include "cref.h"

char crossfile[F_LEN];
char name[MAXVAR + 2];
char lastname[MAXVAR + 2];
char flag;
int l_cnt;

/* Create  temporary file for cross reference */

c_create()
{
	char *template = { "/tmp/crXXXXXX" };

	strcpy(crossfile, mktemp(template));
	if ((fp_cref = fopen(crossfile, "w")) == NULL)
	{
		fprintf(stderr, "ac : ");
		perror(crossfile);
		exit(1);
	}
}


/*
 *	Put reference of variable on external file 
 */

put_ref(var, flag)
char *var;
char *flag;
{
	fprintf(fp_cref, "%.8s\t\t%.1s\t%d\n", var, flag, lin_cnt);
}



mkxref()
{
	int num;
	int first;
	char alfa;

	if ((fp_cref = fopen(crossfile, "r")) == NULL)
	{
		fprintf(stderr, "ac : ");
		perror(crossfile);
		exit(1);
	}
	printf("\n\n\t'A' Language Cross Reference listing\n\n");
	rd_ref();
	putchar('-');
	putchar((alfa = toupper(name[0])));
	putchar('-');
	printf("\n    %s\n", name);
	printf("\t%d", l_cnt);
	strcpy(lastname, name);
	num = 0;
	while (rd_ref() != EOF)
	{
		if (alfa != toupper(name[0]))
		{
			putchar('\n');
			putchar('-');
			putchar((alfa = toupper(name[0])));
			putchar('-');
		}
		if (strcmp(lastname, name) == 0)
		{
			if (num++ == 7)
			{
				printf("\n");
				num = 0;
			}
			printf("\t%d", l_cnt);
		}
		else
		{
			printf("\n    %s\n", name);
			printf("\t%d", l_cnt);
			num = 0;
		}
		strcpy(lastname, name);
	}
	putchar('\n');
	unlink(crossfile);
	printf("\n\n\tEnd Cross reference section \n");
}


rd_ref()
{
	return (fscanf(fp_cref, "%s\t\t%s\t%d\n", name, &flag, &l_cnt));
}
