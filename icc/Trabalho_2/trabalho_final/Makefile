all: pdeSolver

pdeSolver: pdeSolver.o Sistemas_Lineares.o utils.o
	gcc -g -o pdeSolver pdeSolver.o Sistemas_Lineares.o utils.o -lm -DLIKWID_PERFMON -I/home/soft/likwid/include -L/home/soft/likwid/lib -llikwid -O3 -mavx -march=native

pdeSolver.o: pdeSolver.c
	gcc -g -o pdeSolver.o -c pdeSolver.c -lm -Wall -DLIKWID_PERFMON -I/home/soft/likwid/include -L/home/soft/likwid/lib -llikwid -O3 -mavx -march=native

Sistemas_Lineares.o: Sistemas_Lineares.c Sistemas_Lineares.h
	gcc -g -o Sistemas_Lineares.o -c Sistemas_Lineares.c -lm -Wall -DLIKWID_PERFMON -I/home/soft/likwid/include -L/home/soft/likwid/lib -llikwid -O3 -mavx -march=native

utils.o: utils.c utils.h
	gcc -g -o utils.o -c utils.c -lm -Wall -O3 -mavx -march=native

doc: arqDox
	doxygen arqDox

clean:
	rm -rf *.o
	rm -rf pdeSolver
	rm -rf *.txt *.dat
	rm -rf *.c.save
	rm -rf html


#export PATH=/home/soft/likwid/bin:/home/soft/likwid/sbin:$PATH
#export LD_LIBRARY_PATH=/home/soft/likwid/lib:$LD_LIBRARY_PATH