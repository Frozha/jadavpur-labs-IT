#include"088_2b.h"

int send__(const int32_t data){
    int32_t fd = open(FIFO, O_WRONLY);
	if(fd == -1){
		perror("fifo write open failed.");
		return (-1);
	} 

	clock_t start, end;

	uint32_t bytesleft = DATA_TRANSFER_SIZE;
	start = clock();
	while(bytesleft>0){
		write(fd, &data, sizeof(data));
		bytesleft-=sizeof(data);
	}
	end = clock();
	printf("%d : %f seconds for sending %d bytes data.\n",getpid(), ((double) (end - start)) / CLOCKS_PER_SEC, DATA_TRANSFER_SIZE);
	close(fd);
	return (0);
}

int recieve__(const int32_t data_expected){
	int32_t fd = open(FIFO, O_RDONLY);
    if(fd == -1){
        perror("fifo read open failed.");
        return(-1);
    }

    clock_t start, end;

	uint32_t bytesleft = DATA_TRANSFER_SIZE;
    uint32_t bytesread;
    start = clock();
	int32_t val;
	while(bytesleft>0){
        bytesread = read(fd, &val, sizeof(val));
		if(val!=data_expected){
            perror("wrong data read.");
        }
        bytesleft-=bytesread;
    }
    end = clock();
    printf("%d : %f seconds for recieving %d bytes data.\n",getpid(), ((double) (end - start)) / CLOCKS_PER_SEC, DATA_TRANSFER_SIZE);
    close(fd);
    return (0);
}