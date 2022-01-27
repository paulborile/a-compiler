/*
 * FILE INPUT MODULE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defstruct.h"
#include "outhd.h"

static char *name;
char tmp_name[] = { "/tmp/flXXXXXX" };  /* length must be <= 14 */

FILE *control(fil_name)
char *fil_name;
{
    FILE *fopen(), *fp;
    int i;

    name = fil_name;
    i = strlen(fil_name);
    i -= 2;
    if ((strncmp(fil_name + i, ".o", 2)) != 0)
        errorfile("filename must end with .o");
    fp = fopen(fil_name, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "al : ");
        perror(fil_name);
        exit(1);
    }
/*
        errorfile("File not exist");
 */
    return (fp);
}

char *get_name(fp)
FILE *fp;
{
    int i = 0;
    static struct head header;

    if (1 != fread((char *) &header, sizeof(header), 1, fp))
        errorfile("bad format in get_name ( cannot read magic )");
    if (header.mag != 'a')
        errorfile("bad format get_name ( incorrect magic )");
    return (header.label);
}

int get_num(fp)
FILE *fp;
{
    int a;

    if (1 != fread((char *) &a, sizeof(a), 1, fp))
        errorfile("bad format in get_num");
    return (a);
}

put_num(num, fp)
unsigned num;
FILE *fp;
{
    fwrite((char *) &num, sizeof(int), 1, fp);
}

errorfile(message)
char *message;
{
    fprintf(stderr, "al : %s: %s\n", name, message);
    exit(1);
}

FILE *tmp_crea()
{
    FILE *tmp;

    mktemp(tmp_name);
    if ((tmp = fopen(tmp_name, "w")) == NULL)
    {
        fprintf(stderr, "al : ");
        perror(tmp_name);
        exit(1);
    }
    return (tmp);
}

/*
 * END FILE INPUT MODULE
 */
