#include "header.h"

int count;

double root(double (*f)(double), double (*g)(double), double (*df)(double), double (*dg)(double), double (*ddf)(double), double (*ddg)(double), double a, double b, double eps1){
    count = 0;
    while (fabs(a - b) > 2 * eps1) {
        if ((f(a) - g(a))*(ddf(a) - ddg(a)) < 0) {
            a = a - (f(a) - g(a))*(a - b)/((f(a) - g(a) - (f(b) - g(b))));
        } else {
            a = a - (f(a) - g(a))/(df(a) - dg(a));
        }
        if ((f(b) - g(b))*(ddf(b) - ddg(b)) < 0) {
            b = b - (f(b) - g(b))*(b - a)/((f(b) - g(b)) - (f(a) - g(a)));
        } else {
            b = b - (f(b) - g(b))/(df(b) - dg(b));
        }
        count++;
    }
    return (a+b)/2;
}

double integral(double (*f)(double), double a, double b, double eps2) {
    int n = 10;
    double h = (b - a) / n;
    double s1 = 0;
    for (int i = 0; i < n; i++) {
        s1 += (fabs(f(a + i*h) + f(a + (i + 1) * h))) * h / 2;
    }

    double s2 = s1;
    n *= 2;
    h /= 2;
    for (int i = 0; i < n; i++) {
        s2 += (fabs(f(a + i*h) + f(a + (i + 1) * h))) * h / 2;
    }

    while (fabs(s1 - s2) / 3 > eps2) {
        s1 = s2;
        n *= 2;
        h /= 2;
        s2 = 0;
        for (int i = 0; i < n; i++) {
            s2 += (fabs(f(a + i*h) + f(a + (i + 1) * h))) * h / 2;
        }
    }

    return s2;
}

