CFLAGS = -O

SRC = main.c loader.c interpreter.c io.c stack.c insterr.c als.c jump.c \
	inouts.c

OBJ = main.o loader.o interpreter.o io.o stack.o insterr.o als.o jump.o \
	inouts.o


ax	: 	$(OBJ)
		$(CC) -o ax $(OBJ)

axd	:	$(OBJ)
		$(CC) -o axd $(OBJ)

debug	:	
		touch interpreter.c insterr.c
		make axd "CFLAGS = -DDEBUG"
again	:
		touch interpreter.c insterr.c
		make ax

clean:
	rm $(OBJ)

indent:
	indent -ts4 -kr -bl -bli0 -bls -cli4 -nce -l80 *.c


inouts.o jump.o insterr.o main.o loader.o : error.h
interpreter.o io.o stack.o als.o : error.h
jump.o stack.o interpreter.o als.o loader.o : vmacdef.h
inouts.o : vmacdef.h
