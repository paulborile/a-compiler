/*
 * FIRST PASS LINKER MODULE
 */

#include    <stdio.h>
#include <stdlib.h>
#include    "defstruct.h"

extern int l_flag;
extern int in_mod;
extern int indtab();
extern int inrtab();
extern int inrbuffer();
extern int max_etab();
extern FILE *control();
extern char *get_name();
extern int pr_mod_na();
extern int pr_proc();
extern int pr_data();
extern int get_num();
extern drec *get_data();
extern rrec *get_fi_rel();
extern int put_f2_rt();
extern int put_out();
extern erec *et_num_get();
extern dtab *dt_num_get();
extern rrec *rt_f2_pass();
extern rrec *rt_f1_pass();
extern int put_f1_rt();
extern int put_dtab();
extern erec *get_proc();
extern erec *search_eta();
extern int put_etab();
extern int change_ref();
extern int put_num();
extern int pr_line();
extern int pr_sep();
extern int addisp;
extern int splow;
int mod_etab;

first(name, out)
char *name;
FILE *out;
{
    char *mod_name;
    FILE *fp;
    int i, i2, u, cc;
    dtab *point;
    drec *poind;
    erec *poine, *poine2;
    rrec *rtpoin;

    indtab();
    inrtab();
    inrbuffer();
    fp = control(name);
    mod_etab = max_etab();
    mod_name = get_name(fp);
    pr_sep();
    pr_mod_na(mod_name);
    u = get_num(fp);
    if (u)
        pr_sep();
    for (i = 0; i < u; i++)
    {
        poind = get_data(fp);
        splow -= poind->length;
        pr_data(poind, splow);
        put_dtab(poind, splow);
    }
    u = get_num(fp);
    if (u)
        pr_sep();
    for (i = 0; i < u; i++)
    {
        poine = get_proc(fp);
        switch (poine->flag)
        {
        case 'S':
            poine->flag = 'I';
            in_mod++;
        case 'I':
            poine2 = search_eta(poine->name, 'E');
            if (poine2 != NULL)
                put_etab(poine2);
            else
                put_etab(poine);
            break;
        case 'E':
            poine->address += addisp;
            put_etab(poine);
            change_ref(poine);
            pr_proc(poine);
            break;
        case 'L':
            poine->address += addisp;
            put_etab(poine);
            break;
        default:
            poine->address += addisp;
            put_etab(poine);
            pr_proc(poine);
            break;
        }
    }
    u = get_num(fp);
    for (i = 0; i < u; i++)
    {
        rtpoin = get_fi_rel(fp);
        if (rtpoin->flag == 'E')
        {
            put_f2_rt(rtpoin);
        }
        else
        {
            put_f1_rt(rtpoin);
        }
    }
    put_out(out);
    u = get_num(fp);
    put_num(u, out);
    cc = 0;
    i = 0;
    i2 = 0;
    while ((rt_f2_pass(i2) != NULL) || (rt_f1_pass(i) != NULL))
    {
        if (rt_f1_pass(i) != NULL)
        {
            if (rt_f2_pass(i2) != NULL)
            {
                if ((rt_f1_pass(i)->address) > (rt_f2_pass(i2)->address))
                {
                    chgref(fp, out, &cc, &i2, rt_f2_pass(i2));
                }
                else
                {
                    reloc(fp, out, &cc, &i, rt_f1_pass(i));
                }
            }
            else
            {
                reloc(fp, out, &cc, &i, rt_f1_pass(i));
            }
        }
        else
        {
            chgref(fp, out, &cc, &i2, rt_f2_pass(i2));
        }
    }
    for (; cc <= (u - 1); cc++)
        put_num(get_num(fp), out);
    addisp += u;
    pr_sep();
    pr_line();
    fclose(fp);
}

reloc(fp, out, cc, cnt, pointrr)
FILE *fp, *out;
int *cc, *cnt;
rrec *pointrr;
{
    dtab *poind;

    while (*cc < pointrr->address)
    {
        put_num(get_num(fp), out);
        (*cc)++;
    }
    switch (pointrr->flag)
    {
    case 'D':
        poind = dt_num_get(get_num(fp));
        put_num(poind->address, out);
        break;
    case 'J':
        put_num(get_num(fp) + addisp, out);
        break;
    default:
        fprintf(stderr, "** LABEL NOT ALLLOWED **");
        exit(1);
    }
    (*cc)++;
    (*cnt)++;
}

chgref(fp, out, cc, ncnt, rpoint)
FILE *fp, *out;
int *cc, *ncnt;
rrec *rpoint;
{
    while (*cc < rpoint->address)
    {
        put_num(get_num(fp), out);
        (*cc)++;
    }
    put_num(get_num(fp) + mod_etab, out);
    (*cc)++;
    (*ncnt)++;
}

/*
 * END FIRST PASS LINKER MODULE
 */
