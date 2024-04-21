/*
@frozha - hrithvik kondalkar - jadavpur university 2026
-----------------------------------------------------------------------
to display a binary tree in terminal

level = 0
1

level = 1 
. _ 1 _ .
( . . . )
2 . . . 3 

level = 2
. . . _ _ _ 1 _ _ _ 
. . ( . . . . . . . )  
. _ 2 _ . . . . . _ 3 _ 
( . . . ) . . . ( . . . ) 
4 . . . ? . . . 6 . . . 7  

level = 3
. . . . . . . _ _ _ _ _ _ _ 1 _ _ _ _ _ _ _ 
. . . . . . ( . . . . . . . . . . . . . . . ) 
. . . _ _ _ 2 _ _ _ . . . . . . . . . _ _ _ 3 _ _ _ 
. . ( . . . . . . . ) . . . . . . . ( . . . . . . . ) 
. _ 4 _ . . . . . _ ? _ . . . . . _ 6 _ . . . . . _ 7 _ 
( . . . ) . . . ( . . . ) . . . ( . . . ) . . . ( . . . ) 
8 . . . 9 . . . ? . . . ? . . . 12. . . 13. . . 14. . . 15 // enter backspace char '\b' after printing double digs 

level = 4
. . . . . . . . . . . . . . . _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 1 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
. . . . . . . . . . . . . . ( . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ) 
. . . . . . . _ _ _ _ _ _ _ 2 _ _ _ _ _ _ _ . . . . . . . . . . . . . . . . . _ _ _ _ _ _ _ 3 _ _ _ _ _ _ _
. . . . . . ( . . . . . . . . . . . . . . . ) . . . . . . . . . . . . . . . ( . . . . . . . . . . . . . . . )
. . . _ _ _ 4 _ _ _ . . . . . . . . . _ _ _ ? _ _ _ . . . . . . . . . _ _ _ 6 _ _ _ . . . . . . . . . _ _ _ 7 _ _ _
. . ( . . . . . . . ) . . . . . . . ( . . . . . . . ) . . . . . . . ( . . . . . . . ) . . . . . . . ( . . . . . . . )
. _ 8 _ . . . . . _ 9 _ . . . . . _ ? _ . . . . . _ ? _ . . . . . _ 12_ . . . . . _ 13_ . . . . . _ 14_ . . . . . _ 15_
( . . . ) . . . ( . . . ) . . . ( . . . ) . . . ( . . . ) . . . ( . . . ) . . . ( . . . ) . . . ( . . . ) . . . ( . . . )
16. . . 17. . . 18. . . 19. . . ? . . . ? . . . ? . . . ? . . . 24. . . 25. . . 26. . . 27. . . 28. . . 29. . . 30. . . 31

...

[genralizing]
level = n (latest_level)
(current_level is r)
A(n) = 2(n+1) //number of rows 
B(n) = 2^(n+2)-3 //number of columns 
C(n,r) = (2^(n - r))-1 // number of underscores on each side of node
D(n,r) = 2^(n-r)-1 // number of spaces before left most node (before all underscores)
E(n,r) = 2^r // number of nodes per level 
F(n,r) = 2^(n-r+1)+1 //number of spaces between 2 nodes (after underscores) 
G(n,r) = 2^(n-r+1)+1-2 //number of spaces between 2 brackets is

spaces and nodes and parenth are printed with a prespace in them.
ex: ' 0', ' (', etc.
note: ' .'->'  '

node row print(n,r):nrp(n,r)
insert D(n,r) spaces and do a->d (2^r) times 
    a. insert C(n,r) underscores
    b. insert node
    c. insert C(n,r) underscores
    d. insert F(n,r) spaces

bracket row print(n,r):brp(n,r)
insert D(n,r)-1 spaces and then do a -> d (2^r) times 
    a. insert open parenth
    b. insert G(n,r) spaces
    c. insert close parenth
    d. insert G(n,r) spaces

ALGORITHM : 
0. nrp(n,0);
1. set latest row as n and current row as r=1
2. brp(n,r)->newline->nrp(n,r)
3. increment r by one if not equal to n then goto 2. else goto 4.
4. end

*/
#include <stdio.h>
#include"queue.h"
#include"tree.h"
int powr(const int a, const int b){
    int result=1;
    if(b==0){
        return result;
    }
    else if(b>0){
        int i;
        for(i=0;i<b;i++){
            result*=a;
        }
        return result;
    }
    else return -1;
}
#define MOD(a) a>0?a:(-1*a)
#define A(n) (2 * ((n) + 1)) 
#define B(n) (powr(2, (n) + 2) - 3)
#define C(n, r) (powr(2, (n) - (r)) - 1)
#define D(n, r) (powr(2, (n) - (r)) - 1)
#define E(n, r) powr(2, r) 
#define F(n, r) (powr(2, (n) - (r) + 1) + 1) 
#define G(n, r) (powr(2, (n) - (r) + 1) - 1)

int maxDepth(treenode* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftDepth = maxDepth(node->left_child);
        int rightDepth = maxDepth(node->right_child);
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }
}

