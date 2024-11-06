filename = ""

all: assembler simulate


assembler: assembler.c code.c
	@gcc -c assembler.c code.c
	@gcc -o assembler assembler.o code.o
	@./assembler $(filename)

clean:
	rm -f fibonacci.bin assembler assembler.o code.o

help:
	@echo "assembler filename=file.asm: compile assembler code by read what file you want"
	@echo "clean : delete fibonacci.bin assembler assembler.o code.o"
