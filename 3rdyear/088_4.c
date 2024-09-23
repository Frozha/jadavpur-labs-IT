/***********************************************
 * *
 * * 	Name : Hrithvik Kondalkar
 * *	Roll : 002211001088
 * *
 * * 	Assignment 4 :
 * *	use mmap() call and observe page-fault using the ‘sar’ command.
 * *
 * 
 *      shuf for random
 * *    f = 263568
 *      x = 150
 *      fallocate -x -l 2MiB file.bin
 *
 * * 	Compilation command : gcc 088_4.c -o 088_4.out
 * * 	Exectution command  : ./088_4.out
 *                             sar -B 1
 * 
 * *
 * *
 * *	Output generated : 
 * 
02:39:33 AM  pgpgin/s pgpgout/s   fault/s  majflt/s  pgfree/s pgscank/s pgscand/s pgsteal/s    %vmeff
02:39:33 AM      0.00     12.00  11255.00   4729.00   6084.00      0.00      0.00      0.00      0.00
02:39:34 AM      0.00      0.00  10445.00   4593.00   6058.00      0.00      0.00      0.00      0.00
02:39:35 AM      0.00      0.00  10188.00   4901.00   5257.00      0.00      0.00      0.00      0.00
02:39:36 AM      0.00      0.00  10517.00   4678.00   6087.00      0.00      0.00      0.00      0.00
02:39:37 AM     16.00      0.00  12374.00   4364.00   6145.00      0.00      0.00      0.00      0.00
02:39:38 AM      0.00     12.00  14690.00   5659.00   8508.00      0.00      0.00      0.00      0.00
02:39:39 AM      0.00      0.00   9219.00   3435.00   5177.00      0.00      0.00      0.00      0.00
02:39:40 AM      0.00      0.00   2288.00      0.00   1702.00      0.00      0.00      0.00      0.00 < major faults 
02:39:41 AM      0.00      0.00    978.00      0.00    680.00      0.00      0.00      0.00      0.00
02:39:42 AM      0.00      0.00   5017.00      0.00   3033.00      0.00      0.00      0.00      0.00
02:39:43 AM      0.00     12.00   1638.00      0.00   1192.00      0.00      0.00      0.00      0.00
 ************************************************/
#include<sys/mman.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

#define FILE_SIZE 2*1024*1024 //2MiB
#define FILE_NAME "file.bin"
#define OFFSET 
#define X 150
u_int8_t* mmaddrs;
int fdr;
int fdw;
u_int64_t offset =263568;
u_int8_t x = 150;


void terminate(int sig_no){
    if(sig_no==SIGINT){    
        munmap(mmaddrs, FILE_SIZE);
        close(fdr);
        close(fdw);
        exit(0);
    } 
}

void _write(){
    offset = rand()%(FILE_SIZE);
    x = rand()%(0b11111111);
    lseek(fdw,  offset, SEEK_SET); 
    write(fdw, &x, 1);
    //printf("written %u at %d\n",x,offset);
}
int main(){

    fdw = open(FILE_NAME, O_WRONLY);
    fdr = open(FILE_NAME, O_RDONLY); 
    
    mmaddrs = (u_int8_t*) mmap(NULL,FILE_SIZE,PROT_READ,MAP_PRIVATE,fdr,0);
    signal(SIGINT, terminate);
    
    
    while(1){
        _write();
        if(mmaddrs[offset]==x){
       //     printf("read %u at %d\n",x,offset);
        }else{
            perror("wrong value read.");
            terminate(SIGINT);
        }
    }
    
}

