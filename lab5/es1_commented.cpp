#include <iostream>
using namespace std;


// Definiamo, per n ∈ ℕ, la funzione s(n), per n > 0, come la somma dei numeri da 1 a n:
// 
//                     s(n) = n + (n - 1) + ... + 2 + 1
// 
// mentre banalmente s(0) = 0.
// Osserviamo che:
//                     s(n) = n + (n - 1) + ... + 2 + 1
//                                └─────────┬─────────┘
//                                       s(n - 1)
// 
// Otteniamo quindi la seguente definizione ricorsiva:
// 
//                          ⎧ 0,               se n = 0,
//                   s(n) = ⎨
//                          ⎩ n + s(n - 1),    se n > 0.
// 

int somma(int n) {
    if (n == 0) {
        return 0;            // caso base
    }
    return n + somma(n - 1); // caso ricorsivo
}

int main() {
    int a = 0;
    cout << "Inserisci un numero intero positivo: ";
    cin >> a;

    cout << "La somma dei numeri da 1 a " << a << " è: " << somma(a) << endl;

    return 0;
}


// In questo esempio la funzione ricorsiva somma(n) costruisce la somma dei primi
// `n` numeri naturali scendendo di uno alla volta fino a raggiungere il caso base
// somma(0) = 0. Ogni chiamata deve attendere il valore della successiva, perché
// ogni livello della ricorsione dipende dal precedente (`n + somma(n - 1)`).
// Questo porta a una struttura ricorsiva completa, in cui tutte le chiamate
// vengono allocate nello stack prima che inizi la fase di ritorno. L'unwinding
// ricostruisce la somma finale "dal basso verso l'alto": prima 0, poi 1 + 0, poi
// 2 + 1, e infine 3 + 3.

