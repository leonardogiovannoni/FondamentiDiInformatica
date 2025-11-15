#include <iostream>
using namespace std;

int somma(int n) {
    if (n == 0) {
        return 0;
    }
    return n + somma(n - 1);
}

int main() {
    int n = 0;
    cout << "Inserisci un numero intero positivo: ";
    cin >> n;

    cout << "La somma dei numeri da 0 a " << n << " è: " << somma(n) << endl;

    return 0;
}
