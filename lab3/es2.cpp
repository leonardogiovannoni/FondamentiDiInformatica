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

    bool crescente = true;
    for (int i = 0; i < N - 1 && crescente; i++) {
        bool condizione_di_crescita = (arr[i] < arr[i + 1]);
        if (!condizione_di_crescita) {
            crescente = false;
        }
    }

    if (crescente) {
        cout << "L'array e' crescente" << endl;
    } else {
        cout << "L'array non e' crescente" << endl;
    }

    return 0;
}
