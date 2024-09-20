all: 1 

1:088_1b.c
	@echo Compiling Assignment 1b.
	gcc 088_1b.c -o 088_1b.out

2a:088_2a.c
	@echo Compiling Assignment 2a.
	gcc 088_2a.c -o 088_2a.out

2b:088_2b_eater.c 088_2b_feeder.c
	@echo Compiling Assignment 2b.
	gcc -c ./exlib/088_2b.c -o ./exlib/088_2b.out
	gcc 088_2b_eater.c ./exlib/088_2b.out -o 088_2b_eater.out
	gcc 088_2b_feeder.c ./exlib/088_2b.out -o 088_2b_feeder.out
	mkfifo --mode=0600 fifofile 
	ls -l

3:088_3.c
	@echo Compiling Assignment 3
	gcc 088_3.c -o 088_3.out

4:088_4.c
	@echo Compiling Assignment 4
	fallocate -x -l 2MiB file.bin
	gcc 088_4.c -o 088_4.out

clean: 
	@echo Cleaning out files
	rm -fr *.out fifofile assignment_server file.bin


