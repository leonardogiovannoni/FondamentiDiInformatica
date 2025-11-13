#include <iostream>
using namespace std;

void stampa_quadrato_cavo_con_diagonale(int n) {    
    // Iteriamo su tutte le coppie (r, c) che definiscono le coordinate
    // di un quadrato pieno di lato `n`, ossia sull'insieme 
    // {(r, c) ∈ ℕ × ℕ : r ∈ [0, n) ∧ c ∈ [0, n)}.
    // L'iterazione procede in ordine crescente (da 0 incluso a `n` escluso)
    // perché così le righe (r) e le colonne (c) vengono stampate nello
    // stesso ordine naturale in cui l'output viene visualizzato sullo
    // schermo: dall'alto verso il basso e da sinistra a destra.
    // A titolo di esempio, un'inversione dell'ordine (quindi partendo 
    // da n − 1 e arrivando a 0, entrambi inclusi, ovvero 
    // `for (int x = n - 1; x >= 0; x--)`) invertirebbe la direzione di 
    // stampa e produrrebbe il quadrato specchiato rispetto all'asse 
    // orizzontale (invertendo `r`) o rispetto all'asse verticale 
    // (invertendo `c`).

    // Iterando dunque in modo crescente su righe e colonne in questa maniera:
    // ```
    // for (int r = 0; r < n; r++) {
    //     for (int c = 0; c < n; c++) {
    //         ... // qui va la logica per decidere cosa stampare in (r, c)
    //     }
    //     cout << endl; // andiamo a capo alla fine di ogni riga
    // }
    // ```
    // la posizione del carattere stampato nello standard output
    // corrisponde direttamente alla posizione logica della cella
    // identificata dagli indici (r, c) nella seguente tabella:

    // Indici della matrice:
    //
    //               c=0            c=1              c=2         ...        c=n-1
    //       ┌───────────────────────────────────────────────────────────────────────
    // r=  0 │  (r=  0, c=0)   (r=  0, c=  1)   (r=  0, c=  2)   ...   (r=  0, c=n-1)
    // r=  1 │  (r=  1, c=0)   (r=  1, c=  1)   (r=  1, c=  2)   ...   (r=  1, c=n-1)
    // r=  2 │  (r=  2, c=0)   (r=  2, c=  1)   (r=  2, c=  2)   ...   (r=  2, c=n-1)
    //     . │        .              .                                       .
    //     . │        .                               .                      .
    //     . │        .                                                      .
    // r=n-1 │  (r=n-1, c=0)   (r=n-1, c=  1)   (r=n-1, c=  2)   ...   (r=n-1, c=n-1)

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            bool bordo_top       = (r == 0);       // prima riga
            bool bordo_bottom    = (r == n - 1);   // ultima riga
            bool bordo_sx        = (c == 0);       // colonna sinistra
            bool bordo_dx        = (c == n - 1);   // colonna destra
            bool diag_principale = (r == c);       // diagonale principale, ovvero quella
                                                   // che parte da (r=  0,c=  0)
                                                   // e arriva in  (r=n-1,c=n-1)

            // Combiniamo le condizioni con l'operatore logico OR, 
            // poiché dobbiamo stampare un asterisco quando almeno 
            // una di esse risulta vera.
            bool pieno =   bordo_top 
                        || bordo_bottom 
                        || bordo_sx 
                        || bordo_dx 
                        || diag_principale;
            if (pieno) {
                cout << "* "; // spazio dopo l'asterisco per allineamento
            } else {
                cout << "  "; // due spazi per mantenere l'allineamento
            }
        }
        // Fine riga: andiamo a capo
        cout << endl;
    }

    // Supponiamo di avere n = 5. La tabella seguente mostra le coordinate (r, c)
    // che identificano ciascuna cella del quadrato logico percorso dai due cicli annidati:
    //
    //            c=0            c=1            c=2            c=3            c=4
    //     ┌────────────────────────────────────────────────────────────────────────
    // r=0 │   (r=0,c=0)      (r=0,c=1)      (r=0,c=2)      (r=0,c=3)      (r=0,c=4)
    // r=1 │   (r=1,c=0)      (r=1,c=1)      (r=1,c=2)      (r=1,c=3)      (r=1,c=4)
    // r=2 │   (r=2,c=0)      (r=2,c=1)      (r=2,c=2)      (r=2,c=3)      (r=2,c=4)
    // r=3 │   (r=3,c=0)      (r=3,c=1)      (r=3,c=2)      (r=3,c=3)      (r=3,c=4)
    // r=4 │   (r=4,c=0)      (r=4,c=1)      (r=4,c=2)      (r=4,c=3)      (r=4,c=4)
    //
    // Ogni condizione logica (bordo o diagonale) seleziona un sottoinsieme specifico di 
    // celle, che corrisponde a una parte visiva del quadrato stampato.


    // 1)  bordo_top (r == 0)       → prima riga
    //            c=0            c=1            c=2            c=3            c=4
    //     ┌────────────────────────────────────────────────────────────────────────
    // r=0 │  _(r=0,c=0)_    _(r=0,c=1)_    _(r=0,c=2)_    _(r=0,c=3)_    _(r=0,c=4)_
    // r=1 │   (r=1,c=0)      (r=1,c=1)      (r=1,c=2)      (r=1,c=3)      (r=1,c=4)
    // r=2 │   (r=2,c=0)      (r=2,c=1)      (r=2,c=2)      (r=2,c=3)      (r=2,c=4)
    // r=3 │   (r=3,c=0)      (r=3,c=1)      (r=3,c=2)      (r=3,c=3)      (r=3,c=4)
    // r=4 │   (r=4,c=0)      (r=4,c=1)      (r=4,c=2)      (r=4,c=3)      (r=4,c=4)


    // 2)  bordo_bottom (r == n-1)  → ultima riga
    //            c=0            c=1            c=2            c=3            c=4
    //     ┌────────────────────────────────────────────────────────────────────────
    // r=0 │   (r=0,c=0)      (r=0,c=1)      (r=0,c=2)      (r=0,c=3)      (r=0,c=4)
    // r=1 │   (r=1,c=0)      (r=1,c=1)      (r=1,c=2)      (r=1,c=3)      (r=1,c=4)
    // r=2 │   (r=2,c=0)      (r=2,c=1)      (r=2,c=2)      (r=2,c=3)      (r=2,c=4)
    // r=3 │   (r=3,c=0)      (r=3,c=1)      (r=3,c=2)      (r=3,c=3)      (r=3,c=4)
    // r=4 │  _(r=4,c=0)_    _(r=4,c=1)_    _(r=4,c=2)_    _(r=4,c=3)_    _(r=4,c=4)_


    // 3)  bordo_sx (c == 0)        → prima colonna
    //            c=0            c=1            c=2            c=3            c=4
    //     ┌────────────────────────────────────────────────────────────────────────
    // r=0 │  _(r=0,c=0)_     (r=0,c=1)      (r=0,c=2)      (r=0,c=3)      (r=0,c=4)
    // r=1 │  _(r=1,c=0)_     (r=1,c=1)      (r=1,c=2)      (r=1,c=3)      (r=1,c=4)
    // r=2 │  _(r=2,c=0)_     (r=2,c=1)      (r=2,c=2)      (r=2,c=3)      (r=2,c=4)
    // r=3 │  _(r=3,c=0)_     (r=3,c=1)      (r=3,c=2)      (r=3,c=3)      (r=3,c=4)
    // r=4 │  _(r=4,c=0)_     (r=4,c=1)      (r=4,c=2)      (r=4,c=3)      (r=4,c=4)


    // 4)  bordo_dx (c == n-1)      → ultima colonna
    //            c=0            c=1            c=2            c=3            c=4
    //     ┌────────────────────────────────────────────────────────────────────────
    // r=0 │   (r=0,c=0)      (r=0,c=1)      (r=0,c=2)      (r=0,c=3)     _(r=0,c=4)_
    // r=1 │   (r=1,c=0)      (r=1,c=1)      (r=1,c=2)      (r=1,c=3)     _(r=1,c=4)_
    // r=2 │   (r=2,c=0)      (r=2,c=1)      (r=2,c=2)      (r=2,c=3)     _(r=2,c=4)_
    // r=3 │   (r=3,c=0)      (r=3,c=1)      (r=3,c=2)      (r=3,c=3)     _(r=3,c=4)_
    // r=4 │   (r=4,c=0)      (r=4,c=1)      (r=4,c=2)      (r=4,c=3)     _(r=4,c=4)_


    // 5)  diag_principale (r == c) → diagonale da sinistra in alto a destra in basso
    //            c=0            c=1            c=2            c=3            c=4
    //     ┌────────────────────────────────────────────────────────────────────────
    // r=0 │  _(r=0,c=0)_     (r=0,c=1)      (r=0,c=2)      (r=0,c=3)      (r=0,c=4)
    // r=1 │   (r=1,c=0)     _(r=1,c=1)_     (r=1,c=2)      (r=1,c=3)      (r=1,c=4)
    // r=2 │   (r=2,c=0)      (r=2,c=1)     _(r=2,c=2)_     (r=2,c=3)      (r=2,c=4)
    // r=3 │   (r=3,c=0)      (r=3,c=1)      (r=3,c=2)     _(r=3,c=3)_     (r=3,c=4)
    // r=4 │   (r=4,c=0)      (r=4,c=1)      (r=4,c=2)      (r=4,c=3)     _(r=4,c=4)_



    // Combinando le condizioni mediante l'operatore logico OR, 
    // otteniamo l'insieme di coordinate in cui viene stampato un asterisco,
    // ossia quando almeno una condizione di bordo o diagonale è vera:
    //
    //            c=0            c=1            c=2            c=3            c=4
    //     ┌────────────────────────────────────────────────────────────────────────
    // r=0 │  _(r=0,c=0)_    _(r=0,c=1)_    _(r=0,c=2)_    _(r=0,c=3)_    _(r=0,c=4)_
    // r=1 │  _(r=1,c=0)_    _(r=1,c=1)_     (r=1,c=2)      (r=1,c=3)     _(r=1,c=4)_
    // r=2 │  _(r=2,c=0)_     (r=2,c=1)     _(r=2,c=2)_     (r=2,c=3)     _(r=2,c=4)_
    // r=3 │  _(r=3,c=0)_     (r=3,c=1)      (r=3,c=2)     _(r=3,c=3)_    _(r=3,c=4)_
    // r=4 │  _(r=4,c=0)_    _(r=4,c=1)_    _(r=4,c=2)_    _(r=4,c=3)_    _(r=4,c=4)_
    // 
    // Il risultato stampato sullo schermo è quindi:
    //
    // * * * * *
    // * *     *
    // *   *   *
    // *     * *
    // * * * * *

}

int main() {
    int n = 0;
    cout << "Inserisci la dimensione del quadrato: ";
    cin >> n;

    // Controllo per evitare valori non validi
    if (n < 1) {
        cout << "Il numero deve essere positivo!" << endl;
        return 1;
    }

    stampa_quadrato_cavo_con_diagonale(n);

    return 0;
}
