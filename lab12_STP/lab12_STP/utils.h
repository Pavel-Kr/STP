#pragma once

#include <vector>

struct MinElementResult {
    int value;
    int index;
};

struct MinElement2DArrayResult {
    int value;
    int indexI;
    int indexJ;
};

MinElementResult findMinElement(const std::vector<int>& arr);
void bubbleSort(int arr[], int n);
int binarySearch(int arr[], int n, int target);
MinElement2DArrayResult findMinElement(const std::vector<std::vector<int>>& arr);
void reverseArray(int arr[], int size);
void cyclicShiftLeft(int arr[], int size, int positions);
void replaceAll(int arr[], int size, int target, int newValue);