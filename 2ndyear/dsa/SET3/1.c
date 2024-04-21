#include"display.h"
int main(){
    int choice, data;
    treenode* root = NULL;

    do {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert Node(s)\n");
        printf("2. Display Inorder\n");
        printf("3. Display Preorder\n");
        printf("4. Display Postorder\n");
        printf("5. Display Tree (experimental)\n");
        printf("6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int count[1]={0};
        queue *pre, *ino;
        switch (choice) {
            case 1:
                insertion(&root);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                count[0]=0;
                element_count(root,count);
                pre = init(*count);
                ino = init(*count);
                preorder_queue(root,pre);
                inorder_queue(root,ino);
                display_tree_preorder_inorder(pre->data,ino->data,*count);
                delete_queue(pre);
                delete_queue(ino);
                break;  
            case 6:
                printf("Exiting...\n");
                delete_tree(&root);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
