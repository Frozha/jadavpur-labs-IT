#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>        
#include<sys/types.h>
#include<sys/stat.h>
#include<stdint.h>
#include<unistd.h>
#include<time.h>

#define DATA_TRANSFER_SIZE 1024*1024*1024
#define FIFO "fifofile"

int send__(int32_t data);

int recieve__(int32_t data_expected);

