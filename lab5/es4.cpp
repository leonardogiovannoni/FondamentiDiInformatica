#include <cmath>  // Per `sqrt`
#include <iostream>
using namespace std;

void stampa_menu(char rect_print, char sqrt_calc, char exit_cmd) {
    cout << "MENU fondamenti funzioni" << endl;
    cout << rect_print << ": Stampa rettangolo NxM di asterischi" << endl;
    cout << sqrt_calc << ": Radice quadrata" << endl;
    cout << exit_cmd << ": esci" << endl;
}

void stampa_rettangolo(int n, int m) {
    if (n < 0 || m < 0) {
        cout << "N e M devono essere positivi" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int n = 0;
    int m = 0;
    double numero = 0.0;
    double radice = 0.0;
    char cmd = '!';
    bool b = true;

    while (b) {
        // Funzione di stampa menu
        stampa_menu('s', 'r', 'e');
        cout << "inserisci il comando.. " << endl;
        cin >> cmd;
        if (!cin) {
            return 0;
        }
        switch (cmd) {
            case 's': {
                cout << "inserisci altezza e larghezza.. " << endl;
                cin >> n >> m;
                stampa_rettangolo(n, m);
                break;
            }
            case 'r': {
                cout << "inserisci un numero.. " << endl;
                cin >> numero;
                radice = sqrt(numero);
                cout << "la radice quadrata di " << numero << " e': " << radice << endl;
                break;
            }
            case 'e': {
                b = false;
                cout << "Terminazione" << endl;
                break;
            }
            default: {
                cout << "Comando non ammissibile" << endl;
                break;
            }
        }
    }
    return 0;
}
