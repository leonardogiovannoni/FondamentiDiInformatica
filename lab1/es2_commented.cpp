#include <iostream>
using namespace std;


//                ╭────────────╮
//                │   Inizio   │
//                ╰──────┬─────╯
//                       │
//                       ▼
//             ┌─────────────────┐
//             │   var a, b      │
//             └────────┬────────┘
//                      │
//                      ▼
//             ╱──────────────────╲
//            ╱    leggi a, b    ╱
//           ╲──────────────────╱
//                      │
//                      ▼
//            ╱──────────────────╲
//           ╱      a >= b?      ╲
//           ╲                   ╱
//            ╲──────────────────╱
//                 ╱         ╲
//              Sì╱           ╲No
//               ╱             ╲
//              ▼               ▼
//      ╱─────────────────╲   ╱─────────────────╲
//     ╱ scrivi "max a"  ╱   ╱ scrivi "max b"  ╱
//    ╲─────────────────╱   ╲─────────────────╱
//               ╲             ╱
//                ▼           ▼
//                ╭────────────╮
//                │    Fine    │
//                ╰────────────╯

int main() {

                        // Esempio dello stato (astratto) della memoria. A sinistra è
                        // riportato il nome della variabile (oppure il "nome" tra
                        // parentesi se la variabile non è ancora definita). A destra si
                        // trova il valore contenuto nella variabile. I valori mostrati
                        // quando la variabile non è ancora inizializzata sono casuali.

                        //      STACK (frame di main)
                        //  ┌───────────────────────────┐
                        //  │ (b) :   901234561         │  // `b` non ancora definita/inizializzata
                        //  ├───────────────────────────┤
                        //  │ (a) :   345678901         │  // `a` non ancora definita/inizializzata
                        //  └───────────────────────────┘
    // Supponiamo, a titolo di esempio, di definire, ma non inizializzare, le variabili `a` e `b`:
    int a;         
    int b;         
                        //      STACK (frame di main)
                        //  ┌───────────────────────────┐
                        //  │  b  :   901234561         │  // `b` definita ma non inizializzata: valore casuale
                        //  ├───────────────────────────┤
                        //  │  a  :   345678901         │  // `a` definita ma non inizializzata: valore casuale
                        //  └───────────────────────────┘

                        // In questo esercizio, come in `lab1/es1.cpp`, non si verificano
                        // problemi se una variabile non inizializzata viene scritta da
                        // `cin`. Tuttavia, ciò non è sempre garantito: `cin` può fallire
                        // (ad esempio se l'utente inserisce un valore non numerico) e, in
                        // tal caso, l'output potrebbe dipendere da due valori di `a` e
                        // `b` indeterminati.
                        
                        // Dal prossimo esercizio in poi inizializzeremo sempre ogni
                        // variabile al momento della definizione.

    cout << "Inserisci il primo numero a:" << endl;
    // Lettura del primo numero; supponiamo che l'utente inserisca 17.
    cin >> a;

    cout << "Inserisci il secondo numero b:" << endl;
    // Lettura del secondo numero; supponiamo che l'utente inserisca 12.
    cin >> b;
                        //      STACK (frame di main)
                        //  ┌───────────────────────────┐
                        //  │  b  :         12          │
                        //  ├───────────────────────────┤
                        //  │  a  :         17          │
                        //  └───────────────────────────┘

    // Valutazione della condizione `a >= b`: Con i valori d'esempio (17 e 12)
    // l'espressione risulta vera, quindi il flusso entra nel ramo "Sì" e stampa `a`
    // come massimo. In caso contrario, entrerebbe nel ramo "No" e stamperebbe `b`.
    //
    // Notare che l'operatore `>=` gestisce anche il caso di uguaglianza: se `a ==
    // b`, il programma considera `a` come massimo e lo stampa (equivalente a stampare
    // `b`, poiché i valori coincidono).

    if (a >= b) {
        cout << "Il massimo è a: " << a << endl;   // Ramo "Sì"
    } else {
        cout << "Il massimo è b: " << b << endl;   // Ramo "No"
    }

    return 0;
}
