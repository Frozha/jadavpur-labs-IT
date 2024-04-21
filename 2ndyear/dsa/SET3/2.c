#include<stdio.h>
#include<stdlib.h>
#include"display.h"

int main() {

    int num_of_elems;
    int *pre;
    int *ino;
    printf("Enter number of nodes in tree : ");
    scanf("%d", &num_of_elems);
    pre = (int*)calloc(num_of_elems,sizeof(int));
    ino = (int*)calloc(num_of_elems,sizeof(int));
    if(pre==NULL || ino==NULL){
        printf("malloc falied!");
        return -1;
    }
    printf("Enter preorder : ");
    int i;
    for(i=0;i<num_of_elems;i++){
        scanf("%d",pre+i);
    }
    printf("Enter inorder : ");
    for(i=0;i<num_of_elems;i++){
        scanf("%d",ino+i);
    }
    display_tree_preorder_inorder(pre,ino,num_of_elems);
}