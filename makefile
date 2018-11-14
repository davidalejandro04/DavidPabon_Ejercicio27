exes=hello mpisend_recv sample

all: ${exes}

mpisend_recv: mpisend_recv.c
	mpicc -o mpisend_recv mpisend_recv.c

hello: hello.c
	mpicc -o hello hello.c

sample: sample.cpp
	mpiCC -o sample sample.cpp

clean:
	rm -f ${exes}
