#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;

    int count_pari = 0;
    int somma_pari = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << i << endl;
            count_pari++;
            somma_pari += i;
        }
    }
    cout << "Pari stampati: " << count_pari << endl;
    cout << "Somma dei pari: " << somma_pari << endl;
    return 0;
}
