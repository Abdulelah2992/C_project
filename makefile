filename = ""

all: assembler simulate

simulate: main.c alu.c mux.c decoder.c decoderfunction.c
	@gcc -c main.c alu.c mux.c decoder.c decoderfunction.c
	@gcc -o test_exe main.c alu.c mux.c decoder.c decoderfunction.c
	@./test_exe $(filename)

assembler: assembler.c code.c
	@gcc -c assembler.c code.c
	@gcc -o assembler assembler.o code.o
	@./assembler $(filename)

clean:
	rm -f fibonacci.bin assembler assembler.o code.o

help:
	@echo "assembler filename=file.asm: compile assembler code by read what file you want"
	@echo "clean : delete fibonacci.bin assembler assembler.o code.o"
