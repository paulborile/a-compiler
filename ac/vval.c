/*
 *	v v a l . c
 *
 * Code generation and semantic analisys
 * for variables as value ( rigth value )
 */

#include <stdio.h>
#include "structs.h"
#include "instcod.h"
#include "extern.h"
#include "var.h"


vval()
{
    if (l_list)
        put_ref(yysave, "U");
    if ((in_proc) && (strncmp(yysave, p_param, MAXVAR) == 0))
    {
        ia_add(PUSHR, (act_sp + 3));
        if (s_flag)
        {
            as_i_int("pushr", (act_sp + 3));
        }
        act_sp += 1;
        ib_add(PUSH_);
        if (s_flag)
        {
            as_inst_pr("push*", "");
        }
        return;
    }

    d_dummy = d_search(dbase, yysave);
    lv_dummy = lv_search(lvbase, yysave);

/* here we are in procedure module */

    if (in_proc)
    {
        if ((d_dummy == NULL) && (lv_dummy == NULL))
        {
            yygenerr("undefined variable '", yysave, "'", "");
            return;
        }
        if (lv_dummy != NULL)
        {
            ia_add(PUSHR, (act_sp - (lv_dummy->addr) + 1));
            if (s_flag)
            {
                as_i_int("pushr", (act_sp - (lv_dummy->addr) + 1));
            }
            act_sp += 1;
        }
        else
        {
            ia_add(PUSH, (d_dummy->addr));
            rel_all("D");
            act_sp += 1;
            if (s_flag)
            {
                as_inst_pr("push", yysave);
            }
        }
    }
/* here is outside procedure body */
    else
    {
        if (d_dummy == NULL)
        {
            yygenerr("undefined variable '", yysave, "'", "");
            return;
        }
        ia_add(PUSH, (d_dummy->addr));
        rel_all("D");
        if (s_flag)
        {
            as_inst_pr("push", yysave);
        }
    }
}
