#include <iostream>
using namespace std;


// Sia n ∈ ℕ, v = (v_0,...,v_{n-1}) ∈ ℤⁿ. Definiamo informalmente la funzione f(v, n) che
// restituisce l'array invertito:
// 
//                     ⎧ v                                                       se n ≤ 1
//          f(v, n) =  ⎨ 
//                     ⎩ (v_{n-1}) ⊕ f((v_1,...,v_{n-2}), n - 2) ⊕ (v_0)       se n > 1
// 
// 
// dove ⊕ rappresenta la concatenazione di vettori.
// 
// inverti(v, n) restituisce f(v, n)

void scambia(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void inverti(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    scambia(&arr[0], &arr[n - 1]);
    inverti(&arr[1], n - 2);
}


// Esempio con array [1, 2, 3, 4, 5, 6]
//
// Chiamata iniziale: inverti([1, 2, 3, 4, 5, 6], 6)
//
// Array iniziale
//     ┌───┬───┬───┬───┬───┬───┐
//     │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │
//     └───┴───┴───┴───┴───┴───┘
//       ↑                   ↑
//       └──────scambia──────┘
//
// Chiamata ricorsiva su [2, 3, 4, 5]
//     ┌───┬───┬───┬───┬───┬───┐
//     │ 6 │ 2 │ 3 │ 4 │ 5 │ 1 │
//     └───┴───┴───┴───┴───┴───┘
//           ↑           ↑
//           └──scambia──┘
//
// Chiamata ricorsiva su [3, 4]
//     ┌───┬───┬───┬───┬───┬───┐
//     │ 6 │ 5 │ 3 │ 4 │ 2 │ 1 │
//     └───┴───┴───┴───┴───┴───┘
//               ↑   ↑
//               └───┘
//              scambia
//
// Dopo scambio(arr[2], arr[3])
//     ┌───┬───┬───┬───┬───┬───┐
//     │ 6 │ 5 │ 4 │ 3 │ 2 │ 1 │  ← Array completamente invertito
//     └───┴───┴───┴───┴───┴───┘
//
// La ricorsione termina perché il sottovettore ha dimensione 0.

int main() {
    const int N = 8;
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    inverti(&arr[0], N);

    cout << "Array invertito: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
