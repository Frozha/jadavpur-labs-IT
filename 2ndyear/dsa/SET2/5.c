#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infix_to_postfix(const char *infix, char *postfix) {
    char output[200] = ""; 
    char operators[100] = ""; 
    int op_index = 0; 

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        //parenthesis start
        //will push to operator stack
        if (ch == '(') {
            operators[op_index++] = ch;
        }

        //parenthesis end pop all operators encounted after parenthesis start
        else if (ch == ')' ) {
            //if operator stack not empty then empty till ( encountered
            while (op_index > 0 && operators[op_index - 1] != '(') {
                output[strlen(output)] = operators[--op_index];
                output[strlen(output)] = ' ';
            }
            //remove ( for next iteration
            if (op_index > 0 && operators[op_index - 1] == '(') {
                op_index--;
            }
        } 

        //operators encountered
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            //if stack not empty then pop operator stack till end or till ( encountered whatever is first
            while (op_index > 0 && operators[op_index - 1] != '(' && precedence(operators[op_index - 1]) >= precedence(ch)) {
                output[strlen(output)] = operators[--op_index];
                output[strlen(output)] = ' ';
            }
            operators[op_index++] = ch;
        } 

        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||(ch>=48&&ch<=58)) {
            if((ch>=48&&ch<=58)){
                while(infix[i]<=58&&infix[i]>=48){
                    ch = infix[i];
                    output[strlen(output)] = ch;
                    i++;
                }
                i--;
                output[strlen(output)] = ' ';
            }
            else{
                output[strlen(output)] = ch;
                output[strlen(output)] = ' ';
            }
            
        }
    }

    //empty remaining operator stack
    while (op_index > 0) {
        output[strlen(output)] = operators[--op_index];
        output[strlen(output)] = ' ';
    }

    strcpy(postfix, output);
}

int main() {
    char infix[200]; 
    char postfix[200]; 

    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0'; 

    infix_to_postfix(infix, postfix);
    printf("postfix expression: %s\n", postfix);

    return 0;
}
