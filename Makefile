test:
	gcc -c main.c alu.c mux.c
	gcc -o test_exe main.c alu.c mux.c
	./test_exe
