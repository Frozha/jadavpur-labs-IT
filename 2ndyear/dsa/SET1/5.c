#include"polynomial.c"

int main(){
    printf("polynomial 1\n");
    struct polynomial poly1;
    init(&poly1);
    display(&poly1);
    printf("polynomial 2\n");
    struct polynomial poly2;
    init(&poly2);
    display(&poly2);
    
    struct polynomial prod = product(&poly1, &poly2);
    display(&prod);

    destroy(&poly1);
    destroy(&poly2);
    destroy(&prod);
    return 0;
}