#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    int data;
    struct node* previous;
    struct node* next;
}node;

node* give_node(node* previous, int data, node* next){
    node* newnode = (node*)calloc(1,sizeof(node));
    newnode->previous = previous;
    newnode->data = data;
    newnode->next = next;
    return newnode;
}

node* insert(node* head, int data, int index){
    if(head == NULL){
        head = give_node(NULL,data,NULL);
        return head;
    }
    if(index!=0){
        int insertion_index = 1;
        node* current = head;
        while(current->next!= NULL &&index != insertion_index){
            current = current->next;
            insertion_index++;
        }
        node* newl = give_node(current,data,current->next);
        current->next = newl;
        newl->next->previous = newl;
        return head;
    }
    else{
        node* newl = give_node(NULL,data,head);
        head->previous = newl;
        return newl;
    }
}

node* delete_index(node* head, int index){
    if(head == NULL){
        return NULL;
    }
    if(index !=0){
        int deletion_index = 1;
        node* current = head;
        while(current->next!=NULL&&index != deletion_index){
            current = current->next;
            deletion_index++;
        }
        if(current->next == NULL){
            current->previous->next = NULL;
            free(current);
            return head;
        }
        node* temp = current->next;
        current->next = temp->next;
        if(temp->next!=NULL){
            temp->next->previous = current;
        }
        free(temp);
        return head;
    }
    else{
        if(head->next !=NULL){
            node* current = head->next;
            free(head);
            current->previous = NULL;
            return current;
        }
        else{
            free(head);
            return NULL;
        }
        
    }
}

void print(node* head){
    node *current = head;
    printf("[");
    while(current!=NULL){
        printf("<%p|%d|%p> ",current->previous,current->data,current->next);
        current = current->next;
    }
    printf("]\n");
}

void reverse_print(node* head){
    if(head!=NULL){
        node*current = head;
        while(current->next!=NULL){
            current=current->next;
        }

        printf("[");
        while(current!=head){
            printf("%d ",current->data);
            current = current->previous;
        }
        printf("%d]\n",head->data);
    }
    else printf("[]");
}

int size(node* head){
    if(head !=NULL){
        int s = 1;
        node*current = head;
        while(current->next!=NULL){
            current=current->next;
            s++;
        }
        return s;
    }
    else return 0;
}

node* reverse(node* head){
    if(head==NULL) return NULL;
    if(size(head)>1){
        node* next=head->next;
        node* current = head;
        while (next!=NULL){
            current->next = current->previous;
            current->previous = next;
            current = current->previous;
            next = current->next;
        }
        current->next = current->previous;
        current->previous = NULL;

        return current;
    }
    else return head;
}

void end(node* head){
    node* prev;
    while(head!=NULL){
        prev = head;
        head = head->next;
        free(prev);
    }
}

