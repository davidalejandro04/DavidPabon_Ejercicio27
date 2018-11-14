exes=hello mpisend_recv

all: ${exes}

mpisend_recv: mpisend_recv.c
	mpicc -o mpisend_recv mpisend_recv.c

hello: hello.c
	mpicc -o hello hello.c

clean:
	rm -f ${exes}
