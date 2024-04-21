#include<stdlib.h>
#include<stdio.h>

typedef struct queue_arr{
    int tail;
    int* array;
    int length;  
}queue_arr;

queue_arr* give_queue_arr(int arr_size){
    queue_arr *q1 = (queue_arr*)calloc(1,sizeof(queue_arr));
    q1->array = (int*)calloc(arr_size,sizeof(int));
    q1->tail=-1;
    q1->length=arr_size;
    return q1;
}

void enqueue_arr(queue_arr **main_queue_arr,int data){
    if((*main_queue_arr)->tail==-1){
        ((*main_queue_arr)->array)[0] = data;
        ((*main_queue_arr)->tail)++;
    }
    else if((*main_queue_arr)->tail!=((*main_queue_arr)->length)-1&&((*main_queue_arr)->tail)>=0){
        int i;
        for(i=(*main_queue_arr)->tail;i>=0;i--){
            ((*main_queue_arr)->array)[i+1]=((*main_queue_arr)->array)[i];
        }
        ((*main_queue_arr)->array)[0] = data;
        ((*main_queue_arr)->tail)++;
    }
    else{
        printf("overflow\n");
    }
}

int dequeue_arr(queue_arr**main_queue_arr){
    if((*main_queue_arr)->tail==-1){
        printf("underflow\n");
        return 0;
    }
    else{
        int i = ((*main_queue_arr)->array)[((*main_queue_arr)->tail)];
        ((*main_queue_arr)->array)[((*main_queue_arr)->tail)]=0;
        ((*main_queue_arr)->tail)--;
        return i;
    }
}

void queue_arr_length(queue_arr**main_queue_arr){
    printf("tail : %d\n",((*main_queue_arr)->tail)+1);
    printf("max length : %d\n",((*main_queue_arr)->length));
}


void delete_queue_arr(queue_arr**main_queue_arr){
    free((*main_queue_arr)->array);
    free(*main_queue_arr);
}