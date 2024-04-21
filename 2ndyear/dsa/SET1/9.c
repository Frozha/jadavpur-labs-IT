#include<stdio.h>


int main(){
    int rows=2,cols=3;
    int matx[rows][cols]={
        {1,2,3},
        {4,5,6}
    };
    int *arr =&matx[0][0];
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d ",*(arr+i*cols+j));
        }
        printf("\n");
    }
}