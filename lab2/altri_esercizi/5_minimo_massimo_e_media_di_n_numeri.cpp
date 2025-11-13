#include <iostream>
using namespace std;


int main() {
    int n = 0;
    int x = 0;
    
    // (* associamo alla variabile `minimo`.. 
    int minimo = 0;
    bool minimo_valido = false;
    // ..un flag per sapere se `minimo` è valido o no *)

    // (* associamo alla variabile `massimo`.. 
    int massimo = 0;
    bool massimo_valido = false;
    // ..un flag per sapere se `massimo` è valido o no *)

    // Potremmo tenere anche un flag unico per entrambi,
    // dato che alla prima iterazione entrambi diventano validi,
    // ma, opinabilmente, in questo modo è piu' chiaro.

    int somma = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (minimo_valido == false || x < minimo) {
            minimo_valido = true;
            minimo = x;
        }
        if (massimo_valido == false || x > massimo) {
            massimo_valido = true;
            massimo = x;
        }
        somma += x;
    }

    // Potremmo anche far partire il for da 1 e assegnare direttamente
    // il primo numero letto a `minimo` e `massimo`, evitando di usare
    // i flag, è una questione di gusti.

    cout << "Minimo: ";
    if (minimo_valido) {
        cout << minimo << endl;
    } else {
        cout << "Nessun numero inserito" << endl;
    }

    cout << "Massimo: ";
    if (massimo_valido) {
        cout << massimo << endl;
    } else {
        cout << "Nessun numero inserito" << endl;
    }

    cout << "Media intera: ";
    if (n > 0) {
        int media = somma / n;
        cout << media << endl;
    } else {
        cout << "Nessun numero inserito" << endl;
    }

    return 0;
}
