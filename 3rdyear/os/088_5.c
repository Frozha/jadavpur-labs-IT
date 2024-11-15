/***********************************************
 * *
 * * 	Name : Hrithvik Kondalkar
 * *	Roll : 002211001088
 * *
 * * 	Assignment 5 :
 * *	creating deadlock in threads.
 * *
 *
 *
 * * 	Compilation command : gcc -pthread 088_5.c -o 088_5.out
 * * 	Exectution command  : ./088_5.out
 * 
 * *
 
 * Deadlock Avoidance Strategy:
 * To prevent deadlock, ensure consistent lock ordering.
 * In this program, both threads acquire `lock1` first, then `lock2`.
 
 * *
 * *	Output generated : 
 * Do you want a deadlock ? (no-0 / yes-1) : 1
139356469470976 : I am deadlock thread. 
139356477863680 : random value : 3
139356444292864 : random value : 33
139356444292864 : acquired lock1
139356444292864 : acquired lock2
139356444292864 : total values : 1000, 1000 
139356444292864 : updated total values : 1033, 967 
139356444292864 : relinquished lock2
139356444292864 : relinquished lock1
139356444292864 : random value : 46
139356444292864 : acquired lock1
139356444292864 : acquired lock2
139356444292864 : total values : 1033, 967 
139356444292864 : updated total values : 1079, 921 
139356444292864 : relinquished lock2
139356444292864 : relinquished lock1
139356444292864 : random value : 10
139356444292864 : acquired lock1
139356444292864 : acquired lock2
139356444292864 : total values : 1079, 921 
139356444292864 : updated total values : 1089, 911 
139356444292864 : relinquished lock2
139356444292864 : relinquished lock1
139356444292864 : random value : 3
139356444292864 : acquired lock1
139356444292864 : acquired lock2
139356444292864 : total values : 1089, 911 
139356444292864 : updated total values : 1092, 908 
139356444292864 : relinquished lock2
139356444292864 : relinquished lock1
139356444292864 : random value : 45
139356444292864 : acquired lock1
139356444292864 : acquired lock2
139356444292864 : total values : 1092, 908 
139356444292864 : updated total values : 1137, 863 
139356444292864 : relinquished lock2
139356444292864 : relinquished lock1
139356444292864 : random value : 16
139356444292864 : acquired lock1
139356444292864 : acquired lock2
139356444292864 : total values : 1137, 863 
139356444292864 : updated total values : 1153, 847 
139356444292864 : relinquished lock2
139356444292864 : relinquished lock1
139356444292864 : random value : 37
139356444292864 : acquired lock1
139356444292864 : acquired lock2
139356444292864 : total values : 1153, 847 
139356444292864 : updated total values : 1190, 810 
139356444292864 : relinquished lock2
139356444292864 : relinquished lock1
139356444292864 : random value : 41
139356444292864 : acquired lock1
139356444292864 : acquired lock2
139356444292864 : total values : 1190, 810 
139356444292864 : updated total values : 1231, 769 
139356444292864 : relinquished lock2
139356444292864 : relinquished lock1
139356444292864 : random value : 14
139356461078272 : random value : 25
139356452685568 : I am deadlock thread. 
139356452685568 : random value : 22
139356452685568 : acquired lock2
139356477863680 : acquired lock1
139356469470976 : random value : 50
^C


 ************************************************/
#include<pthread.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#define NUM_THREADS 5
#define NUM_ITER_PER_THREAD 10


int32_t Total_1=1000;
int32_t Total_2=1000;
pthread_mutex_t lock1;
pthread_mutex_t lock2;

pthread_t tid[NUM_THREADS];

void* myroutine(void* args){
	int i = NUM_ITER_PER_THREAD;
	while(i>0){
	i--;
	long int randval = random();
	randval %=50;
	randval++;
	//randval is now between 1 and 50 inclusive;
	pthread_t thisthread = pthread_self();
	printf("%ld : random value : %ld\n",thisthread,randval);	
	
	pthread_mutex_lock(&lock1);
	printf("%ld : acquired lock1\n", thisthread);
	pthread_mutex_lock(&lock2);
	printf("%ld : acquired lock2\n", thisthread);

	printf("%ld : total values : %d, %d \n",thisthread, Total_1, Total_2);	
	Total_1+=randval;
	Total_2-=randval;
	printf("%ld : updated total values : %d, %d \n",thisthread, Total_1, Total_2);

	pthread_mutex_unlock(&lock2);
	printf("%ld : relinquished lock2\n", thisthread);
	pthread_mutex_unlock(&lock1);	
	printf("%ld : relinquished lock1\n", thisthread);


	}
	return NULL;

}

void* mydeadlockroutine(void* args) {
 	int i = NUM_ITER_PER_THREAD;
	while(i>0){
	i--;
	long int randval = random();
	randval %=50;
	randval++;
	//randval is now between 1 and 50 inclusive;
	pthread_t thisthread = pthread_self();
	printf("%ld : I am deadlock thread. \n",thisthread);	
	printf("%ld : random value : %ld\n",thisthread,randval);
	
	pthread_mutex_lock(&lock2);
	printf("%ld : acquired lock2\n", thisthread);

	pthread_mutex_lock(&lock1);
	printf("%ld : acquired lock1\n", thisthread);

	printf("%ld : total values : %d, %d \n",thisthread, Total_1, Total_2);	
	Total_1+=randval;
	Total_2-=randval;
	printf("%ld : updated total values : %d, %d \n",thisthread, Total_1, Total_2);

	pthread_mutex_unlock(&lock2);
	printf("%ld : relinquished lock2\n", thisthread);
	pthread_mutex_unlock(&lock1);	
	printf("%ld : relinquished lock1\n", thisthread);

	}
	return NULL;

}

int main(){
	srand(1123);

	if(pthread_mutex_init(&lock1, NULL)!=0){
		perror("initialization of lock1 failed");
		return 1;
	}

	if(pthread_mutex_init(&lock2, NULL)!=0){
		perror("initialization of lock2 failed");
		pthread_mutex_destroy(&lock1);
		return 1;
	}
	
	int wantdeadlock = 0;
	printf("Do you want a deadlock ? (no-0 / yes-1) : ");
	scanf("%d", &wantdeadlock);

	int i =0;
	while(i<NUM_THREADS){
		if(wantdeadlock==0||i%2==0){
			if(pthread_create(&tid[i], NULL, &myroutine, NULL)!=0){
			perror("Thread creation failed");
			while(i>=0){
				i--;
				pthread_cancel(tid[i]);
			}
			pthread_mutex_destroy(&lock2);
			pthread_mutex_destroy(&lock1);
			return 1;
			}
		}else{
			if(pthread_create(&tid[i], NULL, &mydeadlockroutine, NULL)!=0){
			perror("Thread creation failed");
			while(i>=0){
				i--;
				pthread_cancel(tid[i]);
			}
			pthread_mutex_destroy(&lock2);
			pthread_mutex_destroy(&lock1);
			return 1;
			}
		}
	i++;
	}
	i = 0;
	while(i<NUM_THREADS){
	pthread_join(tid[i],NULL);
	i++;
	}

	pthread_mutex_destroy(&lock2);
	pthread_mutex_destroy(&lock1);
	
	return 0;


}
