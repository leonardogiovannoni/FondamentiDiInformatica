#include <iostream>
using namespace std;


// Il programma legge un intero n e stampa i numeri da 0 a n - 1.
// Escludendo il ciclo `do..while` (poco usato), ci sono due modi per
// risolvere l’esercizio: usare `for` oppure `while`.
// Anche se `for` e `while` sono equivalenti (ogni `for` può essere
// riscritto come `while` e viceversa (1)), in questo caso è più
// naturale utilizzare il `for`.

int main() {
    int n = 0;
    cin >> n;

    // `n` è un numero intero, cioè n ∈ ℤ. Consideriamo il caso più
    // semplice in cui n >= 0.  
    // Il ciclo `for` eseguirà esattamente `n` iterazioni, cioè per i
    // valori di `i` nell’intervallo [0, n), chiuso a sinistra e aperto
    // a destra. In ℤ ciò equivale a [0, n - 1], la cui cardinalità è:
    // `(n - 1) - 0 + 1 = n`.
    // Scrivere l’intervallo come [0, n) ci permette di capire subito
    // la cardinalità e quindi che il `for` viene eseguito `n - 0 = n`
    // volte.
    //
    // Se `n` è negativo (n < 0), il ciclo non viene mai eseguito,
    // poiché non esistono interi `i` tali che `0 <= i < n`
    // (ad esempio, se n == -3, non esistono `i` con `0 <= i < -3`,
    // quindi la `i` viene definita e inizializzata a 0, viene confrontata
    // con -3, la condizione risulta falsa e non entra nel ciclo).
    //
    // In generale, si può avere un ciclo del tipo:
    // ```
    // for (int i = x; i < y; i++) { ... }
    // ```
    // con due numeri `x` e `y`, dove `y >= x`. In questo caso `i`
    // appartiene all’intervallo [x, y), e il ciclo viene eseguito per
    // `y - x` iterazioni, con `i` in `{x, x + 1, x + 2, ..., y - 1}`.
    //
    // Tornando all’esercizio, stampiamo `i` ad ogni iterazione.
    // `i` assumerà i valori {0, 1, 2, ..., n - 1}.

    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }

    // Si potrebbe anche utilizzare il `while`, in questo caso sporcando
    // lo scope esterno al ciclo (perché `i` sopravvive dopo che il ciclo
    // è terminato):

    // ```
    // int i = 0;
    // while (i < n) {
    //     cout << i << endl;
    //     i++;
    // }
    // ```

    // `i` alla fine del ciclo è valido e accessibile, ma in ogni caso
    // non "intralcia" la logica del programma e quindi possiamo evitare
    // di inserire uno scope bizzarro


    return 0;
}



// (1)
// L’equivalenza tra `for` e `while` può essere rappresentata così
// (tralasciando il caso delle istruzioni `continue`: in un `for`,
// dopo una `continue` viene comunque eseguita `expression`, mentre
// nel `while` ciò non accade):
//
//                                                  --->
// for (init-statement; condition; expression) {    --->    {
//     statement;                                   --->        init-statement;
// }                                                --->        while (condition) {
//                                                  --->            statement;
//                                                  --->            expression;
//                                                  --->        }
//                                                  --->    }
//                                                  --->
//
// Esempio di equivalenza:
//
//                                                  --->
// for (int i = 0; i < 10; i++) {                   --->    {
//     cout << i << endl;                           --->        int i = 0;
// }                                                --->        while (i < 10) {
//                                                  --->            cout << i << endl;
//                                                  --->            i++;
//                                                  --->        }
//                                                  --->    }
//                                                  --->
//
// Da notare come il `while`, nell'equivalenza, è racchiuso dentro un blocco. 
// Questo perché durante l'init-statement (e.g. `int i = 0`) si crea una o più 
// variabili che altrimenti "sporcherebbero" lo scope esterno al `while`.
//
// In altre parole, se scrivessimo:
//
// int i = 0;
// while (i < 10) {
//     cout << i << endl;
//     i++;
// }
//
// la variabile `i` rimarrebbe visibile anche dopo il ciclo,
// mentre nel caso del `for` (e dell'equivalenza con il blocco `{ .. }`),
// la `i` è visibile solo all'interno del ciclo.
//
//
// Ad esempio:
//
// for (int i = 0; i < 10; i++) {
//     cout << i << endl;
// }
// cout << i; // Errore: 'i' non è definita qui
//
// {
//     int i = 0;
//     while (i < 10) {
//         cout << i << endl;
//         i++;
//     }
// }
// cout << i; // Errore analogo: 'i' non è definita qui
//
// Qualora avessi avuto un `continue` dentro il ciclo, l'equivalenza non sarebbe più valida:
//                                                  --->
// for (int i = 0; i < 10; i++) {                   --->    {
//     cout << i << endl;                           --->        int i = 0;
//     continue;                                    --->        while (i < 10) {
// }                                                --->            cout << i << endl;
//                                                  --->            continue; // <--- problema!                   
//                                                  --->            i++;
//                                                  --->        }
//                                                  --->    }
//                                                  --->
// In questo caso, il `continue` nel `while` salterebbe l'incremento di `i`,
// causando un ciclo infinito.


// Viceversa, l'equivalenza tra `while` e `for` è questa:
//
// while (condition) {             --->    for (; condition; ) {
//     statement;                  --->        statement;
// }                               --->    }
//
// Dove si può notare come nel `for` si omettono l’inizializzazione e l’espressione 
// finale (in quanto il linguaggio lo consente)
// Esempio di equivalenza:
//
// int i = 0;                              int i = 0;
// while (i < 10) {                --->    for (; i < 10; ) {
//     cout << i << endl;          --->        cout << i << endl;
//     i++;                        --->        i++;
// }                               --->    }
//
// In questo caso stiamo sporcando intenzionalmente, in entrambi i casi, lo scope esterno 
// al ciclo (ci sono casi d'uso in cui è utile ricordarsi il valore ultimo assunto dalla 
// variabile `i`, in questo caso banale però sappiamo che alla fine del ciclo varrà 
// sempre `i == 10`, ovvero il primo numero che non soddisfa la condizione)