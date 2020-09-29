CC = gcc-9
EXECS = sequential

.PHONY: $(EXECS)
all: $(EXECS)

sequential:
	cd src; $(CC) rcm.c functions.c main_sequential.c -fopenmp -o ../bin/$@; cd ..;

parallel:
	cd src; $(CC) rcm.c functions.c main_omp.c -fopenmp -o ../bin/$@; cd ..;