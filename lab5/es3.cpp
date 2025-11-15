#include <iostream>
using namespace std;

bool tutti_pari(int arr[], int n) {
    if (n == 0) {
        return true;
    }

    if (arr[n - 1] % 2 != 0) {
        return false;
    }

    return tutti_pari(arr, n - 1);
}

int main() {
    const int N = 10;
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

    bool rv = tutti_pari(arr, N);

    if (rv) {
        cout << "Gli elementi sono tutti pari" << endl;
    } else {
        cout << "Non tutti gli elementi sono pari" << endl;
    }
}