//
// Created by vladik on 14.05.2021.
//

#ifndef INTEGRAL_HEADER_H
#define INTEGRAL_HEADER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int count;


extern double f1(double);
extern double f2(double);
extern double f3(double);
extern double df1(double);
extern double df2(double);
extern double df3(double);
extern double ddf1(double);
extern double ddf2(double);
extern double ddf3(double);
extern void test_root(void);
extern void test_integral(void);
extern void print_absciss(void);
extern void count_iterations(void);
extern void help(void);
extern void print_res(void);
extern double root(double (double), double (double), double (double), double (double), double (double), double (double), double, double, double);
extern double integral(double (double), double, double, double);

#endif //INTEGRAL_HEADER_H
