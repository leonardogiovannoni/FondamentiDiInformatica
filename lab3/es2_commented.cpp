#include <iostream>
using namespace std;


// Nelle figure (che rappresentano gli stack frame rispettivamente di `main`
// e della funzione `f*` chiamata da `main`) indichiamo con un numero tra parentesi
// le posizioni nel codice a cui si riferiscono, quindi nel caso di
// ```
// int a = 10;
// // (1)
// a = a * 2; 
// ```
// stiamo indicando con (1) lo stato della memoria subito dopo
// `int a = 10;` e subito prima di `a = a * 2;`.
// Con `(*)`, `(**)` e `(***)` indichiamo invece
// delle posizioni nel `main`, per mostrare l'effetto delle
// chiamate alle funzioni una volta ritornate.

//
// (1)                                              (2)
// ↑ indirizzi bassi                                ↑ indirizzi bassi
// ┌──────────────────────────────────┐             ┌──────────────────────────────────┐
// │                                  │             │                                  │
// │ Stack frame: f1                  │             │ Stack frame: f1                  │
// │ ┌───────────────┐                │             │ ┌───────────────┐                │
// │ │ x = 10        │ <─ copia di 'a'              │ │ x = 20        │                │
// │ └───────────────┘                │             │ └───────────────┘                │   
// │                                  │             │                                  │   
// └──────────────────────────────────┘             └──────────────────────────────────┘
//                                                                                         
// ┌──────────────────────────────────┐             ┌──────────────────────────────────┐   
// │                                  │             │                                  │   
// │ Stack frame: main                │             │ Stack frame: main                │   
// │ ┌───────────────┐                │             │ ┌───────────────┐                │   
// │ │ a = 10        │                │             │ │ a = 10        │                │   
// │ └───────────────┘                │             │ └───────────────┘                │
// │                                  │             │                                  │
// └──────────────────────────────────┘             └──────────────────────────────────┘
// ↓ indirizzi alti                                 ↓ indirizzi alti
//

//
// (*)                               
// ↑ indirizzi bassi
// ┌──────────────────────────────────┐
// │                                  │
// │ Stack frame: main                │
// │ ┌───────────────┐                │
// │ │ a = 10        │                │
// │ └───────────────┘                │
// │                                  │
// └──────────────────────────────────┘
// ↓ indirizzi alti                
//


// il valore della variabile `a` è letto e copiato
// nella nuova variabile `x`
void f1(int x) {
    // (1)
    x = x * 2;
    // (2)
}


//
// (1)                                              (2)
// ↑ indirizzi bassi                                ↑ indirizzi bassi
// ┌──────────────────────────────────┐             ┌──────────────────────────────────┐
// │                                  │             │                                  │
// │ Stack frame: f2                  │             │ Stack frame: f2                  │
// │ ┌───────────────┐                │             │ ┌───────────────┐                │
// │ │ x = 10        │ <─ copia di 'a'              │ │ x = 20        │                │
// │ └───────────────┘                │             │ └───────────────┘                │   
// │                                  │             │                                  │   
// └──────────────────────────────────┘             └──────────────────────────────────┘   
//                                                                                         
// ┌──────────────────────────────────┐             ┌──────────────────────────────────┐   
// │                                  │             │                                  │   
// │ Stack frame: main                │             │ Stack frame: main                │   
// │ ┌───────────────┐                │             │ ┌───────────────┐                │   
// │ │ a = 10        │                │             │ │ a = 10        │                │   
// │ └───────────────┘                │             │ └───────────────┘                │
// │                                  │             │                                  │
// └──────────────────────────────────┘             └──────────────────────────────────┘
// ↓ indirizzi alti                                 ↓ indirizzi alti
//

//
// (**)
// ↑ indirizzi bassi
// ┌──────────────────────────────────┐
// │                                  │
// │ Stack frame: main                │
// │ ┌───────────────┐                │
// │ │ a = 20        │ <─ assegnamento del valore di ritorno (`x`) ad `a`
// │ └───────────────┘                │
// │                                  │
// └──────────────────────────────────┘
// ↓ indirizzi alti     
//



// il valore della variabile `a` è letto e copiato
// nella nuova variabile `x`, che viene ritornato
// e può, per esempio, essere riassegnato ad `a`
int f2(int x) {
    // (1)
    x = x * 2;
    // (2)
    return x;
}

