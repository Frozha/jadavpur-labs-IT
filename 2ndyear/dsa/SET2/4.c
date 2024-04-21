#include "stack.c" // Include the stack implementation

int main() {
    stack* top = NULL; // Initialize an empty stack
    char choice;
    float value;

    do {
        printf("Stack Menu:\n");
        printf("a. Push element\n");
        printf("b. Pop element\n");
        printf("c. Peek element\n");
        printf("d. Check if the stack is empty\n");
        printf("e. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter value to push: ");
                scanf("%f", &value);
                add(&top, value);
                break;

            case 'b':
                if (!is_empty(&top)) {
                    printf("Popped value: %.2f\n", pop(&top));
                } else {
                    printf("Stack is empty.\n");
                }
                break;

            case 'c':
                if (!is_empty(&top)) {
                    printf("Peeked value: %.2f\n", peep(&top));
                } else {
                    printf("Stack is empty.\n");
                }
                break;

            case 'd':
                if (is_empty(&top)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;

            case 'e':
                while (!is_empty(&top)) {
                    pop(&top); // Free remaining stack memory
                }
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 'e');

    return 0;
}
