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
	uncrustify -l C --replace --no-backup -c ../crustify-config *.[ch]

