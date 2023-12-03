#include "TPoly.h"
#include <iostream>

int main()
{
    TPoly a[] = { TPoly(1, 2), TPoly(2, 1), TPoly(3, 0) }; // x^2 + 2x + 3
    TPoly b[] = { TPoly(5, 1), TPoly(4, 0) };                // 5x + 4
    TPoly poly_a, poly_b;
    for (int i = 0; i < 3; i++) {
        poly_a = poly_a + a[i];
    }
    for (int i = 0; i < 2; i++) {
        poly_b = poly_b + b[i];
    }
    TPoly res = poly_a * poly_b;
}
