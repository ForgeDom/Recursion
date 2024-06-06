#include <iostream>
#include <ctime>

using namespace std;

const int max_size = 100;
const int length = 10;

int sum(int arr[], int start = 0) {
    int sum = 0;
    for (int i = start; i < start + length; i++) {
        sum += arr[i];
    }
    return sum;
}

int findMinSum(int arr[], int currentIndex, int minSum, int minIndex) {
    if (currentIndex > max_size - length) {
        return minIndex;
    }

    int currentSum = sum(arr, currentIndex);

    if (currentSum < minSum) {
        minSum = currentSum;
        minIndex = currentIndex;
    }

    return findMinSum(arr, currentIndex + 1, minSum, minIndex);
}

int main() {
    srand(time(0));

    int arr[max_size];

    for (int i = 0; i < max_size; i++) {
        arr[i] = rand() % 20;
    }

    cout << "Array: ";
    for (int i = 0; i < max_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int initialSum = sum(arr, 0);
    int minIndex = findMinSum(arr, 1, initialSum, 0);

    cout << "Position with the least sum: " << minIndex << endl;

    return 0;
}
