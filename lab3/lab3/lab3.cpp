#include "lab3.h"
#include <iostream>

int Lab3::max3(int a, int b, int c) {     // 1) a > b, a < c
    int max;                              // 2) a > b, a >= c
    if (a > b)                            // 3) a <= b, b < c
        max = a;                          // 4) a <= b, b >= c
    else
        max = b;
    if (max < c)
        max = c;
    return max;
}

int Lab3::magic(unsigned int a) {        // 1) a == 0
    int b = 0;                           // 2) a > 1000
    int i = 1;
    while (a > 0)
    {
        if (i % 2 == 0) {
            int digit = a % 10;
            b = b * 10 + digit;
        }
        i++;
        a /= 10;
    }
    return b;
}

int Lab3::min_digit(unsigned int a) {            // 1) a == 0
    int min = 10;                                // 2) a == 5634
    if (a == 0) {
        return 0;
    }
    while (a > 0)
    {
        if (a % 10 < min)
            min = a % 10;
        a /= 10;
    }
    return min;
}

int Lab3::odd_sum(Matrix& mat) {                // 1) rows != cols
    if (mat.rows != mat.cols)                   // 2) rows == 0
        throw "Matrix is not square";           // 3) rows == 1
    int sum = 0;                                // 4) rows > 1, cols == rows, elements odd
    for (int i = 0;                             // 5) rows > 1, cols == rows, elements even
        i < mat.rows;
        i++) {
        for (int j = 0;
            j < i;
            j++) {
            if (mat.get(i, j) % 2 != 0) {
                sum += mat.get(i, j);
            }
        }
    }
    return sum;
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
}

void Matrix::set(int row, int col, int value) {
    if (row < rows && col < cols) {
        arr[row][col] = value;
    }
}

int Matrix::get(int row, int col) {
    if (row < rows && col < cols) {
        return arr[row][col];
    }
}

void Matrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}