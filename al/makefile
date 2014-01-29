CFLAGS = -O

SRC = main.c open.c linker.c fpass.c emod.c rmod.c dmod.c rbuff.c io.c print.c  spass.c


OBJ = main.o open.o linker.o fpass.o emod.o rmod.o dmod.o rbuff.o io.o print.o  spass.o


al	: 	$(OBJ)
		$(CC) -o al $(OBJ)
clean :
	rm *.o 

indent	:
	indent -ts4 -kr -bl -bli0 -bls -cli4 -nce -l80 *.c

print.o rbuff.o dmod.o rmod.o emod.o fpass.o spass.o : defstruct.h
linker.o : vmacdef.h
io.o : outhd.h
