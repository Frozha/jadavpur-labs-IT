#include"polynomial.c"

int main() {
    struct polynomial poly1;
    printf("For the first polynomial");
    init(&poly1);
    display(&poly1);
    double x;
    printf("Evaluate entered polynomial for x = ");
    scanf("%lf", &x);
    printf("f(%.2lf) = %.2lf\n", x, eval(&poly1, x));

    destroy(&poly1);

    return 0;
}