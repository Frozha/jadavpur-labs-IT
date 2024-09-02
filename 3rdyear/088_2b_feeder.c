#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>        
#include <sys/types.h>
#include <sys/stat.h>
#include<stdint.h>
#define BUFFER_SIZE 8 
#define FIFO "fifofile"
int main(){
	int32_t val = 3;
	//opening the fifo for writing end
	int32_t fd = open(FIFO, O_WRONLY);
	if(fd == -1){
		perror("fifo open failed.");
		exit(-1);
	} 
	sleep(5);
	//waiting for other end to connect to fifo
	uint32_t bytesleft = BUFFER_SIZE;
	while(bytesleft>0){
		write(fd, &val, sizeof(val));
		bytesleft-=sizeof(val);
	}
	exit(0);
}