void nrp(queue* q, int n, int r) {
    int i, j,counter;
    for (i = 0; i < D(n, r); i++) {
        printf("  ");
    }
    for (i = 0,counter = 0; i < powr(2, r);i++) {
        for (j = 0; j < C(n, r); j++) {
            printf("_ ");
        }
        if(counter<q->tail){
            if((q->data)[counter]==-1){
                printf("? ");
                counter++;
            }
            else{
                printf("%d ",(q->data)[counter]); // Node
                counter++;
                if(((q->data)[counter])/10!=0){
                printf("\b");
                }
            }
        }
        else if(counter>=q->tail&&counter<q->buffer_size){
            printf("? ");
            counter++;
        }

        for (j = 0; j < C(n, r); j++) {
            printf("_ ");
        }
        for (j = 0; j < F(n, r); j++) {
            printf("  ");
        }
    }
    printf("\n");
}

void brp(int n, int r) {
    int i, j;
    for (i = 0; i < D(n, r) - 1; i++) {
        printf("  ");
    }
    for (i = 0; i < powr(2, r); i++) {
        printf("( "); // Open Parenthesis
        for (j = 0; j < G(n, r); j++) {
            printf("  ");
        }
        printf(") "); // Close Parenthesis
        for (j = 0; j < G(n, r); j++) {
            printf("  ");
        }
    }
    printf("\n");
}

void display_tree(queue** buffer, int max_lvl) {
    nrp(buffer[0], max_lvl, 0); // Display root node
    int r = 1; // Current row starts from 1
    while (r <= max_lvl) {
        brp(max_lvl, r-1); // Display branches for the current row
        nrp(buffer[r], max_lvl, r); // Display nodes for the current row
        r++; // Increment row
    }
}

int left_subtree_inorder_index(int* pre, int* in){
    int length = sizeof(pre);
    if(length == 0)return -1;
    else if(length == 1)return 0;
    int i= 0;
    queue* pending = init(length);
    do{
       if(in_queue_at(pending,pre[i])==-1){
            enqueue(pending,pre[i]);
        }
        else{
            remove(pending,pre[i]);
        }
        if(in_queue_at(pending,in[i])==-1){
            enqueue(pending,in[i]);
        }
        else{
            remove(pending,in[i]);
        }
        i++;
    } while (pending->tail!=0&&i<length);
    if(pending->tail==0){delete_queue(pending);return i-1;}
    else{delete_queue(pending);return-1;}
}

int* subarray(int* arr, int a, int b){
    int* subarr;
    if(a < b){
        subarr = (int*)calloc((b - a), sizeof(int));
        int i;
        for(i = a; i < b; i++){
            subarr[i - a] = arr[i];
        }
    }
    else if(a==b){
        subarr = (int*)calloc(1,sizeof(int));
        *subarr = arr[a];
    }
    else {
        subarr = NULL;   
    }
    return subarr;
}

queue** create_treeconv_buffer(int max_lvl){
    int i;
    queue** buffer = (queue**)calloc(max_lvl+1,sizeof(queue*));
    if(buffer==NULL)goto z;
    for(i=0;i<=max_lvl;i++){
        buffer[i] = init(powr(2,i));
        if(buffer[i]==NULL)goto y;
    }
    return buffer;
    y:
    while(i!=0){
        i--;
        delete_queue(buffer[i]);
    }
    z:
    free(buffer);
    printf("mem alloc for buffer failed");
    return NULL;
}

void treeconv(int* pre, int* in, int length,int* max_level, int current_level, queue** buffer,int write_buffer_bool){
    int root_indx = left_subtree_inorder_index(pre,in);
    int root_dat=-1;
    if(root_indx>=0&&root_indx<length){root_dat = in[root_indx];}
    else{
        if(write_buffer_bool!=0){
            //printf("root indx = %d Root - %d, level - %de\n",root_indx, root_dat,current_level);
            enqueue(buffer[current_level],root_dat);
        }
        return;
    }
    if (current_level > *max_level) {
        if(write_buffer_bool!=0&&buffer[*max_level]->tail-1!=0){
            int l;
            for(l=0;l<powr(2,buffer[*max_level]->tail-1);l++){
                enqueue(buffer[current_level],-1);
            }
        }
        *max_level = current_level;
    }
    if(write_buffer_bool!=0){
        //printf("root indx = %d Root - %d, level - %d\n",root_indx, root_dat,current_level);
        enqueue(buffer[current_level],root_dat);
    }
    if(length>1){
        int* l_subtree_pre = subarray(pre,1,root_indx+1);
        int* l_subtree_in = subarray(in, 0,root_indx);
        treeconv(l_subtree_pre,l_subtree_in,root_indx,max_level,current_level+1,buffer,write_buffer_bool);
        int* r_subtree_pre = subarray(pre,root_indx+1,length);
        int* r_subtree_in = subarray(in, root_indx+1, length);
        treeconv(r_subtree_pre,r_subtree_in,length-root_indx-1,max_level,current_level+1,buffer,write_buffer_bool);
        free(l_subtree_pre);
        free(l_subtree_in);
        free(r_subtree_pre);
        free(r_subtree_in);
    }
}

void remove_buffer(queue** buffer, int length_of_preorder){
    int i,level=0;
    for(;i-1<length_of_preorder;i*=2){level++;}
    i = level+2;
    while(i!=0){
        i--;
        delete_queue(buffer[i]);
    }
    free(buffer);
}

void display_tree_preorder_inorder(int* pre, int*ino, int num_of_elems){
    int max_lvl[1]={0};
    treeconv(pre,ino,num_of_elems,max_lvl,0,NULL,0);
    queue** buffer= create_treeconv_buffer(*max_lvl);
    max_lvl[0] = 0;
    treeconv(pre,ino,num_of_elems,max_lvl,0,buffer,1);
    display_tree(buffer,*max_lvl);
    remove_buffer(buffer, num_of_elems);
}

