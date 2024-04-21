#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//linkedlist definition
typedef struct node{
    int value;
    struct node* next;
}node;

//returns number of digits of a number that can be stored in
// int type keeping one decimal place for carry
int node_value_int_length(){    
    int max = pow(2,((sizeof(int)*8)-1))-1;
    int max_length =1;

    while((max/((int)pow(10,max_length)))!=0){
        max_length+=1;
    }

    return max_length-1;
}

//input:  "456789123456789"
//index:    1    |    0
//returns -> 456789 for index 1
//index 0 is stored in head of the linked list
int num_at_index(char *inp_str, int indx){
    int int_length = node_value_int_length();
    int str_length = strlen(inp_str)-1;
    int num_of_div = str_length%int_length==0?str_length/int_length:(str_length/int_length)+1;
    int j;
    int num=0;

    //index out of bound condition
    if(num_of_div-indx-1<0) return 0;

    int len_of_num_in_last_div = (str_length%int_length)==0?9:str_length%int_length;
    
    //index is not last block in string
    if(indx!=num_of_div-1){
        //start of div block will be inp_str+len_of_num_in_last_div+((num_of_div-1)*int_length)-1-((indx+1)*int_length)+1
        //                                                      ^                               ^                       ^
        //             brings to first num of second last block | /   brings to right most digit|brings to desired block|s' left most dig 
        char* block_start = inp_str+len_of_num_in_last_div+((num_of_div-1)*int_length)-1-((indx+1)*int_length)+1;
        for(j=0;j<int_length;j++){
            num*=10;
            num+=(int)(*(block_start+j)-'0');
        }
    }

    //index is last block in string
    else{
        for(j=0;j<len_of_num_in_last_div;j++){
            num*=10;
            num+=(int)((*(inp_str+j))-'0');
        }
    }

    return num;
}

//returns next node's address
//next node's address is automaically set in prev_node->next
//function could have void return but isn't
//so that head can be initialised by next_node(val,NULL)
node* next_node(int value,node *prev_node){
    node *nxt=(node*)calloc(1,sizeof(node));
    nxt->value =value;
    nxt->next=NULL;
    if(prev_node!=NULL){
        prev_node->next = nxt;
    }
    return nxt;
}

//takes string and creates linked list with 
//appropriate length numbers
//returns head of linked list
node* set_number(char *inp_str){
    int int_length = node_value_int_length();
    int inp_str_len=strlen(inp_str);
    int num_of_nodes = (inp_str_len%int_length==0)?(inp_str_len/int_length):(inp_str_len/int_length +1);
    int i;
    node *head = next_node(num_at_index(inp_str,0),NULL);
    node *current = head;

    for(i=1;i<num_of_nodes;i++){
        current = next_node(num_at_index(inp_str,i),current);
    }

    return head;
}

//need to print in reverse order of linked list
void print_full_num(node *head){
    node *current = head;
    int size=0;
    while(current!=NULL){
        size++;
        current = current->next;
    }
    current = head;
    int i,j;
    for(i=0;i<size-1;i++){
        current=current->next;
    }
    if(current->value!=0){
        printf("%d",current->value);
    }
    for(i=0;i<size-1;i++){
        current = head;
        for(j=0;j<size-2-i;j++){
            current=current->next;
        }
        printf("%0*d",node_value_int_length(),current->value);
    }
    printf("\n");
}

//traverses and deletes linked list
void delete_linked_list(node *head){
    node *current = head;
    node *temp = current;
    while(current!=NULL){
        current=current->next;
        free(temp);
        temp = current;
    }
}

//returns head of sum node
node* sum(node* a, node* b){
    int node_carry=0;
    int node_sum=0;
    int int_length = node_value_int_length();
    node *sum = (node*)calloc(1,sizeof(node));
    sum->value=0;
    sum->next=NULL;
    node *a_point = a, *b_point = b, *sum_point = sum;
    
    //runs till one linked list reaches end 
    while(a_point!=NULL && b_point!=NULL){
        node_sum = (a_point->value) + (b_point->value);
        node_carry = node_sum/((int)pow(10,int_length));
        node_sum = node_sum%((int)pow(10,int_length));
        
        sum_point->value += node_sum;
        sum_point = next_node(node_carry,sum_point);
        
        a_point = a_point->next;
        b_point = b_point->next;
        
    }

    //copy remaining node of other linked list if any
    if(a_point==NULL){
        while(b_point!=NULL){
            sum_point->value+=b_point->value;
            node_carry = (sum_point->value)/((int)pow(10,int_length));
            sum_point->value=(sum_point->value)%((int)pow(10,int_length));
            b_point=b_point->next;
            sum_point = next_node(node_carry,sum_point);
        }
    }
    else if(b_point==NULL){
        while(a_point!=NULL){
            sum_point->value+=a_point->value;
            node_carry = (sum_point->value)/((int)pow(10,int_length));
            sum_point->value=(sum_point->value)%((int)pow(10,int_length));
            a_point=a_point->next;
            sum_point = next_node(node_carry,sum_point);
        }
    }

    //if end carry is zero then delete last node
    if(sum_point->value == 0 && sum_point->next ==NULL){
        node *before_last_node=sum;
        while(before_last_node->next!=sum_point){
            before_last_node=before_last_node->next;
        }
        before_last_node->next = NULL;
        free(sum_point);
    }

    return sum;
}


int main(){
    char p[100],q[100];
    printf("enter first number  : ");
    fgets(p,sizeof(p),stdin);
    node *head1 = set_number(p);
    printf("enter second number : ");
    fgets(q,sizeof(q),stdin);
    node *head2 = set_number(q);
    node *sum_head = sum(head1,head2);

    printf("sum                 : ");
    print_full_num(sum_head);
    delete_linked_list(head1);
    delete_linked_list(head2);
    delete_linked_list(sum_head);
}