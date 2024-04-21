#include "polynomial.c"


int main() {
    printf("polynomial 1\n");
    struct polynomial poly1;
    init(&poly1);
    display(&poly1);
    printf("polynomial 2\n");
    struct polynomial poly2;
    init(&poly2);
    display(&poly2);
    struct polynomial sum_obj = sum(&poly1, &poly2);
    display(&sum_obj);

    destroy(&poly1);
    destroy(&poly2);
    destroy(&sum_obj);

    return 0;
}