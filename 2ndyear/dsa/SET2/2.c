#include "linked_list.c" 

node* set(int n){
    node* head = (node*)calloc(1,sizeof(node));
    head->data=1;
    int i=2;
    for(;i<n;i++){
        insert(head,i,n);
    }
    insert(head,n,n);
    node *last = head;
    while(last->next != NULL){
        last= last->next;
    }
    last->next = head;
    return head;
}

void remove_target_node(node* head, node* target){
    node *current = head;
    //current goes to one before target;
    while(current->next!=target){
        current = current->next;
    }
    current->next = target->next;
    free(target);
}

int josephus(int num_of_people,int step_size){
    node* head = set(num_of_people);
    node* current = head;
    node* targ = current;
    node* temp;
    int j=0;
    int i;
    while(current->next!=current){
        targ = current;
        for(j=0;j<step_size;j++){
            targ=targ->next;
        }
        temp = targ->next;
        printf("%d removes %d\n",current->data,targ->data);

        remove_target_node(current,targ);
        current = temp;
    }
    printf("%d wins \n",current->data);
    int val=current->data;
    free(current);
    return val;
}

int main(){
    int n,m;
    printf("Enter number of poeple : ");
    scanf("%d",&n);
    printf("Enter number of steps (to remove next person step is 1): ");
    scanf("%d",&m);
    printf("\n");
    josephus(n,m);
}
