#include "double_linked_list.c" 

int main() {
    node* head = NULL;
    char choice;
    int data, index;

    do {
        printf("Doubly Linked List Menu:\n");
        printf("a. Insert node\n");
        printf("b. Delete node by index\n");
        printf("c. Print doubly linked list\n");
        printf("d. Reverse print doubly linked list\n");
        printf("e. Reverse the list\n");
        printf("f. Get doubly linked list size\n");
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
                printf("reversed doubly linked list. \n");
                break;

            case 'f':
                printf("Doubly linked list size: %d\n", size(head));
                break;

            case 'g':
                end(head); 
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 'g');

    return 0;
}
