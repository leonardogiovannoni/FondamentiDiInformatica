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

void stampa_matrice(int *m, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int index = r * cols + c;
            cout << m[index] << " ";
        }
        cout << endl;
    }
}

void inverti_colonne(int *m, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols / 2; c++) {
            int other_c = cols - 1 - c;

            int idx_sx = r * cols + c;
            int idx_dx = r * cols + other_c;

            int tmp = m[idx_sx];
            m[idx_sx] = m[idx_dx];
            m[idx_dx] = tmp;
        }
    }
}

int main() {
    int mat[2][3] = {};

    leggi_matrice(&mat[0][0], 2, 3);
    stampa_matrice(&mat[0][0], 2, 3);
    inverti_colonne(&mat[0][0], 2, 3);
    cout << "Matrice dopo inversione colonne:" << endl;
    stampa_matrice(&mat[0][0], 2, 3);
    return 0;
}
