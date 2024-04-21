#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

struct element {
    double coeff;
    int exponent;
};

struct polynomial {
    struct element* poly;
    int poly_size;
};

void init(struct polynomial* p);
void display(const struct polynomial* p);
struct polynomial sum(const struct polynomial* p1, const struct polynomial* p2);
double eval(const struct polynomial* p, double x);
struct polynomial product(const struct polynomial* p1, const struct polynomial* p2);
void destroy(struct polynomial* p);

#endif