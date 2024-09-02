#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<stdint.h>
#define BUFFER_SIZE 8
#define FIFO "fifofile"
int main(){
        int32_t val;
	int32_t fd = open(FIFO, O_RDONLY);
        if(fd == -1){
                perror("fifo open failed.");
                exit(-1);
        }
	uint32_t bytesleft = BUFFER_SIZE;
        uint32_t bytesread;
	while(bytesleft>0){
                bytesread = read(fd, &val, sizeof(val));
		if(bytesread==-1){//didnt read
			printf("couldn't read from fifo");
			sleep(1);
		}
		printf("%d\n", val);
		sleep(1);
                bytesleft-=bytesread;
        }
        exit(0);
}

