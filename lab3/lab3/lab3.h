#pragma once

class Matrix {
    int** arr;
public:
    int rows, cols;
    Matrix(int rows, int cols);
    void set(int row, int col, int value);
    int get(int row, int col);
    void print();
    ~Matrix();
};

class Lab3 {
public:
    static int max3(int a, int b, int c);
    static int magic(unsigned int a);
    static int min_digit(unsigned int a);
    static int odd_sum(Matrix& mat);
};