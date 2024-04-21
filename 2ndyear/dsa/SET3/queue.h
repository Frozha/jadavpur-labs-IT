#include<stdlib.h>
#include<stdio.h>

typedef struct queue{
    int* data;
    int tail;//enqueue here
    int buffer_size;
}queue;

queue* init(int buffr_size){
    queue* q = (queue*)calloc(1,sizeof(queue));
    q->data = (int*)calloc(buffr_size, sizeof(int));
    q->tail = 0;
    q->buffer_size = buffr_size;
    return q;
}

void enqueue(queue* q, int dat){
    if(q->tail==q->buffer_size){
        printf("overflow");
        return;
    }
    else{
        q->data[q->tail++] = dat;
    }
}

int dequeue(queue*q){
    int a=-1;
    if(q->tail==0) printf("underflow");
    else{
        a= q->data[--(q->tail)];
    }
    return a;
}

int in_queue_at(queue* q, int target){
    int i;
    for(i=0;i<q->tail;i++){
        if(target == q->data[i]) break;
        
    }
    if(i==q->tail) return -1;
    else return i;
}

void display_queue(queue*qu){
    printf("[");
    int i;
    for(i=0;i<qu->tail;i++){
        printf("%d ",(qu->data)[i]);
    }
    printf("\b]\n");
}

void delete_queue(queue* q){
    free(q->data);
    free(q);
}

void remove(queue* q, int target){
    int i = in_queue_at(q, target);
    if(i==-1) return;
    for(i;i<q->tail-1;i++){
        q->data[i] = q->data[i+1];
    }
    q->tail--;
}