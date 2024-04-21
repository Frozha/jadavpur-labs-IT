#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* give_node(int data){
    node *n = (node*)calloc(1,sizeof(node));
    n->data = data;
    return n;
}

node* insert(node* head, int data, int index){
    if(head == NULL){
        node *newh = give_node(data);
        return newh;
    }
    if(index!=0){
        int insertion_index = 1;
        node* current = head;
        while(current->next!=NULL&&index != insertion_index){
            current = current->next;
            insertion_index++;
        }
        node* newl = give_node(data);
        newl->next = current->next;
        current->next = newl;
        return head;
    }
    else{
        node* newl = give_node(data);
        newl->next = head;
        return newl;
    }
}

node* delete_index(node* head, int index){
    if(head == NULL){
        return NULL;
    }
    if(index!=0){
        int deletion_index = 1;
        node* current = head;
        while(current->next!=NULL&&index != deletion_index){
            current = current->next;
            deletion_index++;
        }
        if(current->next == NULL){
            node* before_current = head;
            while(before_current->next!=current){
                current=current->next;
            }
            current = before_current;
        }
        node* temp = current->next;
        current->next = current->next->next;
        free(temp);
        return head;
    }
    else{
        node* current = head->next;
        free(head);
        head = current;
        return head;
    }
}

void print(node* head){
    node *current = head;
    printf("[");
    while(current!=NULL){
        printf("%p ",current->data,current->next);
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
        node* before_current= head;
        while(current!=head){
            before_current = head;
            printf("%d ",current->data);
            while(before_current->next!=current){
                before_current=before_current->next;
            }
            current = before_current;
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
    if(size(head)>1){
        node* prev = head;
        node* current = prev->next;
        node* next = current->next;
        prev->next = NULL;
        while(current!=NULL){
            current->next = prev;
            prev = current;
            current = next;
            if(next!=NULL){
                next = next->next;
            }
        }
        return prev;
    }
    if(size(head)==1) return head;
    else return NULL;
}

void end(node* head){
    node* prev;
    while(head!=NULL){
        prev = head;
        head = head->next;
        free(prev);
    }
}
