
#include "queue.c"
#include "queue_array.c"

int main() {
    char choice;
    
    do {
        printf("Queue Implementation Menu:\n");
        printf("a. Use Linked List\n");
        printf("b. Use Array\n");
        printf("c. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a': {
                queue *q1 = give_queue();
                char operation;
                int data;

                do {
                    printf("Linked List Queue Menu:\n");
                    printf("a. Enqueue element\n");
                    printf("b. Dequeue element\n");
                    printf("c. Get queue length\n");
                    printf("d. Exit\n");
                    printf("Enter your choice: ");
                    scanf(" %c", &operation);

                    switch (operation) {
                        case 'a':
                            printf("Enter value to enqueue: ");
                            scanf("%d", &data);
                            enqueue(&q1, data);
                            break;

                        case 'b':
                            if (queue_length(&q1) > 0) {
                                printf("Dequeued value: %d\n", dequeue(&q1));
                            } else {
                                printf("Queue is empty.\n");
                            }
                            break;

                        case 'c':
                            printf("Queue length: %d\n", queue_length(&q1));
                            break;

                        case 'd':
                            delete_queue(&q1);
                            printf("Exiting Linked List Queue...\n");
                            break;

                        default:
                            printf("Invalid choice. Please choose again.\n");
                    }
                } while (operation != 'd');
                break;
            }

            case 'b': {
                int arr_size;
                printf("Enter the maximum size of the queue: ");
                scanf("%d", &arr_size);

                queue_arr *q1 = give_queue_arr(arr_size); 
                char operation;
                int data;

                do {
                    printf("Array Queue Menu:\n");
                    printf("a. Enqueue element\n");
                    printf("b. Dequeue element\n");
                    printf("c. Get queue length\n");
                    printf("d. Exit\n");
                    printf("Enter your choice: ");
                    scanf(" %c", &operation);

                    switch (operation) {
                        case 'a':
                            printf("Enter value to enqueue: ");
                            scanf("%d", &data);
                            enqueue_arr(&q1, data);
                            break;

                        case 'b':
                            if (q1->tail >= 0) {
                                printf("Dequeued value: %d\n", dequeue_arr(&q1));
                            } else {
                                printf("Queue is empty.\n");
                            }
                            break;

                        case 'c':
                            queue_arr_length(&q1);
                            break;

                        case 'd':
                            delete_queue_arr(&q1);
                            printf("Exiting Array Queue...\n");
                            break;

                        default:
                            printf("Invalid choice. Please choose again.\n");
                    }
                } while (operation != 'd');
                break;
            }

            case 'c':
                printf("Exiting Queue Implementation Menu...\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 'c');

    return 0;
}
