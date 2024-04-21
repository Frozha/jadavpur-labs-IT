#include<stdio.h>

int arr_size = 5;
void inplacereversal(int *arr){
    int i,temp;
    for(i=0;i<=arr_size/2;i++){
        temp = *(arr+i);
        *(arr+i)=*(arr+arr_size-i-1);
        *(arr+arr_size-i-1)=temp;
    }
    for(i=0;i<arr_size;i++){
        printf("%d ",*(arr+i));
    }
}

int main(){
    printf("enter %d numbers for an array\n",arr_size);
    int array[arr_size];
    int i;
    for(i=0;i<arr_size;i++){
        scanf("%d",array+i);
    }
    inplacereversal(array);
}