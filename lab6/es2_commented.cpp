#include <iostream>
using namespace std;


// Esempio: matrice 2x3
//   Posizione (0,0) → index = 0*3 + 0 = 0
//   Posizione (0,1) → index = 0*3 + 1 = 1
//   Posizione (0,2) → index = 0*3 + 2 = 2
// 
//   Posizione (1,0) → index = 1*3 + 0 = 3
//   Posizione (1,1) → index = 1*3 + 1 = 4
//   Posizione (1,2) → index = 1*3 + 2 = 5
void leggi_matrice(int *m, int rows, int cols) {
    // L'ordine più naturale per iterare una matrice è per righe, e quindi per ogni
    // riga, iterare su ogni colonna, in modo da scorrere gli indici della matrice in
    // questo ordine:
    // (0,0), (0,1), (0,2),
    // (1,0), (1,1), (1,2)
    // che con l'indice lineare index = r * cols + c corrisponde a:
    // 0, 1, 2,
    // 3, 4, 5
    // Iteriamo su tutte le righe
    for (int r = 0; r < rows; r++) {
        // Per ogni riga, iteriamo su tutte le colonne
        for (int c = 0; c < cols; c++) {
            // Calcoliamo l'indice lineare corrispondente alla posizione (r, c)
            int index = r * cols + c;
            // Leggiamo il valore da input e lo memorizziamo nella posizione
            // calcolata
            cin >> m[index];
        }
    }
}

void stampa_matrice(int *m, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int index = r * cols + c;
            cout << m[index] << " ";
        }
        cout << endl;
    }
}

// Funzione per invertire l'ordine delle colonne in una matrice
//
// Esempio con matrice 2x5:
//
//   ┌───┬───┬───┬───┬───┐
//   │ 1 │ 2 │ 3 │ 4 │ 5 │
//   ├───┼───┼───┼───┼───┤
//   │ 6 │ 7 │ 8 │ 9 │10 │
//   └───┴───┴───┴───┴───┘
//     ↑               ↑
//   col 0           col 4
//     │               │
//     └───────────────┘
//        swap col 0↔4
//
//   ┌───┬───┬───┬───┬───┐
//   │ 5 │ 2 │ 3 │ 4 │ 1 │
//   ├───┼───┼───┼───┼───┤
//   │10 │ 7 │ 8 │ 9 │ 6 │
//   └───┴───┴───┴───┴───┘
//         ↑       ↑
//       col 1   col 3
//         │       │
//         └───────┘
//          swap col 1↔3
//
//   ┌───┬───┬───┬───┬───┐
//   │ 5 │ 4 │ 3 │ 2 │ 1 │  ← Risultato finale
//   ├───┼───┼───┼───┼───┤
//   │10 │ 9 │ 8 │ 7 │ 6 │
//   └───┴───┴───┴───┴───┘
//             ↑
//           col 2
//      (resta al centro)
//
// Per ogni riga, scambiamo gli elementi simmetricamente:
// - colonna 0 ←→ colonna 4  (prima con ultima)
// - colonna 1 ←→ colonna 3  (seconda con penultima)
// - colonna 2 rimane al centro (elemento centrale, se numero dispari di
//   colonne)
//
// Iteriamo fino a `cols / 2` per non rifare lo scambio due volte
void inverti_colonne(int *m, int rows, int cols) {
    // Per ogni riga
    for (int r = 0; r < rows; r++) {
        // Scorriamo solo metà delle colonne, e invertiamole con le loro
        // simmetriche
        for (int c = 0; c < cols / 2; c++) {
            // Calcoliamo l'indice della colonna simmetrica
            // Se c = 0, other_c = cols - 1 (ultima colonna)
            // Se c = 1, other_c = cols - 2 (penultima colonna)
            // ...
            // Se c = i, other_c = cols - 1 - i
            int other_c = cols - 1 - c;
            // nel caso di una matrice 2x7:
            //   c = 0  → other_c = 6
            //   c = 1  → other_c = 5
            //   c = 2  → other_c = 4
            //
            // Se considerassimo c = 3, varrebbe other_c = 3, che è la colonna centrale,
            // e non ha senso (anche se non sarebbe errore) scambiarla con sé stessa, e
            // infatti consideriamo solo c < cols / 2, ovvero c < 7 / 2, ovvero c < 3,
            // quindi c == 2 come ultimo valore considerato.

            // Facciamo lo scambio tra gli elementi in posizione (r, c) e (r, cols - 1 - c)

            // Calcoliamo gli indici lineari degli elementi da scambiare
            int idx_sx = r * cols + c;         // elemento a sinistra
            int idx_dx = r * cols + other_c;   // elemento a destra
            
            // Scambio classico usando una variabile temporanea
            int tmp = m[idx_sx];
            m[idx_sx] = m[idx_dx];
            m[idx_dx] = tmp;
        }
    }
}

