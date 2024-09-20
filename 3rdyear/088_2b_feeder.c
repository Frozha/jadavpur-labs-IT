/***********************************************
 * *
 * * 	Name : Hrithvik Kondalkar
 * *	Roll : 002211001088
 * *
 * * 	Assignment 2b :
 * *	Transfer 1GB data using fifo file bidirectionally between 2 processes.
 * *
 * *
 * * 	Compilation command : make 2b
 * *	[refer to makefile for detailed compilation instructions]
 * * 	Exectution command  : ./088_2b_feeder.out
 * *	[both feeder and eater need to be executing to exchange data
 * *	in case of either is not running the running program will be blocked
 * *	the pipe will be blocked till other end is opened.]
 * *
 * *	Output generated : 
 * *	16357 : 60.314208 seconds for sending 1073741824 bytes data.
 * *	16357 : 60.792217 seconds for recieving 1073741824 bytes data.
 * *	16357 : 121.106648 seconds for entire double transfer of 1073741824 bytes.	
 * *
 * *
 * *	ls -l output:
 * *	
 
 
 ************************************************/
#include"exlib/088_2b.h"

int main(){
	clock_t start, end;
	start = clock();
	send__(28932);
	recieve__(28932);
	end = clock();
	printf("%d : %f seconds for entire double transfer of %d bytes.\n",getpid(), ((double) (end - start)) / CLOCKS_PER_SEC, DATA_TRANSFER_SIZE);
}
