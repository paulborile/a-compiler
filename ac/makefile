# Milano , Silab    Thu Sep 12 1985
#
# M a k e f i l e   for ac compiler
#

CFLAGS = -O2
YFLAGS = -v
LIBES = 
YACC = bison -yl

SRC = acmain.c yyerror.c gram.y scan.l dtab.c etab.c rtab.c \
itab.c init.c yyvars.c outhd.c dump.c stacks.c asout.c cref.c \
yylvars.c lvtab.c vval.c aval.c vref.c aref.c call.c iden.c \
signal.c cout.c

OBJ = acmain.o yyerror.o gram.o scan.o dtab.o etab.o rtab.o \
itab.o init.o yyvars.o outhd.o dump.o stacks.o asout.o cref.o \
yylvars.o lvtab.o vval.o aval.o vref.o aref.o call.o iden.o \
signal.o cout.o

ac: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBES)

indent:
	uncrustify -l C --replace --no-backup -c ../crustify-config *.[ch]

