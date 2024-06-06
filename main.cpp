#include <iostream>
using namespace std;

int func(int a, int b) {
    if (b == 0) {
        return a; 
    }
    return func(b, a % b); 
}

int main() {
    int num1, num2;
    cin >> num1;
    cin >> num2;

    cout << func(num1, num2) << endl;

    return 0;
}
