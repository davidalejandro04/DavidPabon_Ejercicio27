EXECS=hello mpisend_recv
MPICC?=mpicc

all: ${EXECS}

mpisend_recv: mpisend_recv.c
	${MPICC} -o mpisend_recv mpisend_recv.c

hello: hello.c
	${MPICC} -o hello hello.c

clean:
	rm -f ${EXECS}
