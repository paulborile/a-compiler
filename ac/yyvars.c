/*
 * y y v a r s . c
 *
 * What to do when I find variable declarations
 */

#include <stdio.h>
#include "extern.h"
#include "structs.h"
#define TOBEDEF -1

/*
 * Extern variables
 */

/* For dtab */

extern int d_cnt;
extern int d_first;
extern struct dtab *dbase;
extern struct dtab *done;
extern struct dtab *dtwo;
struct dtab *d_init(), *d_add(), *d_search();

/* For etab */

extern int e_cnt;
extern int e_first;
extern struct etab *ebase;
extern struct etab *eone;
extern struct etab *etwo;
struct etab *e_init(), *e_add(), *e_search();
extern struct etab *e_read, *e_write, *e_rd_str, *e_wr_str;

/* For rtab */

extern int r_first;
extern struct rtab *rbase;
extern struct rtab *rone;
extern struct rtab *rtwo;
struct rtab *r_init(), *r_add();


/* for itab */

extern int i_size;
extern int i_cnt;

extern int io_in;
extern char yytext[];
extern char tsave[];
extern char pname[];
extern char procname[];

/* Also need space for PROGRAM statement */

prog_all()
{
    if (e_first)
    {
        ebase = e_init("M", pname);
        eone = etwo = ebase;
    }
}

/* fill program entry point with actual itab address */

fill_p_add()
{
    struct etab *dummy;

    if ((dummy = e_search(ebase, pname)) == NULL)
    {
        yygenerr("No program name", "", "", "");
        return;
    }
    dummy->e_out.addr = i_cnt;
}


/*
 * Allocate space for import variables
 */

imp_all()
{
    if (e_first)
    {
        ebase = e_init("I", yytext);
        eone = etwo = ebase;
    }
    else
    {
        if (e_search(ebase, yytext) == NULL)
        {
            etwo = e_add(eone, "I", yytext);
            eone = etwo;
        }
        else
        {
            yyredec(yytext);
        }
    }
}


/*
 * Allocate space for export variables
 */

exp_all()
{
    struct etab *dummy;

    if (e_first)
    {
        ebase = e_init("E", yytext);
        eone = etwo = ebase;
        return;
    }
    dummy = e_search(ebase, yytext);
    if (dummy == NULL)
    {
        etwo = e_add(eone, "E", yytext);
        etwo->e_out.addr = TOBEDEF;
        eone = etwo;
        return;
    }
    if (dummy->e_out.type == 'P')
    {
        dummy->e_out.type = 'E';
        return;
    }
    yyredec(yytext);
}

/*
 * allocate entry in ETAB for standard I/O routines
 */

io_all()
{
    if (io_in)
        return;
    if (e_first)
    {
        ebase = e_init("S", "read");
        e_read = ebase;
        eone = etwo = ebase;
        etwo = e_add(eone, "S", "write");
        e_write = etwo;
        eone = etwo;
        etwo = e_add(eone, "S", "readstr");
        e_rd_str = etwo;
        eone = etwo;
        etwo = e_add(eone, "S", "writestr");
        e_wr_str = etwo;
        eone = etwo;
        io_in = 1;
        return;
    }
    etwo = e_add(eone, "S", "read");
    e_read = etwo;
    eone = etwo;
    etwo = e_add(eone, "S", "write");
    e_write = etwo;
    eone = etwo;
    etwo = e_add(eone, "S", "readstr");
    e_rd_str = etwo;
    eone = etwo;
    etwo = e_add(eone, "S", "writestr");
    e_wr_str = etwo;
    eone = etwo;
    io_in = 1;
    return;
}



/*
 * Allocate space for VAR declarations
 */

var_all()
{
    if (d_first)
    {
        dbase = d_init(yytext, 1);
        done = dtwo = dbase;
    }
    else
    {
        if (d_search(dbase, yytext) == NULL)
        {
            dtwo = d_add(done, yytext, 1);
            done = dtwo;
        }
        else
        {
            yyredec(yytext);
        }
    }
}

/*
 * Allocate space for array declarations
 */

array_all()
{
    if (d_first)
    {
        dbase = d_init(tsave, atoi(yytext));
        done = dtwo = dbase;
    }
    else
    {
        if (d_search(dbase, tsave) == NULL)
        {
            dtwo = d_add(done, tsave, atoi(yytext));
            done = dtwo;
        }
        else
        {
            yyredec(yytext);
        }
    }
}


/*
 * Allocate entry for procedure
 */

proc_all()
{
    struct etab *dummy;

    if (e_first)
    {
        ebase = e_init("P", yytext);
        eone = etwo = ebase;
        ebase->e_out.addr = i_cnt;
        return;
    }
    dummy = e_search(ebase, yytext);
    if (dummy == NULL)
    {
        etwo = e_add(eone, "P", yytext);
        eone = etwo;
        etwo->e_out.addr = i_cnt;
        return;
    }
    if (dummy->e_out.type == 'E')
    {
        dummy->e_out.addr = i_cnt;
        return;
    }
    yyredec(yytext);
}

/*
 *   Allocate entry in rtab for instruction to be relocated
 */

rel_all(flag)
char *flag;
{
    if (r_first)
    {
        rbase = r_init(flag, i_cnt - 1);
        rone = rtwo = rbase;
    }
    else
    {
        rtwo = r_add(rone, flag, i_cnt - 1);
        rone = rtwo;
    }
}


/*
 * Test if there are some export without procedures to be exported
 */


exp_tst()
{
    struct etab *e_scan;

    e_scan = ebase;
    while (e_scan != NULL)
    {
        if ((e_scan->e_out.type == 'E') && (e_scan->e_out.addr == -1))
        {
            yygenerr("Unresolved export :", e_scan->e_out.ep_name, "", "");
        }
        e_scan = e_scan->next;
    }
}
