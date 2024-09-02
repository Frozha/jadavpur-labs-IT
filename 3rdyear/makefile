all: 1

1:088_1b.c
	@echo Compiling Assignment 1b.
	gcc 088_1b.c -o 088_1b.out

2a:088_2a.c
	@echo Compiling Assignment 2a.
	gcc 088_2a.c -o 088_2a.out
2b:088_2b_eater.c 088_2b_feeder.c
	@echo Compiling Assignment 2b.
	gcc 088_2b_eater.c -o 088_2b_eater.out
	gcc 088_2b_feeder.c -o 088_2b_feeder.out
	mkfifo --mode=0600 fifofile 
	
clean: 
	@echo Cleaning out files
	rm *.out
	rm fifofile

