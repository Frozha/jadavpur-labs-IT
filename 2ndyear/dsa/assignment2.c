/*
working principle :-
1   2   0            row wise            diagonal wise
3   4   5  <--> { 1,2,3,4,5,6,7 } <-->  {1,4,7, 2,5, 3,6}
0   6   7                                  n  , n-1 ,n-1

nxn 2d matrix <--> n+(n-1)+(n-1) array

*/
#include<stdio.h>
#include<stdlib.h>

int dimension;

double* tridiagonal2d_to_1dbyrow(double **a){
    int i,j;
    double* arr_by_row = (double*)calloc((3*dimension)-2,sizeof(double));
    *(arr_by_row) = a[0][0];
    *(arr_by_row+1) = a[0][1];
    int arrcount = 2;
    for(i=1;i<dimension-1;i++){
        for(j=i-1;j<i+2;j++){
            *(arr_by_row+arrcount) = a[i][j];
            arrcount++;
        }
    }
    *(arr_by_row+arrcount) = a[dimension-1][dimension-2];
    *(arr_by_row+arrcount+1) = a[dimension-1][dimension-1];
    return arr_by_row;
}

double* tridiagonal2d_to_1dbydiagonal(double **a){
    double* arr_by_row = tridiagonal2d_to_1dbyrow(a);
    int i,j,arrindex=0;
    double* arr_by_diag = (double*)calloc((3*dimension)-2,sizeof(double));
    for(i=0;i<3;i++){
        j=i;
        while(j<3*dimension-2){
            *(arr_by_diag+arrindex) = *(arr_by_row+j);
            j+=3;
            arrindex++;
        }
    }
    return arr_by_diag;
}

double* giverow(int size){
    double* row = (double*)calloc(size,sizeof(double));
    return row;
}

int is_tridiagonal(double **matrix) {
    int i,j;
    for ( i=0;i<dimension;i++) {
        for ( j = 0; j < dimension; j++) {
            if (((i-j)>1 || (j-i)>1) && matrix[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

void print_matrix_from_diag_array(double *diag_arr){
    int i;
    double *row_wise_array = (double*)calloc((3*dimension)-2,sizeof(double));
    int index=0;
    for(i=0;i<dimension;i++){
        *(row_wise_array+index) = *(diag_arr+i);
        index=index+3;      
    }
    index=1;
    for(;i<2*dimension-1;i++){
       
        *(row_wise_array+index) = *(diag_arr+i);
        index=index+3;
    }
    index=2;
    for(;i<3*dimension-2;i++){
       
        *(row_wise_array+index) = *(diag_arr+i);
        index=index+3;
    }
    index=2;
    printf("%.2lf\t%.2lf\t",row_wise_array[0],row_wise_array[1]);
    for(i=0;i<dimension-2;i++){
        printf("0.00\t");
    }
    printf("\n");
   
    int j;
    for(i=0;i<dimension-1;i++){
        for(j=0;j<i;j++){
            printf("0.00\t");
        }
        for(j=0;j<3;j++){
            if(index<3*dimension-2){
                printf("%.2lf\t",row_wise_array[index]);
                index++;
            }
            else break;
        }
        for(j=0;j<dimension-i-3;j++){
            printf("0.00\t");
        }
        printf("\n");
    }

    free(row_wise_array);
}

double** matrix_from_diag_array(double *diag_arr){
    int i,j;
    double *row_wise_array = (double*)calloc((3*dimension)-2,sizeof(double));
    int index=0;

    for(i=0;i<dimension;i++){
        *(row_wise_array+index) = *(diag_arr+i);
        index=index+3;      
    }
    index=1;
    for(;i<2*dimension-1;i++){
       
        *(row_wise_array+index) = *(diag_arr+i);
        index=index+3;
    }
    index=2;
    for(;i<3*dimension-2;i++){
       
        *(row_wise_array+index) = *(diag_arr+i);
        index=index+3;
    }
   
    double **matx = (double**)calloc(dimension,sizeof(double*));
   
    *(matx) = giverow(dimension);
    *(*(matx)) = row_wise_array[0];
    *(*(matx)+1) = row_wise_array[1];
    index=2;
   
   
    for(i=0;i<dimension-1;i++){
        *(matx+i+1) = giverow(dimension);
        for(j=0;j<3;j++){
            if(index<3*dimension-2){
                matx[i+1][i+j] = row_wise_array[index];
                index++;
            }
            else break;
        }
    }

    free(row_wise_array);
    return matx;
}

int main(){
    printf("enter dimension of matrix (nxn) \n n = ");
    scanf("%d",&dimension);
    printf("Enter matrix :\n");
    int i,j;
    double** matx = (double**)calloc(dimension,sizeof(double*));
    for(i=0;i<dimension;i++){
        *(matx+i) =  giverow(dimension);
        for(j=0;j<dimension;j++){
            scanf("%lf",&matx[i][j]);
        }
    }

    double* array2 = tridiagonal2d_to_1dbydiagonal(matx);
   
    if(is_tridiagonal(matx)==0){
        printf("\nthis isn't a tridiagonal matrix,\nwill discard elements outside 3 largest diagonals.\n\n");
        printf("considering new matrix : \n");
        print_matrix_from_diag_array(array2);
    }

    printf("\narray of diagonal elements : \n");
    for(i=0;i<(3*dimension-2);i++){
        printf("%lf ",array2[i]);
    }

    //deleting input matrix
    for(i = 0; i < dimension; i++){
        free(matx[i]);
    }
    free(matx);

    printf("\n\nreconstructing matrix from diagonal element array : \n");
    matx = matrix_from_diag_array(array2);
    for ( i = 0; i < dimension; i++) {
        for ( j = 0; j <dimension; j++) {
            printf("%.2lf\t", matx[i][j]);
        }
        printf("\n");
    }

    free(array2);
    for(i = 0; i < dimension; i++){
        free(matx[i]);
    }
    free(matx);
}