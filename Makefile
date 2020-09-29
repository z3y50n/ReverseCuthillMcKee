CC = gcc-9
EXECS = rcm_sequential rcm_openmp

.PHONY: $(EXECS)
all: $(EXECS)

rcm_sequential:
	cd src; $(CC) rcm.c functions.c main_sequential.c -fopenmp -o ../bin/$@; cd ..;

rcm_openmp:
	cd src; $(CC) rcm.c functions.c main_omp.c -fopenmp -o ../bin/$@; cd ..;
