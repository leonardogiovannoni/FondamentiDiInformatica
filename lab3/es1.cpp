#include <iostream>
using namespace std;

int main() {
    const int N = 6;
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri interi" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int num_pari = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 0) {
            num_pari++;
        }
    }
    cout << "Risultato: " << num_pari << endl;

    return 0;
}
