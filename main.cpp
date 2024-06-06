#include <iostream>
using namespace std;

void Draw(int N) {
    if (N > 0) {
        cout << '*';
        Draw(N - 1);
    }
}

int main() {
    int N;
    cout << "Enter stars amount: ";
    cin >> N;

    Draw(N);
    cout << endl;

    return 0;
}
