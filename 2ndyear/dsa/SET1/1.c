#include<stdio.h>
int arr_size =  10;
void delatindex(int *arr, int index){
    int i;
    for(i=index;i<arr_size-1;i++){
        *(arr+i)=*(arr+i+1);
    }
    *(arr+arr_size-1)=NULL;
    arr_size-=1;
    printf("\n");
    for(i=0;i<arr_size;i++){
        printf("%d ",*(arr+i));
    }
}

int main(){
    printf("Enter 10 numbers to form an array\n");
    int i;
    int array[arr_size];
    for(i=0;i<arr_size;i++){
        scanf("%d",(array+i));
    }
    delatindex(array,5);
    delatindex(array,2);
    return 0;
}