#include <iostream>
#include <ctime>
#include <Windows.h>
#include <chrono>
#include <thread>
using namespace std;

const int size1 = 5;
const int size2 = 5;
const int size3 = 5;

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMax(int arr[][size2], int rows, int cols) {
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

int findMax(int arr[][size2][size3], int x, int y, int z) {
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
    return findMax(findMax(a, b), c);
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    int arr1[size1];
    int arr2[size1][size2];
    int arr3[size1][size2][size3];
    for (int i = 0; i < size1; ++i) {
        arr1[i] = rand() % 100;
    }

    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            arr2[i][j] = rand() % 100;
        }
    }
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            for (int k = 0; k < size3; ++k) {
                arr3[i][j][k] = rand() % 100;
            }
        }
    }

    for (int i = 0; i < size1; ++i) {
        cout << arr1[i] << " ";
    }
    cout << endl << "-------------" << endl;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "-------------" << endl;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            for (int k = 0; k < size3; ++k) {
                cout << arr3[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Максимальне значення в одновимірному масиві: " << findMax(arr1, size1) << endl;
    cout << "Максимальне значення в двовимірному масиві: " << findMax(arr2, size1, size2) << endl;
    cout << "Максимальне значення в тривимірному масиві: " << findMax(arr3, size1, size2, size3) << endl;
    cout << "Максимальне значення між двома цілими числами (3 і 7): " << findMax(3, 7) << endl;
    cout << "Максимальне значення між трьома цілими числами (3, 7 і 5): " << findMax(3, 7, 5) << endl;
    return 0;
}
