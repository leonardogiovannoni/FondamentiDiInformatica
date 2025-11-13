#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    if (n == 0) {
        cout << "Cifre: 1" << endl;
        cout << "Somma cifre: 0" << endl;
        cout << "Invertito: 0" << endl;
        return 0;
    }
    int tmp = n;
    int invertito = 0;
    int somma = 0;
    int cifre = 0;
    while (tmp > 0) {
        int d = tmp % 10;
        somma += d;
        invertito = invertito * 10 + d;
        tmp /= 10;
        cifre++;
    }
    cout << "Cifre: " << cifre << endl;
    cout << "Somma cifre: " << somma << endl;
    cout << "Invertito: " << invertito << endl;
    return 0;
}
