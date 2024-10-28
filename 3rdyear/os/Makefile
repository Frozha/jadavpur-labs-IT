all: 1b 2a 2b 3 4

1b:088_1b.c
	gcc 088_1b.c -o 088_1b.out

2a:088_2a.c
	gcc 088_2a.c -o 088_2a.out

2b: 088_2b.c
	mkfifo fifofile
	fallocate -l 1G /usr/tmp/datafile.bin
	fallocate -l 1G /usr/tmp/datafileout.bin
	fallocate -l 1G /usr/tmp/datafileoutfinal.bin
	gcc 088_2b.c -o 088_2b.out

3: 088_3.c
	gcc 088_3.c -o 088_3.out

4:088_4.c
	@echo Compiling Assignment 4
	fallocate -l 1G /usr/tmp/file.bin
	gcc 088_4.c -o 088_4.out
5: 088_5.c
	@echo Compiling Assignment 5
	gcc 088_5.c -pthread -o 088_5.out

7: 088_7.c
	@echo Compiling Assignment 7
	gcc 088_7.c -pthread -o 088_7.out

clean:
	rm -f *.bin fifofile *.out *.txt

clean_tmp: 
	rm -f /usr/tmp/datafile.bin /usr/tmp/datafileout.bin /usr/tmp/datafileoutfinal.bin
	rm -f /usr/tmp/original.txt /usr/tmp/final.txt /usr/tmp/temp.txt
	rm -f /usr/tmp/file.bin

