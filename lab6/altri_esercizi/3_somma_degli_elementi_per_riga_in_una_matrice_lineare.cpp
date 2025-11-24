#include <iostream>
using namespace std;

void leggi_matrice(int *m, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int index = r * cols + c;
            cin >> m[index];
        }
    }
}

int somma_riga(const int *m, int cols, int rows, int r) {
    int somma = 0;
    for (int c = 0; c < cols; c++) {
        int index = r * cols + c;
        int val = m[index];
        somma += val;
    }
    return somma;
}

int main() {
    const int ROWS = 4;
    const int COLS = 5;
    int m[ROWS][COLS] = {};
    leggi_matrice(&m[0][0], ROWS, COLS);

    for (int r = 0; r < ROWS; r++) {
        int s = somma_riga(&m[0][0], COLS, ROWS, r);
        cout << "Somma riga " << r << ": " << s << endl;
    }

    return 0;
}
