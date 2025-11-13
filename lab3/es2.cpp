#include <iostream>
using namespace std;

void f1(int x) {
    x = x * 2;
}

int f2(int x) {
    x = x * 2;
    return x;
}

void f3(int &x) {
    int tmp = x * 2;
    x = tmp;
}

int main() {
    int a = 0;
    cout << "Inserisci un numero intero: ";
    cin >> a;
    cout << endl;
    cout << "Valore iniziale: " << a << endl;

    f1(a);
    cout << "Dopo f1(x): " << a << endl;

    a = f2(a);
    cout << "Dopo x = f2(x): " << a << endl;
    f3(a);
    cout << "Dopo f3(x): " << a << endl;

    return 0;
}