// Uno dei problemi che incontriamo quando lavoriamo con matrici in C++ è che non
// possiamo passare matrici 2D come argomenti alle funzioni in modo generico rispetto
// alle dimensioni come facciamo con gli array 1D, questo perché le matrici, essendo
// array di array, possono essere passate alle funzioni esattamente come gli array
// monodimensionali, ovvero passando un puntatore al primo elemento dell'array. Nel
// caso delle matrici 2D, il primo elemento è un array 1D (la prima riga della
// matrice).
// Questo è un esempio di come passare una matrice 2D a una funzione:
// ```
// void funzione(int m[][COLS], int rows) {
//     for (int r = 0; r < rows; r++) {
//         for (int c = 0; c < COLS; c++) {
//             cout << m[r][c] << " ";
//         }
//         cout << endl;
//     }
// }
// ```
// Questa sintassi strana, in realtà significa che stiamo passando un puntatore a un
// array di COLS interi, ed è del tutto equivalente a questa sintassi (ancora più
// strana):
// ```
// void funzione(int (*m)[COLS], int rows) {
//     for (int r = 0; r < rows; r++) {
//         for (int c = 0; c < COLS; c++) {
//             cout << m[r][c] << " ";
//         }
//         cout << endl;
//     }
// }
// ```
// `int (*m)[COLS]` è la sintassi per dichiarare un "puntatore a un array di COLS
// interi", cioè un puntatore a un oggetto di tipo int[COLS].
//
// Non abbiamo mai introdotto i puntatori a array (e non li useremo nel corso),
// ma menzioniamo questa sintassi per completezza. Nei nostri esempi, quando lavoreremo
// con gli array, useremo sempre e solo un puntatore al primo elemento dell'array.
//
// Sebbene questa dichiarazione sia perfettamente corretta, è poco pratica: richiede
// di conoscere a priori la dimensione COLS. Per evitare questa rigidità, in questo
// esercizio tratteremo le matrici 2D sfruttando il fatto che la loro rappresentazione
// in memoria è identica a quella di un array 1D di lunghezza rows * cols. Ciò ci
// permette di definire una corrispondenza biunivoca tra gli indici 2D (i, j) e gli
// indici 1D, come illustrato più avanti.

