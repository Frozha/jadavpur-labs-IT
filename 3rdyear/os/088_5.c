#include<pthread.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#define NUM_THREADS 10
#define NUM_ITER_PER_THREAD 5
#define NUM_GLOBAL_VARS

int32_t Total[NUM_GLOBAL_VARS];
pthread_mutex_t lock[NUM_GLOBAL_VARS];


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
	printf("%d : random value : %d\n",thisthread,randval);	
	
	pthread_mutex_lock(&lock1);
	printf("%d : acquired lock1\n", thisthread);
	pthread_mutex_lock(&lock2);
	printf("%d : acquired lock2\n", thisthread);

	printf("%d : total values : %d, %d \n",thisthread, Total_1, Total_2);	
	Total_1+=randval;
	Total_2-=randval;
	printf("%d : updated total values : %d, %d \n",thisthread, Total_1, Total_2);

	pthread_mutex_unlock(&lock2);
	printf("%d : relinquished lock2\n", thisthread);
	pthread_mutex_unlock(&lock1);	
	printf("%d : relinquished lock1\n", thisthread);
	
	
	}
	return NULL;

}

int main(){
	srandom(1402);

	if(pthread_mutex_init(&lock1, NULL)!=0){
		perror("initialization of lock1 failed");
		return 1;
	}

	if(pthread_mutex_init(&lock2, NULL)!=0){
		perror("initialization of lock2 failed");
		pthread_mutex_destroy(&lock1);
		return 1;
	}
	
	int i =0;
	while(i<NUM_THREADS){
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
