#include<stdio.h>
#include<stdlib.h>

typedef struct circular_queue_arr {
    int* array;
    int max_length;
    int head;
    int tail;
    int size;
} circular_queue_arr;

circular_queue_arr* give_circular_queue_arr(int arr_size) {
    circular_queue_arr* q = (circular_queue_arr*)calloc(1, sizeof(circular_queue_arr));
    q->array = (int*)calloc(arr_size, sizeof(int));
    q->max_length = arr_size;
    q->head = -1;
    q->tail = -1;
    q->size = 0;
    return q;
}

void enqueue_circular_arr(circular_queue_arr** q, int data) {
    if (((*q)->tail + 1) % (*q)->max_length == (*q)->head) {
        printf("Overflow\n");
    } 
    else {
        if ((*q)->head == -1) {
            (*q)->head = 0;
        }
        (*q)->tail = ((*q)->tail + 1) % (*q)->max_length;
        (*q)->array[(*q)->tail] = data;
        (*q)->size++;
    }
}

int dequeue_circular_arr(circular_queue_arr** q) {
    if ((*q)->head == -1) {
        printf("Underflow\n");
        return -1;
    } else {
        int value = (*q)->array[(*q)->head];
        if ((*q)->head == (*q)->tail) {
            (*q)->head = -1;
            (*q)->tail = -1;
        } else {
            (*q)->head = ((*q)->head + 1) % (*q)->max_length;
        }
        (*q)->size--;
        return value;
    }
}

void circular_queue_arr_length(circular_queue_arr** q) {
    printf("Queue size: %d\n", (*q)->size);
}

void delete_circular_queue_arr(circular_queue_arr** q) {
    free((*q)->array);
    free(*q);
}