// Indichiamo informalmente con `ref` il fatto che
// una variabile è un riferimento a un'altra variabile.
// Usiamo la stessa convenzione del lab1, quindi indichiamo con (tmp)
// il fatto che il compilatore abbia riservato lo spazio per la
// variabile `tmp`, ma che `tmp` non sia ancora stata definita.
// La variabile di appoggio `tmp` è utilizzata per mostrare meglio
// le operazioni che avvengono nella funzione.

// (1)                                              (2)
// ↑ indirizzi bassi                                ↑ indirizzi bassi
// ┌──────────────────────────────────┐             ┌──────────────────────────────────┐
// │                                  │             │                                  │
// │ Stack frame: f3                  │             │ Stack frame: f3                  │
// │ ┌───────────────┐                │             │ ┌───────────────┐                │
// │ │ x = ref a     │────────────────────┐         │ │ x = ref a     │────────────────────┐
// │ └───────────────┘                │   │         │ └───────────────┘                │   │
// │                                  │   │         │                                  │   │
// │ ┌───────────────┐                │   │         │ ┌───────────────┐                │   │
// │ │ (tmp) = ..    │                │   │         │ │ tmp = 40      │                │   │
// │ └───────────────┘                │   │         │ └───────────────┘                │   │
// │                                  │   │         │                                  │   │
// └──────────────────────────────────┘   │         └──────────────────────────────────┘   │
//                                        │                                                │
// ┌──────────────────────────────────┐   │         ┌──────────────────────────────────┐   │
// │                                  │   │         │                                  │   │
// │ Stack frame: main                │   │         │ Stack frame: main                │   │
// │ ┌───────────────┐                │   │         │ ┌───────────────┐                │   │
// │ │ a = 20        │ <──────────────────┘         │ │ a = 40        │ <──────────────────┘
// │ └───────────────┘                │             │ └───────────────┘                │
// │                                  │             │                                  │
// └──────────────────────────────────┘             └──────────────────────────────────┘
// ↓ indirizzi alti                                 ↓ indirizzi alti


// (3)
// ↑ indirizzi bassi
// ┌──────────────────────────────────┐
// │                                  │
// │ Stack frame: f3                  │
// │ ┌───────────────┐                │
// │ │ x = ref a     │────────────────────┐
// │ └───────────────┘                │   │
// │                                  │   │
// │ ┌───────────────┐                │   │
// │ │ tmp = 40      │                │   │
// │ └───────────────┘                │   │
// │                                  │   │
// └──────────────────────────────────┘   │             (***)
//                                        │             ↑ indirizzi bassi
// ┌──────────────────────────────────┐   │             ┌──────────────────────────────────┐
// │                                  │   │             │                                  │
// │ Stack frame: main                │   │             │ Stack frame: main                │
// │ ┌───────────────┐                │   │             │ ┌───────────────┐                │
// │ │ a = 40        │ <──────────────────┘             │ │ a = 40        │                │
// │ └───────────────┘                │                 │ └───────────────┘                │
// │                                  │                 │                                  │
// └──────────────────────────────────┘                 └──────────────────────────────────┘
// ↓ indirizzi alti                                     ↓ indirizzi alti




// Il riferimento è, secondo lo standard del C++, un alias a una variabile
// ovvero un altro nome per la variabile. In questo caso, questo significa
// che `x` è "un altro nome" per `a`, definizione che lo standard usa per
// essere il più generale possibile.
void f3(int &x) {
    // (1)
    // (* qui si legge il valore di `a`
    int tmp = x * 2;
    // *)
    // (2)
    // (* qui invece si sovrascrive il valore di `a`
    x = tmp;
    // *)
    // (3)
}



int main() {
    int a = 0;
    cout << "Inserisci un numero intero: ";
    cin >> a;
    cout << endl;
    cout << "Valore iniziale: " << a << endl;

    f1(a); // Passaggio per valore
    // (*)
    cout << "Dopo f1(x): " << a << endl;

    a = f2(a); // Passaggio per valore, con riassegnamento
    // (**)
    cout << "Dopo x = f2(x): " << a << endl;

    f3(a); // Passaggio per riferimento
    // (***)
    cout << "Dopo f3(x): " << a << endl;

    return 0;
}

