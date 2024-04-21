#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    float element;
    struct stack *previous;
}stack;

stack* new_top(stack **top){
    stack* nt = (stack*)calloc(1,sizeof(stack));
    nt->previous=*top;
    return nt;
}

void add(stack **top, float a){
    stack* x = new_top(top);
    x->element = a;
    *top = x;
}

float pop(stack **top){
    if(*top!=NULL){
        float temp = (*top)->element;
        stack *prev_top = *top;
        *top = (*top)->previous;
        free(prev_top);
        return temp;
    }
    return -1;
}

float peep(stack **top){
    if(*top!=NULL){
        return (*top)->element;
    }
    return -1;
}

int is_empty(stack **top){
    return *top==NULL? 1:0;
}

/*
int main(){
    stack *top = NULL;
    add(&top,1);
    add(&top,2);
    printf("popped : %f",pop(&top));
    printf("\npopped : %f",pop(&top));
}*/