// Chiamata iniziale a somma(3)          6
//                                       ↑
//                                       |
//                                       |   
// somma(3)                              │ 3 + 3
//     │                                 │ 
//     │ Calcolo: 3 + somma(2)           │
//     │ Chiamo somma(2)                 3
//     │                                 ↑
//     ↓                                 │
//                                       │
// somma(2)                              │ 2 + 1
//     │                                 │
//     │ Calcolo: 2 + somma(1)           │
//     │ Chiamo somma(1)                 1
//     │                                 ↑
//     ↓                                 │
//                                       │
// somma(1)                              │ 1 + 0
//     │                                 │
//     │ Calcolo: 1 + somma(0)           │
//     │ Chiamo somma(0)                 0
//     │                                 ↑
//     ↓                                 │
//                                       │
// somma(0)                              │
//     │                                 │
//     │ n <= 0 (caso base)              │
//     │ Restituisco 0                   │
//     └─────────────────────────────────┘
//
// FASE DI CHIAMATA (costruzione dello stack):
//
//
//     Stato 0:             Stato 1:             Stato 2:             Stato 3:
//
//                                                                    somma(0)
//                                               somma(1)             somma(1)
//                          somma(2)             somma(2)             somma(2)
//     main()               main()               main()               main()
//
// ↑ indirizzi numericamente più bassi
//
// ┌──────────────────┐ ┌──────────────────┐ ┌──────────────────┐ ┌──────────────────┐
// │                  │ │                  │ │                  │ │  somma(0)        │
// │                  │ │                  │ │                  │ │  ┌────────────┐  │
// │                  │ │                  │ │                  │ │  │ n = 0      │  │
// │                  │ │                  │ │                  │ │  │ return 0   │  │
// │                  │ │                  │ │                  │ │  └────────────┘  │
// │                  │ │                  │ │                  │ │                  │
// │                  │ │                  │ │──────────────────│ │──────────────────|
// │                  │ │                  │ │  somma(1)        │ │  somma(1)        |
// │                  │ │                  │ │  ┌────────────┐  │ │  ┌────────────┐  │
// │                  │ │                  │ │  │ n = 1      │  │ │  │ n = 1      │  │
// │                  │ │                  │ │  │ waiting... │  │ │  │ waiting... │  │
// │                  │ │                  │ │  └────────────┘  │ │  └────────────┘  │
// │                  │ │                  │ │                  │ │                  │
// │                  │ │──────────────────│ ├──────────────────┤ ├──────────────────┤
// │                  │ │  somma(2)        │ │  somma(2)        │ │  somma(2)        │
// │                  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │
// │                  │ │  │ n = 2      │  │ │  │ n = 2      │  │ │  │ n = 2      │  │
// │                  │ │  │ waiting... │  │ │  │ waiting... │  │ │  │ waiting... │  │
// │                  │ │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │
// │                  │ │                  │ │                  │ │                  │
// ├──────────────────┤ ├──────────────────┤ ├──────────────────┤ ├──────────────────┤
// │  main            │ │  main            │ │  main            │ │  main            │
// │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │
// │  │ a = 2      │  │ │  │ a = 2      │  │ │  │ a = 2      │  │ │  │ a = 2      │  │
// │  │ waiting... │  │ │  │ waiting... │  │ │  │ waiting... │  │ │  │ waiting... │  │
// │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │
// │                  │ │                  │ │                  │ │                  │
// └──────────────────┘ └──────────────────┘ └──────────────────┘ └──────────────────┘
//
// ↓ indirizzi numericamente più alti
//
//
// FASE DI RITORNO (unwinding dello stack):
//
//
//     Stato 4:             Stato 5:             Stato 6:             Stato 7:
//
//     somma(0)
//     somma(1)             somma(1)           
//     somma(2)             somma(2)             somma(2)           
//     main()               main()               main()               main()           
//
//
//
// ↑ indirizzi numericamente più bassi
//
// ┌──────────────────┐ ┌──────────────────┐ ┌──────────────────┐ ┌──────────────────┐
// │  somma(0)        │ │                  │ │                  │ │                  │
// │  ┌────────────┐  │ │                  │ │                  │ │                  │
// │  │ n = 0      │  │ │                  │ │                  │ │                  │
// │  │ return 0   │  │ │                  │ │                  │ │                  │
// │  └────────────┘  │ │                  │ │                  │ │                  │
// │                  │ │                  │ │                  │ │                  │
// │──────────────────│ │──────────────────│ │                  │ │                  │
// │  somma(1)        │ │  somma(1)        │ │                  │ │                  │
// │  ┌────────────┐  │ │  ┌────────────┐  │ │                  │ │                  │
// │  │ n = 1      │  │ │  │ n = 1      │  │ │                  │ │                  │
// │  │ waiting... │  │ │  │ return 1+0 │  │ │                  │ │                  │
// │  └────────────┘  │ │  └────────────┘  │ │                  │ │                  │
// │                  │ │                  │ │                  │ │                  │
// ├──────────────────┤ ├──────────────────┤ ├──────────────────┤ │                  │
// │  somma(2)        │ │  somma(2)        │ │  somma(2)        │ │                  │
// │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │                  │
// │  │ n = 2      │  │ │  │ n = 2      │  │ │  │ n = 2      │  │ │                  │
// │  │ waiting... │  │ │  │ waiting... │  │ │  │ return 2+1 │  │ │                  │
// │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │ │                  │
// │                  │ │                  │ │                  │ │                  │
// ├──────────────────┤ ├──────────────────┤ ├──────────────────┤ ├──────────────────┤
// │  main            │ │  main            │ │  main            │ │  main            │
// │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │ │  ┌────────────┐  │
// │  │ a = 2      │  │ │  │ a = 2      │  │ │  │ a = 2      │  │ │  │ a = 2      │  │
// │  │ waiting... │  │ │  │ waiting... │  │ │  │ waiting... │  │ │  │ result = 3 │  │
// │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │ │  └────────────┘  │
// │                  │ │                  │ │                  │ │                  │
// └──────────────────┘ └──────────────────┘ └──────────────────┘ └──────────────────┘
//
// ↓ indirizzi numericamente più alti