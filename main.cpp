#include <iostream>
#include <ctime>

using namespace std;

void initMatrix(int** matrix, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void initMatrix(double** matrix, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (rand() % 10000) / 100.0;
        }
    }
}

void initMatrix(char** matrix, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 'A' + rand() % 26;
        }
    }
}

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void printMatrix(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void printMatrix(char** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void findMinMaxDiag(int** matrix, int size, int& minElem, int& maxElem) {
    minElem = maxElem = matrix[0][0];
    for (int i = 1; i < size; i++) {
        if (matrix[i][i] < minElem) minElem = matrix[i][i];
        if (matrix[i][i] > maxElem) maxElem = matrix[i][i];
    }
}

void findMinMaxDiag(double** matrix, int size, double& minElem, double& maxElem) {
    minElem = maxElem = matrix[0][0];
    for (int i = 1; i < size; i++) {
        if (matrix[i][i] < minElem) minElem = matrix[i][i];
        if (matrix[i][i] > maxElem) maxElem = matrix[i][i];
    }
}

void findMinMaxDiag(char** matrix, int size, char& minElem, char& maxElem) {
    minElem = maxElem = matrix[0][0];
    for (int i = 1; i < size; i++) {
        if (matrix[i][i] < minElem) minElem = matrix[i][i];
        if (matrix[i][i] > maxElem) maxElem = matrix[i][i];
    }
}

void sortRow(int* row, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (row[j] > row[j + 1]) {
                int temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

void sortRow(double* row, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (row[j] > row[j + 1]) {
                double temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

void sortRow(char* row, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (row[j] > row[j + 1]) {
                char temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

void sortRows(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        sortRow(matrix[i], size);
    }
}

void sortRows(double** matrix, int size) {
    for (int i = 0; i < size; i++) {
        sortRow(matrix[i], size);
    }
}

void sortRows(char** matrix, int size) {
    for (int i = 0; i < size; i++) {
        sortRow(matrix[i], size);
    }
}

int main() {
    int size = 4;

    int** intMatrix = new int* [size];
    for (int i = 0; i < size; i++) {
        intMatrix[i] = new int[size];
    }
    initMatrix(intMatrix, size);
    cout << "Int matrix:" << endl;
    printMatrix(intMatrix, size);

    int minInt, maxInt;
    findMinMaxDiag(intMatrix, size, minInt, maxInt);
    cout << "Min on diag: " << minInt << ", Max on diag: " << maxInt << endl;

    sortRows(intMatrix, size);
    cout << "Sorted int matrix:" << endl;
    printMatrix(intMatrix, size);

    double** doubleMatrix = new double* [size];
    for (int i = 0; i < size; i++) {
        doubleMatrix[i] = new double[size];
    }
    initMatrix(doubleMatrix, size);
    cout << "\nDouble matrix:" << endl;
    printMatrix(doubleMatrix, size);

    double minDouble, maxDouble;
    findMinMaxDiag(doubleMatrix, size, minDouble, maxDouble);
    cout << "Min on diag: " << minDouble << ", Max on diag: " << maxDouble << endl;

    sortRows(doubleMatrix, size);
    cout << "Sorted double matrix:" << endl;
    printMatrix(doubleMatrix, size);

    char** charMatrix = new char* [size];
    for (int i = 0; i < size; i++) {
        charMatrix[i] = new char[size];
    }
    initMatrix(charMatrix, size);
    cout << "\nChar matrix:" << endl;
    printMatrix(charMatrix, size);

    char minChar, maxChar;
    findMinMaxDiag(charMatrix, size, minChar, maxChar);
    cout << "Min on diag: " << minChar << ", Max on diag: " << maxChar << endl;

    sortRows(charMatrix, size);
    cout << "Sorted char matrix:" << endl;
    printMatrix(charMatrix, size);

    for (int i = 0; i < size; i++) {
        delete[] intMatrix[i];
        delete[] doubleMatrix[i];
        delete[] charMatrix[i];
    }
    delete[] intMatrix;
    delete[] doubleMatrix;
    delete[] charMatrix;

    return 0;
}
