#include <iostream>
using namespace std;

int main() {
    const int N = 6;
    int arr[N] = {};

    cout << "Inserisci " << N << " numeri interi" << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << "Array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Settiamo la variabile booleana `crescente` a `true`,
    // assumendo inizialmente che l'array sia in ordine crescente.
    // Poi verifichiamo questa ipotesi confrontando coppie di
    // elementi adiacenti nell'array.
    // Se troviamo una coppia che non rispetta l'ordine crescente,
    // impostiamo `crescente` a `false`.
    bool crescente = true;
    // Facciamo al più N-1 iterazioni, perché in ogni iterazione
    // confrontiamo l'elemento in posizione `i` con quello in posizione `i+1`.
    // Inseriamo anche un controllo sulla variabile booleana `crescente`:
    // qualora l'array risulti crescente, la variabile rimane `true` e
    // il ciclo continua per `N-1` volte; se invece troviamo un elemento
    // che non rispetta la condizione di crescita, mettiamo `crescente`
    // a `false` perché la proprietà che tutti gli elementi siano
    // in ordine crescente non è più valida, e quindi possiamo uscire
    // anticipatamente; all'iterazione successiva la condizione del `while`
    // sarà la seguente `i < N - 1 && false`, che risulterà `false` e il
    // ciclo terminerà.

    // La condizione `i < N - 1 && crescente` avrà la segunte tabella di verità:
    //
    // | i < N - 1 | crescente | i < N - 1 && crescente |
    // |-----------|-----------|------------------------|     caso 1 con crescente == false
    // |   false   |   false   |         false          | <----------------------------------+ 
    // |   false   |   true    |         false          |     caso 2 con crescente == false  |
    // |    true   |   false   |         false          | <----------------------------------+
    // |    true   |   true    |          true          |                                    |
    // +------------------------------------------------+                                    |
    // Ovvero il ciclo continua se e solo se entrambe le condizioni sono vere.               |
    // Qualora la condizione `arr[i] < arr[i + 1]` non sia rispettata,                       |
    // `crescente` viene impostata a `false`, e quindi la condizione                         |
    // complessiva del `for` diventa `false`, terminando il ciclo.                           |
    // Qualora invece tutti gli elementi rispettino la condizione di crescita,               |
    // `crescente` rimane `true` e il ciclo continua fino a completare                       |
    // tutte le `N-1` iterazioni.                                                            |
    for (int i = 0; i < N - 1 && crescente; i++) {                 //                        |
        // La condizione di crescita è che l'elemento in posizione `i` sia                   |
        // minore di quello in posizione `i + 1`.                                            |
        bool condizione_di_crescita = (arr[i] < arr[i + 1]);       //                        | 
        if (!condizione_di_crescita) {                             //                        |      
            // se la condizione di crescita non è rispettata       //                        |
            // (ovvero `arr[i] >= arr[i + 1]`), allora             //                        |
            // ciò è sufficiente per affermare che l'array         //                        |
            // non è in ordine crescente.                          //                        |
            // È inutile continuare a controllare gli altri        //                        |
            // elementi, quindi possiamo uscire dal ciclo          //                        |
            // anticipatamente.                                    //                        |
            crescente = false;                                     //                        |  
            // Settiamo `crescente` a `false`, la condizione complessiva                     |
            // della prossima iterazione del `for` verrà calcolata come                      |
            // `i < N - 1 && false`, quindi sia che `i < N - 1` sia                          |
            // true che false, la condizione complessiva sarà `false` -----------------------+
            // e il ciclo terminerà.
        }
    }

    if (crescente) {
        cout << "L'array e' crescente" << endl;
    } else {
        cout << "L'array non e' crescente" << endl;
    }

    return 0;
}
