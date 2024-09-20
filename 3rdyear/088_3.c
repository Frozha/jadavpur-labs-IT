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
 * *	40139 : im parent process.
 * *	parent : socket created.
 * *	40140 : im child process.
 * *	child : socket created.
 * *	parent : address bound.
 * *	parent : server listening.
 * *	child : connected.
 * *	parent : connected.
 * *	parent : write successful.
 * *	child : read successful.
 * *	parent : write time for 1073741824 bytes was 128.492855 seconds.
 * *	child : read time for 1073741824 bytes was 128.848543 seconds.
 * *	child : write successful.
 * *	child : write time for 1073741824 bytes was 136.203522 seconds.
 * *	child : total time for 1073741824 bytes duplex transfer was 265.052080 seconds.
 * *	child : connection closed.
 * *	parent : read successful.
 * *	parent : read time for 1073741824 bytes was 136.199118 seconds.
 * *	parent : total time for 1073741824 bytes duplex transfer was 264.692027 seconds.
 * *	parent : connection closed.
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
#include<sys/un.h>
#include<stddef.h>
#include<string.h>
#include<time.h>

#define SERVE_PATH "assignment_server"
#define DATA_SIZE 1024*1024*1024

	
int main(){
	pid_t childpid = fork();
	if(childpid<0){
		perror("child process creation failed.");
	}else if(childpid==0){
		printf("%d : im child process.\n",getpid());
		//socket creation		
		int sfd = socket(AF_UNIX, SOCK_STREAM, 0);
		if(sfd == -1){perror("child : socket creation failed");}
		printf("child : socket created.\n");
		sleep(1);

		//preparing server address to connect to
		struct sockaddr_un serveaddr;
		memset(&serveaddr, 0, sizeof(serveaddr));
		serveaddr.sun_family = AF_UNIX;
		strncpy(serveaddr.sun_path, SERVE_PATH, sizeof(serveaddr.sun_path)-1);
		
		//connect socket to server address
		if(connect(sfd, (struct sockaddr*)&serveaddr, sizeof(serveaddr))==-1){
			perror("child : connect failed.");
		}
		printf("child : connected.\n");
		
		clock_t start1, start2, end;

		int32_t i = 0;
		int32_t recv_data;
		start1 = clock();
		for(i=0;i<DATA_SIZE;i=i+sizeof(int32_t)){
			read(sfd, &recv_data, sizeof(int32_t));
			if(recv_data!=i){fprintf(stderr, "child : incorrect data read : %d\n",recv_data);}
		}
		end = clock();
		printf("child : read successful.\n");
		printf("child : read time for %d bytes was %f seconds.\n",DATA_SIZE, ((double)(end-start1)/CLOCKS_PER_SEC));
		start2 = clock();
		for(i=0;i<DATA_SIZE;i=i+sizeof(int32_t)){
			write(sfd, &i, sizeof(int32_t));
		}
		end = clock();
		printf("child : write successful.\n");
		printf("child : write time for %d bytes was %f seconds.\n",DATA_SIZE, ((double)(end-start2)/CLOCKS_PER_SEC));

		if(close(sfd)==-1){
			fprintf(stderr, "child : socket closing failed %d", sfd);
		}
		printf("child : total time for %d bytes duplex transfer was %f seconds.\n",DATA_SIZE, ((double)(end-start1)/CLOCKS_PER_SEC));
		printf("child : connection closed.\n");

		exit(0);
	}else{
		printf("%d : im parent process.\n",getpid());
		

		//socket creation	
		int pfd = socket(AF_UNIX, SOCK_STREAM, 0);
		if(pfd==-1){perror("parent : socket creation failed.");}
		printf("parent : socket created.\n");


		//binding address
		struct sockaddr_un paddr;
		memset(&paddr, 0, sizeof(paddr));
		paddr.sun_family = AF_UNIX;
		strncpy(paddr.sun_path, SERVE_PATH, sizeof(paddr.sun_path)-1);
		if(bind(pfd, (struct sockaddr*)&paddr, sizeof(paddr))==-1){
			perror("parent : bind failed.");
		}
		printf("parent : address bound.\n");


		//listening on server begins	
		if(listen(pfd, 50)==-1){perror("parent : listen failed.");}		
		
		struct sockaddr_un caddr;
		int caddrsize = sizeof(caddr);
		printf("parent : server listening.\n");
		int cfd = accept(pfd,(struct sockaddr*)&caddr, &caddrsize);
		if(cfd == -1){perror("parent : couldn't accept child connection.");} 
		printf("parent : connected.\n");

		clock_t start1, start2, end;
		int32_t i = 0;
		start1 = clock();
		for(i=0;i<DATA_SIZE;i=i+sizeof(int32_t)){
			write(cfd, &i, sizeof(int32_t));
		}
		end = clock();
		printf("parent : write successful.\n");
		printf("parent : write time for %d bytes was %f seconds.\n",DATA_SIZE, ((double)(end-start1)/CLOCKS_PER_SEC));
		int32_t recv_data;
		start2 = clock();
		for(i=0;i<DATA_SIZE;i=i+sizeof(int32_t)){
			read(cfd, &recv_data, sizeof(int32_t));
			if(recv_data!=i){fprintf(stderr, "parent : incorrect data read : %d\n",recv_data);}
		}
		end = clock();
		printf("parent : read successful.\n");
		printf("parent : read time for %d bytes was %f seconds.\n",DATA_SIZE, ((double)(end-start2)/CLOCKS_PER_SEC));
		if(unlink(SERVE_PATH) == -1){
			fprintf(stderr, "parent : unlink was unsuccessful for path %s", SERVE_PATH);
		}
		if(close(pfd)==-1){
			fprintf(stderr, "parent : file descriptor %d could not be closed.", pfd);
		}
		printf("parent : total time for %d bytes duplex transfer was %f seconds.\n",DATA_SIZE, ((double)(end-start1)/CLOCKS_PER_SEC));
		printf("parent : connection closed.\n");
	}

}
