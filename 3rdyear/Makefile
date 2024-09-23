all: 1 2a 2b 3 4

1:088_1b.c
	gcc 088_1b.c -o 088_1b.out

2a:088_2a.c
	gcc 088_2a.c -o 088_2a.out

2b: 088_2b.c
	mkfifo fifofile
	touch datafile.bin
	touch datafileout.bin
	touch datafileoutfinal.bin
	gcc 088_2b.c -o 088_2b.out

3: 088_3.c
	gcc 088_3.c -o 088_3.out

4:088_4.c
	@echo Compiling Assignment 4
	fallocate -x -l 2MiB file.bin
	gcc 088_4.c -o 088_4.out

clean:
	rm -f *.bin fifofile *.out *.txt
