CC=gcc
# CFLAGS=-I$(IDIR)

../ebin/naive_c_port: naive_c_port.c naive_solution.o array_list.o
	$(CC) -o ../ebin/naive_c_port naive_c_port.c naive_solution.c array_list.c

.PHONY: clean

clean:
	rm -f *.o ../ebin/naive_c_port