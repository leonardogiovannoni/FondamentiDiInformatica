#include <iostream>
using namespace std;


// Sia n ∈ ℕ, v = (v₀,...,vₙ₋₁) ∈ ℤⁿ, x ∈ ℤ. Per 0 ≤ k ≤ n definiamo
// 
//                       ⎧ 0                       se k = 0,
//                       ⎪
//          f(v, k, x) = ⎨ 1                       se k > 0 ∧ vₖ₋₁ = x,
//                       ⎪
//                       ⎩ f(v, k - 1, x)          se k > 0 ∧ vₖ₋₁ ≠ x.
// 
// 
// contains(v, n, x) = f(v, n, x)

bool contains(int arr[], int n, int x) {
    if (n == 0) {
        return false;
    }

    if (arr[n - 1] == x) {
        return true;
    }

    return contains(arr, n - 1, x);
}


// Esempio con array [3, 7, 1, 9, 2] e ricerca di x = 9
//
// Chiamata iniziale: contains([3, 7, 1, 9, 2], 5, 9)
//
// Passo 1: Controllo arr[4] = 2
//     ┌───┬───┬───┬───┬───┐
//     │ 3 │ 7 │ 1 │ 9 │ 2 │  ← arr[4] = 2 ≠ 9, continua
//     └───┴───┴───┴───┴───┘
//                       ↑ controlla questo
//                       └─ ricorsione su n=4
//
// Passo 2: Controllo arr[3] = 9
//     ┌───┬───┬───┬───┬───┐
//     │ 3 │ 7 │ 1 │ 9 │ 2 │  ← arr[3] = 9 = 9, TROVATO!
//     └───┴───┴───┴───┴───┘
//                   ↑ controlla questo
//                   └─ return true
//
// Risultato: true (elemento trovato)
//
//
// Esempio con array [3, 7, 1, 9, 2] e ricerca di x = 5
//
// Chiamata iniziale: contains([3, 7, 1, 9, 2], 5, 5)
//
// Passo 1: arr[4] = 2 ≠ 5  →  ricorsione su n=4
// Passo 2: arr[3] = 9 ≠ 5  →  ricorsione su n=3
// Passo 3: arr[2] = 1 ≠ 5  →  ricorsione su n=2
// Passo 4: arr[1] = 7 ≠ 5  →  ricorsione su n=1
// Passo 5: arr[0] = 3 ≠ 5  →  ricorsione su n=0
// Passo 6: n = 0 (caso base)  →  return false
//
//     ┌───┬───┬───┬───┬───┐
//     │ 3 │ 7 │ 1 │ 9 │ 2 │  ← Tutti controllati, nessuno = 5
//     └───┴───┴───┴───┴───┘
//       ×   ×   ×   ×   ×
//
// Risultato: false (elemento non trovato)


// Alternativa con indice `i`, più simile a come
// lo faremmo con un ciclo for
// ```
// bool contains(int arr[], int n, int x, int i = 0) {
//     if (i == n) {
//         return false;
//     }
// 
//     if (arr[i] == x) {
//         return true;
//     }
// 
//     return contains(arr, n, i + 1);
// }
// ```

int main() {
    const int N = 7;
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Inserisci il valore da cercare: ";
    cin >> x;

    if (contains(arr, N, x)) {
        cout << x << " e' presente nell'array." << endl;
    } else {
        cout << x << " NON e' presente nell'array." << endl;
    }

    return 0;
}
