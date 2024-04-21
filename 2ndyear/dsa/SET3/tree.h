#include<stdio.h>
#include<stdlib.h>

typedef struct treenode{
    int data;
    struct treenode* left_child;
    struct treenode* right_child;
    struct treenode* parent;
}treenode;

treenode* give_child(treenode* parent, const int data){
    treenode* child= (treenode*)calloc(1,sizeof(treenode));
    child->data = data;
    child->left_child = NULL;
    child->right_child = NULL;
    child->parent = parent;
    return child;
}

void show_current_node(treenode *node){
    printf("\nCurrent Node at %p with value %d\n",node, node->data);
}

void insertion(treenode** root){

    int k=1;
    int b;

    if(*root==NULL){
        printf("Creating Root\n");
        *root = (treenode*)calloc(1,sizeof(treenode));
        printf("Enter value at root : ");
        scanf("%d",&((*root)->data));
        (*root)->left_child = NULL;
        (*root)->right_child = NULL;
        (*root)->parent = NULL;
    }
    treenode* current_root = (*root);
    treenode* buffer;
    do
    {
        show_current_node(current_root);
        printf("1. Current Node\n2. Left Child\n3. Right Child\n4. Go to Parent of Current Node\nEnter q to quit insertion menu.\nchoice : ");
        char a;
        fflush(stdin);
        scanf("%c",&a);
        switch (a){
            case '1':
                printf("Enter new value ( currently = %d ) : ",current_root->data);
                scanf("%d", &(current_root->data));
                break;
            case '2':
                printf("Moving to left child of node with value( %d )\n",current_root->data);
                if(current_root->left_child){
                    current_root=current_root->left_child;
                    printf("Enter new value ( currently = %d ) : ",current_root->data);
                    scanf("%d", &(current_root->data));
                }
                else{
                    printf("Enter value for new node : ");
                    scanf("%d",&b);
                    buffer = give_child(current_root,b);
                    current_root->left_child = buffer;
                    current_root = current_root->left_child;
                }
                break;
            case '3':
                printf("Moving to right child of node with value( %d )\n",current_root->data);
                if(current_root->right_child){
                    current_root=current_root->right_child;
                    printf("Enter new value ( currently = %d ) : ",current_root->data);
                    scanf("%d", &(current_root->data));
                }
                else{
                    printf("Enter value for new node : ");
                    scanf("%d",&b);
                    buffer = give_child(current_root,b);
                    current_root->right_child = buffer;
                    current_root = current_root->right_child;
                }
                break;
            case '4':
                if(current_root->parent){
                    printf("Going back from current node(%d) to its parent(%d)",current_root->data,current_root->parent->data);
                    current_root=current_root->parent;
                }
                else{
                    printf("This is the root, it has no parent.\n");
                }
                break;
            case 'q':
                k=0;
                printf("for Modified Tree\n");
                break;
            
            default:
                printf("invalid input.\n");
                break;
        }
    } while (k);
    
}

void inorder(const treenode* root){
    if(root){
        inorder(root->left_child);
        printf("%d ",root->data);
        inorder(root->right_child);
    }
}

void inorder_queue(treenode* root,queue* q){
    if(root){
        inorder_queue(root->left_child,q);
        enqueue(q,root->data);
        inorder_queue(root->right_child,q);
    }
}

void preorder_queue(treenode* root, queue* q){
    if(root){
        enqueue(q,root->data);
        preorder_queue(root->left_child,q);
        preorder_queue(root->right_child,q);
    }
}

void preorder(const treenode* root){
    if(root){
        printf("%d ",root->data);
        preorder(root->left_child);
        preorder(root->right_child);
    }
}

void postorder(const treenode* root){
    if(root){
        postorder(root->left_child);
        postorder(root->right_child);
        printf("%d ",root->data);
    }
}

void delete_tree(treenode **root) {
    if (*root == NULL) {
        return;
    }
    delete_tree(&((*root)->left_child));
    delete_tree(&((*root)->right_child));
    printf("Deleting node with value %d\n", (*root)->data);
    free(*root);
    *root = NULL;
}

void element_count(treenode*root, int*count){
    if(root){
        (*count)++;
        element_count(root->left_child,count);
        element_count(root->right_child,count);
    }
}

