#	P.Borile
#	Milano , Silab    Thu Sep 12 1985
#
#	M a k e f i l e   for aa assembler
#

CFLAGS = -O
LFLAGS = -v
YFLAGS = -vd
LIBES = -ll


SRC =  aamain.c agram.y ascan.l dtab.c etab.c rtab.c \
       init.c yyvars.c outhd.c dump.c yyerror.c itab.c ltab.c \
       label.c ultab.c

OBJ =  aamain.o agram.o ascan.o dtab.o etab.o rtab.o \
       init.o yyvars.o outhd.o dump.o yyerror.o itab.o ltab.o \
       label.o ultab.o


aa : 	$(OBJ)
	$(CC) $(CFLAGS) -o aa $(OBJ) $(LIBES)


clean:
	rm $(OBJ)

indent:
	indent -ts4 -kr -bl -bli0 -bls -cli4 -nce -l80 *.c



agram.o  : y.tab.h extern.h
ascan.o : extern.h
aamain.o : aa.h
dtab.o : structs.h extern.h
etab.o : structs.h extern.h
rtab.o : structs.h extern.h
itab.o : structs.h extern.h
ltab.o : structs.h extern.h
ultab.o : structs.h extern.h
label.o : structs.h extern.h
yyerror.c : extern.h
dump.o : dump.h structs.h extern.h
outhd.o : extern.h outhd.h
yyvars.o : extern.h structs.h extern.h
init.o : extern.h
