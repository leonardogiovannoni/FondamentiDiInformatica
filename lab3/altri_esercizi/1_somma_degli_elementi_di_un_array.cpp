#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri interi:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int somma = 0;
    for (int i = 0; i < N; i++) {
        somma += arr[i];
    }

    cout << "Somma = " << somma << endl;

    return 0;
}