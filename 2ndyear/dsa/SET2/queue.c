#include"linked_list.c"

typedef struct queue{
    node* head;
    int tail_index;
}queue;

queue* give_queue(){
    queue *q1 = (queue*)calloc(1, sizeof(queue));
    q1->head = NULL;
    q1->tail_index = -1;
    return q1;
}

void enqueue(queue**main_queue, int data){
    ((*main_queue)->head) = insert(((*main_queue)->head),data,0);
    (*main_queue)->tail_index++;
}

int dequeue(queue**main_queue){
    if(((*main_queue)->tail_index)!=-1){
        int i=0;
        node* dummy=((*main_queue)->head);
        for(i=0;i<((*main_queue)->tail_index);i++){
            dummy=dummy->next;
        }
        i = dummy->data;
        ((*main_queue)->head) = delete_index(((*main_queue)->head),((*main_queue)->tail_index));
        ((*main_queue)->tail_index)--;
        return i;
    }
    else{
        printf("underflow");
        return 0;
    }
}

int queue_length(queue**main_queue){
    return ((*main_queue)->tail_index)+1;
}

void delete_queue(queue**main_queue){
    end((*main_queue)->head);
    free(*main_queue);
}
