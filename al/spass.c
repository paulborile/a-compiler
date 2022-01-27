/*
 * SECOND PASS LINKER MODULE
 */

#include <stdio.h>
#include <stdlib.h>
#include "defstruct.h"

extern int splow;
extern int addisp;
extern char *out_name;
extern int inrtab();
extern rrec *get_fi_rel();
extern int put_f1_rt();
extern int put_num();
extern int get_num();
extern int max_etab();
extern erec *et_num_get();
extern rrec *rt_f1_pass();
extern char *tmp_name[];

second(fp)
FILE *fp;
{
    int i, maxe;
    int std_adr;
    int num;
    int ci;
    int mov;
    int e_flag = 0;
    int m_flag = 0;
    erec *poine;
    rrec *poinr;
    FILE *fp2;
    char key = 'A';

    maxe = max_etab();
    for (i = 0; i < maxe; i++)
    {
        poine = et_num_get(i);
        if (poine->flag == 'I')
        {
            fprintf(stderr, "al : Procedure not defined :");
            fprintf(stderr, "%.8s \n", poine->name);
            e_flag++;
        }
        if (poine->flag == 'M')
        {
            if (m_flag == 1)
            {
                fprintf(stderr, "al : Too many program");
                fprintf(stderr, " statements \n");
                m_flag++;
            }
            else
            {
                m_flag++;
                std_adr = poine->address;
            }
        }
    }
    if ((m_flag == 0) && maxe)
        fprintf(stderr, "al : Missing program module \n");
    if ((e_flag != 0) || (m_flag != 1))
    {
        fclose(fp);
        exit(1);
    }
    if (addisp >= splow)
    {
        fprintf(stderr, "al : Program too big \n");
        fclose(fp);
        unlink(tmp_name);
        exit(1);
    }
    if (out_name == NULL)
        out_name = "out.ax";
    fp2 = fopen(out_name, "w");
    if (fp2 == NULL)
    {
        fprintf(stderr, "al : ");
        perror(out_name);
        fclose(fp);
        unlink(tmp_name);
        exit(1);
    }
    fwrite(&key, sizeof(char), 1, fp2);
    put_num(addisp, fp2);
    put_num(splow, fp2);
    put_num(std_adr, fp2);
    while ((maxe = get_num(fp)) != -1)
    {
        inrtab();
        for (i = 0; i < maxe; i++)
        {
            poinr = get_fi_rel(fp);
            put_f1_rt(poinr);
        }
        num = get_num(fp);
        ci = 0;
        for (i = 0; i < maxe; i++)
        {
            poinr = rt_f1_pass(i);
            for (; ci < poinr->address; ci++)
                put_num(get_num(fp), fp2);
            mov = get_num(fp);
            poine = et_num_get(mov);
            put_num(poine->address, fp2);
            ci++;
        }
        for (; ci < num; ci++)
            put_num(get_num(fp), fp2);
    }
    fclose(fp2);
}

/*
 * END OF SECOND PASS LINKER MODULE
 */
