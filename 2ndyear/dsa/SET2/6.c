#include<string.h>
#include<math.h>
#include"stack.c"
float eval_postfix(char *postfix){
    char temp_num[100] = "";
    float f1,f2;
    stack *values = NULL;
    int i,j;
    for(i=0;i<strlen(postfix);i++){
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            f1 = pop(&values);
            f2 = pop(&values);
            switch (postfix[i]) {
                case '+':
                    add(&values,f2+f1);
                    break;
                case '-':
                    add(&values,f2-f1);
                    break;
                case '*':
                    add(&values,f2*f1);
                    break;
                case '/':
                    add(&values,f2/f1);
                    break;
                case '^':
                    add(&values,pow(f2,f1));
                    break;
                default:
                    break;
            }
        }

        else if(postfix[i]>=48&&postfix[i]<58){
            j=0;
            while(postfix[i] != ' '){
                temp_num[j++] = postfix[i++];
            }
            temp_num[j] = '\0';
            add(&values,atof(temp_num));
        }
    }
    float val = pop(&values);
    while(!is_empty(&values)){
        pop(&values);
    }
    return val;
}

int main(){
    char postfix[200];

    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    float result = eval_postfix(postfix);
    printf("Result: %.2f\n", result);

    return 0;
}