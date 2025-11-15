#include <iostream>
using namespace std;


// Sia n ∈ ℕ, v = (v_0,...,v_{n-1}) ∈ ℤⁿ. Per 0 ≤ k ≤ n definiamo
// 
//                     ⎧ 1              se k = 0,
//                     ⎪
//          f(v, k) =  ⎨ 0              se k > 0 e v_{k-1} è dispari,
//                     ⎪
//                     ⎩ f(v, k - 1)    se k > 0 e v_{k-1} è pari.
// 
// 

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
    int array[N] = {};
    cout << "Inserisci " << N << " numeri interi" << endl;

    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }

    cout << "Array: ";

    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }

    cout << endl;

    bool rv = tutti_pari(array, N);

    if (rv) {
        cout << "Gli elementi sono tutti pari" << endl;
    } else {
        cout << "Non tutti gli elementi sono pari" << endl;
    }
}

//
// ═══════════════════════════════════════════════════════════════════════════════════
// ESEMPIO CON ARRAY [2,4,6]
// ═══════════════════════════════════════════════════════════════════════════════════
//
// In questo esempio la ricorsione visita tutti gli elementi dell'array fino al caso
// base, perché ogni numero incontrato è pari. Ogni chiamata ricorsiva rimane in
// attesa che la successiva ritorni, creando così una catena completa di chiamate
// fino a f(v,0).
// 
// Chiamata iniziale a f([2,4,6], 3)    true
//                                       ↑
// f([2,4,6], 3)                         │
//     │                                 │
//     │ Controllo v[2] = 6              │
//     │ 6 è pari? SÌ!                   │
//     │ Chiamo f([2,4,6], 2)           true
//     │                                 ↑
//     ↓                                 │
//                                       │
// f([2,4,6], 2)                         │
//     │                                 │
//     │ Controllo v[1] = 4              │
//     │ 4 è pari? SÌ!                   │
//     │ Chiamo f([2,4,6], 1)           true
//     │                                 ↑
//     ↓                                 │
//                                       │
// f([2,4,6], 1)                         │
//     │                                 │
//     │ Controllo v[0] = 2              │
//     │ 2 è pari? SÌ!                   │
//     │ Chiamo f([2,4,6], 0)           true
//     │                                 ↑
//     ↓                                 │
//                                       │
// f([2,4,6], 0)                         │
//     │                                 │
//     │ n == 0 (caso base)              │
//     │ Restituisco true                │
//     └─────────────────────────────────┘
//
// FASE DI CHIAMATA (costruzione dello stack):
//
//
//     Stato 0:         Stato 1:             Stato 2:             Stato 3:             Stato 4:
//
//                                                                                     tutti_pari(0)
//                                                                tutti_pari(1)        tutti_pari(1)
//                                           tutti_pari(2)        tutti_pari(2)        tutti_pari(2)
//                      tutti_pari(3)        tutti_pari(3)        tutti_pari(3)        tutti_pari(3)
//     main()           main()               main()               main()               main()
//
// ↑ indirizzi numericamente più bassi
//
// ┌──────────────────┐ ┌──────────────────┐ ┌──────────────────┐ ┌──────────────────┐ ┌──────────────────┐
// │                  │ │                  │ │                  │ │                  │ │  tutti_pari(0)   │
// │                  │ │                  │ │                  │ │                  │ │  ┌────────────┐  │
// │                  │ │                  │ │                  │ │                  │ │  │ n = 0      │  │
// │                  │ │                  │ │                  │ │                  │ │  │ base case  │  │
// │                  │ │                  │ │                  │ │                  │ │  └────────────┘  │
// │                  │ │                  │ │                  │ │                  │ │                  │
// │                  │ │                  │ │                  │ │──────────────────│ ├──────────────────┤
// │                  │ │                  │ │                  │ │  tutti_pari(1)   │ │  tutti_pari(1)   │
// │                  │ │                  │ │                  │ │  ┌────────────┐  │ │  ┌────────────┐  │
// │                  │ │                  │ │                  │ │  │ n = 1      │  │ │  │ n = 1      │  │
// │                  │ │                  │ │                  │ │  │ arr[0]==2  │  │ │  │ arr[0]==2  │  │
// │                  │ │                  │ │                  │ │  │ check OK   │  │ │  │ waiting... │  │
// │                  │ │                  │ │                  │ │  └────────────┘  │ │  └────────────┘  │
// │                  │ │                  │ │                  │ │                  │ │                  │
// │                  │ │                  │ │──────────────────│ ├──────────────────┤ ├──────────────────┤
// │                  │ │                  │ │  tutti_pari(2)   │ │  tutti_pari(2)   │ │  tutti_pari(2)   │
// │                  │ │                  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │
// │                  │ │                  │ │  │ n = 2      │  │ │  │ n = 2      │  │ │  │ n = 2      │  │
// │                  │ │                  │ │  │ arr[1]==4  │  │ │  │ arr[1]==4  │  │ │  │ arr[1]==4  │  │
// │                  │ │                  │ │  │ check OK   │  │ │  │ waiting... │  │ │  │ waiting... │  │
// │                  │ │                  │ │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │
// │                  │ │                  │ │                  │ │                  │ │                  │
// │                  │ │──────────────────│ ├──────────────────┤ ├──────────────────┤ ├──────────────────┤
// │                  │ │  tutti_pari(3)   │ │  tutti_pari(3)   │ │  tutti_pari(3)   │ │  tutti_pari(3)   │
// │                  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │
// │                  │ │  │ n = 3      │  │ │  │ n = 3      │  │ │  │ n = 3      │  │ │  │ n = 3      │  │
// │                  │ │  │ arr[2]==6  │  │ │  │ arr[2]==6  │  │ │  │ arr[2]==6  │  │ │  │ arr[2]==6  │  │
// │                  │ │  │ check OK   │  │ │  │ waiting... │  │ │  │ waiting... │  │ │  │ waiting... │  │
// │                  │ │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │
// │                  │ │                  │ │                  │ │                  │ │                  │
// ├──────────────────┤ ├──────────────────┤ ├──────────────────┤ ├──────────────────┤ ├──────────────────┤
// │  main            │ │  main            │ │  main            │ │  main            │ │  main            │
// │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │
// │  │ array =    │  │ │  │ array =    │  │ │  │ array =    │  │ │  │ array =    │  │ │  │ array =    │  │
// │  │  [2,4,6]   │  │ │  │  [2,4,6]   │  │ │  │  [2,4,6]   │  │ │  │  [2,4,6]   │  │ │  │  [2,4,6]   │  │
// │  │ n = 3      │  │ │  │ waiting... │  │ │  │ waiting... │  │ │  │ waiting... │  │ │  │ waiting... │  │
// │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │
// │                  │ │                  │ │                  │ │                  │ │                  │
// └──────────────────┘ └──────────────────┘ └──────────────────┘ └──────────────────┘ └──────────────────┘
//
// ↓ indirizzi numericamente più alti
//
//
// FASE DI RITORNO (unwinding dello stack):
//
//
//     Stato 5:             Stato 6:             Stato 7:             Stato 8:             Stato 9:
//
//     tutti_pari(0)
//     tutti_pari(1)        tutti_pari(1)
//     tutti_pari(2)        tutti_pari(2)        tutti_pari(2)
//     tutti_pari(3)        tutti_pari(3)        tutti_pari(3)        tutti_pari(3)        
//     main()               main()               main()               main()               main()        
//
// ↑ indirizzi numericamente più bassi
//
// ┌──────────────────┐ ┌──────────────────┐ ┌──────────────────┐ ┌──────────────────┐ ┌──────────────────┐
// │  tutti_pari(0)   │ │                  │ │                  │ │                  │ │                  │
// │  ┌────────────┐  │ │                  │ │                  │ │                  │ │                  │
// │  │ n = 0      │  │ │                  │ │                  │ │                  │ │                  │
// │  │ return true│  │ │                  │ │                  │ │                  │ │                  │
// │  └────────────┘  │ │                  │ │                  │ │                  │ │                  │
// │                  │ │                  │ │                  │ │                  │ │                  │
// ├──────────────────┤ ├──────────────────┤ │                  │ │                  │ │                  │
// │  tutti_pari(1)   │ │  tutti_pari(1)   │ │                  │ │                  │ │                  │
// │  ┌────────────┐  │ │  ┌────────────┐  │ │                  │ │                  │ │                  │
// │  │ n = 1      │  │ │  │ n = 1      │  │ │                  │ │                  │ │                  │
// │  │ arr[0]==2  │  │ │  │ arr[0]==2  │  │ │                  │ │                  │ │                  │
// │  │ waiting... │  │ │  │ return true│  │ │                  │ │                  │ │                  │
// │  └────────────┘  │ │  └────────────┘  │ │                  │ │                  │ │                  │
// │                  │ │                  │ │                  │ │                  │ │                  │
// ├──────────────────┤ ├──────────────────┤ ├──────────────────┤ │                  │ │                  │
// │  tutti_pari(2)   │ │  tutti_pari(2)   │ │  tutti_pari(2)   │ │                  │ │                  │
// │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │                  │ │                  │
// │  │ n = 2      │  │ │  │ n = 2      │  │ │  │ n = 2      │  │ │                  │ │                  │
// │  │ arr[1]==4  │  │ │  │ arr[1]==4  │  │ │  │ arr[1]==4  │  │ │                  │ │                  │
// │  │ waiting... │  │ │  │ waiting... │  │ │  │ return true│  │ │                  │ │                  │
// │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │ │                  │ │                  │
// │                  │ │                  │ │                  │ │                  │ │                  │
// ├──────────────────┤ ├──────────────────┤ ├──────────────────┤ ├──────────────────┤ │                  │
// │  tutti_pari(3)   │ │  tutti_pari(3)   │ │  tutti_pari(3)   │ │  tutti_pari(3)   │ │                  │
// │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │                  │
// │  │ n = 3      │  │ │  │ n = 3      │  │ │  │ n = 3      │  │ │  │ n = 3      │  │ │                  │
// │  │ arr[2]==6  │  │ │  │ arr[2]==6  │  │ │  │ arr[2]==6  │  │ │  │ arr[2]==6  │  │ │                  │
// │  │ waiting... │  │ │  │ waiting... │  │ │  │ waiting... │  │ │  │ return true│  │ │                  │
// │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │ │                  │
// │                  │ │                  │ │                  │ │                  │ │                  │
// ├──────────────────┤ ├──────────────────┤ ├──────────────────┤ ├──────────────────┤ ├──────────────────┤
// │  main            │ │  main            │ │  main            │ │  main            │ │  main            │
// │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │
// │  │ array =    │  │ │  │ array =    │  │ │  │ array =    │  │ │  │ array =    │  │ │  │ array =    │  │
// │  │  [2,4,6]   │  │ │  │  [2,4,6]   │  │ │  │  [2,4,6]   │  │ │  │  [2,4,6]   │  │ │  │  [2,4,6]   │  │
// │  │ waiting... │  │ │  │ waiting... │  │ │  │ waiting... │  │ │  │ waiting... │  │ │  │ rv= true   │  │
// │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │
// │                  │ │                  │ │                  │ │                  │ │                  │
// └──────────────────┘ └──────────────────┘ └──────────────────┘ └──────────────────┘ └──────────────────┘
//
// ↓ indirizzi numericamente più alti
//
//
//
//
// ═══════════════════════════════════════════════════════════════════════════════════
// ESEMPIO CON ARRAY [2,3,4]
// ═══════════════════════════════════════════════════════════════════════════════════
// In questo caso la ricorsione non raggiunge il caso base k = 0: si interrompe
// precocemente quando incontra il valore 3, che è dispari. La funzione ritorna
// immediatamente false, e tutte le chiamate precedenti ricevono questo valore senza
// compiere ulteriori controlli. Ciò mette in evidenza come la presenza di un singolo
// elemento dispari faccia terminare la ricorsione prima rispetto al caso in cui tutti
// gli elementi sono pari, riducendo il numero totale di chiamate eseguite.
//
// Chiamata iniziale a f([2,3,4], 3)    false
//                                       ↑
// f([2,3,4], 3)                         |
//     │                                 │
//     │ Controllo v[2] = 4              │
//     │ 4 è pari? SÌ!                   │
//     │ Chiamo f([2,3,4], 2)           false
//     │                                 ↑
//     ↓                                 │
//                                       │
// f([2,3,4], 2)                         │
//     │                                 │
//     │ Controllo v[1] = 3              │
//     │ 3 è pari? NO!                   │
//     │ Restituisco false               │
//     └─────────────────────────────────┘
//
// FASE DI CHIAMATA (costruzione dello stack):
//
//
//     Stato 0:         Stato 1:             Stato 2:             
//
//                                           tutti_pari(2)
//                      tutti_pari(3)        tutti_pari(3)        
//     main()           main()               main()        
//
// ↑ indirizzi numericamente più bassi
//
// ┌──────────────────┐ ┌──────────────────┐ ┌──────────────────┐
// │                  │ │                  │ │  tutti_pari(2)   │
// │                  │ │                  │ │  ┌────────────┐  │
// │                  │ │                  │ │  │ n = 2      │  │
// │                  │ │                  │ │  │ arr[1]==3  │  │
// │                  │ │                  │ │  │ check...   │  │
// │                  │ │                  │ │  └────────────┘  │
// │                  │ │                  │ │                  │
// │                  │ │──────────────────│ ├──────────────────┤
// │                  │ │  tutti_pari(3)   │ │  tutti_pari(3)   │
// │                  │ │  ┌────────────┐  │ │  ┌────────────┐  │
// │                  │ │  │ n = 3      │  │ │  │ n = 3      │  │
// │                  │ │  │ arr[2]==4  │  │ │  │ arr[2]==4  │  │
// │                  │ │  │ check OK   │  │ │  │ waiting... │  │
// │                  │ │  └────────────┘  │ │  └────────────┘  │
// │                  │ │                  │ │                  │
// ├──────────────────┤ ├──────────────────┤ ├──────────────────┤
// │  main            │ │  main            │ │  main            │
// │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │
// │  │ array =    │  │ │  │ array =    │  │ │  │ array =    │  │
// │  │  [2,3,4]   │  │ │  │  [2,3,4]   │  │ │  │  [2,3,4]   │  │
// │  │ n = 3      │  │ │  │ waiting... │  │ │  │ waiting... │  │
// │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │
// │                  │ │                  │ │                  │
// └──────────────────┘ └──────────────────┘ └──────────────────┘
//
// ↓ indirizzi numericamente più alti
//
//
//
// FASE DI RITORNO (unwinding dello stack):
//
//
//     Stato 3:             Stato 4:             Stato 5:
//
//     tutti_pari(2)
//     tutti_pari(3)        tutti_pari(3)        
//     main()               main()               main()       
// 
//
// ↑ indirizzi numericamente più bassi
//
// ┌──────────────────┐ ┌──────────────────┐ ┌──────────────────┐
// │  tutti_pari(2)   │ │                  │ │                  │
// │  ┌────────────┐  │ │                  │ │                  │
// │  │ n = 2      │  │ │                  │ │                  │
// │  │ arr[1]==3  │  │ │                  │ │                  │
// │  │ 3 dispari! │  │ │                  │ │                  │
// │  │ ret false  │  │ │                  │ │                  │
// │  └────────────┘  │ │                  │ │                  │
// │                  │ │                  │ │                  │
// ├──────────────────┤ ├──────────────────┤ │                  │
// │  tutti_pari(3)   │ │  tutti_pari(3)   │ │                  │
// │  ┌────────────┐  │ │  ┌────────────┐  │ │                  │
// │  │ n = 3      │  │ │  │ n = 3      │  │ │                  │
// │  │ arr[2]==4  │  │ │  │ arr[2]==4  │  │ │                  │
// │  │ waiting... │  │ │  │ ret false  │  │ │                  │
// │  └────────────┘  │ │  └────────────┘  │ │                  │
// │                  │ │                  │ │                  │
// ├──────────────────┤ ├──────────────────┤ ├──────────────────┤
// │  main            │ │  main            │ │  main            │
// │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │
// │  │ array =    │  │ │  │ array =    │  │ │  │ array =    │  │
// │  │  [2,3,4]   │  │ │  │  [2,3,4]   │  │ │  │  [2,3,4]   │  │
// │  │ waiting... │  │ │  │ waiting... │  │ │  │ rv==false  │  │
// │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │
// │                  │ │                  │ │                  │
// └──────────────────┘ └──────────────────┘ └──────────────────┘
//
// ↓ indirizzi numericamente più alti
//
// Nota: In questo esempio, la funzione ritorna false non appena trova un numero
// dispari (3 in posizione 1), senza continuare a controllare gli altri elementi.
