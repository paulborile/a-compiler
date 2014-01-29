#	Milano , Silab    Thu Sep 12 1985
#
#	M a k e f i l e   for ac compiler
#

CFLAGS = 
LFLAGS = -v
YFLAGS = -v
LIBES = 
YACC = bison -yl


SRC =  acmain.c yyerror.c gram.y scan.l dtab.c etab.c rtab.c \
       itab.c init.c yyvars.c outhd.c dump.c stacks.c asout.c cref.c \
       yylvars.c lvtab.c vval.c aval.c vref.c aref.c call.c iden.c \
       signal.c cout.c

OBJ =  acmain.o yyerror.o gram.o scan.o dtab.o etab.o rtab.o \
       itab.o init.o yyvars.o outhd.o dump.o stacks.o asout.o cref.o \
       yylvars.o lvtab.o vval.o aval.o vref.o aref.o call.o iden.o \
       signal.o cout.o


ac : 	$(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBES)

clean :
	rm *.o 
	rm y.output

yacc	:
	touch gram.y
	make ac

lex	:
	touch scan.l
	make ac

instal 	:
	cp ac $(HOME)/bin/ac

indent	:
	indent -ts4 -kr -bl -bli0 -bls -cli4 -nce -l80 *.c


# Dependencies after this line here !!

gram.o  : y.tab.h extern.h instcod.h
scan.o : extern.h
yyerror.o  : extern.h
acmain.o : ac.h
dtab.o : structs.h
etab.o : structs.h
rtab.o : structs.h
itab.c : structs.h
init.o : extern.h
yyvars.o : extern.h structs.h 
outhd.o : extern.h outhd.h
dump.o : dump.h structs.h
stacks.o : stacks.h
asout.o : extern.h
cref.o : cref.h
yylvars.o : extern.h structs.h
lvtab.o : structs.h
vval.o : instcod.h var.h
aval.o : instcod.h var.h
vref.o : instcod.h var.h
aref.o : instcod.h var.h
call.o : instcod.h var.h
iden.o : instcod.h
signal.o : extern.h
