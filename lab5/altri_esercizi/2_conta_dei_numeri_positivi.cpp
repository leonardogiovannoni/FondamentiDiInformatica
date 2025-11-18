#include <iostream>
using namespace std;


// Sia n ∈ ℕ, v = (v_0,...,v_{n-1}) ∈ ℤⁿ. Per 0 ≤ k ≤ n definiamo
// 
//                     ⎧ 0                      se k = 0,
//                     ⎪
//          f(v, k) =  ⎨ f(v, k - 1) + 1        se k > 0 e v_{k-1} > 0,
//                     ⎪
//                     ⎩ f(v, k - 1)            se k > 0 e v_{k-1} ≤ 0.
// 
// 
// conta_positivi(v, n) = f(v, n)

int conta_positivi(int v[], int n) {
    if (n == 0) {
        return 0;
    }

    int curr_is_pos = 0;
    if (v[n - 1] > 0) {
        curr_is_pos = 1;
    }

    return curr_is_pos + conta_positivi(v, n - 1);
}



// Alternativa con indice di posizione, più simile a come
// lo faremmo con un ciclo for
// ```
// int conta_positivi(int v[], int n, int i = 0) {
//     if (i == n) {
//         return 0;
//     }
// 
//     int curr_is_pos = 0;
//     if (v[i] > 0) {
//         curr_is_pos = 1;
//     }
// 
//     return curr_is_pos + conta_positivi(v, n, i + 1);
// }
// ```

int main() {
    const int N = 8;
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Ci sono " << conta_positivi(arr, N) << " numeri positivi." << endl;

    return 0;
}
