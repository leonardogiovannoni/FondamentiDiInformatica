#include <iostream>
using namespace std;


int main() {
    const int N = 5;
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri interi:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    bool palindromo = true;
    // { 0, 1, 2, . . . , ⌊N / 2⌋ − 1 } => intervallo [0, N / 2 - 1] = [0, N / 2)
    for (int i = 0; i < N / 2 && palindromo; i++) {
        if (arr[i] != arr[N - 1 - i]) {
            palindromo = false;
        }
    }

    if (palindromo) {
        cout << "palindromo? si" << endl;
    } else {
        cout << "palindromo? no" << endl;
    }

    return 0;
}