/*
 * MAIN MODULE OF LINKER FOR 'A' LANGUAGE
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

extern options(), link();
extern char tmp_name[], *out_name;

rubout()
{
    signal(SIGINT, rubout);
    if (access(tmp_name, 0) == 0)
    {
        unlink(tmp_name);
    }
    if (access(out_name, 0) == 0)
    {
        unlink(out_name);
    }
    exit(1);
}

main(argc, argv)
int argc;
char *argv[];
{
    signal(SIGINT, rubout);
    options(&argc, argv);
    link(argc, argv);
}

/*
 * END MAIN MODULE OF LINKER
 */
