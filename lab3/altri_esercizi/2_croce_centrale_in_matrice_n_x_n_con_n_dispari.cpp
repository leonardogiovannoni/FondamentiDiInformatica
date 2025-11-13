#include <iostream>
using namespace std;

void stampa_croce(int n) {
    int mid = n / 2;  // indice centrale (valido se n è dispari)
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            bool riga_centrale = (r == mid);
            bool col_centrale  = (c == mid);

            bool pieno = riga_centrale || col_centrale;
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
    cout << "n dispari: ";
    cin >> n;
    if (n < 1 || n % 2 == 0) {
        cout << "Serve n >= 1 e dispari." << endl;
        return 1;
    }
    stampa_croce(n);
}
