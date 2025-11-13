#include <iostream>
using namespace std;

int main() {
    const int N = 6;
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri interi:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int massimo = arr[0];
    int minimo = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > massimo) {
            massimo = arr[i];
        }
        if (arr[i] < minimo) {
            minimo = arr[i];
        }
    }

    cout << "Massimo = " << massimo << endl;
    cout << "Minimo = " << minimo << endl;

    return 0;
}