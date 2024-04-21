#include"display.h"

void insertions_bst(treenode**root){
    char choice;
    if(*root==NULL){
        printf("Creating Root\n");
        *root = (treenode*)calloc(1,sizeof(treenode));
        printf("Enter value at root : ");
        scanf("%d",&((*root)->data));
        (*root)->left_child = NULL;
        (*root)->right_child = NULL;
        (*root)->parent = NULL;
        printf("Do you want to insert keys in the tree ?(y/n)");
        fflush(stdin);
        scanf("%c",&choice);
        printf("\n");
        if(choice=='n')return;
    }

    treenode* current_root = (*root);
    treenode* buffer = NULL;
    int key;
    
    do{
        current_root = *root;
        
        printf("Enter key to insert in tree : ");
        scanf("%d", &key);
        if(buffer==NULL){
            goto t;
        }
        
        while(buffer!=NULL){
            current_root=buffer;
            t:
            if(key<current_root->data){
                printf("Moving to left from parent with value %d\n",current_root->data);
                buffer = current_root->left_child;
            }
            else{
                printf("Moving to right from parent with value %d\n",current_root->data);
                buffer = current_root->right_child;
            }
        }
        if(key<current_root->data){
            current_root->left_child = give_child(current_root,key);
        }
        else{
            current_root->right_child = give_child(current_root,key);
        }
        printf("insertion done going back to root now.\n");
        fflush(stdin);
        printf("Do you want to exit (y/n) : ");
        scanf("%c",&choice);
    }while(choice!='y');
}

treenode* search_bst(treenode* root, int target_key){
    treenode* current_root = root;
    while(current_root!=NULL){
        if(target_key==current_root->data){
            printf("Found target key in tree!\n");
            return current_root;
        }
        else if(target_key<current_root->data){
            printf("Moving to left from parent with value %d\n",current_root->data);
            current_root = current_root->left_child;
        }
        else if(target_key>current_root->data){
            printf("Moving to right from parent with value %d\n",current_root->data);
            current_root = current_root->right_child;
        }
        
    }
    printf("Target key not found in tree.\n");
    return NULL;
}

treenode* successor_bst(treenode* root){
    treenode* current_root = root;
    if(current_root==NULL||current_root->right_child==NULL){
        return NULL;
    }
    else{
        while(current_root->left_child!=NULL){
            current_root=current_root->left_child;
        }
        return current_root;
    }
}

treenode* predecessor_bst(treenode* root){
    treenode* current_root = root;
    if(current_root==NULL||current_root->left_child==NULL){
        return NULL;
    }
    else{
        while(current_root->right_child!=NULL){
            current_root=current_root->right_child;
        }
        return current_root;
    }
}

treenode* delete_treenode_bst(treenode** root,int target_key){
    treenode* current_root = search_bst(*root, target_key);
    treenode* successor;
    
    if(current_root){
        if(current_root->left_child==NULL&&current_root->right_child==NULL){
            if(current_root->parent == NULL){
                *root = NULL;
                return current_root;
            }
            else if(current_root==current_root->parent->left_child){
                current_root->parent->left_child = NULL;
                return current_root;
            }
            else if(current_root==current_root->parent->right_child){
                current_root->parent->right_child=NULL;
                return current_root;
            }
        }
        else if(current_root->left_child==NULL||current_root->right_child==NULL){
            if(current_root->parent == NULL){
                if(current_root->left_child){
                    current_root->left_child->parent=NULL;
                    *root = current_root->left_child;
                    return current_root;
                }
                else{
                    current_root->right_child->parent=NULL;
                    *root = current_root->right_child;
                    return current_root;
                }
            }
            else if(current_root == current_root->parent->left_child){
                successor = current_root->left_child==NULL?current_root->right_child:current_root->left_child;
                current_root->parent->left_child = successor;
                return current_root;
            }
            else if(current_root == current_root->parent->right_child){
                successor = current_root->left_child==NULL?current_root->right_child:current_root->left_child;
                current_root->parent->right_child = successor;
                return current_root;
            }
        }
        else{
            treenode* temp;
            successor = successor_bst(current_root);
            temp = delete_treenode_bst(root, successor->data);
            temp->parent = NULL;
            current_root->left_child->parent = temp;
            current_root->right_child->parent = temp;
            if(current_root==*root){
                *root = successor;
            }
            else{
                temp->parent = current_root->parent;
            }
            return current_root;

        }
    }
    return NULL;
}

int main() {
    treenode* root = NULL;
    int choice, key;
    treenode* result;

    do {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Create BST / Insert a key\n");
        printf("2. Search for a key\n");
        printf("3. Find in-order predecessor and successor\n");
        printf("4. Delete a key\n");
        printf("5. Display Tree (experimental)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int count[1]={0};
        queue *pre, *ino;

        switch (choice) {
            case 1:
                insertions_bst(&root);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = search_bst(root, key);
                break;
            case 3:
                printf("Enter the key: ");
                scanf("%d", &key);
                result = search_bst(root, key);
                if (result != NULL) {
                    treenode* pred = predecessor_bst(result);
                    treenode* succ = successor_bst(result);
                    printf("Inorder Traversal from subtree: ");
                    inorder(result);
                    printf("\n");
                    printf("Predecessor of key: %d\n", pred ? pred->data : -1);
                    printf("Successor of key: %d\n", succ ? succ->data : -1);
                }
                break;
            case 4:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                result = delete_treenode_bst(&root, key);
                if (result != NULL) {
                    printf("Deleted node with key %d\n", result->data);
                    free(result);
                } else {
                    printf("Key not found in the tree.\n");
                }
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
                printf("Exiting the program.\n");
                delete_tree(&root);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}