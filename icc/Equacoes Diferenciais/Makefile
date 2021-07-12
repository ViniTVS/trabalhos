    CC     = gcc -std=c11
    CFLAGS = 
    LFLAGS = -lm

      PROG = labZeroFuncoes
      OBJS = utils.o \
             ZeroFuncao.o \
             $(PROG).o



.PHONY: limpa faxina clean distclean purge all

%.o: %.c %.h utils.h
	$(CC) -c $(CFLAGS) $<

$(PROG):  $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

clean:
	@rm -f *~ *.bak

purge:   clean
	@rm -f *.o core a.out
	@rm -f $(PROG)

