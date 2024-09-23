/***********************************************************************
 * *
 * * 	Name : Hrithvik Kondalkar
 * *	Roll : 002211001088
 * *	Date : 5th aug 2024
 * *
 * * 	Assignment 2a :
 * *	Catch the signal ‘SIGINT’ and display “Ha Ha, Not Stopping”.
 * *	Use ‘signal’ system call. 
 * *	Always use “perror” to check the return status of a library/system call.
 * *
 * *
 * * 	Compilation command : gcc 088_2a.c -o 088_2a.out
 * * 	Exectution command  : ./088_2a.out
 * *
 * *
 * * 	Output Generated:
 * *	free to press Ctrl+c 5 times before exiting
 * *	^CHa Ha, Not Stopping.
 * *	^CHa Ha, Not Stopping.
 * *	^CHa Ha, Not Stopping.
 * *	^CHa Ha, Not Stopping.
 * *	^CHa Ha, Not Stopping.
 * *	^Cresetting Ctrl+c's function
 * *	^C
 * *
 * ***********************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

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
