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

void trasponi(int *dst, const int *src, int src_rows, int src_cols) {
    const int dst_rows = src_cols;
    const int dst_cols = src_rows;
    for (int i = 0; i < src_rows; i++) {
        for (int j = 0; j < src_cols; j++) {
            int dst_index = j * dst_cols + i;
            int src_index = i * src_cols + j;
            dst[dst_index] = src[src_index];
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

int main() {
    const int SRC_ROWS = 3;
    const int SRC_COLS = 4;
    const int DST_ROWS = SRC_COLS;
    const int DST_COLS = SRC_ROWS;
    int src[SRC_ROWS][SRC_COLS] = {};
    int dst[DST_ROWS][DST_COLS] = {};

    leggi_matrice(&src[0][0], SRC_ROWS, SRC_COLS);

    trasponi(&dst[0][0], &src[0][0], SRC_ROWS, SRC_COLS);

    stampa_matrice(&dst[0][0], DST_ROWS, DST_COLS);
    return 0;
}

