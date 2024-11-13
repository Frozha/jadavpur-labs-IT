/***********************************************
 * *
 * * 	Name : Hrithvik Kondalkar
 * *	Roll : 002211001088
 * *
 * * 	Assignment 7 :
 * *	producer and comsumer thread synchronization and shared memory.
 * *
 *
 *
 * * 	Compilation command : gcc -pthread 088_7.c -o 088_7.out
 * * 	Exectution command  : ./088_7.out
 * 
 * *
 * *
 * *	Output generated : 
 * 
Pairs(X,Y)              |       A       |       B       |       C       |       D       |       E
——————————————————————————————————————————————————————————————————————
(3.000000, 6.000000)    | 18.000000     | 9.000000      | 9.000000      | 2.000000      | -27.000000
(7.000000, 5.000000)    | 35.000000     | 17.500000     | 12.000000     | 2.916667      | 24.000000
(3.000000, 5.000000)    | 15.000000     | 7.500000      | 8.000000      | 1.875000      | -16.000000
(6.000000, 2.000000)    | 12.000000     | 6.000000      | 8.000000      | 1.500000      | 32.000000
(9.000000, 1.000000)    | 9.000000      | 4.500000      | 10.000000     | 0.900000      | 80.000000

Shared memory status:

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 0          be2288 	 666        280        1                       

 ************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

typedef struct {
    double A;
    double B;
    double C;
    double D;
    double E;
} result_structure;

typedef struct {
    double X;
    double Y;
    result_structure result;
} data;

// Shared memory ID and pointer
int shmid;
data *pairs;

// Number of pairs
int num_pairs;

// Semaphore declarations
sem_t sem_a, sem_c;

pthread_t tid[3];

// Function to initialize result fields to -21
void reset_result(result_structure *res) {
    res->A = -21;
    res->B = -21;
    res->C = -21;
    res->D = -21;
    res->E = -21;
}

// Function to compute and display results for all pairs
void display_results() {
    printf("Pairs(X,Y)\t\t|\tA\t|\tB\t|\tC\t|\tD\t|\tE\t\n");
    printf("——————————————————————————————————————————————————————————————————————\n");
    for (int i = 0; i < num_pairs; i++) {
        printf("(%f, %f)\t| %f\t| %f\t| %f\t| %f\t| %f\n",
               pairs[i].X, pairs[i].Y,
               pairs[i].result.A, pairs[i].result.B, pairs[i].result.C,
               pairs[i].result.D, pairs[i].result.E);
    }
}

// Computation functions
void calculateA(data *d) { d->result.A = d->X * d->Y; }
void calculateB(data *d) { d->result.B = d->result.A / 2; }
void calculateC(data *d) { d->result.C = d->X + d->Y; }
void calculateD(data *d) { d->result.D = d->result.A / d->result.C; }
void calculateE(data *d) { d->result.E = (d->X + d->Y) * (d->X - d->Y); }

// Producer: Thread 1 function
void* thread1funct(void* args) {
    for (int i = 0; i < num_pairs; i++) {
        calculateA(&pairs[i]);
        sem_post(&sem_a); // Signal that A is ready
        calculateE(&pairs[i]);
    }
    return NULL;
}

// Consumer: Thread 2 function
void* thread2funct(void* args) {
    for (int i = 0; i < num_pairs; i++) {
        sem_wait(&sem_a); // Wait for A to be ready
        calculateB(&pairs[i]);

        sem_wait(&sem_c); // Wait for C to be ready
        calculateD(&pairs[i]);
    }
    return NULL;
}

// Producer: Thread 3 function
void* thread3funct(void* args) {
    for (int i = 0; i < num_pairs; i++) {
        calculateC(&pairs[i]);
        sem_post(&sem_c); // Signal that C is ready
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_pairs>\n", argv[0]);
        return 1;
    }

    num_pairs = atoi(argv[1]);
    if (num_pairs <= 0) {
        printf("Number of pairs must be positive.\n");
        return 1;
    }

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, num_pairs * sizeof(data), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("Failed to create shared memory");
        return 1;
    }

    // Attach the shared memory
    pairs = (data *)shmat(shmid, NULL, 0);
    if (pairs == (data *)-1) {
        perror("Failed to attach shared memory");
        shmctl(shmid, IPC_RMID, NULL);  // Cleanup
        return 1;
    }

    // Initialize semaphores
    sem_init(&sem_a, 0, 0);
    sem_init(&sem_c, 0, 0);

    // Generate random (X, Y) pairs and reset results
    for (int i = 0; i < num_pairs; i++) {
        pairs[i].X = rand() % 10;
        pairs[i].Y = rand() % 10;
        reset_result(&pairs[i].result);
    }

    // Create threads
    pthread_create(&tid[0], NULL, thread1funct, NULL);
    pthread_create(&tid[1], NULL, thread2funct, NULL);
    pthread_create(&tid[2], NULL, thread3funct, NULL);

    // Wait for threads to complete
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);

    // Display results once all threads are done
    display_results();

    // Display shared memory status
    printf("\nShared memory status:\n");
    system("ipcs -m");

    // Detach and remove shared memory
    shmdt(pairs);
    shmctl(shmid, IPC_RMID, NULL);

    // Cleanup
    sem_destroy(&sem_a);
    sem_destroy(&sem_c);

    return 0;
}