int main() {
    // Dichiarazione di una matrice 2x3 (2 righe, 3 colonne)
    // In C++, le matrici bidimensionali sono array di array.
    // La sintassi int mat[2][3] crea un array di 2 elementi,
    // dove ogni elemento è un array di 3 interi.
    // Quindi, dichiarare int mat[2][3] significa creare una matrice
    // con 2 righe e 3 colonne, ovvero creare un array di dimensione 2
    // i cui elementi sono array di dimensione 3.
    int mat[2][3] = {};
    
    // int mat[2][3] = { {1, 2, 3}, {4, 5, 6} };
    // int arr[6] = { 1, 2, 3, 4, 5, 6 };
    // in memoria, la matrice è memorizzata come una sequenza lineare: `mat` e `arr`
    // sono memorizzati nello stesso modo.
    // Questo è chiamato layout "row-major" (per righe). La matrice viene memorizzata
    // riga per riga in memoria contigua

    //  Visione matematica (2D):                 Memoria fisica (1D):
    //                                      
    //  ⎡                           ⎤           ┌─────┬─────┬─────┬─────┬─────┬─────┐
    //  │   a₀₀ ───> a₀₁ ───> a₀₂   │   ════>   │ a₀₀ │ a₀₁ │ a₀₂ │ a₁₀ │ a₁₁ │ a₁₂ │
    //  │   ┌───────────────────┘   │           └─────┴─────┴─────┴─────┴─────┴─────┘
    //  │   ↓                       │             [0]   [1]   [2]   [3]   [4]   [5]
    //  │   a₁₀ ───> a₁₁ ───> a₁₂   │           
    //  ⎣                           ⎦            └──── riga 0 ────┘└──── riga 1 ────┘
    //
    // Le frecce nella visione 2D mostrano l'ordine row-major (per righe):
    // si attraversa tutta la riga 0, poi si passa alla riga 1.
    // Ogni riga occupa 3 posizioni consecutive in memoria.


    //  Visione matematica (2D):              Memoria fisica (1D):
    //                                      
    //  ⎡                   ⎤                ┌───┬───┬───┬───┬───┬───┐
    //  │   1 ──> 2 ──> 3   │     ════>      │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │
    //  │   ┌──────────┘    │                └───┴───┴───┴───┴───┴───┘
    //  │   ↓               │                 [0] [1] [2] [3] [4] [5]
    //  │   4 ──> 5 ──> 6   │           
    //  ⎣                   ⎦                 └─ riga 0 ─┘└─ riga 1 ─┘
    //
    
    // ╔══════════════════════════════════════════════════════════════╗
    // ║  Mappatura: Indici 2D (riga, colonna) ──> Indice Lineare 1D  ║
    // ╠══════════════════════════════════════════════════════════════╣
    // ║                                                              ║
    // ║  Formula:  index = riga × num_colonne + colonna              ║
    // ║                                                              ║
    // ╠═════════╦═══════════╦═══════════╦════════════════════════════╣
    // ║ Valore  ║ mat[r][c] ║  arr[i]   ║        Calcolo             ║
    // ╠═════════╬═══════════╬═══════════╬════════════════════════════╣
    // ║    1    ║  [0][0]   ║    [0]    ║    0 × 3 + 0  =  0         ║
    // ║    2    ║  [0][1]   ║    [1]    ║    0 × 3 + 1  =  1         ║
    // ║    3    ║  [0][2]   ║    [2]    ║    0 × 3 + 2  =  2         ║
    // ╠═════════╬═══════════╬═══════════╬════════════════════════════╣
    // ║    4    ║  [1][0]   ║    [3]    ║    1 × 3 + 0  =  3         ║
    // ║    5    ║  [1][1]   ║    [4]    ║    1 × 3 + 1  =  4         ║
    // ║    6    ║  [1][2]   ║    [5]    ║    1 × 3 + 2  =  5         ║
    // ╚═════════╩═══════════╩═══════════╩════════════════════════════╝
    //
    // Perché questa formula funziona?
    // - Ogni riga contiene 3 elementi (num_colonne = 3)
    // - La riga 0 occupa le posizioni [0, 1, 2]
    // - La riga 1 occupa le posizioni [3, 4, 5]
    // - Per raggiungere la riga r, dobbiamo "saltare" r righe complete,
    //   ovvero r * 3 elementi
    // - Poi aggiungiamo l'offset della colonna c

    // Quando passiamo una matrice a una funzione, il tipo int[2][3] è brutalmente
    // castato a int*, puntatore al primo elemento. &mat[0][0] ottiene esplicitamente
    // l'indirizzo del primo elemento.
    //
    // Nota: mat, &mat, &mat[0], &mat[0][0] hanno tutti lo stesso valore (lo stesso
    // indirizzo di memoria), ma tipi diversi dal punto di vista del compilatore:
    //   - mat        decade in int (*)[3]       (puntatore ad array di 3 int)
    //   - &mat       ha tipo int (*)[2][3]      (puntatore a matrice 2x3)
    //   - &mat[0]    ha tipo int (*)[3]         (puntatore ad array di 3 int)
    //   - &mat[0][0] ha tipo int*               (puntatore a int)
    //
    // Usiamo &mat[0][0] per evitare cast espliciti e per semplicità visto che la
    // funzione si aspetta un int*
    
    leggi_matrice(&mat[0][0], 2, 3);
    stampa_matrice(&mat[0][0], 2, 3);
    inverti_colonne(&mat[0][0], 2, 3);
    cout << "Matrice dopo inversione colonne:" << endl; 
    stampa_matrice(&mat[0][0], 2, 3);
    return 0;
}

