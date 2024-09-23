/***********************************************
 * *
 * * 	Name : Hrithvik Kondalkar
 * *	Roll : 002211001088
 * *
 * * 	Assignment 3 :
 * *	Transfer 1GB data using unix sockets bidirectionally between parent child processes.
 * *
 * *
 * * 	Compilation command : gcc 088_3.c -o 088_3.out
 * * 	Exectution command  : ./088_3.out
 * *
 * *
 * *	Output generated : 
            number of random bytes written : 4194304 
            739 : im parent process.
            parent : socket created.
            740 : im child process.
            child : socket created.
            parent : address bound.
            parent : server listening.
            child : connected.
            parent : connected.
            parent : write successful.
            parent : write time for 4194304 bytes was 0.578332 seconds.
            child : read successful.
            child : read time for 4194304 bytes was 0.540071 seconds.
            child : write successful.
            child : write time for 4194304 bytes was 0.604434 seconds.
            child : total time for 4194304 bytes duplex transfer was 0.604434 seconds.
            child : connection closed.
            parent : read successful.
            parent : read time for 4194304 bytes was 0.575924 seconds.
            parent : total time for 4194304 bytes duplex transfer was 1.154447 seconds.
            parent : connection closed.
            files original.txt and final.txt match!
 * *
 * *
 * *	ss -x | grep "assignment_server" output:
 * *	u_str ESTAB 40     0                                     assignment_server 2852826            * 2855337 
 * *	
 * *	
 * *	netstat -a | grep "assignment_server" output:
 * *	unix  2      [ ACC ]     STREAM     LISTENING     2852825  assignment_server
 * *	unix  3      [ ]         STREAM     CONNECTED     2852826  assignment_server
 
 
 ************************************************/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/un.h>
#include<stddef.h>
#include<string.h>
#include<time.h>
#include<stdint.h>

#define SERVE_PATH "assignment_server"
#define ORIGINAL_FILE "original.txt"
#define TEMP_FILE "temp.txt"
#define FINAL_FILE "final.txt"
#define DATA_TRANSFER_SIZE 4*1024*1024
#define BACKLOG 50 // define a constant for the backlog value

