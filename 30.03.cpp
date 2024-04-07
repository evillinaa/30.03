#include <iostream>
#include <cstdlib>
#include <Windows.h>
using namespace std;



void generateRandomArr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
}


int findMinSequence(int arr[], int start) {
    if (start > 90) {
        return -1;
    }

    int minSum = arr[start] + arr[start + 1] + arr[start + 2] + arr[start + 3] + arr[start + 4] +
        arr[start + 5] + arr[start + 6] + arr[start + 7] + arr[start + 8] + arr[start + 9];

    int nMinSumPos = findMinSequence(arr, start + 1);

    if (nMinSumPos == -1) {
        return start;
    }

    int nMinSum = arr[nMinSumPos] + arr[nMinSumPos + 1] + arr[nMinSumPos + 2] +
        arr[nMinSumPos + 3] + arr[nMinSumPos + 4] + arr[nMinSumPos + 5] +
        arr[nMinSumPos + 6] + arr[nMinSumPos + 7] + arr[nMinSumPos + 8] +
        arr[nMinSumPos + 9];

    return (minSum < nMinSum) ? start : nMinSumPos;
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMax(int arr[][3], int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int findMax(int arr[][3][2], int x, int y, int z) {
    int max = arr[0][0][0];
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                if (arr[i][j][k] > max) {
                    max = arr[i][j][k];
                }
            }
        }
    }
    return max;
}

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int findMax(int a, int b, int c) {
    return max(a, b), c;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[100];
    generateRandomArr(arr, 100);

    int startPos = findMinSequence(arr, 0);

    cout << startPos << endl;

    int arr1D[] = { 3, 7, 2, 8, 1, 9, 6, 4, 5 };
    int arr2D[2][3] = { {1, 5, 3}, {9, 2, 6} };
    int arr3D[1][3][2] = { { {4, 8}, {3, 1}, {7, 2} } };

    cout << "максимальное значение: " << findMax(arr1D, 9) << endl;
    cout << "максимальное значение(в двумерном массиве): " << findMax(arr2D, 2, 3) << endl;
    cout << "максимальное значение(в трехмерном массиве):: " << findMax(arr3D, 1, 3, 2) << endl;
    cout << "максимальное значение двух целых: " << findMax(10, 5) << endl;
    cout << "максимальное значение трех целых: " << findMax(3, 7, 2) << endl;

    return 0;
}