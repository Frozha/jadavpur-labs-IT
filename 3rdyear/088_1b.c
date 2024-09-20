/***********************************************************************
 * *
 * * 	Name : Hrithvik Kondalkar
 * *	Roll : 002211001088
 * *	Date : 5th aug 2024
 * *
 * * 	Assignment 1b :
 * *	Program to GET and SET the Environment variable and to know 
 * *	use of getenv and setenv system calls
 * *
 * *
 * * 	Compilation command : gcc 088_1b.c -o 088_1b.out
 * * 	Exectution command  : ./088_1b.out
 * *
 * *
 * * 	Output Generated:
 * 	reading system variables.
 *
 * 	USER : be2288
 * 	HOME : /home/usr/student/ug/yr22/be2288
 * 	HOST : null(HOST env variable was not found)
 * 	ARCH : null(ARCH env variable was not found)
 * 	DISPLAY : null(DISPLAY env variable was not found)
 * 	PRINTER : null(PRINTER env variable was not found)
 * 	PATH : /usr/lib64/qt-3.3/bin:/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/home/usr/student/ug/yr22/be2288/.local/bin:/home/usr/student/ug/yr22/be2288/bin
 * 	writing env variables.
 *
 * 	MYENV1 : env1val
 * 	MYENV2 : env2val
 * *
 * ***********************************************************************/

#include<stdlib.h>
#include<stdio.h>

void printenv(const char* env){
	const char* envbl =  getenv(env);
	if(envbl==NULL){
		printf("null(%s env variable was not found)", env);
	}else{
		printf("%s", envbl);
	}
}

int main(int a, char* ac){
	printf("reading system variables.\n");
	printf("\nUSER : ");
	printenv("USER");
	printf("\nHOME : ");
	printenv("HOME");
	printf("\nHOST : ");
	printenv("HOST");
	printf("\nARCH : ");
	printenv("ARCH");
	printf("\nDISPLAY : ");
	printenv("DISPLAY");
	printf("\nPRINTER : ");
	printenv("PRINTER");
	printf("\nPATH : ");
	printenv("PATH");
	printf("\n");
	printf("writing env variables.\n");
	setenv("MYENV1", "env1val", 1);
	printf("\nMYENV1 : ");
	printenv("MYENV1");	
	setenv("MYENV2", "env2val", 1);
	printf("\nMYENV2 : ");
	printenv("MYENV2");
	printf("\n");
}
