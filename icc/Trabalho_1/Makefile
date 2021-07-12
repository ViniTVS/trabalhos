CC = gcc
CFLAGS= -g -lm

final=	pdeSolver.o Sistemas_Lineares.o utils.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)


pdeSolver:	$(final)
	$(CC) -o $@ $^ $(CFLAGS)

all:	pdeSolver

clean:
	rm -rf html/
	rm *.o
	rm pdeSolver
doc:
	doxygen arqDox