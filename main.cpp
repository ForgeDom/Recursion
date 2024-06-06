#include <iostream>
using namespace std;

int stepin(int a, int b, int i = 0, int result = 1) {
    if (i < b) {
        return stepin(a, b, ++i, result * a);
    }
    else {
        return result;
    }
}

int main() {
    cout << stepin(2, 3) << endl;
    return 0;
}
