#include "linked_list.c"

typedef struct circular_queue_ll {
    node* head;
    node* tail;
} circular_queue_ll;

circular_queue_ll* give_circular_queue_ll() {
    circular_queue_ll* q = (circular_queue_ll*)calloc(1, sizeof(circular_queue_ll));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue_circular_ll(circular_queue_ll** q, int data) {
    if ((*q)->head == NULL) {
        (*q)->head = give_node(data);
        (*q)->head->next = (*q)->head;
        (*q)->tail = (*q)->head;
    } else {
        node* new_node = give_node(data);
        new_node->next = (*q)->head;
        (*q)->tail->next = new_node;
        (*q)->tail = new_node;
    }
}

int dequeue_circular_ll(circular_queue_ll** q) {
    if ((*q)->head == NULL) {
        printf("Underflow\n");
        return -1;
    } else {
        int value = (*q)->head->data;
        if ((*q)->head == (*q)->tail) {
            free((*q)->head);
            (*q)->head = NULL;
            (*q)->tail = NULL;
        } else {
            node* temp = (*q)->head;
            (*q)->head = (*q)->head->next;
            (*q)->tail->next = (*q)->head;
            free(temp);
        }
        return value;
    }
}

int circular_queue_ll_length(circular_queue_ll** q) {
    int length = 0;
    node* current = (*q)->head;
    while (current != NULL) {
        length++;
        current = current->next;
        if (current == (*q)->head) {
            break;
        }
    }
    return length;
}

void delete_circular_queue_ll(circular_queue_ll** q) {
    while ((*q)->head != NULL) {
        dequeue_circular_ll(q);
    }
    free(*q);
}
