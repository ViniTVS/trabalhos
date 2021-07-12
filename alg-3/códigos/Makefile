CC = gcc
CFLAGS= -g 

final=	main.o funcoes_avl.o funcoes_abb.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)


myavl:	$(final)
	$(CC) -o $@ $^ $(CFLAGS)

all:	myavl

clean:
	rm *.o
	rm myavl
