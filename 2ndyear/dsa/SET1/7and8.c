#include<stdio.h>
#include<stdlib.h>

typedef struct matx_elem{
    int value;
    int row_index;
    int col_index;
}matx_elem;


int matx_rows,matx_cols;
int array_size;

int init(int (*inpt_matx)[matx_cols]){
    int i,j;
    int non_zero_count=0;
    for(i=0;i<matx_rows;i++){
        for(j=0;j<matx_cols;j++){
            if(inpt_matx[i][j]!=0){
                non_zero_count++;
            }
        }
    }
    array_size = non_zero_count;
    return array_size;
}

matx_elem* matx_to_struct(int (*inpt_matx)[matx_cols]){
    int i,j;
    int non_zero_count=0;
    matx_elem* matrix = (matx_elem*)calloc(array_size,sizeof(matx_elem));
    non_zero_count=-1;
    for(i=0;i<matx_rows;i++){
        for(j=0;j<matx_cols;j++){
            if(inpt_matx[i][j]!=0){
                non_zero_count++;
                (matrix+non_zero_count)->value = inpt_matx[i][j];
                (matrix+non_zero_count)->row_index = i;
                (matrix+non_zero_count)->col_index = j;
                
            }
        }
    }
    
    return matrix;
}

void display(matx_elem *a,int array_size){
    int i;
    for(i=0;i<array_size;i++){
        printf("%d %d %d\n",(a+i)->value,(a+i)->row_index,(a+i)->col_index);    
    }
}
matx_elem* add(matx_elem *a,int sizea, matx_elem *b,int sizeb){
    matx_elem* sum = (matx_elem*)calloc(sizea+sizeb,sizeof(matx_elem));
    int count=0,i;
    for(i=0;i<sizea;i++){
        (sum+count)->value = (a+i)->value;
        (sum+count)->row_index = (a+i)->row_index;
        (sum+count)->col_index = (a+i)->col_index;
        count++;
    }
    int j,pres_bool;
    for(i=0;i<sizeb;i++){
        pres_bool=0;
        for(j=0;j<count;j++){
            if((sum+j)->row_index == (b+i)->row_index && (sum+j)->col_index == (b+i)->col_index){
            (sum+j)->value+=(b+i)->value;
            pres_bool=1;
            }
        }
        if(pres_bool==0){
            (sum+count)->value = (b+i)->value;
            (sum+count)->row_index = (b+i)->row_index;
            (sum+count)->col_index = (b+i)->col_index;
            count++;
        }
    }
    return sum;
}

void display_as_matrix(matx_elem *a, int length){
    int i,j,k,printed;
    for (i=0;i<matx_rows;i++){
        for(j=0;j<matx_cols;j++){
            printed=0;
            for(k=0;k<length;k++){
                if((a+k)->row_index==i && (a+k)->col_index==j){
                    printf("%d ",(a+k)->value);
                    printed =1;
                    break;
                }
            }
            if(printed==0){
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void non_zero_per_row(matx_elem *a,int length){
    int non_zero_count=0;
    int i,j=0;
    for(i=0;i<matx_rows;i++){
        non_zero_count=0;
        for(j=0;j<length;j++){
            if(a[j].row_index==i && a[j].value!=0){
                non_zero_count++;
            }
        }
        printf("non zero in row %d - %d\n",i+1,non_zero_count);
    }
}

int main(){
    printf("Enter dimensions of matrix :-\nrows : ");
    scanf("%d",&matx_rows);
    printf("cols : ");
    scanf("%d",&matx_cols);
    int i,j;
    int matrix2d[matx_rows][matx_cols];
    
    printf("enter first matrix\n");
    for(i=0;i<matx_rows;i++){
        for(j=0;j<matx_cols;j++){
            scanf("%d",&matrix2d[i][j]);
        }
    }
    int sizea = init(matrix2d);
    matx_elem *matrix_struc_a=matx_to_struct(matrix2d);
    
    printf("enter second matrix\n");
    for(i=0;i<matx_rows;i++){
        for(j=0;j<matx_cols;j++){
            scanf("%d",&matrix2d[i][j]);
        }
    }
    int sizeb = init(matrix2d);
    matx_elem *matrix_struc_b=matx_to_struct(matrix2d);
    
    matx_elem *sum = add(matrix_struc_a,sizea,matrix_struc_b,sizeb);
    //display(sum,sizea+sizeb);
    printf("\nsum :\n");
    display_as_matrix(sum,sizea+sizeb);
    non_zero_per_row(sum,sizea+sizeb);
}

