#include <iostream>
#include "lab3.h"

int main()
{
    Matrix mat(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat.set(i, j, i * 3 + j + 1);
        }
    }
    mat.print();
    std::cout << Lab3::odd_sum(mat);
    
}
