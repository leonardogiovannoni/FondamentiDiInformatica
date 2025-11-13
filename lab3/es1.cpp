#include <iostream>
using namespace std;

void stampa_quadrato_cavo_con_diagonale(int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            bool bordo_top       = (r == 0);
            bool bordo_bottom    = (r == n - 1);
            bool bordo_sx        = (c == 0);
            bool bordo_dx        = (c == n - 1);
            bool diag_principale = (r == c);
            bool pieno = bordo_top 
                        || bordo_bottom 
                        || bordo_sx
                        || bordo_dx
                        || diag_principale;
            if (pieno) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n = 0;
    cout << "Inserisci la dimensione del quadrato: ";
    cin >> n;

    if (n < 1) {
        cout << "Il numero deve essere positivo!" << endl;
        return 1;
    }

    stampa_quadrato_cavo_con_diagonale(n);

    return 0;
}
