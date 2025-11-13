#include <iostream>
using namespace std;

void stampa_triangolo_cavo(int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < r; c++) {
            bool cateto_sx = (c == 0);
            bool base      = (r == n - 1);
            bool ipotenusa = (c == r);

            bool pieno = cateto_sx || base || ipotenusa;
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
    cout << "n: ";
    cin >> n;
    if (n < 1) {
        cout << "n deve essere >= 1\n";
        return 1;
    }
    stampa_triangolo_cavo(n);
}
