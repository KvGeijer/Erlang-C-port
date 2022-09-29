CC=gcc
ERL_PATH=/opt/homebrew/lib/erlang/erts-13.0.4/include

.PHONY: all clean naive_port naive_nif


all: ../ebin/naive_c_port ../ebin/naive_c_nif.so

naive_port: ../ebin/naive_c_port

naive_nif: ../ebin/naive_c_nif.so


../ebin/naive_c_port: naive_c_port.c naive_solution.o array_list.o
	$(CC) -o ../ebin/naive_c_port naive_c_port.c naive_solution.c array_list.c

../ebin/naive_c_nif.so: naive_c_nif.c naive_solution.o array_list.o
	$(CC) -undefined dynamic_lookup -dynamiclib -o ../ebin/naive_c_nif.so -I$(ERL_PATH) -fpic -shared naive_c_nif.c naive_solution.c array_list.c

clean:
	rm -f *.o ../ebin/naive_c_nif ../ebin/naive_c_port
