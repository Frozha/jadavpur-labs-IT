#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<stddef.h>
#include<string.h>

#define pservepath "parentserver"
#define numbr 1024

void send_data(int reciever_fd){
	//sending 1 to numbr numbers
	int i = 1;
	int buffer[numbr];
	memset(&buffer, 0, sizeof(int)*numbr);
	for(i=1;i<=numbr;i++){
		buffer[i-1] = i;
	}
	write(reciever_fd, &buffer, numbr*sizeof(int));
}
int verify_data(char data[]);


int main(){
	pid_t childpid = fork();
	if(childpid<0){
		perror("child process creation failed.");
	}else if(childpid==0){
		printf("im child process.\n");
		sleep(1);
				
		int sfd = socket(AF_UNIX, SOCK_STREAM, 0);
		if(sfd == -1){
			perror("child : socket creation failed");
		}
		printf("child : socket created.\n");

		struct sockaddr_un serveaddr;
		memset(&serveaddr, 0, sizeof(serveaddr));
		serveaddr.sun_family = AF_UNIX;
		strncpy(serveaddr.sun_path, pservepath, sizeof(serveaddr.sun_path)-1);
		
		if(connect(sfd, (struct sockaddr*)&serveaddr, sizeof(serveaddr))==-1){
			perror("child : connect failed.");
		}
		printf("child : connected.\n");
		
		send_data(sfd);	
		

		if(close(sfd)==-1){
			fprintf(stderr, "child : socket closing failed %d", sfd);
		}
		printf("child : connection closed.");

		exit(0);
	}else{
		printf("im parent process.\n");
		

		//socket creation	
		int pfd = socket(AF_UNIX, SOCK_STREAM, 0);
		if(pfd==-1){
			perror("parent : socket creation failed.");
			exit(1);
		}
		printf("parent : socket created.\n");


		//binding address
		struct sockaddr_un paddr;
		memset(&paddr, 0, sizeof(paddr));
		paddr.sun_family = AF_UNIX;
		strncpy(paddr.sun_path, pservepath, sizeof(paddr.sun_path)-1);
		if(bind(pfd, (struct sockaddr*)&paddr, sizeof(paddr))==-1){
			perror("parent : bind failed.");
		}
		printf("parent : address bound.\n");


		//listening on server begins	
		if(listen(pfd, 50)==-1){
			perror("parent : listen failed.");
		}		
		
		struct sockaddr_un caddr;
		int caddrsize = sizeof(caddr);
		printf("parent : server listening.\n");
		int cfd = accept(pfd,(struct sockaddr*)&caddr, &caddrsize);
		if(cfd == -1){
			perror("parent : couldn't accept child connection.");
		} 
		printf("parent : connected.\n");

			
		int buffer[numbr];
		read(cfd, &buffer, sizeof(int)*numbr);
		printf("parent : %d\n", buffer[1]);
		
		

		if(unlink(pservepath) == -1){
			fprintf(stderr, "parent : unlink was unsuccessful for path %s", pservepath);
		}
		if(close(pfd)==-1){
			fprintf(stderr, "parent : file descriptor %d could not be closed.", pfd);
		}
		printf("parent : connection closed.\n");
	}

}
