#include "linked_list.c"

int main() {
    node* head = NULL;
    char choice;
    int data, index;

    do {
        printf("Linked List Menu:\n");
        printf("a. Insert node\n");
        printf("b. Delete node by index\n");
        printf("c. Print linked list\n");
        printf("d. Reverse print linked list\n");
        printf("e. Reverse linked lsit\n");
        printf("f. Get linked list size\n");
        printf("g. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter data and index: ");
                scanf("%d %d", &data, &index);
                head = insert(head, data, index);
                break;

            case 'b':
                printf("Enter index to delete: ");
                scanf("%d", &index);
                head = delete_index(head, index);
                break;

            case 'c':
                print(head);
                break;

            case 'd':
                reverse_print(head);
                break;

            case 'e':
                head = reverse(head);
                printf("Linked list reversed.\n");
                break;

            case 'f':
                printf("Linked list size: %d\n", size(head));
                break;

            case 'g':
                end(head); // Free memory used by the linked list
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 'g');

    return 0;
}