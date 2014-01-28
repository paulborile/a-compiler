/* 
 *  Milano , Silab Thu Sep 12 1985
 *
 *  a c m a i n . c	Ac compiler .
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include "ac.h"

#define	OPTS	"CSlo:"

extern int fatal;				/* fatal error flag */
extern char crossfile[];
char command[80];
int status;						/* child status */
extern int rubout();
char *template = "./cbXXXXXX";
extern char *mktemp();
char shell[80];

main(argc, argv)
int argc;
char *argv[];
{
	int i, j;
	extern int optind;
	extern char *optarg;

/*
 * 	trap interupt SIGINT ( delete key )
 */
	signal(SIGINT, (void *) rubout);

	while ((j = getopt(argc, argv, OPTS)) != EOF)
	{
		switch (j)
		{

			case 'o':
				/* Compilation and linking together  */
				if (oflag)
				{
					fprintf(stderr, "ac : to many output files\n");
					exit(0);
				}
				oflag++;
				/*      strncpy(ofile,optarg,F_LEN); */
				/*      system("linker");  */
				break;
			case 'l':
				l_list++;
				break;
			case 'S':
				s_flag++;
				break;
			case 'C':
				c_flag++;
				break;
			case '?':
				fprintf(stderr, USAGE);
				exit(0);
		}
	}

	for (; optind < argc; optind++)
	{

		if (argv[optind][(strlen(argv[optind]) - 1)] != 'a')
		{
			fprintf(stderr, "ac : filename must end with .a\n");
			break;
		}
		if (argv[optind][(strlen(argv[optind]) - 2)] != '.')
		{
			fprintf(stderr, "ac : filename must end with .a\n");
			break;
		}

		strncpy(ifile, argv[optind], F_LEN);
		strncpy(ofile, argv[optind], F_LEN);

/* if flag for assembly output create file */

		if (l_list)
		{
			c_create();
		}
		if (s_flag)
		{
			strncpy(asfile, argv[optind], F_LEN);
		}
		if (c_flag)
		{
			strncpy(cfile, argv[optind], F_LEN);
		}
		if (!oflag)
		{
			if (s_flag)
			{
				asfile[strlen(asfile) - 1] = 's';
				if ((fp_ass = fopen(asfile, "w")) == NULL)
				{
					fprintf(stderr, "ac : ");
					perror(asfile);
					exit(1);
				}
			}
			if (c_flag)
			{
				cfile[strlen(cfile) - 1] = 'c';
				if ((fp_c = fopen(cfile, "w")) == NULL)
				{
					fprintf(stderr, "ac : ");
					perror(cfile);
					exit(1);
				}
			}
			ofile[(strlen(ofile) - 1)] = 'o';
			if ((fp_out = fopen(ofile, "w")) == NULL)
			{
				fprintf(stderr, "ac : ");
				perror(ofile);
				exit(1);
			}
			fd_out = fileno(fp_out);
		}
		else
		{
			/* compile and link facility */
			printf("Not yet implemented.Sorry ...\n");
			exit(1);
		}


		if ((i = access(argv[optind], 4)) == -1)
		{
			fprintf(stderr, "ac : ");
			perror(argv[optind]);
			break;
		}

		if ((freopen(argv[optind], "r", stdin)) == NULL)
		{
			fprintf(stderr, "ac : ");
			perror(argv[optind]);
			break;
		}
		printf("Compiling %s\n", argv[optind]);

		yret_code = yyparse();

		printf("Compilation completed %d\n", yret_code);


/*  write on file all tables created by yyparse() */
/*  only if fatal error flag had not been set     */

		if (!fatal)
		{

			/* put header */
			put_hd();
			/* dump dtable with size on top */
			d_dump();
			/* dump etable with size on top */
			e_dump();
			/* dump rtable with size on top */
			r_dump();
			/* dump i_table with size on top */
			i_dump();
			/* Complete ! */
			close(fd_out);
			fclose(fp_out);
			if (s_flag)
			{
				fclose(fp_ass);
			}
			if (c_flag)
			{
				fclose(fp_c);
			}
			if (l_list)
			{
				fclose(fp_cref);
			}
		}
		else
		{
			/* no file has to be created */

			unlink(ofile);
			if (l_list)
			{
				unlink(crossfile);
			}
			if (s_flag)
			{
				unlink(asfile);
			}
			if (c_flag)
			{
				unlink(cfile);
			}
		}


		if ((l_list) && (!fatal))
		{
			if (!fork())
			{
				execl("/usr/bin/sort", "sort", crossfile, "-o", crossfile,
					  (char *) NULL);
			}
			wait(&status);
			mkxref();
		}

		if ((c_flag) && (!fatal))
		{
			strcpy(cbfile, mktemp(template));
			strcat(shell, "cb -s ");
			strcat(shell, cfile);
			strcat(shell, " > ");
			strcat(shell, cbfile);
			system(shell);
			if (unlink(cfile) < 0)
			{
				perror(cfile);
				exit(1);
			}
			if (link(cbfile, cfile) < 0)
			{
				perror(cbfile);
				exit(1);
			}
			if (unlink(cbfile) < 0)
			{
				perror(cbfile);
				exit(1);
			}
		}


		ac_init();				/* initialize variables again for other compilations */
		if (yret_code)
		{
			fprintf(stderr, "ac : cannot finish compilation. Bye...\n");
			break;
		}
	}
}

int yywrap(void)
{
	return (1);
}
