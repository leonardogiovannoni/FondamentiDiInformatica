#include <iostream>
using namespace std;


// Definiamo, per n ∈ ℕ, la funzione f(n) (fattoriale di n):
// 
//                     f(n) = n × (n - 1) × (n - 2) × ... × 2 × 1
// 
// mentre banalmente f(0) = 1 per definizione.
// Osserviamo che:
//                     f(n) = n × (n - 1) × (n - 2) × ... × 2 × 1
//                                └────────────┬────────────────┘
//                                          f(n - 1)
// 
// Otteniamo quindi la seguente definizione ricorsiva:
// 
//                          ⎧ 1,               se n = 0,
//                   f(n) = ⎨
//                          ⎩ n × f(n - 1),    se n > 0.
// 

int fattoriale(int n) {
    if (n == 0) { 
        return 1;
    }
    return n * fattoriale(n - 1);
}

int main() {
    int n = 0;

    cout << "Inserisci un numero intero positivo: ";
    cin >> n;

    cout << "Il fattoriale di " << n << " e': " << fattoriale(n) << endl;

    return 0;
}

