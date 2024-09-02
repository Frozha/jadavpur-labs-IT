#include<stdio.h>
#include<signal.h>

int count = 0;

void sig_handler(int signo){
	if(signo==SIGINT&&count<5){
		printf("Ha Ha, Not Stopping.\n");
		count++;
	}else{
		printf("resetting Ctrl+c's function\n");
		signal(SIGINT, SIG_DFL);
	}
}

int main(){
	signal(SIGINT, sig_handler);
	printf("free to press Ctrl+c 5 times before exiting\n");
	while(1){
		sleep(1);
	}
}
