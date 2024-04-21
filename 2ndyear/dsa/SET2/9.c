#include"stack.c"

void enqueue(stack **main_stack, stack **aux_stack, float data){
    while(!is_empty(main_stack)){
        add(aux_stack, pop(main_stack));
    }
    add(main_stack,data);
}

float dequeue(stack **main_stack){
    return pop(main_stack);
}


int main(){
    stack *stack1 = NULL;
    stack *stack2 = NULL;
    int option;
    float data;

    do {
        printf("\nQueue using Two Stacks:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%f", &data);
                enqueue(&stack1, &stack2, data);
                break;
            case 2:
                if (!is_empty(&stack2)) {
                    printf("Dequeued element: %.2f\n", dequeue(&stack2));
                } else {
                    while (!is_empty(&stack1)) {
                        add(&stack2, pop(&stack1));
                    }
                    if (!is_empty(&stack2)) {
                        printf("Dequeued element: %.2f\n", dequeue(&stack2));
                    } else {
                        printf("Queue is empty.\n");
                    }
                }
                break;
            case 3:
                while (!is_empty(&stack1)) {
                    pop(&stack1);
                }
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (option != 3);

}