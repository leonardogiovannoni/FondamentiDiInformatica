#include <iostream>
using namespace std;


int main() {
    int n = 0;
    cin >> n;

    // Devo stampare un triangolo rettangolo del genere
    //
    // *
    // **
    // ***
    // ****
    //
    // Dove il numero di righe, che nell'esempio sopra è 4, è uguale ad `n`
    // Ciò significa che devo fare un ciclo di esattamente 4 (in generale, `n`) iterazioni:
    //  -) alla prima   iterazione (`i == 0`) devo stampare 1 asterisco
    //  -) alla seconda iterazione (`i == 1`) devo stampare 2 asterischi
    //  -) alla terza   iterazione (`i == 2`) devo stampare 3 asterischi
    //  -) alla quarta  iterazione (`i == 3`) devo stampare 4 asterischi
    //
    // Quindi il primo ciclo, di cardinalità `4`, lo seleziono con `i` in `[0, 4)` (ovvero, `[0, n)`).
    // Ciò significa, come mostrato nella bullet list, che alla `i`-esima iterazione devo stampare `i + 1` asterischi.
    // Per stampare `i + 1` asterischi, creo un ciclo di cardinalità `i + 1`, per esempio un ciclo con `j` in `[0, i + 1)`.

    // *        i == 0
    // **       i == 1
    // ***      i == 2
    // ****     i == 3
    
    
    //          i == 0      ->      j == 0
    // *        
    //          i == 1      ->      j == 0
    //                              j == 1
    // **       
    //          i == 2      ->      j == 0
    //                              j == 1
    //                              j == 2
    // ***      
    //          i == 3      ->      j == 0
    //                              j == 1
    //                              j == 2
    //                              j == 3
    // ****


    for (int i = 0; i < n; i++) {
        // iterazione `i`-esima    ->    stampo `i + 1` asterischi    ->   ciclo con `i + 1` iterazioni    ->    `j` in `[0, i + 1)`
        for (int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}