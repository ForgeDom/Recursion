#include <iostream>
#include <ctime>
using namespace std;

void generateNumber(int number[], int size) {
    srand(time(0)); 
    for (int i = 0; i < size; i++) {
        number[i] = rand() % 10; 
    }
}

void countBullsAndCows(int secret[], int guess[], int size, int& bulls, int& cows) {
    bulls = 0;
    cows = 0;
    bool usedSecret[4] = { false, false, false, false }; 
    bool usedGuess[4] = { false, false, false, false }; 

    for (int i = 0; i < size; i++) {
        if (guess[i] == secret[i]) {
            bulls++;
            usedSecret[i] = true;
            usedGuess[i] = true;
        }
    }

    for (int i = 0; i < size; i++) {
        if (!usedGuess[i]) {
            for (int j = 0; j < size; j++) {
                if (!usedSecret[j] && guess[i] == secret[j]) {
                    cows++;
                    usedSecret[j] = true;
                    break;
                }
            }
        }
    }
}

void playGame(int secret[], int size, int attempts = 0) {
    int guess[4];
    cout << "Введіть ваше чотирицифрове число: ";

    for (int i = 0; i < size; i++) {
        char digit;
        cin >> digit;
        guess[i] = digit - '0'; 
    }

    int bulls, cows;
    countBullsAndCows(secret, guess, size, bulls, cows);

    if (bulls == size) {
        cout << "Вітаємо! Ви відгадали число за " << attempts + 1 << " спроб." << endl;
        return;
    }
    else {
        cout << "Бики: " << bulls << ", Корови: " << cows << endl;
        playGame(secret, size, attempts + 1);  
    }
}

int main() {
    const int size = 4;
    int secretNumber[size];

    generateNumber(secretNumber, size);

    playGame(secretNumber, size);

    return 0;
}
