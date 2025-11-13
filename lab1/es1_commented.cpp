#include <iostream>
using namespace std;


//             .------------.
//            (    Inizio    )
//             '------------'
//                   |
//                   v
//          +----------------+
//          |    var a, b    |
//          +----------------+
//                   |
//                   v
//           /-----------------/
//          /   leggi a, b    /
//         /-----------------/
//                   |
//                   v
//          +-----------------+
//          |  var c = a + b  |
//          +-----------------+
//                   |
//                   v
//           /-----------------/
//          /    scrivi c     /
//         /-----------------/
//                   |
//                   v
//             .------------.
//            (     Fine     )
//             '------------'

int main() {

                        // Le variabili a e b vengono inizializzate a 0 al punto (1).
                        // Anche se in questo caso non è strettamente necessario,
                        // poiché verranno sovrascritte dai valori letti in input ai
                        // punti (2) e (3), è buona pratica inizializzare sempre le
                        // variabili. Se non venissero inizializzate e fossero lette
                        // prima di essere sovrascritte (ad esempio stampandone il
                        // valore, come in un programma del tipo:
                        // ```
                        //   int main() { int a; cout << a; }
                        // ```
                        // ), il contenuto sarebbe indefinito. Potremmo ottenere in
                        // output qualunque valore intero, rendendo il comportamento
                        // del programma imprevedibile.

                        // La figura sotto è un esempio di cosa contiene la memoria in
                        // corrispondenza delle variabili: a sinistra dei due punti c'è
                        // il nome della variabile, a destra il valore contenuto nella
                        // variabile.
                        
                        // Quando una variabile non è ancora stata definita, la locazione
                        // di memoria “esiste” (il compilatore riserva lo spazio per essa
                        // all'inizio della funzione main), ma non è ancora associata alla
                        // variabile, la quale non esiste ancora (non essendo, ancora, 
                        // definita).
                        
                        // Per questo la indichiamo con il nome tra parentesi tonde, a
                        // ricordare che quella memoria è già riservata dal compilatore
                        // all'inizio dello stack frame, ma finché la variabile non è
                        // definita, non è ancora accessibile.
                        
                        // Poiché la variabile non è ancora stata definita (e quindi
                        // neppure inizializzata), il valore della locazione è casuale.
                        // In questo esempio scegliamo tre valori arbitrari per
                        // illustrare il concetto.
                    
                        // Nella rappresentazione seguente, gli indirizzi di memoria
                        // sono in ordine crescente dall'alto verso il basso. Come
                        // visto a lezione, lo stack cresce verso indirizzi di memoria
                        // più bassi. Le variabili locali sono allocate in ordine
                        // inverso rispetto alla loro definizione nel codice sorgente:
                        // l'ultima variabile definita viene allocata all'indirizzo
                        // più basso.

                        // Questa osservazione vale nella pratica, ma non è garantita
                        // dal linguaggio. Esistono compilatori che potrebbero
                        // allocare le variabili in ordine diverso. Tuttavia, questo
                        // è *trasparente per il programmatore* (*) e rimane un dettaglio
                        // d’implementazione del compilatore.

                        
                        // (*)    Trasparente per il programmatore significa che un 
                        //        certo meccanismo o servizio opera automaticamente, 
                        //        senza richiedere interventi o conoscenze specifiche 
                        //        da parte del programmatore, mantenendo invariato il 
                        //        comportamento logico del programma.
                      

                        //      STACK (frame di main)
                        //  +---------------------------+
                        //  | (c) :  242605778          |   // Valore casuale; `c` non ancora definita né inizializzata
                        //  +---------------------------+
                        //  | (b) :  646376713          |   // Valore casuale; `b` non ancora definita né inizializzata
                        //  +---------------------------+
                        //  | (a) :  238421271          |   // Valore casuale; `a` non ancora definita né inizializzata
                        //  +---------------------------+
    // (* 1
    int a = 0;         
    int b = 0;         
// 1 *)
                        //      STACK (frame di main)
                        //  +---------------------------+
                        //  | (c) :  242605778          |   // `c` non ancora definita né inizializzata
                        //  +---------------------------+
                        //  |  b  :          0          |   // `b` è stata definita e inizializzata a 0
                        //  +---------------------------+
                        //  |  a  :          0          |   // `a` è stata definita e inizializzata a 0
                        //  +---------------------------+
    cout << "Inserisci un numero a:" << endl;
    // Lettura del primo numero, supponiamo che l'utente inserisca 32.
    // (* 2
    cin >> a;
    // 2 *)
    cout << "Inserisci un numero b:" << endl;
    // Lettura del secondo numero, supponiamo che l'utente inserisca 36.
    // (* 3
    cin >> b; 
    // 3 *)
                        //      STACK (frame di main)
                        //  +---------------------------+
                        //  | (c) :  242605778          |   // `c` non ancora né definita né inizializzata
                        //  +---------------------------+
                        //  |  b  :         36          |
                        //  +---------------------------+
                        //  |  a  :         32          |
                        //  +---------------------------+
    int c = a + b;  // Dichiarazione e inizializzazione della variabile `c`.

                        //      STACK (frame di main)
                        //  +---------------------------+
                        //  |  c  :         68          |   // `c` è stata definita e inizializzata con il risultato della somma di `a` e `b`
                        //  +---------------------------+
                        //  |  b  :         36          | 
                        //  +---------------------------+
                        //  |  a  :         32          |
                        //  +---------------------------+
    cout << "La somma a + b è uguale a: " << c << endl;

    return 0;
}

