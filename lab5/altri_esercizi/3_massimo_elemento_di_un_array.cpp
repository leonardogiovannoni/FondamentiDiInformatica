#include <iostream>
using namespace std;


// Sia n ∈ ℕ, v = (v_0,...,v_{n-1}) ∈ ℤⁿ. Per 0 ≤ k ≤ n definiamo
// 
//                     ⎧ -1                             se k = 0
//                     ⎪ 
//          f(v, k) =  ⎨ v_0                            se k = 1
//                     ⎪ 
//                     ⎩ max(v_{k-1}, f(v, k - 1))      se k > 1
// 
// 
// massimo(v, n) = f(v, n)

int massimo(int arr[], int n) {
    if (n == 0) {
        return -1; // Array vuoto
    }

    if (n == 1) {
        return arr[0];
    }

    int cur_max = massimo(arr, n - 1);

    if (arr[n - 1] > cur_max) {
        cur_max = arr[n - 1];
    }

    return cur_max;
}

// Un altro approccio più robusto è quello di creare una funzione `massimo`
// fatta così:
//
// ```
// bool massimo(int arr[], int n, int& max_val) {
//     if (n == 0) {
//         return false; // Array vuoto
//     }
// 
//     if (n == 1) {
//         max_val = arr[0];
//         return true;
//     }
// 
//     bool prev_contains_values = massimo(arr, n - 1, max_val);
// 
//     if (!prev_contains_values || arr[n - 1] > max_val) {
//         max_val = arr[n - 1];
//     }
// 
//     return true;
// }
// ```
//
// In cui il valore di ritorno è un booleano che ci indica se il risultato è 
// valido o meno, nel caso di array di dimensione 0.
// Questo ci permette di non dover limitare l'input a numeri solo positivi.
// Nel main, il codice sarà una cosa del genere:
// ```
// int main() {
//     ... 
//     int max_val = 0;
//     if (!massimo(arr, N, max_val)) {
//         cout << "Array vuoto, nessun valore massimo." << endl;
//     } else {
//         cout << "Il valore massimo è: " << max_val << endl;
//     }
// }
// ```
// Nel caso in cui la funzione ritorni false, il valore di `max_val` non viene
// letto, in quanto la funzione ci sta dicendo che il suo valore non è valido.


int main() {
    const int N = 6;
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri positivi:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            cout << "Inserisci solo numeri positivi" << endl;
            return 0;
        }
    }

    int max_val = massimo(arr, N);
    if (max_val < 0) {
        cout << "Array vuoto, nessun valore massimo." << endl;
    } else {
        cout << "Il valore massimo è: " << max_val << endl;
    }

    return 0;
}

