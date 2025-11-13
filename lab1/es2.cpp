#include <iostream>
using namespace std;

int main() {
    int a;
    int b;

    cout << "Inserisci il primo numero a:" << endl;
    cin >> a;

    cout << "Inserisci il secondo numero b:" << endl;
    cin >> b;

    if(a >= b) {
        cout << "Il massimo è a: " << a << endl;
    } else {
        cout << "Il massimo è b: " << b << endl;
    }

    return 0;
}
