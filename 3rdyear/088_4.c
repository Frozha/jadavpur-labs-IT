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
 * *
 * *

 
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
    printf("written %u at %d\n",x,offset);
}
int main(){

    fdw = open(FILE_NAME, O_WRONLY);
    fdr = open(FILE_NAME, O_RDONLY); 
    
    mmaddrs = (u_int8_t*) mmap(NULL,FILE_SIZE,PROT_READ,MAP_PRIVATE,fdr,0);
    signal(SIGINT, terminate);
    
    
    while(1){
        _write();
        if(mmaddrs[offset]==x){
            printf("read %u at %d\n",x,offset);
        }else{
            perror("wrong value read.");
            terminate(SIGINT);
        }
    }
    
}