void write_random_file(const char* datafilepath){
    FILE* datafp = fopen(datafilepath, "wb");
    if (!datafp) {
        perror("fopen failed");
        exit(1);
    }
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
    write_random_file(ORIGINAL_FILE);
    pid_t childpid = fork();
    if(childpid<0){
        perror("child process creation failed.");
    }else if  (childpid>0){
        printf("%d : im parent process.\n",getpid());

        //socket creation
        int parent_fd = socket(AF_UNIX, SOCK_STREAM, 0);
        if(parent_fd==-1){
            perror("parent : socket creation failed.");
            exit(1);
        }
        printf("parent : socket created.\n");

        //binding address
        struct sockaddr_un paddr;
        memset(&paddr, 0, sizeof(paddr));
        paddr.sun_family = AF_UNIX;
        strncpy(paddr.sun_path, SERVE_PATH, sizeof(paddr.sun_path)-1);
        if(bind(parent_fd, (struct sockaddr*)&paddr, sizeof(paddr))==-1){
            perror("parent : bind failed.");
            exit(1);
        }
        printf("parent : address bound.\n");

        //listening on server begins
        if(listen(parent_fd, BACKLOG)==-1){
            perror("parent : listen failed.");
            exit(1);
        }

        struct sockaddr_un caddr;
        int caddrsize = sizeof(caddr);
        printf("parent : server listening.\n");
        int child_fd = accept(parent_fd,(struct sockaddr*)&caddr, &caddrsize);
        if(child_fd == -1){
            perror("parent : couldn't accept child connection.");
            exit(1);
        }
        printf("parent : connected.\n");

        FILE* datafp = fopen(ORIGINAL_FILE, "rb");
        if (!datafp) {
            perror("fopen failed");
            exit(1);
        }
        clock_t start1, start2, end;
        int32_t i = 0;
        start1 = clock();
        u_int32_t bytestransfered = 0;
        int32_t data;
        while(bytestransfered<DATA_TRANSFER_SIZE){
            i= fread(&data, sizeof(int32_t), 1, datafp);
            bytestransfered+=write(child_fd, &data, i*sizeof(int32_t));
        }
        end = clock();
        fclose(datafp);

        printf("parent : write successful.\n");
        printf("parent : write time for %d bytes was %f seconds.\n",bytestransfered, ((double)(end-start1)/CLOCKS_PER_SEC));

        datafp = fopen(FINAL_FILE, "wb");
        if (!datafp) {
            perror("fopen failed");
            exit(1);
        }
        bytestransfered =0;
        u_int32_t bytesread;
        int32_t val;
        start2 = clock();
        while(bytestransfered<DATA_TRANSFER_SIZE){
            bytesread = read(child_fd, &val, sizeof(val));
            bytestransfered+=bytesread;
            fwrite(&val, sizeof(int32_t), 1, datafp);
        }
        end = clock();
        fclose(datafp);

        printf("parent : read successful.\n");
        printf("parent : read time for %d bytes was %f seconds.\n",bytestransfered, ((double)(end-start2)/CLOCKS_PER_SEC));

        if(unlink(SERVE_PATH) == -1){
            fprintf(stderr, "parent : unlink was unsuccessful for path %s", SERVE_PATH);
        }
        if(close(parent_fd)==-1){
            fprintf(stderr, "parent : file descriptor %d could not be closed.", parent_fd);
        }
        printf("parent : total time for %d bytes duplex transfer was %f seconds.\n",DATA_TRANSFER_SIZE, ((double)(end-start1)/CLOCKS_PER_SEC));
        printf("parent : connection closed.\n");
    }else{
        printf("%d : im child process.\n",getpid());

        //socket creation
        int child_fd = socket(AF_UNIX, SOCK_STREAM, 0);
        if(child_fd == -1){
            perror("child : socket creation failed");
            exit(1);
        }
        printf("child : socket created.\n");
        sleep(1);

        //preparing server address to connect to
        struct sockaddr_un serveaddr;
        memset(&serveaddr, 0, sizeof(serveaddr));
        serveaddr.sun_family = AF_UNIX;
        strncpy(serveaddr.sun_path, SERVE_PATH, sizeof(serveaddr.sun_path)-1);

        //connect socket to server address
        if(connect(child_fd, (struct sockaddr*)&serveaddr, sizeof(serveaddr))==-1){
            perror("child : connect failed.");
            exit(1);
        }
        printf("child : connected.\n");

        clock_t start1, end;

        start1 = clock();
        FILE* datafp = fopen(TEMP_FILE, "wb");
        if (!datafp) {
            perror("fopen failed");
            exit(1);
        }
        u_int32_t bytestransfered =0;
        u_int32_t bytesread;
        int32_t val;
        while(bytestransfered<DATA_TRANSFER_SIZE){
            bytesread = read(child_fd, &val, sizeof(val));
            bytestransfered+=bytesread;
            fwrite(&val, sizeof(int32_t), 1, datafp);
        }
        end = clock();
        fclose(datafp);

        printf("child : read successful.\n");
        printf("child : read time for %d bytes was %f seconds.\n",bytestransfered, ((double)(end-start1)/CLOCKS_PER_SEC));

        start1 = clock();

        datafp = fopen(TEMP_FILE, "rb");
        if (!datafp) {
            perror("fopen failed");
            exit(1);
        }
        bytestransfered = 0;
        int32_t data;
        while(bytestransfered<DATA_TRANSFER_SIZE){
            fread(&data, sizeof(int32_t), 1, datafp);
            bytestransfered+=write(child_fd, &data, sizeof(int32_t));
        }
        end = clock();
        fclose(datafp);

        printf("child : write successful.\n");
        printf("child : write time for %d bytes was %f seconds.\n",bytestransfered, ((double)(end-start1)/CLOCKS_PER_SEC));

        if(close(child_fd)==-1){
            fprintf(stderr, "child : socket closing failed %d", child_fd);
        }
        printf("child : total time for %d bytes duplex transfer was %f seconds.\n",DATA_TRANSFER_SIZE, ((double)(end-start1)/CLOCKS_PER_SEC));
        printf("child : connection closed.\n");

        exit(0);
    }

	compare_files(ORIGINAL_FILE, FINAL_FILE);
    return 0;
}