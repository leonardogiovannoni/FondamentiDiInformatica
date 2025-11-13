#include <iostream>
using namespace std;

bool primo(int n) {
    if (n <= 1) {
        return false;
    }
    
    if (n % 2 == 0) {
        // l'unico numero primo pari è il 2
        return n == 2;
    }

    // un numero è primo se nessun altr numero
    // nell'intervallo [3, n) lo divide.
    // Incrementiamo con `i += 2` perché
    // un numero primo != da 2 è sicuramente dispari
    // e non può essere diviso da un numero pari.
    // Consideriamo come candidati divisori di `n`
    // quindi i numeri { 3, 5, 7, 9, ..., n - 1 }
    for (int i = 3; i < n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int prossimo_primo(int n) {
    if (n <= 2) {
        return 2;
    }
    if (n % 2 == 0) {
        n++;
    }
    while (!primo(n)) {
        n += 2;
    }
    return n;
}

int main() {
    int n = 0;
    cout << "n: ";
    cin >> n;
    if (primo(n)) {
        cout << n << " e' primo" << endl;
    } else {
        cout << n << " non e' primo" << endl;
    }
    int x = prossimo_primo(n);
    cout << "prossimo primo >= n: " << x << endl;
}
