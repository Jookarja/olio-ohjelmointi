#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void peli() {
    srand(time(0));
    int tavoite = rand() % 20 + 1;

    cout << "Guess a number between 1 and 20." << endl;

    while (true) {
        cout << "Guess: ";
        int arvaus;
        cin >> arvaus;

        if (arvaus < tavoite) {
            cout << "Number is bigger." << endl;
        } else if (arvaus > tavoite) {
            cout << "Number is smaller." << endl;
        } else {
            cout << "Correct! Number was: " << tavoite << endl;
            break;
        }
    }
}

int main() {
    peli();
    return 0;
}
