/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<cmath>
#include<math.h>

double f(double x) {
    return exp(x) - 4.4 * x;
}

double fi(double x) {
    return exp(x) / 4.4;
}

double fi2(double x) {
    return (exp(x) - x) / 3.4;
}

void m_H(double x0, double e, double df) {
    std::cout << "Модифицированный метод Ньютона: " << '\n';
    double xn = x0;
    double xn1 = xn - f(xn) / df;
    int n = 1;


    while (fabs(xn1 - xn) >= e) {
        n++;
        xn = xn1;
        xn1 = xn - f(xn) / df;
    }

    std::cout << "Полученный корень : " << xn1 << '\n';
    std::cout << "Количество итерации : " << n << '\n';

}

void m_X(double x0, double x1, double e) {
    std::cout << "Метод хорд: " << '\n';
    double xn = x1;
    double xn1 = xn - f(xn) * (xn - x0) / (f(xn) - f(x0));
    int n = 1;



    while (fabs(xn1 - xn) >= e) {
        n++;
        xn = xn1;
        xn1 = xn - f(xn) * (xn - x0) / (f(xn) - f(x0));
    }

    std::cout << "Полученный корень : " << xn << '\n';
    std::cout << "Количество итерации : " << n << '\n';

}

void m_PIt(double x0, double e, double (*fun)(double)) {
    std::cout << "Метод простой итерации" << '\n';
    double xn = x0;
    double xn1 = fun(xn);
    int n = 1;


    while (fabs(xn1 - xn) >= e) {
        n++;
        xn = xn1;
        xn1 = fun(xn);
    }

    std::cout << "Полученный корень : " << xn1 << '\n';
    std::cout << "Количество итерации : " << n << '\n';

}

int main()
{
    double (*fun)(double) = NULL;
    double (*fun2)(double) = NULL;
    fun = &fi;
    fun2 = &fi2;
    double e = 0.5 * pow(10, -5);
    double x0 = 0;
    double x1 = 1;
    double df = exp(x0) - 4.4;
    for (int i = 0; i < 2; i++) {
        m_H(x0, e, df);
        m_X(x0, x1, e);
        m_PIt(x0, e, fun);
        m_PIt(x0, e, fun2);
        x0 = 0.3;
        df = exp(x0) - 4.4;
        std::cout << '\n' << '\n';
    }

    return 0;
}