#include <iostream>
using namespace std;

int Calcul(int a, int b, int sum = 0) {
    if (a <= b) {
        sum += a;
        return Calcul(++a, b, sum);
    }
    else {
        return sum;
    }
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << Calcul(a, b) << endl;
    return 0;
}
