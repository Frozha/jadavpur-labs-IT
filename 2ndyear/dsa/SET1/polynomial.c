#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polynomial.h"
/*
struct element {
    double coeff;
    int exponent;
};

struct polynomial {
    struct element* poly;
    int poly_size;
};
*/

void init(struct polynomial* p) {
    printf("Enter the number of terms: ");
    scanf("%d", &p->poly_size);

    p->poly = (struct element*)malloc(p->poly_size * sizeof(struct element));

    for (int i = 0; i < p->poly_size; i++) {
        printf("Coefficient of %d term: ", i + 1);
        scanf("%lf", &p->poly[i].coeff);

        printf("Exponent of %d term: ", i + 1);
        scanf("%d", &p->poly[i].exponent);
    }

    printf("\n");
}

void display(const struct polynomial* p) {
    printf("%.2lfx^%d ", p->poly[0].coeff, p->poly[0].exponent);
    for (int i = 1; i < p->poly_size; i++) {
        if (!(p->poly[i].exponent == 0 && p->poly[i].coeff == 0)) {
            printf("+ %.2lfx^%d ", p->poly[i].coeff, p->poly[i].exponent);
        }
    }
    printf("\n\n");
}

struct polynomial sum(const struct polynomial* p1, const struct polynomial* p2) {
    struct polynomial sum;
    sum.poly_size = p1->poly_size + p2->poly_size;
    sum.poly = (struct element*)malloc(sum.poly_size * sizeof(struct element));

    int current_tail_index = p1->poly_size - 1;
    int exponent_overlap;

    for (int i = 0; i < p1->poly_size; i++) {
        sum.poly[i].exponent = p1->poly[i].exponent;
        sum.poly[i].coeff = p1->poly[i].coeff;
    }

    for (int j = 0; j < p2->poly_size; j++) {
        exponent_overlap = 0;
        for (int k = 0; k <= current_tail_index; k++) {
            if (sum.poly[k].exponent == p2->poly[j].exponent) {
                exponent_overlap = 1;
                sum.poly[k].coeff += p2->poly[j].coeff;
                break;
            }
        }
        if (exponent_overlap == 0) {
            current_tail_index++;
            sum.poly[current_tail_index].coeff = p2->poly[j].coeff;
            sum.poly[current_tail_index].exponent = p2->poly[j].exponent;
        }
    }

    struct polynomial final_sum;
    final_sum.poly_size = current_tail_index + 1;
    final_sum.poly = (struct element*)malloc(final_sum.poly_size * sizeof(struct element));

    for (int k = 0; k <= current_tail_index; k++) {
        final_sum.poly[k].coeff = sum.poly[k].coeff;
        final_sum.poly[k].exponent = sum.poly[k].exponent;
    }

    free(sum.poly);

    return final_sum;
}

double eval(const struct polynomial* p, double x) {
    double sum = 0;
    for (int i = 0; i < p->poly_size; i++) {
        sum += p->poly[i].coeff * pow(x, (double)p->poly[i].exponent);
    }
    return sum;
}

struct polynomial product(const struct polynomial* p1, const struct polynomial* p2) {
    struct polynomial prod;
    prod.poly_size = p1->poly_size * p2->poly_size;
    prod.poly = (struct element*)malloc(prod.poly_size * sizeof(struct element));

    int tail_index = 0;

    for (int i = 0; i < p1->poly_size; i++) {
        for (int j = 0; j < p2->poly_size; j++) {
            prod.poly[tail_index].coeff = p1->poly[i].coeff * p2->poly[j].coeff;
            prod.poly[tail_index].exponent = p1->poly[i].exponent + p2->poly[j].exponent;
            tail_index++;
        }
    }


    for (int k1 = 0; k1 < prod.poly_size; k1++) {
        for (int k2 = k1 + 1; k2 < prod.poly_size; k2++) {
            if (prod.poly[k1].exponent == prod.poly[k2].exponent) {
                prod.poly[k1].coeff += prod.poly[k2].coeff;
                prod.poly[k2].coeff = 0;
                prod.poly[k2].exponent = 0;
            }
        }
    }

    return prod;
}

void destroy(struct polynomial* p) {
    free(p->poly);
    p->poly_size = 0;
}
/*
int main() {

    struct polynomial p1, p2, sum_poly, prod_poly;
    double x;

    printf("Polynomial 1:\n");
    init(&p1);
    display(&p1);

    printf("Polynomial 2:\n");
    init(&p2);
    display(&p2);

    printf("Sum of Polynomials:\n");
    sum_poly = sum(&p1, &p2);
    display(&sum_poly);

    printf("Enter the value of x for evaluation: ");
    scanf("%lf", &x);
    printf("Evaluation of Polynomial 1 at x=%.2lf: %.2lf\n", x, eval(&p1, x));
    printf("Evaluation of Polynomial 2 at x=%.2lf: %.2lf\n", x, eval(&p2, x));

    printf("Product of Polynomials:\n");
    prod_poly = product(&p1, &p2);
    display(&prod_poly);

    destroy(&p1);
    destroy(&p2);
    destroy(&sum_poly);
    destroy(&prod_poly);

    return 0;
}
*/