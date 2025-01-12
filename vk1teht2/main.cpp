#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum);

int main() {
    int maxnum;

    cout << "Give me biggest number you want to seach: ";
    cin >> maxnum;

    int arvausten_maara = game(maxnum);

    cout << "You guessed correctly with " << arvausten_maara << " guesses!" << endl;

    return 0;
}

int game(int maxnum) {
    srand(time(0));
    int tavoite = rand() % maxnum + 1;

    int arvaus, yritykset = 0;

    cout << "Give me a number between 1-" << maxnum << "." << endl;

    while (true) {
        cout << "Guess: ";
        cin >> arvaus;

        yritykset++;

        if (arvaus < tavoite) {
            cout << "Number is bigger." << endl;
        } else if (arvaus > tavoite) {
            cout << "Number is smaller." << endl;
        } else {
            cout << "Correct! Number was: " << tavoite << endl;
            break;
        }
    }

    return yritykset;
}
