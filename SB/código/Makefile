AS = as SB.s -o SB.o
all:
	$(AS)
	ld SB.o -o trab -dynamic-linker /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o /usr/lib/x86_64-linux-gnu/crtn.o -lc

home:
	$(AS)	
	ld SB.o -o trab -dynamic-linker /lib/ld-linux-x86-64.so.2 /usr/lib/crt1.o /usr/lib/crti.o /usr/lib/crtn.o -lc

c:
	as Teste.s -o Teste.a
	gcc -fPIE teste_c.c Teste.a -o trab
clean:
	rm *.o
	rm trab