#include <stdio.h>
#include <stdlib.h>

struct number {
    int *arr;
    int length;
};

int strlen(const char *str) {
    int i = 0, l = 0;
    while (str[i] != '\0') {
        i++;
        l++;
    }
    return l;
}

void init_number(struct number *num, const char *str) {
    num->length = strlen(str);
    num->arr = (int *)malloc((num->length + 1) * sizeof(int));
    int i,j;
    for (i = num->length - 1, j = 0; i >= 0; i--, j++) {
        num->arr[j] = (int)(str[i] - '0');
    }
    num->arr[num->length] = 0;
}

void display_number(const struct number *num) {
    int i;
    printf("+ _");
    for(i=0;i<num->length;i++){
        printf("_");
    }
    printf("\n  ");
    for (i = num->length - 1; i >= 0; i--) {
        printf("%d", num->arr[i]);
    }
    printf("\n");
}

void add_numbers(const struct number *num1, const struct number *num2, struct number *result) {
    int max_length = (num1->length > num2->length) ? num1->length : num2->length;
    result->length = max_length;
    result->arr = (int *)malloc((result->length + 1) * sizeof(int));
    int i;
    for (i = 0; i <= result->length; i++) {
        result->arr[i] = 0;
    }

    for (i = 0; i < num1->length; i++) {
        result->arr[i] = num1->arr[i];
    }
    int j;
    for (j = 0; j < num2->length; j++) {
        result->arr[j] += num2->arr[j];
    }
    int k;
    for ( k = 0; k < result->length; k++) {
        if (result->arr[k] > 9) {
            result->arr[k + 1] += result->arr[k] / 10;
            result->arr[k] = result->arr[k] % 10;
        }
    }

    if (result->arr[result->length] != 0) {
        result->length++;
    }
}

void destroy_number(struct number *num) {
    free(num->arr);
    num->length = 0;
}

int main() {
    printf("Enter 2 large numbers to add them -\n1. ");
    char a[100], b[100];
    gets(a);
    printf("2. ");
    gets(b);

    struct number num1, num2, sum;
    init_number(&num1, a);
    init_number(&num2, b);
    add_numbers(&num1, &num2, &sum);

    display_number(&sum);

    destroy_number(&num1);
    destroy_number(&num2);
    destroy_number(&sum);

    return 0;
}