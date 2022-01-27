/*
 *  Milano , Silab Thu Sep 12 1985
 *
 *  a a m a i n . c	Stack Machine  Assembler .
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "aa.h"

extern char tsave[];
extern int err_cnt, ill_cnt;

main(argc, argv)
int argc;
char *argv[];
{
    int i, j;
    extern int optind;
    extern char *optarg;

    while ((j = getopt(argc, argv, "lo:")) != EOF)
    {
        switch (j)
        {

        case 'o':
            /* Compilation and linking together  */
            if (oflag)
            {
                fprintf(stderr, "aa : too many output files\n");
                exit(0);
            }
            oflag++;
            strncpy(ofile, optarg, F_LEN);
            /*      system("linker");  */
            break;
        case 'l':
            l_list++;
            break;
        case '?':
            fprintf(stderr, USAGE);
            exit(0);
        }
    }

    for (; optind < argc; optind++)
    {

        if (argv[optind][(strlen(argv[optind]) - 1)] != 's')
        {
            fprintf(stderr, "aa : filename must end with .s\n");
            break;
        }
        if (argv[optind][(strlen(argv[optind]) - 2)] != '.')
        {
            fprintf(stderr, "aa : filename must end with .s\n");
            break;
        }

        strncpy(ofile, argv[optind], F_LEN);
        strncpy(ifile, argv[optind], F_LEN);

        if (!oflag)
        {
            ofile[(strlen(ofile) - 1)] = 'o';
            if ((fp_out = fopen(ofile, "w")) == NULL)
            {
                fprintf(stderr, "aa : ");
                perror(ofile);
                exit(1);
            }
            fd_out = fileno(fp_out);
        }
        else
        {
            /* compile and link facility */
        }


        if ((i = access(argv[optind], 4)) == -1)
        {
            fprintf(stderr, "aa : ");
            perror(argv[optind]);
            break;
        }

        if ((freopen(argv[optind], "r", stdin)) == NULL)
        {
            fprintf(stderr, "aa : ");
            perror(argv[optind]);
            break;
        }
        printf("Compiling %s\n", argv[optind]);

        tsave[0] = '\0';
        yret_code = yyparse();

/*  write on file all tables created by yyparse() */

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
        }
        else
        {
            unlink(ofile);
        }

        if (yret_code)
        {
            fprintf(stderr, "aa : Cannot finish compilation. Bye...\n");
            break;
        }
        else
        {
            printf("Program Assembly completed .");
            printf("Total errors = %d\n", err_cnt + ill_cnt);
        }
        ac_init();              /* initialize variables again for other compilations */
    }
}
