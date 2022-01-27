/*
 * LOADER MODULE
 */

#include <stdio.h>
#include "vmacdef.h"
#include "error.h"

#define FILE_KEY    'A'         /* chiave per riconoscere un file A eseguibile */

extern unsigned memory[];       /* memoria della macchina virtuale */
extern get_word();
extern get_byte();
extern int sp, pc, max_sp;


loader(name)                    /* carica il programma dal file in memoria */
char *name;                     /* nome file esterno */
{
    int program_size;           /* numero di istruzioni da caricare */
    FILE *fopen(), *fp;

    if ((fp = fopen(name, "r")) != NULL)
    {
        if (control(fp) == ERROR_FUNCT)
        {
            printf("** File corrupted on instruction number **\n");
            return (ERROR_FUNCT);
        }
        if (get_word(fp, &program_size) == ERROR_FUNCT)
        {
            printf("%s\n", FILE_ERROR);
            return (ERROR_FUNCT);
        }
        if (get_word(fp, &sp) == ERROR_FUNCT)
        {
            printf("** File corrupted on sp **\n");
            return (ERROR_FUNCT);
        }
        max_sp = sp;
        if (get_word(fp, &pc) == ERROR_FUNCT)
        {
            printf("** File corrupted on start address **\n");
            return (ERROR_FUNCT);
        }
        if (program_size != ERROR_FUNCT)
            program_size = load(program_size, fp);
        fclose(fp);
        return (program_size);  /* ritorna il numero di istruzioni
                                   oppure ERROR_FUNCT se si e' verificato un errore
                                   nel caricamento   */
    }
    else
    {
        fprintf(stderr, "ax : ");
        perror(name);
/*
        printf("%s %s\n",NOT_OPEN_FILE,name);
 */
        fclose(fp);
        return (ERROR_FUNCT);
    }
}                               /* END LOADER */

control(plf)
FILE *plf;
{
    if (get_byte(plf) == ((int) FILE_KEY))
    {
        return (!ERROR_FUNCT);
    }
    else
    {
        printf("%s\n", NOT_A_TYPE);
        return (ERROR_FUNCT);
    }
}                               /* END CONTROL */

load(pgm_size, pf)
int pgm_size;
FILE *pf;
{
    int i;

    for (i = 0;
         (i < pgm_size) && (i < MEM_DIM)
         && ((get_word(pf, &memory[i])) != ERROR_FUNCT); i++)
        ;
    if (i != pgm_size)
    {
        printf("%s\n", FILE_ERROR);
        return (ERROR_FUNCT);
    }
    else
        return (pgm_size);
}                               /* END LOAD */

/*
 * END LOADER MODULE
 */
