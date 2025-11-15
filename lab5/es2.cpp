#include <iostream>
using namespace std;

void scambia(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void inverti(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        scambia(&arr[i], &arr[n - 1 - i]);
    }
}

int main() {
    const int N = 5;
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri interi:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Array: ";

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    
    inverti(arr, N);

    cout << "Array invertito: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


