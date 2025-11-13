#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri interi:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int count_negativi = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            count_negativi++;
        }
    }

    cout << "Numeri negativi: " << count_negativi << endl;

    return 0;
}