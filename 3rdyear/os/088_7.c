#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<pthread.h>

typedef struct{
	double A;
	double B;
	double C;
	double D;
	double E;
}result_structure;

result_structure result;

//initialize to -21;
void reset_result(){
	result.A = -21;
	result.B = -21;
	result.C = -21;
	result.D = -21;
	result.E = -21;
}
void view_result(){
	printf("\tA\t|\tB\t|\tC\t|\tD\t|\tE\t\n");
	printf("%f\t%f\t%f\t%f\t%f\n", result.A, result.B, result.C, result.D, result.E);
	return;
}
double X;
double Y;

void reset_X_Y(){
	long rand = random();
	X = rand%10;
	rand = random();
	Y = rand%10;	
	return;
}

void view_X_Y(){
	printf("X : %f\nY : %f\n", X,Y);
	return;
}

pthread_t tid[3];

void calculateA(){//thread 1
	result.A = X*Y;
	return; 
}

void calculateB(){//thread 2
	//A needs to be computed by thread 1 before this runs
	result.B = (result.A)/2;
	return;
} 

void calculateC(){//thread 3
	result.C = X+Y;
	return;
}

void calculateD(){//thread 2
	// A and C must be computed by thread 1 and thread 3 before this runs;
	result.D = result.A/result.C;
	return;
}

void calculateE(){//thread 1
	//A will be computed by same thread before so no synchronization reqd;
	result.E = (result.A)/(X-Y);
	return;
}

sigset_t mysignalA;
sigset_t mysignalC;


void* thread1funct(void* args){
	calculateA();
	pthread_kill(tid[1], SIGUSR1);	
	calculateE();
	return NULL;
}

void* thread2funct(void* args){
	int sigrecvd;
	if(result.A==-21){
		sigwait(&mysignalA, &sigrecvd);
	}
	calculateB();
	if(result.C==-21){
		sigwait(&mysignalC, &sigrecvd);
	}
	calculateD();
	return NULL;
}

void* thread3funct(void* args){
	calculateC();
	pthread_kill(tid[1], SIGUSR2);
	return NULL;
}

int main(){
	reset_result();
	reset_X_Y();
	
	sigemptyset(&mysignalA);
	sigaddset(&mysignalA, SIGUSR1);

	sigemptyset(&mysignalC);
	sigaddset(&mysignalC, SIGUSR2);

	pthread_sigmask(SIG_BLOCK, &mysignalA, NULL);
	pthread_sigmask(SIG_BLOCK, &mysignalC, NULL);

	pthread_create(&tid[0], NULL, &thread1funct, NULL);
	pthread_create(&tid[1], NULL, &thread2funct, NULL);
	pthread_create(&tid[2], NULL, &thread3funct, NULL);
	
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	
	view_X_Y();
	view_result();	
	return 0;
}
