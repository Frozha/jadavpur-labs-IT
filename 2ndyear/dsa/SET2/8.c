#include "circular_queue_linked_list.c"
#include "circular_queue_array.c"

int main() {
    int choice;
    printf("Choose the type of circular queue:\n");
    printf("1. Linked List\n");
    printf("2. Array\n");
    scanf("%d", &choice);

    if (choice == 1) {
        circular_queue_ll* cq_ll = give_circular_queue_ll();
        int data, option;

        do {
            printf("\nCircular Queue using Linked List:\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Queue Length\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &option);

            switch (option) {
                case 1:
                    printf("Enter data to enqueue: ");
                    scanf("%d", &data);
                    enqueue_circular_ll(&cq_ll, data);
                    break;
                case 2:
                    printf("Dequeued element: %d\n", dequeue_circular_ll(&cq_ll));
                    break;
                case 3:
                    printf("Queue Length: %d\n", circular_queue_ll_length(&cq_ll));
                    break;
                case 4:
                    delete_circular_queue_ll(&cq_ll);
                    break;
                default:
                    printf("Invalid choice\n");
            }
        } while (option != 4);
    } 
    else if (choice == 2) {
        int arr_size;
        printf("Enter the size of the array: ");
        scanf("%d", &arr_size);
        circular_queue_arr* cq_arr = give_circular_queue_arr(arr_size);
        int data, option;

        do {
            printf("\nCircular Queue using Array:\n");
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Queue Length\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &option);

            switch (option) {
                case 1:
                    printf("Enter data to enqueue: ");
                    scanf("%d", &data);
                    enqueue_circular_arr(&cq_arr, data);
                    break;
                case 2:
                    printf("Dequeued element: %d\n", dequeue_circular_arr(&cq_arr));
                    break;
                case 3:
                    circular_queue_arr_length(&cq_arr);
                    break;
                case 4:
                    delete_circular_queue_arr(&cq_arr);
                    break;
                default:
                    printf("Invalid choice\n");
            }
        } while (option != 4);
    } 
    else {
        printf("Invalid choice\n");
    }

    return 0;
}
