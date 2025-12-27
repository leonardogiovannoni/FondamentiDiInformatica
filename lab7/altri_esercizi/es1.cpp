#include <iostream>
using namespace std;

// Uno dei problemi di maneggiare i puntatori in C++ è che il linguaggio non fornisce
// un'indicazione su chi debba essere responsabile della deallocazione della memoria
// del puntatore.
// Spesso, possiamo risolvere questo problema incapsulando i puntatori all'interno di strutture dati
// e definendo delle funzioni che si occupano di inizializzare e distruggere tali strutture dati.
// In questi casi, è evidente che la responsabilità della deallocazione della memoria ricade sulle
// funzioni di distruzione. Definiamo `owner` la struttura dati che ha la responsabilità di liberare
// la memoria di un puntatore nella sua funzione di distruzione. In questo caso, assumiamo che
// `Polynomial` sia l'`owner` del puntatore `coeffs`, quindi il main passerà l'ownership della
// memoria allocata per `coeffs` alla struttura dati `Polynomial`, e sarà suo onere liberarla, il
// main non dovrà più occuparsene.

struct Polynomial {
    int *coeffs;
    int len;
};

// # Safety: coeffs è un vettore di interi di lunghezza `len` e è stato allocato con la `new[]`.
// coeffs diventa di proprietà della struttura dati Polynomial, che sarà responsabile della sua
// deallocazione anche in caso di errore.
bool polynomial_init(Polynomial &p, int coeffs[], int len) {
    if (len <= 0) {
        delete[] coeffs;
        p.coeffs = nullptr;
        p.len = 0;
        return false;
    }
    p.coeffs = coeffs;
    p.len = len;
    return true;
}

void polynomial_destroy(Polynomial &p) {
    delete[] p.coeffs;
    p.coeffs = nullptr;
    p.len = 0;
}

void polynomial_print(const Polynomial &p) {
    cout << "\nPolynomial: ";
    for (int i = p.len - 1; i >= 0; i--) {
        cout << p.coeffs[i];
        switch (i) {
            case 0: {
                break;
            }
            case 1: {
                cout << "*x";
                break;
            }
            default: {
                cout << "*x^" << i;
                break;
            }
        }
        if (i != 0) {
            cout << "\t+\t";
        }
    }
    cout << endl;
}

Polynomial polynomial_derivative(const Polynomial &p) {
    if (p.len <= 1) {
        Polynomial dp = {};
        dp.coeffs = new int[1];
        dp.coeffs[0] = 0;
        dp.len = 1;
        return dp;
    }
    int *coeffs = new int[p.len - 1];
    int len = p.len - 1;
    for (int i = 0; i < len; i++) {
        coeffs[i] = (i + 1) * p.coeffs[i + 1];
    }
    Polynomial dp = {};
    if (!polynomial_init(dp, coeffs, len)) {
        polynomial_destroy(dp);
        // Non dovrebbe mai succedere perché len > 0,
        // se succede, è un bug: terminiamo il programma.
        exit(1);
    }
    return dp;
}

int main() {
    int n = 0;
    cout << "How many coefficients? ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size." << endl;
        return 0;
    }

    int *coeffs = new int[n];

    cout << "Enter coefficients (from degree 0 to degree " << n - 1 << "):\n";
    for (int i = 0; i < n; i++) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coeffs[i];
    }

    Polynomial p = {};
    if (!polynomial_init(p, coeffs, n)) {
        polynomial_destroy(p);
        cout << "Failed to initialize polynomial." << endl;
        return 1;
    }

    polynomial_print(p);

    Polynomial dp = polynomial_derivative(p);
    cout << "Derivative:";
    polynomial_print(dp);

    polynomial_destroy(dp);
    polynomial_destroy(p);
    return 0;
}
