#include "utils.h"

MinElementResult findMinElement(const std::vector<int>& arr) {
    if (arr.empty()) {
        return { 0, -1 };
    }

    int minVal = arr[0];
    int minIndex = 0;

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }

    return { minVal, minIndex };
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

MinElement2DArrayResult findMinElement(const std::vector<std::vector<int>>& arr) {
    if (arr.empty()) {
        return { 0, -1, -1 };
    }

    int minValue = arr[0][0];
    int minIndexI = 0;
    int minIndexJ = 0;

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            if (arr[i][j] < minValue) {
                minValue = arr[i][j];
                minIndexI = i;
                minIndexJ = j;
            }
        }
    }

    return { minValue, minIndexI, minIndexJ };
}

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void cyclicShiftLeft(int arr[], int size, int positions) {
    if (size <= 1) {
        return;
    }

    positions %= size;

    if (positions < 0) {
        positions += size;
    }

    int temp;
    for (int i = 0; i < positions; i++) {
        temp = arr[0];
        for (int j = 0; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
    }
}

void replaceAll(int arr[], int size, int target, int newValue) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            arr[i] = newValue;
        }
    }
}