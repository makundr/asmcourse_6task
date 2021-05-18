#include "header.h"

void help(void) {
    printf("--count_iterations\t");
    printf("Число итераций, потребовавшихся на приближенное решение уравнений при поиске точек пересечения\n");
    printf("--print_absciss   \t");
    printf("Печать абсцисс точек пересечения кривых\n");
    printf("--test_root       \t");
    printf("Тестирование функции нахождения корня\n");
    printf("--test_integral   \t");
    printf("Тестирование функции нахождения интеграла\n");
    printf("--help            \t");
    printf("Помощь\n");
    printf("По умолчанию программа выводит результат вычисления площади\n");
}

void print_res(void) {
    double min_x = 0.1;
    double max_x = 3;
    double eps = 0.0001;
    double eps_i = 0.001;

    double a = root(f1, f2, df1, df2, ddf1, ddf2, min_x, max_x, eps);
    double b = root(f1, f3, df1, df3, ddf1, ddf3, 0.2, 0.3, eps);

    double square = integral(f1, b, a, eps_i);

    b = root(f2, f3, df2, df3, ddf2, ddf3, min_x, max_x, eps);

    square -= integral(f2, b, a, eps_i);

    a = root(f1, f3, df1, df3, ddf1, ddf3, 0.2, 0.3, eps);

    square -= integral(f3, a, b, eps);

    printf("Площадь равна: %lf\n", square);

}

void test_root(void) {
    printf("Напишите два номера функции(1, 2, 3)\n");
    int f;
    int g;
    scanf("%d %d", &f, &g);
    printf("Введите точность eps\n");
    double eps;
    scanf("%lf", &eps);
    double a = 0;
    if (f == 1 && g == 2) {
        a = root(f1, f2, df1, df2, ddf1, ddf2, 0.1, 3, eps);
    } else if (f == 1 && g == 3) {
        a = root(f1, f3, df1, df3, ddf1, ddf3, 0.2, 0.3, eps);
    } else if (f == 2 && g == 3) {
        a = root(f2, f3, df2, df3, ddf2, ddf3, 0.1, 3, eps);
    }
    printf("%lf\n", a);
}

void test_integral(void) {
    printf("Напишите номер функции(1, 2, 3)\n");
    int f;
    scanf("%d", &f);

    double a;
    double b;
    double eps;

    printf("Границы интегрирования: ");
    scanf("%lf %lf", &a, &b);
    printf("Точность: ");
    scanf("%lf", &eps);
    double square = 0;
    if (f == 1) {
        square = integral(f1, a, b, eps);
    }
    if (f == 2) {
        square = integral(f2, a, b, eps);
    }
    if (f == 3) {
        square = integral(f3, a, b, eps);
    }
    printf("%lf\n", square);
}

void print_absciss(void) {
    double min_x = 0.1;
    double max_x = 3;
    double eps = 0.0001;

    double a = root(f1, f2, df1, df2, ddf1, ddf2, min_x, max_x, eps);
    double b = root(f1, f3, df1, df3, ddf1, ddf3, 0.2, 0.3, eps);

    printf("Точки перечечения f1 \t c f2: %lf \t с f3: %lf\n", a, b);

    b = root(f2, f3, df2, df3, ddf2, ddf3, min_x, max_x, eps);

    printf("Точки перечечения f2 \t c f1: %lf \t с f3: %lf\n", a, b);

    a = root(f1, f3, df1, df3, ddf1, ddf3, 0.2, 0.3, eps);

    printf("Точки перечечения f3 \t c f1: %lf \t с f2: %lf\n", a, b);
}

void count_iterations(void) {
    double min_x = 0.1;
    double max_x = 3;
    double eps = 0.001;

    root(f2, f3, df2, df3, ddf2, ddf3, min_x, max_x, eps);
    printf("Количество итераций равно %d\n", count);
}