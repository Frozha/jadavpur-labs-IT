/***********************************************************************
 * *
 * * 	Name : Hrithvik Kondalkar
 * *	Roll : 002211001088
 * *
 * * 	Assignment 2b :
 * *	use named pipe to perform full duplex transfer of file between
 * *    processes.
 * *
 * *
 * * 	Compilation command : gcc 088_2b.c -o 088_2b.out
 * * 	Exectution command  : 
        touch datafile.bin
        touch datafileout.bin
        touch datafileoutfinal.bin
        ./088_2b.out
 * *    
 * *
 * * 	Output Generated:
 *      number of random bytes written : 4096 
        44176 : 0.000365 seconds for sending 4096 bytes data.
        44177 : 0.000406 seconds for recieving 4096 bytes data.
        44177 : 0.000456 seconds for sending 4096 bytes data.
        44176 : 0.000374 seconds for recieving 4096 bytes data.
        files datafile.bin and datafileoutfinal.bin match!
        time for 4096 bytes duplex transfer was 0.001317 seconds.

 * ***********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>        
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdint.h>
#include<time.h>


#define DATA_TRANSFER_SIZE 4*1024 //1024 4byte ints
#define FIFO "fifofile"
#define INPUT_PATH "datafile.bin"
#define TEMP_OUTPUT_PATH "datafileout.bin"
#define OUTPUT_PATH "datafileoutfinal.bin"


int send_file(const char* datafilepath){
    FILE* datafp = fopen(datafilepath, "rb");
    int32_t fd = open(FIFO, O_WRONLY);
	if(fd == -1){
		perror("fifo write open failed.");
		return (-1);
	} 

	clock_t start, end;

	uint32_t bytestransfered = 0;
	int32_t data;
    start = clock();
	while(bytestransfered<DATA_TRANSFER_SIZE){
        fread(&data, sizeof(int32_t), 1, datafp);
		bytestransfered+=write(fd, &data, sizeof(data));
    }
    
	end = clock();
	printf("%d : %f seconds for sending %d bytes data.\n",getpid(), ((double) (end - start)) / CLOCKS_PER_SEC, bytestransfered);
	close(fd);
    fclose(datafp);
	return (0);
}

int recieve_file(const char* datafilepath){
    FILE* datafp = fopen(datafilepath, "wb");
	int32_t fd = open(FIFO, O_RDONLY);
    if(fd == -1){
        perror("fifo read open failed.");
        return(-1);
    }

    clock_t start, end;

	uint32_t bytestransfered =0;
    uint32_t bytesread;
    start = clock();
	int32_t val;
	while(bytestransfered<DATA_TRANSFER_SIZE){
        bytesread = read(fd, &val, sizeof(val));
        bytestransfered+=bytesread;
        fwrite(&val, sizeof(int32_t), 1, datafp);
    }
    end = clock();
    printf("%d : %f seconds for recieving %d bytes data.\n",getpid(), ((double) (end - start)) / CLOCKS_PER_SEC, bytestransfered);
    close(fd);
    fclose(datafp);
    return (0);
}

void write_random_file(const char* datafilepath){
    FILE* datafp = fopen(datafilepath, "wb");
    int64_t byteswritten = DATA_TRANSFER_SIZE;
    while(byteswritten>0){
        int32_t data = rand()%INT32_MAX;
        byteswritten-=sizeof(int32_t)*fwrite(&data, sizeof(int32_t), 1, datafp);
    }
    printf("number of random bytes written : %d \n", DATA_TRANSFER_SIZE-byteswritten);
    fclose(datafp);
}

void compare_files(const char* firstfilepath, const char* secondfilepath){
    FILE* firstfile = fopen(firstfilepath,"rb");
    FILE* secondfile = fopen(secondfilepath,"rb");
    int32_t val1, val2;
    fwrite(&val1, sizeof(int32_t), 1, firstfile);
    fwrite(&val1, sizeof(int32_t), 1, secondfile);
    int64_t bytesread = DATA_TRANSFER_SIZE-sizeof(int32_t);
    while (bytesread>0){
        if (val1!=val2){
            perror("file don't match.");
            return;
        }
    fwrite(&val1, sizeof(int32_t), 1, firstfile);
    fwrite(&val1, sizeof(int32_t), 1, secondfile);
    bytesread-=sizeof(int32_t);
    }
    printf("files %s and %s match!\n", firstfilepath, secondfilepath);
    fclose(firstfile);
    fclose(secondfile);
}

int main(){
    mknod(FIFO, S_IFIFO|0666,0);
    write_random_file(INPUT_PATH);
    clock_t start, end;
    if(fork()!=0){//parent
        start = clock();
        send_file(INPUT_PATH);
        recieve_file(OUTPUT_PATH);
        end = clock();
    }else{//child
        recieve_file(TEMP_OUTPUT_PATH);
        send_file(TEMP_OUTPUT_PATH);
        exit(0);
    }
    compare_files(INPUT_PATH, OUTPUT_PATH);
    printf("time for %d bytes duplex transfer was %f seconds.\n",DATA_TRANSFER_SIZE, ((double)(end-start)/CLOCKS_PER_SEC));

}